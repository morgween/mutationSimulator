#ifndef POPULATION_H_
#define POPULATION_H_
#include "Virus.h"
#include "../datastructures/MyQueue.h"
#include "../Vtypes/Lentivirus.h"
#include "../Vtypes/Mimivirus.h"
#include "../Vtypes/Papilloma.h"


/*
    Population class represents population of viruses
    here we store each virus upgrade them and update this population
*/

class Population {
   public:
    Population(Queue<Virus *> vL, int tU);
    Population();
    Population(const Population &other);
    Population(Population &&other);
    Population &operator=(Population &other);
    Population &operator=(Population &&other);

    // prints all the vectors of population;
    // ends only if isEnd() return true;
    // if we reached the end of the life cycle or lifed full
    // of given timeUnits at the start then this function called
    void happyEnding();
    // check if we ended the life cycle
    bool isEnd() { return isEnded; };

    // operator ++ update the populatian and trigger personal update of viruses
    //  and check if we ended the life cycle
    void update();
    Population operator++(int);

    // print current population
    void print();

   protected:
    // function used to implement the update of current population
    void updateVectors();
    void updateGroup();

   private:
    // stores all the viruses
    Queue<Virus *> virusesList;
    // save the best vector of all time to print him out at the end
    std::string theBestOfAllTime;  // GOAT
    // save index of the GOAT virus
    double bestIndex;
    // how much steps left
    int timeUnits;
    // steps done
    int step;
    bool isEnded = false;
    bool isAllP = false;
};

#endif