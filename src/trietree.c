#include "trietree.h"
#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <string.h>
#include <stdlib.h>

char *convertToLowerCase(char *name)
{
  int i = 0;
  char *buffer;
  buffer = (char*)malloc(strlen(name)+1);
  strcpy(buffer,name); 
  printf("%s\n",buffer);
  while(buffer[i] != '\0')
  {
    buffer[i] = tolower(buffer[i]);
    ++i;
  }
  printf("%s",buffer);
  return buffer;
  free(buffer);
}

void buildDictionary(Trie **tree, char *name, char *definition) // MAIN 
{
  convertToLowerCase(name);
  
}

char *searchDictionary(Trie *tree, char *name)
{
  
}

//Trie *root = NULL;