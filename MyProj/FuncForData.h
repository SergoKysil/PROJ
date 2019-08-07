#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "mysql.h"
#include "DataManage.h"
#include "Storage.h"




class FuncForData : public DataManage
{
public:
	explicit FuncForData(const std::string &dataBaseName, const std::string & host, const std::string & user, const std::string & password);

	//WORK WITH DATABASE

	bool connect_db();
	
	void queryRequest(const std::string &query);

	void queryRequestRes(const std::string &query);

	bool checkForEmpty();

	~FuncForData();

	//WORK WITH TABLE VEGETABLE
	
	bool print_vegetable();
	
	std::string get_name_veg(const int & id);
	
	void add_name_veg(const std::string & val);
	
	void del_name_veg(const int &id);

	bool check_ID_veg(const int & id);

	//WORK WITH TABLES FOR SAVE PRODUCT

	bool print_from_stor_room(const std::string & tablename);
	
	void create_new_table(const std::string & val);

	void addBatch(const Storage & newElement);

	int get_count(const Storage & newElement);

	bool changeCount(const Storage & newElement);

	void dellBatch(const Storage & newElement);
	
	bool check_ID(const int & ID, const std::string & name_veg);

	void drop_table(const std::string &tablename);

	//FUNCTIONS FOR ARCHIVE

	bool print_all_archive();

	void AddToArchive(const Storage & newElement);

	void ClearArchive();
	
	//FUNCTIONS FOR PASSWORD

	std::string get_password();

	void change_password(const std::string & password);

	//void auto_increment1(const std::string * tablename);

};


