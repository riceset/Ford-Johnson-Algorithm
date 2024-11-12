#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <string>
#include <sstream>

#define DECIMAL (10)

#ifdef DEBUG
#define DEBUG_PRINT(...) (std::cout << __VA_ARGS__ << std::endl)
#else
#define DEBUG_PRINT(...)
#endif

bool validInput(int argc, char **argv);
void insertIntoList(int argc, char **argv, std::list<int> &numbers);
void printList(std::list<int> numbers);

#endif