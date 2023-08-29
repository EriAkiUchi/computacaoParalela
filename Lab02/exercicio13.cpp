#include <cstring>
#include <iostream>
char str[100] = "paralelo";
void removerCaracter(int posicao) {
  if (posicao >= 0 && posicao < strlen(str)) {
    for (int i = posicao; i < strlen(str) - 1; ++i) {
      str[i] = str[i + 1];
    }
    str[strlen(str) - 1] = '\0';
  }
}
int main() {
  int posicao = 3;
  std::cout << "string inicial:\n" << str << "\n\n";
  removerCaracter(posicao);
  std::cout << "string sem caractere na posicao " << posicao << ":\n"
            << str << "\n";
}