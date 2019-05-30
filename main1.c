#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD

#include <stdbool.h>   // bool, true, false가 정의된 헤더 파일

=======
>>>>>>> 947695c8db11b1bbdbb0f3d857a88222d6722b55


int start = 0;

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
    char *string;
} tok_t;

tok_t token;



#define TOKEN_COUNT 1024

// JSON 구조체
typedef struct JSON {
    tok_t tokenSAVE[TOKEN_COUNT]; // 토큰 배열
}JSON;

int tokenIndex = 0;

void Parser(int size, int start, char * buff, JSON *json);

void freeJSON (JSON *json)
{
    for (int i = 0; i < TOKEN_COUNT; i++)            // 토큰 개수만큼 반복
    {
        if (json->tokenSAVE[i].type == STRING)    // 토큰 종류가 문자열이면
            free(json->tokenSAVE[i].string);
        
    }// 동적 메모리 해제
}

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
<<<<<<< HEAD
=======


>>>>>>> 947695c8db11b1bbdbb0f3d857a88222d6722b55
    int i=0;

    while((d = fgetc(fp)) != EOF){
        buff[i] = d;
        i++;
    }
<<<<<<< HEAD
    
    JSON json = { 0, };    // JSON 구조체 변수 선언 및 초기화
    
    Parser(n,start , buff, &json);
    
    printf("%s\n",json.tokenSAVE[0].string);
    
    freeJSON(&json);
    
=======

    Parser(n,start , buff);
>>>>>>> 947695c8db11b1bbdbb0f3d857a88222d6722b55
    return 0;
}

