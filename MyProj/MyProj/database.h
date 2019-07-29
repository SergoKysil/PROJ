#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

#include "mysql.h"
#include "Storage.h"




class database
{
public:
	database();

	//
	
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;

	//WORK WITH DATABASE

	void connect_db();
	
	void queryRequest(const std::string *query);

	void saveAll();

	//WORK WITH TABLE VEGETABLE
	
	void print_vegetable();
	
	std::string get_name_veg( int * id);
	
	void add_name_veg(const std::string * val);
	
	void del_name_veg( int *id);

	//WORK WITH TABLES FOR SAVE PRODUCT

	void auto_increment1(const std::string * tablename);

	void print_from_stor_room(const std::string * tablename);
	
	void create_new_table(const std::string * val);

	void addBatch(const Storage & newElement);

	int get_count(const Storage & newElement);

	bool changeCount(const Storage & newElement);

	void dellBatch(const Storage & newElement);
	
	//FUNCTIONS FOR ARCHIVE

	void print_all_archive();

	void AddToArchive(const Storage & newElement);

	void ClearArchive();
	
	~database();


};


