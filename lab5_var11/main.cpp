#include "functions.h"
int main() {
    int32_t** mtr = nullptr;

    int32_t n{};
    EnterAmountColsAndRows(n);
    try {
        if (n % 2 == 0) {
            throw "it can't be fill by spiral";
        }
        if (n <= 0) {
            throw "wrong argument";
        }
        CreateMatrix(mtr, n);

        int32_t row_cntr = n / 2;
        int32_t col_cntr = n / 2;
        MakeAllZero(mtr, n);
        FillMatrixBySpiral(mtr, n, row_cntr, col_cntr);
        PrintMatrix(mtr, n);

        std::cout << "Sum of elements of lower right triangle: " << SumOfElementsOfLowerRightTriangle(mtr, n) << '\n';

        DeleteMatrix(mtr, n);
        system("pause");
    }
    catch (const char* e) {
        std::cout << e;
    }
    return 0;
}