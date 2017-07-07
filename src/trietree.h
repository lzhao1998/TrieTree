#ifndef _TRIETREE_H
#define _TRIETREE_H

typedef struct Trie Trie;
typedef struct LinkedList LinkedList;

struct Trie
{
  char *name;
  LinkedList *list;
  char *definition;
};

struct LinkedList
{
  Trie *head;
  Trie *tail;
  int branch;
};

void strLow(char *text);
void buildDictionary(Trie **tree, char *name, char *definition);
char *convertToLowerCase(char *name);
char *searchDictionary(Trie *tree, char *name);

#endif // _TRIETREE_H
