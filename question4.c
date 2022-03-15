#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <openssl/md5.h>

#define BUFSIZ
  //*4- Ecrire un programme qui calcule le MD5 d'un fichier passé en paramètre.//
 char *
     MD5File(const char *filename, char *buf);
int main( int argc, char *argv[])
{
  char *md5file;
  char buffer[BUFFER_SIZE];
   BUFFER_SIZE=150;

  md5file=MD5File("file1.txt",buff);
  printf("%s",MD5);

   return 0;
}
