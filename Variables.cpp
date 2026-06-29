#include "BinaryReader.h"
#include "Serializer.h"
#include "Main.h"
#include "Variables.h"
#include <iostream>
#include <typeinfo>


int ConvertToInt(MapShortcut& map, std::string key) {
	
	return std::get<int>(map[key]);

}

float ConvertToFloat(MapShortcut& map, std::string key) {

	return std::get<float>(map[key]);

}

bool ConvertToBool(MapShortcut& map, std::string key) {

	return std::get<bool>(map[key]);

}

std::string ConvertToString(MapShortcut& map, std::string key) {

	return std::get<std::string>(map[key]);

}



void WriteVariable() {

	for (int C = 0; C < PairsList.size(); C++) {
		std::cout << PairsList[C].NewKey << std::endl;
	}

	for (int i = 0; i < PairsList.size(); i++) {

		PairsMap[PairsList[i].NewKey] = PairsList[i].NewValue;

	}

}
