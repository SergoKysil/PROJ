#include "pch.h"
#include "FuncForMenu.h"

void FuncForMenu::print_menu()
{
	std::string text = "===Select one of the menu items!===\n\n\
1. Show a list of vegetables\n\
2. View the contents of one of the repositories\n\
3. Add a new type of vegetables\n\
4. Download a batch of vegetables\n\
5. Unload a batch of vegetables\n\
6. Unload a portion of the batch of vegetables\n\
7. View archive\n\
8. View closed function\n\
9. Reference\n\
0. Exit\n";
	std::cout << text << std::endl;
}

void FuncForMenu::print_menu_for_closed_function()
{
	std::string text = "1. Delete information about a particular vegetable\n\
2. Clear the archive\n\
3. Change password\n\n\
4. Return to the main menu\n\
0. Exit\n";
	std::cout << text << std::endl;
}

void FuncForMenu::print_info_menu()
{
	std::string text = "1. Help for use\n\
2. About program\n\
3. Return to the main menu\n\
0. Exit\n";
	std::cout << text << std::endl;
}

void FuncForMenu::print_back_menu1()
{
	std::string text = "\n1. Return to the main menu\n\
2. Continue performing this function\n\
0. Exit\n";
	std::cout << text << std::endl;
}

void FuncForMenu::print_back_menu2()
{
	std::string text = "\n1. Return to the main menu\n\
0. Exit\n";
	std::cout << text;
}

void FuncForMenu::print_back_menu_for_close_func()
{
	std::string text = "\n1. Return to the main function\n\
2. Stay in this menu\n\
0. Exit\n";
	std::cout << text;
}

void FuncForMenu::choise_back_menu1(bool & case_x)
{
	int choise_case;
	bool back = true;
	while (back)
	{
		std::cout << "\nYour choise: ";
		std::cin >> choise_case;
		if (choise_case == 1) {
			system("cls");
			back = false;
			case_x = false;
		}
		else if (choise_case == 2) {
			system("cls");
			back = false;
		}
		else if (choise_case == 0)
			exit(0);
		else {
			std::cout << ("\nInvalid choise!\n");
			back = true;
		}
	}
}

void FuncForMenu::choise_back_menu2(bool & case_x)
{
	int choise_case;
	bool back = true;
	while (back)
	{
		std::cout << "\nYour choise: ";
		std::cin >> choise_case;
		if (choise_case == 1) {
			system("cls");
			back = false;
			case_x = false;
		}
		else if (choise_case == 0)
			exit(0);
		else {
			std::cout << ("\nInvalid choise!\n");
			back = true;
		}
	}
}

void FuncForMenu::choise_back_menu_for_close_func(bool & case_x, bool & menux)
{
	int choise_case;
	bool back = true;
	while (back)
	{
		std::cout << "\nYour choise: ";
		std::cin >> choise_case;
		if (choise_case == 1) {
			system("cls");
			back = false;
			case_x = false;
			menux = false;
		}
		else if (choise_case == 2) {
			system("cls");
			back = false;
			case_x = false;
		}
		else if (choise_case == 0)
			exit(0);
		else {
			std::cout << ("\nInvalid choise!\n");
			back = true;
		}
	}
}

void FuncForMenu::go_back_for_menu1(bool & case_x)
{
	print_back_menu1();
	choise_back_menu1(case_x);
}

void FuncForMenu::go_back_for_menu2(bool & case_x)
{
	print_back_menu2();
	choise_back_menu2(case_x);
}

void FuncForMenu::go_back_for_menu_for_close_func(bool & case_x, bool & menux)
{
	print_back_menu_for_close_func();
	choise_back_menu_for_close_func(case_x, menux);
}




