//copyright 2024 Muneem. 
//this code is only meant to be used by those who are allowed to use it and not to be copied. 
#include <bits/pthreadtypes.h>
#include <errno.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <sys/types.h>
#include<unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/shm.h>
      #include <sys/types.h>
       #include <sys/stat.h>
#define MAXIMUM_FUNC 3
struct pipe_struct{
    int pipe2[2];
    char *identifier;
};

struct pipe_struct *pipe_struct_array=NULL;
void init_all(){
    pipe_struct_array = (struct pipe_struct*)malloc(sizeof(struct pipe_struct));

}
int amount_of_pipes=0;
void init_end_all(){
    for (int i =0; i<amount_of_pipes; i++) {
    close(pipe_struct_array[i].pipe2[0]);
    close(pipe_struct_array[i].pipe2[1]);

    }
}
void run_program_init(char ***arguments,int *number_of_arguments, int COMMAND_NUMBER  ){
    //empty block because no code is needed in this option
}
void recieve_pipe_init(char ***arguments,int *number_of_arguments, int COMMAND_NUMBER ){
    
    }
void store_pipe_init(char ***arguments,int *number_of_arguments , int COMMAND_NUMBER ){
pipe_struct_array[amount_of_pipes].identifier=arguments[COMMAND_NUMBER][0];
if(pipe(pipe_struct_array[amount_of_pipes].pipe2)==-1){
fprintf(stderr, "\n making pipe failed\n");
}
    amount_of_pipes++;
    pipe_struct_array = (struct pipe_struct*)realloc(pipe_struct_array, amount_of_pipes*sizeof(struct pipe_struct));
    }
    void (*functions_init[MAXIMUM_FUNC])(char ***, int *,int)={&run_program_init, &store_pipe_init, &recieve_pipe_init};

#define take_input(input,  sizeof_input){\
         memset((void*)input, 0, sizeof_input);\
\
   for(int i=0,j=0, c=0;; i++){\
    if(i ==sizeof_input-1){\
        input[i]= '\0';\
        break;\
    }\
    input[i]=getchar();\
    if(input[i]=='\n'){\
        if(j||c){\
        \
        }\
        else{\
            break;\
        }\
    }\
\
   \
    if(input[i]=='\''){\
         if(j==1){\
            j=0;\
        \
    }\
         else{\
            if(c==0){\
            j=1;\
            }\
        }\
    }\
    if(input[i]=='\"'){\
         if(c==1){\
            c=0;\
        \
    }\
         else{\
            if(j==0){\
            c=1;\
            }\
        }\
    }\
\
   }\
    }

void Run_progam(int command_NUMBER,char ***strings_to_use, int *number_of_strings,char ***strings_to_use2, int *number_of_strings2){
    char *argv[number_of_strings[command_NUMBER]+1];
    for(int i=0; i<number_of_strings[command_NUMBER]; i++){
        argv[i]= strings_to_use[command_NUMBER][i];
    }
    argv[(number_of_strings[command_NUMBER])]=NULL;
    execvp(argv[0], argv+1);
    }



#define pipe_name strings_to_use2[command_NUMBER]

void pipe_reciever(int command_NUMBER,char ***strings_to_use, int *number_of_strings,char ***strings_to_use2, int *number_of_strings2){
 int j =-1;
for(int i =0; i<amount_of_pipes;i++){
if(!strcmp(pipe_name[1], pipe_struct_array[i].identifier)){
    fprintf(stderr, "\n name is %s\n on reciever", pipe_name[1]);
    j=i;
    break;
}

}
if(j==-1){
fprintf(stderr, "\npipe not found\n");
}
else{
    fprintf(stderr, "\nloop done\n");


  if(dup2(pipe_struct_array[j].pipe2[0], STDIN_FILENO)==-1){
    fprintf(stderr,"\nerror is %s\n", errno);
 }
close(pipe_struct_array[j].pipe2[1]);
close(pipe_struct_array[j].pipe2[0]);
}
    }

void pipe_store(int command_NUMBER,char ***strings_to_use, int *number_of_strings,char ***strings_to_use2, int *number_of_strings2){
int j =-1;
for(int i =0; i<amount_of_pipes;i++){
if(!strcmp(pipe_name[0], pipe_struct_array[i].identifier)){
    j=i;
    break;
}

}
if(j==-1){
fprintf(stderr, "\npipe not found\n");
}
else{
        fprintf(stderr, "\nname on storing end is %s\n", pipe_name[0]);

 if(dup2(pipe_struct_array[j].pipe2[1], STDOUT_FILENO)==-1){
    fprintf(stderr, "\npipe joining failed on sending end\n");

 }
 
close(pipe_struct_array[j].pipe2[1]);
close(pipe_struct_array[j].pipe2[0]);
}

}
    void (*functions[MAXIMUM_FUNC])(int, char ***,int *, char ***,int *)={&Run_progam, &pipe_store, &pipe_reciever};

