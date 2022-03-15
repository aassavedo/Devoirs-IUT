#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <md5.h>

//** Reprendre la question 1) et ajouter la possibilité de vérifier que la copie s'est
 /*bien passée en exploitant le code de la question 4).*//
int main(int argc, char *argv[])
{
  if(argc!=3){
    fprintf(stderr,"Suntaxe: %s fichier_source fichier_destination\n",argv[0]);
    return 1;
  }
  FILE *fp1, *fp2;

  int retour;
  fp1=fopen(argv[1],"r");
  if(fp1==NULL)
{
    printf("Problème lors de l'ouverture %s\n",argv[1]);
    exit(1);
}
  fp2=fopen(argv[2],"w");
  if(fp2==NULL)
{
    fclose(fp1);
    printf("Problème lors de  d'ouverture %s\n",argv[2]);
    exit(2);
  }
  else
{
    char buffer[150];
     char *md5file1, *md5file2;
    md5file1=MD5File(argv[1],buffer);
    printf("%s\n",md5file1);
   char ch;

while(ch= getc (fp1) !=EOF)
{
     putc(ch,fp2);
}


    md5file2= MD5File(argv[2],buffer);
    printf("%s\n",md5file2);
  }
  fclose(fp1);
  fclose(fp2);
  getch();
  return 0;
}

