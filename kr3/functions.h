#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <windows.h>

struct Student {
	char name[30];
	int32_t group;
	double grade;
};

void CheckInputFile(std::istream& fin);
void CheckOutputFile(std::ofstream& fout);

void EnterChoice(int32_t& choice);

int32_t FindCounter(std::istream& fin);
void FillStudents(std::istream& fin, Student* students, int32_t amount_of_students);

int CompareUpName(const void* el1, const void* el2);
void QsortArrayUpName(Student* students, int32_t amount_of_students);

int32_t FindStudentIndexByName(Student* students, int32_t amount_of_students, char* name);

int32_t FindGroup(Student students);
int CompareUpGroup(const void* el1, const void* el2);
void QsortArrayUpGroup(Student* students, int32_t amount_of_students);

void FillAverageMarks(Student* students, int32_t amount_of_students, double* average_mark);
#endif
