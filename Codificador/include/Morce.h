#ifndef MORCE_H
#define MORCE_H
#include <Nodo.h>
#include <iostream>

class Morce
{
    public:
        Morce();
        void setRaizPunto(Nodo *);
        void setRaizRaya (Nodo *);
        std::string getMorce(char);
        virtual ~Morce();
    protected:
    private:
        Nodo *raizPunto;
        Nodo *raizRaya;

};

#endif // MORCE_H
