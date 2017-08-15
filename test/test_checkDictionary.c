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
