#include <stdio.h>
#include <stdlib.h>

struct Data {
    int dia, mes, ano;
};

struct Pessoa {
    char nome[30];
    float altura;
    struct Data nascimento;
};

void criaData(struct Data *D)
{
    D->mes = 1 + (rand() % 12);
    D->ano = 1950 + (rand() % 49);
    D->dia = 1 + (rand() % 30);
}

void ImprimeTelaDeOpcoes() {
    printf("1 - Inserir nome\n");
    printf("2 - Listar nomes e alturas\n");
    printf("3 - Listar nomes das pessoas nascidas antes da data fornecida\n");
    printf("4 - Sair\n");
}

void LePessoaDeTeclado(struct Pessoa *p) {
    printf("Digite o nome: \n");
    scanf("%s", p->nome);
    printf("Digite a altura: \n");
    scanf("%f", &p->altura);
}

void AdicionaPessoa(struct Pessoa *povo, struct Pessoa *p, int *qtdPessoas) {
    criaData(&p->nascimento);
    povo[*qtdPessoas] = *p;
    *qtdPessoas += 1;
}

void ImprimeTodasAsPessoas(struct Pessoa povo[10], int qtdPessoas) {
    for (int i = 0; i < qtdPessoas; i++) {
        printf("Nome: %s\n", povo[i].nome);
        printf("Altura: %f\n", povo[i].altura);
        printf("--------------------\n");
    }
}

int EscolheOpcao() {
    int opcao = 0;
    printf("Digite uma opção. \n");
    scanf("%d", &opcao);
    return opcao;
}

void LeDataDeTeclado(struct Data p){
    printf("Digite o dia: ");
    scanf("%d", &p.dia);
    printf("Digite o mes: ");
    scanf("%d", &p.mes);
    printf("Digite o ano: ");
    scanf("%d", &p.ano);
}

void ImprimeMaisVelhos(struct Pessoa povo[10], int qtdPessoas, struct Data dia){
    for (int i = 0; i < qtdPessoas; i++) {
        if(povo[i].nascimento.dia < dia.dia && povo[i].nascimento.mes < dia.mes && povo[i].nascimento.ano < dia.ano) {
            printf("Nome: %s\n", povo[i].nome);
        }
    }
}

int main()
{
    struct Pessoa povo[10];
    struct Pessoa p;
    int opcao, qtdPessoas = 0;
    struct Data dia;
    ImprimeTelaDeOpcoes();

    do
    
    {
        opcao = EscolheOpcao();
        if (opcao == 1)
        {
            LePessoaDeTeclado(&p);
            AdicionaPessoa(povo, &p, &qtdPessoas);
        }
        if (opcao == 2)
        {
            ImprimeTodasAsPessoas(povo, qtdPessoas);
        }
        if (opcao == 3)
        {
            LeDataDeTeclado(dia);
            ImprimeMaisVelhos(povo, qtdPessoas, dia);
        }
    } while (opcao != 4);
}