#include <iostream> 

int main (){
  // Tamanho da pirâmide (deve ser impar)
  int size = 11;

  for (int i = 0; i < size; i++){;
    for (int j = i; j < size-i; j++){
      std::cout << j+1 << " ";
    }
    std::cout << std::endl;
    
    for (int k = 0; k < (i + 1) * 2; k++){
      std::cout << " ";
    }
  }
  
}
