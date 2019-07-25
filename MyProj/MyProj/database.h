#pragma once
#include <iostream>
#include <string>
#include <vector>


#include "mysql.h"
#include "Storage.h"


using namespace std;


class database
{
public:
	database();

	int qstate;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;

	

	void connect_db();
	void saveAll();
	void queryRequest(const string *query);
	void create_new_table(const Storage &newElement);
	void print_vegetable();
	string get_name_veg( int *id);
	void add_name_veg(const string *val);
	string del_name_veg( int *id);
	void auto_increment1();
	void addItem(const Storage & newElement);
	~database();

	
		
		

	

};

