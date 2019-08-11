#include "pch.h"
#include "Password.h"




std::string Password::hash(std::string & pass)
{
	std::string hashpass = pass;
	std::size_t str_hash = std::hash<std::string>{}(hashpass);
	return std::to_string(str_hash);
}

bool Password::password_verification(DataBase & data)
{	
	std::cout << "Enter password: ";
	std::string entered_pass;
	std::cin >> entered_pass;
	std::string hashpass = hash(entered_pass);
	std::string current_pass = data.get_password();	
	return (hashpass == current_pass);
}

void Password::change_password(DataBase & data)
{

	if (password_verification(data))
	{
		std::cout << "Enter new password: ";
		std::string new_password;
		std::cin >> new_password;
		std::string new_hash_password = hash(new_password);
		data.change_password(new_hash_password);
		std::cout << "Your password was changed!" << std::endl;
	}
	else std::cout << "Invalid password!" << std::endl;
}
