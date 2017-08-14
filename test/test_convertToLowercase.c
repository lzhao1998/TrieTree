
#include "unity.h"
#include "trietree.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void){}
void tearDown(void){}

//test for convert word into lowercase (DONE)
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