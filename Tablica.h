#pragma once
#ifndef TABLICA_H
#define TABLICA_H

#include "Struktura.h"

class Tablica : public Struktura
{
	//public: int rozmiar; //liczba okreslajaca ilosc elementow
	int *w;	//wskaznik na tablice


public: Tablica(); //konstruktor klasy Tablica
		void wyswietl_tablice(); //funkcja do wyswietlania tablic
		void usun_element(int index); //usuwanie elementu z indeksie
		void dodaj_element(int index, int wartosc); //dodanie elementu na indeks
		//void relokacja(); //funkcja relokujaca tablice

		void dodaj_pocz(int wartosc); //dodaje na poczatek
		void usun_pocz(); //usuwa z poczatku

		void dodaj_kon(int wartosc); //dodaje na koniec
		void usun_kon(); //usuwa z konca
		
		void dodaj_losowo(int wartosc); //dodaje losowa wartosc na losowe miejsce
		void usun_losowo();//usuwa z losowej pozycji

		void wczytaj(std::string nazwa); //funkcja do wczytywania tablicy z pliku
		void sprawdz(int wartosc);
		~Tablica(); //destruktor tablicy
};
#endif