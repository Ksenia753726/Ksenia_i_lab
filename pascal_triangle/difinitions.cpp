#include "Header.h"

void InputDegree(int32_t& degree) {
	std::cout << "enter degree of matrix\n";
	std::cin >> degree;
}

void CreateArray(int32_t**& array, int32_t degree) {
	array = new int32_t*[degree];
	for (int32_t i{}; i < degree; ++i) {
		array[i] = new int32_t [degree];
	}
}

void DeleteArray(int32_t**& array, int32_t degree) {
	for (int32_t i{}; i < degree; ++i) {
		delete[] array[i];
	}
	delete[] array;
}

void FillPascalTriangle(int32_t**& mtr, int32_t degree) {
	mtr[0][0] = 1;

	for (int32_t i{ 1 }; i < degree; ++i) {
		mtr[i][0] = 1;
		mtr[i][i] = 1;

		for (int32_t j{ 1 }; j < i; ++j) {
			mtr[i][j] = mtr[i - 1][j - 1] + mtr[i - 1][j];
		}
		
	}
}

void PrintPascalTriangle(int32_t**& mtr, int32_t degree) {
	for (int32_t i{}; i < degree; ++i) {
		for (int32_t j{}; j <= i; ++j) {
			std::cout << std::setw(6) << mtr[i][j];
		}
		std::cout << std::endl;
	}
}