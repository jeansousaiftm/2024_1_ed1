#include<stdio.h>
#include<string.h>

struct No {

    char idioma[200];
    char texto[200];
    No* prox;

    No() {
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

    void inserirFinal(char idioma[], char texto[]) {
        No* novo = new No();
        strcpy(novo->idioma, idioma);
        strcpy(novo->texto, texto);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    void encontrarIdioma(char idioma[]) {
        No* aux = inicio;
        while (aux != NULL) {
            if (strcmp(aux->idioma, idioma) == 0) {
                printf("%s\n", aux->texto);
            }
            aux = aux->prox;
        }
    }

};

int main() {

    Lista l;

    int n;
    scanf("%d%*c", &n);

    char idioma[200], texto[200], nome[200];

    for (int i = 0; i < n; i++) {
        scanf("%[^\n]%*c", idioma);
        scanf("%[^\n]%*c", texto);
        l.inserirFinal(idioma, texto);
    }

    scanf("%d%*c", &n);

    for (int i = 0; i < n; i++) {
        scanf("%[^\n]%*c", nome);
        scanf("%[^\n]%*c", idioma);
        printf("%s\n", nome);
        l.encontrarIdioma(idioma);
        printf("\n");
    }

    return 0;
}
