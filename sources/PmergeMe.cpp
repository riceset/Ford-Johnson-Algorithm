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
        return false;
    }
    if (val < 0) {
        std::cerr << "Error: Negative numbers are not allowed." << std::endl;
        return false;
    }
    return true;
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
    DEBUG_PRINT("Input is valid!");
    return (true);
}

// void insertIntoList(int argc, char **argv, std::list<int> numbers) {}
