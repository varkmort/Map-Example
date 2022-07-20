#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>

#include "Init.hpp"

void FindByVector(std::vector<NameRecord>& db, std::vector<std::string> &names)
{
	for (auto &name : names) {
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
}

std::vector<std::string> OneOwner(std::map<std::string, NameRecord*> &searchTable, std::vector<std::string> &names) {
	

	std::vector<std::string> result;
	

	for (auto &name : names) {

		if (!searchTable.contains(name)) {
			result.emplace_back(name);
			return result;
		}
		else if (searchTable.at(name)->count == 1) {
			return;
		}
	}

};

int main()
{
	system("chcp 65001");
	std::vector<NameRecord> db = GetNames();
	std::vector<std::string> names;
	std::ifstream in("names.txt");
	while (!in.eof()) {
		std::string tmp;
		in >> tmp;
		names.push_back(tmp);
	}
	//
	std::map<std::string, NameRecord *> searcTable;
	for (auto &record:db) {
		searcTable.insert({record.name, &record});
	}
	for (auto &name : names) {
		if (!searcTable.contains(name)) {
			std::cout << name << " wasnt found\n";
		}
		else {
			std::cout << searcTable[name]->name << " has " <<
				searcTable[name]->count << " owners\n";
		}
	}


	return 0;
}