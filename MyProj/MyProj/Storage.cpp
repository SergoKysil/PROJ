#include "pch.h"
#include "Storage.h"


Storage::Storage()
{
}

Storage::Storage(const int & ID, const std::string & NAME_VEG)
{
	this->ID = std::make_shared<int>(ID);
	this->NAME_VEG = std::make_shared < std::string>(NAME_VEG);
}

std::string Storage::get_NAME_VEG() const
{
	return *NAME_VEG.get();
}

int Storage::get_ID() const
{
	return *ID.get();
}


Storage::~Storage()
{
}
