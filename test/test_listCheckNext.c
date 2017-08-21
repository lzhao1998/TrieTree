#include "unity.h"
#include "trietree.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void){}
void tearDown(void){}
/*
void test_insert_name_and_def_once(void)
{
  TrieNode *root;
  buildDictionary(&root);

  listCheckNext(&root,"apple","fruit");
  TEST_ASSERT_EQUAL_STRING("apple",root->name);
  TEST_ASSERT_EQUAL_STRING("fruit",root->definition);
}*/

void test_insert_name_and_def_twice(void)
{
  TrieNode *root;
  buildDictionary(&root);

  listCheckNext(&root,"apple","fruit");
  listCheckNext(&root,"tree","plant");
  TEST_ASSERT_EQUAL_STRING("apple",root->name);
  TEST_ASSERT_EQUAL_STRING("fruit",root->definition);
  TEST_ASSERT_EQUAL_STRING("tree",root->list.next->name);
  TEST_ASSERT_EQUAL_STRING("plant",root->list.next->definition);
}