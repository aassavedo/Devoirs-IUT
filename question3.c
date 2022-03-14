/*3- Reprendre la question 2 de manière à ce que le père envoie un nombre secret au processus fils.
 (Vous pouvez utiliser les pipes) */

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
     int fd[2], ret;
     pid_t pid;
   ret = pipe(fd);
  if(ret < 0)
{

    fprintf(stderr, "Erreur de création du pipe (%d)\n", errno);
    return 1;
}
 int pid;
 pid = fork(); /* demande de création du processus fils*/
  if(pid < 0)
{
    fprintf(stderr, "Erreur de création du fils(%d)\n", errno);
    return 1;
}
  if(pid == 0)
{
    /* Nous sommes dans le fils*/
    char buff[BUFSIZ +1];
    close(fd[1]); /*  Fermeture de  l'extrémité d'écriture */

    while(read(fd[0], buff, BUFSIZ) !=0))
    printf("Fils(%s)\n", buff);
    close(fd[0]);
}
else
{
  //*Nous sommes dans le père*/


      char buff[BUFSIZ +1];
      close(fd[0]);//* Fermeture de l'extremité de lecture*//
      strcpy(buff,"saisir le nobre secret\n");
      write(fd[1],buff,strlen(buff) +1);;
      close(fd[1]);


}
