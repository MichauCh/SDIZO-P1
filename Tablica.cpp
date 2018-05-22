#pragma once
#include "Tablica.h"

	Tablica::Tablica() {
			rozmiar = 0; //domyslnie tablica jest pusta
			w = new int[rozmiar]; //ustawienie wskaznika
		}
		void Tablica::wyswietl_tablice() {
			if (rozmiar == 0) std::cout << "Tablica jest pusta \n"; //warunek sprawdzajacy czy tablica ma jakas zawartosc
			else
			{
				for (int i = 0; i < rozmiar; i++) { //petla do wypisywania wartosci tablicy
					std::cout<< w[i] << "\t"; 
				} 
			}
			std::cout << "\n";
		}

		void Tablica::usun_element(int index) {

			if (rozmiar <= 0) {
				std::cout << "Tablica jest pusta \n";
			}
			else {
				int *temp = new int[rozmiar - 1];

				if (rozmiar == 0) {
					std::cout << "Tablica jest pusta \n"; //sprawdzenie czy jest co usuwac
				}
				else if (index >= rozmiar) //sprawdzenie czy istnieje element o takim indeksie
					std::cout << "Tablica nie ma elementu o indeksie " << index << std::endl;
				else { //jezeli jest element o takim indeksie
					licznik = 0;
					czasStart();
					for (int i = 0; i < index; i++)
					{
						temp[i] = w[i];
					}
					for (int i = index; i < rozmiar-1; i++)
					{
						temp[i] = w[i + 1]; //przypisanie kazdemu elementowi o wyzszym indeksie wartosci nastepnej
					}
					delete[] w;
					w = temp;
					rozmiar--; //zmniejszenie ilosci elementow o 1
					pobierzCzas();
				}
			}
		}
		void Tablica::dodaj_element(int index, int wartosc) {

			if (index >= rozmiar && index >0) //sprawdzenie czy podany indeks miesci sie w istniejacej juz tablicy
			{
				dodaj_kon(wartosc); //jezeli jest zbyt duzy zostaje dodany na koniec
				std::cout << "dodany na koncu tablicy \n";
			}
			else if(index>=0)
			{
				int *temp = new int[rozmiar+1];
				licznik = 0;
				czasStart();
				for (int i = 0; i < index; i++)
				{
					temp[i] = w[i];
				}
				temp[index] = wartosc;
				for (int i = index; i < rozmiar; i++)
				{
					temp[i+1] = w[i];
				}

				rozmiar++;
				delete w;
				w = temp;
				pobierzCzas();
			}
			else std::cout << "Podano nieprawidlowy indeks \n";
		}

	/*void Tablica::relokacja() {
		int *temp = new int[rozmiar]; //deklaracja tablicy tymaczasowej 
		for (int i = 0; i < rozmiar; i++)
		{
			temp[i] = w[i]; //przepisanie tablicy
		}
		delete w; //zwolnienie pamieci
		w = temp; 
	}*/

	void Tablica::dodaj_pocz(int wartosc) {
		int *temp = new int[rozmiar+1];
		licznik = 0;
		czasStart();
		temp[0] = wartosc;
		
			for (int i = 0; i < rozmiar; i++) //przesuniecie wartosci
			{
				temp[i+1] = w[i];
			}
			delete w;
			w = temp;
			rozmiar++; //zwiekszenie tablicy o 1 pozycje
			pobierzCzas();	
	}

	void Tablica::usun_pocz() {
		if (rozmiar == 0)
			std::cout << "Tablica jest pusta \n";
		else
		{
			licznik = 0;
			czasStart();
			int *temp = new int[rozmiar - 1];

			//Przepisz elementy starej tablicy poza pierwszym
			for (int i = 0; i < rozmiar - 1; i++) {
				temp[i] = w[i + 1];
			}

			//zwolnij pamiêæ po starym wskaŸniku
			//Przypisz nowy wskaŸnik na jego miejsce
			delete[] w;
			w = temp;

			rozmiar--;
			pobierzCzas();
		}
	}


	void Tablica::dodaj_kon(int wartosc) {
			int *temp = new int[rozmiar + 1];
			licznik = 0;
			czasStart();
			//w[rozmiar] = wartosc; //przypisanie wartosci na koniec tablicy, rozmiar = ostatni indeks+1			
			temp[rozmiar] = wartosc;
			for (int i = 0; i < rozmiar; i++) {
				temp[i] = w[i];
			}

			delete w;
			w = temp;

			rozmiar++;
			pobierzCzas();
		}
		void Tablica::usun_kon() {
			if (rozmiar == 0) {
				std::cout << "Tablica jest pusta \n";
			}

			else
			{
				licznik = 0;
				czasStart();
				int *temp = new int[rozmiar - 1];

				//Przepisz elementy starej tablicy poza ostatnim
				for (int i = 0; i < rozmiar - 1; i++) {
					temp[i] = w[i];
				}

				delete[] w;
				w = temp;
				rozmiar--;
				pobierzCzas();

			}
		}


		void Tablica::dodaj_losowo(int wartosc) {
			
			if (rozmiar == 0) {
				dodaj_kon(wartosc);
			}
			else {
				int index = generuj();
				index = index%rozmiar;
				dodaj_element(index, wartosc);
			}
		}

	void Tablica::usun_losowo() {
		if (rozmiar == 0) {
			std::cout << "Tablica jest pusta \n";
		}

		else
		{
			licznik = 0;
			czasStart();

			int index = generuj();
			index = index%rozmiar;
			usun_element(index);

			pobierzCzas();
			//relokacja();
		}

	}

	void Tablica::wczytaj(std::string nazwa) {
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
	void Tablica::sprawdz(int wartosc){
		int index;
		for (int i = 0; i < rozmiar; i++) {
			if (w[i] == wartosc) {
				index = i;
				std::cout << "Znaleziono liczbe " << wartosc << " na " << index << " pozycji tablicy \n";
				return;
			}
		}std::cout << "Nie znaleziono liczby w tablicy \n";

	}
	Tablica:: ~Tablica() { 
				//std::cout << "Uruchomiono destruktor tablicy \n"; 
				rozmiar = 0;
				delete[]w;
}