#include <iostream>

int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

void somarLinhas(int linhaSomar, int linhaAtualizar) {
  for (int i = 0; i < 3; i++) {
    matriz[linhaAtualizar][i] += matriz[linhaSomar][i];
  }
}

void multiplicarLinhas(int linhaMultiplicar, int linhaAtualizar) {
  for (int i = 0; i < 3; i++) {
    matriz[linhaAtualizar][i] *= matriz[linhaMultiplicar][i];
  }
}
int main() {
  std::cout << "matriz inicial:\n";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << matriz[i][j] << " ";
    }
    std::cout << "\n";
  }
  int linha0 = 0;
  int linha1 = 1;
  somarLinhas(linha0, linha1);

  std::cout << "\nmatriz com L0 e L1 somadas:\n";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << matriz[i][j] << " ";
    }
    std::cout << "\n";
  }

  multiplicarLinhas(linha0, linha1);
  std::cout << "\nmatriz com L0 e L1 multiplicadas:\n";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << matriz[i][j] << " ";
    }
    std::cout << "\n";
  }
}