#include "pch.h"
#include "Storage.h"


Storage::Storage()
{
}

Storage::Storage(const std::string & NAME_VEG,const int &count_prod)
{
	this->NAME_VEG = std::make_shared <std::string>(NAME_VEG);
	this->count_prod = std::make_shared<int>(count_prod);
}

Storage::Storage(const int & ID, const std::string & NAME_VEG,const int  & count_prod)
{
	this->ID = std::make_shared<int>(ID);
	this->NAME_VEG = std::make_shared<std::string>(NAME_VEG);
	this->count_prod = std::make_shared<int>(count_prod);
}

Storage::Storage(const int & ID, const std::string & value)
{
	this->ID = std::make_shared<int>(ID);
	this->NAME_VEG = std::make_shared<std::string>(value);
}

Storage::Storage(const int & ID, const int & count_prod)
{
	this->ID = std::make_shared<int>(ID);
	this->count_prod = std::make_shared<int>(count_prod);
}



std::string Storage::get_NAME_VEG() const
{
	return *NAME_VEG.get();
}

int Storage::get_ID() const
{
	return *ID.get();
}

int Storage::get_count_prod() const
{
	return *count_prod.get();
}

void Storage::set_NAME_VEG(const std::string &NAME_VEG)
{
	this->NAME_VEG = std::make_shared<std::string>(NAME_VEG);
}

void Storage::set_count_prod(const int &count_prod)
{
	this->count_prod = std::make_shared<int>(count_prod);
}

void Storage::set_ID(const int &ID)
{
	this->ID = std::make_shared<int>(ID);
}

Storage::~Storage()
{
}
