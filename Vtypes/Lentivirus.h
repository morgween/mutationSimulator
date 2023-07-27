#ifndef LENTIVIRUS_H_
#define LENTIVIRUS_H_

#include "../Headers/Virus.h"
// Lentivirus sub virus that makes permutation with permutation index 2 (2 permutations per cycle)

class Lentivirus : public Virus {
   public:
    Lentivirus(std::string n, int pI, Permutation &per, int t) : Virus(n, pI, per, t){};
    Lentivirus() = default;
    Lentivirus(Lentivirus &&) = default;
    Lentivirus(const Lentivirus &) = default;
    Lentivirus &operator=(Lentivirus &&) = default;
    Lentivirus &operator=(const Lentivirus &) = default;
    ~Lentivirus() = default;

    void update() override {
        // build-in method for permutation class
        getVector().permute(getPermutationIndex());
        // must have to update error index
        updateErrorIndex();
    }
    void print() {
        std::cout << subGroup;
    }
    char getSubGroup() const override { return subGroup; }

   private:
    char subGroup = 'L';
};

#endif