#include "functions.h"

void InputSize(int32_t& size) {
	std::cout << "enter size of array\n";
	std::cin >> size;
}

void EnterChoice(int32_t& choice) {
	std::cout << "enter choice to fill array\n[1]Fill array by random\n[2]Fill array by hand\n";
	std::cin >> choice;
}

void EnterLowBorder(int32_t& low_brdr) {
	std::cout << "enter low border\n";
	std::cin >> low_brdr;
}

void EnterHightBorder(int32_t& hight_brdr) {
	std::cout << "enter hight border\n";
	std::cin >> hight_brdr;
}

void SwapBorders(int32_t& low_b, int32_t& hight_b) {
	if (low_b > hight_b) {
		Swap(low_b, hight_b);
	}
}

void CreateArray(int32_t*& array, int32_t size) {
	array = new int32_t[size];
}

void FillArrayRandom(int32_t* array, int32_t size,int32_t hight_brdr,int32_t low_brdr) {
	srand(time(NULL));
	for (size_t i{}; i < size; ++i) {  
		array[i] = low_brdr + rand() % (hight_brdr - low_brdr + 1);
	}

}
void FillArrayByHand(int32_t* array, int32_t size) {
	for (size_t i{}; i < size; ++i) {
		std:: cin >> array[i] ;
	}
}

void SortArray(int32_t* array, int32_t size) {
	int32_t all_good{1};
	while (all_good == 1) {
		all_good = 0;
		for (int32_t i{ 1 }; i < size; ++i) {
			if (array[i] % 2 == 0 && array[i - 1] % 2 != 0) {
				Swap(array[i - 1], array[i]);
				all_good = 1;
			}
		}
	}
}

void PrintArray(int32_t* array, int32_t size) {
	std::cout << "your sorted array : \n";
	for (int32_t i{}; i < size; ++i) {
		std::cout << array[i] << ' ';
	}
}

void DeleteArray(int32_t*& array) {
	delete[] array;
}

int32_t CountOfChangesOfSign(int32_t* array, int32_t size) {
	int32_t counter{};
	for (int32_t i{1}; i < size; ++i) {
		if ((array[i] > 0 && array[i - 1] < 0) || (array[i] < 0 && array[i - 1] > 0)) {
			++counter;
		}
	}
	return counter;
}

int32_t FindIndexOfFirstNull(int32_t* array, int32_t size) {
	int32_t indx_frst_nll{-1};
	for (int32_t i{}; i < size; ++i) {
		if (array[i] == 0) {
			indx_frst_nll = i;
			break;
		}
	}
	return indx_frst_nll;
}
int32_t FindIndexOfSecondNull(int32_t* array, int32_t size) {
	int32_t indx_scnd_nll{-1};
	for (int32_t i{FindIndexOfFirstNull(array,size) + 1}; i < size; ++i) {
		if (array[i] == 0) {
			indx_scnd_nll = i;
			break;
		}
	}
	return indx_scnd_nll;
}

int32_t ÑompositionElementsBetweenNulls(int32_t* array, int32_t size) {
	int32_t composition{1};
	
	for (int32_t i{}; i < size; ++i) {
		if (i > FindIndexOfFirstNull(array, size) && i < FindIndexOfSecondNull(array, size)) {
			composition *= array[i];
		}
	}
	return composition;
}