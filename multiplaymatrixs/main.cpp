#include "functions.h"

int main() {
	int32_t** mtr_first = nullptr;
	int32_t rows_first{};
	int32_t cols_first{};
	EnterRows(rows_first);
	EnterCols(cols_first);
	CreateMatrix(mtr_first, rows_first, cols_first);
	FillMatrix(mtr_first, rows_first, cols_first);

	int32_t** mtr_second = nullptr;
	int32_t cols_second{};
	EnterCols(cols_second);
	CreateMatrix(mtr_second, cols_first, cols_second);
	FillMatrix(mtr_second, cols_first, cols_second);

	int32_t** mtr_new = nullptr;
	CreateMatrix(mtr_new, rows_first, cols_second);
	MultiplayOfMatrixs(mtr_first, rows_first, cols_first, mtr_second, cols_second, mtr_new);

	PrintMatrix(mtr_new, rows_first, cols_second);


	DeleteMatrix(mtr_first, rows_first);
	DeleteMatrix(mtr_second, cols_first);
	DeleteMatrix(mtr_new, rows_first);

	return 0;
}