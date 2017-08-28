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

  addDictionary(&root,"apple","fruit");
  TEST_ASSERT_EQUAL_STRING("apple",root->list.child->name);
  TEST_ASSERT_EQUAL_STRING("fruit",root->list.child->definition);
}

void test_insert_name_and_def_twice(void) //done
{
  TrieNode *root;
  buildDictionary(&root);

  addDictionary(&root,"apple","fruit");
  addDictionary(&root,"tree","plant");
  TEST_ASSERT_EQUAL_STRING("apple",root->list.child->name);
  TEST_ASSERT_EQUAL_STRING("fruit",root->list.child->definition);
  //TEST_ASSERT_EQUAL_STRING("tree",root->list.child->list.next->name);
  //TEST_ASSERT_EQUAL_STRING("plant",root->list.child->list.next->definition);
}