#include <iostream>
#include <list>
#include <random>
#include "zbior.h"

using namespace std;

int main()
{
    // Tworzenie listy o losowej długości (np. od 5 do 10 elementów)
    random_device genLiczbyLosowe;
    uniform_int_distribution<int> liczbaElementowDistribution(5, 10);
    int liczbaElementow = liczbaElementowDistribution(genLiczbyLosowe);

    list<double> mojaLista;
    uniform_real_distribution<double> ZakresWartosci(1.0, 100.0);

    for (int i = 0; i < liczbaElementow; ++i)
        mojaLista.push_back(ZakresWartosci(genLiczbyLosowe));

    // Wyświetlenie zawartości listy
    cout << "Lista:";
    for (const auto& element : mojaLista)
        cout << " " << element;
    cout << endl;

    // Konwersja listy na wektor za pomocą klasy Zbior
    Zbior zbiorListy(mojaLista);
    vector<double> posortowanyWektor = zbiorListy.toVector();

    // Wyświetlenie zawartości posortowanego wektora
    cout << "Wektor po sortowaniu:";
    for (const auto& element : posortowanyWektor)
    {
        cout << " " << element;
    }
    cout << endl;


    Zbior zbiorFunktora(5, 1.0, 10.0);
    Funktor fun(zbiorFunktora);

    // Przykładowa lista wartości do sprawdzenia
    vector<double> valuesToCheck = { 3.0, 12.0, 5.5, 8.0, 15.0 };

    // Użycie funktora jako predykatu z algorytmem std::count_if
    int countWithinBounds = count_if(valuesToCheck.begin(), valuesToCheck.end(), fun);

    // Wyświetlenie wyniku
    cout << "Liczba wartości w granicach zbioru: " << countWithinBounds << endl;
}