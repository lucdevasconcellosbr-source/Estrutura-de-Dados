#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "musica.h"

int main(){

    Item * D = CriarItem("Aquarela", "Toquinho", 1983);
    Item * E = CriarItem("Romaria", "Renato Teixeria", 1978);
    Item * F = CriarItem("Eu nasci há dez mil anos atrás", "Raul Seixas", 1976);
    Item * G = CriarItem("Cálice", "Chico Buarque e Gilberto Gil", 1978);
    Item * H = CriarItem("Tempo Perdido", "Renato Russo", 1986);

    D->Anterior = NULL;
    D->Posterior = E;

    E->Anterior = D;
    E->Posterior = F;

    F->Anterior = E;
    F->Posterior = G;

    G->Anterior = F;
    G->Posterior = H;

    H->Anterior = G;
    H->Posterior = NULL;

    Lista * Playlist = (Lista *) malloc(sizeof(Lista));
    if (Playlist == NULL) {
        exit(1);
    }

    Playlist->tamanho = 5;
    Playlist->Inicio = D;
    Playlist->Fim = H;

    exibirInicio(Playlist);
    //Caso queira deletar uma musica, é o declarar a anterior como NULL
    //Sempre que pedir para excluir item, utilizar o free() no final, para liberar memoria
}