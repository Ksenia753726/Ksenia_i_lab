#include "functions.h"

bool IsLatinLetter(char letter) {
    return ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'));
}

bool ConsistOnlyLatin(std::string str) {
    for (int32_t i{}; i < str.size(); ++i) {
        if (!IsLatinLetter(str[i]))
            return false;
    }
    return true;
}

int Compare(const void* el1, const void* el2) {
    if (*((std::string*)el1) < *((std::string*)el2))
        return -1;
    else if (*((std::string*)el2) < *((std::string*)el1))
        return 1;
    return 0;
}

int32_t FindAmountWordsAndSpaces(std::string str) {
    size_t amount_of_symbols{ str.length() };
    int32_t amount_of_words_spaces{};
    int32_t i{};

    while (i < amount_of_symbols) {
        if (str[i] == ' ') {
            ++amount_of_words_spaces;
            while (i < amount_of_symbols && str[i] == ' ')
                ++i;
        }
        else {
            amount_of_words_spaces++;
            while (i < amount_of_symbols && str[i] != ' ')
                ++i;
        }
    }
    return amount_of_words_spaces;
}

void FillWordsAndSpacesArray(std::string*& words_and_spaces_array, bool*& is_word_array, int32_t amount_of_words_spaces, std::string str) {
    size_t amount_of_symbols{ str.length() };
    int32_t j{};
    int32_t index{};
    int32_t begin{};
    while (j < amount_of_symbols) {
        if (str[j] == ' ') {
            begin = j;
            while (j < amount_of_symbols && str[j] == ' ') {
                ++j;
            }

            words_and_spaces_array[index] = str.substr(begin, j - begin);
            is_word_array[index] = false;
            ++index;
        }
        else {
            begin = j;
            while (j < amount_of_symbols && str[j] != ' ') {
                ++j;
            }
            words_and_spaces_array[index] = str.substr(begin, j - begin);
            is_word_array[index] = true;
            ++index;
        }
    }
}

int32_t FindCountOfOnlyLatinaWords(std::string* words_and_spaces_array, bool* is_word_array, int32_t amount_of_words_spaces) {
    int32_t count_of_latin{};
    for (int32_t j{}; j < amount_of_words_spaces; ++j) {
        if (is_word_array[j] && ConsistOnlyLatin(words_and_spaces_array[j]))
            ++count_of_latin;
    }
    if (count_of_latin == 0) {
        throw "there isnt latina words\n";
    }
    return count_of_latin;
}

void FillLatinsArray(std::string*& array_of_latins, int32_t*& array_of_index_of_latins, std::string* words_and_spaces_array, bool* is_word_array, int32_t amount_of_words_spaces) {
    int32_t i{};
    for (int32_t j{}; j < amount_of_words_spaces; ++j) {
        if (ConsistOnlyLatin(words_and_spaces_array[j]) && is_word_array[j]) {
            array_of_latins[i] = words_and_spaces_array[j];
            array_of_index_of_latins[i] = j;
            ++i;
        }
    }
}

void Qsort(std::string*& array_of_latins, int32_t count_of_latin) {
    qsort(array_of_latins, count_of_latin, sizeof(std::string), Compare);
}

void OutputResult(std::string* words_and_spaces_array, int32_t amount_of_words_spaces) {
    for (int32_t i{}; i < amount_of_words_spaces; ++i) {
        std::cout << words_and_spaces_array[i];
    }
}
