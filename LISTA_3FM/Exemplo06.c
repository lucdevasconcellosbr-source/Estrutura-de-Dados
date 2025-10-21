#include <stdio.h>
#include <stdlib.h>

//definindo a estrutura de um item da lista encadeada

typedef struct Item{
    
    int chave; 
    struct Item * Proximo;

} Item;

Item * CriarItem(int chave);

void ExibirLista(Item * Inicio); //Para Lista não Circular.
void InserirItem(Item * Inicio, Item * I, int Posicao);
void ExcluirItem(Item * Inicio, int Posicao)

//bloco principal

int main(){

    Item * A = CriarItem(17);
    Item * B = CriarItem(29);
    Item * C = CriarItem(41);
    Item * D = CriarItem(97);

    A -> chave = 17;
    B -> chave = 29;
    C -> chave = 41;
    D -> chave = 97;

    A ->chave = NULL;
    B ->chave = NULL;
    C ->chave = NULL;
    D ->chave = NULL;

    // alguns testes (pritnf's)

    printf("%x \t %d\n", A, A->chave);
    printf("%x \t %d\n", B, B->chave);
    printf("%x \t %d\n", C, C->chave);
    printf("%x \t %d\n", D, D->chave);

    //construindo o encadeamneto (lista Circular) A, C, B, D

    A -> Proximo = B;
    B -> Proximo = C;
    C -> Proximo = D;
    D -> Proximo = A; // Depois do último estara o primeiro.

    printf("\nLista:\n\n");

    Item * X = A;

    for (item * X = A; ; i<15; i++, X = X->Proximo) {
        printf("%X \t %d\n", X, X->Chave);
        if (X == NULL) break;
    }

    Item * CriarItem(int Chave) {
        Item * X = (Item *) malloc(sizeof(Item));
        X->Chave = Chave;
        x->Proximo = NULL;
        return X;
    }

    void ExibirLista(Item * Inicio) {

         Item * X = Inicio;

    for (int i = 0; ; X != NULL; i++, X = X->Proximo) {
        printf("%X \t %d\n", X->Chave);
    }
    }
}