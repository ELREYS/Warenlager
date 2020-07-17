#include <iostream>
using namespace std;

struct produkt
{
    string Produktname;
    float Preis;
};

int bestand[3] = {2, 14, 3};
int eingabe, auswahl, anzahl, total;

int bestellen(int eingabe, int stk, int anzahl)
{
    int tmp;
    tmp = stk - anzahl;
    bestand[eingabe] = eingabe;
    return stk;
}