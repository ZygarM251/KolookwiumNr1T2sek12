#include "zbior.h"
#include <new>
#include <random>

void Zbior::alokuj(int n)
{
	if (n > 0)
	{
		m_elementy = new(std::nothrow) double[n];
		m_liczbaElementow = n;
	}
}

void Zbior::zwolnij()
{
	if (m_elementy != nullptr)
	{
		delete[] m_elementy;
		m_elementy = nullptr;
	}
}

Zbior::Zbior(size_t liczElem, double dGran, double gGran)
{
	alokuj(liczElem);
	std::uniform_real_distribution<double> zakres(dGran, gGran);
	std::random_device generator;
	for (int elem = 0; elem < liczElem; elem++)
		m_elementy[elem] = zakres(generator);
}

vector<double> Zbior::toVector() const
{
	vector<double> result(m_elementy, m_elementy + m_liczbaElementow);
	sort(result.begin(), result.end());
	return result;
}

Zbior::Zbior(const list<double>& lista)
{
	// Za³ó¿my, ¿e lista nie jest pusta
	m_liczbaElementow = lista.size();
	alokuj(m_liczbaElementow);

	auto Lista = lista.begin();
	for (int elem = 0; elem < m_liczbaElementow; elem++, ++Lista)
		m_elementy[elem] = *Lista;

	// Ustaw granice na min i max wartoœci z listy
	m_dolnaGranica = *min_element(lista.begin(), lista.end());
	m_gornaGranica = *max_element(lista.begin(), lista.end());
}

Zbior::Zbior(const Zbior& zbr)
{
	if (zbr.m_elementy != nullptr)
	{
		alokuj(zbr.m_liczbaElementow);
		for (int i = 0; i < zbr.m_liczbaElementow; i++)
			this->m_elementy[i] = zbr.m_elementy[i];
	}
}

Zbior::Zbior(Zbior&& el)
{
	this->m_elementy = el.m_elementy;
	el.m_elementy = nullptr;
}
