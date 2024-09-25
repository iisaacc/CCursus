#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
	private:

	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

	public:

	//-----------------CONSTRUCT & DESTRUCT------------------
	Fixed(void);
	Fixed(int const n);
	Fixed(float const f);
	Fixed(Fixed const &src);
	~Fixed(void);

	//-----------------------OPERATORS------------------------
	Fixed	&operator=(Fixed const &src);
	Fixed	&operator++();		//++FIXED
	Fixed	operator++(int);	//FIXED++
	Fixed	&operator--();		//--FIXED
	Fixed	operator--(int);	//FIXED--

	bool	operator<(Fixed const &other) const;
	bool	operator>(Fixed const &other) const;
	bool	operator<=(Fixed const &other) const;
	bool	operator>=(Fixed const &other) const;
	bool	operator==(Fixed const &other) const;
	bool	operator!=(Fixed const &other) const;

	float	operator+(Fixed const &other) const;
	float	operator-(Fixed const &other) const;
	float	operator*(Fixed const &other) const;
	float	operator/(Fixed const &other) const;

	//------------------GETTERS & SETTERS---------------------
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	//------------------------METHODS-------------------------
	float	toFloat( void ) const;
	int		toInt( void ) const;
	static const Fixed	&min(Fixed const &copy1, Fixed const &copy2);
	static const Fixed	&max(Fixed const &copy1, Fixed const &copy2);
};

	std::ostream &operator<<(std::ostream &out, Fixed const &src);

#endif
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

	//-----------------CONSTRUCT & DESTRUCT------------------
	Fixed(void);
	Fixed(int const n);
	Fixed(float const f);
	Fixed(Fixed const &src);
	~Fixed(void);

	//-----------------------OPERATORS------------------------
	Fixed	&operator=(Fixed const &src);
	Fixed	&operator++();		//++FIXED
	Fixed	operator++(int);	//FIXED++
	Fixed	&operator--();		//--FIXED
	Fixed	operator--(int);	//FIXED--

	bool	operator<(Fixed const &other) const;
	bool	operator>(Fixed const &other) const;
	bool	operator<=(Fixed const &other) const;
	bool	operator>=(Fixed const &other) const;
	bool	operator==(Fixed const &other) const;
	bool	operator!=(Fixed const &other) const;

	float	operator+(Fixed const &other) const;
	float	operator-(Fixed const &other) const;
	float	operator*(Fixed const &other) const;
	float	operator/(Fixed const &other) const;

	//------------------GETTERS & SETTERS---------------------
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	//------------------------METHODS-------------------------
	float	toFloat( void ) const;
	int		toInt( void ) const;
	static const Fixed	&min(Fixed const &copy1, Fixed const &copy2);
	static const Fixed	&max(Fixed const &copy1, Fixed const &copy2);
};

	std::ostream &operator<<(std::ostream &out, Fixed const &src);

#endif