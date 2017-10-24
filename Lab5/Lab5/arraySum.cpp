/*********************************************************************
** Program name: Lab5
** Author: Mario Franco-Munoz
** Date: 10/23/2017
** Description: Source file for arraySum function. This function uses recursion to 
** summ all the elements of a 1-D array. 
*********************************************************************/

#include "arraySum.hpp"

int arraySum(int *arr, int size) {
	if (size > 0) {  //base case
		size -= 1;
		return arr[size] + arraySum(arr, size);
	}
	else { //conlcuding statement - what happens when the base case is reached the "actual" base case
		return 0;
	}
}
