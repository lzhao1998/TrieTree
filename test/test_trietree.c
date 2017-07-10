#include "unity.h"
#include "trietree.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_trietree(void)
{
  char *result;
  result = convertToLowerCase("HELLO W33lD");
  
  TEST_ASSERT_EQUAL_STRING("hello w33ld",result);
}
