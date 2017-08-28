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


char *convertToLowerCase(char *name);
char *checkIsWord(char *name);
int findFirstIndexOfNoneSameChar(char* str1, char* str2);
char *createSubString(char *strName,int startIndex, int length);
void buildDictionary(TrieNode **root);
TrieNode *createBranch(char* name, char* definition);
void addDictionary(TrieNode **root, char *name, char *definition);
void listCheckNext(TrieNode **root, char *name, char *definition);
void listCreateSubString(TrieNode **root, char *name, char *definition);
void listAdd(TrieNode **root, char *name, char *definition);
void listFree(TrieNode **root);
char *searchDictionary(TrieNode **root, char *name);
int isMatchSomeChar(char *name, char *word);

#endif // _TRIETREE_H
