//
//  enterosLargos.c
//  P4
//
//  Created by Uxío García Andrade on 20/4/18.
//  Copyright © 2018 Uxío García Andrade. All rights reserved.
//

#include "vectordinamico.h"
#include <stdlib.h>
#include <math.h>

typedef struct{
    vectorP cifras;
    short signo;
}STenteroLargo;

typedef STenteroLargo *enteroLargo;

void creaEnteroLargo(enteroLargo *n,unsigned long tam,short signo){
    
    *n = (enteroLargo)malloc(sizeof(enteroLargo));
    
    if(n == NULL){
        printf("Error, no se ha podido reservar memoria para el entero largo");
        exit(0);
    }
    crear(&((*n)->cifras), tam);
    (*n)->signo = signo;
}

void asignarCifras(enteroLargo *n,unsigned long posicion, TELEMENTO valor){
    asignar(&((*n)->cifras), posicion, valor);
}

void liberarEntero(enteroLargo *n){
    liberar(&((*n)->cifras));
    if (*n!=NULL) free(*n);
    *n = NULL;
}

TELEMENTO recuperarCifra(enteroLargo n, unsigned long posicion){
    return recuperar(n->cifras, posicion);
}

short signoEntero(enteroLargo n){
    return n->signo;
}

/*void cambiarSigno(enteroLargo *n){
    (*n)->signo
}*/

void inicializaEnteroRandom(enteroLargo *n){
    inicializaVectorRand(&((*n)->cifras));
}

unsigned long tamanhoEntero(enteroLargo n){
    return tamanho(n->cifras);
}

void divideEntero(enteroLargo *n1, enteroLargo *a, enteroLargo *b){

    creaEnteroLargo(a,tamanhoEntero(*n1)/2,signoEntero(*n1));
    creaEnteroLargo(b,tamanhoEntero(*n1)/2,signoEntero(*n1));
    
    for (unsigned long i=0; i< tamanhoEntero(*n1)/2; i++){
        asignarCifras(a, i, recuperarCifra(*n1, i));
    }
    for (unsigned long i=(tamanhoEntero(*n1)/2); i<tamanhoEntero(*n1); i++){
        asignarCifras(b, i - tamanhoEntero(*n1)/2 , recuperarCifra(*n1, i));
    }
    
}

void imprimeEntero(enteroLargo n){
    if(signoEntero(n)!=1) printf("-");
    for(long long i=tamanhoEntero(n)-2;i>=0;i--){
        printf("%lu",recuperarCifra(n, i));
    }
    if (recuperarCifra(n, tamanhoEntero(n)-1)!=0) printf("%lu",recuperarCifra(n,tamanhoEntero(n)));
    printf("\n");
}


void multiplicarUnaCifra(enteroLargo *n1,enteroLargo *n2, enteroLargo *mult){

        for(int i=0; i<tamanhoEntero(*n1);i++){
            for(int j=0; j<tamanhoEntero(*n1);j++){
                    asignarCifras(mult, i + j, (recuperarCifra(*n1, i) * recuperarCifra(*n2,j)) + recuperarCifra(*mult, i+j));
            }
        }
}

void signoMult(enteroLargo n1,enteroLargo n2, enteroLargo *mult){
    if(signoEntero(n1)*signoEntero(n2)<0) (*mult)->signo = -1;
    else (*mult)->signo = 1;
}
void carry(enteroLargo *mult){
    
    int aux=0;
    
    for(unsigned long i=0;i<tamanhoEntero(*mult);i++){
        asignarCifras(mult, i, recuperarCifra(*mult,i) + aux);
        aux = recuperarCifra(*mult, i)/10;
        asignarCifras(mult, i, recuperarCifra(*mult,i) - 10 * aux);
    }
}

