#pragma once

#include <iostream>
#include <vector>

class AVM32{
    // private variables
    int32_t pc = 100;//program counter
    int32_t sp = 0;//stack pointer
    std::vector<int32_t> memory;
    int32_t typ = 0;//type register
    int32_t dat = 0;//data register
    int32_t running = 1;//running register

    // private functions
    int32_t getType(int32_t instruction);
    int32_t getData(int32_t instruction);
    void fetch();
    void decode();
    void execute();
    void doPrimitive();

public:
    AVM32();
    void run();
    void loadProgram(std::vector<int32_t> prog);
};