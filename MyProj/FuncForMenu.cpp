#include "pch.h"
#include "FuncForMenu.h"



bool FuncForMenu::connectdb(FuncForData & work)
{
	if (work.connect_db("localhost", "root", ""))
	{
		return true;
	}
	return false;
}

void FuncForMenu::print_menu()
{
	std::string text = "===Select one of the menu items!===\n\n\
1. Show a list of vegetables\n\
2. View the contents of one of the repositories\n\
3. Add a new type of vegetables\n\
4. Unload a batch of vegetables\n\
5. Unload a portion of the batch of vegetables\n\
6. Download a batch of vegetables\n\
7. View archive\n\
8. View closed function\n\
9. Reference\n\
0. Exit\n";
	std::cout << text << std::endl;
}

void FuncForMenu::print_closed_function()
{
	std::string text = "1. Delete information about a particular vegetable\n\
2. Clear the archive\n\
3. Change password\n\n\
4. Return to the main menu\n\
0. Exit\n";
	std::cout << text << std::endl;
}

void FuncForMenu::print_refer_menu()
{
	std::string text = "1. Help for use\n\
2. About program\n\n\
3. Return to the main menu\n\
0. Exit\n";
	std::cout << text << std::endl;
}

void FuncForMenu::print_min_menu()
{
	std::string text = "\n1. Return to the main menu\n\
2. Continue performing this function\n\
0. Exit\n";
	std::cout << text << std::endl;
}

void FuncForMenu::print_min_menu2()
{
	std::string text = "\n1. Return to the main menu\n\
0. Exit\n";
	std::cout << text;
}

void FuncForMenu::print_min_menux()
{
	std::string text = "\n1. Return to the main function\n\
2. Stay in this menu\n\
0. Exit\n";
	std::cout << text;
}

void FuncForMenu::choise_min_menu(bool * case_x)
{
	int choise_case;
	std::cout << "\nYour choise: ";
	std::cin >> choise_case;
	bool back = true;
	while (back)
	{
		if ((choise_case) == 1)
		{
			system("cls");
			back = false;
			(*case_x) = false;
		}
		else if ((choise_case) == 2)
		{
			system("cls");
			back = false;
		}
		else if ((choise_case) == 0)
		{
			exit(0);
		}
		else
		{
			printf("\nInvalid choise!\n");
			back = true;
		}
	}
}

void FuncForMenu::choise_min_menu2(bool * case_x)
{
	int choise_case;
	std::cout << "\nYour choise: ";
	std::cin >> choise_case;
	bool back = true;
	while (back)
	{
		if (choise_case == 1)
		{
			system("cls");
			back = false;
			(*case_x) = false;	
		}
		else if (choise_case == 0)
		{
			exit(0);
		}
		else
		{
			printf("\nInvalid choise!\n");
			back = true;
		}
	}
}

void FuncForMenu::choise_min_menux(bool * case_x, bool * menux)
{
	int choise_case;
	std::cout << "\nYour choise: ";
	std::cin >> choise_case;
	bool back = true;
	while (back)
	{
		if (choise_case == 1)
		{
			system("cls");
			back = false;
			(*case_x) = false;
			(*menux) = false;
		}
		else if (choise_case == 2)
		{
			system("cls");
			back = false;
			(*case_x) = false;
		}
		else if (choise_case == 0)
		{
			exit(0);
		}
		else
		{
			printf("\nInvalid choise!\n");
			back = true;
		}
	}
}

void FuncForMenu::show_list_of_vegetable(FuncForData & work)
{
	if (work.print_vegetable())
	{}
	else std::cout << "There is no vegetable!" << std::endl;
}

void FuncForMenu::print_from_room(FuncForData & work)
{
	if (work.print_vegetable())
	{
		std::cout << "\nChoose which product you want to see: ";
		int choise;
		std::cin >> choise;
		if (work.check_ID_veg(choise))
		{
			system("cls");
			const std::string name_veg = work.get_name_veg(choise);
			if (work.print_from_stor_room(name_veg))
			{}
			else
			{
				std::cout << "Storage is empty!" << std::endl;
			}
		}
		else
		{
			std::cout << "There is no such ID!" << std::endl;
		}
	}
	else
	{
	std::cout << "There is no vegetable!" << std::endl;
	}
}

void FuncForMenu::add_a_new_type_of_vegetables(FuncForData & work)
{
	std::cout << "Enter a product name: ";
	std::string t_name;
	std::cin >> t_name;
	work.add_name_veg(t_name);
	work.create_new_table(t_name);
}

