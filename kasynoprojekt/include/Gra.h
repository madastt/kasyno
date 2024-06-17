#ifndef GRA_H
#define GRA_H
#include "Gracz.h"


class Gra
{
    public:
        virtual void play() = 0;
        virtual ~Gra(){}
};

#endif // GRA_H
