#include <iostream> 
#include <string>
//Insertion sort
std::string sort(std::string str, int len){
  for (int i = 1; i < len; i++){
    char temp = str[i];
    
    int j = i - 1;
    while (j >= 0 && str[j] > temp){
      str[j + 1] = str[j];
      j--;
    }
    str[j + 1] = temp;
  }
  return str;
}
void printInOrder(std::string name, int size){
  std::cout << "Nome antes de ser ordenado: " << name << std::endl;
  
  std::string inOrderName = sort(name, size);
  
  std::cout << "Nome ordenado: " << inOrderName << std::endl;
}

int main () {
  std::string name1 = "rogerio";
  std::string name2 = "cleberson";

  int name1Size = name1.length();
  int name2Size = name2.length();

  printInOrder(name1, name1Size);
  std::cout << std::endl;
  printInOrder(name2, name2Size);
  
  return 0;
}
