#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <iomanip>
#include <exception>
void InputDegree(int32_t&);

void CreateArray(int32_t*&, int32_t);
void DeleteArray(int32_t*&, int32_t);

void FillArrayByHand(int32_t*, int32_t);
 
void FillComposition(int32_t*&, int32_t, int32_t*&, int32_t, int32_t*&, int32_t);
void TurnAllElementsInNulls(int32_t*&, int32_t);
void PrintPolynomian(int32_t*, int32_t);
#endif
