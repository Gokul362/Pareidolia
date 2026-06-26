#pragma once
#include <unordered_map>
#include <variant>
#include <string>

inline std::unordered_map<std::string, std::variant<int, float, bool, std::string>> PairsMap;