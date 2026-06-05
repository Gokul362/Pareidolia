#pragma once
#include <variant>

void ReadBinary();

struct Pairs {

	std::variant<int, float, bool, std::string> NewKey;
	std::variant<int, float, bool, std::string> NewValue;

};