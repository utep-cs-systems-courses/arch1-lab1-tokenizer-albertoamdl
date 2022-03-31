#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c == ' ' || c == '\t'){
    return 1;
  }
  else{
    return 0;
  }  
}


int non_space_char(char c)
{
  if(!space_char(c) && c != '\0'){
    return 1;
  }
  else{
    return 0;
  }
}


char *word_start(char *str)
{
  char *dummy = str;

  while((*dummy) != '\0' && space_char(*dummy)) {
    dummy++;
  }

  return dummy;
}

char *word_terminator(char *word)
{
  int i = 0;

  while(non_space_char(*(word+i))) {

    if(space_char(*(word+i)))
      return word+i;

    else
      i++;
  }
  return word+i;
}


int count_words(char *str)
{
  char *dummy = word_start(str);
  int count = 0;

  while ((*dummy) != '\0') {
    if(non_space_char(*dummy)) {
      count++;
    }

    dummy = word_terminator(dummy);
    dummy = word_start(dummy);
  }

  return count;
}


char *copy_str(char *inStr, short len)
{
  char *p = malloc(sizeof(char) * (len + 1));
  char *dummy = inStr;

  for(int i = 0; i<len; i++){
    *(p+i) = *dummy;
    dummy++;
  }

  *(p + len) = '\0';

  return p;
}



char **tokenize(char *str)
{
  int numOfWords = count_words(str);
  char **tokens = (char**)malloc((numOfWords + 1) * sizeof(char *));
  char *start, *end;

  start = word_start(str);

  for(int i = 0; i<numOfWords; i++) {
    end = word_terminator(start);

    if(non_space_char(*start) && start != end - 1)
      tokens[i] = copy_str(start, end - start);

    start = word_start(end);
  }

  tokens[numOfWords] = NULL;
  return tokens;
}



void print_tokens(char **tokens)
{
  char **dummy = tokens;
  int i = 0;
  while (*dummy != NULL) {
    printf("tokens[%d] = %s\n", i++, *(dummy++));
  }
}



void free_tokens(char **tokens)
{
  char **dummy = tokens;

  while (*dummy != NULL) {
    free(*dummy);
    dummy++;
  }

  free(tokens);
}
