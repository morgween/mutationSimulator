#include "Globals.h"

u_int Globals::Dimension;
u_int Globals::vectorsPull;
int* Globals::targetVector;
int* Globals::arrayOfVersions;


void Globals::setDimension(int dim) {
    Dimension = dim;
}

u_int Globals::getDimension() {
    return Dimension;
}

void Globals::setVectorsPull(int pull) {
    vectorsPull = pull;
}

u_int Globals::getVectorsPull() {
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
u_int Globals::getIndex(int i){
    return arrayOfVersions[i];
}
void Globals::destroy(){
    delete[] targetVector;
    delete[] arrayOfVersions;
}
