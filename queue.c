#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <string.h>
#include "queue.h"

//Eiles sukurimas
void InicijuotiEile(Eile* eil){
    eil->pradzia = NULL;
    eil->galas = NULL;
};

//Tikriname, ar eile pilna
int ArPilna(){
    Node* laikinas;
    laikinas = (Node*) malloc(sizeof(Node));
    if (laikinas != NULL)
    {
        free(laikinas);
        return FALSE;
    }
    else return TRUE;
}

//Tikriname, ar eile tuscia
int ArTuscia(Eile* eil){
    return eil->pradzia != NULL ? FALSE : TRUE;
}

//Idedame elementa i eile

int IdetiElementa(Data x, Eile *eil){
    Node *temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) return 0; //Pilnos eiles erroras
    temp->duom = x;
    temp->next = NULL;
    if(eil->pradzia == NULL){
        eil->pradzia = eil->galas = temp;
        return 1;
    }
    eil->galas->next = temp;
    eil->galas = temp;
    return 1;
}


//Isimame elementa ir parodome ekrane
Data IsimtiElementa(Eile * eil,int *err){
    Node* temp =  eil->pradzia;
    if(eil->pradzia==NULL) {
            *err=0;
            return NULL; //tuscios eiles erroras
    eil->pradzia = eil->galas = NULL;
    }
    Data x = eil->pradzia->duom;
    eil->pradzia = eil->pradzia->next;
    free(temp);
    *err = 1;
    return x;
}

//Gauname pirmo elemento reiksme
Data GautiReiksme(Eile* eil){
    return eil->pradzia->duom;
}

//Kiek elementu yra eileje
int KiekElementu(Eile* eil){
    Node* temp;
    temp= eil->pradzia;
    int i=0;
    while(temp!=NULL){
        temp=temp->next;
        i++;
    }
    return i;
}

//Sunaikiname eile
void Istrinti(Eile* eil) {
    if (eil->pradzia != NULL) {
        Node *temp;
        while (eil->pradzia->next != 0) {
            temp = eil->pradzia;
            eil->pradzia = eil->pradzia->next;
            free(temp);
        }
        eil->pradzia = NULL;
        eil->galas = NULL;
    }
}
