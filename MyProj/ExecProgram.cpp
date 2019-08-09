#include "pch.h"
#include "ExecProgram.h"



ExecProgram::ExecProgram()
{	
	dataBase = new DataBase("Storage", "localhost", "root", "");
	func = new FuncForMenu();
	password = new Password();
	info = new Info();
}

bool ExecProgram::Start()
{
	if (dataBase->connect_db())
		return true;
	else
		return false;

}

void ExecProgram::function_for_case1()
{
	bool go_back_from_case_1 = true;
	while (go_back_from_case_1)
	{
		dataBase->print_vegetable();
		func->go_back_for_menu1(go_back_from_case_1);
	}
}

void ExecProgram::function_for_case2()
{
	bool go_back_from_case_2 = true;
	while (go_back_from_case_2)
	{
		if (dataBase->print_vegetable()) {
			std::cout << "\nChoose which product you want to see: ";
			int choise;
			std::cin >> choise;
			if (dataBase->check_ID_veg(choise)) {
				system("cls");
				const std::string name_veg = dataBase->get_name_veg(choise);
				if (dataBase->print_from_stor_room(name_veg)) {}
				else std::cout << "Storage is empty!" << std::endl;
			}
			else std::cout << "There is no such ID!" << std::endl;
		}
		else std::cout << "There is no vegetable!" << std::endl;
		func->go_back_for_menu1(go_back_from_case_2);
	}
}

void ExecProgram::function_for_case3()
{
	bool go_back_from_case_3 = true;
	while (go_back_from_case_3)
	{
		std::cout << "Enter a product name: ";
		std::string t_name;
		std::cin >> t_name;
		dataBase->add_name_veg(t_name);
		dataBase->create_new_table(t_name);
		std::cout << ("Operation was successful!");
		func->go_back_for_menu1(go_back_from_case_3);
	}
}

void ExecProgram::function_for_case4()
{
	bool go_back_from_case_4 = true;
	while (go_back_from_case_4)
	{
		if (dataBase->print_vegetable()) {
			std::cout << "\nChoose which product you want to download: ";
			int choise;
			std::cin >> choise;
			if (dataBase->check_ID_veg(choise)) {
				const std::string name_veg = dataBase->get_name_veg(choise);
				std::cout << "Enter the quantity of products: ";
				int count;
				std::cin >> count;
				dataBase->addBatch(name_veg, count);
				std::cout << ("Operation was successful!");
			}
			else std::cout << "There is no such ID!" << std::endl;
		}
		else std::cout << "There is no vegetable!" << std::endl;
		func->go_back_for_menu1(go_back_from_case_4);
	}
}

void ExecProgram::function_for_case5()
{
	bool go_back_from_case_5 = true;
	while (go_back_from_case_5)
	{
		if (dataBase->print_vegetable()) {
			std::cout << "\nChoose which product you want to unload: ";
			int choise;
			std::cin >> choise;
			if (dataBase->check_ID_veg(choise)) {
				system("cls");
				const std::string name_veg = dataBase->get_name_veg(choise);
				if (dataBase->print_from_stor_room(name_veg)) {
					std::cout << "Select the batch you want to unload: ";
					int choise_batch;
					std::cin >> choise_batch;
					if (dataBase->check_ID(choise_batch, name_veg)) {
						int count = dataBase->get_count(name_veg, choise_batch);
						dataBase->AddToArchive(name_veg, count);
						dataBase->dellBatch(name_veg, choise_batch);
						std::cout << ("Operation was successful!");
					}
					else std::cout << "There is no such party!" << std::endl;
				}
				else std::cout << "Storage is empty!" << std::endl;
			}
			else std::cout << "There is no such ID!" << std::endl;
		}
		else std::cout << "There is no vegetable!" << std::endl;
		func->go_back_for_menu1(go_back_from_case_5);
	}
}

void ExecProgram::function_for_case6()
{
	bool go_back_from_case_6 = true;
	while (go_back_from_case_6)
	{
		if (dataBase->print_vegetable()) {
			std::cout << "\nChoose which product you want to unload: ";
			int choise;
			std::cin >> choise;
			if (dataBase->check_ID_veg(choise)) {
				system("cls");
				const std::string name_veg = dataBase->get_name_veg(choise);
				if (dataBase->print_from_stor_room(name_veg)) {
					std::cout << "Select the portion of the batch you want to unload: ";
					int choise_batch;
					std::cin >> choise_batch;
					if (dataBase->check_ID(choise_batch, name_veg)) {
						std::cout << "Enter count: ";
						int count;
						std::cin >> count;
						if (dataBase->changeCount(name_veg, choise_batch, count) == true) {
							dataBase->AddToArchive(name_veg, count);
							std::cout << ("Operation was successful!");
						}
						else std::cout << ("There are not so many products in the lot\n");
					}
					else std::cout << "There is no such party!" << std::endl;
				}
				else std::cout << "Storage is empty!" << std::endl;
			}
			else std::cout << "There is no such ID!" << std::endl;
		}
		else std::cout << "There is no vegetable!" << std::endl;
		func->go_back_for_menu1(go_back_from_case_6);
	}
}

