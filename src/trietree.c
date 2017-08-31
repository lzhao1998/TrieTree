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
  if(str1 == NULL || str2 == NULL)
  {
    i = -1;
    return i;
  }
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
    /*printf("SUBSTRING ERROR!! IT IS NULL!!\n");*/
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
      buffer[j] = 0;
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
void addDictionary(TrieNode **root, char *name, char *definition) // MAIN FUNCTION
{
  char *nameInLowercase;
  nameInLowercase = convertToLowerCase(name);
  nameInLowercase = checkIsWord(nameInLowercase);
  if(nameInLowercase == NULL)
  {
	  return;
  }
	
  if(*root == NULL) //if no insert any word
  {
    printf("Dictionary has no word\n");
    return;
  }

  //if got word, insert the word to child then it will become
  //        root(parent)
  //             |
  //         word(child)

  //for the 1st node
  if((*root)->list.child == NULL)
  {
    //(*root)->list.child = word;
		listAdd(&(*root)->list.child,nameInLowercase,definition);
    return;
  }

	// more than 1 node
  listCheckNext(&(*root)->list.child, nameInLowercase, definition);
  return;
}

//check the list next and curent stage NULL or not
void listCheckNext(TrieNode **root, char *name, char *definition)
{
  TrieNode *word = NULL;
  word = (TrieNode*)malloc(sizeof(TrieNode));
  
  if((*root)->name == NULL)
  {
    if(findFirstIndexOfNoneSameChar(name,(*root)->name) < 0)
    {	
			listAdd(&(*root),name,definition);
      return;
    }
		else
		{
		  listCreateSubString(&(*root),name,definition);
		  return;
		}
  }
  if((*root)->name != NULL)
  {
    if(findFirstIndexOfNoneSameChar(name,(*root)->name) >= 0)
    {
      listCreateSubString(&(*root),name,definition);
      return;
    }
    if(findFirstIndexOfNoneSameChar(name,(*root)->name) < 0)
    {
      if((*root)->list.next == NULL)
      {
        listAdd(&(*root)->list.next,name,definition);
        return;
      }
      listCheckNext(&(*root)->list.next,name,definition);
      return;
    }
  }
  listCreateSubString(&(*root),name,definition);
  return;
}

//list to create sub string and choose suitable process should be do
void listCreateSubString(TrieNode **root, char *name, char *definition)
{
  int i = findFirstIndexOfNoneSameChar(name, (*root)->name);
  char *buffer1 = NULL ,*buffer2 = NULL,*buffer3 = NULL;
  buffer1 = createSubString(name, 0, i+1); //parent
  buffer2 = createSubString((*root)->name, i+1, strlen((*root)->name)-(i+1)); //child1
  buffer3 = createSubString(name, i+1, strlen(name)-(i+1)); //child2
  
  char *tempRootWord = (*root)->definition;
  char *tempInsertWord = definition;
  
  if(buffer2 == NULL && buffer3 == NULL)
  {}
  else if(buffer2 != NULL && buffer3 != NULL)
  {
    listFree(&(*root));
    listAdd(&(*root),buffer1,NULL);
    addDictionary(&(*root),buffer2,tempRootWord);
    addDictionary(&(*root),buffer3,tempInsertWord);
  }
  else if(buffer2 == NULL && buffer3 != NULL)
  {
    listFree(&(*root));
    listAdd(&(*root),buffer1,tempRootWord);
    addDictionary(&(*root),buffer3,tempInsertWord);
  }
  else if(buffer2 != NULL && buffer3 == NULL)
  {
    listFree(&(*root));
    listAdd(&(*root),buffer1,tempInsertWord);
    addDictionary(&(*root),buffer2,tempRootWord);
  }
  else
  {
    listFree(&(*root));
    listAdd(&(*root),buffer1,NULL);
    addDictionary(&(*root),buffer2,tempInsertWord);
    addDictionary(&(*root),buffer3,tempInsertWord);
  }
   return;
}

//straight adding the word into node
void listAdd(TrieNode **root, char *name, char *definition)
{
	if((*root) == NULL)
	{
		TrieNode *word = NULL;
		word = (TrieNode*)malloc(sizeof(TrieNode));
		word = createBranch(name, definition);
		word->name = name;
		word->definition = definition;
		(*root) = word;
	}
 (*root)->name = name;
 (*root)->definition = definition;
  return;
}

//free name and definition
void listFree(TrieNode **root)
{
  (*root)->name = NULL;
  (*root)->definition = NULL;
	return;
}

//search dictionary
char *searchDictionary(TrieNode **root, char *name)
{
  char *result;
	TrieNode *word = NULL;
  word = (TrieNode*)malloc(sizeof(TrieNode));
	word = (*root)->list.child;
	//check word to be search is an actual a word or not
	char *wordSearch = convertToLowerCase(name);
  if(wordSearch == NULL)
  {
	  return NULL;
  }

	int i;
	//check is there any match word in it
  if(findFirstIndexOfNoneSameChar(word->name, wordSearch) < 0 && word != NULL)
	{
    word = word->list.next;
	}

  i = findFirstIndexOfNoneSameChar(word->name, wordSearch);
	//return NULL if there is not such word in dictionary
	if(word == NULL)
	{
		return NULL;
	}
	//buffer1 and buffer2 is word to be search
	//buffer3 and buffer4 is the word in dictionary
	char *buffer1,*buffer2,*buffer3,*buffer4;
	buffer1 = createSubString(wordSearch, 0, i+1);
	buffer2 = createSubString(wordSearch, i+1, strlen(wordSearch)-(i+1));
	buffer3 = createSubString(word->name, 0, i+1);
	buffer4 = createSubString(word->name, i+1, strlen(word->name)-(i+1));

	//if there is not fully match between word in dictionary and word to search
	if(buffer4 != NULL)
	{
		free(buffer1);free(buffer2);free(buffer3);free(buffer4);
		return NULL;
	}

	//if there are same
	if(buffer4 == NULL && buffer2 == NULL)
	{
		free(buffer1);free(buffer2);free(buffer3);free(buffer4);
		return (word->definition);
	}

	result = searchDictionary(&word, buffer2);
	free(buffer1);free(buffer2);free(buffer3);free(buffer4);
  return result;
}
