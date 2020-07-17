#include <iostream>
#include "modul/funktionen.h"

using namespace std;

produkt Produkt1;

int checkWarenCode(int eingabe, int max)
{

    if (eingabe > max)
    {

        return 0;
    }
    return 1;
}

int getWarenBestand(int liste[], int eingabe)
{
    return liste[eingabe];
}

int subItemStock(int liste[], int eingabe, int summ, int err)
{
    int total, auswahl;
    int result;
    total = liste[eingabe] - summ;
    if (summ > liste[eingabe])
    {
        cout << "Achtung Ware ist nicht vorhanden, muss bestellt werden\n [1] JA [2] Beeden" << endl;
        cin >> auswahl;
        if (auswahl)
        {
            liste[eingabe] = total;
            return 0;
        }
        else
        {
            liste[eingabe] = total;
            return -1;
        }
    }
    else
    {
        liste[eingabe] = total;
        return total;
    }
}

int checkMenge(int menge)
{

    if (menge < 0)
    {
        cout << "Keine Ware Bitte bestellen." << endl;
        return 0;
    }

    else if ((menge > 0) && (menge <= 10))
    {
        cout << "Nur noch: " << menge << " Bitte bestellen." << endl;
        return 1;
    }
    else
    {
        cout << "Stk: " << menge << endl;
        return 2;
    }
}

int checkBestellmenge(int code)
{

    if (code == -1)
    {
    }
    else
    {
        return code;
    }

    return code;
}

int bestellen(int bestand[], int eingabe, int bestellmenge)
{

    int errorcode;

    total = subItemStock(bestand, eingabe, bestellmenge, errorcode);

    return total;
}

string weiterShoppen()
{
    int bestellenAuswahl;
    cout << "Wollt ihr  weiter shoppen.\n[1] JA [2] Beenden" << endl;
    cin >> bestellenAuswahl;
    if (bestellenAuswahl == 1)
    {

        return "N";
    }
    else
    {

        return "J";
    }
}

int main()
{
    int bestand[3] = {5, 14, 0};
    int eingabe, auswahl, check, bestellmenge, bestellenAuswahl, errorcode;
    string beenden = "N";
    cout << "Willkomen:Bitte wählen sie:\n[1] Bestellen [2] Lagerbestand" << endl;
    cin >> auswahl;
    while (beenden != "J")
    {
        //Bestellen
        if (auswahl == 1)
        {
            cout << "Bitte Artikelnummer eingeben: ";
            cin >> eingabe;

            checkWarenCode(eingabe, 3) == 1 ? check = true : check = false;
            if (check)
            {
                int code = checkMenge(getWarenBestand(bestand, eingabe));
                if (code == 2)
                {
                    //BestellProzess
                    cout << "Wie viele Stücke bestellen:" << endl;
                    cin >> bestellmenge;
                    checkBestellmenge(bestellen(bestand, eingabe, bestellmenge));
                    cout << "Vielen Dank für Ihre Bestellung\n"
                         << "[" << bestellmenge << "] - Stk"
                         << " wurden erfolgreich bestellt!" << endl;
                    cout << "-----------------------------------------------------------\n";

                    beenden = weiterShoppen();
                    //cout << "LagerStand: " << bestand[eingabe] << endl;
                }
                else if (code == 1)
                {
                    //BestellProzess
                    cout << "Wie viele Stücke bestellen:" << endl;
                    cin >> bestellmenge;
                    cout << "Nur noch: " << getWarenBestand(bestand, eingabe) << endl;
                    cout << "Wollt ihr wirklick bestellen.\n[1] JA [2] Beenden" << endl;
                    cin >> bestellenAuswahl;
                    if (bestellenAuswahl == 1)
                    {
                        checkBestellmenge(bestellen(bestand, eingabe, bestellmenge));
                        cout << "Vielen Dank für Ihre Bestellung\n"
                             << endl;
                        beenden = weiterShoppen();
                    }
                    else
                    {

                        beenden = "J";
                    }
                }
                else
                {
                    beenden = "J";
                }
            }
        }
        //Lagerbestand
        else
        {
            cout << "Bitte Artikelnummer eingebenQQQ: ";
            cin >> eingabe;
            checkWarenCode(eingabe, 3) == 1 ? check = true : check = false;
            if (check)
            {

                checkMenge(getWarenBestand(bestand, eingabe));
                cout << "Wollen Sie bestellen?" << endl;
                cout << "[1] JA [2] NEIN" << endl;
                ;
                cin >> bestellenAuswahl;
                if (bestellenAuswahl == 1)
                {
                    auswahl = 1;
                }
                else
                {
                    beenden = "J";
                }
            }
            else
            {
                cout << "Falsche Artikelnummer ";
                cout << " Auf wiedersehen" << endl;
                beenden = "J";
            }
            //Waren Index
        }
    }

    return 0;
}
