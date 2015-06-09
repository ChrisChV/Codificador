#ifndef ABCMORCE_H_INCLUDED
#define ABCMORCE_H_INCLUDED
#include <Morce.h>
#include <Nodo.h>






///letras reservadas n, m, c, l, h, e, s;



Morce* generarArbol(){
    Nodo *uno = new Nodo('1','1');
    Nodo *dos = new Nodo('2','1');
    Nodo *tres = new Nodo('3','1');
    Nodo *cuatro = new Nodo('4','1');
    Nodo *cinco = new Nodo('5','0');
    Nodo *seis = new Nodo('6','0');
    Nodo *siete = new Nodo('7','0');
    Nodo *ocho = new Nodo('8','0');
    Nodo *nuebe = new Nodo('9','0');
    Nodo *cero = new Nodo('0','1');
    Nodo *H = new Nodo(cuatro, cinco,'h','0');
    Nodo *V = new Nodo(tres,'v','1', true);
    Nodo *F = new Nodo('f','0');
    Nodo *_ = new Nodo(dos, '_','1', true);
    Nodo *L = new Nodo('l','0');
    Nodo *P = new Nodo('p','0');
    Nodo *J = new Nodo(uno, 'j','1', true);
    Nodo *B = new Nodo(seis, 'b','0', false);
    Nodo *X = new Nodo('x','1');
    Nodo *C = new Nodo('c','0');
    Nodo *Y = new Nodo('y','1');
    Nodo *Z = new Nodo(siete,'z','0',false);
    Nodo *Q = new Nodo('q','1');
    Nodo *punto = new Nodo(ocho,'.','0',false);
    Nodo *raya = new Nodo(cero,nuebe,'-','1');
    Nodo *S = new Nodo(V, H, 's','0');
    Nodo *U = new Nodo(_, F, 'u','1');
    Nodo *R = new Nodo(L, 'r','0', false);
    Nodo *W = new Nodo(J, P, 'w','1');
    Nodo *D = new Nodo(X, B, 'd','0');
    Nodo *K = new Nodo(Y, C, 'k','1');
    Nodo *G = new Nodo(Q, Z, 'g','0');
    Nodo *O = new Nodo(raya, punto, 'o','1');
    Nodo *I = new Nodo(U, S, 'i','0');
    Nodo *A = new Nodo(W, R, 'a','1');
    Nodo *N = new Nodo(K, D, 'n','0');
    Nodo *M = new Nodo(O, G, 'm','1');
    Nodo *E = new Nodo(A, I, 'e','0');
    Nodo *T = new Nodo(M, N, 't','1');
    Morce *morce = new Morce();
    morce->setRaizPunto(E);
    morce->setRaizRaya(T);
    return morce;
}


#endif // ABCMORCE_H_INCLUDED
