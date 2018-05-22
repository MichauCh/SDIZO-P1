#pragma once
#ifndef LISTA_H
#define LISTA_H

#include "Struktura.h"

struct Memb {
	public:
		Memb *next, *prev;
		int klucz;

};
class Lista : public Struktura
{
	//public:
		//int rozmiar;
	private:
		Memb *glowa, *ogon;
	public:
		Lista();
		void wyswietl();

		void dodaj_pocz(int klucz);
		void usun_pocz();

		void dodaj_kon(int klucz);
		void usun_kon();

		void dodaj_losowo(int klucz);
		void usun_losowo();

		void sprawdz(int klucz);
		void usun_klucz(int klucz);
		void zapelnij_losowo(int ile);
		void wczytaj(std::string nazwa);

		~Lista();
};
#endif