#include "../Headers/Virus.h"

Virus::Virus(std::string n, int pI, Permutation &per, int t) {
    vector = per;
    name = n;
    permutationIndex = pI;
    updateErrorIndex();
    type = t;
};

Virus::Virus() {
    name = "Virus";
    permutationIndex = 0;
    vector = Permutation();
    updateErrorIndex();
    type = 1;
}

Virus::Virus(const Virus &other) {
    type = other.type;
    name = other.getName();
    vector = other.getVector();
    permutationIndex = other.getPermutationIndex();
    errorIndex = other.getErrorIndex();
}

Virus &Virus::operator=(const Virus &other) {
    if (this == &other) {
        return *this;
    } else {
        type = other.type;
        name = other.name;
        vector = other.vector;
        permutationIndex = other.permutationIndex;
        errorIndex = other.errorIndex;
    }
    return *this;
}

// func for update name of virus
std::string string_with_number(std::string name, int num) {
    size_t pos = name.find_last_of("_");
    if (pos == std::string::npos) {
        // if there is no underscore, add one before appending the number
        if (num == 0) {
            name += "_1";
        } else {
            name += "_" + std::to_string(num + 1);
        }
    } else {
        // if there is an underscore, replace the number after it with the new number
        if (num == 0) {
            name.replace(pos + 1, std::string::npos, "1");
        } else {
            name.replace(pos + 1, std::string::npos, std::to_string(num + 1));
        }
    }
    return name;
}

void Virus::updateName() {
    name = string_with_number(name, Globals::getIndex(type));
    Globals::updateIndex(type);
}

void Virus::updateErrorIndex() {
    errorIndex = vector.calculateError();
}

std::string Virus::toString() const {
    std::string returnString = "";
    returnString += getSubGroup();
    returnString += " ";
    returnString += getName();
    returnString += " ";
    returnString += getVector().vectorToString();
    return returnString;
}

bool Virus::operator<(const Virus &other) const {
    if (errorIndex != other.errorIndex) {
        return errorIndex < other.errorIndex;
    } else {
        return name < other.name;
    }
}
bool Virus::operator<(const Virus *other) const {
    if (this->getErrorIndex() != other->getErrorIndex()) {
        return this->getErrorIndex() < other->getErrorIndex();
    } else {
        return this->getName() < other->getName();
    }
}
