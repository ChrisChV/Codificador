#include "Morce.h"
#include <vector>

using namespace std;

Morce::Morce()
{

}


string Morce::getMorce(char letra)
{
    string result;
    vector<Nodo*> linea;
    bool temp = false;
    linea.push_back(raizPunto);
    while(linea.back()->letra != letra){
        char tt = linea.back()->letra;
        if(linea.back()->punto == 0 or !linea.back()->polarityPunto){
            if(linea.back()->raya == 0 or !linea.back()->polarityRaya){
                if(linea.back()->letra == 'e'){
                    temp = true;
                    break;
                }
                linea.pop_back();
            }
            else{
                linea.back()->polarityRaya = false;
                linea.push_back(linea.back()->raya);
            }
        }
        else{
            linea.back()->polarityPunto = false;
            linea.push_back(linea.back()->punto);
        }
    }
    if(temp){
        linea.clear();
        linea.push_back(raizRaya);
        while(linea.back()->letra != letra){
            if(linea.back()->punto == 0 or !linea.back()->polarityPunto){
                if(linea.back()->raya == 0 or !linea.back()->polarityRaya){
                    if(linea.back()->letra == 't'){
                        break;
                    }
                    linea.pop_back();
                }
                else{
                    linea.back()->polarityRaya = false;
                    linea.push_back(linea.back()->raya);
                }
            }
            else{
                linea.back()->polarityPunto = false;
                linea.push_back(linea.back()->punto);
            }
        }
    }
    if(linea.empty()){
        return " ";
    }
    for(auto i = 0; i < linea.size(); i++){
        result.insert(result.end(),linea[i]->pol);
    }
    return result;
    delete(raizPunto);
    delete(raizRaya);
}


void Morce::setRaizRaya(Nodo* raya)
{
    raizRaya = raya;
}

void Morce::setRaizPunto(Nodo* punto){
    raizPunto = punto;
}

Morce::~Morce()
{
    //dtor
}
