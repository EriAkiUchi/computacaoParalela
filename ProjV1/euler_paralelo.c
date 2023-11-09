#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <omp.h>

void calcTaylorPart(int start, int end, mpf_t *partialSum) {
    mpf_t term;
    mpf_init2(term, 10024); // Aumente a precisão conforme necessário
    mpf_set_ui(*partialSum, 0);
    mpf_set_ui(term, 1);

    for (int i = start; i <= end; i++) {
        if (i == 0) {
            mpf_set_ui(term, 1);
        } else {
            mpf_div_ui(term, term, i);
        }
        mpf_add(*partialSum, *partialSum, term);
    }

    mpf_clear(term);
}

void save_to_file(mpf_t e, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    gmp_fprintf(file, "%.300000Ff\n", e);
    fclose(file);
}

int main() {
    omp_set_num_threads(4);
    int limit = 1000000; // Aumente a precisão ao aumentar o número de bits
    mpf_t e;
    mpf_init2(e, 10024); // Aumente a precisão conforme necessário

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        int terms_per_thread = limit / num_threads;
        int start = thread_id * terms_per_thread;
        int end = (thread_id == num_threads - 1) ? limit : start + terms_per_thread;

        mpf_t partialSum;
        mpf_init2(partialSum, 10024); // Aumente a precisão conforme necessário

        calcTaylorPart(start, end, &partialSum);

        #pragma omp critical
        mpf_add(e, e, partialSum);

        mpf_clear(partialSum);
    }

    save_to_file(e, "ValorParalelo.txt");
    mpf_clear(e);
    
    return 0;
}
