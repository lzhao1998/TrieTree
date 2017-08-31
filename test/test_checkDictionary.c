#include "unity.h"
#include "trietree.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void){}
void tearDown(void){}

void test_search_apple_after_insert_apple(void)
{
  TrieNode *root;
  buildDictionary(&root);

  addDictionary(&root,"apple","a fruit");
  char *result = searchDictionary(&root,"apple");
  printf("Defintion of apple is %s \n",result);
  TEST_ASSERT_EQUAL_STRING("a fruit",result);
}

void test_search_apple_after_insert_must_apple(void)
{
  TrieNode *root;
  buildDictionary(&root);

  addDictionary(&root,"must","need to");
  addDictionary(&root,"apple","a fruit");
  char *result = searchDictionary(&root,"apple");
  printf("Defintion of apple is %s \n",result);
  TEST_ASSERT_EQUAL_STRING("a fruit",result);
}

void test_search_must_after_insert_must_apple(void)
{
  TrieNode *root;
  buildDictionary(&root);

  addDictionary(&root,"must","need to");
  addDictionary(&root,"apple","a fruit");
  char *result = searchDictionary(&root,"must");
  printf("Defintion of must is %s \n",result);
  TEST_ASSERT_EQUAL_STRING("need to",result);
}

void test_search_must_after_insert_must_musician(void)
{
  TrieNode *root;
  buildDictionary(&root);

  addDictionary(&root,"must","need to");
  addDictionary(&root,"musician","people who play music");
  char *result = searchDictionary(&root,"must");
  printf("Defintion of must is %s \n",result);
  TEST_ASSERT_EQUAL_STRING("need to",result);
}

void test_search_musician_after_insert_must_musician(void)
{
  TrieNode *root;
  buildDictionary(&root);

  addDictionary(&root,"must","need to");
  addDictionary(&root,"musician","people who play music");
  char *result = searchDictionary(&root,"musician");
  printf("Defintion of musician is %s \n",result);
  TEST_ASSERT_EQUAL_STRING("people who play music",result);
}

void test_search_mus_after_insert_mus_musician(void)
{
  TrieNode *root;
  buildDictionary(&root);

  addDictionary(&root,"mus","no meaning");
  addDictionary(&root,"musician","people who play music");
  char *result = searchDictionary(&root,"mus");
  printf("Defintion of mus is %s \n",result);
  TEST_ASSERT_EQUAL_STRING("no meaning",result);
}

void test_search_musician_after_insert_mus_musician(void)
{
  TrieNode *root;
  buildDictionary(&root);

  addDictionary(&root,"mus","no meaning");
  addDictionary(&root,"musician","people who play music");
  char *result = searchDictionary(&root,"musician");
  printf("Defintion of musician is %s \n",result);
  TEST_ASSERT_EQUAL_STRING("people who play music",result);
}

void test_search_must_after_insert_must_must(void)
{
  TrieNode *root;
  buildDictionary(&root);

  addDictionary(&root,"must","need to");
  addDictionary(&root,"must","should be");
  char *result = searchDictionary(&root,"must");
  printf("Defintion of must is %s \n",result);
  TEST_ASSERT_EQUAL_STRING("need to",result);
}

void test_search_must_after_insert_apple_tree(void)
{
  TrieNode *root;
  buildDictionary(&root);

  addDictionary(&root,"apple","a fruit");
  addDictionary(&root,"tree","plant");
  char *result = searchDictionary(&root,"must");
  printf("Defintion of must is %s \n",result);
  TEST_ASSERT_EQUAL_STRING(NULL,result);
}

void test_search_tree_after_insert_apple_tree_ton_must_music_ten(void)
{
  TrieNode *root;
  buildDictionary(&root);

  addDictionary(&root,"apple","a fruit");
  addDictionary(&root,"tree","plant");
	addDictionary(&root,"ton","1000kg");
	addDictionary(&root,"music", "vocal or instrumental sounds combined in such a way as to produce beauty of form");
	addDictionary(&root,"must","should be");
	addDictionary(&root,"ten","10");
  char *result = searchDictionary(&root,"tree");
  printf("Defintion of tree is %s \n",result);
  TEST_ASSERT_EQUAL_STRING("plant",result);
}

