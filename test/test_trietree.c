#include "unity.h"
#include "trietree.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void){}
void tearDown(void){}

void test_trietree_lowercase(void)
{
  char *result;
  result = convertToLowerCase("HELLO WORLD!");
  
  TEST_ASSERT_EQUAL_STRING("hello world!",result);
}

void test_only_1_node(void)
{
  TrieNode *root;
  buildDictionary(&root);
  
  addDictionary(&root,"hey", "hi to everyone");
}

void test_1st_node(void)
{
  TrieNode *root;
  buildDictionary(&root);
  
  addDictionary(&root,"music", "can be song,melody");
  addDictionary(&root,"sock", "just a sock");
}

void test_listAdd_function(void)
{
  TrieNode *root;
  buildDictionary(&root);
  listAdd(&root,"hi","hhh",1);
  listAdd(&root,"hey","ad",1);
  listAdd(&root,"hooo","hasdh",2);
  listAdd(&root,"world","asqwgh",3);
}

void test_dictionary(void)
{
  TrieNode *root;
  buildDictionary(&root);
  
  addDictionary(&root,"determine", "de");
  addDictionary(&root,"determination", "zz...");
}

void test_find_1st_Index_of_None_Same_Char_tone_toe(void)
{
  int i = findFirstIndexOfNoneSameChar("tone","toe");
  TEST_ASSERT_EQUAL(1,i);
}

void test_find_1st_Index_of_None_Same_Char_toe_tone(void)
{
  int i = findFirstIndexOfNoneSameChar("toe","tone");
  TEST_ASSERT_EQUAL(1,i);
}

void test_find_1st_Index_of_None_Same_Char_xing_zing(void)
{
  int i = findFirstIndexOfNoneSameChar("xing","zing");
  TEST_ASSERT_EQUAL(-1,i);
}

void test_find_1st_Index_of_None_Same_Char_NULL_toe(void)
{
  int i = findFirstIndexOfNoneSameChar("","toe");
  TEST_ASSERT_EQUAL(-1,i);
}

void test_find_1st_Index_of_None_Same_Char_info_informative(void)
{
  int i = findFirstIndexOfNoneSameChar("info","informative");
  TEST_ASSERT_EQUAL(3,i);
}

void test_find_1st_Index_of_None_Same_Char_information_informative(void)
{
  int i = findFirstIndexOfNoneSameChar("information","informative");
  TEST_ASSERT_EQUAL(8,i);
}

void test_get_llo_from_hello_when_start2_length3 (void)
{
  char *result;
  result = createSubString("hello", 2, 3);
  
  TEST_ASSERT_EQUAL_STRING("llo",result);
}

void test_get_he_from_hello_when_start0_length2 (void)
{
  char *result;
  result = createSubString("hello", 0, 2);
  
  TEST_ASSERT_EQUAL_STRING("he",result);
}

void test_get_NULL_from_hello_when_start6_length2 (void)
{
  char *result;
  result = createSubString("hello", 6, 2);
  
  TEST_ASSERT_EQUAL_STRING(NULL,result);
}

void test_get_hello_from_hello_when_start0_length10 (void)
{
  char *result;
  result = createSubString("hello", 0, 10);
  
  TEST_ASSERT_EQUAL_STRING("hello",result);
}

void test_get_NULL_from_hello_when_start2_length0 (void)
{
  char *result;
  result = createSubString("hello", 2, 0);
  
  TEST_ASSERT_EQUAL_STRING(NULL,result);
}