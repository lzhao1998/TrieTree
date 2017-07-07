#include "trietree.h"
#include <stdio.h>
#include <ctype.h>

void strLow(char *text) //let all words become lowercase
{
  while(*text != '\0') //when is not end of the word, keep let the word become lowercase
  {
    *text = tolower(*text);
    ++text;
  }
}

char *convertToLowerCase(char *name)
{
  strLow(name);
  printf("Output = %s\n", name); 
  return name;
}

void buildDictionary(Trie **tree, char *name, char *definition) // MAIN 
{
  convertToLowerCase(name);
}

char *searchDictionary(Trie *tree, char *name)
{
  
}

//Trie *root = NULL;