void Run_progam_destroyer(){}
int bool=0;
void pipe_store_destroyer(){
if(bool){
    for (int i =0; i<amount_of_pipes; i++) {
    close(pipe_struct_array[i].pipe2[0]);
    close(pipe_struct_array[i].pipe2[1]);

    }
    fprintf(stderr,"\n am gonna free\n");
    free(pipe_struct_array);
    fprintf(stderr,"\n free\n");
}
else{
bool =1;
}
}
void pipe_reciever_destroyer(){
if(bool){

    for (int i =0; i<amount_of_pipes; i++) {
    close(pipe_struct_array[i].pipe2[0]);
    close(pipe_struct_array[i].pipe2[1]);

    }
    fprintf(stderr,"\n am gonna free\n");
    free(pipe_struct_array);
    fprintf(stderr,"\n free\n");
}
else{
bool =1;
}
}
void(*function_destroyer[MAXIMUM_FUNC])()={&Run_progam_destroyer, &pipe_store_destroyer, &pipe_reciever_destroyer};
  #define cleanmem( strings_to_use,  number_of_strings,  INPUT_DETAILED, number_of_COMMANDS){\
    for(int i=0; i<number_of_COMMANDS;i++){\
                free(INPUT_DETAILED[i]);\
                for(int j=0;j<number_of_strings[i];j++){\
                free(strings_to_use[i][j]);\
\
                }\
                free(strings_to_use[i]);\
               }\
    \
                free(number_of_strings);\
                free(INPUT_DETAILED);\
                free(strings_to_use);\
\
                number_of_strings=NULL;\
                INPUT_DETAILED=NULL;\
                strings_to_use=NULL;\
\
}

#define readall_options(filename,options,  NUMBER_OF_OPTIONS){\
    options=malloc(0);\
    NUMBER_OF_OPTIONS=0;\
    FILE *file_of_options=fopen(filename, "r");\
    char l=0;\
    fseek(file_of_options, 0,SEEK_SET);\
\
   for(int i=0,e=0,j=0, c=0, a=0;; i++, e++){\
\
    l=getc(file_of_options);\
    \
    if(l==EOF){\
        break;\
    }\
\
\
    if(l=='&'&&!(j||c)){\
        \
\
        options = (char**) realloc((void**)options, (NUMBER_OF_OPTIONS+1)*sizeof(char*));\
\
\
        options[NUMBER_OF_OPTIONS]=NULL;\
        options[NUMBER_OF_OPTIONS]=(char*) realloc((void*)options[NUMBER_OF_OPTIONS], (e+1)*sizeof(char));\
       fseek(file_of_options, i-e,SEEK_SET);\
        for(int i2 =0; i2<=e;i2++){\
        options[NUMBER_OF_OPTIONS][i2]= fgetc(file_of_options);\
\
        }\
       \
        \
        \
        options[NUMBER_OF_OPTIONS][e]= '\0';\
        e=-1;\
        NUMBER_OF_OPTIONS++;\
\
    }\
    if(l=='\n'){\
        if(j||c){\
        \
        }\
        else{\
            break;\
        }\
    }\
\
    if(l=='\''){\
         if(j==1){\
            j=0;\
        \
    }\
         else{\
            if(c==0){\
            j=1;\
            }\
        }\
    }\
    if(l=='\"'){\
         if(c==1){\
            c=0;\
        \
    }\
         else{\
            if(j==0){\
            c=1;\
            }\
        }\
    }\
\
   }\
   fclose(file_of_options);\
}

#define format_input(){\
    while(getchar()!=EOF&&getchar()!='\n');\
\}
#define take_input_dyna( input,  size_of_input){\
    input=NULL;\
    input= (char*)malloc(0);\
    *size_of_input=0;\
   for(int i=0,j=0, c=0;; i++){\
    (*size_of_input)++;\
    input= (char*)realloc((void*)input,*size_of_input*sizeof(char) );\
    input[i]=getchar();\
    if(input[i]=='\n'){\
        if(j||c){\
        }\
        else{\
            (*size_of_input)++;\
            input= (char*)realloc((void*)input,*size_of_input*sizeof(char) );\
            input[(*size_of_input)-1]='\0';\
            break;\
        }\
    }\if(input[i]=='\''){\
         if(j==1){\
            j=0;\
        \
    }\
         else{\
            if(c==0){\
            j=1;\
            }\
        }\
    }\
    if(input[i]=='\"'){\
         if(c==1){\
            c=0;\
        \
    }\
         else{\
            if(j==0){\
            c=1;\
            }\
        }\
    }\
\
   }\
    }

