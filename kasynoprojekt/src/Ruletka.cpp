#include "Ruletka.h"
#include <time.h>
#include <iostream>
#include "Gra.h"
#include "Gracz.h"

using namespace std;

Ruletka::Ruletka(Gracz &G) : gracz(G), liczba(0), stawka(0), wygrana(0), kolor(0), nazwaK("") {}
void Ruletka::play() {
    cout << "Wybrales opcje ruletka" << endl;
    cout << "O jaka stawke grasz: ";
    Ruletka::stawka = gracz.wybor(1, gracz.getBalance());
    gracz.minusBalance(Ruletka::stawka);
    cout << "\n" << gracz.getName() << ", $" << gracz.getBalance() << endl;
    Ruletka::displayMenu();
    gracz.updateBalance(Ruletka::wygrana);
    gracz.addWygrana(Ruletka::wygrana);

}

void Ruletka::displayMenu(){
Ruletka::wygrana = 0;


    srand(time(0));
    Ruletka::spin();

    cout <<"Jaki tryb wybierasz:\n1. Kolor\n2. Pojedynczy numer\n3. Dwa numery\n4. Zakres numerow [1-18]/[19-36]" << endl;
    int choice;
    int numer;
    int numer2;
    choice = gracz.wybor(1,4);

    switch (choice) {
        case 1:{
            cout <<"Wybierz kolor:\n1.Czerwony\n2.Czarny" << endl;
            numer = gracz.wybor(1, 2);
            cout << "\nWylosowane: " << liczba << " " << nazwaK << endl;
            if(numer == kolor){
                cout << "Gratulacje wygrales $" << Ruletka::stawka*2 << endl;
                Ruletka::wygrana = Ruletka::stawka*2;

            }else cout << "Przegrana" << endl;
            }
        break;
        case 2:{
            cout <<"Jaki numer wybierasz[0-36]: ";
            numer = gracz.wybor(0,36);
            cout << "\nWylosowana liczba: " << liczba << endl;
            if (numer == liczba){
                cout << "Gratulacje wygrales $" << Ruletka::stawka*36 << endl;
                Ruletka::wygrana = Ruletka::stawka*36;
                }
            else cout << "Przegrana" << endl;
            break;}
        case 3:{
            cout << "Podaj pierwszy numer[0-36]: ";
            numer = gracz.wybor(0,36);
        do {
            cout << "Podaj drugi numer [0-36]: ";
            numer2 = gracz.wybor(0, 36);

            if (numer2 == numer) {
            cout << "Drugi numer nie moze byc taki sam jak pierwszy! Sprobuj ponownie." << endl;
        }
    } while (numer2 == numer);
            cout << "\nWylosowana liczba: " << liczba << endl;
            if(numer == liczba || numer2 == liczba){
                cout << "Gratulacje wygrales $" << Ruletka::stawka*18 << endl;
                Ruletka::wygrana = Ruletka::stawka*18;
            }else{
                cout << "Przegrana" << endl;
            }
            break;}
        case 4:{
            cout << "Ktory zakres wybierasz:\n1.[1-18]\n2.[19-36]" << endl;
            numer = gracz.wybor(1,2);
            cout << "\nWylosowana liczba: " << liczba << endl;
            if((numer == 1 && liczba > 0 && liczba < 19) || (numer == 2 && liczba > 18 && liczba < 37)){
                cout << "Gratulacje wygrales $" << Ruletka::stawka*2 << endl;
                Ruletka::wygrana = Ruletka::stawka*2;
            }else{
                cout << "Przegrana" << endl;
            }
            break;}
        default:
            cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
            Ruletka::displayMenu();
            break;
    }


}
void Ruletka::spin(){
    liczba = rand() % 37;
    switch(liczba){
        case 0:{
            kolor = 0;
            nazwaK = "Zielony";
            break;
        }
        case 1: case 3: case 5: case 7: case 9: case 12: case 14: case 16:
        case 18: case 19: case 21: case 23: case 25: case 27: case 30:
        case 32: case 34: case 36:{
            kolor = 1;
            nazwaK = "Czerwony";
            break;
        }
        default:{
            kolor = 2;
            nazwaK = "Czarny";
        }
    }
}

