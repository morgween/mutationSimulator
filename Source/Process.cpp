
#include "../Process.h"

int start(std::string initFile, std::string locationFile) {
    readInit(initFile);
    Population myPopulation = createPopulation(locationFile);
    while (!myPopulation.isEnd()) {
        myPopulation++;
    }
    return 0;
}

int readInit(std::string initFile) {
    int dim = 0, val = 0, i = 0, *targetVector;
    std::ifstream input_file(initFile);
    if (!input_file.is_open()) {
        std::cerr << "Error: Unable to open file " << initFile << std::endl;
        exit(1);
    }
    input_file >> dim;            // first line is all viruses dimension
    targetVector = new int[dim];  // target vector
    while (input_file >> val) {
        targetVector[i++] = val;
    }
    input_file.close();
    Globals::setDimension(dim);  // set globals and go to next
    Globals::setTargetVector(targetVector);
    return 1;
}

Population createPopulation(std::string locationFile) {
    std::ifstream input_file(locationFile);
    if (!input_file.is_open()) {
        std::cerr << "Error: Unable to open file " << locationFile << std::endl;
        exit(1);
    }
    std::string name;
    int permutation_indexes[] = {2, 4, 1}, numberOfVectors = 0, *virusVector,
        versionControl = 0, *arr;
    char virusClass[] = {'L', 'M', 'P'}, type;
    Queue<Virus *> first_generation{};

    input_file >> numberOfVectors;

    virusVector = new int[numberOfVectors];
    arr = new int[Globals::getDimension()];

    while (input_file >> type) {
        input_file >> name;
        virusVector[versionControl] = 0;
        for (int i = 0; i < Globals::getDimension(); i++) {
            int k = 0;
            input_file >> k;
            if (!k) {
                // got zero - not enough length of vector
                std::cerr << "Invalid input.\n";
                std::cerr << "Error: Virus " << name << " has invalid vector.\n"
                          << std::endl;
                delete[] arr;
                exit(1);
            }
            arr[i] = k;
        }
        Permutation p(arr);
        Virus *v;
        if (type == virusClass[0]) {
            v = new Lentivirus(name, permutation_indexes[0], p, versionControl++);
        } else if (type == virusClass[1]) {
            v = new Mimivirus(name, permutation_indexes[1], p, versionControl++);
        } else if (type == virusClass[2]) {
            v = new Papilloma(name, permutation_indexes[2], p, versionControl++);
        } else {
            std::cerr << "Invalid input.\n";
            std::cerr << "Error: Virus " << name << " has invalid type.\n"
                      << std::endl;
            delete[] arr;
            exit(1);
        }
        first_generation.enqueueWithPriority(v, true);
        if (versionControl == numberOfVectors) {
            break;
        }
    }
    input_file.close();
    int timeUnits = 0;
    std::cin >> timeUnits;
    delete[] arr;
    Globals::setVectorsPull(numberOfVectors);
    Globals::setArrayOfVersions(virusVector);

    Population firstPopulation(first_generation, timeUnits);
    return firstPopulation;
}