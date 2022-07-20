#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

#include "Init.hpp"

int main()
{
	std::vector<NameRecord> db = GetNames();
	std::vector<std::string> names;
	std::ifstream in("names.txt");
	while (!in.eof()) {
		std::string tmp;
		in >> tmp;
		names.push_back(tmp);
	}
	//
	for (auto &name:names) {
		auto res = std::find_if(
			db.begin(), 
			db.end(),
			[&name](NameRecord &obj) {
				if (obj.name == name) {
					return true;
				}
				else {
					return false;
				}
			}
		);
		if (res == db.end()) {
			std::cout << name << " wasnt found\n";
		}
		else {
			std::cout << res->name << " has " << res->count << " owners\n";
		}
	}	
	return 0;
}