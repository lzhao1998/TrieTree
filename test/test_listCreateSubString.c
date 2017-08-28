#include "unity.h"
#include "trietree.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void){}
void tearDown(void){}

void test_insert_name_and_def_once(void) //done
{
  TrieNode *root;
  buildDictionary(&root);

  listCheckNext(&root,"apple","fruit");
  TEST_ASSERT_EQUAL_STRING("apple",root->name);
  TEST_ASSERT_EQUAL_STRING("fruit",root->definition);
}