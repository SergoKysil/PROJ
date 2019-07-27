#include "pch.h"
#include "database.h"
#include "mysql.h"
#include "Storage.h"



//WORK WITH DATABASE

database::database()
{
}

void database::connect_db()
{
	conn = mysql_init(0);//initialization connect
	conn = mysql_real_connect(conn, "localhost", "root", "", "Storage", 3306, NULL, 0);//set parametrs of connection
	if (conn)//if sucñessful connect
	{
		puts("Successful connection to database!");//print
	}
	else
	{
		puts("Connection to database has failed!");
	}
}

void database::queryRequest(const std::string * quer)
{
	std::string query = *quer;//appropriation variable
	const char* q = query.c_str();//convert to const char
	mysql_query(conn, q);//query request
}

void database::saveAll()
{
	mysql_commit(conn);//commit changes
}

database::~database()//CLOSE CONNECTION TO DB
{
	delete res;
	delete conn;
	mysql_close(conn);
}

//WORK WITH TABLE VEGETABLE

void database::print_vegetable()
{
	std::string query = "SELECT * FROM vegetable;"; //query request
	queryRequest(&query);//send a request
	res = mysql_store_result(conn);//get result
	while (row = mysql_fetch_row(res))
	{
		printf("%s: %s\n", row[0], row[1]);//print result
	}
}

std::string database::get_name_veg(int *id)
{
	auto temp = std::to_string(*id);//convert to string
	std::string query = "SELECT NAME_VEG FROM vegetable WHERE ID = " + temp + ";"; //creation query request
	queryRequest(&query);//call function for query request
	res = mysql_store_result(conn);//get result
	std::string value;//value for save
	row = mysql_fetch_row(res);//assigning to arr
	value = row[1];// assigning to variable
	return value; //return result
}

void database::add_name_veg(const std::string *val)
{
	std::string temp = (*val);//appropriation variable
	std::string query = ("INSERT INTO vegetable(NAME_VEG) VALUES('" + temp + "');");//query request
	queryRequest(&query);// send a request
}

void database::del_name_veg( int *id)
{
	auto temp = std::to_string(*id);//convert to string
	std::string query = "DELETE FROM vegetable WHERE ID = " + temp + ";";//query request
	queryRequest(&query);
}

//WORK WITH TABLES

void database::auto_increment1(std::string *tablename)
{
	std::string t_tablename = (*tablename);
	std::string query = "ALTER TABLE " + t_tablename + " AUTO_INCREMENT = 1;"; //creation query request
	queryRequest(&query);// send a request
}

void database::create_new_table(const Storage & newElement)
{
	std::string query = "CREATE TABLE " + newElement.get_NAME_VEG() + "(ID INT AUTO_INCREMENT PRIMARY KEY, NAME_VEG VARCHAR(20), CountProd INT DEFAULT 0, DeliveryDate DATETIME NOT NULL);";
	queryRequest(&query);
}

void database::addBatch(const Storage & newElement)
{
	std::string query = "INSERT INTO " + newElement.get_NAME_VEG() + "(NAME_VEG, CountProd, DeliveryDate) VALUES('" + newElement.get_NAME_VEG() + "', " + std::to_string(newElement.get_count_prod()) + ", NOW());";
	queryRequest(&query);
}

int database::get_count(const Storage & newElement)
{
	std::string query = "SELECT CountProd FROM " + newElement.get_NAME_VEG() + "WHERE ID = " + std::to_string(newElement.get_ID()) + ";";
	queryRequest(&query);
	res = mysql_store_result(conn);//get result
	std::string value;//value for save
	row = mysql_fetch_row(res);//assigning to arr
	value = row[0];// assigning to variable
	return 1; /*std::stoi(value);*/ //return result convert to int
}

void database::changeCount(const Storage & newElement)
{
	int t_value = get_count(newElement);//set result from function
	if (t_value >= newElement.get_count_prod())
	{
		t_value = t_value - newElement.get_count_prod();
		std::string query = "UPDATE TABLE " + newElement.get_NAME_VEG() + " SET CountProd = " + std::to_string(t_value) + "WHERE ID = " + std::to_string(newElement.get_ID()) + ";";
		queryRequest(&query);
	}
	else
	{
		std::cout << "Not enought count in batch of products!" << std::endl;
	}
}

void database::dellBatch(const Storage & newElement)
{
	std::string query = "DELETE FROM " + newElement.get_NAME_VEG() + " WHERE ID = " + std::to_string(newElement.get_ID()) + ";";
	queryRequest(&query);
}

//FUNCTIONS FOR ARCHIVE

void database::print_all_archive()
{
	std::string query = "SELECT * FROM Archive";
	queryRequest(&query);
}

void database::AddToArchive(const Storage & newElement)
{
	std::string query = "INSERT INTO Archive(NAME_VEG, CountProd, UnloadingDate) VALUES(" + newElement.get_NAME_VEG() + ", " + std::to_string(newElement.get_count_prod()) + ", NOW());";
	queryRequest(&query);
}

void database::ClearArchive()
{
	std::string query = "TRUNCATE TABLE Archive";
	queryRequest(&query);
}






//CREATE TABLE TableName(
//	ID INT AUTO_INCREMENT PRIMARY KEY,
//  NAME_VEG VARCHAR(20),
//	CountProd INT DEFAULT 0,
//	DeliveryDate DATETIME NOT NULL
//	);



//string query = "INSERT INTO tomate(NAME_VEG, CountProd, DeliveryDate) VALUES('tomate', 20000, NOW())";