#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <iomanip>
#include <exception>
void InputDegree(int32_t&);

void CreateArray(int32_t**&, int32_t);
void DeleteArray(int32_t**&,int32_t);

void FillPascalTriangle(int32_t**&, int32_t);
void PrintPascalTriangle(int32_t**&, int32_t);
#endif
