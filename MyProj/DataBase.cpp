#include "pch.h"
#include "DataBase.h"
#include "mysql.h"


//WORK WITH DATABASE

DataBase::DataBase(const std::string &dataBaseName, const std::string & host, const std::string & user, const std::string & password)
{
	this->dataBaseName = std::make_shared<std::string>(dataBaseName);
	this->host = std::make_shared<std::string>(host);
	this->user = std::make_shared<std::string>(user);
	this->password = std::make_shared<std::string>(password);
}

bool DataBase::connect_db()
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
	else {
		std::cout << "Connection to database has failed!" << std::endl;
		return false;
	}
}

void DataBase::queryRequest(const std::string & quer)
{
	std::string query = quer;//appropriation variable
	const char* q = query.c_str();//convert to const char
	mysql_query(conn, q);//query request
}

void DataBase::queryRequestWithResult(const std::string & query)
{
	queryRequest(query);//send a request
	res = mysql_store_result(conn);//get result
}

bool DataBase::checkForEmpty()
{
	int rows = mysql_num_rows(res);//get count of rows in table
	if (rows > 0) return true;//check
	else return false;
}

void DataBase::saveAll()
{
	mysql_commit(conn);//commit changes
}

DataBase::~DataBase()//CLOSE CONNECTION TO DB
{
	delete res;//delete result
	mysql_close(conn);//close connection
	delete conn;//delete connection
}

//WORK WITH TABLE VEGETABLE

bool DataBase::print_vegetable()
{
	std::string query = "SELECT * FROM vegetable;"; //query request
	queryRequestWithResult(query);//request with return result
	if (checkForEmpty()) {
		std::cout << "ID\tName vegetable" << std::endl;
		while (row = mysql_fetch_row(res))//as long as there are deadlines
			printf("%s: \t%s\n", row[0], row[1]);//print result
		return true;
	}
	return false;
}

std::string DataBase::get_name_veg(const int &id)
{
	auto temp = std::to_string(id);//convert to string
	std::string query = "SELECT NAME_VEG FROM vegetable WHERE ID = " + temp + ";"; //creation query request
	queryRequestWithResult(query);//request with return result
	std::string value;//value for save
	row = mysql_fetch_row(res);//assigning to arr
	value = row[0];// assigning to variable
	return value; //return result
}

void DataBase::add_name_veg(const std::string &val)
{
	std::string query = ("INSERT INTO vegetable(NAME_VEG) VALUES('" + val + "');");//query request
	queryRequest(query);// send a request
}

void DataBase::del_name_veg(const int &id)
{
	auto temp = std::to_string(id);//convert to string
	std::string query = "DELETE FROM vegetable WHERE ID = " + temp + ";";//query request
	queryRequest(query);// send a request
}

bool DataBase::check_ID_veg(const int & id)
{
	int ID = id;
	std::string query = "SELECT ID FROM vegetable";
	queryRequestWithResult(query);//request with return result
	while (row = mysql_fetch_row(res))//as long as there are deadlines
		if (std::to_string(ID) == row[0]) return true;
	return false;
}

//WORK WITH TABLES

bool DataBase::print_from_stor_room(const std::string & tablename)
{
	std::string t_name = tablename;//get value
	std::string query = "SELECT * FROM " + t_name + ";";
	queryRequestWithResult(query);//request with return result
	if (checkForEmpty()) {
		std::cout << "ID\tName veget\tCount Prod\tDelivery Date" << std::endl;
		while (row = mysql_fetch_row(res))//as long as there are deadlines
			printf("%s: \t%s\t\t%s\t\t%s\n", row[0], row[1], row[2], row[3]);//print result with conversation lines
		return true;
	}
	return false;
}

void DataBase::create_new_table(const std::string &tablename)
{
	std::string t_name = tablename;
	std::string query = "CREATE TABLE " + t_name + "(ID INT AUTO_INCREMENT PRIMARY KEY, NAME_VEG VARCHAR(20), CountProd INT DEFAULT 0, DeliveryDate DATETIME NOT NULL);";
	queryRequest(query);// send a request
}

