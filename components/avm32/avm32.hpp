#pragma once

#include <iostream>
#include <vector>
namespace AVM{
    const int32_t EXIT =    0x40000000;
    const int32_t ADD =     0x40000001;
    const int32_t SUB =     0x40000002;
    const int32_t MUL =     0x40000003;
    const int32_t DIV =     0x40000004;

}

class AVM32{
    // private variables
    int32_t pc = 0;                 // program counter
    int32_t sp = -1;                // stack pointer
    std::vector<int32_t> memory;     // stack memory
    int32_t typ = 0;                // type register
    int32_t dat = 0;                // data register
    int32_t running = 1;            // running register

    // private functions
    int32_t getType(int32_t instruction);   //  extracts a type from a instruction
    int32_t getData(int32_t instruction);   //  extracts the data from a instruction
    void fetch();                           // increases pc register to go to next instruction
    void decode();                          // extracts type and data out of instruction at pc
    void execute();                         // looks if it should push a number or execute a operation
    void doPrimitive();                     // executes the operation

public:
    explicit AVM32(unsigned int programSize, unsigned int stackSize);   // constructor function, will set the size of the memory
    void run();                                                         // will run the program that is loaded in memory
    void loadProgram(std::vector<int32_t> prog);                        // will load a program into memory
};