#ifndef NAMES_HPP
#define NAMES_HPP

#include <string>
#include <istream>
#include <ostream>

struct NameRecord {
	int id;
	std::string name;
	bool sex;
	int count;
};

std::istream &operator>>(std::istream &in, NameRecord &data);
std::ostream &operator<<(std::ostream &out, NameRecord &data);

#endif // !NAMES_HPP