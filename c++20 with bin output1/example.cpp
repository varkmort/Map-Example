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



void PrintContaint(std::map<std::string, NameRecord*> &searcTable, std::vector<std::string> &names)
{
	for (const auto name : names)
	{
		if (searcTable.contains(name))
		{
			std::cout << "Name: " << searcTable.at(name)->name << " id: " << searcTable.at(name)->id << std::endl;
		}
		else
		{
			std::cout << name << " wasnt found\n";
		}
	}
		
}

std::vector<std::string> FindName(std::map<std::string, NameRecord*> searcTable, std::vector<std::string> names)
{
	std::vector<std::string> res;
	for (auto& name : names) {
		if (!searcTable.contains(name)) {
			//std::cout << name << " wasnt found\n";
		}
		else if (searcTable.at(name)->count == 1)
		{
			/*std::cout << searcTable.at(name)->name << " has " <<
				searcTable.at(name)->count << " owners\n";*/
			res.push_back(name);
		}
	}
	return res;
}

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
	std::vector<std::string> namesCount1 = FindName(searcTable, names);
	for (const auto it : namesCount1)
	{
		std::cout << it << '\n';
	}
	std::cout << std::endl;
	PrintContaint( searcTable, names);
	return 0;
}