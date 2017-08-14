#include "unity.h"
#include "trietree.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void){}
void tearDown(void){}

//test for there is an actual word or not (DONE)
void test_wordsd_return_wordsd(void)
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
