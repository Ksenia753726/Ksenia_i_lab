#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>

void EnterRows(int32_t&);
void EnterCols(int32_t&);

void FillMatrix(int32_t**&, int32_t, int32_t);
void CreateMatrix(int32_t**&, int32_t, int32_t);
void DeleteMatrix(int32_t**&, int32_t);

void MultiplayOfMatrixs(int32_t**, int32_t, int32_t, int32_t**, int32_t, int32_t**&);
void PrintMatrix(int32_t**&, int32_t, int32_t);

void MakeAllZero(int32_t**&, int32_t, int32_t);

#endif
