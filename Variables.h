#pragma once
#include <unordered_map>
#include <variant>
#include <string>

using VariantShortcut = std::variant<int, float, bool, std::string>;
using MapShortcut = std::unordered_map<std::string, VariantShortcut>;

inline MapShortcut PairsMap;


void WriteVariable();

