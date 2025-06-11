#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void EnterChoice(int32_t&);
void EnterOrder(int32_t&);
void EnterStream(int32_t&);
void EnterSize(int32_t&); 
void CheckInputFile(std::istream& fin);
void CheckOutputFile(std::ofstream& fout);

int32_t FindCounter(std::istream& fin);
void FillArrayFromFile(std::istream& fin, double* array, int32_t size);
void FillArrayFromConsole(double* array, int32_t size);
void OutputArray(std::ostream& fout, double* array, int32_t size);

int CompareUp(const void* el1, const void* el2);
void QsortArrayUp(double* array, int32_t size);

int CompareDown(const void* el1, const void* el2);
void QsortArrayDown(double* array, int32_t size);

void SortInsertionUp(double* array, int32_t size);
void SortInsertionDown(double* array, int32_t size);

void SelectionSortUp(double* array, int32_t size);
void SelectionSortDown(double* array, int32_t size);

void BubbleSortUp(double* array, int32_t size);
void BubbleSortDown(double* array, int32_t size);

int32_t CountOfDigitsAfterPoint(double el);
int32_t FindCountOfDigits(int64_t numb);
int CompareUpSpecial(const void* el1, const void* el2);
int CompareDownSpecial(const void* el1, const void* el2);
void QsortArrayUpSpecial(double* array, int32_t size);
void QsortArrayDownSpecial(double* array, int32_t size);

void DoMergeUp(double* array, int32_t low, int32_t mid, int32_t high);
void MergeSortUp(double* arr, int32_t low, int32_t high);

void DoMergeDown(double* array, int32_t low, int32_t mid, int32_t high);
void MergeSortDown(double* arr, int32_t low, int32_t high);

#endif