// Authors: Maxim_V 
#include <iostream>
#include "Process.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: run the program with <init file name> <location file name>\n";
        std::exit(-1);
    }
    // send it to Process-> process start
    start(argv[1], argv[2]);
    return 0;

}
