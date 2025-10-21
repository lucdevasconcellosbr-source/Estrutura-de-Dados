#include <stdio.h>


//definindo a estrutura de um item da lista encadeada

typedef struct Item{
    
    int chave; 
    struct Item * Proximo;

} Item;

//bloco principal

int main(){

    Item * A = (Item *) malloc (sizeof(Item));
    Item * B = (Item *) malloc (sizeof(Item));
    Item * C = (Item *) malloc (sizeof(Item));
    Item * D = (Item *) malloc (sizeof(Item));

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

    //construindo o encadeamneto (lista) A, C, B, D

    A -> Proximo = B;
    B -> Proximo = C;
    C -> Proximo = D;

        //percorrer a lista (visitar todos os nos da lista)

    printf("Lista:\n\n");

    Item * X = A;
    printf("%x\ t  %d\n" , X, X->chave); 
    
    X = X->Proximo;
    printf("%X \t $d\n, X, X->Chave"); //29

    X = X->Proximo;
    printf("%X \t $d\n, X, X->Chave"); //41

    X = X->Proximo;
    printf("%X \t $d\n, X, X->Chave"); //Do 3 para o 4

    X = X->Proximo;
    if (X == NULL) printf("Final da lista")

    //Estrutura de repetição

    for (int i = 0; i<=X; i++) {
        
    }

        
    



    }