#pragma once
#include <iostream>
#include <string>



#include "mysql.h"
#include "Storage.h"




class database
{
public:
	database();

	
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;

	void connect_db();
	
	void queryRequest(const std::string *query);
	
	void create_new_table(const Storage &newElement);
	
	void print_vegetable();
	
	void auto_increment1(std::string * tablename);

	std::string get_name_veg( int * id);
	
	void add_name_veg(const std::string * val);
	
	void del_name_veg( int *id);
	
	void addBatch(const Storage & newElement);

	int get_count(const Storage & newElement);

	void changeCount(const Storage & newElement);

	void dellBatch(const Storage & newElement);

	void AddToArchive(const Storage & newElement);

	void saveAll();
	
	~database();

	
		
		

	

};

