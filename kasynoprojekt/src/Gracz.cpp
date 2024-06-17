#include "Gracz.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Gracz::Gracz(){
    srand(time(0));
    balance = rand()%900+100;
}

void Gracz::setBalance(int amount){
    Gracz::balance = amount;
}
void Gracz::setName(string name){
    Gracz::name = name;
}
int Gracz::getBalance(){
    return Gracz::balance;
}
string Gracz::getName(){
    return Gracz::name;
}
void Gracz::updateBalance(int amount){
    Gracz::balance = Gracz::balance + amount;
}
void Gracz::minusBalance(int amount){
    Gracz::balance = Gracz::balance - amount;
}
void Gracz::addWygrana(int amount){
    Gracz::wygrana = Gracz::wygrana + amount;
}
int Gracz::getWygrana(){
    return Gracz::wygrana;
}

int Gracz::wybor(int minimum, int maximum){
    int wybrana;
    cout << ">> ";
    cin >> wybrana;
    while (cin.fail() || wybrana > maximum || wybrana < minimum) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Wystapil blad! Wybierz liczbe z zakresu (" << minimum << ", " << maximum << "): ";
        cout << ">> ";
        cin >> wybrana;
    }
    return wybrana;
}

void Gracz::lista(){
    int wygrana = Gracz::wygrana;
    string name = Gracz::name;
    string *gracz = new string[100];
    int *wygrane = new int[100];

    for (int i=0;i<100;i++){
        gracz[i] = "-";

        wygrane[i] = 0;

    }
    ifstream plik("top100.txt");
    string g;
    string l;
    int i=0;
    while (i < 100 && getline(plik,g) && getline(plik,l)){
        gracz[i] = g;
        wygrane[i] = stoi(l);
        i++;
    }
    plik.close();
    gracz[99] = name;
    wygrane[99] = wygrana;

      for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100 - i; j++) {
            if (wygrane[j] < wygrane[j + 1]) {
                swap(wygrane[j], wygrane[j + 1]);
                swap(gracz[j], gracz[j + 1]);
            }
        }
    }
    ofstream zapis("top100.txt");
    for (int j = 0; j < 100; j++) {
        zapis << gracz[j] << endl;
        zapis << wygrane[j] << endl;
    }
    zapis.close();


    delete[] gracz;
    delete[] wygrane;
}
void Gracz::getLista(){
    ifstream plik("top100.txt");
    string g;
    string l;
    string numerek;
    int i=0;
    while (i < 100 && getline(plik,g) && getline(plik,l)){
        g.insert(0, to_string(i+1).append("."));
        cout << g << endl;
        cout << l << endl;
        i++;
    }

    plik.close();
}

