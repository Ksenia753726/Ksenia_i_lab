#include "functions.h"

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::ifstream fin("in.txt");

	try {
		CheckInputFile(fin);

		std::ofstream fout("in.txt", std::ios::app);
		CheckOutputFile(fout);
		int32_t amount_of_students{ FindCounter(fin) };
		Student* students = new Student[amount_of_students];

		FillStudents(fin, students, amount_of_students);
		int32_t flag{ 1 };
		while (flag) {
			int32_t choice{};
			EnterChoice(choice);

			char name[30];
			double average_mark[5];
			int32_t index_st_wth_name{};
			switch (choice) {
			case 1:
				QsortArrayUpName(students, amount_of_students);
				fout << std::endl << "sorted list of students : \n";
				for (int32_t i{}; i < amount_of_students; ++i) {
					fout << students[i].name << ';' << students[i].group << ';' << students[i].grade << '\n';
				}
				std::cout << "file was recorded\n";
				break;
			case 2:
				std::cout << "Enter name of student that you want to find :\n";
				std::cin.ignore();
				std::cin.getline(name, 30);
				index_st_wth_name = FindStudentIndexByName(students, amount_of_students, name);
				std::cout << "info of this student : " << students[index_st_wth_name].name << ';' << students[index_st_wth_name].group << ';' << students[index_st_wth_name].grade << '\n';
				break;
			case 3:
				QsortArrayUpGroup(students, amount_of_students);
				for (int32_t i{}; i < amount_of_students; ++i) {
					std::cout << students[i].name << ';' << students[i].group << ';' << students[i].grade << '\n';
				}
				break;
			case 4:
				FillAverageMarks(students, amount_of_students, average_mark);
				for (int32_t i{}; i < 5; ++i) {
					if (average_mark[i] == 0) {
						continue;
					}
					else {
						std::cout << "average mark of " << i + 1 << " group :" << average_mark[i] << '\n';
					}
				}
				break;
			default:
				std::cout << "i dont know this problem!\n";
				break;

			}
			std::cout << "would you like to continue\n[0]no\[1]yes :\n";
			std::cin >> flag;
		}
	}
	catch (const char* m) {
		std::cout << m;
	}
	return 0;
}