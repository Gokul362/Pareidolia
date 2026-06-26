#include "BinaryReader.h"
#include "Serializer.h"
#include "Main.h"
#include <iostream>

void WriteVariable() {

	for (int C = 0; C < PairsList.size(); C++) {
		std::cout << PairsList[C].NewKey << std::endl;
	}

	for (int i = 0; i < PairsList.size(); i++) {

		PairsMap[PairsList[i].NewKey] = PairsList[i].NewValue;

	}

}
