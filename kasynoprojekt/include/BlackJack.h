#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "Gra.h"


class BlackJack : public Gra
{
    public:
        BlackJack(Gracz &G);
        void play();


    private:

        Gracz &gracz;
        int stawka;
        int wygrana;
        void displayMenu();
        void dodajKarteGraczowi(int karta);
        void dodajKarteKrupierowi(int karta);
        void drawCard(char kto);
        int rekaGracza[10];
        int rekaKrupiera[10];
        int punktyGracza = 0;
        int punktyKrupiera = 0;
        int talia [52] =   {2,2,2,2,
                            3,3,3,3,
                            4,4,4,4,
                            5,5,5,5,
                            6,6,6,6,
                            7,7,7,7,
                            8,8,8,8,
                            9,9,9,9,
                            10,10,10,10,
                            10,10,10,10,
                            10,10,10,10,
                            10,10,10,10,
                            11,11,11,11};
        bool czyMaAsa(int reka[], int& indeksAsa);
        void sprawdzCzyMaAsa();
        int indeksAsa;
        string AsGracz = "";
        string AsKrupier = "";

};

#endif // BLACKJACK_H
