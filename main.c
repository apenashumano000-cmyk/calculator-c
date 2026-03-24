#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    char ad = '+';
    char sub = '-';
    char mult = '*';
    char div = '/';

    while (1) {
        printf("===============================\n");
        printf("     Calculadora Simples\n");
        printf("===============================\n");
        printf("Selecione uma operacao: \n");
        printf("1. Adicao\n");
        printf("2. Subtracao\n");
        printf("3. Multiplicacao\n");
        printf("4. Divisao\n");
        printf("5. Sair\n");

        int request;
        char input_buffer[100];
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
            printf("Digite uma opção valida.\n");
            clear_screen();
            continue;
        }
        if (sscanf(input_buffer, "%d", &request) != 1) {
            printf("Digite uma opção valida.\n");
            clear_screen();
            continue;
        }

        if (request < 1 || request > 5) {
            printf("Digite uma opção valida.\n");
            clear_screen();
            continue;
        }

        if (request == 5) {
            printf("Obrigado por usar a calculadora! Ate a proxima.\n");
            break;
        }

        double num1, num2;
        printf("Digite o primeiro namero: ");
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL || sscanf(input_buffer, "%lf", &num1) != 1) {
            printf("Entrada invalida para numero.\n");
            clear_screen();
            continue;
        }
        printf("Digite o segundo numero: ");
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL || sscanf(input_buffer, "%lf", &num2) != 1) {
            printf("Entrada invalida para numero.\n");
            clear_screen();
            continue;
        }

        double res;
        switch (request) {
            case 1:
                res = num1 + num2;
                printf("Resultado: %.6g %c %.6g = %.6g\n", num1, ad, num2, res);
                break;
            case 2:
                res = num1 - num2;
                printf("Resultado: %.6g %c %.6g = %.6g\n", num1, sub, num2, res);
                break;
            case 3:
                res = num1 * num2;
                printf("Resultado: %.6g %c %.6g = %.6g\n", num1, mult, num2, res);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Erro: Divisao por zero nao eh permitida.\n");
                } else {
                    res = num1 / num2;
                    printf("Resultado: %.6g %c %.6g = %.6g\n", num1, div, num2, res);
                }
                break;
        }

        printf("Deseja realizar outra operacao? (s/n): ");
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
            printf("Erro: Resposta invalida.\n");
            break;
        }
        // Remove trailing newline if present
        size_t len = strlen(input_buffer);
        if (len > 0 && input_buffer[len - 1] == '\n') {
            input_buffer[len - 1] = '\0';
        }
        // Convert to lowercase
        char replay = tolower(input_buffer[0]);

        if (replay != 's' && replay != 'n') {
            printf("Erro: Resposta invalida.\n");
            break;
        }
        if (replay == 'n') {
            printf("Obrigado por usar a calculadora! Ate a proxima.\n");
            break;
        }
        clear_screen();
    }

    return 0;
}