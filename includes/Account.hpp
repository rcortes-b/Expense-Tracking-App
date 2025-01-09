#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "main.hpp"

class Account {
	private:
			char	currency;
			int		total;
			int		monthly_income;
			int		monthly_outcome;
			std::map<std::string, int>	_incomeCategories;
			std::map<std::string, int>	_outcomeCategories;
			std::map<std::string, std::map<std::string, int>>	_accounts;
			//Type: investment,       name:MyInvestor, amount: 4000€
	public:
			Account( void );
			Account( std::string &name);
			Account( Account const &obj );
			Account &operator=( Account const &obj );
			~Account( void );

			
};

#endif