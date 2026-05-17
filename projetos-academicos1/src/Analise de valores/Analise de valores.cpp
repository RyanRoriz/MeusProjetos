#include <stdio.h>

int main() {
    int numeros[10];
    int i;
    int maior, menor;
    float soma = 0, media;

    for (i = 0; i < 10; i++) {
        printf("Digite o %do numero: ", i + 1); 
        scanf("%d", &numeros[i]);
        
        soma = soma + numeros[i];
    }

    media = soma / 10.0;
    
    maior = numeros[0];
    menor = numeros[0];

    for (i = 1; i < 10; i++) {
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }

    printf("\n--- RESULTADOS ---");
    printf("\nMaior valor: %d", maior);
    printf("\nMenor valor: %d", menor);
    printf("\nMedia: %.1f", media);

    printf("\nValores acima da media: ");
    for (i = 0; i < 10; i++) {
        if (numeros[i] > media) {
            printf("%d ", numeros[i]);
        }
    }

    printf("\n\nPresione ENTER para sair...");
    fflush(stdin);
    getchar();
    
    return 0;
}

//"numeros": É o nome do prédio inteiro.
//"[ ]": É o elevador.
//"i": É o botão do andar que você aperta.(top melhor exemplo que o gemini me deu, eu amei).

//sem o %d o programa perde a capacidade de mostrar valores que mudam (variáveis). Ele vira apenas um letreiro fixo que sempre diz a mesma frase, não importa o que aconteça no código.
