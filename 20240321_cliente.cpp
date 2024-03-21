#include<stdio.h>
#include <time.h>
#define MAX 50

struct data {
    int dia, mes, ano;
    void ler() {
        scanf("%d/%d/%d%*c", &dia, &mes, &ano);
    }
    void imprimir() {
        printf("%02d/%02d/%04d\n", dia, mes, ano);
    }
    int calcularIdade() {
        int diaAtual = 21, mesAtual = 3, anoAtual = 2024;

        /*time_t mytime;
        mytime = time(NULL);
        struct tm tm = *localtime(&mytime);
        int diaAtual = tm.tm_mday;
        int mesAtual = tm.tm_mon + 1;
        int anoAtual = tm.tm_year + 1900;*/

        if (mes < mesAtual ||
            (mes == mesAtual && dia <= diaAtual)) {
            return anoAtual - ano;
        } else {
            return (anoAtual - ano) - 1;
        }
    }
};

struct Cliente {

    char nome[100];
    data nascimento;
    int idade;
    char sexo;

    void ler() {
        scanf("%[^\n]%*c", nome);
        nascimento.ler();
        idade = nascimento.calcularIdade();
        scanf("%c%*c", &sexo);
    }

    void imprimir() {
        printf("%s\n", nome);
        nascimento.imprimir();
        printf("%d\n", idade);
        printf("%c\n", sexo);
    }

};

int main() {

    Cliente c[MAX];
    int ultimo = 0, opcao;

    do {

        printf("1. Cadastrar\n");
        printf("2. Listar\n");
        scanf("%d%*c", &opcao);

        switch(opcao) {
            case 1:
                c[ultimo].ler();
                ultimo++;
                break;
            case 2:
                for (int i = 0; i < ultimo; i++) {
                    c[i].imprimir();
                }
                break;
        }

    } while (opcao == 1 || opcao == 2);


    return 0;
}
