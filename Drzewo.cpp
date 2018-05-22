#include "Drzewo.h"

Drzewo::Drzewo() {
	cr = cl = cp = "  "; //stringi pomocne do wyswietlania drzewa
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	rozmiar = 0; //wyzerowanie rozmiaru
	//Puste drzewo zawiera jedynie straznika
	straznik.kolor = 'B'; //liscie zawsze sa czarne
	straznik.rodzic = &straznik; 
	straznik.lewo = &straznik;
	straznik.prawo = &straznik;
	korzen = &straznik; //korzen pustego drzewa wskazuje straznika
}
Drzewo::~Drzewo() {
	if (korzen)
		usun_drzewo();
}

void Drzewo::usun_drzewo() {
	licznik = 0; 
	czasStart();
	usun_element(korzen); //usuwanie korzeni az zostana sami straznicy

	straznik.kolor = 'B'; //przywrocenie wlasnosci z konstruktora
	straznik.rodzic = &straznik;
	straznik.lewo = &straznik;
	straznik.prawo = &straznik;
	korzen = &straznik;

	rozmiar = 0;
	pobierzCzas();
}

void Drzewo::usun_element(TreeMemb *element) {

	if (element != &straznik) { //jezeli element do usuniecia nie jest straznikiem usunie jego dzieci
		usun_element(element->lewo); //funkcja rekurencyjnie usunie dzieci jego dzieci :(
		usun_element(element->prawo);
		delete element; //na koniec usuwa sam element

		rozmiar--; //dekrementacja rozmiaru drzewa
	}
}
void Drzewo::obrot_lewo(TreeMemb *element) { //obrot wezla w lewo

	TreeMemb *y, *p;

	y = element->prawo;
	if (y != &straznik) {
		p = element->rodzic;
		element->prawo = y->lewo;
		if (element->prawo != &straznik) element->prawo->rodzic = element;

		y->lewo = element;
		y->rodzic = p;
		element->rodzic = y;

		if (p != &straznik) {
			if (p->lewo == element) p->lewo = y; else p->prawo = y;
		}
		else korzen = y;
	}

}

void Drzewo::obrot_prawo(TreeMemb *element) { //obrot wezla w prawo

	TreeMemb *y, *p;

	y = element->lewo;
	if (y != &straznik) {
		p = element->rodzic;
		element->lewo = y->prawo;
		if (element->lewo != &straznik) element->lewo->rodzic = element;

		y->prawo = element;
		y->rodzic = p;
		element->rodzic = y;

		if (p != &straznik) {
			if (p->lewo == element) p->lewo = y; else p->prawo = y;
		}
		else korzen = y;
	}

}

