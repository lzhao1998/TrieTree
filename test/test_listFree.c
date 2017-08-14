#include "unity.h"
#include "trietree.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void){}
void tearDown(void){}

//test list free name and defintion (DONE)
void test_free_name_and_definition(void)
{
  TrieNode *root;
  buildDictionary(&root);
	listAdd(&root,"joke","funny things");
  listFree(&root);
  TEST_ASSERT_EQUAL_STRING(NULL,root->name);
  TEST_ASSERT_EQUAL_STRING(NULL,root->definition);
}

void test_free_all_when_there_is_name_and_no_definition(void)
{
  TrieNode *root;
  buildDictionary(&root);
	listAdd(&root,"joke",NULL);
  listFree(&root);
  TEST_ASSERT_EQUAL_STRING(NULL,root->name);
  TEST_ASSERT_EQUAL_STRING(NULL,root->definition);
}

void test_free_all_when_there_is_definition_and_no_name(void)
{
  TrieNode *root;
  buildDictionary(&root);
	listAdd(&root,NULL,"funny things");
  listFree(&root);
  TEST_ASSERT_EQUAL_STRING(NULL,root->name);
  TEST_ASSERT_EQUAL_STRING(NULL,root->definition);
}

void test_free_all_when_there_is_NULL_in_it(void)
{
  TrieNode *root;
  buildDictionary(&root);
	listAdd(&root,NULL,NULL);
  listFree(&root);
  TEST_ASSERT_EQUAL_STRING(NULL,root->name);
  TEST_ASSERT_EQUAL_STRING(NULL,root->definition);
}
