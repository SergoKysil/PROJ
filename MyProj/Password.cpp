#include "pch.h"
#include "Password.h"


Password::Password()
{
}

bool Password::password_verification(database & db)
{
	std::cout << "Enter password: ";
	std::string entered_pass;
	std::cin >> entered_pass;
	std::string current_pass = db.get_password();
	if (entered_pass == current_pass)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Password::change_password(database & db)
{
	std::cout << "Enter your old password: ";
	std::string entered_password;
	std::cin >> entered_password;
	std::string current_password = db.get_password();
	if (entered_password == current_password)
	{
		std::cout << "Enter new password: ";
		std::string new_password;
		std::cin >> new_password;
		db.change_password(&new_password);
		printf("Your password was changed!");
	}
	else
	{
		printf("Invalid password!");
	}

}

Password::~Password()
{
}
