#include "unity.h"
#include "trietree.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void){}
void tearDown(void){}



//test for listAdd (DONE)
void test_listadd_with_name_and_def(void)
{
  TrieNode *root;
  buildDictionary(&root);
	listAdd(&root,"joke","funny things");
  TEST_ASSERT_EQUAL_STRING("joke",root->name);
  TEST_ASSERT_EQUAL_STRING("funny things",root->definition);
}

void test_listadd_with_NULL_and_def(void)
{
  TrieNode *root;
  buildDictionary(&root);
  listAdd(&root,NULL,"funny things");
  TEST_ASSERT_EQUAL_STRING(NULL,root->name);
  TEST_ASSERT_EQUAL_STRING("funny things",root->definition);
}

void test_listadd_with_name_and_NULL(void)
{
  TrieNode *root;
  buildDictionary(&root);
  listAdd(&root,"joke",NULL);
  TEST_ASSERT_EQUAL_STRING("joke",root->name);
  TEST_ASSERT_EQUAL_STRING(NULL,root->definition);
}

void test_listadd_with_NULL_and_NULL(void)
{
  TrieNode *root;
  buildDictionary(&root);
  listAdd(&root,NULL,NULL);
  TEST_ASSERT_EQUAL_STRING(NULL,root->name);
  TEST_ASSERT_EQUAL_STRING(NULL,root->definition);
}

void test_listadd_2_different_name_and_definition(void)
{
  TrieNode *root;
  buildDictionary(&root);
  listAdd(&root,"joke","funny things");
  listAdd(&root,"mock","fake it");
  TEST_ASSERT_EQUAL_STRING("mock",root->name);
  TEST_ASSERT_EQUAL_STRING("fake it",root->definition);
}

void test_listadd_2_times_same_name_but_not_same_definition(void)
{
  TrieNode *root;
  buildDictionary(&root);
  listAdd(&root,"joke","funny things");
  listAdd(&root,"joke","what?");
  TEST_ASSERT_EQUAL_STRING("joke",root->name);
  TEST_ASSERT_EQUAL_STRING("what?",root->definition);
}

void test_listadd_2_times_same_definition_but_not_same_name(void)
{
  TrieNode *root;
  buildDictionary(&root);
  listAdd(&root,"joke","funny things");
  listAdd(&root,"mock","funny things");
  TEST_ASSERT_EQUAL_STRING("mock",root->name);
  TEST_ASSERT_EQUAL_STRING("funny things",root->definition);
}

void test_listadd_2_times_same_name_and_definition (void)
{
  TrieNode *root;
  buildDictionary(&root);
  listAdd(&root,"joke","funny things");
  listAdd(&root,"joke","funny things");
  TEST_ASSERT_EQUAL_STRING("joke",root->name);
  TEST_ASSERT_EQUAL_STRING("funny things",root->definition);
}
