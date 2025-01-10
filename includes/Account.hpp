#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "main.hpp"

class Account {
	private:
			std::string	_name;
			std::string	_status; //Daily, Weekly, Monthly, Yearly
			char		_currency; //€, $, ...
			float			_total_heritage; //total current heritage
			float			_total_income; //total since start
			float			_total_outcome; //total since start
			std::map<std::string, float>	_incomeCategories;
			std::map<std::string, float>	_outcomeCategories;
			std::map<std::string, std::map<std::string, float>>	_subAccounts;
			//Type: investment,       name:MyInvestor, amount: 4000€
	public:
			Account( void );
			Account( std::ifstream &database );
			Account( std::string &name);
			Account( Account const &obj );
			Account &operator=( Account const &obj );
			~Account( void );

			//Getters
			std::string	const	&getName( void ) { return _name; }
			std::string const	&getStatus( void ) { return _status; }
			char				getCurrency( void ) { return _currency; }
			float					getTotalHeritage( void ) { return _total_heritage; }
			float					getTotalIncome( void ) { return _total_income; }
			float					getTotalOutcome( void ) { return _total_outcome; }
			std::map<std::string, float> const	&getIncomeCategories( void ) { return _incomeCategories; }
			std::map<std::string, float> const	&getOutcomeCategories( void ) { return _outcomeCategories; }
			std::map<std::string, float> const	&getTypeAccount( std::string &key ) { return _subAccounts[key]; }
			std::map<std::string, std::map<std::string, float>> const	&getSubAccounts( void ) { return _subAccounts; }

			//Setters
			void	setName( std::string name ) { _name = name; }
			void	setStatus( std::string status ) { _status = status; }
			void	setCurrency( char currency ) { _currency = currency; }
			void	addHeritage( float amount ) { _total_heritage += amount; }
			void	substractHeritage( float amount ) { _total_heritage -= amount; }
			void	addIncome( float amount ) { _total_income += amount; }
			void	substractIncome( float amount ) { _total_income -= amount; }
			void	addOutcome( float amount ) { _total_outcome += amount; }
			void	substractOutcome( float amount ) { _total_outcome -= amount; }

			void	setValues(std::string &line, int i);
			void	loadIncomeCategories(void); //etc...
};

#endif