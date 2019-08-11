#include "pch.h"
#include <iostream>
#include "mysql.h"
#include "ExecProgram.h"
#include "DataBase.h"
#include "FuncForMenu.h"
#include "Info.h"
#include "Password.h"



int main()
{
	ExecProgram launch;

	launch.Implementation_Program();

	launch.~ExecProgram();


	return 0;

}