void ExecProgram::function_for_case7()
{
	bool go_back_from_case_7 = true;
	while (go_back_from_case_7)
	{
		if (dataBase->print_all_archive()) {}
		else std::cout << "Archive is clear!" << std::endl;
		func->go_back_for_menu2(go_back_from_case_7);
	}
}

void ExecProgram::function_for_close_case1(bool & go_back)
{
	bool go_back_from_closed_case_1 = true;
	while (go_back_from_closed_case_1)
	{
		if (dataBase->print_vegetable()) {
			std::cout << "\nChoose which product you want to delete: ";
			int choise;
			std::cin >> choise;
			if (dataBase->check_ID_veg(choise)) {
				std::string name_veg = dataBase->get_name_veg(choise);
				dataBase->del_name_veg(choise);
				dataBase->drop_table(name_veg);
				std::cout << ("Operation was successful!");
			}
			else std::cout << "There is no product under this ID!" << std::endl;
		}
		else std::cout << "There is no vegetable!" << std::endl;
		func->go_back_for_menu_for_close_func(go_back_from_closed_case_1, go_back);
	}
}

void ExecProgram::function_for_close_case2(bool & go_back)
{
	bool go_back_from_closed_case_2 = true;
	while (go_back_from_closed_case_2)
	{
		dataBase->ClearArchive();
		std::cout << ("Operation was successful!");
		func->go_back_for_menu_for_close_func(go_back_from_closed_case_2, go_back);
	}
}

void ExecProgram::function_for_close_case3(bool & go_back)
{
	bool go_back_from_closed_case_3 = true;
	while (go_back_from_closed_case_3)
	{
		password->change_password(*dataBase);
		func->go_back_for_menu_for_close_func(go_back_from_closed_case_3, go_back);
	}
}

void ExecProgram::function_for_case8()
{
	if (password->password_verification(*dataBase))
	{
		bool menu_with_close_func = true;
		while (menu_with_close_func)
		{
			func->print_menu_for_closed_function();
			int choise_close_func;
			std::cout << "Your choise: ";
			std::cin >> choise_close_func;
			switch (choise_close_func)
			{
			case 1:
			{
				function_for_close_case1(menu_with_close_func);
			}
			break;

			case 2:
			{
				function_for_close_case2(menu_with_close_func);
			}
			break;

			case 3:
			{
				function_for_close_case3(menu_with_close_func);
			}
			break;

			case 4:
			{
				menu_with_close_func = false;
			}
			break;

			case 0: exit(0);
				break;

			default: std::cout << ("\nInvalid choise!\n");
				break;
			}
		}
	}
}

void ExecProgram::function_for_info_case1(bool & go_back)
{
	bool go_back_from_info_case_back_1 = true;
	while (go_back_from_info_case_back_1)
	{
		info->Help_for_use();
		func->print_back_menu_for_close_func();
		func->choise_back_menu_for_close_func(go_back_from_info_case_back_1, go_back);
	}
}

void ExecProgram::function_for_info_case2(bool & go_back)
{
	bool go_back_from_info_case_back_2 = true;
	while (go_back_from_info_case_back_2)
	{
		info->About_the_program();
		func->print_back_menu_for_close_func();
		func->choise_back_menu_for_close_func(go_back_from_info_case_back_2, go_back);
	}
}

void ExecProgram::function_for_case9()
{
	bool menu_info = true;
	while (menu_info)
	{
		func->print_info_menu();
		int choise_item_of_menu_info;
		std::cout << "Your choise: ";
		std::cin >> choise_item_of_menu_info;
		switch (choise_item_of_menu_info)
		{
		case 1:
		{
			function_for_info_case1(menu_info);
		}
		break;

		case 2:
		{
			function_for_info_case2(menu_info);
		}
		break;

		case 3:
		{
			menu_info = false;
		}
		break;

		case 0: exit(0);
			break;

		default: std::cout << ("\nInvalid choise!\n");
			break;
		}
	}
}

void ExecProgram::Implementation_Program()
{
	if (Start())
	{
		system("cls");
		bool menu_choise = true;
		while (menu_choise)
		{
			system("cls");
			func->print_menu();
			int choise;
			std::cout << "Your choise: ";
			std::cin >> choise;
			system("cls");
			switch (choise)
			{
			case 1:
			{
				function_for_case1();
			}
			break;

			case 2:
			{
				function_for_case2();
			}
			break;

			case 3:
			{
				function_for_case3();
			}
			break;

			case 4:
			{
				function_for_case4();
			}
			break;

			case 5:
			{
				function_for_case5();
			}
			break;

			case 6:
			{
				function_for_case6();
			}
			break;

			case 7:
			{
				function_for_case7();
			}
			break;

			case 8:
			{
				function_for_case8();
			}
			break;

			case 9:
			{
				function_for_case9();
			}

			case 0: exit(0);
				break;

			default:
			{
				system("cls");
				std::cout << "\nInvalid input!!!\n" << std::endl;
				Sleep(1000);
				system("cls");
			}
			break;
			}
		}
	}
}
