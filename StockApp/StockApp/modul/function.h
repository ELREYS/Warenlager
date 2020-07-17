//
//  function.cpp
//  StockApp
//
//  Created by MMBBS0000 on 17.07.20.
//  Copyright © 2020 gditdev. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

struct user{
    string fname;
    string lname;
    int kdnmr;
    string phone;
};

struct produkt
{

    string Produktname;
    float Preis;
    int Menge;
    
    
};

user registration(){
    
    user tmp;
    cout << "Please add your  first name!" << endl;
    cin >> tmp.fname;
    cout << "Please add your  last name!" << endl;
    cin >> tmp.lname;
    cout << "Please add your  Client Number:" << endl;
    int guid = tmp.kdnmr = rand() % 100;
    tmp.kdnmr = guid;
    cout << "Please add your   Phone" << endl;
    cin >> tmp.phone;
     return tmp;
}

void printUserDetail(user userDetails){
    
    cout << "UserName:" << userDetails.fname << endl;
    cout << "LastName:" << userDetails.lname << endl;
    cout << "Client Number:" << userDetails.kdnmr << endl;
    cout << "Phones:" << userDetails.phone << endl;
        
    
}

int checkWarenCode(int eingabe, int max)
{

    if (eingabe > max)
    {

        return 0;
    }
    return 1;
}

int getWarenBestand(produkt liste[], int eingabe)
{
    int rest =  liste[eingabe].Menge;
    
    return rest;
}

int subItemStock(produkt liste[], int eingabe, int summ)
{
    int total, auswahl;
    
    int menge = liste[eingabe].Menge;
    total = menge - summ;
    if (summ > menge)
    {
        cout << "Achtung Ware ist nicht vorhanden, muss bestellt werden\n [1] JA [2] Beeden" << endl;
        cin >> auswahl;
        if (auswahl)
        {
            liste[eingabe].Menge = total;
            return 0;
        }
        else
        {
            liste[eingabe].Menge = total;
            return -1;
        }
    }
    else
    {
        liste[eingabe].Menge= total;
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

int bestellen(produkt  liste[], int eingabe, int bestellmenge)
{

    int total;

    total = subItemStock(liste, eingabe, bestellmenge);

    return total;
}

float totalPrice(produkt  liste[], int eingabe, int bestellmenge,float currentTotal = 0.0){
    float result = 0.0;
    result = result + currentTotal;
    return result =  result + bestellmenge * liste[eingabe].Preis;
    
    
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


