//copyright 2024 Muneem. 
//this code is only meant to be used by those who are allowed to use it and not to be copied. 
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/shm.h>
#define MAXIMUM_FUNC 3
int FD_FOR_BOOL[2];
int INIT_EVERYTHING_ELSE(){
    if (pipe(FD_FOR_BOOL) == -1) {
    fprintf(stderr,"Pipe failed");
    return 1;
}
return 0;
}
int destroy_ALL(){
    //for removing pipes:
    close(FD_FOR_BOOL[0]);
    close(FD_FOR_BOOL[1]);
    return 0;
}
int bool_(){
int pid=0;
read(FD_FOR_BOOL[0], &pid,sizeof(pid));
if(pid !=0){
int pidd=getpid();
if(pidd>pid){
write(FD_FOR_BOOL[1],&pidd, sizeof(pid));
return 1;
}
else{
    write(FD_FOR_BOOL[1],&pidd, sizeof(pid));
    return 0;
}
}
else{
    pid=getpid();
    write(FD_FOR_BOOL[1], &pid,sizeof(pid));
    int pid2=pid;
    while(pid2!=pid){
        read(FD_FOR_BOOL[0], &pid, sizeof(pid));
    }
    if(pid<pid2){
        return 1;
    }
    else{
        return 0;
    }
}


return 0;
}
FILE *FILE_TO_MEDIATE;

void closepip(int command_NUMBER,char ***strings_to_use, int *number_of_strings){
    fclose(FILE_TO_MEDIATE);
}

void PIPE_SHARE(int command_NUMBER,char ***strings_to_use, int *number_of_strings){
printf("\npipe taken\n");
if(bool_()==0){
int UNIQUE=IPC_PRIVATE;
char KEY_[sizeof(UNIQUE)+1];
memcpy(&UNIQUE, KEY_, sizeof(UNIQUE));
KEY_[sizeof(UNIQUE)]='\0';
FILE_TO_MEDIATE= fopen(KEY_, "w+");
dup2(fileno(FILE_TO_MEDIATE), stdout);
}
if(bool_()==1){
    dup2(fileno(FILE_TO_MEDIATE), stdin);

}
}

void Run_progam(int command_NUMBER,char ***strings_to_use, int *number_of_strings){
    char *argv[number_of_strings[command_NUMBER]+1];
    for(int i=0; i<number_of_strings[command_NUMBER]; i++){
        argv[i]= strings_to_use[command_NUMBER][i];
    }
    argv[(number_of_strings[command_NUMBER])]=NULL;
    execvp(argv[0], argv);
    }
    void (*functions[MAXIMUM_FUNC])(int, char ***,int *)={&Run_progam,&PIPE_SHARE, &closepip};

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
    }\  
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

#define process_input_into_parts(input,INPUT_DETAILED,  number_of_COMMANDS,  size_of_input){\
 INPUT_DETAILED=NULL;\
 INPUT_DETAILED =(char**)malloc(0);\
    \
    number_of_COMMANDS=0;\
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

#define furthur_process_input(strings_to_use,number_of_strings, INPUT_DETAILED,  number_of_COMMANDS){\
    number_of_strings = (int*)malloc(number_of_COMMANDS*sizeof(int));\
    memset((void*)number_of_strings, 0, number_of_COMMANDS*sizeof(int));\
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
    }\
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
for(int i =0; i<number_of_COMMANDS; i++){\
if(fork()==0){\
for(int j=0; j<NUMBER_OF_OPTIONS; j++){\
if(j==MAXIMUM_FUNC){\
    break;\
}\
for(int i1=0; i1<number_of_strings1[i]; i1++){\
if(!(strcmp(strings_to_use1[i][i1], options[j]))){\
            functions[j](i,strings_to_use, number_of_strings);\
}\
}\
}\
char path1[10000];\
memset(path1, 0, 10000);\
    getcwd(path1, 0);\
    strcat(path1, "/");\
    strcat(path1, "dumb_return");\
    execlp(path1, NULL);}\ 
    else{wait(NULL);}\
}\
char path1[10000];\
memset(path1, 0, 10000);\
    getcwd(path1, 0);\
    strcat(path1, "/");\
    strcat(path1, "dumb_return");\
    execlp(path1, NULL);\
}\
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