#include <iostream>

void ImprimeMatriz(int m[3][3], int n)
{
  for(int i = 0; i < n; i++)
    {
      std::cout << std::endl;
      for(int j = 0; j < n; j++)
        {
          std::cout << m[i][j] << " ";
        }
      
    }
}

void Modulo(int m[3][3], int n)
{
  for(int i = 0; i<n; i++)
    {
      for(int j = 0; j<n; j++)
        m[i][j] = abs(m[i][j]);
    }
}

int main() {

  int n = 3;
  
  int m[3][3] =  {{-12, 23, -34},
                  {45, -56, 67},
                  {-78, 89, -90}};
  
  std::cout << "\nMatriz original:" << std::endl;
  ImprimeMatriz(m, n);

  Modulo(m, n);

  std::cout << "\n\nMatriz em modulo:" << std::endl;
  ImprimeMatriz(m, n);

  std::cout << std::endl;
  
  return 0;
  
}


