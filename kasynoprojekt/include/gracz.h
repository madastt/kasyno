#ifndef GRACZ_H
#define GRACZ_H
#include <string>

using namespace std;

class Gracz
{
    public:
        Gracz();
        string getName();
        void setName(string name);
        void setBalance(int amount);
        int getBalance();
        void updateBalance(int amount);
        void minusBalance(int amount);
        int wybor(int minimum,int maximum);
        void addWygrana(int amount);
        int getWygrana();
        void lista();
        void getLista();


    protected:


    private:
        string name;
        int balance;
        int wygrana = 0;
};

#endif // GRACZ_H
