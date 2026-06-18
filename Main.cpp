#include <unordered_map>
#include "raylib.h"
#include "Main.h"
#include "FileWatcher.h"
#include "Serializer.h"
#include "BinaryReader.h"

int main() {

	// Initial Boot 
	BinaryConvert();
	ReadBinary();

	std::unordered_map<std::string, int> PairsMap;

	for (int i = 0; i < PairsList.size(); i++) {

		PairsMap[PairsList[i].NewKey] = i;

	}

	// Initial Variables
	int index = PairsMap["X"];
	Pairs& myInstance = PairsList[index];
	int x = std::get<int>(myInstance.NewValue);

	// Window Setup
	InitWindow(950, 600, "Pareidolia++");
	SetTargetFPS(60);


	while (!WindowShouldClose()) {

		BeginDrawing();

			ClearBackground(BLACK);
			DrawText("Pareidolia++", 300, 20, 40, DARKBLUE); // remember to change 300 to x

		EndDrawing();


		if (ChangeDetected() == true) {
			BinaryConvert();
			ReadBinary();

			std::unordered_map<std::string, int> PairsMap;

			for (int i = 0; i < PairsList.size(); i++) {

				PairsMap[PairsList[i].NewKey] = i;

			}

			// Variables Again
			index = PairsMap["X"];
			Pairs& myInstance = PairsList[index];
			x = std::get<int>(myInstance.NewValue);


		}



	}

	CloseWindow();


}
