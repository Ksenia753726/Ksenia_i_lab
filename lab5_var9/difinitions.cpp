#include "functions.h"


void EnterSizeVectorX(int32_t& n) {
    std::cout << "Enter size of x: ";
    std::cin >> n;
}

void EnterSizeVectorY(int32_t& n) {
    std::cout << "Enter size of y: ";
    std::cin >> n;
}

void EnterChoice(int32_t& choice) {
    std::cout << "Enter choice 1[random] or 2[hand]: ";
    std::cin >> choice;
}

void CreateMatrix(double**& mtr, int32_t p,int32_t q) {
    mtr = new double * [p];
    for (int32_t i{}; i < p; ++i) {
        mtr[i] = new double[q];
    }
}
void DeleteMatrix(double**& mtr, int32_t p) {
    for (int32_t i{}; i < p; ++i) {
        delete[] mtr[i];
    }
    delete[] mtr;
}

void CreateVector(double*& vector, int32_t n) {
    vector = new double [n];
    
}
void DeleteVector(double*& vector, int32_t n) {
    delete[] vector;
}


void MakeAllZero(double**& mtr, int32_t p, int32_t q) {
    for (int32_t i{}; i < p; ++i) {
        for (int32_t j{}; j < q; ++j) {
            mtr[i][j] = 0;
        }
    }
}

void PrintMatrix(double** mtr, int32_t p,int32_t q) {
    std::cout << "mantrix of Cauchy : \n";
    for (int32_t i{}; i < p; i++) {
        for (int32_t j{}; j < q; ++j) {
            std::cout << mtr[i][j] << std::setw(12);
        }
        std::cout << '\n';
    }
}

void FillVectorByRandom(double*& vector, int32_t n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(1, 100);

    for (int32_t i{}; i < n; ++i) {
       vector[i] = dist(gen);
    }

}

void FillVectorByHand(double*& vector, int32_t n) {
    for (int32_t i{}; i < n; ++i) {
        std::cin >> vector[i];
    }
}

void FillCauchyMatrix(double**& mtr,double*& x, double*& y, int32_t p, int32_t q) {
    for (int32_t i{}; i < p; ++i) {
        for (int32_t j{}; j < q; ++j) {
            mtr[i][j] = 1 / (x[i] + y[j]);

        }
    }
}

void PrintVector(double* vector, int32_t n) {
    for (int32_t i{}; i < n; ++i) {
        std::cout << vector[i] << std::setw(12);
    }
    std::cout << '\n';
}

double SumOfElementsInColumn(double** mtr, int32_t p , int32_t q) {
    double sum{};

    for (int32_t i{}; i < p; ++i) {
        sum += mtr[i][q];
    }

    return sum;
}

void PrintSumOfElementsInColumn(double** mtr, int32_t p, int32_t q) {
    for (int32_t i{}; i < q; ++i) {
        std::cout << "summ of " << i + 1 << "column : " << SumOfElementsInColumn(mtr, p, i) << '\n';
    }
}