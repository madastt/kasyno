#ifndef STANOWISKO_H
#define STANOWISKO_H
#include "Gracz.h"

class Stanowisko
{
    public:
        virtual void graj(Gracz& Gracz) = 0;

        virtual ~Stanowisko() = default;
};

#endif // STANOWISKO_H
