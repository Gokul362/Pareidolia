#pragma once
#include <iostream>
#include <variant>
#include <vector>
#include <string>

void ReadBinary();

struct Pairs {

	std::string NewKey;
	std::variant<int, float, bool, std::string> NewValue;

};

inline std::vector<Pairs> PairsList;