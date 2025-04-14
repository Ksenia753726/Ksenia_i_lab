#include "functions.h"

void EnterRows(int32_t& rows) {
	std::cout << "Enter rows: ";
	std::cin >> rows;
}
void EnterCols(int32_t& cols) {
	std::cout << "Enter cols: ";
	std::cin >> cols;
}

void FillMatrix(int32_t**& mtr, int32_t rows, int32_t cols) {
	for (int32_t i{}; i < rows; ++i) {
		for (int32_t j{}; j < cols; ++j) {
			std::cin >> mtr[i][j];
		}
	}
}
void CreateMatrix(int32_t**& mtr, int32_t rows, int32_t cols) {
	mtr = new int32_t * [rows];
	for (int32_t i{}; i < rows; ++i) {
		mtr[i] = new int32_t[cols];
	}
}
void DeleteMatrix(int32_t**& mtr, int32_t rows) {
	for (int32_t i{}; i < rows; ++i) {
		delete[] mtr[i];
	}
	delete[] mtr;
}

void MultiplayOfMatrixs(int32_t** mtr1, int32_t rows1, int32_t cols1, int32_t** mtr2, int32_t cols2, int32_t**& mtr_new) {
	for (int32_t i{}; i < rows1; ++i) {
		for (int32_t j{}; j < cols2; ++j) {
			mtr_new[i][j] = 0;
			for (int32_t s{}; s < cols1; ++s) {
				mtr_new[i][j] += mtr1[i][s] * mtr2[s][j];
			}
		}
	}
}

void MakeAllZero(int32_t**& mtr_new, int32_t rows1, int32_t cols2) {
	for (int32_t i{}; i < rows1; ++i) {
		for (int32_t j{}; j < cols2; ++j) {
			mtr_new[i][j] = 0;
		}
	}
}

void PrintMatrix(int32_t**& mtr_new, int32_t rows1, int32_t cols2) {
	for (int32_t i{}; i < rows1; i++) {
		for (int32_t j{}; j < cols2; ++j) {
			std::cout << mtr_new[i][j] << std::setw(6);
		}
		std::cout << '\n';
	}
}