
#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc < 2) {
		cerr << "Usage: " << argv[0] << " <num1> <num2> ... <numN>" << endl;
		return 1;
	}
	uint32_t threshold = 2;
	vector<std::pair<int, int> > arr;
	list<std::pair<int, int> > arrlist;
	PmergeMe pmergeMelist;

	// Vector
	for (int i = 1; i < argc; i += 2) {
		arr.push_back(std::make_pair(std::stoi(argv[i]), std::stoi(argv[i + 1])));
	}
	cout << "Tableau non trié:" << endl;
	for (std::vector<std::pair<int, int> >::iterator it = arr.begin(); it != arr.end(); ++it) {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
	
	cout << endl;

	clock_t start_time_vector = std::clock();
	
	PmergeMe sorter;
    sorter.mergeSortPairs(arr);
	std::vector<int> result = sorter.mergeSortedPairs(arr);
	clock_t end_time_vector = std::clock();

	// List
	for (int i = 1; i < argc; ++i) {
		arrlist.push_back(std::make_pair(std::stoi(argv[i]), i));
	}

	clock_t start_time_list = std::clock();
	pmergeMelist.mergeInsertionSortList(arrlist, threshold);
	clock_t end_time_list = std::clock();

	cout << "Tableau trié : ";
	for (std::vector<int>::const_iterator it = result.begin(); it != result.end(); ++it) {
		std::cout << *it << " ";
	}
	cout << endl;

	// Temps écoulé
	double elapsed_seconds_vector = static_cast<double>(end_time_vector - start_time_vector) / CLOCKS_PER_SEC;
	double elapsed_seconds_list = static_cast<double>(end_time_list - start_time_list) / CLOCKS_PER_SEC;
	cout << "\nTemps écoulé pour le tri du vector de taille: "<< arr.size() << " : " << std::fixed << std::setprecision(7) << elapsed_seconds_vector << " secondes." << endl;
	cout << "\nTemps écoulé pour le tri de la liste de taille: "<< arrlist.size() << " : " << std::fixed << std::setprecision(7) << elapsed_seconds_list << " secondes." << endl;

	return 0;
}
