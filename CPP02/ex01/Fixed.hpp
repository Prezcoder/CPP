#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::ostream;

class Fixed
{
	public:
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		Fixed(const Fixed &fixed);
		~Fixed();
		float toFloat( void ) const;
		int toInt( void ) const;

		Fixed &operator=(const Fixed &fixed);
		

		
		int getRawBits(void) const;
		void setRawBits(int const raw);
	


	private:
		int _fixedPointValue;
		static const int _fractionBits = 8;

};

ostream &operator<<(ostream &out, const Fixed &fixed);

#endif