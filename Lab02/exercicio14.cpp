#include <cstring>
#include <iostream>

char str[100] = "paralelo";

void inserirCaractere(char caracter, int posicao) {
  if (posicao >= 0 && posicao <= strlen(str)) {
    for (int i = strlen(str); i >= posicao; i--) {
      str[i + 1] = str[i];
    }
    str[posicao] = caracter;
  }
}

int main() {
  char caracter = 'w';
  int posicao = 3;
  std::cout << "string inicial:\n" << str << "\n\n";
  inserirCaractere(caracter, posicao);
  std::cout << "string com caractere na posicao " << posicao << ":\n"
            << str << "\n";
}