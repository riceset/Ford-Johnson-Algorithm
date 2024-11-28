#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    std::list<int> numbers;
    std::list<int> sorted;

    std::list<std::pair<int, int> > pairs;
    int struggler;

    if (!validInput(argc, argv))
        return (EXIT_FAILURE);
    insertIntoList(argc, argv, numbers);
    pairs = groupListIntoPairs(numbers, struggler);
    sorted = fordJohnson(pairs);
    if (struggler != NO_STRUGGLER)
        sorted.push_back(struggler);
#ifdef DEBUG
    printList(numbers);
    printList(sorted);
    // printPairs(pairs, struggler);
#endif
    return (EXIT_SUCCESS);
}