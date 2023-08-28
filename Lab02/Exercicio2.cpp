#include <iostream> 

int main (){
  int N1  = 7;
  int N2 = 8;
  int N3 = 9;

  float ME = (N1 + N2 + N3) / 3;

  float MA = ((N1) + (N2*2) + (N3*3) + ME)/7;

  std::cout << "As notas foram: " << N1 << ", " << N2 << " e " << N3 << "\nCom uma média aproveitada de: \n";
    
  if (MA >= 9){
    std::cout << MA << " ==  A" << std::endl;
  }
  else if (MA >= 7.5){
    std::cout << MA << " ==  B" << std::endl;
  }
  else if (MA >= 6){
    std::cout << MA << " ==  C" << std::endl;
  }
  else if (MA >= 4){
    std::cout << MA << " ==  D" << std::endl;
  }
  else{
    std::cout << MA << " ==  E" << std::endl;
  }
  return 0;
}