#define process_input_into_parts(input,INPUT_DETAILED,  number_of_COMMANDS,  size_of_input){\
    number_of_COMMANDS=0;\
 if(input[0]=='\n'){fprintf(stderr,"\ninput empty please write something in it\n");}\
 else{\
 INPUT_DETAILED=NULL;\
 INPUT_DETAILED =(char**)malloc(0);\
    \
    for(int i=0,j=0, c=0, e=0;; i++, e++){\
    if(size_of_input==i){\
\
        break;\
    }\
        if(i==1000){\
            break;\
        }\
    if(input[i]== '|'&&!(j||c)){\
                number_of_COMMANDS++;\
\
        INPUT_DETAILED = (char**) realloc((void**)INPUT_DETAILED, (number_of_COMMANDS)*sizeof(char*));\
         INPUT_DETAILED[number_of_COMMANDS-1]=NULL;\
\
        INPUT_DETAILED[number_of_COMMANDS-1]= (char*) realloc((void*)INPUT_DETAILED[number_of_COMMANDS-1],(e+1)*sizeof(char));\
\
        memcpy((void*)INPUT_DETAILED[number_of_COMMANDS-1], (void*)(input+(i-e)),(e*sizeof(char)));\
        INPUT_DETAILED[number_of_COMMANDS-1][e]='\0';\
        e=-1;\
\
    }\
    if(input[i]=='\n'&&!(j||c)){\
        \
    }\
\
    if(input[i]=='\''){\
         if(j==1){\
            j=0;\
        \
    }\
         else{\
            if(c==0){\
            j=1;\
            }\
        }\
    }\
    if(input[i]=='\"'){\
         if(c==1){\
            c=0;\
        \
    }\
         else{\
            if(j==0){\
            c=1;\
            }\
        }\
    }\
\
   }}\
}

#define furthur_process_input(strings_to_use,number_of_strings, INPUT_DETAILED,  number_of_COMMANDS){\
    if(number_of_COMMANDS==0){}\
        else{\
    number_of_strings = (int*)malloc(number_of_COMMANDS*sizeof(int));\
    memset(number_of_strings, 0, number_of_COMMANDS*sizeof(int));\
    strings_to_use = (char***)malloc(number_of_COMMANDS*sizeof(char**));\
    for(int i =0; i<number_of_COMMANDS; i++){ \
        strings_to_use[i]=NULL;\
    }\
    \
    for(int COMMAND_NUMBER=0; COMMAND_NUMBER<number_of_COMMANDS;COMMAND_NUMBER++){\
    \
    for(int i=0,j=0, c=0, e=0;; i++, e++){\
        \
        if(INPUT_DETAILED[COMMAND_NUMBER][i]=='\0'){\
            break;\
        }\
    if(INPUT_DETAILED[COMMAND_NUMBER][i]== '&'&&!(j||c)){\
\
        if(INPUT_DETAILED[COMMAND_NUMBER][i+1]== '&'){\
            printf("bro wrong syntax!!!!");\
            exit(1);\
        }\
\
\
\
\
    strings_to_use[COMMAND_NUMBER] = (char**) realloc((void**)strings_to_use[COMMAND_NUMBER], (number_of_strings[COMMAND_NUMBER]+1)*sizeof(char*));\
\
    strings_to_use[COMMAND_NUMBER][number_of_strings[COMMAND_NUMBER]]=NULL;\
\
    strings_to_use[COMMAND_NUMBER][number_of_strings[COMMAND_NUMBER]]= (char*) realloc((void*)strings_to_use[COMMAND_NUMBER][number_of_strings[COMMAND_NUMBER]],(e+1)*sizeof(char));\
\
        memcpy((void*)strings_to_use[COMMAND_NUMBER][number_of_strings[COMMAND_NUMBER]], (void*)(&INPUT_DETAILED[COMMAND_NUMBER][i-e]),((e)*sizeof(char)));\
\
        strings_to_use[COMMAND_NUMBER][number_of_strings[COMMAND_NUMBER]][e]='\0';\
\
        e=-1;\
                number_of_strings[COMMAND_NUMBER]++;\
    }\
    if(INPUT_DETAILED[COMMAND_NUMBER][i]=='\n'&&!(j||c)){\
\
            break;\
        \
    }\
\
    if(INPUT_DETAILED[COMMAND_NUMBER][i]=='\''){\
         if(j==1){\
            j=0;\
        \
    }\
         else{\
            if(c==0){\
            j=1;\
            }\
        }\
    }\
    if(INPUT_DETAILED[COMMAND_NUMBER][i]=='\"'){\
         if(c==1){\
            c=0;\
        \
    }\
         else{\
            if(j==0){\
            c=1;\
            }\
        }\
    }\
\
   }\
    }}\
}
#define runprograms(strings_to_use,options, number_of_strings, INPUT_DETAILED,  number_of_COMMANDS,  NUMBER_OF_OPTIONS){\
if(!(number_of_COMMANDS>0)){\
    }\
