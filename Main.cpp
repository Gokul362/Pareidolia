#include <unordered_map>
#include "raylib.h"
#include "Main.h"
#include "FileWatcher.h"
#include "Serializer.h"
#include "BinaryReader.h"


// Use these functions to create your variables
int ConvertToInt(auto& map, auto key) {

	return std::get<int>(map[key]);

}

float ConvertToFloat(auto& map, auto key) {

	return std::get<float>(map[key]);

}

bool ConvertToBool(auto& map, auto key) {

	return std::get<bool>(map[key]);

}

std::string ConvertToString(auto& map, auto key) {

	return std::get<std::string>(map[key]);

}



int main() {

	std::unordered_map<std::string, std::variant<int, float, bool, std::string>> PairsMap;

	// Initial Boot 
	BinaryConvert();
	ReadBinary();

	for (int i = 0; i < PairsList.size(); i++) {

		PairsMap[PairsList[i].NewKey] = PairsList[i].NewValue;

	}

	// Declare your variables here
	int x = ConvertToInt(PairsMap, "x");
	int y = ConvertToInt(PairsMap, "y");
	int size = ConvertToInt(PairsMap, "size");

	// Window Setup
	InitWindow(950, 600, "Untitled");
	SetTargetFPS(60);


	while (!WindowShouldClose()) {

		BeginDrawing();

			ClearBackground(BLACK);
			DrawText("Testing", x, y, size, DARKBLUE); // remember to change 300 to x

		EndDrawing();


		if (ChangeDetected() == true) {
			BinaryConvert();
			ReadBinary();

			for (int i = 0; i < PairsList.size(); i++) {

				PairsMap[PairsList[i].NewKey] = PairsList[i].NewValue;

			}

			// Re-Assign your variables here
			x = ConvertToInt(PairsMap, "x");
			y = ConvertToInt(PairsMap, "y");
			size = ConvertToInt(PairsMap, "size");

		}



	}

	CloseWindow();


}
