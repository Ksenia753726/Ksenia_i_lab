#include "functions.h"
int main() {
	int32_t choice{};

	int32_t rand_low_bord{};
	int32_t rand_hight_bord{};

	int32_t size{};
	InputSize(size);
	try {
		if (size <= 0) {
			throw "invalid size\n";
		}
		int32_t* array = nullptr;
		CreateArray(array, size);

		EnterChoice(choice);

		switch (choice) {
		case 1 :
			EnterLowBorder(rand_low_bord);
			EnterHightBorder(rand_hight_bord);
			SwapBorders(rand_low_bord, rand_hight_bord);
			FillArrayRandom(array, size, rand_hight_bord, rand_low_bord);

			SortArray(array, size);

			PrintArray(array, size);
			std::cout << std::endl;

			std::cout << "count of changes of sign in array : " << CountOfChangesOfSign(array, size) << '\n';

			try {
				if (FindIndexOfFirstNull(array, size) == -1) {
					throw "there is no nulls";
				}
				if (FindIndexOfSecondNull(array, size) == -1) {
					throw "there is no second null";
				}
				if (FindIndexOfSecondNull(array, size) - FindIndexOfFirstNull(array, size) == 1) {
					throw "no space between nulls";
				}
				std::cout << "Ñomposition elements between nulls : " << ÑompositionElementsBetweenNulls(array, size);
			}
			catch (const char* e) {
				std::cout << e;
			}
			break;
		case 2 :
			FillArrayByHand(array, size);

			SortArray(array, size);

			PrintArray(array, size);
			std::cout << std::endl;

			std::cout << "count of changes of sign in array : " << CountOfChangesOfSign(array, size) << '\n';

			try {
				if (FindIndexOfFirstNull(array, size) == -1) {
					throw "there is no nulls";
				}
				if (FindIndexOfSecondNull(array, size) == -1) {
					throw "there is no second null";
				}
				if (FindIndexOfSecondNull(array, size) - FindIndexOfFirstNull(array, size) == 1) {
					throw "no space between nulls";
				}
				std::cout << "Ñomposition elements between nulls : " << ÑompositionElementsBetweenNulls(array, size);
			}
			catch (const char* e) {
				std::cout << e;
			}
			break;
		default:
			std::cout << "bad choice";
			break;
		}
			
	}
		catch (std::invalid_argument e) {
			std::cout << e.what();
		}
	return 0;
}