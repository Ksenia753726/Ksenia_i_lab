#include "functions.h"
int main() {
  
    int32_t choice{};
    EnterChoice(choice);

    double** mtr = nullptr;
    double* x = nullptr;
    int32_t p{};
    EnterSizeVectorX(p);

    double* y = nullptr;
    int32_t q{};
    EnterSizeVectorY(q);

    try {
        if (p <= 0 || q <= 0) {
            throw "wrong argument";
        }
       
        CreateVector(x,p);
        CreateVector(y,q);

      
        switch (choice) {
        case 1:
            FillVectorByRandom(x, p);
            PrintVector(x, p);
            FillVectorByRandom(y, q);
            PrintVector(y, q);
            break;
        case 2:

            FillVectorByHand(x, p);
            FillVectorByHand(y, q);
            break;
        default:
            std::cout << "your choice is bad\n";
            DeleteVector(x, p);
            DeleteVector(y, q);
            return 0;
        }
        CreateMatrix(mtr,p,q); 
        MakeAllZero(mtr, p,q);
        FillCauchyMatrix(mtr,x,y, p, q);

        PrintMatrix(mtr, p,q);
        PrintSumOfElementsInColumn(mtr, p, q);

        DeleteMatrix(mtr,p);
        DeleteVector(x, p);
        DeleteVector(y, q);

        system("pause");
    }
    catch (const char* e) {
        std::cout << e;
    }
    return 0;
}