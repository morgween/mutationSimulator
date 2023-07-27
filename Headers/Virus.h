#ifndef VIRUS_H_
#define VIRUS_H_
#include <iostream>
#include <string>
#include "Permutation.h"

/*
    viruses represented as integer numbers, each
    virus trying to get as close to target vector
    as it possible, but random is versus them
    and trying to get each virus deleted
    viruses perform n permutation at each time unit
    n = permutationIndex
*/

class Virus {
   public:
    // 5 c'tor
    Virus(std::string n, int pI, Permutation &per, int t);
    Virus();
    Virus(Virus &&other) = default;
    Virus(const Virus &other);
    Virus &operator=(const Virus &other);
    ~Virus() = default;

    // method that updates version in name of vector
    void updateName();
    // update viruses error index at each step
    void updateErrorIndex();

    // getters
    int getPermutationIndex() const { return permutationIndex; }
    double getErrorIndex() const { return errorIndex; }
    const std::string &getName() const { return name; }
    const Permutation &getVector() const { return vector; }
    virtual int getType() { return type; };
    std::string toString() const;

    virtual char getSubGroup() const = 0;
    virtual void update() = 0;

    bool operator<(const Virus &other) const;
    bool operator<(const Virus *other) const;
    friend std::ostream &operator<<(std::ostream &out, const Virus &virus) {  // operator<< for viruses
        out << virus.getSubGroup() << " " << virus.getName() << " " << virus.getVector();
        return out;
    }
    friend std::ostream &operator<<(std::ostream &out, const Virus *virus) {  // operator<< for viruses pointers
        out << virus->getSubGroup() << " " << virus->getName() << " " << virus->getVector();
        return out;
    }

   protected:
    Permutation &getVector() { return vector; }

   private:
    std::string name;
    Permutation vector;
    int permutationIndex;
    double errorIndex;
    int type;
};

#endif