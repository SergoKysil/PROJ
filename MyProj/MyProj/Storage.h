#pragma once
#include <iostream>
#include <string>

class Storage
{
public:
	Storage();
	explicit Storage(const std::string &NAME_VEG, int &count_prod);
	explicit Storage(const int &ID, const std::string &NAME_VEG, int &count_prod);
	explicit Storage(const int &ID, const std::string &NAME_VEG);
	explicit Storage(const int &ID, const int &count_prod);

	int get_ID() const;
	int get_count_prod() const;
	std::string get_NAME_VEG() const;
	
	void set_NAME_VEG(const std::string &NAME_VEG);
	void set_count_prod(const int &count_prod);
	void set_ID(const int &ID);
	
	~Storage();
private:
	std::shared_ptr<int> count_prod;
	std::shared_ptr<int> ID;
	std::shared_ptr<std::string> NAME_VEG;
};


