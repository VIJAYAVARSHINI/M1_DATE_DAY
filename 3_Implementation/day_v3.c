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

int wd(int year, int month, int day)
{
    int wday = 0;
    wday = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5)
        + (365 * (year + 4800 - ((14 - month) / 12)))
        + ((year + 4800 - ((14 - month) / 12)) / 4)
        - ((year + 4800 - ((14 - month) / 12)) / 100)
        + ((year + 4800 - ((14 - month) / 12)) / 400)
        - 32045)
        % 7;
    return wday;
}

void manual_test_wd()
{
    printf("\nTEST FOR WEEK DAY - MANUAL TESTING\n");

    if ((!(0,1,2,3,4,5,6)) == wd(26, 03, 2022))
        printf("\nInvalid Date and no day\n");
    else
        printf("\nValid Date and Day\n");

    if (6 == wd(26, 03, 202255))
        printf("Valid Date and day\n");
    else
        printf("Invalid Date and no Day\n");

    if (12 == wd(26, -03, 2022))
        printf("valid Date and day\n");
    else
        printf("Invalid Date and no Day\n");

}

void automated_test_wd()
{
    printf("\nTEST FOR WEEK DAY - AUTOMATED TESTING\n");

    TEST_ASSERT_EQUAL(!0, wd(0, 0, 0));
    TEST_ASSERT_EQUAL(5, wd(27, 03, 2022));
    TEST_ASSERT_EQUAL(1, wd(19, 03, 2000));
    
}

/*
int main()
{
    manual_test_wd();
    return 0;
}
*/

