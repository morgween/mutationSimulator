#ifndef PAPILLOMA_H_
#define PAPILLOMA_H_

#include "../Headers/Virus.h"

// virus subclass that makes permutation with permutation index 1
// viruses of this class couldn't be replaced at population updates

class Papilloma : public Virus {
   public:
    Papilloma(std::string n, int pI, Permutation &per, int t) : Virus(n, pI, per, t){};
    Papilloma() = default;
    Papilloma(Papilloma &&) = default;
    Papilloma(const Papilloma &) = default;
    Papilloma &operator=(Papilloma &&) = default;
    Papilloma &operator=(const Papilloma &) = default;
    ~Papilloma() = default;

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
    char subGroup = 'P';
};

#endif