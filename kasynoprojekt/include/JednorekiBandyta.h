#ifndef JEDNOREKIBANDYTA_H
#define JEDNOREKIBANDYTA_H
#include "Gracz.h"
#include "Gra.h"


class JednorekiBandyta : public Gra
{
    public:
        JednorekiBandyta(Gracz &G);
        void play();


    private:
        Gracz &gracz;
        int stawka;
        int wygrana;
        void displayMenu();
};

#endif // JEDNOREKIBANDYTA_H
