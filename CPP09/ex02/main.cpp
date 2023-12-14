
#include "PmergeMe.hpp"

void processArgs(int argc, char* argv[], std::vector<std::pair<int, int> >& arr) {
	for (int i = 1; i < argc; i += 2) {
		int firstArg = std::stoi(argv[i]);
		int secondArg = (i + 1 < argc) ? std::stoi(argv[i + 1]) : -1;
		arr.push_back(std::make_pair(firstArg, secondArg));
	}

	// If the number of pairs is odd, fill the second half of the last pair with -1
	if (argc % 2 == 2)
		arr.back().second = -1;
}

int main(int argc, char** argv) {
	if (argc < 3) {
		std::cerr << "Error: Please provide at least 2 numbers.\n";
		return 1;
	}
	// Vector
	vector<std::pair<int, int> > arr;
	processArgs(argc, argv, arr);
	cout << "Tableau non trié:" << endl;
	for (std::vector<std::pair<int, int> >::iterator it = arr.begin(); it != arr.end(); ++it) {
		std::cout << "(" << it->first << ", " << it->second << ") " << endl;
	}
	cout << endl;

	clock_t start_time_vector = std::clock();
	PmergeMe sorter;
	sorter.mergeSortPairsHelper(arr);

	cout << "Tableau trié : " << endl;
	for (vector<std::pair<int, int> >::iterator it = arr.begin(); it != arr.end(); ++it) {
		cout << "(" << it->first << ", " << it->second << ") " << endl;
	}
	cout << endl;
	vector<int> seconds, lowest;
	sorter.separateSecondsAndLowest(arr, seconds, lowest);

	cout << "Highest Values: ";
	for (size_t i = 0; i < seconds.size(); ++i) {
		cout << seconds[i] << " ";
	}

	cout << "\nLowest Values: ";
	for (size_t i = 0; i < lowest.size(); ++i) {
		cout << lowest[i] << " ";
	}
	cout << endl;
	sorter.combineAndSort(seconds, lowest);

	cout << "Combined and Sorted Values: ";
	for (size_t i = 0; i < seconds.size(); ++i) {
		cout << seconds[i] << " ";
	}
	cout << endl;
	clock_t end_time_vector = std::clock();
	// Temps écoulé
	double elapsed_seconds_vector = static_cast<double>(end_time_vector - start_time_vector) / CLOCKS_PER_SEC;
	cout << "\nTemps écoulé pour le tri du vector de taille: "<< argc - 1 << " : " << std::fixed << std::setprecision(7) << elapsed_seconds_vector << " secondes." << endl;

	return 0;
}
