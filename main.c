#include <stdio.h>
#include <stdlib.h>

void Parser(int size, int start, char * buff);

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

    Parser(n,start , buff);
    return 0;
}

void Parser(int size, int startp, char *buff)
{
    int i = 0;
    int j = 0;
    int cnt = 0;
    int objNested = 0;
    int objSize = 0;
    int arraySize = 0;
    int arrayNested = 0;

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

                token.end = i;

                if(buff[i+1] == ':') token.size ++;


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

                            default:
                                break;
                        }
                        i++;
                    }
                    printf("%c",buff[a]);
                }
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



                Parser(token.start + objSize, token.start, nestObj);


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


                }

                for(int a = token.start; a <= token.end; a++)
                {
                    printf("%c",buff[a]);

                }

                printf(" (size : %d ,range : %d ~%d , type : %d) \n", token.size , token.start, token.end, token.type);

                token.size = 0; //

                i = token.start + 1;


                break;

            default: break;


        }
        i++;
    }


}
