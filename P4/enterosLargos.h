//
//  enterosLargos.h
//  P4
//
//  Created by Uxío García Andrade on 20/4/18.
//  Copyright © 2018 Uxío García Andrade. All rights reserved.
//

#ifndef enterosLargos_h
#define enterosLargos_h

#include "vectordinamico.h"
#include <stdio.h>


typedef void * enteroLargo;

void creaEnteroLargo(enteroLargo *n,unsigned long tam, short signo);
void asignarCifras(enteroLargo *n,unsigned long posicion, TELEMENTO valor);
void liberarEntero(enteroLargo *n);
TELEMENTO recuperarCifra(enteroLargo n, unsigned long posicion);
short signoEntero(enteroLargo n);
void inicializaEnteroRandom(enteroLargo *n);
unsigned long tamanhoEntero(enteroLargo n);
void imprimeEntero(enteroLargo n);
void multiplicarUnaCifra(enteroLargo *n1,enteroLargo *n2, enteroLargo *mult);
void Karatsuba(enteroLargo *n1,enteroLargo *n2, enteroLargo *mult);
void carry(enteroLargo *mult);
void divYVence(enteroLargo *n1,enteroLargo *n2, enteroLargo *mult);

#endif /* enterosLargos_h */
