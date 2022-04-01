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

int validateDate(int d, int m, int y)
{
    if (y >= 1800 && y <= 2999) {
        if (m >= 1 && m <= 12) {
            if (d >= 1 && d <= 31) {
                if ((d >= 1 && d <= 30) && (m == 4 || m == 6 || m == 9 || m == 11))
                    return 1; //valid date
                else if ((d >= 1 && d <= 30) && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
                    return 1; //valid date
                else if ((d >= 1 && d <= 28) && (m == 2))
                    return 1; //valid date
                else if (d == 29 && m == 2 && ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)))
                    return 1; //valid date
                else
                    return 0; //invalid day
            }
            else {
                return 0; //day is invalid
            }
        }
        else {
            return 0; //month is invalid
        }
    }
    else {
        return 0; //year is invalid
    }
}


void manual_test_validateDate()
{
    printf("\nTEST FOR VALID DATE - MANUAL TESTING\n");

    if (0 == validateDate(0, 0, 0))
        printf("Invalid Date\n");
    else
        printf("Valid Date\n");

    if (1 == validateDate(26, 03, 2022))
        printf("Valid Date\n");
    else
        printf("Invalid Date\n");

    if (0 == validateDate(-12, -13, 2020))
        printf("Invalid Date\n");
    else
        printf("Valid Date\n");

    if (0 == validateDate(45, 22, 2040))
        printf("Invalid Date\n");
    else
        printf("Valid Date\n");

    if (1 == validateDate(01, 12, 2020))
        printf("Valid Date\n\n");
    else
        printf("Invalid Date\n\n");
}



void automated_test_validateDate()
{

    printf("\nTEST FOR VALID DATE - AUTOMATED TESTING\n");

    TEST_ASSERT_EQUAL(0, validateDate(0, 0, 0));
    TEST_ASSERT_EQUAL(1, validateDate(27, 03, 2022));
    TEST_ASSERT_EQUAL(0, validateDate(19, 60, 203));
    TEST_ASSERT_EQUAL(0, validateDate(-12, -03, 2003));
    TEST_ASSERT_EQUAL(1, validateDate(19, 06, 2095));
}



/*

int main()
{
    automated_test_validateDate();
    return 0;
}
*/



