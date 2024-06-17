#ifndef RULETKA_H
#define RULETKA_H
#include "Gracz.h"
#include "Gra.h"


class Ruletka : public Gra
{
    public:
        Ruletka (Gracz &G);

        void play();

    private:
        Gracz &gracz;
        int liczba;
        int stawka;
        int wygrana;
        int kolor;
        string nazwaK;
        void spin();
        void displayMenu();
};

#endif // RULETKA_H
