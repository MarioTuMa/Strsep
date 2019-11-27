#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
char ** parse_args( char * line ){

  int counter = 0;
  int currentSize = 0;
  char** parsed_args = malloc(0);
  while(line){
      parsed_args=realloc(parsed_args,8*counter+8);
      parsed_args[counter]=strsep( &line, " " );
      printf("%s\n",parsed_args[counter]);
      counter++;
  }
  parsed_args[counter] = NULL;
  return parsed_args;
}
int main(){
  char line[100] = "ls -a -l";
  char** callParams=parse_args(line);
  printf("made it here \n");
  printf("%s\n", (callParams[0]));
  printf("%s\n", (callParams[1]));
  printf("%s\n", (callParams[2]));
  execvp(callParams[0],callParams);
  return 0;
}
