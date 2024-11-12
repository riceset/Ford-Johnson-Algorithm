#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    std::list<int> numbers;

    if (!validInput(argc, argv))
        return (EXIT_FAILURE);
    insertIntoList(argc, argv, numbers);
    printList(numbers);
    return (EXIT_SUCCESS);
}