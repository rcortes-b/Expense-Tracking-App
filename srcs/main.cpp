#include "../includes/main.hpp"

static void	loadDatabase( std::map<std::string, class Account>	&Accounts, std::ifstream &database )
{
	std::string	line = "";
	
	while (std::getline(database, line))
	{
		if (line.find("Account: "));
	}
}

static void	getDatabase( std::map<std::string, class Account>	&Accounts )
{
	/* Possibity of using env variables to get any path of your computer */
	std::ifstream	database(".ExpenseTrackingApp_data");
	if (!database.is_open()) {
		std::ofstream	newFile(".ExpenseTrackingApp_data");
		if (newFile.is_open())
			newFile.close();
		database.open(".ExpenseTrackingApp_data");
		if (!database.is_open())
			throw ThrowError("Error: Database is unavailable");
	}
	loadDatabase(Accounts, database);
}

int main( void )
{
	std::map<std::string, class Account>	Accounts;
	try {
		getDatabase(Accounts);
		if (Accounts.empty()) {
			//setDefaultValues
		}

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	//if (database do not exist)
	//	generate database && setDefaultValues
	//else
	//	read database
	//choose_acc
	//menu()
	//database.close();
	return 0;
}