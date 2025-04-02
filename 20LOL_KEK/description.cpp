#include "functions.h"

void InputSize(int32_t& size) {
	std::cout << "enter size of array\n";
	std::cin >> size;
}

void EnterChoice(int32_t& choice) {
	std::cout << "enter choice to fill array\n[1]Fill array by random\n[2]Fill array by hand\n";
	std::cin >> choice;
}

void EnterLowBorder(double& low_brdr) {
	std::cout << "enter low border\n";
	std::cin >> low_brdr;
}


void EnterHightBorder(double& hight_brdr) {
	std::cout << "enter hight border\n";
	std::cin >> hight_brdr;
}


void PrintArray(double* array, int32_t size) {
	std::cout << "your array : \n";
	for (int32_t i{}; i < size; ++i) {
		std::cout << array[i] << ' ';
	}
}

void CreateArray(double*& array, int32_t size) {
	array = new double[size];
}

void FillArrayRandom(double* array, int32_t size,double low_brdr,double hight_brdr) {
	srand(time(NULL));
	for (size_t i{}; i < size; ++i) { 
		array[i] = low_brdr + static_cast<double>(rand() / (static_cast<double>(RAND_MAX / (hight_brdr - low_brdr))));
	}

}
void FillArrayByHand(double* array, int32_t size) {
	for (size_t i{}; i < size; ++i) {
		std::cin >> array[i];
	}
}

void DeleteArray(double*& array) {
	delete[] array;
}


int32_t CounterOfWrongNumbers(double* array, int32_t size, double low, double hight) {
	int32_t counter{};
	for (int32_t i{}; i < size; ++i) {
		if (array[i] >= low && array[i] <= hight) {
			++counter;
		}
	}
	return counter;
}

void SqueezeArray(double* array, int32_t size, double low , double hight) {
	for(int32_t j{ 0 }; j < CounterOfWrongNumbers(array,size,low,hight); ++j) {
		for (int32_t i{0}; i < size - 1; ++i) {
			if (array[i] >= low && array[i] <= hight) {
				Swap(array[i], array[i + 1]);
			}
		}
	}
	ChangeWrongNumbersToNull(array,size,low, hight);
}
void ChangeWrongNumbersToNull(double* array, int32_t size, double low, double hight) {
	for (int32_t i{ 0 }; i < size; ++i) {
		if (array[i] >= low && array[i] <= hight) {
			array[i] = 0;
		}
	}
}

int32_t AmountUpElement(double* array, int32_t size,int32_t index) {
	int32_t amount_up{};
	for (int32_t i{}; i < size; ++i) {
		if (array[i] > array[index]) {
			amount_up += array[i];
		}
	}
	return amount_up;
}

int32_t AmountAfterElement(double* array, int32_t size, int32_t index) {
	int32_t amount_after{};
	for (int32_t i{}; i < size; ++i) {
		if (array[i] < array[index]) {
			amount_after += array[i];
		}
	}
	return amount_after;
}

int32_t FindIndexOfMinimumDifference(double* array, int32_t size) {
	int32_t min_index{1};
	int32_t min_differense{AmountAfterElement(array, size, 1) - AmountUpElement(array,size,1)};
	int32_t difference{};
	for (int32_t i{2}; i < size - 1; ++i) {
		difference = AmountAfterElement(array, size, i) - AmountUpElement(array, size, i);
		if (min_differense > difference) {
			min_differense = difference;
			min_index = i;
		}
	}
	return min_index;
}


double FindMaxElement(double* array, int32_t size) {
	double max_element{abs(array[0])};
	for (int32_t i{}; i < size; ++i) {
		if (abs(max_element) < abs(array[i])) {
			max_element = array[i];
		}
	}
	return max_element;
}

int32_t FindIndexOfMaxElement(double* array, int32_t size) {
	double max_element{ abs(array[0]) };
	int32_t index_max_element{};
	for (int32_t i{}; i < size; ++i) {
		if (abs(max_element) < abs(array[i])) {
			max_element = array[i];
			index_max_element = i;
		}
	}
	return index_max_element;
}