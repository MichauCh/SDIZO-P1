// main.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//
#pragma once
#include "Struktura.h"
#include "Tablica.h"
#include "Kopiec.h"
#include "Lista.h"
#include "Drzewo.h"
#include "Testy.h"

int main()
{
	while (true) {
		int wybor;
		std::cout << "Wybierz strukture do testow \n" << "1. Tablica \n" << "2. Lista \n" << "3. Kopiec \n"
			<< "4. Drzewo czerwono-czarne \n" << "5. Testy do sprawozdania \n";
		std::cin >> wybor;


		system("cls");
		switch (wybor)
		{
		case 1:
		{
			Tablica* tab;
			tab = new Tablica();
			int ile;
			while (true)
			{
				std::cout << "Tablica ma  " << tab->rozmiar << " elementow \n" << "Co dalej? \n"
					<< "1. Wczytaj z pliku \n" << "2. Dodaj element \n" << "3. Usun element \n" << "4. Wyszukaj po kluczu \n"
					<< "5. Wyswietl \n" << "6. Zniszcz tablice \n" << "7. Zakoncz program \n";
				std::cin >> wybor;

				switch (wybor)
				{
				case 1: {
					string nazwa;
					tab = new Tablica();
					std::cout << "Pierwsza liczba w pliku bedzie rozmiarem tablicy \n"
						<< "Podaj nazwe pliku do wczytania danych \n";
					std::cin >> nazwa;
					std::cout << "\n";
					tab->wczytaj(nazwa);
				} break;

				case 3: {
					//int  wartosc;
					std::cout << "1. Usun z poczatku \n" << "2. Usun z konca \n" <<
						"3. Usun po indeksie \n" << "4. Usun element wybrany losowo \n";
					std::cin >> wybor;
					switch (wybor)

					{

					case 1:
					{
						tab->usun_pocz();

					}break;

					case 2:
					{
						tab->usun_kon();
					}break;
					case 3: {
						while (true)
						{
							std::cout << "Podaj indeks elementu do usuniecia \n";
							std::cin >> ile;
							std::cout << "\n";
							if (ile < 0)
								std::cout << "Nieprawidlowy indeks \n";
							else break;
						}

						tab->usun_element(ile);

					}break;
					case 4: {
						tab->usun_losowo();

					}break;

					}

				}break;
				case 2: {
					int  wartosc;
					std::cout << "1. Dodaj na poczatek \n" << "2. Dodaj na koniec \n" <<
						"3. Dodaj wybrana liczbe na wybrany indeks \n" << "4. Dodaj wybrana liczbe w losowe miejsce \n";
					std::cin >> wybor;
					switch (wybor)

					{

					case 1:
					{
						std::cout << "Podaj wartosc nowego elementu \n";
						std::cin >> wartosc;
						std::cout << "\n";
						tab->dodaj_pocz(wartosc);


					}break;

					case 2:
					{
						std::cout << "Podaj wartosc nowego elementu \n";
						std::cin >> wartosc;
						std::cout << "\n";
						tab->dodaj_kon(wartosc);
					}break;
					case 3: {
						while (true)
						{
							std::cout << "Podaj indeks na ktory zostanie wpisany nowy element \n";
							std::cin >> ile;
							std::cout << "\n";
							if (ile < 0)
								std::cout << "Podaj liczbe wieksza od zera! \n";
							else break;
						}

						std::cout << "Podaj wartosc nowego elementu \n";
						std::cin >> wartosc;
						std::cout << "\n";
						tab->dodaj_element(ile, wartosc);
					}break;
					case 4: {
						std::cout << "Podaj wartosc nowego elementu \n";
						std::cin >> wartosc;
						std::cout << "\n";
						tab->dodaj_losowo(wartosc);
					}break;
					}break;

				case 4: {
					int  wartosc;
					std::cout << "Podaj wartosc ktorej szukasz \n";
					std::cin >> wartosc;
					std::cout << "\n";
					tab->sprawdz(wartosc);
				}break;
				case 5: {
					tab->wyswietl_tablice();
				}break;
				case 6: {
					tab->~Tablica();
					tab = new Tablica();
				}break;

				case 7: {
					delete tab;
					return 0;
				}break;
				}
				}
			}break;
		case 2: {

			unsigned ile;
			Lista* lista;
			lista = new Lista();

			while (true) {
				std::cout << "Lista o dlugosci " << lista->rozmiar << "\n" << "Co chcesz zrobic? \n"
					<< "1. Wczytaj z pliku \n" << "2. Stworz liste z losowych elementow\n" << "3. Usun element \n" << "4. Dodaj \n" <<
					"5. Wyswietl \n" << "6. Wyszukaj wartosc po kluczu \n" << "7. Zniszcz liste \n" << "8. Zakoncz program \n";
				std::cin >> wybor;
				switch (wybor)
				{
				case 1: {
					lista->~Lista();
					lista = new Lista();
					std::string nazwa;
					std::cout << "Podaj nazwe pliku \n";
					std::cin >> nazwa;
					std::cout << "\n";
					lista->wczytaj(nazwa);
				}break;
				case 2: {
					lista->~Lista();
					while (true)
					{
						std::cout << "Ilu elementowa liste stworzyc? \n";
						std::cin >> ile;
						std::cout << "\n";
						if (ile <= 0)
							std::cout << "Wprowadzono zla wartosc \n";
						else break;
					}
					lista = new Lista();
					lista->zapelnij_losowo(ile);
				}break;
				case 3: {
					//int  wartosc;
					std::cout << "1. Usun z poczatku \n" << "2. Usun z konca \n" << "3. Usun wybrany element \n" << "4. Usun element z losowej pozycji \n";
					std::cin >> wybor;
					switch (wybor)

					{

					case 1:
					{
						lista->usun_pocz();

					}break;

					case 2:
					{
						lista->usun_kon();
					}break;
					case 3: {

						std::cout << "Podaj klucz elementu do usuniecia \n";
						std::cin >> ile;
						std::cout << "\n";
						lista->usun_klucz(ile);

					}break;
					case 4: {
						lista->usun_losowo();

					}break;

					}

				}break;

				case 4: {
					int  wartosc;
					std::cout << "1. Dodaj na poczatek \n" << "2. Dodaj na koniec \n" << "3. Dodaj na losowe miejsce \n";
					std::cin >> wybor;
					switch (wybor)

					{
					case 1:
					{
						std::cout << "Podaj klucz nowego elementu \n";
						std::cin >> wartosc;
						std::cout << "\n";
						lista->dodaj_pocz(wartosc);

					}break;

					case 2:
					{
						std::cout << "Podaj klucz nowego elementu \n";
						std::cin >> wartosc;
						std::cout << "\n";
						lista->dodaj_kon(wartosc);
					}break;
					case 3: {
						std::cout << "Podaj klucz nowego elementu \n";
						std::cin >> wartosc;
						std::cout << "\n";
						std::cout << "Podana liczba zostanie wpisana na losowe miejsce \n";
						lista->dodaj_losowo(wartosc);

					}break;

					}



				}break;

				case 5: {
					lista->wyswietl();
				}break;
				case 6: {
					int val = lista->generuj();
					val = val % 200000 - 100000;
					lista->sprawdz(val);


				}break;
				case 7: {
					lista->~Lista();
					lista = new Lista();


				}break;

				case 8: {
					delete lista;
					return 0;
				}break;

				}


			}break;
		}break;
		case 3: {
			int ile;
			system("cls");
			Kopiec *kopiec;
			kopiec = new Kopiec();
			while (true)
			{
				std::cout << "Kopiec o ilosci elementow " << kopiec->rozmiar << "\n" << "Co chcesz zrobic? \n" <<
					"1.Wczytaj z pliku \n" << "2. Usun \n" << "3. Dodaj \n" << "4. Wyszukaj \n" <<
					"5. Wyswietl \n" << "6. Zniszcz \n" << "7. Zakoncz program \n";
				std::cin >> wybor;

				switch (wybor)
				{
				case 1: {
					string nazwa;
					std::cout << "Podaj nazwe pliku \n";
					std::cin >> nazwa;
					std::cout << "\n";
					kopiec = new Kopiec();
					kopiec->wczytaj(nazwa);
				}break;

				case 2: {
					std::cout << "1. Usuwanie korzenia \n2. Usuwanie po kluczu \n";
					std::cin >> wybor;
					switch (wybor) {
					case 1:
					{
						kopiec->usun_korzen();
					}break;
					case 2: {
						std::cout << "Jaki klucz usunac? \n";
						std::cin >> ile;
						std::cout << "\n";
						kopiec->usun(ile);
					}break;
					}
				}break;

				case 3: {
					std::cout << "Podaj klucz elementu do wstawienia \n";
					std::cin >> ile;
					std::cout << "\n";
					kopiec->dodaj(ile);


				}break;

				case 4: {
					std::cout << "Podaj wartosc, ktora chcesz sprawdzic \n";
					std::cin >> ile;
					std::cout << "\n";
					kopiec->szukaj(ile);

				}break;
				case 5: {
					kopiec->wyswietl();
				}break;
				case 6: {
					kopiec->~Kopiec();
					kopiec = new Kopiec();
				}break;

				case 7: {
					delete kopiec;
					return 0;
				}break;
				}
			}

		}break;
		case 4: {
			Drzewo* rb;
			rb = new Drzewo();

			while (true) {
				std::cout << "Drzewo czerwono-czarne ma " << rb->rozmiar << " elementow \n" << "Co chcesz zrobic? \n"
					<< "1. Wczytaj z pliku \n" << "2. Dodaj element \n" << "3. Usun element \n" << "4. Wyszukaj \n" <<
					"5. Wyswietl \n" << "6. Zniszcz drzewo \n" << "7. Zakoncz program \n";
				std::cin >> wybor;
				switch (wybor)
				{
				case 1: {
					rb->~Drzewo();
					rb = new Drzewo();
					string nazwa;
					std::cout << "Podaj nazwe pliku \n";
					std::cin >> nazwa;
					std::cout << "\n";
					rb->wczytaj(nazwa);
				}break;

				case 2: {
					int  wartosc;
					std::cout << "Wprowadz klucz, ktory zostanie dodany do drzewa \n";
					std::cin >> wartosc;

					rb->dodaj(wartosc);

				}break;

				case 3: {
					int  wartosc;
					std::cout << "Podaj klucz elementu, ktory chcesz usunac \n";
					std::cin >> wartosc;
					rb->usun(wartosc);

				}break;

				case 4: {
					int wartosc;
					std::cout << "Podaj klucz elementu, ktory chcesz sprawdzic \n";
					std::cin >> wartosc;
					rb->sprawdz(wartosc);
				}break;
				case 5: {
					rb->print();
				}break;

				case 6: {
					rb->usun_drzewo();
				}break;
				case 7: {
					delete rb;
					return 0;
				}break;
				}


			}break;
		}break;
		case 5: {
			system("cls");
			Testy t;
			while (true) {
				std::cout << "Wybierz strukture do testow \n" << "1. Tablica \n" << "2. Lista \n" << "3. Kopiec \n"
					<< "4. Drzewo czerwono-czarne \n";
				std::cin >> wybor;
				switch (wybor) {

				case 1:
					t.test_tablicy();
					break;
				case 2:
					t.test_listy();
					break;
				case 3:
					t.test_kopca();
					break;
				case 4:
					t.test_drzewa();
					break;
				}
			}
		}
				system("pause");

				return 0;
		}
		}
	}
}