Integrantes do grupo:  
  
Eric AKio Uchiyamada TIA: 42107865  
  
Oliver Kieran Galvão McCormack TIA: 42122058  
  
Pedro Loureiro Morone Branco Volpe TIA: 4213193  
  
  
Como o comando time apresenta o resultado em segundos não é possível inferir com certeza a diferença de tempo entre os dois códigos.  
Mas, como fatorialFork.c não explora eficientemente paralelismo ao utilizar apenas um núcleo, é possível dizer que provavelmente a  
versão serial será mais rápida. Porque a criação de novos processos adiciona mais sobrecarga ao processador e a coordenação entre  
os processos pode adicionar mais atrasos. Mesmo que o número a ser calculado seja muito grande, a sobrecarga adicional que o fork()  
causa faria com que a versão serial provavelmente seja mais rápida.
