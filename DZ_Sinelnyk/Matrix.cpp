#include <stdexcept>
#include "Matrix.h"

#include <ranges>

Matrix::Matrix() : 
	rows(0), columns(0), data(0) 
{ }

Matrix::Matrix(size_t rows, size_t cols) :
	rows(rows), columns(cols)
{ 
	data = std::vector<int>(rows*cols);
}

Matrix::Matrix(const Matrix& other) : 
	rows(other.rows), columns(other.columns), data(other.data)
{ }

int& Matrix::getRef(size_t x, size_t y) {
	if (x >= columns || y >= columns)
		throw std::invalid_argument("X ot Y were out of bounds!");

	return data[y * rows + x];
}

int Matrix::get(size_t x, size_t y) const {
	if (x >= columns || y >= columns)
		throw std::invalid_argument("X ot Y were out of bounds!");

	return data[y * rows + x];
}

void Matrix::fillWithRandom() {
	std::mt19937 randomGenerator(time(0));
	std::uniform_int_distribution<> numberRoll(0, 99);

	for (int i = 0; i < rows * columns; ++i) {
		data[i] = numberRoll(randomGenerator);
	}
}

void Print(const Matrix& m) {
	for (int row = 0; row < m.getRows(); ++row) {
		for (int column = 0; column < m.getColumns(); ++column) {
			std::cout << std::setw(2) << m.get(column, row) << ' ';
		}
		std::cout << '\n';
	}
}

void Matrix::printMaxElements(int sector) {
	int currentMax = INT_MIN;

	//Iterate through matrix and 
	//find max element in given sector
	switch (sector) {
	case 1:
		for (int i = 0; i < rows / 2; ++i) {
			for (int j = i + 1; j < columns - i - 1; ++j) {
				currentMax = std::max(currentMax, get(j, i));
			}
		}
		break;
	case 2:
		for (int j = 0; j < columns / 2; ++j) {
			for (int i = j + 1; i < rows - j - 1; ++i) {
				currentMax = std::max(currentMax, get(j, i));
			}
		}
		break;
	case 3:
		for (int i = rows / 2 + 1; i < rows; ++i) {
			for (int j = columns - i; j < i; ++j) {
				currentMax = std::max(currentMax, get(j, i));
			}
		}
		break;
	case 4:
		for (int j = columns / 2; j < columns; ++j) {
			for (int i = rows - j; i < j; ++i) {
				currentMax = std::max(currentMax, get(j, i));
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
				if (get(j, i) == currentMax)
					std::cout << "(" << j << ", " << i << ")\n";
			}
		}
		break;
	case 2:
		for (int j = 0; j < columns / 2; ++j) {
			for (int i = j + 1; i < rows - j - 1; ++i) {
				if (get(j, i) == currentMax)
					std::cout << "(" << j << ", " << i << ")\n";
			}
		}
		break;
	case 3:
		for (int i = rows / 2 + 1; i < rows; ++i) {
			for (int j = columns - i; j < i; ++j) {
				if (get(j, i) == currentMax)
					std::cout << "(" << j << ", " << i << ")\n";
			}
		}
		break;
	case 4:
		for (int j = columns / 2; j < columns; ++j) {
			for (int i = rows - j; i < j; ++i) {
				if (get(j, i) == currentMax)
					std::cout << "(" << j << ", " << i << ")\n";
			}
		}
		break;
	}
}
