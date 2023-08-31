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

void MultLinha(int m[3][3], int n, int fat, int linha)
{
  for(int j = 0; j<n; j++)
    {
      m[linha][j] = fat*m[linha][j];
    }
}

void MultColuna(int m[3][3], int n, int fat, int coluna)
{
  for(int i = 0; i<n; i++)
    {
      m[i][coluna] = fat*m[i][coluna];
    }
}

int main() {

  int n = 3, coord = 0, fat = 0;
  char dir = '0';
  
  
  int m[3][3] =  {{1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9}};
  
  ImprimeMatriz(m, n);
  
  std::cout << "\n\nGostaria de multiplicar uma linha ou coluna da matriz acima?(Responda L para linha e C para coluna) ";
  std::cin >> dir;

  if(toupper(dir) == 'L')
  {
    std::cout << "\nGostaria de multiplicar qual linha da matriz?(Responda de 0 a 2) ";
    std::cin >> coord;

    std::cout << "\nMultiplicar por qual fator? ";
    std::cin >> fat;

    MultLinha(m, n, fat, coord);

    std::cout << "\nNova matriz:" << std::endl;
    ImprimeMatriz(m, n);
  }
  
  
  else if(toupper(dir) == 'C')
  {
    std::cout << "\nGostaria de multiplicar qual coluna da matriz?(Responda de 0 a 2) ";
    std::cin >> coord;

    std::cout << "\nMultiplicar por qual fator? ";
    std::cin >> fat;

    MultColuna(m, n, fat, coord);

    std::cout << "\nNova matriz:" << std::endl;
    ImprimeMatriz(m, n);
  }

  std::cout << std::endl;

  return 0;
  
}


