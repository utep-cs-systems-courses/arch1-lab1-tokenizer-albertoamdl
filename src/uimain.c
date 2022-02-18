#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main()
{
  char input[100];
  List *ls = init_history();
  char **tokens;
  int translator;

  while(1){

    printf("Input a string to tokenize it or a number in the format !<num> for specified history, !h for full history , !q to quit\n");

    putchar('$');
    fgets(input, 100, stdin);
    tokens = tokenize(input);

    if(**tokens == '!') {
      if(*(*tokens+1) == 'q') {
	break;
      }

      else if(*(*tokens+1) == 'h') {
	printf("printing history\n");
	print_history(ls);

      }

      else {
	translator = atoi(input+1);
	printf("History at %d is: %s\n", translator, get_history(ls, translator));
      }
    }

    else {
      add_history(ls, input);
      printf("---printing tokens----\n");
      print_tokens(tokens);
    }


    printf("Input was: %s\n", input);
    free(tokens);
  }
  //free_tokens(tokens);
  free_history(ls);
  return 0;
}
