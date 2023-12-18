
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) { (void)copy; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
	if (this != &copy)
		*this = copy;
	return *this;
}

static int jacobsthal(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	int prev = 0;
	int current = 1;
	
	for (int i = 2; i <= n; ++i) {
		int next = current + 2 * prev;
		prev = current;
		current = next;
	}
	return current;
}

// Vector

size_t PmergeMe::findInsertPosition(const vector<int>& arr, int value) {
	return std::lower_bound(arr.begin(), arr.end(), value) - arr.begin();
}

void PmergeMe::combineAndSort(vector<int>& highest, const vector<int>& lowest) {
	size_t highestIndex = 0;
	size_t lowestIndex = 0;
	vector<int> result;

	while (lowestIndex < lowest.size() || highestIndex < highest.size()) {
		int jacobsthalLowest = (lowestIndex < lowest.size()) ? jacobsthal(lowestIndex) : std::numeric_limits<int>::max();
		int jacobsthalHighest = (highestIndex < highest.size()) ? jacobsthal(highestIndex) : std::numeric_limits<int>::max();
		if (jacobsthalLowest < jacobsthalHighest) {
			size_t insertPos = findInsertPosition(result, lowest[lowestIndex]);
			result.insert(result.begin() + insertPos, lowest[lowestIndex]);
			++lowestIndex;
		}
		else {
			result.push_back(highest[highestIndex]);
			++highestIndex;
		}
	}
	highest.swap(result);
}

void PmergeMe::mergeSortPairsHelper(vector<pair<int, int> >& arr) {
	if (arr.size() > 1) {
		for (size_t i = 0; i < arr.size(); ++i) {
			if (arr[i].second != -1 && arr[i].first > arr[i].second)
				std::swap(arr[i].first, arr[i].second);
		}
		bool swapped;
		int maxIterations = arr.size();
		int iterations = 0;
		do {
			swapped = false;
			for (size_t i = 0; i < arr.size() - 1; ++i) {
				if (arr[i].second > arr[i + 1].second || (arr[i].second == -1 && arr[i + 1].second != -1)) {
					std::swap(arr[i], arr[i + 1]);
					swapped = true;
				}
			}
			iterations++;
		} while (swapped && iterations < maxIterations);
	}
}

void PmergeMe::separateSecondsAndLowest(const vector<pair<int, int> >& arr, vector<int>& seconds, vector<int>& lowest) {
	seconds.clear();
	lowest.clear();

	for (size_t i = 0; i < arr.size(); ++i) {
		if (arr[i].second != -1)
			seconds.push_back(arr[i].second);
		lowest.push_back(arr[i].first);
	}
}

// Deque

size_t PmergeMe::findInsertPosition(const deque<int>& arr, int value) {
	return std::lower_bound(arr.begin(), arr.end(), value) - arr.begin();
}

void PmergeMe::combineAndSort(deque<int>& highest, const deque<int>& lowest) {
	size_t highestIndex = 0;
	size_t lowestIndex = 0;
	deque<int> result;

	while (lowestIndex < lowest.size() || highestIndex < highest.size()) {
		int jacobsthalLowest = (lowestIndex < lowest.size()) ? jacobsthal(lowestIndex) : std::numeric_limits<int>::max();
		int jacobsthalHighest = (highestIndex < highest.size()) ? jacobsthal(highestIndex) : std::numeric_limits<int>::max();
		if (jacobsthalLowest < jacobsthalHighest) {
			size_t insertPos = findInsertPosition(result, lowest[lowestIndex]);
			result.insert(result.begin() + insertPos, lowest[lowestIndex]);
			++lowestIndex;
		}
		else {
			result.push_back(highest[highestIndex]);
			++highestIndex;
		}
	}
	highest.swap(result);
}

void PmergeMe::mergeSortPairsHelper(deque<pair<int, int> >& arr) {
	if (arr.size() > 1) {
		for (size_t i = 0; i < arr.size(); ++i) {
			if (arr[i].second != -1 && arr[i].first > arr[i].second)
				std::swap(arr[i].first, arr[i].second);
		}
		bool swapped;
		int maxIterations = arr.size();
		int iterations = 0;
		do {
			swapped = false;
			for (size_t i = 0; i < arr.size() - 1; ++i) {
				if (arr[i].second > arr[i + 1].second || (arr[i].second == -1 && arr[i + 1].second != -1)) {
					std::swap(arr[i], arr[i + 1]);
					swapped = true;
				}
			}
			iterations++;
		} while (swapped && iterations < maxIterations);
	}
}

void PmergeMe::separateSecondsAndLowest(const deque<pair<int, int> >& arr, deque<int>& seconds, deque<int>& lowest) {
	seconds.clear();
	lowest.clear();

	for (size_t i = 0; i < arr.size(); ++i) {
		if (arr[i].second != -1)
			seconds.push_back(arr[i].second);
		lowest.push_back(arr[i].first);
	}
}
