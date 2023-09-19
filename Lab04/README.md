--  

NOME: Pedro Loureiro Morone Branco Volpe  TIA: 42131936  
NOME: Eric Akio Uchiyamada                TIA: 42107865  
NOME: Oliver Kieran Galvão McCormack      TIA: 42122058  

--  

Primeiro, criamos as variáveis de caminho (path), ID da memória compartilhada (shmid) e tamanho da memória compartilhada (size). Obtemos a chave única (key) com ftok (usando a permissão 'W' ou write), criamos a região de memória compartilhada com shmget (usando as variáveis criadas anteriormente) e ligamos a região de memória compartilhada ao ponteiro p usando shmat.  
  
No bloco de operação fork(), usamos as variáveis para os processos e a variável ponteiro  (p). O processo filho realiza adição usando p, enquanto o processo pai realiza multiplicação usando o ponteiro.
Como o ponteiro está associado a memória compartilhada, seu valor é salvo dentro da memoria compartilhada e dessa forma qualquer alteração feita no filha será vista pelo pai e vice-versa. Diferente da variavel local (value) que não está na memoria compartilhada.       
  
