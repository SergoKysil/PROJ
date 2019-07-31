#pragma once
#include <iostream>
#include <string>
#include "mysql.h"
#include "database.h"
#include "Storage.h"
#include "Password.h"


class Menu
{
public:
	Menu();

	~Menu();

	void print_menu();
	
	void print_closed_function();

	void print_min_menu();

	void print_min_menu2();

	void print_min_menux();

	void choise_min_menu( bool * case_x);

	void choise_min_menu2(bool * case_x);

	void choise_min_menux(bool * case_x, bool * menux);

	void show_list_of_vegetable(database & db);
	
	void print_from_room(database & db);
	
	void add_a_new_type_of_vegetables(database & db);
	
	void download_a_batch_of_vegetable(database & db);
	
	void unload_a_batch_of_product(database & db);
	
	void unload_a_portion_of_the_batch(database &db);
	
	void print_all_archive(database &db);
	
	void exit_prog(database &db);

	//functions for password

	void del_veget(database & db);

	void clear_archive(database &db);

	void change_password(database & db);
	

};

