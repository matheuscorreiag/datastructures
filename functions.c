#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

typedef struct node { //estrutura do nó
    int num;
    struct node* next;
}Node;

typedef struct list{ //estrutura da lista
    int size; //tamanho da lista
    Node* head; //cabeca da lista
} List;

List* createList(){//cria lista
    List* list = (List*)malloc(sizeof(List));//aponta para a lista
    list->size = 0;//seta tamanho da lista
    list->head = NULL; //aponta para o elemento cabeca da lista

    return list;
}

bool isEmpty(List* list){//verifica se a lista é vazia
    return (list->size == 0);
}
void printList(List* list){//printa a lista
    if(isEmpty(list)){
        printf("LISTA VAZIA\n");
        return;
    }
    Node* pointer = list->head; //cria um ponteiro para percorrer a lista

    while(pointer != NULL){ //enquanto o ponteiro não for NULL:
        printf("%d ", pointer->num); //printa elementos da lista
        pointer = pointer-> next; //aponta para o próximo elemento da lista
    }
}

Node* atPos(List* list, int index){
    if(index >= 0 && index < list->size){
        Node* node = list->head; //apontando para a cabeca da lista

        int i;
        for(i = 0; i < index; i++){ //percorrendo a lista ate o valor em index
             node = node->next;
        }
        return node;
    }
    printf("Index invalido");
    return NULL;
}
void push(List* list, int num){//adicionando valores na lista
    Node* node = (Node*)malloc(sizeof(Node)); //alocando espaço de Node
    node->num = num;  //setando numero
    node->next = list-> head;
    list->head = node;
    list->size++; //incrementado tamanho da lista
}

int indexOf(List* list, Node* node){
    if(node != NULL){

        Node* pointer = list-> head;

        int index = 0;
        while(pointer != node && pointer != NULL){

            pointer = pointer->next;
            index++;


        }
        if(pointer != NULL){
            return index;
            }
        return 0;
    }
    printf("No nao existe\n\n");
    return -1;
}
void search(List* list, int num){
    Node* node = list->head;
    int flag = 0;

    while(node != NULL){
        if(node->num == num){
            flag++;
            break;
        }
        node = node->next;
    }

    if(flag != 0 ){
        printf("O NUMERO PERTENCE AO CONJUNTO");
    }else{

        printf("O NUMERO NAO PERTENCE AO CONJUNTO");
    }
}
void min(List* list){ //procurando numero maximo
    Node* pointer = list->head;
    int smallestNum = pointer->num;

    while(pointer != NULL){
        if(pointer->num < smallestNum){
            smallestNum = pointer->num;
        }
        pointer = pointer->next; //aponta para o próximo elemento da lista
    }
    printf("O MENOR NUMERO EH: %d", smallestNum); //retorna o node máximo
}

void insert(List* list, int num){
    Node* node = list->head;
    int flag = 0;
    while (node != NULL)//verifica se o número já existe no conjunto.
    {
        if (node->num == num)
        {
            flag++;
            break;
        }
        node = node->next;
    }
    if (flag == 0)//Insere número no conjunto.
    {
        Node* node2 = (Node*)malloc(sizeof(Node)); //alocando espaço de Node

        node2->num = num;
        node2->next = list->head;
        list->head = node2;
        list->size++;
    }
}
void erase(List* list, int index){
    if(index == 0){
        pop(list);
    }else {
        Node* current = atPos(list, index);


        if(current != NULL){
            Node* previous = atPos(list, index - 1); //pega index da posicao atual - 1
            previous->next = current->next; //posicao atual - 1 vai apontar agora para a posicao atual + 1

            free(current);//apaga o ponteiro
            list->size--;//diminui tamanho da lista
        }
    }
}
void max(List* list){ //procurando numero maximo
    Node* pointer = list->head;
    int biggestNum = pointer->num;

    while(pointer != NULL){
        if(pointer->num > biggestNum){
            biggestNum = pointer->num;
        }
        pointer = pointer->next; //aponta para o próximo elemento da lista
    }
    printf("O MAIOR NUMERO EH: %d", biggestNum); //retorna o node máximo
}

