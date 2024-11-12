#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    std::list<int> numbers;

    if (!validInput(argc, argv))
        return (EXIT_FAILURE);
    insertIntoList(argc, argv, numbers);
#ifdef DEBUG
    printList(numbers);
#endif
    return (EXIT_SUCCESS);
}