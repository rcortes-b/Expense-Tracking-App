#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>

#include "Account.hpp"

class ThrowError : public std::exception {
	private:
			std::string	_err_msg;
	public:
			ThrowError( std::string const err_msg ) {
				_err_msg = err_msg;
			}
			virtual ~ThrowError( void ) throw() {};
			virtual const char	*what( void ) const throw() {
				return _err_msg.c_str();
			}
};

#endif