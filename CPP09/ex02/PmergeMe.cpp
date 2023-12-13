
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) { (void)copy; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
	if (this != &copy)
		*this = copy;
	return *this;
}

// Vector
bool pairComparator(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}

void PmergeMe::mergeSortPairs(vector<pair<int, int> >& arr) {
	for (vector<pair<int, int> >::iterator it = arr.begin(); it != arr.end(); ++it) {
		std::sort(&(*it), &(*it) + 1, pairComparator);
	}
}

vector<int> PmergeMe::mergeSortedPairs(const vector<pair<int, int> >& arr) {
    vector<int> sortedFirst;
    vector<int> sortedSecond;

    // Extraire les 'first' et 'second' et les trier individuellement
    for (vector<pair<int, int> >::size_type i = 0; i < arr.size(); ++i) {
        sortedFirst.push_back(arr[i].first);
        sortedSecond.push_back(arr[i].second);
    }

    // Trier les listes individuelles
    std::sort(sortedFirst.begin(), sortedFirst.end());
    std::sort(sortedSecond.begin(), sortedSecond.end());

    // Fusionner les deux listes triées
    vector<int> result;
    vector<int>::size_type i = 0;
    vector<int>::size_type j = 0;

    while (i < sortedFirst.size() && j < sortedSecond.size()) {
        if (sortedFirst[i] < sortedSecond[j]) {
            result.push_back(sortedFirst[i++]);
        } else {
            result.push_back(sortedSecond[j++]);
        }
    }

    // Ajouter les éléments restants, s'il y en a
    while (i < sortedFirst.size()) {
        result.push_back(sortedFirst[i++]);
    }

    while (j < sortedSecond.size()) {
        result.push_back(sortedSecond[j++]);
    }

    return result;
}

vector<int> PmergeMe::mergePairs(const vector<int>& arr1, const vector<int>& arr2) {
	vector<int> merged;
	vector<int>::const_iterator it1 = arr1.begin();
	vector<int>::const_iterator it2 = arr2.begin();

	while (it1 != arr1.end() && it2 != arr2.end()) {
		if (*it1 < *it2) {
			merged.push_back(*it1);
			++it1;
		} else {
			merged.push_back(*it2);
			++it2;
		}
	}
	while (it1 != arr1.end()) {
		merged.push_back(*it1);
		++it1;
	}
	while (it2 != arr2.end()) {
		merged.push_back(*it2);
		++it2;
	}
	return merged;
}

// List
void PmergeMe::insertionSortList(list<pair<int, int> >& arr) {
	for (list<pair<int, int> >::iterator it = ++arr.begin(); it != arr.end(); ++it) {
		pair<int, int> key = *it;
		list<pair<int, int> >::iterator j = it;
		while (j != arr.begin() && key.second < (--j)->second) {
			std::advance(j, 1);
			*j = *--j;
		}
		*j = key;
	}
}

void PmergeMe::mergeList(list<pair<int, int> >& arr, const list<pair<int, int> >& left, const list<pair<int, int> >& right) {
	list<pair<int, int> >::iterator it = arr.begin();
	list<pair<int, int> >::const_iterator leftIt = left.begin();
	list<pair<int, int> >::const_iterator rightIt = right.begin();

	while (leftIt != left.end() && rightIt != right.end()) {
		if (leftIt->second < rightIt->second)
			*it++ = *leftIt++;
		else
			*it++ = *rightIt++;
	}
	while (leftIt != left.end())
		*it++ = *leftIt++;
	while (rightIt != right.end())
		*it++ = *rightIt++;
}

void PmergeMe::mergeInsertionSortList(list<pair<int, int> >& arr, uint32_t threshold) {
	if (arr.size() > threshold) {
		uint32_t mid = arr.size() / 2;
		list<pair<int, int> > left(arr.begin(), arr.begin());
		list<pair<int, int> > right(arr.begin(), arr.begin());
		list<pair<int, int> >::iterator it = arr.begin();
		for (uint32_t i = 0; i < mid; ++i) {
			left.push_back(*it++);
		}
		for (uint32_t i = mid; i < arr.size(); ++i) {
			right.push_back(*it++);
		}
		mergeInsertionSortList(left, threshold);
		mergeInsertionSortList(right, threshold);
		mergeList(arr, left, right);
	}
	else
		insertionSortList(arr);
}