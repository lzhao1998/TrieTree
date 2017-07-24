#include "trietree.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "CException.h"
#include "Exception.h"

#define ERROR_TO_CREATE_SUBSTRING 1

char *convertToLowerCase(char *name) //convert all words in lowercase
{
  int i = 0;
  char *buffer;
  buffer = (char*)malloc(strlen(name)+1);
  strcpy(buffer,name); 
  //printf("before: %s\n",buffer);
  while(buffer[i] != '\0')
  {
    buffer[i] = tolower(buffer[i]);
    ++i;
  }
  //printf("after:%s\n\n",buffer);
  return buffer;
  free(buffer);
}

int findFirstIndexOfNoneSameChar(char* str1, char* str2)
{
  int i = 0;
  //printf("str1: %s\n",str1);
  //printf("str2: %s\n",str2);

  while(str1[i] == str2[i])
  {
    i++;
  }
    return i-1;
}

char *createSubString(char *strName,int startIndex, int length)
{
  CEXCEPTION_T ex;
  char* buffer;
  //printf("input subString:%s \n",strName);
  int j = 0;
  int a = strlen(strName);
  buffer = (char*)malloc(length + 1);
  
  Try
  {
    if(a < startIndex || length == 0)
      Throw(ERROR_TO_CREATE_SUBSTRING);
  }
  Catch(ex)
  {
    //printf("Error!!\n");
    return NULL;
  }
  
  while(j != length+1)
  {
   if(j < length && length != 0)
    {
      buffer[j] = strName[startIndex];
      //printf("Inserting : %c\n",buffer[j]);
      startIndex++;
      j++;
    }
    else
    {
      buffer[j] = NULL;
      j++; 
    }
  }
  return buffer;
  free(buffer);
}

void buildDictionary(Trie **root)
{
  *root = createBranch(NULL,NULL);
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

void addDictionary(Trie **root, char *name, char *definition) // MAIN 
{
  CEXCEPTION_T ex;
  char *nameInLowercase;
  nameInLowercase = convertToLowerCase(name);
  
  /*
  Catch(ex) // for checking spacebar and numeric
  {
    printf("ERROR!! DONT HAVE ANY NUMERIC AND SPACEBAR!!\n");
  }
  */
  
  printf("\noutput for lowercase: %s\n",nameInLowercase);
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
    printf("insert word:%s\n", nameInLowercase);
    word = createBranch(nameInLowercase, definition);
    
  //for the 1st node
  if(word == NULL && (*root)->child == NULL)
  {
    word = (*root)->child;
    printf("Inserting 1st node: %s\n",word->name);
    printf("Inserting 1st node definition: %s\n",word->definition);
    return;
  }
    printf("another node? yes!! \n");
    printf("name : %s\n",word->name);
    printf("def : %s\n", word->definition);
    int i = findFirstIndexOfNoneSameChar((word->name), (*root)->child->name); //PROBLEM HERE
    printf("%d\n",i);
    return;
  //for 2nd or more node
  /*while(*result != '\0')
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
  }*/
  
}


char *searchDictionary(Trie *tree, char *name)
{
  
}

//Trie *root = NULL;