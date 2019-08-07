#pragma once
#include <iostream>
#include <string>
#include "mysql.h"
#include "FuncForData.h"

class Password
{
public:
	bool password_verification(FuncForData & work);
	
	void change_password(FuncForData & work);
};

