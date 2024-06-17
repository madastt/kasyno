#include "JednorekiBandyta.h"
#include "Gra.h"
#include "Gracz.h"
#include <iostream>
#include <time.h>

JednorekiBandyta::JednorekiBandyta(Gracz &G):gracz(G), stawka(0){}

void JednorekiBandyta::play(){
    cout << "Wybrales opcje Jednoreki Bandyta" << endl;
    cout << "O jaka stawke grasz: ";
    JednorekiBandyta::stawka = gracz.wybor(1, gracz.getBalance());
    gracz.minusBalance(JednorekiBandyta::stawka);
    cout << "\n" << gracz.getName() << ", $" << gracz.getBalance() << endl;
    JednorekiBandyta::displayMenu();
    gracz.updateBalance(JednorekiBandyta::wygrana);
    gracz.addWygrana(JednorekiBandyta::wygrana);


}
void JednorekiBandyta::displayMenu(){
    JednorekiBandyta::wygrana = 0;
    srand(time(0));
    int wygrana = 0;
    int liczba;
    int siedemC = 0;
    int dzwonC = 0;
    int pomaranczC = 0;
    int cytrynC = 0;
    int wisniaC = 0;
    int mnoznik = 0;
    string wynik;
    string symbole[5] = {"wisnia","cytryna","pomarancza","dzwon","7"};
    cout << "-----" << endl;
    for(int i=0;i<3;i++){
    liczba = rand() % 20;
    if(liczba == 0){wynik = symbole[4]; siedemC++;}
    else if(liczba > 0 && liczba < 3) {wynik = symbole[3]; dzwonC++;}
    else if(liczba > 2 && liczba < 7) {wynik = symbole[2]; pomaranczC++;}
    else if(liczba > 6 && liczba < 12) {wynik = symbole[1]; cytrynC++;}
    else {wynik = symbole[0]; wisniaC++;}
    cout << wynik << endl;
    }
    cout << "-----" << endl;
    if(wisniaC == 3) {mnoznik = 17; cout << "3 wisnie mnoza razy 17" << endl;}
    if(wisniaC == 2) {mnoznik = 2; cout << "2 wisnie mnoza razy 2" << endl;}
    if(cytrynC == 3) {mnoznik = 65; cout << "3 cytryny mnoza razy 65" << endl;}
    if(pomaranczC == 3) {mnoznik = 125; cout << "3 pomarancze mnoza razy 125" << endl;}
    if(dzwonC == 3) {mnoznik = 1000; cout << "3 dzwony mnoza razy 1000" << endl;}
    if(siedemC == 3) {mnoznik = 8000; cout << "3 siodemki mnoza razy 8000" << endl;}

    if(mnoznik == 0){
         cout << "Przegrana" << endl;
    }
    else {
        cout << "Gratulacje wygrales $" << JednorekiBandyta::stawka*mnoznik << endl;
        JednorekiBandyta::wygrana = JednorekiBandyta::stawka*mnoznik;
    }



}
