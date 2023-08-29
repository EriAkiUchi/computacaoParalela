#include <iostream>
#include <string>
int posicaoCaractere(char caractere, std::string string) {
  for (int i = 0; i < string.length(); i++) {
    if (string[i] == caractere)
      return i;
  }
  return -1;
}

int main() {
  char caractere = 'a';
  std::string string = "coisa";
  int posicao = posicaoCaractere(caractere, string);
  std::cout << "caractere " << caractere << " está na posição " << posicao
            << "\n";
}