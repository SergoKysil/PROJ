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

bool database::print_vegetable()
{
	std::string query = "SELECT * FROM vegetable;"; //query request
	queryRequest(&query);//send a request
	res = mysql_store_result(conn);//get result
	int num = mysql_num_rows(res);
	if (num > 0)
	{
		std::cout << "ID\tName vegetable" << std::endl;
		while (row = mysql_fetch_row(res))
		{
			printf("%s: \t%s\n", row[0], row[1]);//print result
		}
		return true;
	}
	else
	{
		return false;
	}
}

std::string database::get_name_veg(const int *id)
{
	auto temp = std::to_string(*id);//convert to string
	std::string query = "SELECT NAME_VEG FROM vegetable WHERE ID = " + temp + ";"; //creation query request
	queryRequest(&query);//call function for query request
	res = mysql_store_result(conn);//get result
	std::string value;//value for save
	row = mysql_fetch_row(res);//assigning to arr
	value = row[0];// assigning to variable
	return value; //return result
}

void database::add_name_veg(const std::string *val)
{
	std::string query = ("INSERT INTO vegetable(NAME_VEG) VALUES('" + (*val) + "');");//query request
	queryRequest(&query);// send a request
}

void database::del_name_veg(const int *id)
{
	auto temp = std::to_string(*id);//convert to string
	std::string query = "DELETE FROM vegetable WHERE ID = " + temp + ";";//query request
	queryRequest(&query);
}

bool database::check_ID_veg(const int * id)
{
	int ID = (*id);
	std::string query = "SELECT ID FROM vegetable;";
	queryRequest(&query);
	res = mysql_store_result(conn);
	row = mysql_fetch_row(res);
	while (row = mysql_fetch_row(res))
	{
		if (std::to_string(ID) == row[0])
		{
			return true;
		}
	}
	return false;
}

//WORK WITH TABLES

bool database::print_from_stor_room(const std::string * tablename)
{
	std::string t_name = (*tablename);
	std::string query = "SELECT * FROM " + t_name + ";";
	queryRequest(&query);
	res = mysql_store_result(conn);
	int num = mysql_num_rows(res);
	if (num > 0)
	{
		std::cout << "ID\tName veget\tCount Prod\tDelivery Date" << std::endl;
		while (row = mysql_fetch_row(res))
		{
			printf("%s: \t%s\t\t%s\t\t%s\n", row[0], row[1], row[2], row[3]);
		}
		return true;
	}
	else
	{
		return false;
	}
}

void database::create_new_table(const std::string *tablename)
{
	std::string t_name = (*tablename);
	std::string query = "CREATE TABLE " + t_name + "(ID INT AUTO_INCREMENT PRIMARY KEY, NAME_VEG VARCHAR(20), CountProd INT DEFAULT 0, DeliveryDate DATETIME NOT NULL);";
	queryRequest(&query);
}

void database::addBatch(const Storage & newElement)
{
	std::string query = "INSERT INTO " + newElement.get_NAME_VEG() + "(NAME_VEG, CountProd, DeliveryDate) VALUES('" + newElement.get_NAME_VEG() + "', " + std::to_string(newElement.get_count_prod()) + ", NOW());";
	queryRequest(&query);
}

int database::get_count(const Storage & newElement)
{
	std::string query = "SELECT CountProd FROM " + newElement.get_NAME_VEG() + " WHERE ID = " + std::to_string(newElement.get_ID()) + " LIMIT 1;";
	queryRequest(&query);
	res = mysql_store_result(conn);//get result
	std::string value;//value for save
	row = mysql_fetch_row(res);//assigning to arr
	value = row[0];// assigning to variable
	return std::atoi(value.c_str()); //return result convert to int
}

bool database::changeCount(const Storage & newElement)
{
	int t_value = get_count(newElement);//set result from function
	int t_count = newElement.get_count_prod();
	if (t_value >= t_count)
	{
		int next_ti_value = t_value - t_count;
		std::string query = "UPDATE " + newElement.get_NAME_VEG() + " SET CountProd = " + std::to_string(next_ti_value) + " WHERE ID = " + std::to_string(newElement.get_ID()) + ";";
		queryRequest(&query);
		return true;
	}
	else
	{
		std::cout << "Not enought count in batch of products!" << std::endl;
		return false;
	}
}

void database::dellBatch(const Storage & newElement)
{
	std::string query = "DELETE FROM " + newElement.get_NAME_VEG() + " WHERE ID = " + std::to_string(newElement.get_ID());
	queryRequest(&query);
}

bool database::check_ID(const int * ID, const std::string * name_veg)
{
	std::string t_name = (*name_veg);
	int id = (*ID);
	std::string query = "SELECT ID FROM " + t_name + ";";
	queryRequest(&query);
	res = mysql_store_result(conn);
	row = mysql_fetch_row(res);
	while (row = mysql_fetch_row(res))
	{
		if (std::to_string(id) == row[0])
		{
			return true;
		}
	}
	return false;
}

void database::drop_table(const std::string *tablename)
{
	std::string t_name = (*tablename);
	std::string query = "DROP TABLE " + t_name + ";";
	queryRequest(&query);
}

//FUNCTIONS FOR ARCHIVE

bool database::print_all_archive()
{
	std::string query = "SELECT * FROM Archive;";
	queryRequest(&query);
	res = mysql_store_result(conn);//get result
	int num = mysql_num_rows(res);
	if (num > 0)
	{
		std::cout << "ID\tName veget\tCount Prod\tUnloading Date" << std::endl;
		while (row = mysql_fetch_row(res))
		{
			printf("%s: \t%s\t\t%s\t\t%s\n", row[0], row[1], row[2], row[3]);//print result
		}
		return true;
	}
	else
	{
		return false;
	}
}

void database::AddToArchive(const Storage & newElement)
{
	std::string query = "INSERT INTO Archive(NAME_VEG, CountProd, UnloadingDate) VALUES('" + newElement.get_NAME_VEG() + "'," +std::to_string(newElement.get_count_prod()) + ", NOW())";
	queryRequest(&query);
}

void database::ClearArchive()
{
	std::string query = "TRUNCATE TABLE Archive;";
	queryRequest(&query);
}

//FUNCTIONS FOR PASSWORD

std::string database::get_password()
{
	std::string query = "SELECT Password FROM password WHERE ID = 1 LIMIT 1;";
	queryRequest(&query);
	res = mysql_store_result(conn);
	row = mysql_fetch_row(res);
	std::string passwo = row[0];
	return passwo;
}

void database::change_password(const std::string * password)
{
	std::string new_password = (*password);
	std::string query = "UPDATE password SET Password = " + new_password + " WHERE ID = 1;";
	queryRequest(&query);
}


//Experemental function
//Not for use
//void database::auto_increment1(const std::string *tablename)
//{
//	std::string temp = (*tablename);
//	std::string query = "ALTER TABLE " + temp + " AUTO_INCREMENT = 1;"; //creation query request
//	queryRequest(&query);// send a request
//}