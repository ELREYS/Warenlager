
#include <iostream>
#include "modul/function.h"

using namespace std;

produkt Produkt1[3];





int main()
{
    
    
    Produkt1[0].Produktname = "Messer";
    Produkt1[0].Preis = 1.60;
    Produkt1[0].Menge = 50;
    Produkt1[1].Produktname = "Teller";
    Produkt1[1].Preis = 7.90;
    Produkt1[1].Menge = 20;
    Produkt1[2].Produktname = "Tasse";
    Produkt1[2].Preis = 2.20;
    Produkt1[2].Menge = 10;
    
    //int bestand[3] = {5, 14, 0};
    int eingabe, auswahl, check, bestellmenge, bestellenAuswahl;
    float summeTotal = 0.0;
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
                int code = checkMenge(getWarenBestand(Produkt1, eingabe));
                if (code == 2)
                {
                    //BestellProzess
                    cout << "Wie viele Stücke bestellen:" << endl;
                    cin >> bestellmenge;
                    checkBestellmenge(bestellen(Produkt1, eingabe, bestellmenge));
                    summeTotal = totalPrice(Produkt1, eingabe, bestellmenge,summeTotal);
                    cout << "Total " << summeTotal << ".-" << endl;
                    user client = registration();
                    printUserDetail(client);
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
                    cout << "Nur noch: " << getWarenBestand(Produkt1, eingabe) << endl;
                    cout << "Wollt ihr wirklick bestellen.\n[1] JA [2] Beenden" << endl;
                    cin >> bestellenAuswahl;
                    if (bestellenAuswahl == 1)
                    {
                        checkBestellmenge(bestellen(Produkt1, eingabe, bestellmenge));
                        summeTotal = totalPrice(Produkt1, eingabe, bestellmenge,summeTotal);
                        cout << "Total " << summeTotal << ".-" << endl;
                        user client = registration();
                        printUserDetail(client);
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
                
                checkMenge(getWarenBestand(Produkt1, eingabe));
                cout << "Wollen Sie jetzt etwas bestellen?" << endl;
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
