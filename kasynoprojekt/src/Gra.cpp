#include "Gra.h"
#include <iostream>
#include "Ruletka.h"
#include "Gracz.h"
#include <time.h>

using namespace std;


Gra::Gra(Gracz &G){
    Gra::menu();
}

void Gra::menu(){
    while(true){
    cout <<"W co chcesz zagrac\n1.Ruletka\n2.Jednoreki bandyta\n3.Blackjack\n4.Wyjscie"<<endl;
    int wybor;
    cin >> wybor;
    switch(wybor){
        case 1:{
            Ruletka * R = new Ruletka(*G);
            delete R;
            break;
        }

        case 4:{
        cout <<"Zapraszamy Ponownie :-D"<<endl;
        return;
        }
        default:
            cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
            break;
    }}}
