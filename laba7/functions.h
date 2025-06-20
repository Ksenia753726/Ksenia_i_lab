#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <cstdlib>

bool IsLatinLetter(char);
bool ConsistOnlyLatin(std::string);
int Compare(const void*, const void*);
int32_t FindAmountWordsAndSpaces(std::string);
void FillWordsAndSpacesArray(std::string*&, bool*&, int32_t, std::string);
int32_t FindCountOfOnlyLatinaWords(std::string*, bool*, int32_t);
void FillLatinsArray(std::string*&, int32_t*&, std::string*, bool*, int32_t);
void Qsort(std::string*&, int32_t);
void OutputResult(std::string*, int32_t);

#endif