#pragma once
#ifndef KOPIEC_H
#define KOPIEC_H
#include "Struktura.h"

class Kopiec : public Struktura  //kopiec http://eduinf.waw.pl/inf/alg/001_search/0113.php
{
//public
	//int rozmiar;

private:
	int *w;
	std::string cr, cl, cp;      // ³añcuchy do znaków ramek
public:
	Kopiec();
	void wczytaj(std::string nazwa);
	
	void wyswietl();
	void popraw();
	void szukaj(int wartosc);
	//void relokacja();
	void dodaj(int wartosc);
	void usun(int wartosc);
	void usun_korzen();
	void wyswietl_kopiec(std::string sp, std::string sn, int v);
	~Kopiec();

};
#endif