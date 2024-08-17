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

    bool match(char a, char b, char c, char d) {
        No *aux = topo;
        if (aux->valor == a) {
            aux = aux->prox;
            if (aux->valor == b) {
                aux = aux->prox;
                if (aux->valor == c) {
                    aux = aux->prox;
                    if (aux->valor == d) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

};

int main() {

    int n, q = 0;
    scanf("%d%*c", &n);

    Pilha p;

    while (n--) {
        char a, b, c, d;
        scanf("%c %c %c %c%*c", &a, &b, &c, &d);
        //printf("%c %c %c %c\n", a,b, c, d);
        if (p.n == 0) {
            p.inserir('F');
            p.inserir('A');
            p.inserir('C');
            p.inserir('E');
        }
        if (p.match(a, b, c, d)) {
            p.remover();
            p.remover();
            p.remover();
            p.remover();
            q++;
        } else {
            p.inserir(a);
            p.inserir(b);
            p.inserir(c);
            p.inserir(d);
        }
    }

    printf("%d\n", q);

    return 0;
}
