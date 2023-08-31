#include <iostream>
#include <string.h>

struct Pessoa
{
  std::string nome;
  int idade;
  float peso;
  float altura;
};

void ImprimeDados(Pessoa pessoa)
{
  std::cout << "Nome: " << pessoa.nome << std::endl;
  std::cout << "Idade: " << pessoa.idade << std::endl;
  std::cout << "Peso (kg): " << pessoa.peso << std::endl;
  std::cout << "Altura (m): " << pessoa.altura << std::endl;

  std::cout << std::endl;
}

int main() {
  Pessoa v[3];

  for(int i = 0; i < 3; i++)
    {
      std::cout << "Insira o nome da " << i+1 << "a pessoa: ";
      std::cin >> v[i].nome;

      std::cout << "Insira a idade da " << i+1 << "a pessoa: ";
      std::cin >> v[i].idade;

      std::cout << "Insira o peso (em kg) da " << i+1 << "a pessoa: ";
      std::cin >> v[i].peso;

      std::cout << "Insira a altura (em m) da " << i+1 << "a pessoa: ";
      std::cin >> v[i].altura;

      std::cout << std::endl;
    }

  for(int i = 0; i < 3; i++)
    ImprimeDados(v[i]);

  return 0;
}
