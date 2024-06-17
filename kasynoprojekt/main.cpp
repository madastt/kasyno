#include <iostream>
#include <cstdlib>
#include "Gracz.h"
#include <time.h>
#include <cctype>
#include "Ruletka.h"
#include "JednorekiBandyta.h"
#include "BlackJack.h"
#include "Gracz.h"

using namespace std;
Gra* wyborGry(int wybor, Gracz* G){
    switch(wybor){
        case 1:
            return new Ruletka (*G);
        case 2:
            return new JednorekiBandyta(*G);
        case 3:
        default:
            return new BlackJack(*G);
    }
}
int main()
{

    cout << "Witamy w kasynie.\nPodaj imie: ";
    string name;
    getline(cin,name);
    bool poprawne = true;
    do {
        poprawne = true;
        for (char c : name) {
            if (!isalpha(c)) {
                poprawne = false;
                break;
            }
        }
        if (!poprawne){
            cout << "Niepoprawne imie. Podaj imie, ktore zawiera tylko litery: ";
            getline(cin,name);}
    } while (!poprawne);

    Gracz * G = new Gracz;
    G->setName(name);
    cout<<"Witaj "<<G->getName()<<"!"<<endl;
    srand(time(0));
    while(true){
        if(G->getBalance() == 0){
            cout << "Jestes splukany nie mozesz grac :-(" << endl;
            cout <<"Zapraszamy Ponownie :-D"<<endl;
            break;
        }
        cout << "\n" << G->getName() << ", $" << G->getBalance() << endl;
        cout <<"W co chcesz zagrac\n1.Ruletka\n2.Jednoreki bandyta\n3.Blackjack\n4.Lista top 100\n5.Wyjscie"<<endl;
        int wybor;

        wybor = G->wybor(1,5);
        switch(wybor){
            case 1:
            case 2:
            case 3:{
                Gra* gra = wyborGry(wybor, G);
                gra->play();
                delete gra;
                break;
            }
            case 4:
                G->getLista();
                break;
            case 5:
                cout <<"Calkowita wygrana: "<< G->getWygrana() << endl;
                G->lista();
                cout <<"Zapraszamy Ponownie :-D"<<endl;
                delete G;
                return 0;
        }
    }
    delete G;
    return 0;
}
