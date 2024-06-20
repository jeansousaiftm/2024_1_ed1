#include<stdio.h>

#define MAX_LIVROS 10

struct Livro {

    char titulo[100], autor[100];
    int numPaginas;

    void ler() {
        printf("Digite o titulo: ");
        scanf("%[^\n]%*c", titulo);
        printf("Digite o autor: ");
        scanf("%[^\n]%*c", autor);
        printf("Digite o num de paginas: ");
        scanf("%d%*c", &numPaginas);
    }

    void imprimir() {
        printf("Titulo: %s\n", titulo);
        printf("Autor: %s\n", autor);
        printf("Num. Paginas: %d\n", numPaginas);
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
            printf("Biblioteca cheia\n");
            return;
        }
        livros[qtdLivros].ler();
        qtdLivros++;
    }

    void imprimir() {
        if (qtdLivros == 0) {
            printf("Biblioteca vazia\n");
            return;
        }
        for (int i = 0; i < qtdLivros; i++) {
            livros[i].imprimir();
        }
    }

    void imprimirMaior() {
        if (qtdLivros == 0) {
            printf("Biblioteca vazia\n");
            return;
        }
        int maiorNumPaginas = livros[0].numPaginas;
        int livro = 0;
        for (int i = 1; i < qtdLivros; i++) {
            if (livros[i].numPaginas > maiorNumPaginas) {
                maiorNumPaginas = livros[i].numPaginas;
                livro = i;
            }
        }
        livros[livro].imprimir();
    }

};

int main() {

    Biblioteca b;

    int opcao;

    do {

        printf("1. Ler Livro\n");
        printf("2. Imprimir Todos\n");
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
        }

    } while (opcao != 4);

    return 0;

}
