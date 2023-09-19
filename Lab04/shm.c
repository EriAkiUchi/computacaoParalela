//---------------------------------------------------------------------------------
/*
NOME: Pedro Loureiro Morone Branco Volpe  TIA: 42131936
NOME: Eric Akio Uchiyamada                TIA: 42107865
NOME: Oliver Kieran Galvão McCormack      TIA: 42122058
*/
//---------------------------------------------------------------------------------
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
//---------------------------------------------------------------------------------

int main() {

  char path[] = "./";
  int shmid;
  int size = 1024;

  key_t key;
  char *data;
  
  key = ftok(path,'W'); //obtenção da chave única
  shmid = shmget(key, 1024, 0644 | IPC_CREAT);//criação da área de memória compartilhada
 
  int *p = (int *)shmat(shmid, NULL, 0);//ponteiro para a área
  
 if ( (shmid = shmget(key,size,0)) == -1 ) {
      perror ("Erro shmget()") ; 
      exit(1) ; 
      }
  
  //---------------------------------------------------------------------------------
  //BLOCO DE OPERAÇÃO DO FORK()
  
	pid_t pid;

  *p = 10; //Ponteiro com memória compartilhada 
  int value = 10; //Variavel sem memoria compartilhada
  
  printf("\nTeste de Memória compartilhada entre processos\n");
  printf("Valor inicial do ponteiro e da variavel: %d\n", *p);
  
	pid = fork();
  
	if (pid == 0) { /* processo filho */
		printf("\nProcesso Filho!\n");
    
		*p += 15;
    value += 15;
    
    printf ("Shared Memory pointer value = %d\n",*p); 
    printf ("Variable value(variable not in shared memory) = %d\n",value); 
		return 0;
	}
	else if (pid > 0) { /* processo pai */
		wait(NULL);
    printf("\nProcesso Pai!\n");
    
    *p *= 5;
    value *= 5;
    
		printf ("Shared Memory pointer value = %d\n",*p); 
    printf ("Variable value(variable not in shared memory) = %d\n",value); 
		return 0;
	}
  
//---------------------------------------------------------------------------------
 if ((shmctl(shmid, IPC_RMID, NULL)) == -1){ perror("Erro shmctl()") ;
    exit(1) ; }
  
 exit(0);
}
//---------------------------------------------------------------------------------
