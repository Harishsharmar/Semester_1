/**********
*Author :HARISH R SHARMA
*Date :28.10.2021
*Purpose :Assert based problems as part of ADS Assignment 1
*/

#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

int sum_of_numbers();
int square_of_number();
int store_number_reverse_order();
int pattern_detection(const char[]);
int length_of_sentence();

int main()
{
    assert(sum_of_numbers()==0); // 0 indicates successful
    assert(square_of_number()==0); // 0 indicates successful
    assert(store_number_reverse_order()==0);
    assert(pattern_detection("Harish")==3);
    assert(length_of_sentence()==0);
    return 0;
}

