#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

class mysql
{
private:
	const std::string server = "tcp://127.0.0.1:3306";
	const std::string username = "pytest";
	const std::string password = "pytest";

	sql::Driver* driver;
	sql::Connection* con;

public:
	mysql();
	~mysql();

	void save_data(int mode, int x, int y, int time);

	void load_data(int& mode, int& x, int& y, int& time);
};

