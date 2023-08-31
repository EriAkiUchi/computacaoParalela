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

void Transpor(int m[3][3], int n)
{
  int aux = 0;
  
  for(int i = 0; i < n; i++)
    {
      for(int j = i; j < n; j++)
        {
          aux = m[i][j];
          m[i][j] = m[j][i];
          m[j][i] = aux;
        }
      
    }
  

}

int main() {

  int n = 3;

  int m[3][3] =  {{1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9}};
  

  std::cout << "\nA matriz informada é:" << std::endl;
  ImprimeMatriz(m, n);

  Transpor(m, n);

  std::cout << "\n\nE sua transposta é:" << std::endl;
  ImprimeMatriz(m, n);

  std::cout << std::endl;

  return 0;
    
}
