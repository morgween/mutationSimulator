#ifndef MIMIVIRUS_H_
#define MIMIVIRUS_H_

#include "../Headers/Virus.h"


// super fast virus that makes permutation with permutation index 4

class Mimivirus : public Virus {
   public:
    Mimivirus(std::string n, int pI, Permutation &per, int t) : Virus(n, pI, per, t){};
    Mimivirus() = default;
    Mimivirus(Mimivirus &&) = default;
    Mimivirus(const Mimivirus &) = default;
    Mimivirus &operator=(Mimivirus &&) = default;
    Mimivirus &operator=(const Mimivirus &) = default;
    ~Mimivirus() = default;
    void update() override {
        // build-in method for permutation class
        getVector().permute(getPermutationIndex());
        // must have to update error index
        updateErrorIndex();
    }
    void print() {
        std::cout << subGroup;
    }
    char getSubGroup() const override{ return subGroup; }
    
   private:
    char subGroup = 'M';
};

#endif