#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operacao;

    cout << "=== Calculadora ===" << endl;
    cout << "Digite o primeiro numero: ";
    cin >> num1;
    cout << "Digite o operador (+, -, *, /): ";
    cin >> operacao;
    cout << "Digite o segundo numero: ";
    cin >> num2;

    cout << "Resultado: ";

    switch (operacao) {
        case '+': cout << num1 + num2; break;
        case '-': cout << num1 - num2; break;
        case '*': cout << num1 * num2; break;
        case '/':
            if (num2 != 0)
                cout << num1 / num2;
            else
                cout << "Erro: divisao por zero!";
            break;
        default:
            cout << "Operador invalido!";
    }

    cout << endl;
    return 0;
}