void Drzewo::dodaj(int wartosc) {

	TreeMemb *X, *Y;
	licznik = 0;
	czasStart();

	X = new TreeMemb; //tworzymy nowy wezel
	X->lewo = &straznik;
	X->prawo = &straznik;
	X->rodzic = korzen;
	X->klucz = wartosc;

	if (X->rodzic == &straznik) { //X zostaje korzeniem jesli rodzic jest straznikiem
		korzen = X;
	} 
	else //jesli nie to zostanie wyszukany lisc, ktory zostanie zastapiony przez X
		while (true) {
			
			if (wartosc < X->rodzic->klucz) { //X zastepuje lewy lisc
				if (X->rodzic->lewo == &straznik) {
					X->rodzic->lewo = X;
					break;
				}
				X->rodzic = X->rodzic->lewo;

			}
			else if (wartosc > X->rodzic->klucz) { // X zastepuje prawy lisc
				if (X->rodzic->prawo == &straznik) {
					X->rodzic->prawo = X;
					break;
				}
				X->rodzic = X->rodzic->prawo;
			}

			else { //Nie mozna zastapic liscia
				delete X;
				return;
			}
		}

		X->kolor = 'R'; //kolorowanie wezla na czerwono
		while ((X != korzen) && (X->rodzic->kolor == 'R')) {
			if (X->rodzic == X->rodzic->rodzic->lewo) {
				Y = X->rodzic->rodzic->prawo;

				//Przypadek 1
				if (Y->kolor == 'R') {
					X->rodzic->kolor = 'B';
					Y->kolor = 'B';
					X->rodzic->rodzic->kolor = 'R';
					X = X->rodzic->rodzic;
					continue;
				}

				//Przypadek 2
				if (X == X->rodzic->prawo) {
					X = X->rodzic;
					obrot_lewo(X);
				}

				//Przypadek 3
				X->rodzic->kolor = 'B';
				X->rodzic->rodzic->kolor = 'R';
				obrot_prawo(X->rodzic->rodzic);
				break;

				//Przypadki lustrzane
			}
			else {
				Y = X->rodzic->rodzic->lewo;

				//Przypadek lustrzany 1
				if (Y->kolor == 'R') {
					X->rodzic->kolor = 'B';
					Y->kolor = 'B';
					X->rodzic->rodzic->kolor = 'R';
					X = X->rodzic->rodzic;
					continue;
				}

				//Przypadek lustrzany 2
				if (X == X->rodzic->lewo) {
					X = X->rodzic;
					obrot_prawo(X);
				}

				//Przypadek lustrzany 3
				X->rodzic->kolor = 'B';
				X->rodzic->rodzic->kolor = 'R';
				obrot_lewo(X->rodzic->rodzic);
				break;
			}
		}
		korzen->kolor = 'B'; //korzen drzewa jest zawsze czarny
		rozmiar++; //Zwiêkszenie rozmiaru drzewa o 1
		pobierzCzas();
}
void Drzewo::usun(int wartosc) {

	TreeMemb *element= zwroc_szukany(wartosc); //sprawdzenie czy dany element znajduje sie w drzewie
	if (element == NULL) { //jezeli istnieje zostanie mu przypisany element z drzewa
		std::cout << "Nie ma elementu o podanym kluczu \n"; //jezeli nie otrzymujemy komunikat
	}
	else {
		TreeMemb *W, *Y, *Z;

		licznik = 0;
		czasStart();
		if ((element->lewo == &straznik) || (element->prawo == &straznik))
			Y = element;
		else Y = znajdz_succ(element);

		if (Y->lewo != &straznik) Z = Y->lewo;
		else Z = Y->prawo;

		Z->rodzic = Y->rodzic;

		if (Y->rodzic == &straznik) korzen = Z;
		else if (Y == Y->rodzic->lewo) Y->rodzic->lewo = Z;
		else Y->rodzic->prawo = Z;

		if (Y != element) element->klucz = Y->klucz;

		if (Y->kolor == 'B')   // Naprawa struktury drzewa czerwono-czarnego
			while ((Z != korzen) && (Z->kolor == 'B'))
				if (Z == Z->rodzic->lewo) {
					W = Z->rodzic->prawo;

					//Przypadek 1
					if (W->kolor == 'R') {
						W->kolor = 'B';
						Z->rodzic->kolor = 'R';
						obrot_lewo(Z->rodzic);
						W = Z->rodzic->prawo;
					}

					//Przypadek 2
					if ((W->lewo->kolor == 'B') && (W->prawo->kolor == 'B')) {
						W->kolor = 'R';
						Z = Z->rodzic;
						continue;
					}

					//Przypadek 3
					if (W->prawo->kolor == 'B') {
						W->lewo->kolor = 'B';
						W->kolor = 'R';
						obrot_prawo(W);
						W = Z->rodzic->prawo;
					}

					//Przypadek 4
					W->kolor = Z->rodzic->kolor;
					Z->rodzic->kolor = 'B';
					W->prawo->kolor = 'B';
					obrot_lewo(Z->rodzic);

					//Zakoñczenie pêtli
					Z = korzen;
				}
		//Przypadki lustrzane
				else {
					W = Z->rodzic->lewo;

					//Lustrzany przypadek 1
					if (W->kolor == 'R') {
						W->kolor = 'B';
						Z->rodzic->kolor = 'R';
						obrot_prawo(Z->rodzic);
						W = Z->rodzic->lewo;
					}

					//Lustrzany przypadek 2
					if ((W->lewo->kolor == 'B') && (W->prawo->kolor == 'B')) {
						W->kolor = 'R';
						Z = Z->rodzic;
						continue;
					}

					//Lustrzany przypadek 3
					if (W->lewo->kolor == 'B') {
						W->prawo->kolor = 'B';
						W->kolor = 'R';
						obrot_lewo(W);
						W = Z->rodzic->lewo;
					}

					//Lustrzany przypadek 4
					W->kolor = Z->rodzic->kolor;
					Z->rodzic->kolor = 'B';
					W->lewo->kolor = 'B';
					obrot_prawo(Z->rodzic);

					//Zakoñczenie pêtli
					Z = korzen;
				}
				Z->kolor = 'B';
				delete Y;
				rozmiar--;
				pobierzCzas();
	}
}
void Drzewo::znajdz_element(int wartosc, TreeMemb *korzen_elementu, TreeMemb *&element) {
	if (korzen_elementu != &straznik) {
		if (korzen_elementu->klucz == wartosc) {
			element = korzen_elementu;
			return;
		}
		znajdz_element(wartosc, korzen_elementu->lewo, element);
		znajdz_element(wartosc, korzen_elementu->prawo, element);
	}
}

