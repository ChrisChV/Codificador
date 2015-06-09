#ifndef NODO_H
#define NODO_H


class Nodo
{
    public:
        Nodo();
        Nodo(char,char);
        Nodo(Nodo*, char,char, bool);
        Nodo(Nodo *, Nodo *, char,char);
        Nodo *punto;
        Nodo *raya;
        bool polarityPunto = true;
        bool polarityRaya = true;
        char letra;
        char pol;
        virtual ~Nodo();
    protected:
    private:

};

#endif // NODO_H
