#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <stdexcept>

void InputSize(int32_t&);
void EnterChoice(int32_t&);
void EnterLowBorder(int32_t&);
void EnterHightBorder(int32_t&);
void SwapBorders(int32_t&, int32_t&);

void CreateArray(int32_t*&, int32_t);
void DeleteArray(int32_t*&);

void FillArrayRandom(int32_t*, int32_t, int32_t,int32_t);
void FillArrayByHand(int32_t*, int32_t);

void SortArray(int32_t*, int32_t);

void PrintArray(int32_t*, int32_t);

int32_t CountOfChangesOfSign(int32_t*, int32_t);

int32_t FindIndexOfFirstNull(int32_t*, int32_t);
int32_t FindIndexOfSecondNull(int32_t*, int32_t);

int32_t ÑompositionElementsBetweenNulls(int32_t*, int32_t);

template <class T>
void Swap(T& a, T& b) {
	auto temp{ a };
	a = b;
	b = temp;
}

#endif