void DataBase::addBatch(const std::string & name_vegetable, const int & count_product)
{
	std::string query = "INSERT INTO " + name_vegetable + "(NAME_VEG, CountProd, DeliveryDate) VALUES('" + name_vegetable + "', " + std::to_string(count_product) + ", NOW());";
	queryRequest(query);// send a request
}

int DataBase::get_count(const std::string & name_vegetable, const int & id)
{
	std::string query = "SELECT CountProd FROM " + name_vegetable + " WHERE ID = " + std::to_string(id) + " LIMIT 1;";
	queryRequestWithResult(query);//request with return result
	std::string value;//value for save
	row = mysql_fetch_row(res);//assigning to arr
	value = row[0];// assigning to variable
	return std::atoi(value.c_str()); //return result convert to int
}

void DataBase::dellBatch(const std::string & name_vegetable, const int & id)
{
	std::string query = "DELETE FROM " + name_vegetable + " WHERE ID = " + std::to_string(id);
	queryRequest(query);// send a request
}

bool DataBase::changeCount(const std::string & name_vegetable, const int & id, const int & change_count)
{
	int count_form_table = get_count(name_vegetable, id);//set result from function
	int count_from_user = change_count;//get count from user
	if (count_form_table > count_from_user) {
		int changed_count = count_form_table - count_from_user;
		std::string query = "UPDATE " + name_vegetable + " SET CountProd = " + std::to_string(changed_count) + " WHERE ID = " + std::to_string(id) + ";";
		queryRequest(query);// send a request
		return true;
	}
	else if (count_form_table == count_from_user) {
		dellBatch(name_vegetable, id);
		return true;
	}
	else return false;
}

bool DataBase::check_ID(const int & ID, const std::string & name_veg)
{
	std::string t_name = name_veg;
	int id = ID;
	std::string query = "SELECT ID FROM " + t_name + ";";
	queryRequestWithResult(query);//request with return result
	while (row = mysql_fetch_row(res))//as long as there are deadlines
		if (std::to_string(id) == row[0])
			return true;
	return false;
}

void DataBase::drop_table(const std::string &tablename)
{
	std::string t_name = tablename;
	std::string query = "DROP TABLE " + t_name + ";";
	queryRequest(query);// send a request
}

//FUNCTIONS FOR ARCHIVE

bool DataBase::print_all_archive()
{
	std::string query = "SELECT * FROM Archive;";
	queryRequestWithResult(query);//request with return result
	if (checkForEmpty())
	{
		std::cout << "ID\tName veget\tCount Prod\tUnloading Date" << std::endl;
		while (row = mysql_fetch_row(res))//as long as there are deadlines
			printf("%s: \t%s\t\t%s\t\t%s\n", row[0], row[1], row[2], row[3]);//print result with conversation lines
		return true;
	}
	return false;
}

void DataBase::AddToArchive(const std::string & name_vegetable, const int & count_product)
{
	std::string query = "INSERT INTO Archive(NAME_VEG, CountProd, UnloadingDate) VALUES('" + name_vegetable + "'," + std::to_string(count_product) + ", NOW())";
	queryRequest(query);// send a request
}

void DataBase::ClearArchive()
{
	std::string query = "TRUNCATE TABLE Archive;";
	queryRequest(query);// send a request
}

//FUNCTIONS FOR PASSWORD

std::string DataBase::get_password()
{
	std::string query = "SELECT Password FROM password WHERE ID = 1 LIMIT 1;";
	queryRequestWithResult(query);//request with return result
	row = mysql_fetch_row(res);//assigning to arr
	std::string password = row[0];
	return password;
}

void DataBase::change_password(const std::string & password)
{
	std::string new_password = password;
	std::string query = "UPDATE password SET Password = " + new_password + " WHERE ID = 1;";
	queryRequest(query);// send a request
}


//Experemental function
//Not for use
//void database::auto_increment1(const std::string *tablename)
//{
//	std::string temp = (*tablename);
//	std::string query = "ALTER TABLE " + temp + " AUTO_INCREMENT = 1;"; //creation query request
//	queryRequest(&query);// send a request
//}