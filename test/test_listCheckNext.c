#include "unity.h"
#include "trietree.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void){}
void tearDown(void){}
/*
void test_insert_name_and_def_once(void) //done
{
  TrieNode *root;
  buildDictionary(&root);

  listCheckNext(&root,"apple","fruit");
  TEST_ASSERT_EQUAL_STRING("apple",root->name);
  TEST_ASSERT_EQUAL_STRING("fruit",root->definition);
}

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

void test_insert_name_and_def_three_times(void)
{
  TrieNode *root;
  buildDictionary(&root);

  listCheckNext(&root,"apple","fruit");
  listCheckNext(&root,"tree","plant");
  listCheckNext(&root,"book","many pieces of paper that clip together");
  TEST_ASSERT_EQUAL_STRING("apple",root->name);
  TEST_ASSERT_EQUAL_STRING("fruit",root->definition);
  TEST_ASSERT_EQUAL_STRING("tree",root->list.next->name);
  TEST_ASSERT_EQUAL_STRING("plant",root->list.next->definition);
  TEST_ASSERT_EQUAL_STRING("book",root->list.next->list.next->name);
}

void test_insert_name_and_def_four_times(void)
{
  TrieNode *root;
  buildDictionary(&root);

  listCheckNext(&root,"apple","fruit");
  listCheckNext(&root,"tree","plant");
  listCheckNext(&root,"book","many pieces of paper that clip together");
  listCheckNext(&root,"nemo","fish");
  TEST_ASSERT_EQUAL_STRING("apple",root->name);
  TEST_ASSERT_EQUAL_STRING("fruit",root->definition);
  TEST_ASSERT_EQUAL_STRING("tree",root->list.next->name);
  TEST_ASSERT_EQUAL_STRING("plant",root->list.next->definition);
  TEST_ASSERT_EQUAL_STRING("book",root->list.next->list.next->name);
  TEST_ASSERT_EQUAL_STRING("nemo",root->list.next->list.next->list.next->name);
}*/

void test_insert_name_and_def_twice_with_same_1st_index(void)
{
  TrieNode *root;
  buildDictionary(&root);

  listCheckNext(&root,"apple","fruit");
  listCheckNext(&root,"ant","insect");
  printf("parent : %s\n",root->name);
  printf("child1 : %s\n",root->list.child->name);
  //printf("child2 : %s\n",root->list.child->list.next->name);
  TEST_ASSERT_EQUAL_STRING("a",root->name);
  TEST_ASSERT_EQUAL_STRING("pple",root->list.child->name);
  TEST_ASSERT_EQUAL_STRING("fruit",root->list.child->definition);
  TEST_ASSERT_EQUAL_STRING("insect",root->list.child->list.next->definition);
}