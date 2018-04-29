//
//  quicksort.h
//  P3
//
//  Created by Uxío García Andrade on 17/4/18.
//  Copyright © 2018 Uxío García Andrade. All rights reserved.
//

#ifndef quicksort_h
#define quicksort_h

#include <stdio.h>
#include "vectordinamico.h"

unsigned long choose_pivot(unsigned long i,unsigned long j);
void quicksort(vectorP *pvector, unsigned long beg, unsigned long end);

#endif /* quicksort_h */
