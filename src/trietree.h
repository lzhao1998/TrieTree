#ifndef _TRIETREE_H
#define _TRIETREE_H

typedef struct TrieNode TrieNode;
typedef struct LinkedList LinkedList;

struct LinkedList
{
  TrieNode *next;
  TrieNode *previous;
  TrieNode *child;
};

struct TrieNode
{
  char *name;
  char *definition;
  LinkedList list;
};





void buildDictionary(TrieNode **root);
void addDictionary(TrieNode **root, char *name, char *definition);
char *convertToLowerCase(char *name);
char *searchDictionary(TrieNode *root, char *name);
TrieNode *createBranch(char* name, char* definition);
int findFirstIndexOfNoneSameChar(char* str1, char* str2);
char *createSubString(char *strName,int startIndex, int length);
#endif // _TRIETREE_H
