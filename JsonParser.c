//
//  main.c
//  JsonParser
//
//  Created by 지은신 on 17/05/2019.
//  Copyright © 2019 지은신. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    UNDEFINED = 0,
    OBJECT = 1,
    ARRAY = 2,
    STRING = 3,
    PRIMITIVE = 4
} type_t;

typedef struct {
    type_t type; // Token type
    int start; // Token start position
    int end; // Token end position
    int size; // Number of child (nested) tokens
} tok_t;

int main(int argc, char* argv[]) {
    
    
    // 옵션 지정하지 않았을 때 에러 출력하고 종료
    if (argc == 1) {
        fputs("No Input\n", stderr);
        exit(1);
    }
    
    
    // 옵션 개수 출력
    printf("%d 개의 argv\n\n", argc - 1);
    
    
    // 옵션 배열의 요소들을 하나씩 출력
    for (int i = 1; i < argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
  
    
    FILE * fp = fopen(argv[1], "r");
    //char buff[1024];
    char d;
    int n = 0;

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
 
   printf("The File name is = \"%s\" \n\n", argv[1]);
   
   while((d = fgetc(fp)) != EOF){
      //buff[n] = d;
      n++;
     // printf("%c", d);
    }

   rewind(fp);

   char *buff = (char*) malloc(n*sizeof(char);
   
   int i=0;
   
   while((d = fgetc(fp)) != EOF){
   buff[i] = d;
   i++;
   }

   return 0;
}
