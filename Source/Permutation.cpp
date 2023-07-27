#include "../Headers/Permutation.h"

Permutation::Permutation(int *arr) {
    vector = new int[Globals::getDimension()];
    for (int i = 0; i < Globals::getDimension(); i++) {
        vector[i] = arr[i];
    }
}
Permutation::Permutation() {
    vector = new int[Globals::getDimension()];
    for (int i = 0; i < Globals::getDimension(); i++) {
        vector[i] = i;
    }
}
Permutation::~Permutation() {
    delete[] vector;
}
Permutation::Permutation(const Permutation &other) {
    Permutation newPer{};
    for (int i = 0; i < Globals::getDimension(); i++)
        newPer.vector[i] = other.vector[i];
}
Permutation &Permutation::operator=(const Permutation &other) {
    if (this == &other) {
        return *this;
    } else {
        for (int i = 0; i < Globals::getDimension(); i++)
            vector[i] = other.vector[i];
    }
    return *this;
}



std::string Permutation::vectorToString() const {
    std::string str = "";
    for (int i = 0; i < Globals::getDimension(); i++) {
        str += std::to_string(vector[i]);
        str += " ";
    }
    return str;
}

void Permutation::permute(int permutationIndex) {
    for (int k = 0; k < permutationIndex; k++) {
        int i = (rand() / (RAND_MAX + 1.0)) * Globals::getDimension();
        int j = (rand() / (RAND_MAX + 1.0)) * Globals::getDimension();
        int tmp = vector[i];
        vector[i] = vector[j];
        vector[j] = tmp;
        calculateError();
    }
}
double Permutation::calculateError() {
    double error = Globals::getDimension();
    for (int i = 0; i < Globals::getDimension(); i++) {
        if (vector[i] != Globals::getTargetVector()[i]) {
            error--;
        }
    }
    return 1.0 - (error / (double)Globals::getDimension());
}
