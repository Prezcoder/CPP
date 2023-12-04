
#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>
# include <algorithm>
# include <exception>

using std::cout;
using std::endl;
using std::list;
using std::exception;

class Span
{
	private:
		unsigned int		_number;
		list<int>			_list;
		Span();
	public:
		Span(unsigned int number);
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span();

		void			addNumber(int n);
		void			addNumber(list<int>::const_iterator begin, list<int>::const_iterator end);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		const list<int>	&getList() const;

};

std::ostream& operator<<( std::ostream&, const Span& );

#endif