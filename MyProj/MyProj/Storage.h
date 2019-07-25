#pragma once
#include <iostream>
#include <string>
class Storage
{
public:
	Storage();
	explicit Storage( const std::string &NAME_VEG, int &count_prod);

	
	int get_count_prod() const;
	std::string get_NAME_VEG() const;
	

	~Storage();
private:
	std::shared_ptr<int> count_prod;
	
	std::shared_ptr<std::string> NAME_VEG;
};

