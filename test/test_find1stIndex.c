#include "unity.h"
#include "trietree.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void){}
void tearDown(void){}




//test find first index of none same character (DONE)
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

void test_find_1st_Index_of_None_Same_Char_toe_NULL(void)
{
  int i = findFirstIndexOfNoneSameChar("toe","");
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



