/**
 * @file day.h
 * @author VIJAYA VARSHINI K
 * @brief Validating the day of the week, for a given date along with a message and a book suggession
 * @version 0.1
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <stdio.h>
#include "unity.h"
#if defined __STDC_LIB_EXT1__
#endif

extern void manual_test_validateDate();
extern void automated_test_validateDate();
extern void manual_test_wd();
extern void automated_test_wd();

void setUp(void)
{
}

void tearDown(void)
{
}

/*
void automated_test_validateDate()
{
    TEST_ASSERT_EQUAL(0, validateDate(0, 0, 0));
    TEST_ASSERT_EQUAL(1, validateDate(27, 03, 2022));
    TEST_ASSERT_EQUAL(0, validateDate(19, 60, 203));
}
*/


int main(void)
{
    //manual_test_validateDate();

    UnityBegin(NULL);

    RUN_TEST(manual_test_validateDate);
    RUN_TEST(automated_test_validateDate);
    RUN_TEST(manual_test_wd);
    RUN_TEST(automated_test_wd);
    
    return (UnityEnd());
}