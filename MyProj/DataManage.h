#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "mysql.h"
#include "Storage.h"


class DataManage
{
public:
	DataManage(const std::string & databasename);

	bool connect_db(const std::string &host, const std::string &user, const std::string &password);

	void saveAll();

private:
	std::shared_ptr<std::string> dataBaseName;

protected:
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
};

