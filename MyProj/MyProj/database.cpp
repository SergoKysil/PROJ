#include "pch.h"
#include "database.h"
#include <iostream>
#include <string>
#include <vector>
#include "mysql.h"

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

void database::print_db()
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

void database::disconnect()
{
	mysql_close(conn);
}

void database::add_name_veg(string *val)
{
	string value = (*val);
	string query = ("INSERT INTO vegetable(NAME_VEG) VALUES('"+value+"');");
	const char* q = query.c_str();
	mysql_query(conn, q);
	mysql_commit(conn);
}

database::~database()
{
}
