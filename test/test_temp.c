#include "unity.h"
#include "trietree.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void){}
void tearDown(void){}

/*
void test_insert_3_nodes_music_apple_application(void)
{
  TrieNode *root;
  buildDictionary(&root);

  addDictionary(&root,"music", "vocal or instrumental sounds combined in such a way as to produce beauty of form");
  addDictionary(&root,"apple", "a fruit");
  addDictionary(&root,"application","the act of putting to a special use or purpose");
  TEST_ASSERT_EQUAL_STRING("music",root->list.child->name);
  TEST_ASSERT_EQUAL_STRING("vocal or instrumental sounds combined in such a way as to produce beauty of form",root->list.child->definition);
  TEST_ASSERT_EQUAL_STRING("appl",root->list.child->list.next->name);
  TEST_ASSERT_EQUAL_STRING(NULL,root->list.child->list.next->definition);
  TEST_ASSERT_EQUAL_STRING("e",root->list.child->list.next->list.child->name);
  TEST_ASSERT_EQUAL_STRING("a fruit",root->list.child->list.next->list.child->definition);
  TEST_ASSERT_EQUAL_STRING("ication",root->list.child->list.next->list.child->list.next->name);
  TEST_ASSERT_EQUAL_STRING("the act of putting to a special use or purpose",root->list.child->list.next->list.child->list.next->definition);
}*/

void test_insert_3_nodes_apple_must_tree(void)
{
  TrieNode *root;
  buildDictionary(&root);

  addDictionary(&root,"apple", "a fruit");
  addDictionary(&root,"must", "need to");
  addDictionary(&root,"tree", "a plant");
  TEST_ASSERT_EQUAL_STRING("apple",root->list.child->name);
  TEST_ASSERT_EQUAL_STRING("a fruit",root->list.child->definition);
  TEST_ASSERT_EQUAL_STRING("must",root->list.child->list.next->name);
  TEST_ASSERT_EQUAL_STRING("need to",root->list.child->list.next->definition);
  TEST_ASSERT_EQUAL_STRING("tree",root->list.child->list.next->list.next->name);
  TEST_ASSERT_EQUAL_STRING("a plant",root->list.child->list.next->list.next->definition);
}

/*
void test_search_tree_after_insert_apple_must_tree(void)
{
  TrieNode *root;
  buildDictionary(&root);

  addDictionary(&root,"apple","a fruit");
  addDictionary(&root,"must","need to");
  addDictionary(&root,"tree","a plant");
  TEST_ASSERT_EQUAL_STRING("tree",root->list.child->list.next->list.next);
  char *result = searchDictionary(&root,"tree");
  printf("Defintion of tree is %s \n",result);
  TEST_ASSERT_EQUAL_STRING("a plant",result);
}*/
