#include <stdio.h>

#define max 3

typedef struct{
    int dados[max];
    int fim;
    int ini;
    int tamAtual;
    int tamMax;
}Fila;

void criarFila(Fila *fila){
    fila->ini = 0;
    fila->fim = -1;
    fila->tamAtual = 0;
    fila->tamMax = max;
}

int vazia(Fila *fila){
    if(fila->tamAtual == 0) return 1;
    else return -1;
}

int cheia(Fila *fila){
    if(fila->tamAtual == fila->tamMax) return 1;
    else return -1;
}

int tamanho(Fila *fila){
    return fila->tamAtual;
}

int obtIni(Fila *fila){
    if(vazia(fila) == 1) return -1;
    else return fila->dados[fila->ini];
}

int inserir(Fila *fila, int dados){
    if(cheia(fila) == 1) return -1;

    fila->fim = (fila->fim+1) % fila->tamMax;
    fila->dados[fila->fim] = dados;

    fila->tamAtual++;
    return 1;
}

int remover(Fila *fila){
    if(vazia(fila) == 1) return -1;
    
    int valor = fila->ini;
    fila->ini = (fila->ini+1) % fila->tamMax;
    
    fila->tamAtual--;   
    return valor;
}

int main(){
    Fila fila;
    criarFila(&fila);
    inserir(&fila, 10);
    inserir(&fila, 5);
    inserir(&fila, 2);
    inserir(&fila, 0);
    printf("%d\n",obtIni(&fila));
    remover(&fila);
    inserir(&fila, 1);
    printf("%d\n",obtIni(&fila));
    remover(&fila);
    printf("%d\n",obtIni(&fila));
    remover(&fila);
    printf("%d\n",obtIni(&fila));
    remover(&fila);
    printf("%d\n",obtIni(&fila));
    remover(&fila);
    printf("%d\n",obtIni(&fila));
    return 0;
}