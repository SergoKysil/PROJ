#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "mysql.h"




class DataBase
{
public:
	explicit DataBase(const std::string &dataBaseName, const std::string & host, const std::string & user, const std::string & password);

	//WORK WITH DATABASE

	bool connect_db();
	
	void queryRequest(const std::string &query);

	void queryRequestWithResult(const std::string &query);

	bool checkForEmpty();

	void saveAll();

	~DataBase();

	//WORK WITH TABLE VEGETABLE
	
	bool print_vegetable();
	
	std::string get_name_veg(const int & id);
	
	void add_name_veg(const std::string & val);
	
	void del_name_veg(const int &id);

	bool check_ID_veg(const int & id);

	//WORK WITH TABLES FOR SAVE PRODUCT

	bool print_from_stor_room(const std::string & tablename);
	
	void create_new_table(const std::string & val);

	void addBatch(const std::string & name_vegetable, const int & count_product);

	int get_count(const std::string & name_vegetable, const int & id);
	
	void dellBatch(const std::string & name_vegetable, const int & id);

	bool changeCount(const std::string & name_vegetable, const int & id, const int & change_count);

	bool check_ID(const int & ID, const std::string & name_veg);

	void drop_table(const std::string &tablename);

	//FUNCTIONS FOR ARCHIVE

	bool print_all_archive();

	void AddToArchive(const std::string & name_vegetable, const int & count_product);

	void ClearArchive();
	
	//FUNCTIONS FOR PASSWORD

	std::string get_password();

	void change_password(const std::string & password);

	//void auto_increment1(const std::string * tablename);

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


