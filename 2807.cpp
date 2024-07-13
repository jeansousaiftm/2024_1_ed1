#include<stdio.h>

struct No {

    int valor;
    No* prox;

    No() {
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Lista {

    No* inicio;
    No* fim;
    int n;

    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void inserirInicio(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            novo->prox = inicio;
            inicio = novo;
        }
        n++;
    }

    void inserirFinal(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    void removerInicio() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

    void removerFinal() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        delete(fim);
        fim = aux;
        aux->prox = NULL;
        n--;
    }

    void imprimir() {
        No* aux = inicio;
        //printf("%d %d\n", aux, aux->valor);
        while (aux != NULL) {
            if (aux != inicio) printf(" ");
            printf("%d", aux->valor);
            //printf("%d %d\n", aux->prox, aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }

    void menorLista() {
        if (inicio == NULL) return;
        int i = 0;
        int menor = inicio->valor, posicao = 0;
        No *aux = inicio;
        while (aux != NULL) {
            if (aux->valor < menor) {
                menor = aux->valor;
                posicao = i;
            }
            aux = aux->prox;
            i++;
        }
        printf("Menor valor: %d\n", menor);
        printf("Posicao: %d\n", posicao);
    }

    void inserirFibonacci() {
        if (n < 2) return;
        No *segundo = inicio->prox;
        int v = inicio->valor + segundo->valor;
        inserirInicio(v);
    }

};

int main() {

    Lista l;

    int n;

    scanf("%d", &n);

    if (n == 1) {
        l.inserirInicio(1);
    } else if (n == 2) {
        l.inserirInicio(1);
        l.inserirInicio(1);
    } else {
        l.inserirInicio(1);
        l.inserirInicio(1);
        for (int i = 3; i <= n; i++) {
            l.inserirFibonacci();
        }
    }

    l.imprimir();

    return 0;
}
