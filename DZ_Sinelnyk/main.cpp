#include <iostream>

#include "Matrix.h"


//	  Sectors
//		\1/
//	   2| |3
//		/4\

int RestrictInput(int lowerBound, int upperBound);

int main() {

	Matrix m(5, 5);
	m.fillWithRandom();
	Print(m);

	int sector;

	sector = RestrictInput(1, 4);
	m.printMaxElements(sector);

	return 0;
}

int RestrictInput(int lowerBound, int upperBound) {
	//Read value until it's >= lowerBound AND <= upperBound
	int inputValue;
	do {
		std::cout << "Enter value [" << lowerBound << ":" << upperBound << "]: \n";
		std::cin >> inputValue;
	} while (inputValue < lowerBound || inputValue > upperBound);
	return inputValue;
}