#include<stdio.h>
#include<string.h>

struct No {

    char valor;
    No* prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(char _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Pilha {

    No* topo;
    int n;

    Pilha() {
        topo = NULL;
        n = 0;
    }

    void inserir(char valor) {
        No* novo = new No(valor);
        if (topo == NULL) {
            topo = novo;
        } else {
            novo->prox = topo;
            topo = novo;
        }
        n++;
    }

    void remover() {
        if (n == 0) return;
        if (n == 1) {
            delete(topo);
            topo = NULL;
            n = 0;
            return;
        }
        No* aux = topo;
        topo = topo->prox;
        delete(aux);
        n--;
    }

    int topoPilha() {
        if (topo == NULL) return 0;
        return topo->valor;
    }

};

int main() {

    char tmp[1001];

    while (scanf("%s", tmp) != EOF) {
        Pilha p;
        int correto = 1;
        for (int i = 0; i < strlen(tmp); i++) {
            if (tmp[i] == '(') {
                p.inserir('(');
            } else if (tmp[i] == ')') {
                if (p.n > 0) {
                    p.remover();
                } else {
                    correto = 0;
                }
            }
        }
        if (p.n > 0) {
            correto = 0;
        }
        if (correto == 1) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    return 0;
}
