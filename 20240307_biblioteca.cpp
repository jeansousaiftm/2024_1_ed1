#include<stdio.h>
#define MAX_LIVROS 10

struct Livro {

    char titulo[100];
    char autor[100];
    int numPaginas;

    void ler() {
        printf("Titulo: ");
        scanf("%[^\n]%*c", titulo);
        printf("Autor: ");
        scanf("%[^\n]%*c", autor);
        printf("Num Paginas: ");
        scanf("%d%*c", &numPaginas);
    }

    void imprimir() {
        printf("Titulo: %s\n", titulo);
        printf("Autor: %s\n", autor);
        printf("Num Paginas: %d\n", numPaginas);
    }

};

struct Biblioteca {

    Livro livros[MAX_LIVROS];
    int qtdLivros;

    Biblioteca() {
        qtdLivros = 0;
    }

    void ler() {
        if (qtdLivros >= MAX_LIVROS) {
            printf("Biblioteca cheia.\n");
            return;
        }
        livros[qtdLivros].ler();
        qtdLivros++;
    }

    void imprimir() {
        for (int i = 0; i < qtdLivros; i++) {
            livros[i].imprimir();
        }
    }

    void imprimirMaior() {
        if (qtdLivros == 0) {
            printf("Biblioteca vazia.\n");
            return;
        }
        int maior = 0, posicao = -1;
        for (int i = 0; i < qtdLivros; i++) {
            if (livros[i].numPaginas > maior) {
                maior = livros[i].numPaginas;
                posicao = i;
            }
        }
        livros[posicao].imprimir();
    }

};

int main() {

    Biblioteca b;

    int opcao;

    do {

        printf("1. Ler\n");
        printf("2. Imprimir\n");
        printf("3. Imprimir Maior\n");
        printf("4. Sair\n");

        scanf("%d%*c", &opcao);

        switch(opcao) {
            case 1:
                b.ler();
                break;
            case 2:
                b.imprimir();
                break;
            case 3:
                b.imprimirMaior();
                break;
        };

    } while (opcao != 4);

    return 0;
}
