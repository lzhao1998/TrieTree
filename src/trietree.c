#include "trietree.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "CException.h"
#include "Exception.h"

#define ERROR_TO_CREATE_SUBSTRING 1
#define ERROR_NOT_WORD 2

CEXCEPTION_T ex;

char *convertToLowerCase(char *name) //convert all words in lowercase
{
  Try
  {
    if(name == NULL)
    {
      Throw(ERROR_NOT_WORD);
    }
    int i = 0;
    char *buffer;
    buffer = (char*)malloc(strlen(name)+1);
    strcpy(buffer,name); 
    while(buffer[i] != '\0')
    {
      buffer[i] = tolower(buffer[i]);
      ++i;
    }
    buffer = checkIsWord(buffer);  //ADDED AFTER TEST THE CODE
    return buffer;}
  Catch(ex)
  {
    return NULL;
  }
}

char *checkIsWord(char* name) // check the is word and not contain any numeric, spacebar and special char
{
	Try
	{ 
    if(name == NULL)
    {
      Throw(ERROR_NOT_WORD);
    }
    int lengthOfString = strlen(name);
		for(int i = 0; i < lengthOfString; i ++)
		{
			if(!isalpha(name[i]))
			{
				Throw(ERROR_NOT_WORD);
			}
		}
	}
	Catch(ex)
	{
		printf("ERROR!! THIS IS  NOT WORD!! \n");
		return NULL;
	}
	return name;
}

int findFirstIndexOfNoneSameChar(char* str1, char* str2) //find the 1st index of none same char for 2 words
{
  int i = 0;
  while(str1[i] == str2[i])
  {
    i++;
  }
    return i-1;
}

