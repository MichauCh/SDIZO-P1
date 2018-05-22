#include "Testy.h"

void Testy::test_tablicy() {

	Tablica * tablica;
	tablica = new Tablica();
	int choice, ch2;
	int wartosc, r;
	std::string nazwa_pliku;


	while (true) {
		std::cout << "Wybierz funkcje tablicy \n" << "1.Dodaj \n"<< "2. Usun \n"<<
			"3. Wyszukaj po kluczu \n" << "4. Wyswietl \n";

		std::cin >> choice;

		cout << "Podaj nazwe pliku z danymi: ";
		cin >> nazwa_pliku;

		switch (choice) {

		case 1:
			tablica->wczytaj(nazwa_pliku);
			break;

		case 2:
			tablica->wczytaj(nazwa_pliku);
			std::cout << "1. Usun od poczatku \n" << "2. Usun od konca \n" << "3. Usun w losowej kolejnosci \n";
			std::cin >> ch2;
			switch (ch2) {
			case 1:
				tablica->licznik = 0;
				tablica->czasStart();
				while (tablica->rozmiar != 0) {
					tablica->usun_pocz();
				}
				tablica->pobierzCzas();
				break;

			case 2:
				tablica->licznik = 0;
				tablica->czasStart();
				while (tablica->rozmiar != 0) {
					tablica->usun_kon();
				}
				tablica->pobierzCzas();
					break;
			case 3:
				tablica->licznik = 0;
				tablica->czasStart();
				while (tablica->rozmiar != 0) {
					tablica->usun_losowo();
				}
				tablica->pobierzCzas();
				break;
			}
			break;

		case 3:
				tablica->wczytaj(nazwa_pliku);
				tablica->licznik = 0;
				tablica->czasStart();
				
				for (int i = 0; i < tablica->rozmiar; i++) {
					wartosc = tablica->generuj();
					wartosc = wartosc % 20000 - 10000;
					tablica->sprawdz(wartosc);
				}
				tablica->pobierzCzas();
			break;

		case 4:
			tablica->wczytaj(nazwa_pliku);

			tablica->licznik = 0;
			tablica->czasStart();
			tablica->wyswietl_tablice();
			tablica->pobierzCzas();
			break;

		}

	}
}
void Testy::test_listy() {

	Lista *lista;
	lista = new Lista();
	int choice;
	int wartosc, r;
	std::string nazwa_pliku;


	while (true) {
		std::cout << "Wybierz funkcje listy \n" << "1.Dodaj \n"<< "2. Usun \n"<<"3. Wyszukaj po kluczu \n" << "4. Wyswietl \n";

		std::cin >> choice;

		cout << "Podaj nazwe pliku z danymi: ";
		cin >> nazwa_pliku;

		switch (choice) {

		case 1:
			lista->wczytaj(nazwa_pliku);

			break;


		case 2: 
			lista->wczytaj(nazwa_pliku);

			std::cout << "1. Usun od poczatku \n" << "2. Usun od konca \n" << "3. Usun w losowej kolejnosci \n";
			std::cin >> choice;

			switch (choice) {
			case 1:
				lista->licznik = 0;
				lista->czasStart();
				while (lista->rozmiar != 0) {
					lista->usun_pocz();
				}
				lista->pobierzCzas();
				break;

			case 2:
				lista->licznik = 0;
				lista->czasStart();
				while (lista->rozmiar != 0) {
					lista->usun_kon();
				}
				lista->pobierzCzas();
				break;

			case 3:
				lista->licznik = 0;
				lista->czasStart();
				while (lista->rozmiar != 0) {
					lista->usun_losowo();
				}
				lista->pobierzCzas();
				break;
			}
		break;

		case 3:
			lista->wczytaj(nazwa_pliku);
			lista->licznik = 0;
			lista->czasStart();
			for (int i = 0; i < lista->rozmiar; i++) {
				lista->sprawdz((rand() % 20000 - 10000));
			}
			lista->pobierzCzas();
			break;

		case 4:
			lista->wczytaj(nazwa_pliku);
			lista->licznik = 0;
			lista->czasStart();
			lista->wyswietl();
			lista->pobierzCzas();
			break;

		}

	}
}
void Testy::test_kopca() {

	Kopiec* kopiec;
	kopiec = new Kopiec();
	int choice;
	int wartosc, r, cnt = 0;
	std::string nazwa_pliku;
	while (true) {
		std::cout << "Wybierz funkcje kopca \n" << "1. Dodaj \n" << "2. Usuwaj korzenie \n" << "3. Wyszukaj po kluczu \n" <<
			"4. Wyswietl kopiec \n";
		std::cin >> choice;
		cout << "Podaj nazwe pliku z danymi: ";
		cin >> nazwa_pliku;

		switch (choice) {
		case 1:

			kopiec->wczytaj(nazwa_pliku);
	
			break;
		case 2:

			kopiec->wczytaj(nazwa_pliku);
			kopiec->licznik = 0;
			kopiec->czasStart();
			while (kopiec->rozmiar != 0) {
				kopiec->usun_korzen();
			}
			kopiec->pobierzCzas();
			break;
		case 3:

			kopiec->wczytaj(nazwa_pliku);
			kopiec->licznik = 0;
			kopiec->czasStart();
			for(int i=0; i<kopiec->rozmiar; i++) {
				kopiec->szukaj(rand() % 20000 - 10000);
			}
			kopiec->pobierzCzas();
			break;
		case 4:

			kopiec->wczytaj(nazwa_pliku);

			kopiec->licznik = 0;
			kopiec->czasStart();
			kopiec->wyswietl();
			kopiec->pobierzCzas();
			break;
		}
	}
}
void Testy::test_drzewa() {

	Drzewo * rb;
	rb = new Drzewo();
	int choice;
	int wartosc, r, cnt = 0;
	std::string nazwa_pliku;
	TreeMemb *temp;
	while (true) {
		std::cout << "Wybierz funkcje drzewa czerwono-czarnego \n" << "1. Dodaj \n" << "2. Usun \n" << "3. Wyszukaj po kluczu \n" <<
			"4. Wyswietl drzewo \n";
		std::cin >> choice;
		cout << "Podaj nazwe pliku z danymi: ";
		cin >> nazwa_pliku;

		switch (choice) {
		case 1:
			rb->usun_drzewo();
			rb->wczytaj(nazwa_pliku);
			break;
		case 2:

			rb->wczytaj(nazwa_pliku);

			rb->licznik = 0;
			rb->czasStart();
			//while (rb->rozmiar != 0) {
				//temp = rb->get_korzen();
				//rb->usun_element(temp);
			//}
			rb->usun_drzewo();
			rb->pobierzCzas();
			break;
		case 3:

			rb->wczytaj(nazwa_pliku);
			rb->licznik = 0;
			rb->czasStart();
			for (int i = 0; i < rb->rozmiar; i++ ) {
				rb->sprawdz(rand() % 20000 - 10000);
			} 				rb->pobierzCzas();
			break;
		case 4:

			rb->wczytaj(nazwa_pliku);

			rb->licznik = 0;
			rb->czasStart();
			rb->print();
			rb->pobierzCzas();
			break;
		}
	}
}