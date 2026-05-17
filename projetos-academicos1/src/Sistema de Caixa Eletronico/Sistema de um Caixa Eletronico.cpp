#include <stdio.h>

int main() {
    float saldo, valor;
    int opcao;

    printf("Digite o saldo inicial do caixa: R$ ");
    scanf("%f", &saldo);

    do {
        printf("\n--- CAIXA ELETRONICO ---");
        printf("\n1 - Consultar seu saldo");
        printf("\n2 - Sacar um valor");
        printf("\n3 - Depositar um valor");
        printf("\n4 - Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nSaldo atual: R$ %.2f\n", saldo);
                break;

            case 2:
                printf("\nDigite o valor do saque: ");
                scanf("%f", &valor);
                
            
                if (valor > saldo) {
                    printf("Saldo insuficiente.\n");
                } else {
                    saldo -= valor;
                    printf("Saque realizado! Esse eh seu novo saldo: R$ %.2f\n", saldo);
                }
                break;

            case 3:
                printf("\nDigite o valor do deposito: ");
                scanf("%f", &valor);
                saldo += valor;
                printf("Deposito realizado! Esse eh seu saldo: R$ %.2f\n", saldo);
                break;

            case 4:
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}

//O "for" é para quando você sabe o limite, (ex: 10 números).
//O "do" ou "do-while" é para quando você quer que algo aconteça repetidamente até que alguém peça para parar.
//o "while" Ele é quem decide se o caixa eletrônico deve continuar ligado ou se é hora de desligar tudo. O "while" significa enquanto.  
//O "switch opção" faz o programa olha para o número que você digitou no scanf.
//As "Cases" São os "endereços". Se você digitou 2, o programa ignora o case 1 e pula direto para o código do saque.
//O "break" foi usado como um "freio de mão" pro switch case que eu usei para esse Caixa eletronico, ele serve como um "." ou melhor dizendo "pare aqui e saia do switch".

