#pragma once
#ifndef DRZEWO_H
#define DRZEWO_H
#include "Struktura.h"
//wlasnosci drzewa czerwono-czarnego http://eduinf.waw.pl/inf/alg/001_search/0121.php

struct TreeMemb{
public:
	TreeMemb *rodzic, *lewo, *prawo; //wskazniki

	char kolor; //r lub b
	int klucz; //wartosc elementu

};

class Drzewo : public Struktura 
{
private:
	TreeMemb *korzen;
	TreeMemb straznik; //pelni role lisci w drzewie
	std::string cr, cl, cp;       // £añcuchy do znaków ramek
//public
	//int rozmiar;
	public:
		Drzewo();
		~Drzewo();
		void usun_drzewo();
		void dodaj(int wartosc);
		void usun(int wartosc);
		void obrot_lewo(TreeMemb *element);
		void obrot_prawo(TreeMemb *element);
		void sprawdz(int wartosc);
		void wyswietl(std::string sp, std::string sn, TreeMemb * p);
		void wczytaj(std::string nazwa);

		void usun_element(TreeMemb *element);
		void znajdz_element(int wartosc, TreeMemb *korzen_elementu, TreeMemb *&element);
		void print();
		TreeMemb *znajdz_succ(TreeMemb *);
		void znajdz_klucz (int, TreeMemb *, bool &znalezione);
		TreeMemb *zwroc_szukany(int wartosc);
		TreeMemb *get_korzen();
		TreeMemb *znajdz_min(TreeMemb *p);
		
};

#endif