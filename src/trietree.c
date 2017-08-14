#include "trietree.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//convert all words in lowercase
char *convertToLowerCase(char *name) 
{
  //if there is no word/NULL
  if(name == NULL) 
  {
    return NULL;
  }
  int i = 0;
  char *buffer;
  buffer = (char*)malloc(strlen(name)+1);
  strcpy(buffer,name); 
  //convert the word to lowercase 1 by 1
  while(buffer[i] != '\0')
  {
   buffer[i] = tolower(buffer[i]);
    ++i;
  }
    return buffer;
}

// check the is word and not contain any numeric, spacebar and special char
char *checkIsWord(char* name) 
{
  if(name == NULL)
  {
    return NULL;
  }
  int lengthOfString = strlen(name);
	for(int i = 0; i < lengthOfString; i ++)
	{
    if(!isalpha(name[i]))
		{
			return NULL;
		}
	}
  return name;
}

//find the 1st index of none same char for 2 words
int findFirstIndexOfNoneSameChar(char* str1, char* str2) 
{
  int i = 0;
  //when index of str1 and str2 is same, i = i+1 (check next index)
  //if no same return i-1 because i start from 0
  while(str1[i] == str2[i])
  {
    i++;
  }
    return i-1;
}

//create sub string
char *createSubString(char *strName,int startIndex, int length) 
{
  char* buffer;
  int j = 0;
  int a = strlen(strName);
  
  if(a < startIndex || length <= 0 || strName == NULL)
  {
    printf("Error!! ANSWER IS NULL!!\n");
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

//build dictionary
void buildDictionary(TrieNode **root) 
{
  *root = createBranch(NULL,NULL);
}

//create node
TrieNode *createBranch(char* name, char* definition) 
{
  TrieNode *branch = NULL; //start create the trie and all value is NULL
  branch = (TrieNode*)malloc(sizeof(TrieNode)); //let branch hv same size as trie
  branch->name = name;
  branch->definition = definition;
  branch->list.next = NULL;
  branch->list.previous = NULL; //next and pervious is for left and right
  branch->list.child = NULL;   //parent and child is for up and down
  return branch;

  //        parent(prev) ---------parent(next)  
  //            |                     |       |
  //         child             child(prev) child(next)
  //             
  //  assign all NULL because havent insert any word yet.
  
}

//adding word into dictionary
void addDictionary(TrieNode **root, char *name, char *definition) // MAIN
{
  char *nameInLowercase;
  nameInLowercase = convertToLowerCase(name);
  nameInLowercase = checkIsWord(nameInLowercase);
  if(nameInLowercase == NULL)
  {
	  printf("INSERT WORD FAILED!!\n");
	  return;
  }
  TrieNode *word = NULL;
  TrieNode *pWord = NULL;
  TrieNode *curr = NULL;
  word = (TrieNode*)malloc(sizeof(TrieNode));
  pWord = (TrieNode*)malloc(sizeof(TrieNode));
  curr = (TrieNode*)malloc(sizeof(TrieNode));
  
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
  curr = (*root)->list.child;
	int i;
  
  //if the 1st alphabet of the word is not same then check the next one
  //if next is NULL then assign word->name to the next
	if((i = findFirstIndexOfNoneSameChar(word->name, pWord->name)) < 0 && pWord != NULL) 
	{ 
    printf("search next\n");
    pWord = pWord->list.next;
	}
  
  if(pWord == NULL || i < 0)
  {
    printf("put %s into NULL pWord\n",word->name);
    listAdd(&pWord,word->name,word->definition);
    curr->list.next = pWord;
    (*root)->list.child = curr;
    return;
  }
  
  printf("pword name :%s\n",pWord->name);
  //buffer 1 = same word , buffer 2and3 = not same, 2 is 2nd node, 3 is exist in root->child
  //          buffer1
  //          /     \
  //      buffer2   buffer3
  char *buffer1 = NULL ,*buffer2 = NULL,*buffer3 = NULL; 
  buffer1 = createSubString(word->name, 0, i+1);
  buffer2 = createSubString(pWord->name, i+1, strlen(pWord->name)-(i+1));
  buffer3 = createSubString(word->name, i+1, strlen(word->name)-(i+1));
  printf("buffer1 :%s\n",buffer1);
  printf("buffer2 :%s\n",buffer2);
  printf("buffer3 :%s\n",buffer3);
  char *tempDefPWord = pWord->definition;
  char *tempDefWord = word->definition;
  
  /*if(pWord->list.child != NULL)  //PROBLEM!!!
  {
    printf("yo\n");
    int  j = findFirstIndexOfNoneSameChar(buffer2, pWord->list.child->name);
    int  k = findFirstIndexOfNoneSameChar(buffer3, pWord->list.child->name);
    if(j > 0)
    {
      addDictionary(&pWord,buffer2,tempDefPWord);
    }
    if(k > 0)
    {
      addDictionary(&pWord,buffer3,tempDefWord);
    }
    return;
  }*/
  
  if(buffer2 == NULL && buffer3 == NULL)
  {}
  else if(buffer2 != NULL && buffer3 != NULL)
  {
    listFree(&pWord);
    printf("HERE all not null\n");
    listAdd(&pWord,buffer1,NULL);
    printf("pWord name is: %s\n",pWord->name);
    addDictionary(&pWord,buffer2,tempDefPWord);
    addDictionary(&pWord,buffer3,tempDefWord);
  }
  else if(buffer2 == NULL && buffer3 != NULL)
  {
    printf("buff2 NULL\n");
    listFree(&pWord);
    listAdd(&pWord,buffer1,tempDefPWord);
    addDictionary(&pWord,buffer3,tempDefWord);
  }
  else if(buffer2 != NULL && buffer3 == NULL)
  {
    printf("buff3 NULL\n");
    listFree(&pWord);
    listAdd(&pWord,buffer1,tempDefWord);
    addDictionary(&pWord,buffer2,tempDefPWord);
  }
  else
  {
    printf("HERE eles\n");
    listFree(&pWord);
    listAdd(&pWord,buffer1,NULL);
    addDictionary(&pWord,buffer2,tempDefWord);
    addDictionary(&pWord,buffer3,tempDefWord);
  }
    //free(buffer1);free(buffer2);free(buffer3);
    printf("%s      %s\n",pWord->name,pWord->definition);
    (*root)->list.child = pWord;
    //free(pWord);
    return;
}

//straight adding the word into node
void listAdd(TrieNode **root, char *name, char *definition)
{
  TrieNode *word = NULL;
  word = (TrieNode*)malloc(sizeof(TrieNode));
  word = createBranch(name, definition);
  word->name = name;
  word->definition = definition;
  (*root) = word;
  return;
}

//free name and defintion
void listFree(TrieNode **root)
{
  (*root)->name = NULL;
  (*root)->definition = NULL;
	return;
}

//search dictionary
/*char *searchDictionary(TrieNode *root, char *name)
{
	TrieNode *word = NULL;
  word = (TrieNode*)malloc(sizeof(TrieNode));
	word = (*root)->list.child;
	//check word to be search is an actual a word or not
	char *wordSearch = convertToLowerCase(name);
  if(wordSearch == NULL)
  {
	  printf("THIS IS NOT A PROPER WORD!!\n");
	  return NULL;
  }
	int i;
	//check is there any match word in it
  if((i = findFirstIndexOfNoneSameChar(word->name, wordSearch)) < 0 && word != NULL) 
	{ 
    word = word->list.next;
	}
	//return NULL if there is not such word in dictionary
	if(word == NULL) 
	{
		printf("ERROR 404!! WORD NOT FOUND!!\n");
		return NULL;
	}
	//buffer1 and buffer2 is word to be search
	//buffer3 and buffer4 is the word in dictionary
	char *buffer1,*buffer2,*buffer3,*buffer4;
	buffer1 = createSubString(wordSearch, 0, i+1);
	buffer2 = createSubString(wordSearch, i+1, strlen(name)-i);
	buffer3 = createSubString(word->name, 0, i+1);
	buffer4 = createSubString(word->name, i+1, strlen(word->name)-i);
	//if there is not fully match between word in dictionary and word to search
	if(buffer4 != NULL)
	{
		free(buffer1);free(buffer2);free(buffer3);free(buffer4);
		printf("WORD NOT FOUND!!\n");
		return NULL;
	}
	//if there are same
	if(buffer4 == NULL && buffer2 == NULL)
	{
		prinft("WORD FOUND!!! :3 \n");
		printf("Definition : %s \n",word->definition);
		free(buffer1);free(buffer2);free(buffer3);free(buffer4);
		return (word->definition);
	}
	searchDictionary(&word, buffer2);
	free(buffer1);free(buffer2);free(buffer3);free(buffer4);
}*/
