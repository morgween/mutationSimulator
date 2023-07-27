# C++ Programming Project - Virus Simulation
This project is a simulation of a world containing different types of viruses with polymorphic behavior. 
The main goal is to implement a generic data structure for a queue and extending the virus simulation using object-oriented programming concepts.

## How to Use the Project

### Compilation
To compile the project, you can use the g++ or any other compiler on your system. Make sure you have a compatible C++ compiler installed. 
To compile the code, please use the following command in terminal:\
```g++ -o virus_simulation main.cpp virus.cpp queue.cpp -std=c++11```
### Input Files
The program expects two input files:

- *world_config.txt*: This file describes the initial configuration of the virus world. It contains two lines:

The first line holds a vector of weights that determine the proximity of each virus to the target virus.
The second line holds the target vector.\
Example:\
1 2 3 4 5 6 7 8 9 10\
10 9 8 7 6 5 4 3 2 1
- *initial_generation.txt*: This file describes the initial generation of viruses. The first line contains the number of viruses in the world. The following lines specify each virus with its type ('P', 'M', or 'L'), name, and initial state.

Example:\
5\
P csMEX 1 2 3 4 5 6 7 8 9 10\
P ukSFO 10 2 3 4 5 6 7 8 9 1\
L fhOAK 3 1 2 4 5 6 7 10 9 8\
M jkFIN 7 2 3 4 5 1 6 8 10 9\
L mjdjAMS 8 2 3 9 5 6 10 7 1 4
### Running the Program
After compiling the code and creating the input files, you can run the simulation using the following command:

in terminal:\
```./virus_simulation world_config.txt initial_generation.txt```

### Output
The program will output the vector of weights for the last generation of viruses. Additionally, it will display the best virus based on the specified criteria.

## Notes
* The program does not use the STL library to implement the queue.
* Make sure your input files follow the correct format as described above.
* You may refer to the comments in the source code for more details about the implementation.
## Authors
Maxim_V

## License
This project is licensed under the MIT License. Feel free to use and modify it according to your needs.

*Enjoy the virus simulation!*
