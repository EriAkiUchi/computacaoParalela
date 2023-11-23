--------------------------------------------------------------   
#Integrantes:  
#NOME: Pedro Loureiro Morone Branco Volpe TIA: 42131936  
#NOME: Eric Akio Uchiyamada TIA: 42107865  
#NOME: Oliver Kieran Galvão McCormack TIA: 42122058  
--------------------------------------------------------------   
--------------------------------------------------------------        
**• Como compilar o programa na plataforma disponibilizada**  
  
Para compilar os códigos é necessário baixar as bibliotecas:  
GNU com o seguinte comando:  
sudo dnf install gmp-devel      
GCC com o seguinte comando:    
sudo dnf install gcc  
 
_Para compilar a versão serial:_         
gcc -o euler_serial -lgmp euler_serial.c   
  
_Para rodar a versão paralela:_    
gcc -o euler_paralelo -pthread -lgmp euler_paralelo.c    
  
OBS: o comando (-lgmp) é usado para incluir a biblioteca gmp na compilação.    
--------------------------------------------------------------      
**• Como executar o programa**   
_Para rodar a versão serial:_  
time ./euler_serial  
  
_Para rodar a versão paralela:_  
time ./euler_paralelo  
  
OBS: os (time) presentes antes do comando de execução servem para obtermos o tempo de execução dos códigos  
--------------------------------------------------------------         
** • Como comprovar que os resultados propostos foram alcançados. **   
  
Para comprovar que os resultados de fato foram alcançados, criamos uma função simples para ler dois    
arquivos e imprimir a quantidade de caracteres iguais em sequencia, isto é, ele mostrara a quantidade    
de casas decimais precisas das versões obtidas em comparação com o resultado obtido pela NASA.  
    
_Para compilar e executar o comparador:_      
(Nota: os arquivos que o comparador irá ler estão definidos dentro do próprio código, portanto caso queira    
mudar será necessário alterar o código)      
Compilar: gcc -o comparador comparador.c    
Executar: time ./comparador    
--------------------------------------------------------------   
## Os resultados.  
Para calcularmos os valores de e(1) em cada uma das versões decidimos armazenar seus valores em arquivos,  
devido ao seu tamanho excessivamente grande. Utilizamos duas threads para realizar o cálculo na versão  
paralela, visto que possuiamos apenas dois núcleos disponiveis.  
   
Para visualizar o euler obtido na versão serial, abra o arquivo:  
ValorSerial.txt   
Para a versão paralela:    
ValorPthreads.txt  
Para comparação manual (caso desejar), vide arquivo:  
ValorReal.txt  
OBS: Caso o aquivo não abrir no github, favor abri-lo no ambiente da AWS.  
--------------------------------------------------------------    
**Precisão**   
A precisão na versão serial foi de: _35661_ casas precisas.  
Já na versão paralela obtivemos: _16326_ casas precisas.   
Ou seja, não conseguimos obter um resultado mais preciso que a versão serial, porem chgamos perto.  
     
** O speedup **      
Na versão serial obtivemos um tempo de execução de: **37,664 segundos**     
Já na versão paralela obtivemos um tempo de: **47,379 segundos**  
  
Isso resultou em um speedup de: **0,7949513498**   
Ou seja, não conseguimos obter um speedup adequando, resultando em uma versão paralela mais lenta que a 
versão serial.     
 
--------------------------------------------------------------   
###Considerações finais: 
Nosso grupo obtou por usar a biblioteca GMP(GNU Multiple Precision Arithmetic Library), pois ela permite   
manipular números com precisão arbitrária, sendo útil em situações onde números inteiros ou de ponto   
flutuante com tamanhos maiores que os tipos de dados padrão são necessários. Como é o caso do valor de e(1)  
  
E nós utilizamos a biblioteca Pthreads(POSIX Threads), pois inicialmete fizemos o código com a biblioteca  
OpenMP, porém encontramos problemas com a imcompatibilidade dela com a GMP, e graças a orientação do professor  
mudamos para a biblioteca Pthreads e conseguimos realizar a precisão com maio sucesso na versão paralela,  
embora esta não tenha superado a versão serial.  
--------------------------------------------------------------   
  
