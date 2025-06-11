#include "functions.h"


void EnterChoice(int32_t& choice) {
	std::cout << "enter choice to sort \n[1]qsort\n[2]vstavkoy\n[3]vybora\n[4]sliyanie\n[5]bubble\n[6]lol : \n";
	std::cin >> choice;
}
void EnterOrder(int32_t& order) {
	std::cout << "enter choice to order \n[1]up\n[2]down : \n";
	std::cin >> order;
}
void EnterStream(int32_t& stream) {
	std::cout << "enter choice to stream \n[1]file\n[2]console : \n";
	std::cin >> stream;
}
void EnterSize(int32_t& size) {
	std::cout << "enter size of array : \n";
	std::cin >> size;
}
void CheckInputFile(std::istream& fin) {
	if (!fin.good()) {
		throw "file isnt exist\n";
	}
	if (!fin) {
		throw "input file error\n";
	}
	if (fin.peek() == EOF) {
		throw "file is empty\n";
	}
}

void CheckOutputFile(std::ofstream& fout) {
	if (!fout.good()) {
		throw "file isnt exist\n";
	}
	if (!fout) {
		throw "output file error\n";
	}
}

int32_t FindCounter(std::istream& fin) {
	int32_t counter{};
	double numb{};
	while (fin >> numb) {
		++counter;
	}
	return counter;
}

void FillArrayFromFile(std::istream& fin, double* array, int32_t size) {
	fin.clear();
	fin.seekg(0);
	for (int32_t i{}; i < size; ++i) {
		fin >> array[i];
	}
}
void FillArrayFromConsole(double* array, int32_t size) {
	for (int32_t i{}; i < size; ++i) {
		std::cin >> array[i];
	}
}

void OutputArray(std::ostream& fout, double* array, int32_t size) {
	for (int32_t i{}; i < size; ++i) {
		fout << array[i] << ' ';
	}
	fout << '\n';
}

int CompareUp(const void* el1, const void* el2) {
	return *((double*)el1) - *((double*)el2);
}

int CompareDown(const void* el1, const void* el2) {
	return *((double*)el2) - *((double*)el1);
}

void QsortArrayUp(double* array, int32_t size) {
	std::qsort(array, size, sizeof(double), CompareUp);
}

void QsortArrayDown(double* array, int32_t size) {
	std::qsort(array, size, sizeof(double), CompareDown);
}


void SortInsertionUp(double* array, int32_t size) {
	for (int32_t i{1}; i < size; i++)
		for (int j = i; j > 0; --j) {
			if(array[j - 1] > array[j]){
				std::swap(array[j - 1], array[j]);
			}
		}
}
void SortInsertionDown(double* array, int32_t size) {
	for (int32_t i{1}; i < size; i++)
		for (int j = i; j > 0; --j) {
			if (array[j - 1] < array[j]) {
				std::swap(array[j - 1], array[j]);
			}
		}
}

