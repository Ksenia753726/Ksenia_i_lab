#include "functions.h"

int main() {
	int32_t choice{};

	int32_t size{};
	InputSize(size);

	double low_border{};
	double hight_border{};

	double rand_low_bord{};
	double rand_hight_bord{};

	try {
		if (size <= 0) {
			throw std::invalid_argument("invalid size\n");
		}

		double* array = nullptr;
		CreateArray(array, size);

		EnterChoice(choice);
		switch (choice) {
		case 1:
			EnterLowBorder(rand_low_bord);
			EnterHightBorder(rand_hight_bord);
			if (rand_low_bord > rand_hight_bord) {
				Swap(rand_low_bord,rand_hight_bord);
			}
			try {
				if (rand_low_bord == rand_hight_bord) {
					throw std::logic_error("logic error");
				}
				FillArrayRandom(array, size, rand_low_bord, rand_hight_bord);
				PrintArray(array, size);
				std::cout << std::endl;

				std::cout << "Index of element with minimum amount difference : " << FindIndexOfMinimumDifference(array, size) << '\n';

				std::cout << "the maximum modulo element : " << FindMaxElement(array, size) << '\n';
				std::cout << "its index : " << FindIndexOfMaxElement(array, size) << '\n';

				EnterLowBorder(low_border);
				EnterHightBorder(hight_border);
				if (low_border > hight_border) {
					Swap(low_border, hight_border);
				}
				try {
					if (low_border == hight_border) {
						throw std::logic_error("logic error");
					}
					SqueezeArray(array, size, low_border, hight_border);

					PrintArray(array, size);
				}
				catch (std::logic_error e) {
					std::cout << e.what();
				}
			}
			catch (std::logic_error e) {
				std::cout << e.what();
			}
			break;
		case 2:
			FillArrayByHand(array, size);
			std::cout << std::endl;

			std::cout << "Index of element with minimum amount difference : " << FindIndexOfMinimumDifference(array, size) << '\n';

			std::cout << "the maximum modulo element : " << FindMaxElement(array, size) << '\n';
			std::cout << "its index : " << FindIndexOfMaxElement(array, size) << '\n';

			EnterLowBorder(low_border);
			EnterHightBorder(hight_border);
			if (low_border > hight_border) {
				Swap(low_border, hight_border);
			}
			try {
				if (low_border == hight_border) {
					throw std::logic_error("logic error");
				}
				SqueezeArray(array, size, low_border, hight_border);

				PrintArray(array, size);
			}
			catch (std::logic_error e) {
				std::cout << e.what();
			}
			break;
		default:
			std::cout << "bad choice";
			break;
		}

		//std::cout << std::endl;

		//std::cout << "Index of element with minimum amount difference : " << FindIndexOfMinimumDifference(array, size) << '\n';

		//std::cout << "the maximum modulo element : " << FindMaxElement(array, size) << '\n';
		//std::cout << "its index : " << FindIndexOfMaxElement(array, size) << '\n';

		//EnterLowBorder(low_border);
		//EnterHightBorder(hight_border);
		//if (low_border > hight_border) {
		//	Swap(low_border, hight_border);
		//}
		//try {
		//	if (low_border == hight_border) {
		//		throw std::logic_error("logic error");
		//	}
		//	SqueezeArray(array, size, low_border, hight_border);

		//	PrintArray(array, size);
		//}
		//catch (std::logic_error e) {
		//	std::cout << e.what();
		//}
	}
	catch (std::invalid_argument e) {
		std::cout << e.what();
	}

	return 0;
}