#include "pch.h"
#include "DataManage.h"


DataManage::DataManage(const std::string &databasename, const std::string & host, const std::string & user, const std::string & password)
{
	this->dataBaseName = std::make_shared<std::string>(databasename);
	this->host = std::make_shared<std::string>(host);
	this->user = std::make_shared<std::string>(user);
	this->password = std::make_shared<std::string>(password);
}

bool DataManage::connect_db()
{
	const char*h = this->host.get()->c_str();
	const char*u = this->user.get()->c_str();
	const char*p = this->password.get()->c_str();
	const char*n = this->dataBaseName.get()->c_str();
	conn = mysql_init(NULL);//initialization connect
	conn = mysql_real_connect(conn, h, u, p, n, 3306, NULL, 0);//set parametrs of connection
	if (conn)//if sucñessful connect
	{
		std::cout << "Successful connection to database!" << std::endl;//print
		return true;
	}
	else{
		std::cout << "Connection to database has failed!" << std::endl;
		return false;
	}
}

void DataManage::saveAll()
{
	mysql_commit(conn);//commit changes
}
