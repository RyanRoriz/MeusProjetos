//Sistema para calcular a média 
#include <stdio.h>

int main(){
    float nota1;
    float nota2; 
    float nota3;
    float media;
     
    printf ("Digite a primeira nota:  ");
    scanf ("%f", &nota1); 
    
    printf ("digite a segunda nota: ");
    scanf ("%f", &nota2); 
    
    printf ("digite a terceira nota: ");
    scanf ("%f", &nota3); 
    
    media = (nota1 + nota2 + nota3) /3.0;

    if (media >= 7.0) {
        printf ("media: %.2f\n", media);
        printf ("situacao: Aprovado");
    }
    else if (media >= 5.0 && media < 7.0){
        printf ("media: %.2f\n", media);
        printf ("Situacao: Recuperacao");
    }
    else {
        printf ("media: %.2f\n", media);
        printf ("Situacao: Reprovado");
    }

    return 0;
}
//o "%.2f\n" serve pra que no prompt apareça um numero com 2 casas deciamais dps da virgula.
