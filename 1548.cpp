
#include<stdio.h>

struct No {

    int valor;
    No* prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Fila {

    No* inicio;
    No* fim;
    int n;

    Fila() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void enfileirar(int valor) {
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

    void enfileirarOrdenado(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            if (valor >= inicio->valor) {
                novo->prox = inicio;
                inicio = novo;
            } else if (valor <= fim->valor) {
                fim->prox = novo;
                fim = novo;
            } else {
                No *aux = inicio, *aux2;
                while (valor < aux->valor) {
                    aux2 = aux;
                    aux = aux->prox;
                }
                novo->prox = aux;
                aux2->prox = novo;
            }
        }
        n++;
    }

    void desenfileirar(){
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

    int frente() {
        if (inicio == NULL) return 0;
        return inicio->valor;
    }

};

int main() {

    int n;
    scanf("%d", &n);
    while (n--) {
        int m;
        scanf("%d", &m);
        Fila f1, f2;

        for (int i = 0; i < m; i++) {
            int x;
            scanf("%d", &x);
            f1.enfileirar(x);
            f2.enfileirarOrdenado(x);
        }

        int r = 0;

        for (int i = 0; i < m; i++) {
            if (f1.frente() == f2.frente()) {
                r++;
            }
            //printf("%d %d\n", f1.frente(), f2.frente());
            f1.desenfileirar();
            f2.desenfileirar();
        }

        printf("%d\n", r);

    }

    return 0;
}
