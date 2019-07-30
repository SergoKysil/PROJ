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
	
	void show_list_of_vegetable(database & db);
	
	void add_a_new_type_of_vegetables(database & db);
	
	void download_a_batch_of_vegetable(database & db);
	
	void unload_a_batch_of_product(database & db);
	
	void unload_a_portion_of_the_batch(database &db);
	
	void print_all_archive(database &db);
	
	void exit_prog(database &db);

	//functions for password

	void del_veget(database & db, Password & pass);

	void clear_archive(database &db, Password & pass);

	void change_password(database & db, Password & pass);
	

};

