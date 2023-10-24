#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
  return exp(x);
}

double line_area(double a,double b,int n){
  double x;
  double h = (b-a)/n;
  double approx = (f(a) + f(b))/2.0;
  
  for(int i = 1; i <= n-1; i++){
    x = a + i*h;
    approx += f(x);
  }
  approx = h*approx;
  
  return approx;
}

int main(){
  double a,b,result;
  int n;
  n = 10000000; //Numero de trapezios
  a = 0.0;
  b = 1.0;

  result = line_area(a,b,n);
  printf("%lf",result);
}
