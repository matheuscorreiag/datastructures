#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    //criando lista e nós
    List* l = createList(); //cria um conjunto vazio
    List* l2 = createList(); //cria um conjunto vazio

    //criando elementos da lista
    push(l,1);
    push(l,2);
    push(l,3);
    push(l,4);

    //criando elementos da lista
    push(l2,1);
    push(l2,2);
    push(l2,7);
    push(l2,8);

    //Uniao de conjuntos
     Union(l,l2);

     printf("\n---------------------------\n");
     //interseção de conjuntos
     Intersection(l,l2);

     printf("\n---------------------------\n");
    //printa lista
    printf("LISTA ORIGINAL: ");
    printList(l);
    printf("\n---------------------------\n");

    //procurando por número
    search(l,1);
    printf("\n---------------------------\n");

    //inserindo um número
    printf("INSERINDO NUMERO: ");
    insert(l,7);
    printList(l);
    printf("\n---------------------------\n");

    //verificando maior numero
    max(l);
    printf("\n---------------------------\n");

    //apagando numero em um certo índice
    printf("LISTA COM NUMERO APAGADO: ");
    erase(l, 0);
    printList(l);
    printf("\n---------------------------\n");

    //verificando menor numero
    min(l);
    printf("\n---------------------------\n");

    //retorna tamanho do conjunto
     printf("O TAMANHO DA LISTA EH: ");
     listSize(l);

     //testa se o conjunto é vazio
     printf("\n---------------------------\n");
     testNullConj(l);
      //testa se o conjunto é vazio
     printf("\n---------------------------\n");
     equalConj(l, l2);
     printf("\n---------------------------\n");
     difference(l,l2);
     free(l);
     free(l2);

    return 0;
}
