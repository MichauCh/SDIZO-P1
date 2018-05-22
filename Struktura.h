#pragma once
#ifndef STRUKTURA_H
#define STRUKTURA_H

#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <tchar.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <math.h>
#include <string>
#include <sstream>
#include <random>
#include <iomanip>

//#include "Tablica.h"
//#include "Kopiec.h"
//#include "Lista.h"
//#include "Drzewo.h"
//#include "Testy.h"
using namespace std;

class Struktura 
{
public:
	int rozmiar;
	double PCFreq = 0.0;
	__int64 licznik = 0;

public:
	void wczytaj(std::string nazwa);
	void wyswietl();
	int generuj();

	void czasStart();
	void pobierzCzas();
};

#endif