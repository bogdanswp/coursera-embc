/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief contains functions for statistical analysis
 *
 * C programming functions for computing mean, max, min, medium
 *
 * @author <Bogdan Popescu>
 * @date <18 sept 2022>
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void print_array(unsigned char* data, unsigned length){
}

unsigned char find_mean(unsigned char* data, unsigned length){
}

unsigned char find_maximum(unsigned char* data, unsigned length){
}

unsigned char get_maxpos(unsigned char* data, unsigned length){
}

unsigned char find_minimum(unsigned char* data, unsigned length){
}

unsigned char* sort_array(unsigned char* data, unsigned length){
	return data;
}

unsigned char find_median(unsigned char* data, unsigned length){
}

void print_statistics(unsigned char* data, unsigned char length){
}

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  print_array(test, SIZE);

  printf("mean = %hu \n",find_mean(test, SIZE));

  printf("max = %hu \n",find_maximum(test, SIZE));

  printf("min = %hu \n",find_minimum(test, SIZE));

  printf("median = %hu \n",find_median(test, SIZE));

  print_array(sort_array(test, SIZE),SIZE);

  print_statistics(test, SIZE);

  return 0;
}

/* Add other Implementation File Code Here */

