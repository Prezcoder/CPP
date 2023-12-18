
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <utility>

using std::cout;
using std::endl;
using std::cerr;
using std::vector;
using std::pair;
using std::deque;
using std::string;

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

		size_t findInsertPosition(const deque<int>& arr, int value);
		void combineAndSort(deque<int>& highest, const deque<int>& lowest);
		void mergeSortPairsHelper(deque<pair<int, int> >& arr);
		void separateSecondsAndLowest(const deque<pair<int, int> >& arr, deque<int>& seconds, deque<int>& lowest);

	private:


};



#endif