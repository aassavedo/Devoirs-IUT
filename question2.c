/*2- Ecrire un programme qui crée un processus fils. Le fils affiche le pid de son père. Le père affiche le pid de son fils.
*/
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc , char *argv[])
{
  int pid_t pid ;
  pid_t pid = fork();
  if(pid < 0)
{
   printf( "Erreur dans la création du processus fils\n");
    return 1;
}
  if(pid == 0)
{
    printf("je suis le processus fils  avec pid (%d)\n,  le pid de mon père est (%d)\n", getpid(), getppid());
}
    else if(pid>0)
{
    printf("Je suis le processus  père (%d), le pid de  mon fils est (%d)",getpid());
}

  return 0;
}

