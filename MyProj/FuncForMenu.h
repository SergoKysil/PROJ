#pragma once
#include <iostream>
#include <string>
#include "mysql.h"
#include "FuncForData.h"
#include "Storage.h"
#include "Password.h"
#include "Info.h"


class FuncForMenu
{
public:

	bool connectdb(FuncForData & work);

	void print_menu();
	
	void print_closed_function();

	void print_refer_menu();

	void print_min_menu();

	void print_min_menu2();

	void print_min_menux();

	void choise_min_menu( bool * case_x);

	void choise_min_menu2(bool * case_x);

	void choise_min_menux(bool * case_x, bool * menux);

	void show_list_of_vegetable(FuncForData & work);
	
	void print_from_room(FuncForData & work);
	
	void add_a_new_type_of_vegetables(FuncForData & work);
	
	void download_a_batch_of_vegetable(FuncForData & work);
	
	void unload_a_batch_of_product(FuncForData & work);
	
	void unload_a_portion_of_the_batch(FuncForData & work);
	
	void print_all_archive(FuncForData & work);

	void print_Help();

	void print_about_prog();
	
	void exit_prog(FuncForData & work);

	//functions for password

	void del_veget(FuncForData & work);

	void clear_archive(FuncForData & work);

	void change_password(FuncForData & work);
	

};

