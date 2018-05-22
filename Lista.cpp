#include "Lista.h"

Lista::Lista() {
	ogon = glowa = NULL; //przypisanie domyslnie pustych adresow glowie i ogonowi
	rozmiar = 0; //lista domyslnie pusta
}
void Lista::wyswietl() {


	if (rozmiar == 0) std::cout << "Pusta lista \n"; //sprawdzenie czy lista nie jest pusta
	else
	{
		Memb * temp = new Memb(); //utworzenie tymczasowego elementu listy
		temp = glowa; //przypisanie mu pierwszej pozycji
		for (int i = 1; temp; i++) //petla do wyswietlenia kolejnych elementow listy
		{
			std::cout << i << "." << temp->klucz << " \t";
			temp = temp->next; //przypisanie temp kolejnego elementu
		}
		std::cout << "\n";
		delete temp; //zwolnienie pamieci
	}

}

void Lista::dodaj_pocz(int klucz) {
	licznik = 0;
	czasStart();
	Memb * nowy = new Memb(); //utworzenie nowego elementu listy
	nowy->next = glowa; //element zostaje wpisany przed glowe
	nowy->prev = NULL; //jako ze jest glowa nie ma poprzedniego elementu

	if (glowa) glowa->prev = nowy; //jezeli glowa istnieje to jej poprzednikiem zostaje nowy
	glowa = nowy; //i elemenet zostaje nowa glowa
	if (!ogon) ogon = glowa; //jezeli ogonu nie ma glowa jest jednoczenie ogonem tzn. lista ma 1 element
	nowy->klucz = klucz; //przypisanie wartosci klucza podanego do funkcji
	rozmiar++; //zwiekszenie rozmiari listy
	pobierzCzas();
}

void Lista::usun_pocz() {
	if (rozmiar == 0) std::cout << "Pusta lista \n"; //sprawdzenie czy w liscie sa jakies elementy
	else
	{
		licznik = 0;
		czasStart();
		if (glowa->next)
			glowa = glowa->next; //przesuniecie glowy na nastepna pozycje; ogon bez zmian
		else
			glowa = ogon = NULL;
		rozmiar--; //zmniejszenie rozmiari listy
		pobierzCzas();
	}
}

void Lista::dodaj_kon(int klucz) {
	licznik = 0;
	czasStart();
	Memb * nowy = new Memb(); //deklaracja nowego elementu
	nowy->prev = ogon; //ustawienie nowego za ogonem
	nowy->next = NULL; //jest ostatni, nie ma nastepnego elementu
	if (ogon) ogon->next = nowy; //ogon przechodzi na nowy element
	ogon = nowy;
	if (!glowa) glowa = ogon; //jezeli nie ma glowy to ogon zostaje glowowa (1 element w liscie)
	nowy->klucz = klucz; //przypisanie klucza podanego do funkcji
	rozmiar++; //zwiekszenie rozmiari listy
	pobierzCzas();
}

void Lista::usun_kon() {
	if (rozmiar == 0) std::cout << "Pusta lista \n"; //sprawdzenie czy jest co usunac
	else if (rozmiar == 1) usun_pocz();		
	else
	{
		licznik = 0;
		czasStart();
		ogon->prev->next = NULL; //przesuniecie ogona
		ogon->prev = ogon;
		rozmiar--; //zmniejszenie rozmiari listy
		pobierzCzas();
	}
}

void Lista::dodaj_losowo(int klucz) {

	if (rozmiar == 0 || rozmiar == 1)
		dodaj_kon(klucz);
	else {
		int miejsce = generuj();
		miejsce = miejsce%rozmiar;
		licznik = 0;
		czasStart();

		Memb * nowy = new Memb(); //deklaracja nowego elementu
		Memb * temp = new Memb(); //deklaracja nowego elementu

		nowy = glowa;
		for (int i = 0; i < miejsce; i++) {
			if (nowy->next)
				nowy = nowy->next;
			
		}
		int stary = nowy->klucz;
		dodaj_kon(stary);
		nowy->klucz = klucz; //przypisanie klucza podanego do funkcji
		//++; //zwiekszenie rozmiari listy
		pobierzCzas();
	}
}

void Lista::usun_losowo() {
	if (rozmiar == 0)
		std::cout << "Pusta lista \n";
	else if (rozmiar == 1) usun_pocz();
	else {
		int miejsce = generuj();
		miejsce = miejsce%rozmiar;
		licznik = 0;
		czasStart();

		Memb * nowy = new Memb(); //deklaracja nowego elementu
		//Memb * temp = new Memb(); //deklaracja nowego elementu

		nowy = glowa;
		for (int i = 0; i < miejsce; i++) {
			if (nowy->next)
				nowy = nowy->next;

		}
		usun_klucz(nowy->klucz);
		pobierzCzas();
	}
}

