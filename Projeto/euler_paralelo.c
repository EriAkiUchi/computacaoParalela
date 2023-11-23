#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <pthread.h>

typedef struct {
    int start;
    int end;
    mpf_t e;
} ThreadData;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void fatorial_calc(mpf_t fatorial, int n) {
    mpf_set_ui(fatorial, 1.0);

    for (int i = 2; i <= n; i++) {
        mpf_mul_ui(fatorial, fatorial, i);
    }
}

void* euler_thread(void* arg) {
    ThreadData* data = (ThreadData*)arg;

    mpf_t fatorial, fracao, e_aux;
    mpf_init2(fatorial, 1000000);
    mpf_set_ui(fatorial, 1.0);

    mpf_init2(fracao, 1000000);
    mpf_set_ui(fracao, 1.0);

    mpf_init2(e_aux, 1000000);
    mpf_set_ui(e_aux, 0.0);

    fatorial_calc(fatorial, data->start);
    mpf_ui_div(fracao, 1, fatorial);

    for (int i = data->start; i <= data->end; i++) {
        mpf_add(e_aux, e_aux, fracao);
        fatorial_calc(fatorial, i);
        mpf_ui_div(fracao, 1, fatorial);
    }

    // Operação de soma com exclusão mútua usando um mutex
    pthread_mutex_lock(&mutex);
    mpf_add(data->e, data->e, e_aux);
    pthread_mutex_unlock(&mutex);

    mpf_clear(fracao);
    mpf_clear(fatorial);
    mpf_clear(e_aux);

    pthread_exit(NULL);
}

void euler(int n, mpf_t e, int num_threads) {
    pthread_t* threads = (pthread_t*)malloc(num_threads * sizeof(pthread_t));
    ThreadData* thread_data = (ThreadData*)malloc(num_threads * sizeof(ThreadData));

    int terms_per_thread = n / num_threads;

    for (int i = 0; i < num_threads; i++) {
        thread_data[i].start = i * terms_per_thread;
        thread_data[i].end = (i == num_threads - 1) ? n : thread_data[i].start + terms_per_thread;
        mpf_init2(thread_data[i].e, 1000000);
        mpf_set_ui(thread_data[i].e, 0.0);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, euler_thread, (void*)&thread_data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);

        // Operação de soma com exclusão mútua usando um mutex
        pthread_mutex_lock(&mutex);
        mpf_add(e, e, thread_data[i].e);
        pthread_mutex_unlock(&mutex);

        mpf_clear(thread_data[i].e);
    }

    free(threads);
    free(thread_data);
}

void salvar_arquivo(mpf_t e, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    gmp_fprintf(file, "%.3000000Ff\n", e);
    fclose(file);
}

int main() {
    int num_threads = 2;
    int n = 10000;
    mpf_t e;
    mpf_init2(e, 1000000);
    mpf_set_ui(e, 0.0);

    euler(n, e, num_threads);
    mpf_sub_ui(e, e, 1);
    salvar_arquivo(e, "ValorPthreads.txt");

    mpf_clear(e);

    return 0;
}

