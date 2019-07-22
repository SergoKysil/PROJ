#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "mysql.h"


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
	void print_db();
	void disconnect();
	void add_name_veg(string *val);
	~database();
};

