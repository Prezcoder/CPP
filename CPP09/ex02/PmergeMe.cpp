
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) { (void)copy; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) { (void)copy; return (*this); }

// merge-sort algorithm that takes numbers from the argv
list<int> PmergeMe::operator()(list<int> &a, list<int> &b)
{
	list<int> result;

	while (!a.empty() && !b.empty())
	{
		if (a.front() < b.front())
		{
			result.push_back(a.front());
			a.pop_front();
		}
		else
		{
			result.push_back(b.front());
			b.pop_front();
		}
	}
	while (!a.empty())
	{
		result.push_back(a.front());
		a.pop_front();
	}
	while (!b.empty())
	{
		result.push_back(b.front());
		b.pop_front();
	}
	return (result);
}

// merge-sort algorithm for vectors that takes numbers from the argv
vector<int> PmergeMe::operator()(vector<int> &a, vector<int> &b)
{
	vector<int> result;

	while (!a.empty() && !b.empty())
	{
		if (a.front() < b.front())
		{
			result.push_back(a.front());
			a.erase(a.begin());
		}
		else
		{
			result.push_back(b.front());
			b.erase(b.begin());
		}
	}
	while (!a.empty())
	{
		result.push_back(a.front());
		a.erase(a.begin());
	}
	while (!b.empty())
	{
		result.push_back(b.front());
		b.erase(b.begin());
	}
	return (result);
}