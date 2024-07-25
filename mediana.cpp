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
    No* mediana;
    int n;

    Lista() {
        inicio = NULL;
        fim = NULL;
        mediana = NULL;
        n = 0;
    }

    void inserirInicio(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
            mediana = novo;
        } else {
            novo->prox = inicio;
            inicio = novo;
        }
        n++;
        atualizarMediana();
    }

    void inserirFinal(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
            mediana = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
        atualizarMediana();
    }

    void inserirOrdenado(int valor) {
        if (inicio == NULL) {
            inserirInicio(valor);
            return;
        }
        if (valor <= inicio->valor) {
            inserirInicio(valor);
            return;
        }
        if (valor >= fim->valor) {
            inserirFinal(valor);
            return;
        }
        No *aux = inicio;
        while (aux->prox->valor < valor) {
            aux = aux->prox;
        }
        No *novo = new No(valor);
        novo->prox = aux->prox;
        aux->prox = novo;
        n++;
        atualizarMediana();
    }

    void imprimir() {
        No* aux = inicio;
        //printf("%d %d\n", aux, aux->valor);
        while (aux != NULL) {
            printf("%d ", aux->valor);
            //printf("%d %d\n", aux->prox, aux->valor);
            aux = aux->prox;
        }
        calcularMediana();
    }

    void atualizarMediana() {
        mediana = inicio;
        for (int i = 0; i < ((n + 1) / 2) - 1; i++) {
            mediana = mediana->prox;
        }
    }

    void calcularMediana() {
        if (n % 2 == 1) {
            double m = mediana->valor;
            printf("%.2lf\n", m);
        } else {
            No *aux = mediana->prox;
            double m = (mediana->valor + aux->valor) / 2.0;
            printf("%.2lf\n", m);
            //double m = (mediana->valor + mediana->prox->valor) / 2.0;
            //printf("%.2lf\n", m);
        }
    }

};

int main() {

    Lista l;
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l.inserirOrdenado(x);
        l.imprimir();
    }

    return 0;
}
