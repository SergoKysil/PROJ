#pragma once
#include <iostream>
#include <string>
#include "mysql.h"
#include "database.h"
#include "Storage.h"
#include "database.h"


class Menu
{
public:
	Menu();

	explicit Menu(const int & password);

	int get_password() const;

	void print_menu();
	
	void show_list_of_vegetable(database & db);
	
	void add_a_new_type_of_vegetables(database & db);
	
	void download_a_batch_of_vegetable(database & db);
	
	void unload_a_batch_of_product(database & db);
	
	void unload_a_portion_of_the_batch(database &db);
	
	void print_all_archive(database &db);
	
	void clear_archive(database &db);
	
	void exit_prog(database &db);
	
	~Menu();

private:
	std::shared_ptr<int> password;
};

