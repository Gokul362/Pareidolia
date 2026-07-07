#include "Config.h"
#include "Variables.h"


void Config::Load(MapShortcut& map) {

	Max_X_L = std::get<int>(map["Max_X_L"]);
	Max_X_R = std::get<int>(map["Max_X_R"]);
	GND = std::get<int>(map["GND"]);

}