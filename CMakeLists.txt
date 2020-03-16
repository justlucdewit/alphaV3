cmake_minimum_required(VERSION 3.0.0)

project(Alpha)

add_executable(${PROJECT_NAME} main.cpp fragments/fileReader/fileReader.cpp fragments/errorSys/errorSys.cpp fragments/tokenSys/tokenSys.h)