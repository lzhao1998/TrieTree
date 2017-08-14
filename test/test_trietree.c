#include "unity.h"
#include "trietree.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void){}
void tearDown(void){}

//test for adding word into dictionary
void test_get_NULL_when_insert_NULL_in_dictionary(void)  //DONE
{
  TrieNode *root;
  buildDictionary(&root);
  
  addDictionary(&root,NULL, "hi to everyone");
  TEST_ASSERT_EQUAL_STRING(NULL,root->name);
  TEST_ASSERT_EQUAL_STRING(NULL,root->definition);
}

void test_insert_1_word_into_dictionary(void)
{
  TrieNode *root;
  buildDictionary(&root);
  
  addDictionary(&root,"hey", "hi to everyone");
  TEST_ASSERT_EQUAL_STRING("hey",root->list.child->name);
  TEST_ASSERT_EQUAL_STRING("hi to everyone",root->list.child->definition);
}

void test_insert_2_word_into_dictionary(void) //DONE
{
  TrieNode *root;
  buildDictionary(&root);
  
  addDictionary(&root,"music", "can be song or melody");
  addDictionary(&root,"sock", "just a sock");
  TEST_ASSERT_EQUAL_STRING("music",root->list.child->name);
  TEST_ASSERT_EQUAL_STRING("can be song or melody",root->list.child->definition);
  TEST_ASSERT_EQUAL_STRING("sock",root->list.child->list.next->name);
  TEST_ASSERT_EQUAL_STRING("just a sock",root->list.child->list.next->definition);
}

void test_insert_2_word_with_same_few_char_infront(void) //DONE
{
  TrieNode *root;
  buildDictionary(&root);
  
  addDictionary(&root,"music", "can be song or melody");
  addDictionary(&root,"must", "should be do or need to do");
  TEST_ASSERT_EQUAL_STRING("mus",root->list.child->name);
  TEST_ASSERT_EQUAL_STRING(NULL,root->list.child->definition);
  TEST_ASSERT_EQUAL_STRING("ic",root->list.child->list.child->name);
  TEST_ASSERT_EQUAL_STRING("can be song or melody",root->list.child->list.child->definition);
  TEST_ASSERT_EQUAL_STRING("t",root->list.child->list.child->list.next->name);
  TEST_ASSERT_EQUAL_STRING("should be do or need to do",root->list.child->list.child->list.next->definition);
}

void test_insert_2_node_with_same_word(void) //DONE
{
  TrieNode *root;
  buildDictionary(&root);
  
  addDictionary(&root,"music", "aaa");
  addDictionary(&root,"music", "bbbb");
  TEST_ASSERT_EQUAL_STRING("music",root->list.child->name);
  TEST_ASSERT_EQUAL_STRING("aaa",root->list.child->definition);
  
}

void test_insert_2_node_with_mus_and_musician(void) //DONE
{
  TrieNode *root;
  buildDictionary(&root);
  
  addDictionary(&root,"mus", "mus?");
  addDictionary(&root,"musician", "people who play music");
  TEST_ASSERT_EQUAL_STRING("mus",root->list.child->name);
  TEST_ASSERT_EQUAL_STRING("mus?",root->list.child->definition);
  TEST_ASSERT_EQUAL_STRING("ician",root->list.child->list.child->name);
  TEST_ASSERT_EQUAL_STRING("people who play music",root->list.child->list.child->definition);
}

/*
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
*/