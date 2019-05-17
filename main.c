#include<stdio.h>

typdef enum{
    UNDEFINED = 0,
    OBJECT = 1,
    ARRAY = 2,
    STRING = 3,
    PRIMITIVE = 4,
} type_t;

typdef struct{
    type_t type;
    int start;
    int end;
    int size; 
} tok_t;

void main(char argc, char*argv){

    FILE * fp = fopen(argv[1]);
    char buff[255];
    int n = 0;
    while(fgets(buff, 255, fp) != NULL){
        n++;
    }
    rewind(fp);

    char * data = (char*)malloc(n*sizeof(char));
    int i = 0;
    while(fgets(buff,255,fp) != NULL){
        strcat(data, buff);
        printf("%c", data[i]);
    }



}