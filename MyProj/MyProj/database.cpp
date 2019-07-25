#include "pch.h"
#include "database.h"
#include <iostream>
#include <string>
#include <ctime>

#include <vector>
#include "mysql.h"
#include "Storage.h"



database::database()
{
}

void database::connect_db()
{
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "", "Storage", 3306, NULL, 0);
	if (conn)
	{
		puts("Successful connection to database!");
	}
	else
	{
		puts("Connection to database has failed!");
	}
}

void database::print_vegetable()
{
	string query = "SELECT * FROM vegetable";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	res = mysql_store_result(conn);

	while (row = mysql_fetch_row(res))
	{
		printf("%s: %s\n", row[0], row[1]);
	}
}

void database::saveAll()
{
	mysql_commit(conn);
}

void database::queryRequest(const string * quer)
{
	string query = *quer;
	const char* q = query.c_str();
	mysql_query(conn, q);
}

void database::auto_increment1()
{
	string query = "ALTER TABLE vegetable AUTO_INCREMENT = 1"; //creation query request
	queryRequest(&query);
}

string database::get_name_veg( int *id)
{
	auto temp = std::to_string(*id);//convert to string
	string query = "SELECT NAME_VEG FROM vegetable WHERE ID = " + temp + ""; //creation query request
	queryRequest(&query);//call function for query request
	res = mysql_store_result(conn);//get result
	string value;//value for save
	row = mysql_fetch_row(res);//assigning to arr
	value = row[1];// assigning to variable
	return value;
}

void database::add_name_veg(const string *val)
{
	string temp = (*val);
	string query = ("INSERT INTO vegetable(NAME_VEG) VALUES('" + temp + "');");
	queryRequest(&query);
}

string database::del_name_veg( int *id)
{
	auto temp = std::to_string(*id);
	string query = "DELETE FROM vegetable WHERE ID = " + temp + "";
	queryRequest(&query);
}

void database::create_new_table(const Storage & newElement)
{
	string query = "CREATE TABLE " + newElement.get_NAME_VEG() + "(ID INT AUTO_INCREMENT PRIMARY KEY, NAME_VEG VARCHAR(20), CountProd INT DEFAULT 0, DeliveryDate DATETIME NOT NULL);";
	queryRequest(&query);
}

void database::addItem(const Storage & newElement)
{
	string query = "INSERT INTO " + newElement.get_NAME_VEG() + "(NAME_VEG, CountProd, DeliveryDate) VALUES('" + newElement.get_NAME_VEG() + "', " + std::to_string(newElement.get_count_prod()) + ", NOW());";
	//string query = "INSERT INTO tomate(NAME_VEG, CountProd, DeliveryDate) VALUES('tomate', 20000, NOW())";
	queryRequest(&query);
	
}




database::~database()//CLOSE CONNECTION TO DB
{
	mysql_close(conn);
}


//CREATE TABLE TableName(
//	ID INT AUTO_INCREMENT PRIMARY KEY,
//  NAME_VEG VARCHAR(20),
//	CountProd INT DEFAULT 0,
//	DeliveryDate DATETIME NOT NULL
//	);
