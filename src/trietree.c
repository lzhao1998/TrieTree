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
  while(buffer[i] != '\0')
  {
    buffer[i] = tolower(buffer[i]);
    ++i;
  }
  return buffer;
  free(buffer);
}

int findFirstIndexOfNoneSameChar(char* str1, char* str2)
{
  int i = 0;
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
  int j = 0;
  int a = strlen(strName);
  
  Try
  {
    if(a < startIndex || length == 0)
      Throw(ERROR_TO_CREATE_SUBSTRING);
  }
  Catch(ex)
  {
    printf("Error!!\n");
    return NULL;
  }
  
  buffer = (char*)malloc(length + 1);
  while(j != length+1)
  {
   if(j < length && length != 0)
    {
      buffer[j] = strName[startIndex];
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
}

void buildDictionary(TrieNode **root)
{
  *root = createBranch(NULL,NULL);
}

TrieNode *createBranch(char* name, char* definition)
{
  TrieNode *branch = NULL; //start create the trie and all value is NULL
  branch = (TrieNode*)malloc(sizeof(TrieNode)); //let branch hv same size as trie
  branch->name = name;
  branch->definition = definition;
  branch->list->next = NULL;
  branch->list->previous = NULL; //next and pervious is for left and right
  branch->list->child = NULL;   //parent and child is for up and down
  return branch;

  /*        parent(prev) ---------parent(next)  
              |                     |       |
           child             child(prev) child(next)
               
    assign all NULL because havent insert any word yet.
  */
} 

void addDictionary(TrieNode **root, char *name, char *definition) // MAIN 
{
  CEXCEPTION_T ex;
  char *nameInLowercase;
  nameInLowercase = convertToLowerCase(name);
 // printf("\noutput for lowercase: %s\n",nameInLowercase);
  TrieNode *word = NULL;
  TrieNode *pWord = NULL;
  word = (TrieNode*)malloc(sizeof(TrieNode));
  pWord = (TrieNode*)malloc(sizeof(TrieNode));
  
  /*
  Catch(ex) // for checking spacebar and numeric
  {
    printf("ERROR!! DONT HAVE ANY NUMERIC AND SPACEBAR!!\n");
  }
  */
  
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
    printf("......................................\n");
    printf("insert word:%s\n", nameInLowercase);
    word = createBranch(nameInLowercase, definition);
    
  //for the 1st node
  if((*root)->list->child == NULL)
  {
    (*root)->list->child = word;
    printf("Inserting 1st node: %s\n",word->name);
    printf("Inserting 1st node definition: %s\n",word->definition);
    return;
  }
  // more than 1 node
    printf("another node? yes!! \n");
    printf("name : %s\n",word->name);
    printf("def : %s\n", word->definition);
    int i = findFirstIndexOfNoneSameChar(word->name, (*root)->child->name);
    printf("%d\n",i);
    
    
    char *buffer1,*buffer2,*buffer3; //buffer 1 = same word , buffer 2and3 = not same, 2 is 2nd node, 3 is exist in root->child
    buffer1 = createSubString(word->name, 0, i+1);
    buffer2 = createSubString(word->name, i+1, strlen(word->name)-i);
    buffer3 = createSubString((*root)->child->name, i+1, strlen((*root)->child->name)-i);
    printf("buffer1 :%s\n",buffer1);
    printf("buffer2 :%s\n",buffer2);
    printf("buffer3 :%s\n",buffer3);
    
    if(buffer1 == NULL)
    {
      pWord = (*root)->child;
      while(pWord != NULL)
      {
        pWord = pWord->next;
      }
      pWord = createBranch(buffer2, word->definition);
      printf("pWord name:%s\n",pWord->name);
      printf("pWord definiton:%s\n",pWord->definition);
      printf("1st node name and def:%s %s\n",(*root)->child->name,(*root)->child->definition);
      free(buffer1);
      free(buffer2);
      free(buffer3);
    }
    pWord =(*root)->child;
    while(pWord)
    //addDictionary(&(pWord),buffer1,NULL);
    //addDictionary(&(pWord)->child,buffer2,word->definition);
    //addDictionary(&(pWord)->child,buffer3,pWord->definition);
    
    
    return;
}

void listAdd(TrieNode *root, char *name, char *definition, int i)
{
  if(root->name != NULL)
  {
    root = root->next;
  }
  if(name == NULL)
  {
    root->list->next = root;
    root->name = name;
    root->definition = definition;
  }
  else
  {
    if(i == 1)
    {
      root->name = name;
      root->definition = definition;
    }
    else if(i == 2)
    {
      root->list->child = root;
      root->name = name;
      root->definition = definition;
    }
    else
    {
      root->list->child->next = root;
      root->name = name;
      root->definition = definition;
    }
  }
}

char *searchDictionary(TrieNode *tree, char *name)
{
  
}

//Trie *root = NULL;