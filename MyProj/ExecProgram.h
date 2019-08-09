#pragma once
#include <iostream>
#include <string>

#include "DataBase.h"
#include "FuncForMenu.h"
#include "Password.h"
#include "Info.h"


class ExecProgram
{
public:

	ExecProgram();

	bool Start();

	void function_for_case1();
	
	void function_for_case2();
	
	void function_for_case3();
	
	void function_for_case4();
	
	void function_for_case5();
	
	void function_for_case6();
	
	void function_for_case7();

	void function_for_close_case1(bool & go_back);

	void function_for_close_case2(bool & go_back);

	void function_for_close_case3(bool & go_back);

	void function_for_case8();

	void function_for_info_case1(bool & go_back);

	void function_for_info_case2(bool & go_back);

	void function_for_case9();
	
	void Implementation_Program();


private:
	DataBase * dataBase;
	FuncForMenu * func;
	Password * password;
	Info * info;

};

