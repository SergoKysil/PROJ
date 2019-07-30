#include "pch.h"
#include "Menu.h"



Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::print_menu()
{
	std::string text = "===Select one of the menu items!===\n\n\
1. Show a list of vegetables\n\
2. Add a new type of vegetables\n\
3. Unload a batch of vegetables\n\
4. Unload a portion of the batch of vegetables\n\
5. Download a batch of vegetables\n\
6. View archive\n\
7. Clear archive\n\
0. Exit\n";
	std::cout << text << std::endl;
}

void Menu::show_list_of_vegetable(database & db)
{
	if (db.print_vegetable())
	{ }
	else
	{
		std::cout << "There is no vegetable!" << std::endl;

	}
}

void Menu::add_a_new_type_of_vegetables(database & db)
{
	std::cout << "Enter a product name: ";
	std::string t_name;
	std::cin >> t_name;
	db.add_name_veg(&t_name);
	db.create_new_table(&t_name);
}

void Menu::download_a_batch_of_vegetable(database & db)
{
	if (db.print_vegetable())
	{
		std::cout << "\nChoose which product you want to download: ";
		int choise;
		std::cin >> choise;
		if (db.check_ID_veg(&choise))
		{
			const std::string name_veg = db.get_name_veg(&choise);
			std::cout << "Enter the quantity of products: ";
			int count;
			std::cin >> count;
			Storage temp(name_veg, count);
			db.addBatch(temp);
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

void Menu::unload_a_batch_of_product(database & db)
{
	if (db.print_vegetable())
	{
		std::cout << "\nChoose which product you want to unload: ";
		int choise;
		std::cin >> choise;
		if (db.check_ID_veg(&choise))
		{
			system("cls");
			const std::string name_veg = db.get_name_veg(&choise);
			if (db.print_from_stor_room(&name_veg))
			{
				std::cout << "Select the batch you want to unload: ";
				int choise_batch;
				std::cin >> choise_batch;
				if (db.check_ID(&choise_batch, &name_veg))
				{
					Storage temp(choise_batch, name_veg);
					int count = db.get_count(temp);
					Storage temp1(choise_batch, name_veg, count);
					db.AddToArchive(temp1);
					db.dellBatch(temp);
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

void Menu::unload_a_portion_of_the_batch(database & db)
{
	if (db.print_vegetable())
	{
		std::cout << "\nChoose which product you want to unload: ";
		int choise;
		std::cin >> choise;
		if (db.check_ID_veg(&choise))
		{
			system("cls");
			const std::string name_veg = db.get_name_veg(&choise);
			if (db.print_from_stor_room(&name_veg))
			{
				std::cout << "Select the portion of the batch you want to unload: ";
				int choise_batch;
				std::cin >> choise_batch;
				if (db.check_ID(&choise_batch, &name_veg))
				{
					std::cout << "Enter count: ";
					int count;
					std::cin >> count;
					Storage temp(choise_batch, name_veg, count);
					Storage temp1(name_veg, count);
					if (db.changeCount(temp) == true)
					{
						db.AddToArchive(temp1);
					}
					else
					{
						printf("There are not so many products in the lot\n");
					}
				}
				else
				{
					std::cout << "Storage is empty!" << std::endl;

				}
			}
			else
			{
				std::cout << "There is no such party!" << std::endl;
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

void Menu::print_all_archive(database & db)
{
	if (db.print_all_archive())
	{ }
	else
	{
		std::cout << "Archive is clear!" << std::endl;
	}
}

void Menu::exit_prog(database &db)
{
	db.~database();
	exit(0);
}

//functions for password

void Menu::del_veget(database & db)
{
	Password pass;
	if (pass.password_verification(db))
	{
		if (db.print_vegetable())
		{
			std::cout << "\nChoose which product you want to delete: ";
			int choise;
			std::cin >> choise;
			if (db.check_ID_veg(&choise))
			{
				std::string name_veg = db.get_name_veg(&choise);
				db.del_name_veg(&choise);
				db.drop_table(&name_veg);
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

void Menu::clear_archive(database & db)
{
	Password pass;
	if (pass.password_verification(db))
	{
		db.ClearArchive();
	}
	else
	{
		printf("Invalid password");
	}
}

void Menu::change_password(database & db)
{
	Password pass;
	pass.change_password(db);
}





