
#include "Span.hpp"

Span::Span(unsigned int number) : _number(number) {
}

Span::Span(const Span &copy) {
	*this = copy;
}

Span &Span::operator=(const Span &copy) {
	if (this != &copy)
	{
		_number = copy._number;
		_list = copy._list;
	}
	return (*this);
}

Span::~Span() {
}

void	Span::addNumber(int number) {
	if (_list.size() >= _number)
		throw std::out_of_range("List is full");
	_list.push_back(number);
}

void	Span::addNumber(list<int>::const_iterator begin, list<int>::const_iterator end) {
	if (_list.size() + std::distance(begin, end) > _number)
		throw std::out_of_range("List is full");
	_list.insert(_list.end(), begin, end);
}

unsigned int	Span::shortestSpan( void ) const {
	if ( _list.size() < 2 )
		throw std::out_of_range("list is empty");
	unsigned int  min = Span::longestSpan();
	for ( std::list<int>::const_iterator it = _list.begin(); it != _list.end(); ++it ) {
		for ( std::list<int>::const_iterator it2 = _list.begin(); it2 != _list.end(); ++it2 ) {
			if ( it == it2 ) continue;
			if ( std::abs( *it2 - *it ) <  static_cast< int >( min ) )
				min = std::abs( *it2 - *it );
		}
	}
	return min;
}

unsigned int	Span::longestSpan( void ) const {
	if ( _list.size() < 2 )
		throw std::out_of_range("list is empty");
	return ( *std::max_element( _list.begin(), _list.end() ) - *std::min_element( _list.begin(), _list.end() ) );
}

const list<int>	&Span::getList() const {
	return (_list);
}

std::ostream& operator<<( std::ostream& os, const Span& span ) {
	for ( std::list<int>::const_iterator it = span.getList().begin(); it != span.getList().end(); ++it )
		os << *it << " ";
	return os;
}