#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){

   if(pq->size==0) return NULL;
   return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){

	int pos = pq->size;
	heapElem aux;
   int paux;
	pq->heapArray[pos].data=data;
   pq->heapArray[pos].priority=priority;
	while( pos > 0 ){
      paux = round(pos/2);
	   if(pq->heapArray[pos].priority > pq->heapArray[paux].priority){
		aux = pq->heapArray[pos];
		pq->heapArray[pos] =  pq->heapArray[paux];
      pq->heapArray[paux] =  aux;
	   }
	   pos = paux;
	}
	pq->size++;

}


void heap_pop(Heap* pq){
   int aux=0;
   while(aux!=pq->size){
      pq->heapArray[aux].data=pq->heapArray[aux+1].data;
      pq->heapArray[aux].priority=pq->heapArray[aux+1].priority;
      aux=aux+1;
   }   
   pq->size=aux;
}

Heap* createHeap(){
   Heap* h=(Heap*) malloc(sizeof(Heap));
   h->heapArray=(heapElem*)malloc(h->capac*sizeof(heapElem));
   h->capac=3;
   h->size=0;
   return h;
}
