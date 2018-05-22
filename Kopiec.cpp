#include "Kopiec.h"

Kopiec::Kopiec() {

	cr = cl = cp = "  "; //zmienne, umozliwiajace wyswietlenie kopca
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	rozmiar = 0; //domyslnie rozmiar kopca wynosi 0
	w = new int[rozmiar];
}

//destruktor
Kopiec::~Kopiec()
{
	delete[]w; //zwolnienie pamieci
	rozmiar = 0; //wyzerowanie rozmiaru
}

void Kopiec::wyswietl(){
	wyswietl_kopiec("", "", 0);
}

void Kopiec::popraw() {
	int j, temp = 0; //Zmienna pomocnicza do pêtli sortuj¹cej
	//Pêtla sortuj¹ca, uk³adaj¹ca elementy kopca w odpowiedniej kolejnoœci
	for (int i = 1; i < rozmiar; i++) {
		j = i;
		while ((j > 0) && (w[j] > w[j / 2]))

		{
			//gdy potomek jest wiekszy od rodzica to go z nim zamieniamy
			temp = *(w + j);
			*(w + j) = *(w + (j / 2));
			*(w + (j / 2)) = temp;
			j = j / 2;
		}
	}
}

void Kopiec::szukaj(int wartosc) //sprawdzenie czy element o kluczu istnieje
{	
	//sprawdzenie kazdej kolejnej wartosci
	for (int i = 1; i <= rozmiar; i++)
	{
		if (wartosc == w[i])
		{
			std::cout << "Dana wartosc znajduje sie w kopcu \n";
			return; //jezeli napotkano zadany klucz nie ma sensu szukac dalej
		}
	}
	std::cout << "Dana wartosc nie znajduje sie w kopcu \n";

}

/* void Kopiec::relokacja() { 	//dynamiczne zmienianie rozmiarów tablicy
	int *temp = new int[rozmiar];
	for (int i = 0; i<rozmiar; i++)
	{
		temp[i] = w[i];
	}
	delete[]w; //zwolnienie pamieci
	w = temp;
} */



void Kopiec::dodaj(int wartosc) {
	int *temp = new int[rozmiar + 1];
	//if (!szukaj(wartosc)) {
		licznik = 0;
		czasStart();

		for (int i = 0; i < rozmiar; i++) {
			temp[i] = w[i];
		}

		temp[rozmiar] = wartosc; //przypisanie wartosci na koniec tablicy, rozmiar = ostatni indeks+1
		delete[] w;
		w = temp; //przepisanie wartosci wskaznika
		rozmiar++;
		popraw(); //sortuje elementy w kopcu tak aby zosta³ zachowany warunek kopca
		pobierzCzas();
	//}
	//else std::cout << "Zadana wartosc znajduje sie juz w kopcu \n";
}



void Kopiec::usun(int wartosc) {
	if (rozmiar == 0) std::cout << "Kopiec jest pusty \n";
	else{
		for (int i = 0; i < rozmiar; i++) { //Iteracja po ca³ej tablicy kopca w celu znalezienia wartoœci

			if (w[i] == wartosc) {

				int *nowa = new int[rozmiar - 1]; //stwarza nowa tablice mniejsza o 1 element
				for (int k = 0; k < i; k++) { //przepisujemy elementy 
					nowa[k] = w[k];
				}

				for (int k = i + 1; k < rozmiar; k++) { //pozostale elementy zostaja przesuniete
					nowa[k - 1] = w[k];
				}

				delete[]w; //zwolnienie pamieci
				w = nowa;
				rozmiar--;

				//Popraw kolejnoœæ elementów w tablicy kopca
				popraw();
				return;

			}
		}

	}

}
void Kopiec::usun_korzen() {
		if (rozmiar == 0) std::cout << "Kopiec jest pusty \n";
		else {

			int *nowa = new int[rozmiar - 1]; //stwarza nowa tablice mniejsza o 1 element
			for (int i = 1; i < rozmiar; i++) { //pozostale elementy zostaja przesuniete
				nowa[i - 1] = w[i];
			}

			delete[]w; //zwolnienie pamieci
			w = nowa;
			rozmiar--;

			//Popraw kolejnoœæ elementów w tablicy kopca
			popraw();
			return;
		}
}


void Kopiec::wyswietl_kopiec(std::string sp, std::string sn, int v)
{
		string s;

		if (v < rozmiar)
		{
			s = sp;
			if (sn == cr) s[s.length() - 2] = ' ';
			wyswietl_kopiec(s + cp, cr, 2 * v + 2);

			s = s.substr(0, sp.length() - 2);

			std::cout << s << sn << w[v] << "\n";

			s = sp;
			if (sn == cl) s[s.length() - 2] = ' ';
			wyswietl_kopiec(s + cp, cl, 2 * v + 1);
		}
}


void Kopiec::wczytaj(std::string nazwa) {
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
	if (r <= 0) 
		std::cout << "Niepoprawna wielkosc struktury \n";
	else {
		while (plik.good() && cnt < r) {
			plik >> wartosc; //wczytaj wartosc z pliku
			dodaj(wartosc); //dodaj
			cnt++;
		}

		plik.close();
		if (cnt < r) std::cout << "Liczb w pliku bylo mniej, niz zakladano \n";
		pobierzCzas();
	}
}

