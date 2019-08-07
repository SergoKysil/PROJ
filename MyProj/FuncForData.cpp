#include "pch.h"
#include "FuncForData.h"
#include "mysql.h"
#include "Storage.h"
#include "DataManage.h"



//WORK WITH DATABASE

FuncForData::FuncForData(const std::string &dataBaseName, const std::string & host, const std::string & user, const std::string & password):DataManage (dataBaseName, host, user, password )
{}

bool FuncForData::connect_db()
{
	return DataManage::connect_db();
}

void FuncForData::queryRequest(const std::string & quer)
{
	std::string query = quer;//appropriation variable
	const char* q = query.c_str();//convert to const char
	mysql_query(conn, q);//query request
}

void FuncForData::queryRequestRes(const std::string & query)
{
	queryRequest(query);//send a request
	res = mysql_store_result(conn);//get result
}

bool FuncForData::checkForEmpty()
{
	int rows = mysql_num_rows(res);
	if (rows > 0) return true;
	else return false;
}

FuncForData::~FuncForData()//CLOSE CONNECTION TO DB
{
	delete res;
	delete conn;
	mysql_close(conn);
}

//WORK WITH TABLE VEGETABLE

bool FuncForData::print_vegetable()
{
	std::string query = "SELECT * FROM vegetable;"; //query request
	queryRequestRes(query);
	if (checkForEmpty()){
		std::cout << "ID\tName vegetable" << std::endl;
		while (row = mysql_fetch_row(res))
			std::cout << ("%s: \t%s\n", row[0], row[1]) << std::endl;//print result
		return true;
	}
	return false;
}

std::string FuncForData::get_name_veg(const int &id)
{
	auto temp = std::to_string(id);//convert to string
	std::string query = "SELECT NAME_VEG FROM vegetable WHERE ID = " + temp + ";"; //creation query request
	queryRequestRes(query);
	std::string value;//value for save
	row = mysql_fetch_row(res);//assigning to arr
	value = row[0];// assigning to variable
	return value; //return result
}

void FuncForData::add_name_veg(const std::string &val)
{
	std::string query = ("INSERT INTO vegetable(NAME_VEG) VALUES('" + val + "');");//query request
	queryRequest(query);// send a request
}

void FuncForData::del_name_veg(const int &id)
{
	auto temp = std::to_string(id);//convert to string
	std::string query = "DELETE FROM vegetable WHERE ID = " + temp + ";";//query request
	queryRequest(query);
}

bool FuncForData::check_ID_veg(const int & id)
{
	int ID = id;
	std::string query = "SELECT ID FROM vegetable";
	queryRequestRes(query);
	while (row = mysql_fetch_row(res))
		if (std::to_string(ID) == row[0]) return true;
	return false;
}

//WORK WITH TABLES

bool FuncForData::print_from_stor_room(const std::string & tablename)
{
	std::string t_name = tablename;
	std::string query = "SELECT * FROM " + t_name + ";";
	queryRequestRes(query);
	if (checkForEmpty()){
		std::cout << "ID\tName veget\tCount Prod\tDelivery Date" << std::endl;
		while (row = mysql_fetch_row(res))
			std::cout << ("%s: \t%s\t\t%s\t\t%s\n", row[0], row[1], row[2], row[3]);
		return true;
	}
	return false;
}

void FuncForData::create_new_table(const std::string &tablename)
{
	std::string t_name = tablename;
	std::string query = "CREATE TABLE " + t_name + "(ID INT AUTO_INCREMENT PRIMARY KEY, NAME_VEG VARCHAR(20), CountProd INT DEFAULT 0, DeliveryDate DATETIME NOT NULL);";
	queryRequest(query);
}

void FuncForData::addBatch(const Storage & newElement)
{
	std::string query = "INSERT INTO " + newElement.get_NAME_VEG() + "(NAME_VEG, CountProd, DeliveryDate) VALUES('" + newElement.get_NAME_VEG() + "', " + std::to_string(newElement.get_count_prod()) + ", NOW());";
	queryRequest(query);
}

int FuncForData::get_count(const Storage & newElement)
{
	std::string query = "SELECT CountProd FROM " + newElement.get_NAME_VEG() + " WHERE ID = " + std::to_string(newElement.get_ID()) + " LIMIT 1;";
	queryRequestRes(query);
	std::string value;//value for save
	row = mysql_fetch_row(res);//assigning to arr
	value = row[0];// assigning to variable
	return std::atoi(value.c_str()); //return result convert to int
}

bool FuncForData::changeCount(const Storage & newElement)
{
	int t_value = get_count(newElement);//set result from function
	int t_count = newElement.get_count_prod();
	if (t_value >= t_count){
		int next_ti_value = t_value - t_count;
		std::string query = "UPDATE " + newElement.get_NAME_VEG() + " SET CountProd = " + std::to_string(next_ti_value) + " WHERE ID = " + std::to_string(newElement.get_ID()) + ";";
		queryRequest(query);
		return true;
	}
	else{
		std::cout << "Not enought count in batch of products!" << std::endl;
		return false;
	}
}

void FuncForData::dellBatch(const Storage & newElement)
{
	std::string query = "DELETE FROM " + newElement.get_NAME_VEG() + " WHERE ID = " + std::to_string(newElement.get_ID());
	queryRequest(query);
}

bool FuncForData::check_ID(const int & ID, const std::string & name_veg)
{
	std::string t_name = name_veg;
	int id = ID;
	std::string query = "SELECT ID FROM " + t_name + ";";
	queryRequestRes(query);
	while (row = mysql_fetch_row(res))
		if (std::to_string(id) == row[0])
			return true;
	return false;
}

void FuncForData::drop_table(const std::string &tablename)
{
	std::string t_name = tablename;
	std::string query = "DROP TABLE " + t_name + ";";
	queryRequest(query);
}

//FUNCTIONS FOR ARCHIVE

bool FuncForData::print_all_archive()
{
	std::string query = "SELECT * FROM Archive;";
	queryRequestRes(query);
	if (checkForEmpty())
	{
		std::cout << "ID\tName veget\tCount Prod\tUnloading Date" << std::endl;
		while (row = mysql_fetch_row(res))
			std::cout << ("%s: \t%s\t\t%s\t\t%s\n", row[0], row[1], row[2], row[3]);//print result
		return true;
	}
	return false;
}

void FuncForData::AddToArchive(const Storage & newElement)
{
	std::string query = "INSERT INTO Archive(NAME_VEG, CountProd, UnloadingDate) VALUES('" + newElement.get_NAME_VEG() + "'," +std::to_string(newElement.get_count_prod()) + ", NOW())";
	queryRequest(query);
}

void FuncForData::ClearArchive()
{
	std::string query = "TRUNCATE TABLE Archive;";
	queryRequest(query);
}

//FUNCTIONS FOR PASSWORD

std::string FuncForData::get_password()
{
	std::string query = "SELECT Password FROM password WHERE ID = 1 LIMIT 1;";
	queryRequestRes(query);
	row = mysql_fetch_row(res);
	std::string passwo = row[0];
	return passwo;
}

void FuncForData::change_password(const std::string & password)
{
	std::string new_password = password;
	std::string query = "UPDATE password SET Password = " + new_password + " WHERE ID = 1;";
	queryRequest(query);
}


//Experemental function
//Not for use
//void database::auto_increment1(const std::string *tablename)
//{
//	std::string temp = (*tablename);
//	std::string query = "ALTER TABLE " + temp + " AUTO_INCREMENT = 1;"; //creation query request
//	queryRequest(&query);// send a request
//}