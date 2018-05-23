#ifndef ADS_1_QUEUE_H
#define ADS_1_QUEUE_H
#include <stdio.h>
#include <stdlib.h>

typedef int Data;

#define TRUE 1
#define FALSE 0

typedef struct node{
    Data duom;
    struct node *next;
}Node;

typedef struct eile{
    Node *pradzia;
    Node *galas;
} Eile;



void InicijuotiEile(Eile*);
int ArPilna();
int ArTuscia(Eile *);
int IdetiElementa(Data, Eile *);
Data IsimtiElementa(Eile *, int *);
Data GautiReiksme(Eile*);
int KiekElementu(Eile*);
void Istrinti(Eile*);

#endif //ADS_1_QUEUE_H
