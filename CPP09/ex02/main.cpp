
#include "PmergeMe.hpp"

void processArgs(int argc, char* argv[], vector<pair<int, int> >& arr) {
	try {
		for (int i = 1; i < argc; i += 2) {
			int firstArg = std::stoi(argv[i]);
			if (firstArg < 0) 
				throw std::invalid_argument("Error: Please provide only positive numbers.");
			int secondArg = (i + 1 < argc) ? std::stoi(argv[i + 1]) : -1;
			if (secondArg < 0 && argc % 2 == 1) 
				throw std::invalid_argument("Error: Please provide only positive numbers.");
			arr.push_back(std::make_pair(firstArg, secondArg));
		}
	}
	catch(const std::exception& e) {
		cout << e.what() << endl;
		exit(1);
	}
	if (argc % 2 == 2)
		arr.back().second = -1;
}

void processArgsDeque(int argc, char* argv[], deque<pair<int, int> >& arr) {
	try {
		for (int i = 1; i < argc; i += 2) {
			int firstArg = std::stoi(argv[i]);
			if (firstArg < 0) 
				throw std::invalid_argument("Error: Please provide only positive numbers.");
			int secondArg = (i + 1 < argc) ? std::stoi(argv[i + 1]) : -1;
			if (secondArg < 0 && argc % 2 == 1) 
				throw std::invalid_argument("Error: Please provide only positive numbers.");
			arr.push_back(std::make_pair(firstArg, secondArg));
		}
	}
	catch(const std::exception& e) {
		cout << e.what() << endl;
		exit(1);
	}
	if (argc % 2 == 2)
		arr.back().second = -1;
}

template <typename Container>
void printContainer(const Container& arr, const string& containerName) {
	cout << "Tableau non trié " << containerName << ":" << endl;
	typename Container::const_iterator it;
	for (it = arr.begin(); it != arr.end(); ++it) {
		cout << "(" << it->first << ", " << it->second << ") " << endl;
	}
	cout << endl;
}

template <typename Container>
void printSortedContainer(const Container& arr, const string& containerName) {
	cout << "Tableau trié " << containerName << ":" << endl;
	typename Container::const_iterator it;
	for (it = arr.begin(); it != arr.end(); ++it) {
		cout << "(" << it->first << ", " << it->second << ") " << endl;
	}
	cout << endl;
}

template <typename Container>
void printValues(const Container& values, const string& valuesName) {
	cout << valuesName << ": ";
	typename Container::const_iterator it;
	for (it = values.begin(); it != values.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

int main(int argc, char** argv) {
	if (argc < 3) {
		cout << "Error: Please provide at least 2 numbers.\n";
		return 1;
	}
	// Vector
	vector<pair<int, int> > arrVector;
	processArgs(argc, argv, arrVector);
	printContainer(arrVector, "Vector");

	clock_t start_time_vector = std::clock();
	PmergeMe sorter;
	sorter.mergeSortPairsHelper(arrVector);
	printSortedContainer(arrVector, "Vector");

	vector<int> secondsVector, lowestVector;
	sorter.separateSecondsAndLowest(arrVector, secondsVector, lowestVector);
	printValues(secondsVector, "Highest Values Vector");
	printValues(lowestVector, "Lowest Values Vector");

	sorter.combineAndSort(secondsVector, lowestVector);
	printValues(secondsVector, "Combined and Sorted Values Vector");
	clock_t end_time_vector = std::clock();

	// Deque
	deque<pair<int, int> > arrDeque;
	processArgsDeque(argc, argv, arrDeque);
	printContainer(arrDeque, "Deque");

	clock_t start_time_deque = std::clock();
	PmergeMe sorterDeque;
	sorterDeque.mergeSortPairsHelper(arrDeque);
	printSortedContainer(arrDeque, "Deque");

	deque<int> secondsDeque, lowestDeque;
	sorterDeque.separateSecondsAndLowest(arrDeque, secondsDeque, lowestDeque);
	printValues(secondsDeque, "Highest Values Deque");
	printValues(lowestDeque, "Lowest Values Deque");

	sorterDeque.combineAndSort(secondsDeque, lowestDeque);
	printValues(secondsDeque, "Combined and Sorted Values Deque");
	clock_t end_time_deque = std::clock();

	// Temps écoulé
	double elapsed_seconds_vector = static_cast<double>(end_time_vector - start_time_vector) / CLOCKS_PER_SEC;
	double elapsed_seconds_deque = static_cast<double>(end_time_deque - start_time_deque) / CLOCKS_PER_SEC;
	cout << "\nTemps écoulé pour le tri du vector de taille: "<< argc - 1 << " : " << std::fixed << std::setprecision(7) << elapsed_seconds_vector << " secondes." << endl;
	cout << "Temps écoulé pour le tri du deque de taille: "<< argc - 1 << " : " << std::fixed << std::setprecision(7) << elapsed_seconds_deque << " secondes." << endl;

	return 0;
}