void Lista::sprawdz(int klucz) {
	Memb *temp; //deklaracja tymczasowego elemenentu
	temp = glowa;
	licznik = 0;
	czasStart();

	while ((temp->next != NULL) && (temp->klucz != klucz)) { //sprawdzenie czy nie doszedl do konca listy i czy klucz nie jest tym szukanym 
		temp = temp->next; //przejscie na nastepna pozycje
		if (temp->klucz == klucz) {
			break;
			std::cout << "Znaleziono klucz \n";
			pobierzCzas();
			return;
		}
	}
			std::cout << "Nie znaleziono klucza \n";
			pobierzCzas();
}

void Lista::usun_klucz(int klucz) {
	if (rozmiar == 0) std::cout << "Pusta lista \n"; //sprawdzenie czy jest co usunac
	else
	{
		Memb *temp; //deklaracja tymczasowego elemenentu
		temp = glowa;
		licznik = 0;
		czasStart();
		while ((temp->next != NULL) && (temp->klucz != klucz)) { //sprawdzenie czy nie doszedl do konca listy i czy klucz nie jest tym szukanym 
			temp = temp->next; //przejscie na nastepna pozycje
		}
		if (temp->klucz == klucz) //przerwanie petli while
		{
			if (temp->next) //jezeli istnieje element nastepny
				temp->next->prev = temp->prev; //nastepny staje sie poprzednim
			else
				ogon = temp->prev; //jezeli nie ma nastepnego to byl ostatnim
			if (temp->prev) { //jezeli mial poprzedni
				temp->prev->next = temp->next; //to jego poprzedni staje sie nastepnym
			}
			else //jak nie mial poprzedniego to znaczy ze byl pierwszy
				glowa = temp->next; //glowa przechodzi na nastepny element
			rozmiar--;
			pobierzCzas();
		}
		else std::cout << "Nie znaleziono klucza \n"; //ostatnia mozliwosc
	}
}

void Lista::zapelnij_losowo(int ile) {
	licznik = 0;
	czasStart();
	for (int i = 1; i <= ile; i++) //wykonanie instrukcji ile razy
		dodaj_kon((rand() % 2000) - 1000); //wartosci -1000 do 999

	pobierzCzas();
}

void Lista::wczytaj(std::string nazwa) {
	nazwa = nazwa + ".txt";
	ifstream plik(nazwa);
	int wartosc, wybor, r, cnt = 0;
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
		std::cout << "Jak chcesz dodawac kolejne elementy? \n 1. Na poczatek \n 2.Na koniec \n 3.W losowe miejsca \n";
		std::cin >> wybor;
		licznik = 0;
		czasStart();
		switch (wybor) {
		case 1:
		{

			while (plik.good() && cnt < r) {
				plik >> wartosc; //wczytaj wartosc z pliku
				dodaj_pocz(wartosc); //dodaj
				cnt++;
			}

			plik.close();
			if (cnt < r)
				for (int i = 0; i < (r - cnt); i++)
					dodaj_pocz(0);
		}break;
		case 2:
		{
			while (plik.good() && cnt < r) {
				plik >> wartosc; //wczytaj wartosc z pliku
				dodaj_kon(wartosc); //dodaj
				cnt++;
			}

			plik.close();
			if (cnt < r)
				for (int i = 0; i < (r - cnt); i++)
					dodaj_kon(0);
		}break;
		case 3:
		{
			while (plik.good() && cnt < r) {
				plik >> wartosc; //wczytaj wartosc z pliku
				dodaj_losowo(wartosc); //dodaj
				cnt++;
			}

			plik.close();
			if (cnt < r)
				for (int i = 0; i < (r - cnt); i++)
					dodaj_losowo(0);
		}break;
		}
	}
	pobierzCzas();
}



Lista::~Lista() {
	licznik = 0;
	czasStart();
	for (int i = 0; i < rozmiar; i++) {
		if (glowa->next != NULL)
			glowa = glowa->next; //przesuniecie glowy na nastepna pozycje; ogon bez zmian
		else
			glowa = ogon = NULL;
	}
		rozmiar = 0; //wyzerowanie rozmiaru listy
		pobierzCzas();
	//std::cout << "Uruchomiono destruktor listy \n";
}