void pop(List* list){
    if(!isEmpty(list)){
        Node* pointer = list->head;
        list->head = pointer->next;
        free(pointer);
        list->size--;
    }
}

void listSize(List* list){//funcao que retorna tamanho da lista
    int size = list->size;
    printf("%d", size);
}
void testNullConj(List* list){//funcao para testar conjunto vazio
    if(list->size != 0){
        printf("CONJUNTO NAO VAZIO");
    }else{
        printf("CONJUNTO VAZIO");
    }
}
void Union(List* listA, List* listB){
      List* listC = createList(); //cria lista auxiliar

      Node* pointerA = listA->head; //apontando para a cabeca das listas;
      Node* pointerB = listB->head;



      while(pointerB != NULL){//percorrendo B
        insert(listC,pointerB->num); //inserindo valores de B na lista auxiliar
        pointerB = pointerB->next;
      }
      while(pointerA != NULL){
        insert(listC,pointerA->num); //inserindo valores de A na lista auxiliar

        pointerA = pointerA->next;
      }
      printf("UNIAO DAS LISTAS: ");
      printList(listC); //printa lista auxiliar
}
void Intersection(List* listA, List* listB){//interseccao das listas
    List* listC = createList(); //criacao das listas

    Node* pointerA = listA->head; //apontando para a cabeca das listas
    Node* pointerB = listB->head;

    while(pointerA != NULL){//percorre a lista A
        while(pointerB != NULL){//percorre a lista B
            if(pointerA->num == pointerB->num){//se o numero atual em A for == do atual em B, insere o numero na lista auxiliar
                insert(listC, pointerA->num);
            }
            pointerB = pointerB->next;
        }
        pointerB = listB->head;
        pointerA = pointerA->next;
    }

      printf("INTERSECCAO DAS LISTAS: ");
      printList(listC); //printa lista auxiliar

}
void equalConj(List* listA, List* listB){//verifica se as listas sao iguais

    Node* pointerA = listA->head; //apontando para a cabeca das listas
    Node* pointerB = listB->head;

    int flag = 0;
    while(pointerA != NULL){//percorre todos os numeros de A
        while(pointerB != NULL){//percorre todos os numeros de B
            if(pointerA->num == pointerB->num){ //verifica a igualdade
                flag++; //se for igual, adiciona +1  a flag
            }
            pointerB = pointerB->next; //passa para o proximo elemento de listB
        }
        pointerB = listB->head; //apos o while acabar, reseta o pointerB para a cabeça da lista
        pointerA = pointerA->next; //passa para o proximo elemento de listA
    }
    //se a flag for igual ao tamanho de listA e listB
    //OU flag for igual ao tamanho de listA multiplicado por listB (caso os conjuntos sejam totalmente iguais)
    if((flag == listA->size) && (flag == listB->size) || (flag == (listA->size * listB->size))){
        printf("OS CONJUNTOS SAO IGUAIS");
    }else{
        printf("OS CONJUNTOS NAO SAO IGUAIS");
    }

}
void difference(List* listA, List* listB){ //verifica a diferença da lista A para lista B

      List* listC = createList();//cria lista auxiliar

      Node* pointerA = listA->head; //nó apontando para a cabeça da lista A
      Node* pointerB = listB->head; //nó apontando para a cabeça da lista B

        int flag = 0;

    while(pointerA != NULL){ //percorre a lista A
        while(pointerB != NULL){ //percorre a lista B
            if(pointerA->num != pointerB->num){ //se o numero atual em A for != do atual em B, aciona a flag
            flag++;
            }
            pointerB = pointerB->next; //percorrendo a lista B
        }

        if(flag == listA->size){ //se flag for igual ao tamanho da lista, então este numero é diferente de todos
            insert(listC, pointerA->num); //portanto podemos inserir ele na lista auxiliar
        }
        flag = 0; //resetando flag e lista B
        pointerB = listB->head;
        pointerA = pointerA->next; //indo para o próximo número de A
    }
    printList(listC); //ao final, printa os números de A que são diferentes de B
}