void FuncForMenu::download_a_batch_of_vegetable(FuncForData & work)
{
	if (work.print_vegetable())
	{
		std::cout << "\nChoose which product you want to download: ";
		int choise;
		std::cin >> choise;
		if (work.check_ID_veg(choise))
		{
			const std::string name_veg = work.get_name_veg(choise);
			std::cout << "Enter the quantity of products: ";
			int count;
			std::cin >> count;
			Storage temp(name_veg, count);
			work.addBatch(temp);
		}
		else
		{
			std::cout << "There is no such ID!" << std::endl;
		}
	}
	else
	{
		std::cout << "There is no vegetable!" << std::endl;
	}
}

void FuncForMenu::unload_a_batch_of_product(FuncForData & work)
{
	if (work.print_vegetable())
	{
		std::cout << "\nChoose which product you want to unload: ";
		int choise;
		std::cin >> choise;
		if (work.check_ID_veg(choise))
		{
			system("cls");
			const std::string name_veg = work.get_name_veg(choise);
			if (work.print_from_stor_room(name_veg))
			{
				std::cout << "Select the batch you want to unload: ";
				int choise_batch;
				std::cin >> choise_batch;
				if (work.check_ID(choise_batch, name_veg))
				{
					Storage temp(choise_batch, name_veg);
					int count = work.get_count(temp);
					Storage temp1(choise_batch, name_veg, count);
					work.AddToArchive(temp1);
					work.dellBatch(temp);
				}
				else
				{
					std::cout << "There is no such party!" << std::endl;
				}
			}
			else
			{
				std::cout << "Storage is empty!" << std::endl;
			}
		}
		else
		{
			std::cout << "There is no such ID!" << std::endl;
		}
	}
	else
	{
		std::cout << "There is no vegetable!" << std::endl;

	}
}

void FuncForMenu::unload_a_portion_of_the_batch(FuncForData & work)
{
	if (work.print_vegetable())
	{
		std::cout << "\nChoose which product you want to unload: ";
		int choise;
		std::cin >> choise;
		if (work.check_ID_veg(choise))
		{
			system("cls");
			const std::string name_veg = work.get_name_veg(choise);
			if (work.print_from_stor_room(name_veg))
			{
				std::cout << "Select the portion of the batch you want to unload: ";
				int choise_batch;
				std::cin >> choise_batch;
				if (work.check_ID(choise_batch, name_veg))
				{
					std::cout << "Enter count: ";
					int count;
					std::cin >> count;
					Storage temp(choise_batch, name_veg, count);
					Storage temp1(name_veg, count);
					if (work.changeCount(temp) == true)
					{
						work.AddToArchive(temp1);
					}
					else
					{
						printf("There are not so many products in the lot\n");
					}
				}
				else
				{
					std::cout << "There is no such party!" << std::endl;
				}
			}
			else
			{
				std::cout << "Storage is empty!" << std::endl;	
			}
		}
		else
		{
			std::cout << "There is no such ID!" << std::endl;
		}
	}
	else
	{
		std::cout << "There is no vegetable!" << std::endl;

	}
}

void FuncForMenu::print_all_archive(FuncForData & work)
{
	if (work.print_all_archive())
	{ }
	else
	{
		std::cout << "Archive is clear!" << std::endl;
	}
}

void FuncForMenu::print_Help()
{
	Info help;
	help.Help_for_use();
}

void FuncForMenu::print_about_prog()
{
	Info about;
	about.About_the_program();
}

void FuncForMenu::exit_prog(FuncForData & work)
{
	work.~FuncForData();
	exit(0);
}

//functions for password

void FuncForMenu::del_veget(FuncForData & work)
{
	Password pass;
	if (pass.password_verification(work))
	{
		if (work.print_vegetable())
		{
			std::cout << "\nChoose which product you want to delete: ";
			int choise;
			std::cin >> choise;
			if (work.check_ID_veg(choise))
			{
				std::string name_veg = work.get_name_veg(choise);
				work.del_name_veg(choise);
				work.drop_table(name_veg);
			}
			else
			{
				std::cout << "There is no product under this ID!" << std::endl;
			}

		}
		else
		{
			std::cout << "There is no vegetable!" << std::endl;
		}
	}
	else
	{
		printf("Invalid password!");
	}
}

void FuncForMenu::clear_archive(FuncForData & work)
{
	Password pass;
	if (pass.password_verification(work))
	{
		work.ClearArchive();
	}
	else
	{
		printf("Invalid password");
	}
}

void FuncForMenu::change_password(FuncForData & work)
{
	Password pass;
	pass.change_password(work);
}





