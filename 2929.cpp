#include<stdio.h>
#include<string.h>

struct No {

    long long valor;
    No* prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(long long _valor) {
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

    void inserir(long long valor) {
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

    Pilha p, m;

    int n;
    scanf("%d", &n);
    while (n--) {
        char tmp[10];
        scanf("%s", tmp);
        if (strcmp(tmp, "PUSH") == 0) {
            long long x;
            scanf("%lld", &x);
            p.inserir(x);
            if (m.n == 0) {
                m.inserir(x);
            } else if (m.topoPilha() >= x) {
                m.inserir(x);
            }
        } else if (strcmp(tmp, "MIN") == 0) {
            if (m.n == 0) {
                printf("EMPTY\n");
            } else {
                printf("%d\n", m.topoPilha());
            }
        } else if (strcmp(tmp, "POP") == 0) {
            if (m.n == 0) {
                printf("EMPTY\n");
            } else {
                if (m.topoPilha() == p.topoPilha()) {
                    m.remover();
                }
                p.remover();
            }
        }
    }

    return 0;
}