void Drzewo::sprawdz(int wartosc) {
	licznik = 0;
	czasStart();
	bool znalezione = false;
	znajdz_klucz(wartosc, korzen, znalezione);

	if (znalezione) {
		std::cout << "Wartosc " << wartosc << " wystepuje w drzewie \n";
	}
	else {
		std::cout << "Wartosc " << wartosc << " nie wystepuje w drzewie \n";

	}
	pobierzCzas();
}

void Drzewo::znajdz_klucz(int wartosc, TreeMemb *korzen_elementu, bool &znalezione) {

	if (korzen_elementu != &straznik) {
		if (korzen_elementu->klucz == wartosc) {
			znalezione = true;
			return;
		}
		znajdz_klucz(wartosc, korzen_elementu->lewo, znalezione);
		znajdz_klucz(wartosc, korzen_elementu->prawo, znalezione);
	}

}

TreeMemb * Drzewo::zwroc_szukany(int wartosc){
		TreeMemb * p;
		p = korzen;
		while ((p != &straznik) && (p->klucz != wartosc))
			if (wartosc < p->klucz) p = p->lewo;
			else           p = p->prawo;
			if (p == &straznik) return NULL;
			return p;
}

TreeMemb * Drzewo::get_korzen()
{
	return korzen;
}

void Drzewo::wyswietl(std::string sp, std::string sn, TreeMemb * p) { //funckja wyswietlania http://eduinf.waw.pl/inf/alg/001_search/0121.php#A3
	string t;  //zmienna do przechowywania znakow

	if (p != &straznik)
	{
		t = sp;
		if (sn == cr) t[t.length() - 2] = ' ';
		wyswietl(t + cp, cr, p->prawo);

		t = t.substr(0, sp.length() - 2);
		cout << t << sn << p->kolor << ":" << p->klucz << endl;

		t = sp;
		if (sn == cl) t[t.length() - 2] = ' ';
		wyswietl(t + cp, cl, p->lewo);
	}
}

void Drzewo::wczytaj(std::string nazwa) {
	nazwa = nazwa + ".txt";
	ifstream plik(nazwa);
	int wartosc, r, cnt = 0;
	licznik = 0;
	czasStart();
	if (plik.is_open()) {
		//std::cout << "Plik zostal otwarty \n";
	}
	else {
		std::cout << "Nie udalo sie otworzyc pliku \n";
		return;
	}

	plik >> r;
	if (r <= 0) std::cout << "Niepoprawna wielkosc struktury \n";
	else {
			while (plik.good() && cnt < r) {
				plik >> wartosc; //wczytaj wartosc z pliku
				dodaj(wartosc); //dodaj
				cnt++;
			}

			plik.close();
			if (cnt < r)
				for (int i = 0; i < (r - cnt); i++)
					dodaj(0);

	}
	pobierzCzas();
}


void Drzewo::print(){
	wyswietl("", "", korzen);
}

TreeMemb *Drzewo::znajdz_succ(TreeMemb *p) {
	TreeMemb *succ;

	if (p != &straznik) {
		if (p->prawo != &straznik) return znajdz_succ(p->prawo);
		else {
			succ = p->rodzic;
			while ((succ != &straznik) && (p == succ->prawo)) {
				p = succ;
				succ = succ->rodzic;
			}
			return succ;
		}
	}
	return &straznik;
}

TreeMemb *Drzewo::znajdz_min(TreeMemb *p) {
	if (p != &straznik)
		while (p->lewo != &straznik) p = p->lewo;
	return p;
}