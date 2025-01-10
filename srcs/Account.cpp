#include "../includes/Account.hpp"

static std::vector<std::string>	keys = {"Account:", "Summary Status:",
										"Currency:", "Total Heritage:", "Income:",
										"Outcome:", "Income Categories:",
										"Outcome Categories:", "SubAccounts:"};

void	Account::setValues(std::string &line, int i)
{
	switch (i)
	{
	case 0:
		_name = line.substr(keys[i].size());
		break;
	case 1:
		_status = line.substr(keys[i].size());
		break;
	case 2:
		_currency = line.substr(keys[i].size() + 1)[0];
		break;
	case 3:
		_total_heritage = std::atof(line.substr(keys[i].size()).c_str());
		break;
	case 4:
		_total_income = std::atof(line.substr(keys[i].size()).c_str());
		break;
	case 5:
		_total_outcome = std::atof(line.substr(keys[i].size()).c_str());
		break;
	case 6:
		//_total_outcome = std::atof(line.substr(keys[i].size()).c_str());
		break;
	case 7:
		//_total_outcome = std::atof(line.substr(keys[i].size()).c_str());
		break;
	case 8:
		//_total_outcome = std::atof(line.substr(keys[i].size()).c_str());
		break;
	}
}

Account::Account(void)
{

}

Account::Account( std::ifstream &database )
{
	std::string	line = "";
	auto		i = 0;
	while (std::getline(database, line) && line[0] != '\n')
	{
		for (auto i = 0; i < keys.size(); i++) {
			if (line.find(keys[i]) != std::string::npos)
				this->setValues(line, i);
		}
	}
}

Account::Account(std::string &name)
{
	_name = name;
}

Account::Account(Account const &obj)
{
	if (this != &obj)
		*this = obj;
}

Account	&Account::operator=(Account const &obj)
{
	*this = obj;
	return *this;
}

Account::~Account(void)
{

}
