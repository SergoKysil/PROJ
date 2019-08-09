#pragma once
#include <iostream>
#include <string>
#include "mysql.h"
#include "DataBase.h"

class Password
{
public:
	bool password_verification(DataBase & work);
	
	void change_password(DataBase & work);
};

