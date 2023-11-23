#include <stdio.h>
#include <math.h>
#include <gmp.h>


void euler(int n, mpf_t *e) {
    mpf_t fatorial, fracao;
    mpf_init2(fatorial,1048576);
    mpf_set_ui(fatorial,1.0);

    mpf_init2(fracao,1048576);
    mpf_set_ui(fracao,1.0);

    for (int i = 0; i < n; i++) {
            mpf_add(*e, *e, fracao);                  //adicionar valor atual no número e
                mpf_mul_ui(fatorial, fatorial, i + 1);    //calcular o fatorial do próximo
                mpf_ui_div(fracao, 1, fatorial);       //calcular a divisão do próximo
    }

    mpf_clear(fracao);              // LIBERA MEMÓRIA ALOCADA PELA FRACAO EVITANDO MEMORY LEAK
        mpf_clear(fatorial);            // LIBERA MEMÓRIA ALOCADA PELO FATORIAL EVITANDO MEMORY LEAK
}

void salvar_arquivo(mpf_t e, const char* filename) {
        FILE* file = fopen(filename, "w");
        if (file == NULL) {
                perror("Erro ao abrir o arquivo");
                return;
        }
        gmp_fprintf(file, "%.3000000Ff\n", e); // Salva em arquivo printando 3 milhoes de digitos
        fclose(file);
}

int main() {
    int n = 1000;             // NUMERO DE SOMAS A SEREM FEITAS NA SERIE DE TAYLOR
    mpf_t e;                // ATRIBUINDO TIPO DE DADO DE ALTA PRECISÃO PARA EULER(e), AFIM DE OBTER UMA MELHOR PRECISÃO DE CASA DECIAMAIS
    mpf_init2(e,1048576);   // DEFINIMOS AQUI O TAMANHO DA PRECISÃO QUE DESEJAMOS, EM BITS, DO VALOR DE EULER(e)
    mpf_set_ui(e,0.0);      // AQUI DEFINIMOS O VALOR INICIAL DE EULER PARA ZERO. (BOM DEFINI-LO ANTES DE REALIZAR OPERAÇOES)

    euler(n, &e);           // CALCULA A POTENCIA DE EULER
    salvar_arquivo(e,"ValorSerial.txt");
    //printf("e(%d): %.4000000Ff\n", n, e);

    mpf_clear(e);           // LIBERA MEMÓRIA ALOCADA PELO EULER(e) EVITANDO MEMORY LEAK
    return 0;
}
