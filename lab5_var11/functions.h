#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>

void EnterAmountColsAndRows(int32_t&);


void CreateMatrix(int32_t**&, int32_t);
void DeleteMatrix(int32_t**&, int32_t);

void PrintMatrix(int32_t**, int32_t);

void MakeAllZero(int32_t**&, int32_t);

void FillMatrixBySpiral(int32_t**&, int32_t,int32_t,int32_t);
int32_t SumOfElementsOfLowerRightTriangle(int32_t**, int32_t);

#endif

