#include "functions.h"

int main() {
	std::ifstream fin("in.txt");

	try {
		CheckInputFile(fin);

		std::ofstream fout("in.txt", std::ios::app);
		CheckOutputFile(fout);
		
		int32_t size{ FindCounter(fin) };
		double* array = new double[size];

		int32_t stream_in{};
		EnterStream(stream_in);

		int32_t choice{};
		EnterChoice(choice);

		int32_t order{};
		EnterOrder(order);
		switch (stream_in) {
		case 1:
			FillArrayFromFile(fin, array, size);
			break;
		case 2:
			EnterSize(size);
			std::cout << "fill your array :\n";
			FillArrayFromConsole(array, size);
			break;
		default:
			std::cout << "dont know this way\n";
			break;
		}
		switch (order) {
		case 1:
			switch (choice) {
			case 1:
				QsortArrayUp(array, size);
				break;
			case 2:
				SortInsertionUp(array, size);
				break;
			case 3:
				SelectionSortUp(array, size);
				break;
			case 4:
				MergeSortUp(array, 0, size - 1);
				break;
			case 5:
				BubbleSortUp(array, size);
				break;
			case 6:
				QsortArrayUpSpecial(array, size);
				break;
			default:
				std::cout << "dont know this choice\n";
				break;
			}
			break;
		case 2:
			switch (choice) {
			case 1:
				QsortArrayDown(array, size);
				break;
			case 2:
				SortInsertionDown(array, size);
				break;
			case 3:
				SelectionSortDown(array, size);
				break;
			case 4:
				MergeSortDown(array, 0, size - 1);
				break;
			case 5:
				BubbleSortDown(array, size);
				break;
			case 6:
				QsortArrayDownSpecial(array, size);
				break;
			default:
				std::cout << "dont know this choice\n";
				break;
			}
			break;
		default:
			std::cout << "dont know this order\n";
			break;
		}
		/*switch (choice) {
		case 1 :
			QsortArrayUp(array, size);
			break;
		case 2 :
			SortInsertionDown(array, size);
			break;
		case 3 :
			SelectionSortDown(array, size);
			break;
		case 4 :
			MergeSortDown(array, 0, size - 1);	
			break;
		case 5 :
			BubbleSortDown(array, size);
			break;
		case 6 :
			QsortArrayDownSpecial(array, size);
			break;
		default :
			std::cout << "dont know this choice";
			break;
		}*/
		int32_t stream_out{};
		EnterStream(stream_out);

		switch (stream_out) {
		case 1:
			OutputArray(fout, array, size);
			break;
		case 2:
			OutputArray(std::cout, array, size);
			break;
		default:
			std::cout << "dont know this way\n";
			break;
		}
		fin.close();
		fout.close();
		std::cout << "your data was recorded\n";


	}
	catch (const char* m) {
		std::cout << m;
	}
	return 0;
}