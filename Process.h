#ifndef PROCESS_H_
#define PROCESS_H_

#include <fstream>
#include <iostream>

#include "GlobVals/Globals.h"
#include "Headers/Permutation.h"
#include "Headers/Population.h"
#include "Headers/Virus.h"
#include "datastructures/MyQueue.h"
#include "Vtypes/Lentivirus.h"
#include "Vtypes/Mimivirus.h"
#include "Vtypes/Papilloma.h"

/*
    read from init file set permament global variables:
    dimension, target vector and permutation index
    create first population and set last global variables:
    vectors pull and array of versions
    start main process(loop and update population until
    last step/virus that is similar to target virus)
*/

int start(std::string initFile, std::string locationFile);

/*
        in given file first line is number of vectors that were given in this program
        so we read this number, save it to global variable
        from second line up to 1+given number will be vectors:
        name vector
        ...
        so we read name and after it we read vector with help of global dimension
        if length of vector were lesser then dimension - error

        and then add this virus to sorted list of viruses, sorted list will help to
        find the best and the worst virus in population
        and to stabilize storing of viruses
        i used regular implementation of regular array based List
        just added some functionality and add some futures for adding objects

        we fill this sorted list with viruses(that are created from name and permuation)
        after creating and filling sorted list we close file and create population
        that will be the first

        also creating pointer to integer that will represent version for each one of
        the first viruses in population that will help to control version of viruses
        -> return object from type Population
    */
Population createPopulation(std::string locationFile);

/*
    we got file, that we know that first number in this file is some
    integer between  5 - 100 - no need to check, but need to check that
    every vector corresponding to given dimension
    and secon line is permutation index given from this file is number
    of self updates for virus
    and after this given example of array that will represent target vector

    so we set dimension and target vector as global variables, we will have to
    use them a lot
    -> return permutation index(that will be used in generating population)
*/
int readInit(std::string initFile);

#endif