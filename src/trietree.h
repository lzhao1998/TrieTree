#ifndef _TRIETREE_H
#define _TRIETREE_H

typedef struct Trie Trie;
typedef struct LinkedList LinkedList;


struct Trie
{
  char *name;
  Trie *next;
  Trie *previous;
  Trie *parent;
  Trie *child;
 // LinkedList *list;
  char *definition;
};


/*struct LinkedList
{
  Trie *next;
  Trie *previous;
  Trie *parent;
  Trie *child;
};
*/

void createTrie(Trie **root);
void buildDictionary(Trie **root, char *name, char *definition);
char *convertToLowerCase(char *name);
char *searchDictionary(Trie *root, char *name);
Trie *createBranch(char* name, char* definition);
#endif // _TRIETREE_H
