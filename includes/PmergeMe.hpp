#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <cstdlib>
#include <iostream>
#include <climits>

#define DECIMAL (10)

#ifdef DEBUG
#define DEBUG_PRINT(...) (std::cout << __VA_ARGS__ << std::endl)
#else
#define DEBUG_PRINT(...)
#endif

bool validInput(int argc, char **argv);

#endif