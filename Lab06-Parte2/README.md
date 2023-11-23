NOME: Pedro Loureiro Morone Branco Volpe TIA: 42131936  
NOME: Eric Akio Uchiyamada TIA: 42107865  
NOME: Oliver Kieran Galvão McCormack TIA: 42122058  
  
Problema do Trapézio  
As duas estratégias paralelas utilizadas foram a atomic e a reduction.  
  
Quanto ao integral resultante, a estratégia atomic foi menos precisa (atomic resultou em 1,71828182845905e+00 comparado com 1.718281828459048421464672173897e+00 da estratégia reduction).  
  
É provável que reduction tenha sido mais preciso que atomic devido ao fato de gerenciar a variável atualizada localmente, minimizando o impacto de atualizações concorrentes, enquanto que atomic precisa gerenciar várias threads tentando atualizar a mesma variável, o que gera contenção, que possivelmente afeta a precisão do cálculo.  
  
Quanto ao código de multiplicação de matrizes, os resultados foram iguais, então não foi evidenciada uma precisão maior de uma estratégia sobre a outra neste caso.  
  
Problema da multiplicação de matriz  
As duas estratégias paralelas utilizadas foram critical e lock.  
  
Os tempos finais foram extremamente semelhantes e os cálculos foram iguas. Isso provavelmente aconteceu porque a matriz não é grande.  
Mas, a versão com lock provavelmente será mais rápida considerando a média.  
  

  
| Tabela | Trapezio Versão 1 (uso de atomic) | Trapezio Versão 2 (uso de reduction) | Matriz Versão 1 (uso de critical)| Matriz Versão 2 (uso de lock) |
| ------------- | ------------- | ------------- | ------------- | ------------- |
| Processador t3.medium da AWS (Com 2 Núcleos) | | | | |
| | (0.127+0.117+0.109) / 3 | (0.104+0.124+0.130) / 3 | (0.002+0.002+0.003) / 3 | (0.002+0.002+00.002)/3 |
| Tempo Médio de execução em segundos(de 3 execuções) | 0.1176666667 | 0.1193333333 | 0.0023333333 | 0.0002 |
| Quantidade de threads | 2 | 2 | 10 | 10 |
| Processador t2.medium da AWS (Com 2 Núcleos) | | | | |
| | (0.079 + 0.079 + 0.080) / 3 | (0.080 + 0.081+ 0.081) / 3 | (0.003 + 0.003 + 0.003) / 3 | (0.002 + 0.003 + 0.003) / 3 |
| Tempo Médio de execução em segundos(de 3 execuções) | 0.0793333333 | 0.0806666667 | 0.003 | 0.0026666667 |
| Quantidade de threads | 2 | 2 | 10 | 10 |
