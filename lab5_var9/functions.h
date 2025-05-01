#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <random>

void EnterSizeVectorX(int32_t&);
void EnterSizeVectorY(int32_t&);
void EnterChoice(int32_t&);

void CreateVector(double*&, int32_t);
void DeleteVector(double*&, int32_t);

void CreateMatrix(double**&, int32_t,int32_t);
void DeleteMatrix(double**&, int32_t);

void FillVectorByRandom(double*& , int32_t);
void FillVectorByHand(double*& , int32_t);
void FillCauchyMatrix(double**&, double*&, double*&, int32_t, int32_t);

double SumOfElementsInColumn(double**, int32_t, int32_t);

void PrintMatrix(double**, int32_t,int32_t);
void PrintVector(double*, int32_t);
void PrintSumOfElementsInColumn(double**, int32_t, int32_t);

void MakeAllZero(double**&, int32_t,int32_t);


#endif
