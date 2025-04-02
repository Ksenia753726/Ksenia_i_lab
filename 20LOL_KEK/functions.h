#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <cmath>
void InputSize(int32_t&);
void EnterChoice(int32_t&);
void EnterLowBorder(double&);
void EnterHightBorder(double&);
void PrintArray(double*, int32_t);

void CreateArray(double*&, int32_t);
void DeleteArray(double*&);

void FillArrayRandom(double*, int32_t,double,double);
void FillArrayByHand(double*, int32_t);

void SqueezeArray(double*, int32_t, double, double);

int32_t CounterOfWrongNumbers(double* , int32_t , double , double );
void ChangeWrongNumbersToNull(double* , int32_t , double , double );

template <class T>
void Swap(T& a, T& b) {
	auto temp{ a };
	a = b;
	b = temp;
}

int32_t FindIndexOfMinimumDifference(double*, int32_t);
int32_t AmountUpElement(double*, int32_t,int32_t);
int32_t AmountAfterElement(double*, int32_t,int32_t);

double FindMaxElement(double*, int32_t);
int32_t FindIndexOfMaxElement(double*, int32_t);

#endif

