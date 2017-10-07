/*********************************************************************
** Program name: Lab1 (Matrix Determinant Calculator)
** Author: Mario Franco-Munoz
** Date: 09/27/2017
** Description: This file contains the determinant function takes a pointer to a (prepopulated) 2D array and the size
**	of that array (as a single digit where 2 denotes a 2x2 array and 3 denotes a 3x3 array). The function then
**	calculates the determinant and returns it.
*********************************************************************/

#include "determinant.hpp"

int determinant(int **arrIn, int sizeIn) {
	int det = 0;

	// |A| = ad - bc
	if (sizeIn == 2) {
		det = ((arrIn)[0][0]) * ((arrIn)[1][1]);
		det = det - ( ((arrIn)[1][0]) * ((arrIn)[0][1]) );
	}

	// |A| = a(ei - fh) - b(di - fg) + c(dh - eg)
	else if (sizeIn == 3) {
		det = (arrIn)[0][0] * ( (((arrIn)[1][1]) * ((arrIn)[2][2]) ) - ( ( ((arrIn)[2][1]) * ((arrIn)[1][2]) ) ) );
		det -= (arrIn)[1][0] * ((((arrIn)[0][1]) * ((arrIn)[2][2])) - ((((arrIn)[2][1]) * ((arrIn)[0][2]))));
		det += (arrIn)[2][0] * ((((arrIn)[0][1]) * ((arrIn)[1][2])) - ((((arrIn)[1][1]) * ((arrIn)[0][2]))));
	}
	return det;
}



