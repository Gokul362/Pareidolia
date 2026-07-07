#pragma once
#include "Variables.h"


class Config {

	public:
		int Max_X_L;
		int Max_X_R;
		int GND;

		void Load(MapShortcut& map = PairsMap);

};