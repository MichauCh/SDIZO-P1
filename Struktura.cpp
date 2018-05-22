#include "Struktura.h"

void Struktura::wczytaj(std::string nazwa){}

void Struktura::wyswietl() {}

int Struktura::generuj() //przerobiony kod ze strony http://staff.iiar.pwr.wroc.pl/antoni.sterna/sdizo/SDiZO_random.pdf
{
		int val;
		random_device rd; // non-deterministic generator
		mt19937 gen(rd()); // random engine seeded with rd()
		uniform_int_distribution <> dist(1, 1000000); // distribute results between 
		// 1 and 1000000 inclusive
			val = dist(gen);
		return(val);
}
void Struktura:: czasStart() { //kod z http://stackoverflow.com/questions/1739259/how-to-use-queryperformancecounter
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		std::cout << "Blad pomiaru czasu \n";

	PCFreq = double(li.QuadPart)/ 1000000.0; //milisekundy
	

	QueryPerformanceCounter(&li);
	licznik = li.QuadPart;
}
void Struktura:: pobierzCzas() {
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	std::cout << "Czas operacji : " << (li.QuadPart - licznik) / PCFreq << " milisekund \n";

}
