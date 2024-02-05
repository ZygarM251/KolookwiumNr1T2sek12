#pragma once
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class Zbior
{
	size_t m_liczbaElementow = 0;
	double* m_elementy = nullptr;
	double m_dolnaGranica = 0;
	double m_gornaGranica = 0;
	void alokuj(int);
	void zwolnij();
public:
	Zbior(size_t liczElem, double dGran, double gGran);
	~Zbior() { zwolnij(); }

	//Zbior(const Zbior&) = delete;            // Konstruktor kopiuj�cy
	//Zbior& operator=(const Zbior&) = delete; // Operator przypisania kopiuj�cy
	//Zbior(Zbior&&) = delete;                 // Konstruktor przenosz�cy
	//Zbior& operator=(Zbior&&) = delete;      // Operator przypisania przenosz�cy

	// Konstruktor kopiuj�cy (implementacja dla g��bokiej kopii)
	Zbior(const Zbior& zbr);
	// Konstruktor przenosz�cy
	Zbior(Zbior&& el);
	// Operator przypisania kopiuj�cy (implementacja dla g��bokiej kopii)
	Zbior& operator=(const Zbior& other) = delete;
	// Operator przypisania przenosz�cy
	Zbior& operator=(Zbior&& other) = delete;

	double getDolnaGranica() const { return m_dolnaGranica; }
	double getGornaGranica() const { return m_gornaGranica; }

	vector<double> toVector() const;
	Zbior(const list<double>& lista);
};


class Funktor
{
private:
	const Zbior& zbiorFunktora;

public:
	explicit Funktor(const Zbior& zbior) : zbiorFunktora(zbior) {}

	bool operator()(double value) const
	{
		return (value >= zbiorFunktora.getDolnaGranica()) && (value <= zbiorFunktora.getGornaGranica());
	}
};