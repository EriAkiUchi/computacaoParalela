#include <stdio.h>
#include <stdlib.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 10

double A[MATRIX_ROWS][MATRIX_COLS] =
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

double x[MATRIX_COLS] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
double y[MATRIX_ROWS];

void MatrixVectorMultiply()
{
  for (int i = 0; i < MATRIX_ROWS; i++)
  {
    y[i] = 0.0;
    for (int j = 0; j < MATRIX_COLS; j++)
    {
      y[i] += A[i][j] * x[j];
    }
  }
}

int main()
{
  MatrixVectorMultiply();

  printf("Matrix A:\n");
  for (int i = 0; i < MATRIX_ROWS; i++)
  {
    for (int j = 0; j < MATRIX_COLS; j++)
      printf("%lf ", A[i][j]);
    printf("\n");
  }

  printf("Vector x:\n");
  for (int i = 0; i < MATRIX_COLS; i++)
    printf("%lf\n", x[i]);

  printf("Result (Vector y):\n");
  for (int i = 0; i < MATRIX_ROWS; i++)
    printf("%lf\n", y[i]);

  return 0;
}