void SelectionSortUp(double* array, int32_t size){
	for(int32_t i{}; i < size;++i){
		int32_t min_index = i;
		for (int32_t j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		std::swap(array[i], array[min_index]);
	}
}
void SelectionSortDown(double* array, int32_t size) {
	for (int32_t i{}; i < size; ++i) {
		int32_t min_index = i;
		for (int32_t j = i + 1; j < size; j++)
		{
			if (array[j] > array[min_index])
			{
				min_index = j;
			}
		}
		std::swap(array[i], array[min_index]);
	}
}

void BubbleSortUp(double* array, int32_t size){
	bool flag = true;
	while(flag) {
		for (int32_t i{}; i < size - 1; ++i) {
			if (array[i] > array[i + 1]) {
				flag = false;
				std::swap(array[i], array[i + 1]);
			}
		}
		if (flag) {
			break;
		}
		flag = true;
	}
}
void BubbleSortDown(double* array, int32_t size) {
	bool flag = true;
	while (flag) {
		for (int32_t i{}; i < size - 1; ++i) {
			if (array[i] < array[i + 1]) {
				flag = false;
				std::swap(array[i], array[i + 1]);
			}
		}
		if (flag) {
			break;
		}
		flag = true;
	}
}

int32_t CountOfDigitsAfterPoint(double el) {
	int32_t temp(static_cast<int32_t>(el));
	int32_t count_of_int{};
	int32_t count_of_real{};
	
	count_of_int = FindCountOfDigits(temp);

	int64_t new_el{ static_cast<int64_t>(el * pow(10, 7)) };
	int64_t reverse{};
	while (new_el)
	{
		reverse = reverse * 10 + new_el % 10;
		new_el /= 10;
	}

	count_of_real = FindCountOfDigits(reverse);
	return count_of_real - count_of_int;
}

int32_t FindCountOfDigits(int64_t numb) {
	int32_t count{};
	while (numb != 0) {
		numb /= 10;
		++count;
	}
	return count;
}
int CompareUpSpecial(const void* el1, const void* el2) {
	return CountOfDigitsAfterPoint(*((double*)el1)) - CountOfDigitsAfterPoint(*((double*)el2));
}

int CompareDownSpecial(const void* el1, const void* el2) {
	return CountOfDigitsAfterPoint(*((double*)el2)) - CountOfDigitsAfterPoint(*((double*)el1));
}

void QsortArrayUpSpecial(double* array, int32_t size) {
	std::qsort(array, size, sizeof(double), CompareUpSpecial);
}

void QsortArrayDownSpecial(double* array, int32_t size) {
	std::qsort(array, size, sizeof(double), CompareDownSpecial);
}





void DoMergeUp(double* array, int32_t low, int32_t mid, int32_t high) {
	int32_t index_left{};
	int32_t index_right{};
	int32_t index_new{low};
	int32_t size_left{ mid - low + 1 };
	int32_t size_right{ high - mid };

	double*  array_left = new double[size_left];
	double* array_right = new double[size_right];

	for (int32_t k = 0; k < size_left; k++) {
		array_left[k] = array[low + k];
	}
	for (int32_t l = 0; l < size_right; l++) {
		array_right[l] = array[mid + 1 + l];
	}

	while (index_left < size_left && index_right < size_right) {
		if (array_left[index_left] <= array_right[index_right]) {
			array[index_new] = array_left[index_left];
			index_left++;
		}
		else {
			array[index_new] = array_right[index_right];
			index_right++;
		}
		index_new++;
	}

	while (index_left < size_left) {
		array[index_new] = array_left[index_left];
		index_new++;
		index_left++;
	}
	while (index_right < size_right) {
		array[index_new] = array_right[index_right];
		index_right++;
		index_new++;
	}
	delete[]array_left;
	delete[]array_right;
}
void MergeSortUp(double* arr, int32_t low, int32_t high) {
	int32_t mid{ (low + high) / 2 };
	if (low < high) {
		MergeSortUp(arr, low, mid);
		MergeSortUp(arr, mid + 1, high);

		DoMergeUp(arr, low, mid, high);
	}
}



void DoMergeDown(double* array, int32_t low, int32_t mid, int32_t high) {
	int32_t index_left{};
	int32_t index_right{};
	int32_t index_new{ low };
	int32_t size_left{ mid - low + 1 };
	int32_t size_right{ high - mid };

	double* array_left = new double[size_left];
	double* array_right = new double[size_right];

	for (int32_t k = 0; k < size_left; k++) {
		array_left[k] = array[low + k];
	}
	for (int32_t l = 0; l < size_right; l++) {
		array_right[l] = array[mid + 1 + l];
	}

	while (index_left < size_left && index_right < size_right) {
		if (array_left[index_left] >= array_right[index_right]) {
			array[index_new] = array_left[index_left];
			index_left++;
		}
		else {
			array[index_new] = array_right[index_right];
			index_right++;
		}
		index_new++;
	}

	while (index_left < size_left) {
		array[index_new] = array_left[index_left];
		index_new++;
		index_left++;
	}
	while (index_right < size_right) {
		array[index_new] = array_right[index_right];
		index_right++;
		index_new++;
	}
	delete[]array_left;
	delete[]array_right;
}
void MergeSortDown(double* arr, int32_t low, int32_t high) {
	int32_t mid{ (low + high) / 2 };
	if (low < high) {
		MergeSortDown(arr, low, mid);
		MergeSortDown(arr, mid + 1, high);

		DoMergeDown(arr, low, mid, high);
	}
}
