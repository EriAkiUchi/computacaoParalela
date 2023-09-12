#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int num = 11, i;

    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Processo filho calcula a primeira metade do fatorial
        int factorial = 1;
        for (i = 1; i <= num / 2; i++) {
            factorial = i;
        }
        printf("Processo Filho: Fatorial parcial de %d é %d\n", num, factorial);
    } else {
        // Processo pai calcula a segunda metade do fatorial
        int factorial = 1;
        for (i = num / 2 + 1; i <= num; i++) {
            factorial= i;
        }
        printf("Processo Pai: Fatorial parcial de %d é %d\n", num, factorial);

        // Espera pelo processo filho
        wait(NULL);

        // Calcula o fatorial total multiplicando as partes calculadas pelo pai e pelo filho
        int total_factorial = 1;
        for (i = 1; i <= num; i++) {
            total_factorial *= i;
        }
        printf("\nProcesso Pai: O Fatorial de %d é %d\n", num, total_factorial);
    }

    return 0;
}
