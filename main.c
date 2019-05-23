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
token.size = 0;

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
    
    Parser(0,n,buff);
    return 0;
}

void Parser(int start, int end, char *buff)
{
    int i = 0;
    int j = 0;
    int cnt = 0;
    
    while(i != end){
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
    
    while(i < end){        
     switch ( buff[i] ) {
	    case '{': 
		   token.start = i + 1;
		   token.type = 1;
		   

		   while((buff[j] != '}')){
	  	    if(buff[j] == ',') token.size += 1;
            if(buff[j] == '{'){
      			cnt = j;
			    while(buff[cnt] != '}') cnt++; // nested object size 			    	    
			    parser(j,cnt,tmp);
            }
            else{
                j++;
            }
           }
           token.end = j; 
           parser(token.start, j, buff); // distinguish element in the Object
		   break;

	    case '[': 
		   token.start = i + 1;
		   token.type = 1;
		   

		   while((buff[j] != ']')){
	  	    if(buff[j] == ',') token.size += 1;
            if(buff[j] == '['){
      			cnt = j;
			    while(buff[cnt] != ']') cnt++; // nested object size 			    	    
			    parser(j,cnt,tmp);
            }
            else{
                j++;
            }
           }
           token.end = j; 
           parser(token.start, j, buff); // distinguish element in the Object
		   break;
		
        case '"':    
            token.start = i + 1;
            token.type = 3;
            
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
		    if(buff[j+1] == ':') token.size = 1;
		    else if(buff[j+1] == ',') token.size = 0;
                
            i = j;
            
            token.end = cnt;
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
                
        default: 
            if(buff[i] == 'T') {
                token.start = i;
                char * tmp = (char*)malloc(sizeof(char)*5);
                int cnt = i;
                for(int temp = 0; cnt < cnt+4; temp++, cnt++) 
                    tmp[temp] = buff[cnt];
                tmp[4] = '\0'; // null 
                if(!strcmp(tmp, 'TRUE')){
                    token.type = 4;
                    token.end = cnt;
                    token.size = 0;
                    i = cnt;
                }
            }
            else if(buff[i] == 'F'){
                token.start = i;
                char * tmp = (char*)malloc(sizeof(char)*6);
                int cnt = i;
                for(int temp = 0; cnt < cnt+5; temp++, cnt++) 
                    tmp[temp] = buff[cnt];
                tmp[5] = '\0'; // null 
                if(!strcmp(tmp, 'FALSE')){
                    token.type = 4;
                    token.end = cnt;
                    token.size = 0;
                    i = cnt;
                }
            }
            break;
     }
     i++;
    }   
}


