#ifndef MUSICA_H
#define MUSICA_H

typedef struct  Item 
{
    char Titulo[50];
    char Autor[100];
    int  Ano;

    struct Item * Anterior;
    struct Item * Posterior;
} Item;

typedef struct Lista{
    int tamanho;
    struct Item * Inicio;
    struct Item * Fim;
} Lista;

Item * CriarItem(char * Titulo, char * Autor, int Ano);
void exibirInicio(Lista * L);
void exibirFinal(Lista * L);
void exibirMusicas(Lista * L);

#endif
