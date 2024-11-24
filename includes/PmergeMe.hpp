#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <string>
#include <sstream>
#include "colors.hpp"

#define DECIMAL (10)
#define NO_STRUGGLER (-1)

#ifdef DEBUG
#define DEBUG_PRINT(...) (std::cout << __VA_ARGS__ << std::endl)
#else
#define DEBUG_PRINT(...)
#endif

bool validInput(int argc, char **argv);
void insertIntoList(int argc, char **argv, std::list<int> &numbers);
void printList(std::list<int> numbers);

#endif