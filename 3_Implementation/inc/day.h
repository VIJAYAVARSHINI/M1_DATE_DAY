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

#ifndef _DAY_H_
#define _DAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int validateDate(int d, int m, int y);

/**
 * @brief Validating the provided date
 * @param[in] operand1 Date - DD format
 * @param[in] operand2 Month - MM format
 * @param[in] operand3 Year - YYYY format
 * @return Result 0 or 1
 * 
 */


int wd(int year, int month, int day);

/**
 * @brief Calculating the day of the week
 * @param[in] operand1 Date - DD format
 * @param[in] operand2 Month - MM format
 * @param[in] operand3 Year - YYYY format
 * @return Result [0 to 6]
 * 
 */


#endif  /* _DAY_H_ */
