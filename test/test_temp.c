#include "unity.h"
#include "trietree.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void){}
void tearDown(void){}

//test for adding word into dictionar
void test_insert_3_nodes_which_is_mus_music_musician(void) //PROBLEM!!!
{
  TrieNode *root;
  buildDictionary(&root);
  
  addDictionary(&root,"mus", "no meaning");
  addDictionary(&root,"music", "vocal or instrumental sounds combined in such a way as to produce beauty of form");
  addDictionary(&root,"musician","a person who plays a musical instrument");
  TEST_ASSERT_EQUAL_STRING("mus",root->list.child->name);
  TEST_ASSERT_EQUAL_STRING("no meaning",root->list.child->definition);
  TEST_ASSERT_EQUAL_STRING("ic",root->list.child->list.child->name);
  TEST_ASSERT_EQUAL_STRING("vocal or instrumental sounds combined in such a way as to produce beauty of form",root->list.child->list.child->definition);
  TEST_ASSERT_EQUAL_STRING("ian",root->list.child->list.child->list.child->name);
  TEST_ASSERT_EQUAL_STRING("a person who plays a musical instrument",root->list.child->list.child->list.child->definition);
}
