/*copyright 2024 Muneem. 
u can use it if u want but cant copy it.
*/
#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>
#include <string.h>
#include <sys/types.h>
#include<unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/shm.h>
      #include <sys/types.h>
       #include <sys/stat.h>
#include<errno.h>
#define MAXIMUM_FUNC 5
struct pipe_struct{
    int pipe2[2];
    char *identifier;
};

#define process_input_into_parts(input,INPUT_DETAILED,  number_of_COMMANDS,  size_of_input,token){\
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
    if(input[i]== token&&!(j||c)){\
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

#define furthur_process_input(strings_to_use,number_of_strings, INPUT_DETAILED,  number_of_COMMANDS, tocken){\
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
    if(INPUT_DETAILED[COMMAND_NUMBER][i]== tocken&&!(j||c)){\
\
        if(INPUT_DETAILED[COMMAND_NUMBER][i+1]== tocken){\
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
int BOOL_INPUT=0;
int BOOL_OUTPUT=0;
char ***OUTPUT_DATA=NULL;
int **INPUT_DATA=NULL;
int *position_of_each_command_input=NULL;
int *position_of_each_command_output=NULL;

int *OUTPUT_STRINGS_ON_SPECIFIC_COMMAND_NUMBER=NULL;
int *INPUT_STRINGS_ON_SPECIFIC_COMMAND_NUMBER=NULL;
#define OSOSCN OUTPUT_STRINGS_ON_SPECIFIC_COMMAND_NUMBER
#define ISOSCN INPUT_STRINGS_ON_SPECIFIC_COMMAND_NUMBER
int Amount_of_input_data=0;
void take_input_init(char ***arguments,int *number_of_arguments, int COMMAND_NUMBER ){
if(!BOOL_INPUT){
INPUT_DATA=malloc(COMMAND_NUMBER*sizeof(int*));
ISOSCN=malloc(COMMAND_NUMBER*sizeof(int));
position_of_each_command_input=malloc(COMMAND_NUMBER*sizeof(int*));

BOOL_INPUT=1;
}
char **string_to_be_used_before_int_conversion;
process_input_into_parts(arguments[COMMAND_NUMBER][2], string_to_be_used_before_int_conversion, ISOSCN[Amount_of_input_data], strlen(arguments[COMMAND_NUMBER][2])+1, '*');
INPUT_DATA[Amount_of_input_data]=malloc(ISOSCN[Amount_of_input_data]*sizeof(int));
position_of_each_command_input[Amount_of_input_data]= COMMAND_NUMBER;
for(int j=0; j<ISOSCN[Amount_of_input_data];j++){
    INPUT_DATA[COMMAND_NUMBER][j]=atoi(string_to_be_used_before_int_conversion[j]);
}
Amount_of_input_data++;

    }
     int amount_of_print_data=0;
void print_stuff_init(char ***arguments,int *number_of_arguments, int COMMAND_NUMBER ){
if(!BOOL_OUTPUT){
OUTPUT_DATA=malloc(COMMAND_NUMBER*sizeof(char**));
OSOSCN=malloc(COMMAND_NUMBER*sizeof(int));
position_of_each_command_output=malloc(COMMAND_NUMBER*sizeof(int*));

BOOL_OUTPUT=1;
}
 int amount_of_print_data;
position_of_each_command_output[amount_of_print_data]= COMMAND_NUMBER;

process_input_into_parts(arguments[COMMAND_NUMBER][3], OUTPUT_DATA[amount_of_print_data], OSOSCN[amount_of_print_data], strlen(arguments[COMMAND_NUMBER][3])+1, '*');
amount_of_print_data++;

    }
void store_pipe_init(char ***arguments,int *number_of_arguments , int COMMAND_NUMBER ){
pipe_struct_array[amount_of_pipes].identifier=arguments[COMMAND_NUMBER][0];
if(pipe(pipe_struct_array[amount_of_pipes].pipe2)==-1){
fprintf(stderr, "\n making pipe failed\n");
}
    amount_of_pipes++;
    pipe_struct_array = (struct pipe_struct*)realloc(pipe_struct_array, amount_of_pipes*sizeof(struct pipe_struct));
    }
    void (*functions_init[MAXIMUM_FUNC])(char ***, int *,int)={&run_program_init, &store_pipe_init, &recieve_pipe_init, &take_input_init, &print_stuff_init};


void Run_progam(int command_NUMBER,char ***strings_to_use, int *number_of_strings,char ***strings_to_use2, int *number_of_strings2){
    char *argv[number_of_strings[command_NUMBER]+1];
    for(int i=0; i<number_of_strings[command_NUMBER]; i++){
        argv[i]= strings_to_use[command_NUMBER][i];
    }
    argv[(number_of_strings[command_NUMBER])]=NULL;
    execvp(argv[0], argv+1);
    }

void TAKE_INPUT(int command_NUMBER,char ***strings_to_use, int *number_of_strings,char ***strings_to_use2, int *number_of_strings2){
static int POSITION_OF_DATA_IN_DATA_POOL;
if(!BOOL_INPUT){
for(int i=0; i<Amount_of_input_data;i++){
    if(position_of_each_command_input[i]==command_NUMBER){
        POSITION_OF_DATA_IN_DATA_POOL=i;
    }
}
}
}
int i=0;
int BOOL_FOR_PRINT=0;
#define PODIDP POSITION_OF_DATA_IN_DATA_POOL
void PRINT_OUTPUT(int command_NUMBER,char ***strings_to_use, int *number_of_strings,char ***strings_to_use2, int *number_of_strings2){
static int POSITION_OF_DATA_IN_DATA_POOL;
if(!BOOL_FOR_PRINT){
for(int i=0; i<amount_of_print_data;i++){
    if(position_of_each_command_output[i]==command_NUMBER){
        POSITION_OF_DATA_IN_DATA_POOL=i;
    }
}
}
}

void pipe_reciever(int command_NUMBER,char ***strings_to_use, int *number_of_strings,char ***strings_to_use2, int *number_of_strings2){
int i =0;
for(;i<amount_of_pipes;i++){
if(!strcmp(strings_to_use2[command_NUMBER][1], pipe_struct_array[i].identifier)){
    
if(dup2(pipe_struct_array[i].pipe2[0], STDIN_FILENO)==-1){
    fprintf(stderr,"\n error while recieving, error is %s", errno);
 }
close(pipe_struct_array[i].pipe2[0]);
 
close(pipe_struct_array[i].pipe2[1]);

    break;
}

}
if(i==amount_of_pipes){
fprintf(stderr, "\npipe not found\n");
}

    }

void pipe_store(int command_NUMBER,char ***strings_to_use, int *number_of_strings,char ***strings_to_use2, int *number_of_strings2){
int i =0;
for(;i<amount_of_pipes;i++){
if(!strcmp(strings_to_use2[command_NUMBER][0],
 pipe_struct_array[i].identifier)){
    
    if(dup2(pipe_struct_array[i].pipe2[1], STDOUT_FILENO)==-1){
    fprintf(stderr, "\npipe joining failed on sending end\n");

 }

close(pipe_struct_array[i].pipe2[0]);
 
close(pipe_struct_array[i].pipe2[1]);

    break;
}

}
if(i==amount_of_pipes){
fprintf(stderr, "\npipe not found\n");
}

}

    void (*functions[MAXIMUM_FUNC])(int, char ***,int *, char ***,int *)={&Run_progam, &pipe_store, &pipe_reciever, &TAKE_INPUT, &PRINT_OUTPUT};
void TAKE_INPUT_destroyer(){}
void PRINT_OUTPUT_destroyer(){}

void Run_progam_destroyer(){}
int bool=0;
void pipe_store_destroyer(){
if(bool){
    for (int i =0; i<amount_of_pipes; i++) {
    close(pipe_struct_array[i].pipe2[0]);
    close(pipe_struct_array[i].pipe2[1]);

    }
    free(pipe_struct_array);
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
    free(pipe_struct_array);
}
else{
bool =1;
}
}
void(*function_destroyer[MAXIMUM_FUNC])()={&Run_progam_destroyer, &pipe_store_destroyer, &pipe_reciever_destroyer, &TAKE_INPUT_destroyer, &PRINT_OUTPUT_destroyer};
  #define OPTIONAL_cleanmem( strings_to_use,  number_of_strings,  INPUT_DETAILED, number_of_COMMANDS){\
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


#define runprograms(strings_to_use,options, \
number_of_strings, INPUT_DETAILED,\
number_of_COMMANDS,  NUMBER_OF_OPTIONS){\
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
process_input_into_parts(input, input_DETAILLLLED,Command_Numbers,100,'|');\
furthur_process_input(strings_to_use1, number_of_strings1,input_DETAILLLLED,Command_Numbers, '&');\
free(input_DETAILLLLED);\
char ***strings_to_use2=NULL;\
int *number_of_strings2=NULL;\
int Command_Numbers2=0;\
fprintf(stderr, "enter the arguments for the options YOU chose:\n");\
take_input(input, 100);\
process_input_into_parts(input, input_DETAILLLLED,Command_Numbers2,100,'|');\
furthur_process_input(strings_to_use2, number_of_strings2,input_DETAILLLLED,Command_Numbers2, '&');\
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
if(!Command_Numbers){continue;}\
if(fork()==0){\
int options_selected[MAXIMUM_FUNC];\
memset(options_selected, 1, MAXIMUM_FUNC*sizeof(int));\
for(int j=0; j<NUMBER_OF_OPTIONS; j++){\
if(j==MAXIMUM_FUNC){\
    break;\
}\
for(int i1=0; i1<number_of_strings1[i]; i1++){\
if(!(strcmp(strings_to_use1[i][i1], options[j]))){\
            options_selected[j]=0;\
}\
}\
}\
for(int i2 =0;i2<MAXIMUM_FUNC; i2++){\
if(!options_selected[i2]){\
\
}\
else{\
function_destroyer[i2]();\
}\
}\
for(int j=0; j<number_of_strings1[i]; j++){\
for(int i1=0; i1<NUMBER_OF_OPTIONS; i1++){\
if(i1==MAXIMUM_FUNC){\
    break;\
}\
if(!(strcmp(strings_to_use1[i][j], options[i1]))){\
            functions[i1](i,strings_to_use, number_of_strings,strings_to_use2, number_of_strings2);\
}\
}\
}return 0;}}init_end_all();for\
(int i=0; i<number_of_COMMANDS; i++){wait(NULL);}\
return 0;}wait(NULL);}}
#define optional_manual_cleanup_for_main() {\
  cleanmem(strings_to_use, number_of_strings, INPUT_DETAILED, number_of_COMMANDS);\
               for (int i=0; i<NUMBER_OF_OPTIONS; i++) {\
               free(options[i]);\
               }\
               free(options);\
}
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
if(!(strcmp(input, "QTE\n"))){
         
               return 0;
    }
else{
    process_input_into_parts(input,INPUT_DETAILED, number_of_COMMANDS, 1000,'|');
 
    furthur_process_input(strings_to_use, number_of_strings,INPUT_DETAILED,number_of_COMMANDS, '&');
   

    runprograms(strings_to_use,options, number_of_strings, INPUT_DETAILED,  number_of_COMMANDS,  NUMBER_OF_OPTIONS);
   
    OPTIONAL_cleanmem(strings_to_use, number_of_strings, INPUT_DETAILED, number_of_COMMANDS);
/*clean mem in this case wasent optional*/
    }
}

return 0;

}
