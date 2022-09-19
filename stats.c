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
	unsigned char i;
  	for (i=0; i< length; i++){
  		printf("%d ", (unsigned char)data[i]);
  	}
  	printf("\n");
}

unsigned char find_mean(unsigned char* data, unsigned length){
	unsigned short i, sum=0;
  	for ( i=0; i<length; i++ ){
  		sum+=data[i];
  	}
  	return (unsigned char)(sum/length);
}

unsigned char find_maximum(unsigned char* data, unsigned length){
	unsigned char max, i;
	max = data[0];
	for (i=1; i<length; i++){
		if (data[i]>max){
			max = data[i];
		}
	}
	return max;
}

unsigned char get_maxpos(unsigned char* data, unsigned length){
	unsigned char i, maxpos, max;
	maxpos = 0;
	max = data[0];
	for (i=1; i<length; i++){
		if (data[i]>max){
			max = data[i];
			maxpos=i;
		}
	}
	return maxpos;
}

unsigned char find_minimum(unsigned char* data, unsigned length){
	unsigned char i, min;
	min = data[0];
	for (i=1; i<length; i++){
		if (data[i]<min){
			min = data[i];
		}
	}
	return min;
}

unsigned char* sort_array(unsigned char* data, unsigned length){
	unsigned char i, temp;
	unsigned char maxpos, max;
	for (i=0; i<length; i++){
		max = find_maximum(&data[i],length-i);
		maxpos = get_maxpos(&data[i],length-i);
		temp=max;
		data[maxpos+i]=data[i];
		data[i]=temp;
	}
	return data;
}

unsigned char find_median(unsigned char* data, unsigned length){
	unsigned char* sorted_data;
	unsigned int median;

	sorted_data = sort_array(data, length);

	if (length%2 == 1){
		median = sorted_data[length/2];
		return sorted_data[length/2];
	}
	else{
		median = (sorted_data[length/2-1]+sorted_data[length/2])/2;
		return ((sorted_data[length/2-1]+sorted_data[length/2])/2);
	}
}

void print_statistics(unsigned char* data, unsigned char length){
	  printf("\nThese are printed from print_statistics: \n");

	  printf("mean = %hu \n",find_mean(data, length));

	  printf("max = %hu \n",find_maximum(data, length));

	  printf("min = %hu \n",find_minimum(data, length));

	  printf("median = %hu \n",find_median(data, length));
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

