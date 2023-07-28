#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <iostream>
/*
    Main functionality of the class is to save the global variables and to make them accessible from all
    the other classes.
    The class is static, so we can access the variables without creating an object of the class.
    The class has 4 static variables:
        - Dimension - the dimension of the vectors
        - vectorsPull - the number of vectors we have in the location file
        - targetVector - the vector we want to find
        - arrayOfVersions - the array that holds the number of times we have used a vector from the location file
    The class has 11 static methods:
        - getter and setter for each of the variables
        - updateIndex - updates the number of times version of the virus was updated
        - getIndex - returns the number of times version of the virus was updated
        - destroy - destroys the dinamicly allocated arrays
*/

class Globals {
   public:
    // params we get from init file
    static int Dimension;
    static int* targetVector;
    // params we get from location file
    static int vectorsPull;
    static int* arrayOfVersions;

    static void setDimension(int dim);
    static int getDimension();

    static void setVectorsPull(int pull);
    static int getVectorsPull();

    static void setTargetVector(int* target);
    static int* getTargetVector();

    static void updateIndex(int i);
    static int getIndex(int i);

    static void setArrayOfVersions(int* versions);
    static int* getArrayOfVersions();

    // destroys dinamicly allocated arrays
    static void destroy();
};
#endif