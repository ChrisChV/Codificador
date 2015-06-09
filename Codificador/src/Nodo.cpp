#include "Nodo.h"

Nodo::Nodo()
{
    punto = 0;
    raya = 0;


}
Nodo::Nodo(char letra, char pol)
{
    punto = 0;
    raya = 0;
    this->letra = letra;
    this->pol = pol;
}


Nodo::Nodo(Nodo* nodo, char letra, char pol, bool polarity)
{
    if(polarity){
        raya = nodo;
        punto = 0;
    }
    else{
        punto = nodo;
        raya = 0;
    }
    this->letra = letra;
    this->pol = pol;
}

Nodo::Nodo(Nodo* raya, Nodo* punto, char letra, char pol)
{
    this->raya = raya;
    this->punto = punto;
    this->letra = letra;
    this->pol = pol;
}

Nodo::~Nodo()
{
    delete(raya);
    delete(punto);
}
