#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dados;
    struct No *prox, *ant;
} No;

typedef struct{
    No *ini, *fim;
    int tam;
} Lista;

void criarLista(Lista *lista){
    lista->tam = 0;
    lista->ini = NULL;
    lista->fim = NULL;
}

int vazia(Lista *lista){
    if(lista->tam == 0) return 1;
    else return 0;
}

int tamanho(Lista *lista){
    return lista->tam;
}

int obtPos(Lista *lista, int dado){ //Pega a posição do elemento pelo valor
    if(vazia(lista) == 1) return -1;

    No *aux = lista->ini;

    for(int i = 0;i < lista->tam+1;i++){
        if(aux->dados == dado) return i+1;
        aux = aux->prox;    
    }

    return 0;
}

int obtEle(Lista *lista, int pos){ //Obtem valor pela posição
    if(pos < 1 || pos > lista->tam) return -1;

    No *aux = lista->ini;

    for(int i = 0;i < pos-1;i++){
        aux = aux->prox;    
    }

    return aux->dados;
}

int inserir(Lista *lista,int pos, int dado){
    if(pos < 1 || pos > lista->tam+1) return -1;

    No *novo = (No*)malloc(sizeof(No));
    novo->dados = dado;

    if(pos == 1){
        novo->ant = NULL;
        novo->prox = lista->ini;

        lista->ini->ant = novo;
        lista->ini = novo;

        if(vazia(lista) == 1) lista->fim = novo;
    }else if(pos == lista->tam+1){
        novo->prox = NULL;
        novo->ant = lista->fim;

        lista->fim->prox = novo;
        lista->fim = novo;
    }else{
        No *aux = lista->ini;

        for(int i = 0;i < pos-1;i++){
            aux = aux->prox;
        } 
        
        novo->prox = aux->prox;
        novo->ant = aux;

        aux->prox->ant = novo;
        aux->prox = novo;
    }

    lista->tam++;
    return 1;
}

int remover(Lista *lista,int pos){
    if(vazia(lista) == 1 || pos < 1 || pos > lista->tam) return -1;

    if(pos == 1){
        No *aux = lista->ini;

        aux->prox->ant = NULL;
        lista->ini = aux->prox;
        free(aux);
        if(lista->tam == 1) lista->fim = NULL;
    }else if(pos == lista->tam){
        No *aux = lista->fim;

        lista->fim = aux->ant;
        lista->fim->prox = NULL;

        free(aux);
    }else{
        No *aux = lista->ini;

        for(int i = 0;i < pos-1;i++){
            aux = aux->prox;
        }

        aux->prox->ant = aux->ant;
        aux->ant->prox = aux->prox;
        free(aux);
    }

    lista->tam--;
    return 1;
}

int mostrarLista(Lista *lista){
    No *aux = lista->ini;
    printf("%d|",aux->dados);

    for(int i = 0; i < lista->tam-1;i++){
        aux = aux->prox;
        printf("%d|",aux->dados);
    }
    printf("\n");
    return 0;
}

int main(){
    Lista lista;
    criarLista(&lista);
    inserir(&lista,1,2);
    inserir(&lista,1,1);
    inserir(&lista,3,3);
    inserir(&lista,4,4);
    inserir(&lista,5,5);
    inserir(&lista,6,6);
    mostrarLista(&lista);
    remover(&lista,1);
    mostrarLista(&lista);
    remover(&lista,5);
    mostrarLista(&lista);
    remover(&lista,3);
    mostrarLista(&lista);
    printf("%d",obtPos(&lista,5));
    printf("\n%d",obtEle(&lista,1));
    return 0;
}