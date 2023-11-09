-----------------------------------------------------------  
  Integrantes:   
  NOME: Pedro Loureiro Morone Branco Volpe TIA: 42131936  
  NOME: Eric Akio Uchiyamada TIA: 42107865  
  NOME: Oliver Kieran Galvão McCormack TIA: 42122058  
-----------------------------------------------------------  
O valor mais aproximado de e(1), constante de euler, que conseguimos alcançar com precisão foi de:   
  
Valor de e(1)                                          Aproximação Correta    
2.71828182845904523536028747135266249775724709369995   - 50    
9574966967627724076630353547594571382178525166427427   - 52    
4663919320030599218174135966290435729003342952605956   - 52    
3073813232862794349076323382988075319525101901157383   - 52    
4187930702154089149934884167509244761460668082264800   - 52  
1684774118537423454424371075390777449920695517027618   - 52  
3860626133138458300075204493382656029760673711320070   - 52  
9328709127443747047230696977209310141692836819025515   - 52  
1086574637721112523897844250569536967707854499699679   - 52  
4686445490598793163688923009879312773617821542499922   - 52  
9576351482208269895193668033182528869398496465105820   - 52  
9392398294887933203625094431173012381970684161403970   - 52  
1983767932068328237646480429531180232878250981945581   - 52  
5301756717361332069811250996181881593041690351598888   - 52  
5193458072738667385894228792284998920868058257492796   - 52  
1048419844436346324496848756023362482704197862320900   - 52  
2160...  

Isto é, temos pelo menos 830 casas decimais precisas.   
OBS: Com certeza a precisão é muito superior a 830 casas decimais,  
pórem realizar a contagem no momento foi tudo manual...   
  
Já a versão Paralela apresentou 5 casas decimais corretas.    
  
Esse valor de precisão foi obtido pela versão serial, pois a versão paralela embora seja mais rapida,  
está muito mais imprecisa.  
  
E o speedup obtido da versão paralela em relação a serial foi de:   
1.116s / 0.401s = Portanto speeup resultou em: 2,783042394  
  
  
OBS: Bom lembra que nossa versão paralela, embora seja mais rapida, apresenta uma impresisão enorme  
Comaparada a versão serial.   
  
Para compilar os códigos é necessário baixar as bibliotecas:   
GNU com o seguinte comando:   
sudo dnf install gmp-devel  
  
E para compilar os códigos,   
Versão serial:   
gcc euler_serial.c -o euler_serial.exe -lgmp -lm  
  
Versão Paralela:   
gcc euler_paralelo.c -o euler_paralelo.exe -lgmp -fopenmp  
  
