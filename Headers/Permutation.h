#ifndef PERMUTATION_H_
#define PERMUTATION_H_
#include <iostream>
#include "../GlobVals/Globals.h"


/*
    recreate the vector of virus
    can permute, calculates error index and can make string version of virus
*/
class Permutation {
   public:
    // 3 c'tors we need to implement copy c'tor and assignment operator for
    // good implementation of copy c'tro and assignment operator for virus
    Permutation(int *arr);
    Permutation();
    ~Permutation();  // destroy vector
    Permutation(const Permutation &other);
    Permutation &operator=(const Permutation &other);

    // string version of vector
    std::string vectorToString() const;
    friend std::ostream &operator<<(std::ostream &out, const Permutation &permutation) {
        out << permutation.vectorToString();
        return out;
    }

    // perform mutation
    // randomly take two integers i and j between 0 and dimension-1
    // and move like this:
    // 0 1 i ... j ... dimesnion-1
    // 0 1 j ... i ... dimesnion-1
    void permute(int permutationIndex);

    // function to recalculate error
    // difference from target vector
    double calculateError();

   private:
    int *vector;
};

#endif
