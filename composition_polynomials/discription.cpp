#include "functions.h"

void InputDegree(int32_t& degree) {
	std::cout << "enter degree of polinomialis\n";
	std::cin >> degree;
}

void CreateArray(int32_t*& array, int32_t degree) {
	array = new int32_t [degree];
	
}

void DeleteArray(int32_t*& array, int32_t degree) {
	delete[] array;
}

void FillArrayByHand(int32_t* array, int32_t size) {
	std::cout << "fill array:\n";
	for (int32_t i{}; i < size; ++i) {
		std::cin >> array[i];
	}
}

void FillComposition(int32_t*& coefficients, int32_t degree, int32_t*& coef_f, int32_t degree_f, int32_t*& coef_s, int32_t degree_s) {
	TurnAllElementsInNulls(coefficients, degree);
	for (int32_t i{}; i < degree_f; ++i) {
		for (int32_t j{}; j < degree_s; ++j) {
			coefficients[i + j] += coef_f[i] * coef_s[j];
		}
	}
}

void TurnAllElementsInNulls(int32_t*& coefficients, int32_t degree) {
	for (int32_t i{}; i < degree; ++i) {
		coefficients[i] = 0;
	}

}

void PrintPolynomian(int32_t* coefficients, int32_t degree) {
	for (int32_t i{}; i < degree; ++i) {
		std::cout << coefficients[i] << "x^" << i;
		if (i != degree - 1) {
			std::cout << " + ";
		}
	}
}