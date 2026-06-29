#pragma once
#include <unordered_map>
#include <variant>
#include <string>

using VariantShortcut = std::variant<int, float, bool, std::string>;
using MapShortcut = std::unordered_map<std::string, VariantShortcut>;

inline std::unordered_map<std::string, std::variant<int, float, bool, std::string>> PairsMap;

int ConvertToInt(MapShortcut& map, std::string key);
float ConvertToFloat(MapShortcut& map, std::string key);
bool ConvertToBool(MapShortcut& map, std::string key);
std::string ConvertToString(MapShortcut& map, std::string key);

void WriteVariable();

