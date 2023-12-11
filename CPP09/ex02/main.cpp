
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Usage: ./a.out [list of numbers]" << std::endl;
		return 1;
	}
	// need to create the merge
	PmergeMe merge;
	// need to create a list of numbers
	std::list<int> numbers;
	// need to fill the list with the numbers from the argv
	for (int i = 1; i < argc; i++) {
		numbers.push_back(atoi(argv[i]));
	}
	// need to sort the list
	numbers.sort();
	// need to print the list
	std::cout << "List: ";
	for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	// need to create a vector of numbers
	std::vector<int> numbers2;
	// need to fill the vector with the numbers from the argv
	for (int i = 1; i < argc; i++) {
		numbers2.push_back(atoi(argv[i]));
	}
	// need to sort the vector
	std::sort(numbers2.begin(), numbers2.end());
	// need to print the vector
	std::cout << "Vector: ";
	for (std::vector<int>::iterator it = numbers2.begin(); it != numbers2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return 0;
}