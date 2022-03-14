/*1- Ecrire un programme qui copie le contenue d'un fichier donné en paramètre vers un autre fichier passé en paramètre
    ./prog1 fichier_source fichier_destination*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
  int fd1, fd2, rc;
  char buf;
  if(argc != 3)
{
  fprintf(stderr, "Syntaxe: %s f1 f2\n", argv[0]);
  exit(1);
}
    fd1 = open(argv[1], O_RDONLY);
  if(fd1 < 0)
{
  perror("open(fd1)");
  exit(1);
}
 fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
 if(fd2 < 0)
{
 perror("open(fd2)");
 exit(1);
}
 while(1)
{
  rc = read(fd1, &buf, 1);
if(rc < 0)
{
  perror("read");
  exit(1);
}
 if(rc == 0)
 break;
 rc = write(fd2, &buf, 1);
 if(rc < 0)
{
   perror("write");
   exit(1);
}
  if(rc != 1)
{
  fprintf(stderr, "Écriture interrompue");
  exit(1);
}
}
  close(fd1);
  close(fd2);
return 0;
}
