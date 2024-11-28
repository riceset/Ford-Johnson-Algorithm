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
            if (first > second)
                std::swap(first, second);
            pairs.push_back(std::make_pair(first, second));
        } else {
            struggler = first;
        }
    }
    return (pairs);
}

std::list<int> handleBaseCase(std::list<std::pair<int, int> > &pairs) {
    std::list<int> sortedList;
    if (!pairs.empty()) {
        sortedList.push_back(pairs.front().first);
        sortedList.push_back(pairs.front().second);
    }
    return (sortedList);
}

void splitPairs(const std::list<std::pair<int, int> > &pairs, std::list<std::pair<int, int> > &leftPairs, std::list<std::pair<int, int> > &rightPairs) {
    std::list<std::pair<int, int> >::const_iterator it = pairs.begin();
    std::advance(it, pairs.size() / 2);
    leftPairs.insert(leftPairs.begin(), pairs.begin(), it);
    rightPairs.insert(rightPairs.begin(), it, pairs.end());
}

std::list<int> mergeSort(const std::list<int> &left, const std::list<int> &right) {
    std::list<int> merged;
    std::list<int>::const_iterator itLeft = left.begin();
    std::list<int>::const_iterator itRight = right.begin();
    while (itLeft != left.end() && itRight != right.end()) {
        if (*itLeft < *itRight)
            merged.push_back(*itLeft++);
        else
            merged.push_back(*itRight++);
    }
    while (itLeft != left.end())
        merged.push_back(*itLeft++);
    while (itRight != right.end())
        merged.push_back(*itRight++);
    return (merged);
}

std::list<int> fordJohnson(std::list<std::pair<int, int> > &pairs) {
    if (pairs.size() <= 1)
        return (handleBaseCase(pairs));
    std::list<std::pair<int, int> > leftPairs, rightPairs;
    splitPairs(pairs, leftPairs, rightPairs);
    std::list<int> leftSorted = fordJohnson(leftPairs);
    std::list<int> rightSorted = fordJohnson(rightPairs);
    return (mergeSort(leftSorted, rightSorted));
}