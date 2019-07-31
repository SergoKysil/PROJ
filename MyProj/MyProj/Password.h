#pragma once
#include <iostream>
#include <string>
#include "mysql.h"
#include "database.h"
#include "Storage.h"
#include "Menu.h"

class Password
{
public:
	Password();

	bool password_verification(database & db);
	
	void change_password(database & db);

	~Password();
};

