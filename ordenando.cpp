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
            printf("%d ", aux->valor);
            //printf("%d %d\n", aux->prox, aux->valor);
            aux = aux->prox;
        }
    }

};

int main() {

    Lista l1, l2, l3;

    int n, m, x;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l1.inserirFinal(x);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        l2.inserirFinal(x);
    }

    while (l1.n > 0 && l2.n > 0) {
        if (l1.inicio->valor < l2.inicio->valor) {
            l3.inserirFinal(l1.inicio->valor);
            l1.removerInicio();
        } else {
            l3.inserirFinal(l2.inicio->valor);
            l2.removerInicio();
        }
    }

    while (l1.n > 0) {
        l3.inserirFinal(l1.inicio->valor);
        l1.removerInicio();
    }

     while (l2.n > 0) {
        l3.inserirFinal(l2.inicio->valor);
        l2.removerInicio();
    }

    l3.imprimir();


    return 0;
}

