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
	Sleep(2000);
	system("cls");
	bool menu_choise = true;
	while (menu_choise)
	{
		system("cls");
		menu.print_menu();
		int choise;
		std::cout << "Your choise: ";
		std::cin >> choise;
		switch (choise)
		{
		case 1:
		{
			bool case1 = true;
			while (case1)
			{
				menu.show_list_of_vegetable(DB);
				menu.print_min_menux();
				menu.choise_min_menu2(&case1);
			}
		}
		break;

		case 2:
		{
			bool case2 = true;
			while (case2)
			{
				menu.print_from_room(DB);
				menu.print_min_menu();
				menu.choise_min_menu(&case2);
			}
		}
		break;

		case 3:
		{
			bool case3 = true;
			while (case3)
			{
				menu.add_a_new_type_of_vegetables(DB);
				menu.print_min_menu();
				menu.choise_min_menu(&case3);	
			}
		}
		break;

		case 4:
		{
			bool case4 = true;
			while (case4)
			{
				menu.unload_a_batch_of_product(DB);
				menu.print_min_menu();
				menu.choise_min_menu(&case4);
			}
		}
		break;

		case 5:
		{
			bool case5 = true;
			while (case5)
			{
				menu.unload_a_portion_of_the_batch(DB);
				menu.print_min_menu();
				menu.choise_min_menu( &case5);
			}
		}
		break;

		case 6:
		{
			bool case6 = true;
			while (case6)
			{
				menu.download_a_batch_of_vegetable(DB);
				menu.print_min_menu();
				menu.choise_min_menu(&case6);
			}
		}
		break;

		case 7:
		{
			bool case7 = true;
			while (case7)
			{
				menu.print_all_archive(DB);
				menu.print_min_menux();
				menu.choise_min_menu2(&case7);
			}
		}
		break;

		case 8:
		{
			bool menu_close_func = true;
			while(menu_close_func)
			{
				menu.print_closed_function();
				int choise_close_func;
				std::cout << "Your choise: ";
				std::cin >> choise_close_func;
				switch (choise_close_func)
				{
				case 1:
				{
					bool casex1 = true;
					while (casex1)
					{
						menu.del_veget(DB);
						menu.print_min_menux();
						menu.choise_min_menux(&casex1, &menu_close_func);
					}
				}
				break;

				case 2:
				{
					bool casex2 = true;
					while (casex2)
					{
						menu.clear_archive(DB);
						menu.print_min_menux();
						menu.choise_min_menux(&casex2, &menu_close_func);
					}
				}
				break;

				case 3:
				{
					bool casex3 = true;
					while (casex3)
					{
						menu.change_password(DB);
						menu.print_min_menux();
						menu.choise_min_menux(&casex3, &menu_close_func);
					}
				}
				break;

				default: printf("Invalid choise!");
					break;
				}
			}
		}
		break;

		case 0: exit(0);
			break;

		default:
		{
			system("cls");
			std::cout << "Invalid input!!!" << std::endl;
			Sleep(2000);
			system("cls");
		}
		break;
		}
	}
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