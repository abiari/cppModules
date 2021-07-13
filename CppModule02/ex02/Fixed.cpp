/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 15:50:54 by abiari            #+#    #+#             */
/*   Updated: 2021/07/13 21:12:08 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->_fixedPointValue = 0;
}

Fixed::Fixed( int const nbr)
{
	std::cout << "Int constructor called\n";
	this->setRawBits(nbr * (1 << Fixed::_fractionalBitsNumber));
}

Fixed::Fixed( float const nbr)
{
	std::cout << "Float constructor called\n";
	this->setRawBits(roundf(nbr * (1 << Fixed::_fractionalBitsNumber)));
}

Fixed::Fixed( const Fixed & src )
{
	std::cout << "Copy constructor called\n";
	// this->_fixedPointValue = src.getRawBits(); <--- This works too
	this->operator=(src);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Assignation operator called\n";
	if ( this != &rhs )
	{
		this->_fixedPointValue = rhs.getRawBits();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}

bool		Fixed::operator>( Fixed const & rhs )
{
	return this->_fixedPointValue > rhs.getRawBits();
}

bool		Fixed::operator<( Fixed const & rhs )
{
	return this->_fixedPointValue < rhs.getRawBits();
}

bool		Fixed::operator<=( Fixed const & rhs )
{
	return this->_fixedPointValue <= rhs.getRawBits();
}

bool		Fixed::operator>=( Fixed const & rhs )
{
	return this->_fixedPointValue >= rhs.getRawBits();
}

bool		Fixed::operator==( Fixed const & rhs )
{
	return this->_fixedPointValue == rhs.getRawBits();
}

bool		Fixed::operator!=( Fixed const & rhs )
{
	return this->_fixedPointValue != rhs.getRawBits();
}


Fixed &		Fixed::operator+( Fixed const & rhs )
{
	this->_fixedPointValue += rhs.getRawBits();
	return *this;
}

Fixed &		Fixed::operator-( Fixed const & rhs )
{
	this->_fixedPointValue -= rhs.getRawBits();
	return *this;
}

Fixed &		Fixed::operator*( Fixed const & rhs )
{
	this->_fixedPointValue *= rhs.getRawBits();
	return *this;
}

Fixed &		Fixed::operator/( Fixed const & rhs )
{
	this->_fixedPointValue /= rhs.getRawBits();
	return *this;
}


Fixed &		Fixed::operator++()
{
	this->_fixedPointValue++;
	return *this;
}

Fixed &		Fixed::operator--()
{
	this->_fixedPointValue--;
	return *this;
}

Fixed		Fixed::operator++( int )
{
	Fixed copyInstance = Fixed(*this);
	this->_fixedPointValue++;
	return copyInstance;
}

Fixed		Fixed::operator--( int )
{
	Fixed copyInstance = Fixed(*this);
	this->_fixedPointValue--;
	return copyInstance;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

float	Fixed::toFloat( void ) const
{
	return ((float)getRawBits() / (float)(1 << Fixed::_fractionalBitsNumber));
}

int		Fixed::toInt( void ) const
{
	return ((int)(getRawBits() / (1 << Fixed::_fractionalBitsNumber)));
}

Fixed &	Fixed::min( Fixed& value1, Fixed& value2 )
{
	if (value1.getRawBits() < value2.getRawBits())
		return value1;
	return value2;
}

Fixed &	Fixed::min( Fixed& const value1, Fixed& const value2 )
{
	
}

Fixed &	Fixed::max( Fixed& value1, Fixed& value2 )
{
	if (value1.getRawBits() > value2.getRawBits())
		return value1;
	return value2;
}

Fixed &	Fixed::max( Fixed& const value1, Fixed& const value2 )
{
	
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int		Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called\n";
	return this->_fixedPointValue;
}

void	Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called\n";
	this->_fixedPointValue = raw;
}

/* ************************************************************************** */
