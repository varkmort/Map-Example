#include "name.hpp"

std::istream &operator>>(std::istream &in, NameRecord &data) {
	std::string tmp;
	std::getline(in, tmp, ';');
	data.id = std::atoi(tmp.c_str());
	std::getline(in, tmp, ';');
	data.name = tmp;
	std::getline(in, tmp, ';');
	if (tmp == "Ж") {
		data.sex = false;
	}
	else {
		data.sex = true;
	}
	std::getline(in, tmp, ';');
	data.count = std::atoi(tmp.c_str());
	return in;
}

std::ostream &operator<<(std::ostream &out, NameRecord &data) {
	out << data.id << ' ' << data.name << ' ';
	out << ((data.sex)?"male":"female") << ' ' << data.count;
	return out;
}
