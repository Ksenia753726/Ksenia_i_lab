#include "functions.h"

int main() {
	int32_t degree_first{};
	InputDegree(degree_first);

	int32_t degree_second{};
	InputDegree(degree_second);

	try {
		if (degree_first <= 0 || degree_second <= 0) {
			throw std::invalid_argument("wrong degree\n");
		}
		int32_t* coefficients_first = nullptr;
		CreateArray(coefficients_first, degree_first);
		FillArrayByHand(coefficients_first, degree_first);


		int32_t* coefficients_second = nullptr;
		CreateArray(coefficients_second, degree_second);
		FillArrayByHand(coefficients_second, degree_second);

		int32_t* coefficients_new = nullptr;
		int32_t degree_new{ degree_first + degree_second - 1 };
		CreateArray(coefficients_new, degree_new);
		FillComposition(coefficients_new, degree_new, coefficients_first, degree_first, coefficients_second, degree_second);
		PrintPolynomian(coefficients_new, degree_new);

		DeleteArray(coefficients_first, degree_first);
		DeleteArray(coefficients_second, degree_second);
		DeleteArray(coefficients_new, degree_new);
	}
	catch (std::invalid_argument error) {
		std::cout << error.what();
	}

	return 0;
}