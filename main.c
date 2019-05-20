//
//  main.c
//  JsonParser
//
//  Created by 지은신 on 17/05/2019.
//  Copyright © 2019 지은신. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void Parser(int size, char * buff);

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

tok_t token;

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
    
    char *buff = (char*) malloc(n*sizeof(char));
    
    int i=0;
    
    while((d = fgetc(fp)) != EOF){
        buff[i] = d;
        i++;
    }
    
    Parser(n,buff);
    return 0;
}

void Parser(int size, char *buff)
{
    int i = 0;
    int j = 0;
    int cnt = 0;
    
    while(i != size){
        //buff[n] = d;
        // n++;
        
        printf("buff[%d] = %c\n", i,buff[i]);
        i++;
        
    }
    
    i=0;
    //
    
    if(buff[0] != '{'){
        printf("in if \n");
        return;
    }
    i++;
    
    //  printf("%d", size);
    
    while(i < size){
        // printf("while\n");
        
        switch ( buff[i] ) {
            case '"':
                // printf("1");
                token.start = i + 1;
                token.type = 3;
                //printf("2");
                j = i + 1;
                cnt = i + 1;
 
                while((buff[j] != '"')){
                    if(buff[j] == '\\'){
                        if(buff[j + 1] == '"'){
                            j += 2;
                            cnt++;
                        }
                    }
                    else{
                        j++;
                        cnt++;
                    }
                }
                
                i = j;
                // printf("3");
                token.end = cnt;
                //                printf("end  = %d\n", i);
                token.size = token.end - token.start + 1;
                
                
                for(int a = token.start; a < token.end; a++)
                {
                    if(buff[a] == '\\'){
                        a += 1;
                        switch(buff[a]){
                            case '"':
                                printf("%c", buff[a]);
                                a++;
                                break;
                                //                           case '\':
                                //                               i++;
                                //                               printf("%c", buff[a]);
                                //                               break;
                                //                           case '/':
                                //                               i++;
                                //                               printf("%c", buff[a]);
                                //                               break;
                                //                           case 'b':
                                //                               i++;
                                //                               printf("%c", buff[a]);
                                //                               break;
                                //                           case 'f':
                                //                               i++;
                                //                               printf("%c", buff[a]);
                                //                               break;
                            case 'n':
                                printf("\n");
                                a++;
                                
                                break;
                                //                           case 'r':
                                //                               i++;
                                //                               printf("%c", buff[a]);
                                //                               break;
                                //                           case 't':
                                //                               i++;
                                //                               printf("%c", buff[a]);
                                //                               break;
                                //                           case 'u':
                                //                               i++;
                                //                               printf("%c", buff[a]);
                                break;
                            default:
                                break;
                        }
                    }
                    printf("%c",buff[a]);
                    
                }
                printf(" : ");
                printf("%d\n",token.type);
                printf("token size = %d\n",token.size);
                printf("start = %d, end =%d \n", token.start, token.end);
                break;
                
            case '{':
                
            default: break;
                
                // case '{' :
                
                //   break;
        }
        i++;
    }
    
    
}