void divYVence(enteroLargo *n1,enteroLargo *n2, enteroLargo *mult){
    
    if(tamanhoEntero(*n1)<5){
        multiplicarUnaCifra(n1, n2, mult);
    }else{
        enteroLargo a=NULL,b=NULL,c=NULL,d=NULL,mIzq=NULL,mMedIzq=NULL,mMedDer=NULL,mDer=NULL;
        divideEntero(n1,&b,&a); //Comenzamos dividiendo cada entero en dos mitades
        divideEntero(n2,&d,&c);
        creaEnteroLargo(&mIzq, tamanhoEntero(*n1), signoEntero(*n1));
        creaEnteroLargo(&mMedIzq, tamanhoEntero(*n1), signoEntero(*n1));//Para poder juntar finalmente todo, se divide el resultado final en 4 partes
        creaEnteroLargo(&mMedDer, tamanhoEntero(*n1), signoEntero(*n1));//De esta forma, es posible tener en cuenta la posición de las cifras sin
        creaEnteroLargo(&mDer, tamanhoEntero(*n1), signoEntero(*n1));//necesidad de código extra
        
        divYVence(&b, &d, &mIzq);
        divYVence(&a, &c, &mDer);
        divYVence(&a, &d, &mMedIzq);
        divYVence(&b, &c, &mMedDer);
        
        for(unsigned long i=0; i < tamanhoEntero(*n1);i++){
            asignarCifras(mult, i, recuperarCifra(mIzq, i)); //bd
            asignarCifras(mult, i + tamanhoEntero(*n1), recuperarCifra(mDer, i)); //ac*i^n
        }
        
        for(unsigned long i=0; i<tamanhoEntero(*n1);i++){
            asignarCifras(mult, i + tamanhoEntero(*n1)/2, recuperarCifra(mMedDer, i) + recuperarCifra(mMedIzq, i) + recuperarCifra(*mult, i + tamanhoEntero(*n1)/2)); //(ad+bc)*i^(n/2)
        }

        liberarEntero(&mIzq);
        liberarEntero(&mDer);
        liberarEntero(&mMedIzq);
        liberarEntero(&mMedDer);
        liberarEntero(&a);
        liberarEntero(&b);
        liberarEntero(&c);
        liberarEntero(&d);
    }
    signoMult(*n1, *n2, mult);
}

void Karatsuba(enteroLargo *n1,enteroLargo *n2, enteroLargo *mult){
    if(tamanhoEntero(*n1)<5){
        multiplicarUnaCifra(n1, n2, mult);
    }else{
        enteroLargo a=NULL,b=NULL,c=NULL,d=NULL,mIzq=NULL,mMed=NULL,mDer=NULL,n1Recursivo=NULL,n2Recursivo=NULL;
        divideEntero(n1,&b,&a); //Comenzamos dividiendo cada entero en dos mitades
        divideEntero(n2,&d,&c);
        creaEnteroLargo(&mIzq, tamanhoEntero(*n1), signoEntero(*n1)); //Para poder juntar finalmente todo, se divide el resultado final en tres partes
        creaEnteroLargo(&mMed, tamanhoEntero(*n1), signoEntero(*n1)); //De esta forma, es posible tener en cuenta la posición de las cifras sin
        creaEnteroLargo(&mDer, tamanhoEntero(*n1), signoEntero(*n1)); //necesidad de código extra
        creaEnteroLargo(&n1Recursivo, tamanhoEntero(*n1)/2, signoEntero(*n1));
        creaEnteroLargo(&n2Recursivo, tamanhoEntero(*n2)/2, signoEntero(*n2));
       
        for(unsigned long i=0; i< tamanhoEntero(*n1)/2;i++){
            asignarCifras(&n1Recursivo, i, recuperarCifra(a, i)+recuperarCifra(b, i));
            asignarCifras(&n2Recursivo, i, recuperarCifra(c, i)+recuperarCifra(d, i));
        }
        
        Karatsuba(&n1Recursivo, &n2Recursivo, &mMed);
        Karatsuba(&b, &d, &mIzq);
        Karatsuba(&a, &c, &mDer);
        /*En el fragmento del medio, es necesario restar el resultado de las otras dos mitades para que se verifique la propiedad a utilizar*/
        for(unsigned long i=0; i < tamanhoEntero(*n1);i++){
            asignarCifras(&mMed, i, recuperarCifra(mMed, i)-recuperarCifra(mDer, i)-recuperarCifra(mIzq, i));
        }
        
        
        for(unsigned long i=0; i < tamanhoEntero(*n1);i++){
            asignarCifras(mult, i, recuperarCifra(mIzq, i));
            asignarCifras(mult, i + tamanhoEntero(*n1), recuperarCifra(mDer, i));
        }
        
        for(unsigned long i=0; i<tamanhoEntero(*n1);i++){
            asignarCifras(mult, i + tamanhoEntero(*n1)/2, recuperarCifra(mMed, i) + recuperarCifra(*mult, i + tamanhoEntero(*n1)/2));
        }
        
        liberarEntero(&n1Recursivo);
        liberarEntero(&n2Recursivo);
        liberarEntero(&mIzq);
        liberarEntero(&mDer);
        liberarEntero(&mMed);
        liberarEntero(&a);
        liberarEntero(&b);
        liberarEntero(&c);
        liberarEntero(&d);
    }
    signoMult(*n1, *n2, mult);
}