void Parser(int size, int startp, char *buff, JSON *json)
{
    int i = 0;
    int j = 0;
    int cnt = 0;
    int objNested = 0;
    int objSize = 0;
    int arraySize = 0;
    int arrayNested = 0;
<<<<<<< HEAD
    
    
=======

>>>>>>> 947695c8db11b1bbdbb0f3d857a88222d6722b55
    i = startp;
    //

    if(buff[i] != '{'){
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
                token.start = i+1;
                token.type = STRING;
                //printf("2");
                j = i + 1;
                cnt = i + 1;

                while(buff[j] != '"'){
<<<<<<< HEAD
                    if(buff[j] == '\\'){
                        
                        if(buff[j + 1] == '"'){
                            j += 2;
                            cnt++;
                        }
                        else if(buff[j + 1] == '\\'){
                            j += 2;
                            cnt++;
                        }
                        else if(buff[j + 1] == '/'){
                            j += 2;
                            cnt++;
                        }
                        else if(buff[j + 1] == 'b'){
                            j += 2;
                            cnt++;
                        }
                        else if(buff[j + 1] == 'f'){
                            j += 2;
                            cnt++;
                        }
                        else if(buff[j + 1] == 'n'){
                            j += 2;
                            cnt++;
                        }
                        else if(buff[j + 1] == 'r'){
                            j += 2;
                            cnt++;
                        }
                        else if(buff[j + 1] == 't'){
                            j += 2;
                            cnt++;
                        }
                        else if(buff[j + 1] == 'u'){
                            j += 1;
                            cnt++;
                        }
                        
                    }
                    else { j++; cnt++;}
                }//while string
                
                i = j;
                
=======
                  if(buff[j] == '\\'){

                    if(buff[j + 1] == '"'){
                        j += 2;
                        cnt++;
                    }
                    else if(buff[j + 1] == '\\'){
                        j += 2;
                        cnt++;
                    }
                    else if(buff[j + 1] == '/'){
                        j += 2;
                        cnt++;
                    }
                    else if(buff[j + 1] == 'b'){
                        j += 2;
                        cnt++;
                    }
                    else if(buff[j + 1] == 'f'){
                        j += 2;
                        cnt++;
                    }
                    else if(buff[j + 1] == 'n'){
                        j += 2;
                        cnt++;
                    }
                    else if(buff[j + 1] == 'r'){
                        j += 2;
                        cnt++;
                    }
                    else if(buff[j + 1] == 't'){
                        j += 2;
                        cnt++;
                    }
                    else if(buff[j + 1] == 'u'){
                        j += 1;
                        cnt++;
                    }

                  }
                  else { j++; cnt++;}
                }
                i = j;
                // printf("3");

>>>>>>> 947695c8db11b1bbdbb0f3d857a88222d6722b55
                token.end = i;

                if(buff[i+1] == ':') token.size ++;
<<<<<<< HEAD
                
=======


>>>>>>> 947695c8db11b1bbdbb0f3d857a88222d6722b55
                for(int a = token.start; a < token.end; a++)
                {
                  if(buff[a] == '\\'){
                        a++;

                        switch(buff[a]){
                            case '"':
                                printf("%c", buff[a]);
                                a++;
                                break;
                            case '\\':
                                printf("%c", buff[a]);
                                a++;
                                break;
                            case '/':
                                printf("%c", buff[a]);
                                a++;
                                break;
                            case 'b':
                                printf("\b");
                                a++;
                                break;
                            case 'f':
                                printf("\f");
                                a++;
                                break;
                            case 'n':
                                printf("\n");
                                a++;
                                break;
                            case 'r':
                                printf("\r");
                                a++;
                                break;
                            case 't':
                                printf("\t");
                                a++;
                                break;
                            case 'u':
                                break;
<<<<<<< HEAD
                                
=======

>>>>>>> 947695c8db11b1bbdbb0f3d857a88222d6722b55
                            default:
                                break;
                        }
                        i++;
                    }
                    printf("%c",buff[a]);
                }
                
                
                // 토큰 배열에 문자열 저장
                // 토큰 종류는 문자열
                json->tokenSAVE[tokenIndex].type = STRING;
                // 문자열 길이 + NULL 공간만큼 메모리 할당
                json->tokenSAVE[tokenIndex].string = malloc((token.end-token.start+1) + 1);
                // 할당한 메모리를 0으로 초기화
                memset(json->tokenSAVE[tokenIndex].string, 0, (token.end-token.start+1) + 1);
                
                // 문서에서 문자열을 토큰에 저장
                // 문자열 시작 위치에서 문자열 길이만큼만 복사
                memcpy(json->tokenSAVE[tokenIndex].string, token.start, (token.end-token.start+1));
                
                tokenIndex++; // 토큰 인덱스 증가
                
                
                printf(" : ");
                printf(" (size : %d , range : %d ~%d , type : %d) \n",token.size , token.start, token.end, token.type);

                token.size = 0;
                break;

            case '{':

                token.start = i ;
                token.type = OBJECT;
                j = i;
                while(buff[j] != '}'  ){

                    if(buff[j] ==':' && buff[j-1] == '"' ) token.size ++;
                    if(buff[j] == '{') objNested++;
                    if(buff[j] == '}') objNested--;
                    if(objNested == 0) break;
                    j++;
                }
                token.end = j;
                objSize = (j - i);
                char *nestObj = (char*) malloc(objSize*sizeof(char));

                for(int s = token.start ; s <= token.end; s++){

                    nestObj[s] = buff[i++];


                }

                for(int a = token.start; a<=token.end; a++)
                {
                    printf("%c",buff[a]);

                }

                printf(" (size : %d ,range : %d ~%d , type : %d) \n", token.size , token.start, token.end, token.type);

                token.size = 0;
<<<<<<< HEAD
                
                
                
                Parser(token.start + objSize, token.start, nestObj, json);
                
=======



                Parser(token.start + objSize, token.start, nestObj);


>>>>>>> 947695c8db11b1bbdbb0f3d857a88222d6722b55
                break;

            case  '[' :
                token.size ++;
                token.start = i ;
                token.type = ARRAY;
                j = i;
                while(buff[j] != ']'  ){

                    //if(buff[j] ==':' && buff[j-1] == '"' ) token.size ++;
                    if(buff[j] == '[') arrayNested++;
                    if(buff[j] == ']') arrayNested--;
                    if(arrayNested == 0) break;
                    j++;
                }

                token.end = j;
                arraySize = (j - i);
                char *array = (char*) malloc(arraySize*sizeof(char));

                for(int s = token.start ; s <= token.end; s++){

                    array[s] = buff[i++];

                    if(array[s] == ',' && array[s-1] == '}') token.size++;
                    if(array[s] == ',' && array[s-1] == '"') token.size++;
                    if(array[s] == ',' && array[s-1] == ']') token.size++;
<<<<<<< HEAD
=======


>>>>>>> 947695c8db11b1bbdbb0f3d857a88222d6722b55
                }

                for(int a = token.start; a <= token.end; a++)
                {
                    printf("%c",buff[a]);

                }

                printf(" (size : %d ,range : %d ~%d , type : %d) \n", token.size , token.start, token.end, token.type);

                token.size = 0; //

                i = token.start + 1;


                break;

            default:
<<<<<<< HEAD
                if(buff[i] == 'T') {
                    token.start = i;
                    char * tmp = (char*)malloc(sizeof(char)*5);
                    int cnt = i;
                    int temp;
                    for(temp = 0; cnt < i+4; temp++)
                    {
                        tmp[temp] = buff[cnt];
                        cnt++;
                        //printf("%c",tmp[temp]);
                        
                    }
                    
                    tmp[4] = '\0'; // null
                    if(!strcmp(tmp, "TRUE")){
                        token.type = 4;
                        token.end = cnt;
                        token.size = 0;
                        i = cnt;
                    }
                    for(int a = token.start; a<token.end; a++)
                    {
                        printf("%c",buff[a]);
                        
                    }
                    
                    printf(" (size : %d ,range : %d ~%d , type : %d) \n", token.size , token.start, token.end, token.type);
                }
                else if(buff[i] == 'F'){
                    token.start = i;
                    char * tmp = (char*)malloc(sizeof(char)*6);
                    int cnt = i;
                    int temp;
                    for(temp = 0; cnt < i+5; temp++)
                    {
                        tmp[temp] = buff[cnt];
                        cnt++;
                        //printf("%c",tmp[temp]);
                    }
                    
                    
                    tmp[5] = '\0'; // null
                    if(!strcmp(tmp, "FALSE")){
                        token.type = 4;
                        token.end = cnt;
                        token.size = 0;
                        i = cnt;
                    }
                    for(int a = token.start; a<token.end; a++)
                    {
                        printf("%c",buff[a]);
                        
                    }
                    
                    printf(" (size : %d ,range : %d ~%d , type : %d) \n", token.size , token.start, token.end, token.type);
                }
                
                break;
                
                
        }
        i++;
    }
    
