#include <stdio.h>
#include <openssl/md5.h>

int main()
{
    unsigned char c[MD5_DIGEST_LENGTH];
    char *filename="file.c";
    int i;
    FILE *inFile = fopen (filename, "rb");
    MD5_CTX mdContext=1000;
    int bytes;
    unsigned char data[1024];

    if (inFile == NULL) {
        printf ("%s Problème de l'ouverture de fichiers

.\n", filename);
        return 0;
    }

    MD5_Init (&mdContext);
    while ((bytes = fread (data, 1, 1024, inFile)) != 0)
        MD5_Update (&mdContext, data, bytes);
    MD5_Final (c,&mdContext);
    for(i = 0; i < 1000; i++) printf("%02x", c[i]);
    printf (" %s\n", filename);
    fclose (inFile);
    return 0;
}
