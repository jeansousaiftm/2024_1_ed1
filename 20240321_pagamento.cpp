#include<stdio.h>
#define MAX 10

struct Funcionario {

    char nome[100], cargo[100];
    double salario, beneficios, descontos;

    void ler() {
        scanf("%[^\n]%*c", nome);
        scanf("%[^\n]%*c", cargo);
        scanf("%lf%*c", &salario);
        scanf("%lf%*c", &beneficios);
        scanf("%lf%*c", &descontos);
    }

    void imprimir() {
        printf("%s\n", nome);
        printf("%s\n", cargo);
        printf("R$ %.2lf\n", salario);
        printf("R$ %.2lf\n", beneficios);
        printf("R$ %.2lf\n", descontos);
        printf("R$ %.2lf\n", calcularSalarioFinal());
    }

    double calcularSalarioFinal() {
        return (salario + beneficios) - descontos;
    }
};

struct Loja {

    Funcionario f[MAX];
    int ultimo = 0;

    void ler() {
        if (ultimo >= MAX) {
            printf("Loja cheia\n");
            return;
        }
        f[ultimo].ler();
        ultimo++;
    }

    void imprimir() {
        for (int i = 0; i < ultimo; i++) {
            f[i].imprimir();
        }
    }

    double calcularMediaSalarial() {
        if (ultimo == 0) {
            return 0;
        }
        double media = 0;
        for (int i = 0; i < ultimo; i++) {
            media += f[i].calcularSalarioFinal();
        }
        return media / ultimo;
    }

    void exibirMaiorSalario() {
        if (ultimo == 0) {
            printf("Loja vazia\n");
            return;
        }
        double maximo = f[0].calcularSalarioFinal();
        int posicao = 0;
        for (int i = 1; i < ultimo; i++) {
            if (f[i].calcularSalarioFinal() > maximo) {
                maximo = f[i].calcularSalarioFinal();
                posicao = i;
            }
        }
        f[posicao].imprimir();
    }

};

int main() {

    Loja l;
    int opcao;

    do {
        printf("1. Ler\n");
        printf("2. Listar\n");
        printf("3. Media\n");
        printf("4. Maior\n");
        scanf("%d%*c", &opcao);

        switch(opcao) {
            case 1:
                l.ler();
                break;
            case 2:
                l.imprimir();
                break;
            case 3:
                printf("R$ %.2lf\n", l.calcularMediaSalarial());
                break;
            case 4:
                l.exibirMaiorSalario();
                break;
        }

    } while (opcao >= 1 && opcao <= 4);

    return 0;
}
