#include "functions.h"

int main() {
    std::string str;
    std::cout << "enter string :\n";
    std::getline(std::cin, str);
    try {
        if (str.empty()) {
            throw "your string is empty\n";
        }

        size_t amount_of_symbols{ str.length() };
        int32_t amount_of_words_spaces{ FindAmountWordsAndSpaces(str) };

        std::string* words_and_spaces_array = new std::string[FindAmountWordsAndSpaces(str)];
        bool* is_word_array = new bool[amount_of_words_spaces];

        FillWordsAndSpacesArray(words_and_spaces_array, is_word_array, amount_of_words_spaces, str);

        int32_t count_of_latin{ FindCountOfOnlyLatinaWords(words_and_spaces_array,is_word_array,amount_of_words_spaces) };
        std::string* array_of_latins = new std::string[count_of_latin];
        int32_t* array_of_index_of_latins = new int32_t[count_of_latin];

        FillLatinsArray(array_of_latins, array_of_index_of_latins, words_and_spaces_array, is_word_array, amount_of_words_spaces);

        Qsort(array_of_latins, count_of_latin);

        for (int32_t i{}; i < count_of_latin; ++i) {
            words_and_spaces_array[array_of_index_of_latins[i]] = array_of_latins[i];
        }

        OutputResult(words_and_spaces_array, amount_of_words_spaces);

        delete[] words_and_spaces_array;
        delete[] is_word_array;
        delete[] array_of_latins;
        delete[] array_of_index_of_latins;
    }
    catch (const char* e) {
        std::cout << e;
    }
    return 0;
}