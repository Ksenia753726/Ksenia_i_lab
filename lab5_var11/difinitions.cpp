#include "functions.h"


void EnterAmountColsAndRows(int32_t& n) {
	std::cout << "Enter Amount Cols And Rows: ";
	std::cin >> n;
}

void CreateMatrix(int32_t**& mtr, int32_t n) {
	mtr = new int32_t * [n];
	for (int32_t i{}; i < n; ++i) {
		mtr[i] = new int32_t[n];
	}
}
void DeleteMatrix(int32_t**& mtr, int32_t n) {
	for (int32_t i{}; i < n; ++i) {
		delete[] mtr[i];
	}
	delete[] mtr;
}


void MakeAllZero(int32_t**& mtr, int32_t n) {
	for (int32_t i{}; i < n; ++i) {
		for (int32_t j{}; j < n; ++j) {
			mtr[i][j] = 0;
		}
	}
}

void PrintMatrix(int32_t** mtr, int32_t n) {
	for (int32_t i{}; i < n; ++i) {
		for (int32_t j{}; j < n; ++j) {
			std::cout << mtr[i][j] << std::setw(6);
		}
		std::cout << '\n';
	}
}

void FillMatrixBySpiral(int32_t**& mtr, int32_t n, int32_t row_cntr, int32_t col_cntr) {
    int32_t cycle{1};
    int32_t value{ 1 };

    while (cycle < n) {
        for (int32_t up{}; up < cycle; ++up) {
            
            mtr[row_cntr][col_cntr] = value++;
            --row_cntr;
        }
        for (int32_t rght{}; rght < cycle; ++rght) {
           mtr[row_cntr][col_cntr] = value++;
            ++col_cntr;
        }
        ++cycle;
        for (int32_t down{}; down < cycle; ++down) {
           
           mtr[row_cntr][col_cntr] = value++;
            ++row_cntr;
        }
        for (int32_t lft{}; lft < cycle; ++lft) {
           
           mtr[row_cntr][col_cntr] = value++;
            --col_cntr;
        }
        ++cycle;
    }

    for (int32_t last{}; last < cycle; ++last) {
        
       mtr[row_cntr][col_cntr] = value++;
        --row_cntr;
    }
}

int32_t SumOfElementsOfLowerRightTriangle(int32_t** mtr, int32_t n) {
    int32_t sum{};
    for (int32_t i{}; i < n; ++i) {
        for (int32_t j{n - i - 1}; j < n; ++j) {
            sum += mtr[i][j];
        }
    }

    return sum;
}
