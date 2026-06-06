#include "raylib.h"
#include "FileWatcher.h"
#include "Serializer.h"
#include "BinaryReader.h"
#include <iostream>

int main() {

	InitWindow(950, 600, "Pareidolia++");
	SetTargetFPS(60);

	while (!WindowShouldClose()) {

		BeginDrawing();

			ClearBackground(WHITE);
			DrawText("Everything is fine!", 20, 20, 20, DARKBLUE);

		EndDrawing();


		if (ChangeDetected() == true) {
			BinaryConvert();
			ReadBinary();
		}

		


	}

	CloseWindow();


}
