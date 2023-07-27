#include "Globals.h"
int Globals::Dimension;
int Globals::vectorsPull;
int* Globals::targetVector;
int* Globals::arrayOfVersions;


void Globals::setDimension(int dim) {
    Dimension = dim;
}

int Globals::getDimension() {
    return Dimension;
}

void Globals::setVectorsPull(int pull) {
    vectorsPull = pull;
}

int Globals::getVectorsPull() {
    return vectorsPull;
}

void Globals::setTargetVector(int* target) {
    targetVector = target;
}

int* Globals::getTargetVector() {
    return targetVector;
}
void Globals::setArrayOfVersions(int* versions){
    arrayOfVersions = versions;
}
int* Globals::getArrayOfVersions(){
    return arrayOfVersions;
}

void Globals::updateIndex(int i){
    arrayOfVersions[i]++;
}
int Globals::getIndex(int i){
    return arrayOfVersions[i];
}
void Globals::destroy(){
    delete[] targetVector;
    delete[] arrayOfVersions;
}
