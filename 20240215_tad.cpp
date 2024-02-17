#include<stdio.h>
#define N 500

struct Produto {

    char nome[100];
    double preco;

    void ler() {
        printf("Digite o nome do produto: ");
        scanf("%[^\n]%*c", nome);
        printf("Digite o preco: ");
        scanf("%lf%*c", &preco);
    }

    void imprimir() {
        printf("Nome: %s\n", nome);
        printf("Preco: R$ %.2lf\n", preco);
    }

};

struct Venda {

    char cliente[100];
    int qtdProdutos;
    Produto produtos[20];

    void ler() {
        printf("Digite o cliente: ");
        scanf("%[^\n]%*c", cliente);
        printf("Digite a quantidade de itens: ");
        scanf("%d%*c", &qtdProdutos);
        for (int i = 0; i < qtdProdutos; i++) {
            produtos[i].ler();
        }
    }

    void imprimir() {
        printf("Cliente: %s\n", cliente);
        printf("Qtd de itens: %d\n", qtdProdutos);
        for (int i = 0; i < qtdProdutos; i++) {
            produtos[i].imprimir();
        }
        printf("Total da venda: R$ %.2lf\n", totalVenda());
    }

    double totalVenda() {
        double t = 0;
        for (int i = 0; i < qtdProdutos; i++) {
            t += produtos[i].preco;
        }
        return t;
    }

};

int main() {

    Venda v;

    v.ler();
    v.imprimir();

    return 0;
}
