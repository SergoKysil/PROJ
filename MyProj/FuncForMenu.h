#pragma once
#include <iostream>
#include <string>
#include "mysql.h"
#include "Password.h"
#include "DataBase.h"


class FuncForMenu
{
public:

	void print_menu();
	
	void print_menu_for_closed_function();

	void print_info_menu();

	void print_back_menu1();

	void print_back_menu2();

	void print_back_menu_for_close_func();

	void choise_back_menu1 (bool & case_x);

	void choise_back_menu2(bool & case_x);

	void choise_back_menu_for_close_func(bool & case_x, bool & menux);

	void go_back_for_menu1(bool & case_x);

	void go_back_for_menu2(bool & case_x);

	void go_back_for_menu_for_close_func(bool & case_x, bool & menux);
	

};

