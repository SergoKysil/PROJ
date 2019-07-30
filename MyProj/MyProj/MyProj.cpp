// MyProj.cpp : This file contains the function "main". Here the program starts and ends.
//

#include "pch.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "mysql.h"
#include "database.h"
#include "Storage.h"
#include "Menu.h"
#include "Password.h"



int main()
{

	database DB;
	DB.connect_db();
	Menu menu;

	//menu.print_menu();
	//menu.show_list_of_vegetable(DB);
	//menu.add_a_new_type_of_vegetables(DB);
	//menu.download_a_batch_of_vegetable(DB);
	//menu.unload_a_batch_of_product(DB);
	//menu.unload_a_portion_of_the_batch(DB);
	//menu.print_all_archive(DB);
	//menu.clear_archive(DB);
	//menu.exit_prog(DB);
	

	
	
	return 0;
}

// Run the program: CTRL + F5 or the Debug menu> Run without debugging
// Debugging the program: F5 or the Debug menu> "Start debugging"

// Tips to get started
// 1. In the solution browser window, you can add files and manage them.
// 2. In the Team Explorer window, you can connect to the version control system.
// 3. In the "Output" window, you can view the output of the assembly and other messages.
// 4. In the "List of Errors" window you can see errors.
// 5. Sequentially select Project menu items> Add New Item to create code files or Project> Add Existing Element to add existing code files to the project.
// 6. To open this project later, select File> Open> Project, and select the SLN file.