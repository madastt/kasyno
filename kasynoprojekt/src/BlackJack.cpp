#include "BlackJack.h"
#include <iostream>
#include <time.h>

using namespace std;

BlackJack::BlackJack(Gracz &G):gracz(G){
 for (int i = 0; i < 10; i++) {
        rekaGracza[i] = 0;
        rekaKrupiera[i] = 0;
    }
    punktyGracza = 0;
    punktyKrupiera = 0;
}

void BlackJack::play(){
    cout << "Wybrales opcje BlackJack" << endl;
    cout << "O jaka stawke grasz: \n";

    BlackJack::stawka = gracz.wybor(1, gracz.getBalance());
    gracz.minusBalance(BlackJack::stawka);
    cout << "\n" << gracz.getName() << ", $" << gracz.getBalance() << endl;
    BlackJack::displayMenu();
    gracz.updateBalance(BlackJack::wygrana);
    gracz.addWygrana(BlackJack::wygrana);




}

void BlackJack::displayMenu(){
    BlackJack::wygrana = 0;
    srand(time(0));
    BlackJack::drawCard('G');
    BlackJack::drawCard('D');
    BlackJack::drawCard('G');
    BlackJack::czyMaAsa(rekaGracza,indeksAsa);
    BlackJack::czyMaAsa(rekaKrupiera,indeksAsa);
    cout << "\nTwoje punkty: " << punktyGracza << AsGracz << endl;
    cout << "Punkty Krupiera: " << punktyKrupiera << AsKrupier << endl;

int wybor = 0;
  do{
    cout << "\nCo robisz:\n1.Dobieram karte\n2.Odkrywamy" << endl;
    wybor = gracz.wybor(1,2);
    if(wybor == 1){
        BlackJack::drawCard('G');
        BlackJack::czyMaAsa(rekaGracza,indeksAsa);
        cout << "\nTwoje punkty: " << punktyGracza << AsGracz << endl;
        cout << "Punkty Krupiera: " << punktyKrupiera << AsKrupier << endl;
        if(punktyGracza > 21){
            BlackJack::drawCard('D');
            cout << "Przegrana" << endl;
            return;
            }
   /*     else if(punktyGracza == 21){
            do{BlackJack::drawCard('D');}
            while(punktyKrupiera<17 || punktyKrupiera < punktyGracza);
                if(punktyGracza > punktyKrupiera){
                    cout << "Gratulacje wygrales $" << BlackJack::stawka*2 << endl;
                    BlackJack::wygrana = BlackJack::stawka*2;return;
                    }
                else if(punktyGracza == punktyKrupiera){
                    cout << "Remis, oddajemy ci stawke $" << BlackJack::stawka << endl;
                    BlackJack::wygrana = BlackJack::stawka;return;
                    return;}
                else if(punktyKrupiera > 21){
                    cout << "Gratulacje wygrales $" << BlackJack::stawka*2 << endl;
                    BlackJack::wygrana = BlackJack::stawka*2;return;
                    }
        }
   */ }
    else {
    do{BlackJack::drawCard('D');}while(punktyKrupiera<17 || punktyKrupiera < punktyGracza);
    BlackJack::czyMaAsa(rekaKrupiera,indeksAsa);
    cout << "\nTwoje punkty: " << punktyGracza << AsGracz << endl;
    cout << "Punkty Krupiera: " << punktyKrupiera << AsKrupier << endl;
    if(punktyGracza > punktyKrupiera){
        cout << "Gratulacje wygrales $" << BlackJack::stawka*2 << endl;
        BlackJack::wygrana = BlackJack::stawka*2;
        }
    else if(punktyGracza == punktyKrupiera){
        cout << "Remis, oddajemy ci stawke $" << BlackJack::stawka << endl;
        BlackJack::wygrana = BlackJack::stawka;}
    else if(punktyKrupiera > 21){
        cout << "Gratulacje wygrales $" << BlackJack::stawka*2 << endl;
        BlackJack::wygrana = BlackJack::stawka*2;
        }
    else if(punktyKrupiera > punktyGracza){
        cout << "Przegrana" << endl;
        }
    }
}while(wybor !=2);

}

void BlackJack::drawCard(char kto){
    int i;
    do {
        i=rand()%52;
    } while (talia[i]==0);
    if (kto =='G'){
        for(int j=0; j<10; j++){
            if (rekaGracza[j] == 0) {
                cout << "Dobrales: " << talia[i] << endl;
                rekaGracza[j] = talia[i];
                punktyGracza += talia[i];
                break;}
                }
            if (punktyGracza > 21 && czyMaAsa(rekaGracza, indeksAsa)) {
                punktyGracza -= 10;
                rekaGracza[indeksAsa] = 1;
                AsGracz = "";
                };
        }
     else {
        for (int j = 0; j < 10; j++) {
            if (rekaKrupiera[j] == 0) {
                cout << "Krupier dobral: " << talia[i] << endl;
                rekaKrupiera[j] = talia[i];
                punktyKrupiera += talia[i];
                break;
            }
        }
            if (punktyKrupiera > 21 && czyMaAsa(rekaKrupiera, indeksAsa)) {
                punktyKrupiera -= 10;
                rekaKrupiera[indeksAsa] = 1;
                AsKrupier = "";
        }

}}
void BlackJack::dodajKarteGraczowi(int karta) {
        int i = 0;
        while (rekaGracza[i] != 0) {
            i++;
        }
        rekaGracza[i] = karta;
        punktyGracza += karta;
    }
void BlackJack::dodajKarteKrupierowi(int karta) {
        int i = 0;
        while (rekaKrupiera[i] != 0) {
            i++;
        }
        rekaKrupiera[i] = karta;
        punktyKrupiera += karta;
    }
bool BlackJack::czyMaAsa(int reka[], int& indeksAsa) {
    for (int i = 0; i < 10; i++) {
        if (reka[i] == 11) {
            indeksAsa = i;
            if(reka == rekaGracza) AsGracz = " w tym As";
            if(reka == rekaKrupiera) AsKrupier = " w tym As";
            return true;
        }
    }
    return false;
}
//void BlackJack::sprawdzCzyMaAsa() {
//   int indeksAsa;
//}
