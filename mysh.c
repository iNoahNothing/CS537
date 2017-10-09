#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// char* exit = 'exit';

void parseInput(char* in) {
   int len = strlen(in);

   if (in[len - 1] == '\n')
      in[len - 1] = '\0';

   char* i = in;
   char* j = in;

   while (*j != 0) {
      *i = *j++;
      if (*i != ' ')
         i++;
   }

   *i = 0;


}


int main() {
   int cmdNum = 1;

   while (1) {
      char command[128];

      printf("mysh (%d) > ", cmdNum);

      char* input = fgets(command, sizeof(command), stdin);
      if (NULL != input) {
         parseInput(command);
         printf("%s\n", command);
         if (strcmp("exit", command) == 0) {
            exit(1);
         }
      }

      cmdNum++;
   }

}
