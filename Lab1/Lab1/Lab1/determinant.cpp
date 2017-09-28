/*********************************************************************
** Program name: Lab1
** Author: Mario Franco-Munoz
** Date: 09/27/2017
** Description:
*********************************************************************/

#include "determinant.hpp"

int determinant(int ***arrIn, int sizeIn) {
	int det = 0;

	// |A| = ad - bc
	if (sizeIn == 2) {
		det = ((*arrIn)[0][0]) * ((*arrIn)[1][1]);
		det = det - ( ((*arrIn)[1][0]) * ((*arrIn)[0][1]) );
	}

	// |A| = a(ei - fh) - b(di - fg) + c(dh - eg)
	else if (sizeIn == 3) {
		det = (*arrIn)[0][0] * ( (((*arrIn)[1][1]) * ((*arrIn)[2][2]) ) - ( ( ((*arrIn)[2][1]) * ((*arrIn)[1][2]) ) ) );
		det -= (*arrIn)[1][0] * ((((*arrIn)[0][1]) * ((*arrIn)[2][2])) - ((((*arrIn)[2][1]) * ((*arrIn)[0][2]))));
		det += (*arrIn)[2][0] * ((((*arrIn)[0][1]) * ((*arrIn)[1][2])) - ((((*arrIn)[1][1]) * ((*arrIn)[0][2]))));
	}
	return det;
}



