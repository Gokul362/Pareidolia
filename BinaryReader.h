#pragma once
#include <variant>
#include <vector>

void ReadBinary();

struct Pairs {

	std::vector<char> NewKey;
	std::variant<int, float, bool, std::vector<char>> NewValue;

};

inline std::vector<Pairs> PairsList;