char *createSubString(char *strName,int startIndex, int length) //create sub string
{
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

void buildDictionary(TrieNode **root) //build dictionary
{
  *root = createBranch(NULL,NULL);
}

TrieNode *createBranch(char* name, char* definition) //create node
{
  TrieNode *branch = NULL; //start create the trie and all value is NULL
  branch = (TrieNode*)malloc(sizeof(TrieNode)); //let branch hv same size as trie
  branch->name = name;
  branch->definition = definition;
  branch->list.next = NULL;
//  branch->list.previous = NULL; //next and pervious is for left and right
  branch->list.child = NULL;   //parent and child is for up and down
  return branch;

  //        parent(prev) ---------parent(next)  
  //            |                     |       |
  //         child             child(prev) child(next)
  //             
  //  assign all NULL because havent insert any word yet.
  
}

void addDictionary(TrieNode **root, char *name, char *definition) // MAIN
{
  char *nameInLowercase = convertToLowerCase(name);
  if(nameInLowercase == NULL)
  {
	  printf("INSERT WORD FAILED!!\n");
	  return;
  }
  TrieNode *word = NULL;
  TrieNode *pWord = NULL;
  word = (TrieNode*)malloc(sizeof(TrieNode));
  pWord = (TrieNode*)malloc(sizeof(TrieNode));
  
  if(*root == NULL) //if no insert any word
  {
    printf("Dictionary has no word\n");
    return;
  }

  //if got word, insert the word to child then it will become
  //        root(parent)
  //             |
  //         word(child)
  
  printf("......................................\n");
  printf("insert word:%s\n", nameInLowercase);
  word = createBranch(nameInLowercase, definition);
  
  //for the 1st node
  if((*root)->list.child == NULL)
  {
    (*root)->list.child = word;
    printf("Inserting 1st node: %s\n",word->name);
    printf("Inserting 1st node definition: %s\n",word->definition);
    return;
  }
  
	// more than 1 node
	printf("another node? yes!! \n");
	pWord = (*root)->list.child;
	int i;
  
  //if the 1st alphabet of the word is not same then check the next one
  //if next is NULL then assign word->name to the next
	if((i = findFirstIndexOfNoneSameChar(word->name, pWord->name)) < 0 &&pWord != NULL) 
	{ 
    pWord = pWord->list.next;
	}
  
  if(pWord == NULL)
  {
    printf("put %s into NULL pWord\n",word->name);
    listAdd(&pWord,word->name,word->definition);
    return;
  }
  
  printf("pword name :%s\n",pWord->name);
  char *buffer1,*buffer2,*buffer3; //buffer 1 = same word , buffer 2and3 = not same, 2 is 2nd node, 3 is exist in root->child
  buffer1 = createSubString(word->name, 0, i+1);
  buffer2 = createSubString(pWord->name, i+1, strlen(pWord->name)-i);
  buffer3 = createSubString(word->name, i+1, strlen(word->name)-i);
  printf("buffer1 :%s\n",buffer1);
  printf("buffer2 :%s\n",buffer2);
  printf("buffer3 :%s\n",buffer3);
  
  char *tempDefPWord = pWord->definition;
  char *tempDefWord = word->definition;
  if(buffer2 == NULL && buffer3 == NULL)
  { }
  else if(buffer2 != NULL && buffer3 != NULL)
  {
    listAdd(&pWord,pWord->name,NULL);
    addDictionary(&pWord,buffer2,tempDefPWord);
    addDictionary(&pWord,buffer3,tempDefWord);
  }
  else if(buffer2 == NULL && buffer3 != NULL)
  {
    printf("buff2 NULL\n");
    listAdd(&pWord,buffer1,tempDefPWord);
    addDictionary(&(pWord),buffer3,tempDefWord);
  }
  else if(buffer3 == NULL && buffer2 != NULL)
  {
    printf("buff3 NULL\n");
    listAdd(&pWord,buffer1,tempDefWord);
    addDictionary(&(pWord),buffer2,tempDefPWord);
  }
  else
  {
    pWord->name = buffer1;
    pWord->definition = NULL;
    addDictionary(&(pWord),buffer2,tempDefWord);
    addDictionary(&(pWord),buffer3,tempDefWord);
  }
    free(buffer1);
    free(buffer2);
    free(buffer3);
    return;
  
 /* if(buffer1 == NULL)
  {
    addDictionary(&pWord,buffer2,pWord->definition);
    pWord->definition = NULL;
    addDictionary(&pWord,buffer3,word->definition);
    free(buffer1);
    free(buffer2);
    free(buffer3);
    return;
  }
  if(buffer2 == NULL)
  {
    pWord->name = buffer1;
    pWord->definition = tempDefPWord;
    addDictionary(&(pWord),buffer3,tempDefWord);
    printf("buff2 NULL\n");
    free(buffer1);
    free(buffer2);
    free(buffer3);
    return;
  }
  else if(buffer3 == NULL)
  {
    pWord->name = buffer1;
    pWord->definition = tempDefWord;
    addDictionary(&(pWord),buffer2,tempDefPWord);
    free(buffer1);
    free(buffer2);
    free(buffer3);
    printf("buff3 NULL\n");
    return;
  }
  else
  {
    pWord->name = buffer1;
    pWord->definition = NULL;
    addDictionary(&(pWord),buffer2,tempDefWord);
    addDictionary(&(pWord),buffer3,tempDefWord);
    free(buffer1);
    free(buffer2);
    free(buffer3);
    return;
  }*/
}

//////TRY ONLY/////
/*
void buildDictionary(LinkedList **root) //TRY
{
  *root = createBranch(NULL,NULL);
}


LinkedList *createBranch(char* name, char* definition) //TRY
{
  LinkedList *branch = NULL; //start create the trie and all value is NULL
  branch = (LinkedList*)malloc(sizeof(LinkedList)); //let branch hv same size as trie
  branch->node.name = name;
  branch->node.definition = definition;
  branch->next = NULL;
  branch->previous = NULL; //next and pervious is for left and right
  branch->child = NULL;   //parent and child is for up and down
  return branch;
}

void addDictionary(LinkedList **root, char *name, char *definition) // TRY ONLY
{
  char *nameInLowercase = convertToLowerCase(name);
  if(nameInLowercase == NULL)
  {
	  printf("INSERT WORD FAILED!!\n");
	  return;
  }
  TrieNode *word = NULL;
  TrieNode *pWord = NULL;
  word = (LinkedList*)malloc(sizeof(LinkedList));
  pWord = (LinkedList*)malloc(sizeof(LinkedList));
  
  if(*root == NULL) //if no insert any word
  {
    printf("Dictionary has no word\n");
    return;
  }

 
  printf("......................................\n");
  printf("insert word:%s\n", nameInLowercase);
  word = createBranch(nameInLowercase, definition);
  
  //for the 1st node
  if((*root)->child == NULL)
  {
    (*root)->child = word;
    printf("Inserting 1st node: %s\n",word->node.name);
    printf("Inserting 1st node definition: %s\n",word->node.definition);
    return;
  }
  
	// more than 1 node
	printf("another node? yes!! \n");
	pWord = (*root)->child;
	int i;
  
  //if the 1st alphabet of the word is not same then check the next one
  //if next is NULL then assign word->name to the next
	if((i = findFirstIndexOfNoneSameChar(word->node.name, pWord->node.name)) < 0) 
	{ 
		if(pWord != NULL)
		{
      printf("NOT NULL\n");
      pWord = pWord->next;
     // i = findFirstIndexOfNoneSameChar(word->name, pWord->name);
		}
    else
    {
      printf("NULL\n");
      pWord->node.name = word->node.name;
      pWord->node.definition =word->node.definition;
      addDictionary(&pWord,word->node.name,word->node.definition);
      return;
    }
	}
  
  if(pWord == NULL)
  {
    printf("something wong!!\n");
    //pWord->name = word->name;
    //pWord->definition =word->definition;
    return;
  }
  
  printf("pword name :%s\n",pWord->node.name);
  char *buffer1,*buffer2,*buffer3; //buffer 1 = same word , buffer 2and3 = not same, 2 is 2nd node, 3 is exist in root->child
  buffer1 = createSubString(word->node.name, 0, i+1);
  buffer2 = createSubString(pWord->node.name, i+1, strlen(pWord->node.name)-i);
  buffer3 = createSubString(word->node.name, i+1, strlen(word->node.name)-i);
  printf("buffer1 :%s\n",buffer1);
  printf("buffer2 :%s\n",buffer2);
  printf("buffer3 :%s\n",buffer3);
    
  if(buffer1 == NULL)
  {
    addDictionary(&pWord,buffer2,pWord->node.definition);
    pWord->node.definition = NULL;
    addDictionary(&pWord,buffer3,word->node.definition);
    free(buffer1);
    free(buffer2);
    free(buffer3);
    return;
  }
  char *tempDefPWord = pWord->node.definition;
  char *tempDefWord = word->node.definition;
  pWord->node.name = buffer1;
  pWord->node.definition = NULL;
  addDictionary(&(pWord),buffer2,tempDefPWord);
  addDictionary(&(pWord),buffer3,tempDefWord);
  free(buffer1);
  free(buffer2);
  free(buffer3);
  return;
}*/
//////END TRY//////

void listAdd(TrieNode **root, char *name, char *definition, int i)
{
  TrieNode *word = NULL;
  word = (TrieNode*)malloc(sizeof(TrieNode));
  word = createBranch(name, definition);
  word->name = name;
  word->definition = definition;
  return;
}
/*
void listRemove(TrieNode **root)
{
  TrieNode *word = NULL;
  word = (TrieNode*)malloc(sizeof(TrieNode));
  word = root;
  word->name = NULL;
  word->definition = NULL;
}*/

char *searchDictionary(TrieNode *tree, char *name)
{
  
}
