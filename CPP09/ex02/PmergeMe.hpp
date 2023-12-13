
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <list>
#include <ctime>
#include <iomanip>
#include <utility>

using std::cout;
using std::endl;
using std::cerr;
using std::vector;
using std::list;
using std::pair;

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &copy);
		void mergeSortPairs(vector<std::pair<int, int> >& arr);
		vector<int> mergePairs(const vector<int>& arr1, const vector<int>& arr2);
		vector<int> mergeSortedPairs(const vector<pair<int, int> >& arr);
		
		void mergeInsertionSortList(list<pair<int, int> >& arr, uint32_t threshold);
		
	private:

		void insertionSortList(list<pair<int, int> >& arr);
		void mergeList(list<pair<int, int> >& arr, const list<pair<int, int> >& left, const list<pair<int, int> >& right);


};



#endif