#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <ranges>

class Matrix {
public:
	Matrix();
	Matrix(size_t rows, size_t cols);
	Matrix(const Matrix& other);

	inline void setRows(size_t _rows) { rows =_rows; }
	inline void setColumns(size_t _cols) { columns =_cols; }

	inline size_t getRows() const { return rows; }
	inline size_t getColumns() const { return columns; }

	void fillWithRandom();
	void printMaxElements(int sector);

	int get(size_t x, size_t y) const;
	int& getRef(size_t x, size_t y);

private:
	std::vector<int> data;
	
	size_t rows, columns;

};

void Print(const Matrix& m);