#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "mysql.h"
#include "Storage.h"


class DataManage
{
public:
	DataManage(const std::string & databasename, const std::string & host, const std::string & user, const std::string & password);

	bool connect_db();

	void saveAll();

private:
	std::shared_ptr<std::string> dataBaseName;
	std::shared_ptr<std::string> host;
	std::shared_ptr<std::string> user;
	std::shared_ptr<std::string> password;

protected:
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
};

