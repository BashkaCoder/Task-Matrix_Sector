#include <iostream>
#include <vector>
#include <ctime>
#include <cstdint>
#include <iomanip>
#include <algorithm>
#include <ranges>
#include <iterator>

#include "Matrix.h"


//	  Sectors
//		\1/
//	   2| |3
//		/4\

void ShowIntro(const std::vector<std::vector<int>>& matrix);
int RestrictInput(int lowerBound, int upperBound);

std::vector<std::vector<int>> CreateMatrix(int rows, int columns);
void FillMatrixWithRandom(std::vector<std::vector<int>>& matrix);
void PrintAllElements(const std::vector<std::vector<int>>& matrix);
void PrintMaxElements(const std::vector<std::vector<int>>& matrix, int sector);

int main() {

	Matrix m(5, 5);
	m.fillWithRandom();
	Print(m);

	int sector;
	//ShowIntro(matrix);

	sector = RestrictInput(1, 4);
	m.printMaxElements(sector);

	return 0;
}

std::vector<std::vector<int>> CreateMatrix(int rows, int columns) {
	std::vector<std::vector<int>> matrix = std::vector<std::vector<int>>(rows, std::vector<int>(columns));
	return matrix;
}

void FillMatrixWithRandom(std::vector<std::vector<int>>& matrix) {
	srand( (unsigned int) time(0)); //Init Random Number Generator(RNG)
	//row ~ y axis
	for (int row = 0; row < matrix.size(); ++row) { 
		// column ~ x
		for (int column = 0; column < matrix[row].size(); ++column) { 
			matrix[row][column] = rand() % 10; // [0; 99]
		}
	}
}

void PrintAllElements(const std::vector<std::vector<int>>& matrix) {
	for (const auto& v : matrix) {
		for (const auto& elem : v) {
			std::cout << std::setw(2) << elem << ' ';
		}
		std::cout << '\n';
	}
}

void PrintMaxElements(const std::vector<std::vector<int>>& matrix, int sector) {
	int currentMax = INT_MIN;

	//Iterate through matrix and 
	//find max element in given sector
	auto rows = matrix.size();
	auto columns = matrix[0].size();
	switch (sector) {
	case 1:
		for (int i = 0; i < rows / 2; ++i) {
			for (int j = i + 1; j < columns - i - 1; ++j) {
				currentMax = std::max(currentMax, matrix[i][j]);
			}
		}
		break;
	case 2:
		for (int j = 0; j < columns / 2; ++j) {
			for (int i = j + 1; i < rows - j - 1; ++i) {
				currentMax = std::max(currentMax, matrix[i][j]);
			}
		}
		break;
	case 3:
		for (int i = rows / 2 + 1; i < rows; ++i) {
			for (int j = columns - i; j < i; ++j) {
				currentMax = std::max(currentMax, matrix[i][j]);
			}
		}
		break;
	case 4:
		for (int j = columns / 2; j < columns; ++j) {
			for (int i = rows - j; i < j; ++i) {
				currentMax = std::max(currentMax, matrix[i][j]);
			}
		}
		break;
	}

	std::cout << "Max element: " << currentMax << '\n';
	std::cout << "Positions(x, y): ";
	
	//Depending on sector print all positions where max element is
	switch (sector) {
	case 1:
		for (int i = 0; i < rows / 2; ++i) {
			for (int j = i + 1; j < columns - i - 1; ++j) {
				if (matrix[i][j] == currentMax)
					std::cout << "(" << j << ", " << i << ")\n";
			}
		}
		break;
	case 2:
		for (int j = 0; j < columns / 2; ++j) {
			for (int i = j + 1; i < rows - j - 1; ++i) {
				if (matrix[i][j] == currentMax)
					std::cout << "(" << i << ", " << j << ")\n";
			}
		}
		break;
	case 3:
		for (int i = rows / 2 + 1; i < rows; ++i) {
			for (int j = columns - i; j < i; ++j) {
				if (matrix[i][j] == currentMax)
					std::cout << "(" << j << ", " << i << ")\n";
			}
		}
		break;
	case 4:
		for (int j = columns / 2; j < columns; ++j) {
			for (int i = rows - j; i < j; ++i) {
				if (matrix[i][j] == currentMax)
					std::cout << "(" << i << ", " << j << ")\n";
			}
		}
		break;
	}
}


void ShowIntro(const std::vector<std::vector<int>>& matrix) {
	std::cout << "Generated random matrix " << matrix.size() << "X" << matrix[0].size() << " :\n";
	PrintAllElements(matrix);
	std::cout << '\n';
	std::cout << "Choose sector in which max element will be found:\n";
	std::cout << " \\1/ \n" 
			  << "2 X 4 \n" 
			  << " /3\\ \n";
	std::cout << "Sector: \n";
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