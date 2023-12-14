
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

		void mergeSortPairsHelper(vector<pair<int, int> > &arr);
		void separateSecondsAndLowest(const vector<pair<int, int> >& arr, vector<int>& seconds, vector<int>& lowest);
		void combineAndSort(vector<int>& highest, const vector<int>& lowest);
		size_t findInsertPosition(const vector<int>& arr, int value);

	private:


};



#endif