else{\
if(fork()==0){\
printf("enter the options:\n");\
char input[100];\
take_input(input, 100);\
char **input_DETAILLLLED=NULL;\
int Command_Numbers=0;\
char ***strings_to_use1=NULL;\
int *number_of_strings1=NULL;\
process_input_into_parts(input, input_DETAILLLLED,Command_Numbers,100);\
furthur_process_input(strings_to_use1, number_of_strings1,input_DETAILLLLED,Command_Numbers);\
free(input_DETAILLLLED);\
char ***strings_to_use2=NULL;\
int *number_of_strings2=NULL;\
int Command_Numbers2=0;\
fprintf(stderr, "enter the arguments for the options YOU chose:\n");\
take_input(input, 100);\
process_input_into_parts(input, input_DETAILLLLED,Command_Numbers2,100);\
furthur_process_input(strings_to_use2, number_of_strings2,input_DETAILLLLED,Command_Numbers2);\
init_all();\
for(int i =0; i<number_of_COMMANDS; i++){\
if(!Command_Numbers){continue;}\
for(int j=0; j<NUMBER_OF_OPTIONS; j++){\
if(j==MAXIMUM_FUNC){\
    break;\
}\
for(int i1=0; i1<number_of_strings1[i]; i1++){\
if(!(strcmp(strings_to_use1[i][i1], options[j]))){\
            functions_init[j](strings_to_use2, number_of_strings2, i);\
}\
}\
}}\
for(int i =0; i<number_of_COMMANDS; i++){\
fprintf(stderr,"\n process about to be created\n");\
if(!Command_Numbers){continue;}\
if(fork()==0){\
fprintf(stderr,"\n process created\n");\
int options_selected[MAXIMUM_FUNC];\
for(int j=0; j<NUMBER_OF_OPTIONS; j++){\
if(j==MAXIMUM_FUNC){\
    break;\
}\
for(int i1=0; i1<number_of_strings1[i]; i1++){\
if(!(strcmp(strings_to_use1[i][i1], options[j]))){\
            options_selected[j]=1;\
}\
}\
}\
for(int i2 =0;i2<MAXIMUM_FUNC; i2++){\
if(options_selected[i2]){\
\
}\
else{\
function_destroyer[i2]();\
}\
}\
for(int j=0; j<NUMBER_OF_OPTIONS; j++){\
if(j==MAXIMUM_FUNC){\
    break;\
}\
for(int i1=0; i1<number_of_strings1[i]; i1++){\
if(!(strcmp(strings_to_use1[i][i1], options[j]))){\
            functions[j](i,strings_to_use, number_of_strings,strings_to_use2, number_of_strings2);\
}\
}\
}return 0;}}\
    for(int ii=0;ii<number_of_COMMANDS; ii++){\
    init_end_all();\
    wait(NULL);}   return 0;}\
else{wait(NULL);}}}

int main(){    
    char **INPUT_DETAILED=NULL;
    char ***strings_to_use=NULL;
    int *number_of_strings=NULL;
    int number_of_COMMANDS=0;
    char **options=NULL;
    int NUMBER_OF_OPTIONS=0;
char input[1000];
readall_options("file_of_modes", options, NUMBER_OF_OPTIONS);

while (1==1){

    printf("\nenter ur command:$  ");
    take_input(input, 1000);

    process_input_into_parts(input,INPUT_DETAILED, number_of_COMMANDS, 1000);
 
    furthur_process_input(strings_to_use, number_of_strings,INPUT_DETAILED,number_of_COMMANDS);
    if(!(strcmp(input, "QTE\n"))){
           cleanmem(strings_to_use, number_of_strings, INPUT_DETAILED, number_of_COMMANDS);
               for (int i=0; i<NUMBER_OF_OPTIONS; i++) {
               free(options[i]);
               }
               free(options);
               return 0;
    }
    else{
    runprograms(strings_to_use,options, number_of_strings, INPUT_DETAILED,  number_of_COMMANDS,  NUMBER_OF_OPTIONS);
   
    cleanmem(strings_to_use, number_of_strings, INPUT_DETAILED, number_of_COMMANDS);

    }
}

return 0;

}
