#include <iostream>

void ImprimeMatriz(int *m, int n)
{
  for(int i = 0; i < n; i++)
    {
      std::cout << std::endl;
      for(int j = 0; j < n; j++)
        {
          std::cout << m[n*i + j] << " ";
        }
      
    }
}

void ImprimeTransposta(int *m, int n)
{
  for(int i = 0; i < n; i++)
    {
      std::cout << std::endl;
      for(int j = 0; j < n; j++)
        {
          std::cout << m[n*j + i] << " ";
        }
      
    }
}

int main() {

  int n = 0;
  
  std::cout << "Qual o tamanho n da matriz nxn? ";
  std::cin >> n;

  int*m = new int[n*n];
  
  
  for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
        {
          std::cout << "\nInsira o elemento na linha " << i << " e coluna " << j << " da matriz: ";
          std::cin >> m[n*i + j];
        }
    }

  std::cout << "\nA matriz informada é:" << std::endl;
  ImprimeMatriz(m, n);

  std::cout << "\n\nE sua transposta é:" << std::endl;
  ImprimeTransposta(m, n);

  std::cout << std::endl;

  delete[] m;

  return 0;
    
}
