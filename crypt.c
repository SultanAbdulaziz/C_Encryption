#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void xorcrypt(FILE*,FILE*,const char*,int);
int main(int argc,char *argv[]){
    if(argc != 4){
        printf("Error : enter 3 parameter (infile , outfile , key)");
        return 1;
    }
    FILE* inputfile = fopen(argv[1],"rb");
    FILE* outputfile = fopen(argv[2],"wb");
    if(!inputfile || !outputfile){
        printf("Error opening files.");
        return 1;
    }
    
    int flag = 1; int choice = 0;
    while(flag){
        printf("Choose Encryption/Decryption Algorithm \n 1- XOR Crypt \n 2- xxx");
        scanf("%d",&choice);
        if(choice == 1) xorcrypt(inputfile,outputfile,argv[3],strlen(argv[3]));
    }
    printf("encryption succesful!");
    return 0;
}

void xorcrypt(FILE* in,FILE* out,const char* key,int keylen){
    int byte; int cnt = 0;
    while(1){
        byte = fgetc(in);
        if(byte == EOF) return;
        unsigned char crypt = byte ^ key[cnt++ % keylen];
        fputc(crypt,out);
    }
}