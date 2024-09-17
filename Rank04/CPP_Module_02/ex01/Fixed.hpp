#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed{
	private:

	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

	public:

	Fixed(void);
	Fixed(int const n);
	Fixed(float const f);
	Fixed(Fixed const &src);
	Fixed &operator=(Fixed const &src);
	~Fixed(void);

	int		getRawBits(void) const;
	float	toFloat( void ) const;
	int		toInt( void ) const;
	void	setRawBits(int const raw);
};

	std::ostream &operator<<(std::ostream &out, Fixed const &src);

#endif