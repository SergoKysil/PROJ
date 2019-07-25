#include "pch.h"
#include "Storage.h"


Storage::Storage()
{
}

Storage::Storage(const std::string & NAME_VEG, int &count_prod)
{

	this->NAME_VEG = std::make_shared < std::string>(NAME_VEG);
	this->count_prod = std::make_shared<int>(count_prod);
}

std::string Storage::get_NAME_VEG() const
{
	return *NAME_VEG.get();
}


int Storage::get_count_prod() const
{
	return *count_prod.get();
}



Storage::~Storage()
{
}
