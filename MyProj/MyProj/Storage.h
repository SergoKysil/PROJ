#pragma once
#include <iostream>
#include <string>
class Storage
{
public:
	Storage();
	explicit Storage(const int &ID, const std::string &NAME_VEG);

	int get_ID() const;
	std::string get_NAME_VEG() const;
	

	~Storage();
private:
	std::shared_ptr<int> ID;
	std::shared_ptr<std::string> NAME_VEG;
};

