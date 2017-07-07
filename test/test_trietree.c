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
  char arraySTR[] = "HELLO W33lD";
  result = convertToLowerCase(arraySTR);
  //result = convertToLowerCase("HELLOWORLD");
  
  TEST_ASSERT_EQUAL_STRING("hello w33ld",result);
}
