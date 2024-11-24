#include "PmergeMe.hpp"

static bool sufficientArgs(int argc) {
    if (argc < 2) {
        std::cerr << "Error: No numbers provided!" << std::endl;
        return (false);
    }
    return (true);
}

static bool conversionError(char *end) {
    return (*end != '\0');
}

static bool valueIsOutOfRange(long val) {
    return (val < INT_MIN || val > INT_MAX);
}

static bool couldConvertNumber(char *currNumber, long &val) {
    char *end;
    
    val = strtol(currNumber, &end, DECIMAL);
    if (conversionError(end))
        return (false);
    if (valueIsOutOfRange(val))
        return (false);
    return (true);
}

bool validateArgument(char *arg, long &val) {
    if (!couldConvertNumber(arg, val)) {
        std::cerr << "Error: Invalid number '" << arg << "'." << std::endl;
        return (false);
    }
    if (val < 0) {
        std::cerr << "Error: Negative numbers are not allowed." << std::endl;
        return (false);
    }
    return (true);
}

bool validInput(int argc, char **argv) {
    long val = 0;
    if (!sufficientArgs(argc))
        return (false);
    for (int i = 1; i < argc; i++) {
        if (!validateArgument(argv[i], val)) 
            return (false);
        DEBUG_PRINT("Value: " << val);
    }
    DEBUG_PRINT(GREEN << "Input is valid!" << RESET);
    return (true);
}

void insertIntoList(int argc, char **argv, std::list<int> &numbers) {
    for (int i = 1, num = 0; i < argc; i++) {
        std::stringstream ss(argv[i]);
        ss >> num;
        numbers.push_back(num);
    }
}

void printList(std::list<int> numbers) {
    std::list<int>::const_iterator it;

    std::cout << "LIST: ";
    for (it = numbers.begin(); it != numbers.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void printPairs(const std::list<std::pair<int, int> > &pairs, int struggler) {
    for (std::list<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ")";
    }
    std::cout << std::endl;
    if (struggler == NO_STRUGGLER) {
        DEBUG_PRINT(MAGENTA << "NO STRUGGLER" << RESET);
    } else {
        DEBUG_PRINT(CYAN << "STRUGGLER: " << struggler << RESET);
    }
    std::cout << std::endl;
}

std::list<std::pair<int, int> > groupListIntoPairs(const std::list<int>& numbers, int& struggler) {
    std::list<std::pair<int, int> > pairs;
    std::list<int>::const_iterator it = numbers.begin();
    struggler = NO_STRUGGLER;
    while (it != numbers.end()) {
        int first = *it++;
        if (it != numbers.end()) {
            int second = *it++;
            pairs.push_back(std::make_pair(first, second));
        } else {
            struggler = first;
        }
    }
    return (pairs);
}