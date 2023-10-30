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
