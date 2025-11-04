#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "musica.h"

Item * CriarItem(char * Titulo, char * Autor, int Ano){

    Item * X = (Item *) malloc(sizeof(Item));
    if (X == NULL) {
        printf("ERRO: não foi possível alocar nemória para o Item.\n");
        return NULL;
    }

    strcpy(x->Titulo, Titulo);
    strcpy(x->Autor, Autor);
    x->Ano = Ano;
    x->Anterior = NULL;
    x->Posterior = NULL;

    return X;

}

void exibirInicio(Lista * L){

    Item * Atual = L->Inicio;
    for(int i = 0; i < L->Tamanho; i++) {
        printf("%d \t %s \n", i, Atual->Titulo);
        Atual = Atual->Posterior;
    }

    printf("\n")
}

void exibirFinal(Lista * L) {

}

void exibirMusicas(Lista * L, int Ano){
    Item * Atual = L->Inicio;

    for(int i = 0; i < L->tamanho; i++) {
        if(Atual->Ano == Ano){
            printf("%d \t %s \n", i + 1, Atual->Titulo)
        }
    }
}