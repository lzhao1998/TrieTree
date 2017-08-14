#include "unity.h"
#include "trietree.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void){}
void tearDown(void){}


//test for create sub-string (DONE)
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

void test_get_NULL_from_NULL_when_start1_length1(void)
{
  char *result;
  result = createSubString("",1,1);
  
  TEST_ASSERT_EQUAL_STRING(NULL,result);
}

void test_get_NULL_from_hello_when_start4_length_neg1(void)
{
  char *result;
  result = createSubString("hello",4,-1);
  
  TEST_ASSERT_EQUAL_STRING(NULL,result);
}