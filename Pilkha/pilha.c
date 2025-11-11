#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

Item * criarItem(int chave) {
    Item * I = (Item *) malloc(sizeof(Item));
    if (I == NULL) {
        printf("ERRO: Não foi possivel alocar memoria para o item!\n")
        return NULL;
    }

    I->Chave = chave;
    I->Anterior = NULL

    return I;
}

Pilha * criarPilha(){
    Pilha * P = (Pilha *) malloc(sizeof(Pilha));
    if (P == NULL) {
        printf("ERRO: Não foi possivel alocar memoria para a Pilha!\n")
        return NULL;
    }

    P->Tamanho = 0;
    P->Topo = NULL;

    return P;
}

void empilhar(Pilha * P, Item * I){
        I->Anterior = P->Topo;
        P->Topo = I;
        p->Tamanho++;

}

void desempilhar(Pilha * P) {
    if (P->Tamanho == 0){
        printf("ERRO: A pilha esta vazia!\n");
    }
    Item * I - P->topo
    P->Topo = P->Topo->Anterior;
    free(I);
    P->Tamanho--;
}