=======
            if(buff[i] == 'T') {
                   token.start = i;
                   char * tmp = (char*)malloc(sizeof(char)*5);
                   int cnt = i;
                   int temp;
                   for(temp = 0; cnt < i+4; temp++)
                   {
                       tmp[temp] = buff[cnt];
                       cnt++;
                       //printf("%c",tmp[temp]);

                   }

                   tmp[4] = '\0'; // null
                   if(!strcmp(tmp, "TRUE")){
                       token.type = 4;
                       token.end = cnt;
                       token.size = 0;
                       i = cnt;
                   }
                   for(int a = token.start; a<token.end; a++)
                   {
                       printf("%c",buff[a]);

                   }

                   printf(" (size : %d ,range : %d ~%d , type : %d) \n", token.size , token.start, token.end, token.type);
               }
               else if(buff[i] == 'F'){
                   token.start = i;
                   char * tmp = (char*)malloc(sizeof(char)*6);
                   int cnt = i;
                   int temp;
                   for(temp = 0; cnt < i+5; temp++)
                   {
                       tmp[temp] = buff[cnt];
                       cnt++;
                       //printf("%c",tmp[temp]);
                   }


                   tmp[5] = '\0'; // null
                   if(!strcmp(tmp, "FALSE")){
                       token.type = 4;
                       token.end = cnt;
                       token.size = 0;
                       i = cnt;
                   }
                   for(int a = token.start; a<token.end; a++)
                   {
                       printf("%c",buff[a]);

                   }

                   printf(" (size : %d ,range : %d ~%d , type : %d) \n", token.size , token.start, token.end, token.type);
               }

            break;


        }
        i++;
    }


>>>>>>> 947695c8db11b1bbdbb0f3d857a88222d6722b55
}


