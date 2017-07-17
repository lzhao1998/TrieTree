#include "unity.h"
#include "trietree.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_trietree_lowercase(void)
{
  char *result;
  result = convertToLowerCase("HELLO WORLD!");
  
  TEST_ASSERT_EQUAL_STRING("hello world!",result);
}
void test_1st_node(void)
{
  Trie *root;
  createTrie(&root);
  
  buildDictionary(&root,"HELLO", "hi to everyone");
  buildDictionary(&root,"helo", "hi");
}