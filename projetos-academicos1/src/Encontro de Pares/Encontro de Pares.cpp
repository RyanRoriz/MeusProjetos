//Encontro de Pares
#include <stdio.h>

int main() {
    int inicio, fim, i;
    int contador = 0; 

    printf("Digite o numero inicial: ");
    scanf("%d", &inicio);

    printf("Digite o numero final: ");
    scanf("%d", &fim);

    printf("\nPares encontrados: ");

    for (i = inicio; i <= fim; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
            contador++;
        }
    }
    printf("\nTotal de pares: %d\n", contador);
    return 0;
}


//o "i" serve como um indicador de inicio e fim, sem ele nãe se sabe onde a entrada começa ou termina. 
//o "++" é um dos atalhos do C++, ele somar 1 ao valor atual de uma variável. No exemplo do contador ele começa valendo 0 e toda vez que o contador encontra um numero par ele executa o "contado++". Em resumo ele é um jeito mais rapido e facil de dizer ao C avançar um numero.
//o "&" literalmente significa "e".
