#include "pch.h"
#include "Info.h"


void Info::Help_for_use()
{
	std::string text = R"r(\
=======================HELP FOR USE========================\n\
Upon entering the program, you will be informed whether you\n\
have been able to connect to the server, if all goes well,\n\
you will go to the main menu of the program, otherwise the\n\
program will display an error in the operation and will be closed.\n\
The program is navigated with the keys 0-9 and Enter.\n\
To move from one program item to another, enter the corresponding key.\n\
In case of non-compliance, the program will fail, but you will\n\
still be able to use the program. In addition to the main menu,\n\
the program also has a menu with closed features that require\n\
a password to use. You can request a password from the developer\n\
or department manager. A password change is also available in case of need.\n)r";
	std::cout << text << std::endl;
}

void Info::About_the_program()
{
	std::string text = R"r(\
The program is designed purely for educational purposes,\n\
in the format of course work and not for commercial purposes.\n\n\
\t\tPA (Product Accouning) - Product 49corp.\n\
The program can show the list of products available for download,\n\
adding new types of products, records the data on the supply of\n\
products in the appropriate tables, and information on the upload\n\
of products in the archive.Unloading is possible in both batches and parts,\n\
allowing you to view the products already in storage and archival data.\n\
Interface through console menu.\n\n\
Program Version: 1.0.0\n\n\
Last updated : 08 / 01 / 2019\n\n\
Manufacturer: S.K.R. (49sorp.)\n)r";
	std::cout << text << std::endl;

}
