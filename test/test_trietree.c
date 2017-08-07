#include "unity.h"
#include "trietree.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void){}
void tearDown(void){}

/*void test_wordsd_return_wordsd(void)
{
	char *result;
	result = checkIsWord("wordsd");
	TEST_ASSERT_EQUAL_STRING("wordsd",result);
}

void test_123word_return_NULL(void)
{
	char *result;
	result = checkIsWord("123word");
	TEST_ASSERT_EQUAL_STRING(NULL,result);
}

void test_wo123rd_return_NULL(void)
{
	char *result;
	result = checkIsWord("wo123rd");
	TEST_ASSERT_EQUAL_STRING(NULL,result);
}

void test_12345_return_NULL(void)
{
	char *result;
	result = checkIsWord("12345");
	TEST_ASSERT_EQUAL_STRING(NULL,result);
}

void test_word123_return_NULL(void)
{
	char *result;
	result = checkIsWord("word123");
	TEST_ASSERT_EQUAL_STRING(NULL,result);
}

void test_NULL_return_NULL(void)
{
	char *result;
	result = checkIsWord(" ");
	TEST_ASSERT_EQUAL_STRING(NULL,result);
}

void test_hello_world_return_NULL(void)
{
	char *result;
	result = checkIsWord("hello world");
	TEST_ASSERT_EQUAL_STRING(NULL,result);
}

void test_w_specialChar_sd_return_NULL(void)
{
	char *result;
	result = checkIsWord("wo!?sd");
	TEST_ASSERT_EQUAL_STRING(NULL,result);
}

void test_NULL_in_checkIsWord_return_NULL(void)
{
	char *result;
	result = checkIsWord(NULL);
	TEST_ASSERT_EQUAL_STRING(NULL,result);
}

void test_word_return_word(void)
{
	char *result;
	result = checkIsWord("word");
	TEST_ASSERT_EQUAL_STRING("word",result);
}

void test_trietree_lowercase(void)
{
  char *result;
  result = convertToLowerCase("HELLO WORLD!");
  
  TEST_ASSERT_EQUAL_STRING("hello world!",result);
}

void test_TrieTree_to_trietree(void)
{
  char *result;
  result = convertToLowerCase("TrieTree");
  
  TEST_ASSERT_EQUAL_STRING("trietree",result);
}

void test_aDFg_to_adfg(void)
{
  char *result;
  result = convertToLowerCase("aDFg");
  
  TEST_ASSERT_EQUAL_STRING("adfg",result);
}

void test_Hello123_to_hello123(void)
{
  char *result;
  result = convertToLowerCase("Hello123");
  
  TEST_ASSERT_EQUAL_STRING("hello123",result);
}

void test_NULL_to_NULL_in_convertLowercase(void)
{
  char *result;
  result = convertToLowerCase(NULL);
  
  TEST_ASSERT_EQUAL_STRING(NULL,result);
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
}*/

void test_only_1_node(void)
{
  TrieNode *root;
  //LinkedList *root;
  buildDictionary(&root);
  
  addDictionary(&root,"hey", "hi to everyone");
}

void test_insert_2_node(void)
{
  TrieNode *root;
  //LinkedList *root;
  buildDictionary(&root);
  
  addDictionary(&root,"music", "can be song,melody");
  addDictionary(&root,"sock", "just a sock");
  addDictionary(&root,"toe", "kaki punya finger");
}

void test_insert_2_node_with_same_char_infront(void)
{
  TrieNode *root;
  //LinkedList *root;
  buildDictionary(&root);
  
  addDictionary(&root,"music", "can be song,melody");
  addDictionary(&root,"must", "should be do or need to do");
}

void test_insert_2_node_with_same_word(void)
{
  TrieNode *root;
  //LinkedList *root;
  buildDictionary(&root);
  
  addDictionary(&root,"music", "aaa");
  addDictionary(&root,"music", "bbbb");
}

void test_insert_3_node_should_contain_3_child(void)
{
  TrieNode *root;
  //LinkedList *root;
  buildDictionary(&root);
  
  addDictionary(&root,"mus", "mus?");
  //addDictionary(&root,"music", "should be do or need to do");
  addDictionary(&root,"musication", "people who play music");
}

/*-------------------might not use------------------------
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

------------------------------------------------------*/

