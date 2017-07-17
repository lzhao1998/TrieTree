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
  printf("before: %s\n",buffer);
  while(buffer[i] != '\0')
  {
    buffer[i] = tolower(buffer[i]);
    ++i;
  }
  printf("after:%s\n\n",buffer);
  return buffer;
  free(buffer);
}

void createTrie(Trie **root)
{
  *root = createBranch('\0','\0');
}

Trie *createBranch(char* name, char* definition)
{
  Trie *branch = NULL; //start create the trie and all value is NULL
  branch = (Trie*)malloc(sizeof(Trie)); //let branch hv same size as trie
  branch->name = name;
  branch->definition = definition;
  branch->next = NULL;
  branch->previous = NULL; //next and pervious is for left and right
  branch->parent = NULL;
  branch->child = NULL;   //parent and child is for up and down
  return branch;
  
  /*        parent(prev) ---------parent(next)  
              |                     |       |
           child             child(prev) child(next)
               
    assign all NULL because havent insert any word yet.
  */
} 

void buildDictionary(Trie **root, char *name, char *definition) // MAIN 
{
  int i = 0;
  char *result;
  result = convertToLowerCase(name);
  printf("\noutput for lowercase: %s\n",result);
  Trie *word = NULL;
  
  if(*root == NULL) //if no insert any word
  {
    printf("Dictionary has no word\n");
    return;
  }
  
  /*if got word, insert the word to child then it will become
           root(parent)
               |
           word(child)
  */
    printf("insert word:%s\n", result);
    word = (*root)->child;
    
  //for the 1st node
  if(word == NULL)
  {
    word = createBranch(result,'\0');
    word->child = createBranch('\0',definition);
    word->child->parent = word;
    printf("Inserting 1st node: %s\n",word->name);
    printf("Definition is:%s\n", word->child->definition);
    return;
  }
  
  //for 2nd or more node
  while(*result != '\0')
  {
    if(*result == (word->name))
    {
      printf("\n",result);
      result++;
    }
    word->definition = NULL;
    char *buffer1 = (char*)malloc(strlen(word->name)-i);
    strcpy(buffer1,(word->name)+i);
    word->child = createBranch(buffer1,definition);
    
    word = word->child;   //now is in child of the parent
    char *buffer2 = (char*)malloc(strlen(result)-i);
    strcpy(buffer2,result+i);
    word->next = createBranch(buffer2,definition);
    word->next->parent = word->parent;
    word->next->previous = word;
  }
  
  printf("%s is neighbour of %s\n",word->next->name,word->name);
}


char *searchDictionary(Trie *tree, char *name)
{
  
}

//Trie *root = NULL;