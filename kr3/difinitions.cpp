#include "functions.h"

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

void EnterChoice(int32_t& choice) {
	std::cout << "Enter your problem \n[1]Отсортировать студентов по фамилиям\n[2]Найти запись о студенте по его фамилии\n[3]Отсортировать студентов по группам\n[4]вывести отчет о среднем балле по группам :\n";
	std::cin >> choice;
}

int32_t FindCounter(std::istream& fin) {
	int32_t counter{};
	std::string str;
	while (getline(fin,str)) {
		++counter;
	}
	return counter;
}

void FillStudents(std::istream& fin, Student* students, int32_t amount_of_students) {
	fin.clear();
	fin.seekg(0);

	char group[30];
	char grade[30];
	int32_t i{};
	while (fin.good()) {
		fin.getline(students[i].name, 30, ';');
		fin.getline(group, 30, ';');
		students[i].group = atoi(group);
		fin.getline(grade, 30);
		students[i].grade = atof(grade);
		++i;
	}
}

char FindFirstLetter(Student students) {
	return *students.name;
}
int CompareUpName(const void* el1, const void* el2) {
	return FindFirstLetter (*((Student*)el1)) - FindFirstLetter(*((Student*)el2));
}
void QsortArrayUpName(Student* students, int32_t amount_of_students) {
	std::qsort(students, amount_of_students, sizeof(Student), CompareUpName);
}

int32_t FindStudentIndexByName(Student* students, int32_t amount_of_students, char* name) {
	int32_t i{-1};
	char* copy = new char[amount_of_students];
	for (int32_t k{}; k < amount_of_students; ++k) {
		strcpy(copy, students[k].name);
		if (strcmp(strtok(copy, " "),name) == 0) {
			i = k;
		}
	}
	if (i == -1) {
		throw "name didnt find!\n";
	}
	return i;
}

int32_t FindGroup(Student students) {
	return students.group;
}
int CompareUpGroup(const void* el1, const void* el2) {
	if (FindGroup(*((Student*)el1)) - FindGroup(*((Student*)el2)) == 0) {
		return FindFirstLetter(*((Student*)el1)) - FindFirstLetter(*((Student*)el2));
	}
	return FindGroup(*((Student*)el1)) - FindGroup(*((Student*)el2));
}
void QsortArrayUpGroup(Student* students, int32_t amount_of_students) {
	std::qsort(students, amount_of_students, sizeof(Student), CompareUpGroup);
}


int32_t CountOfDiffGroup(Student* students, int32_t amount_of_students) {
	int32_t array_of_digits[9]{};
	int32_t count_diff{};
	int32_t digit{};
	for (int32_t i{}; i < amount_of_students; ++i) {
		digit = students[i].group;
		++array_of_digits[digit];

	}
	for (int32_t i{}; i < 9; ++i) {
		if (array_of_digits[i] != 0) {
			++count_diff;
		}
	}
	return count_diff;
}
void FillAverageMarks(Student* students, int32_t amount_of_students, double* average_mark) {
	double mark_of_group{};
	int32_t count_of_students_in_group{};
	for (int32_t group{}; group < 5; ++group) {
		for (int32_t i{}; i < amount_of_students; ++i) {
			if (students[i].group == group + 1) {
				mark_of_group += students[i].grade;
				++count_of_students_in_group;
			}
		}
		if (count_of_students_in_group == 0) {
			average_mark[group] = 0;
		}
		else {
			average_mark[group] = mark_of_group / count_of_students_in_group;
		}
		mark_of_group = 0;
		count_of_students_in_group = 0;
	}
}
