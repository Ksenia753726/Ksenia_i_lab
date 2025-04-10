#include "Header.h"


int main() {
	int32_t degree{};
	InputDegree(degree);
	try {
		if (degree <= 0) {
			throw std::invalid_argument("wrong degree\n");
		}
	int32_t** mtr = nullptr;
	CreateArray(mtr, degree);
	FillPascalTriangle(mtr, degree);
	PrintPascalTriangle(mtr, degree);

	DeleteArray(mtr,degree);
	}
	catch (std::invalid_argument error) {
		std::cout << error.what();
	}
	return 0;
}