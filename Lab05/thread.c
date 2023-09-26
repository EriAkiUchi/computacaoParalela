#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Número de linhas da matriz
#define m 10
// Número de colunas da matriz
#define n 10
// Número de threads -> 1 por linha
#define thread_count 10

double A[m][n] =
{
  {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0},
  {11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0},
  {21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0},
  {31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0, 40.0},
  {41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0, 49.0, 50.0},
  {51.0, 52.0, 53.0, 54.0, 55.0, 56.0, 57.0, 58.0, 59.0, 60.0},
  {61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0, 68.0, 69.0, 70.0},
  {71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0, 79.0, 80.0},
  {81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0, 89.0, 90.0},
  {91.0, 92.0, 93.0, 94.0, 95.0, 96.0, 97.0, 98.0, 99.0, 100.0}
};

double x[n] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
double y[m];

void *Pth_mat_vect(void *rank) //esse é o cod. que o prof passou
{
  long my_rank = (long)rank;
  int i, j;
  int local_m = m / thread_count;
  int my_first_row = my_rank * local_m;
  int my_last_row = (my_rank + 1) * local_m - 1;
  
  for (i = my_first_row; i <= my_last_row; i++) 
  {
    y[i] = 0.0;
    for (j = 0; j < n; j++)
      y[i] += A[i][j] * x[j];
  }
  return NULL;
}

int main() 
{
  pthread_t *thread_ids;
  long thread;
  
  thread_ids = malloc(thread_count * sizeof(pthread_t));
  
  for (thread = 0; thread < thread_count; thread++)//cria e fazendo mult
    pthread_create(&thread_ids[thread], NULL, Pth_mat_vect, (void *)thread);
  
  for (thread = 0; thread < thread_count; thread++)//junta os resultados
    pthread_join(thread_ids[thread], NULL);
  
  free(thread_ids);
   
    printf("Matriz A:\n");
    for (int i = 0; i < m; i++) 
    {
      for (int j = 0; j < n; j++) 
        printf("%lf ", A[i][j]);
      printf("\n");
    }

  printf("Vetor x:\n");
  for (int i = 0; i < n; i++)
    printf("%lf\n", x[i]);

  printf("Resultado (Vetor y):\n");
  for (int i = 0; i < m; i++)
    printf("%lf\n", y[i]);
}
