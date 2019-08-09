#include "pch.h"
#include "Password.h"


bool Password::password_verification(DataBase & work)
{
	std::cout << "Enter password: ";
	std::string entered_pass;
	std::cin >> entered_pass;
	std::string current_pass = work.get_password();
	return (entered_pass == current_pass);
}

void Password::change_password(DataBase & work)
{
	std::cout << "Enter your old password: ";
	std::string entered_password;
	std::cin >> entered_password;
	std::string current_password = work.get_password();
	if (entered_password == current_password)
	{
		std::cout << "Enter new password: ";
		std::string new_password;
		std::cin >> new_password;
		work.change_password(new_password);
		std::cout << "Your password was changed!" << std::endl;
	}
	else std::cout << "Invalid password!" << std::endl;
}

