#pragma once
#include <iostream>
#include <string>
#include "mysql.h"
#include "DataBase.h"

#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>


class Password
{
public:

	std::string hash(std::string & pass);

	bool password_verification(DataBase & data);

	void change_password(DataBase & data);


};

