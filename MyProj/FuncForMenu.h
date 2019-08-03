#pragma once
#include <iostream>
#include <string>
#include "mysql.h"
#include "database.h"
#include "Storage.h"
#include "Password.h"
#include "Info.h"


class FuncForMenu
{
public:
	FuncForMenu();

	~FuncForMenu();

	bool connectdb();

	void print_menu();
	
	void print_closed_function();

	void print_refer_menu();

	void print_min_menu();

	void print_min_menu2();

	void print_min_menux();

	void choise_min_menu( bool * case_x);

	void choise_min_menu2(bool * case_x);

	void choise_min_menux(bool * case_x, bool * menux);

	void show_list_of_vegetable();
	
	void print_from_room();
	
	void add_a_new_type_of_vegetables();
	
	void download_a_batch_of_vegetable();
	
	void unload_a_batch_of_product();
	
	void unload_a_portion_of_the_batch();
	
	void print_all_archive();

	void print_Help();

	void print_about_prog();
	
	void exit_prog();

	//functions for password

	void del_veget();

	void clear_archive();

	void change_password();
	

};

