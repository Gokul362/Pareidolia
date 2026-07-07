#include "raylib.h"
#include "Main.h"
#include "FileWatcher.h"
#include "Serializer.h"
#include "BinaryReader.h"
#include "Variables.h"


// Non framework #includes
#include "Players.h"


int main() {

	// Initial Boot 
	BinaryConvert();
	ReadBinary();
	WriteVariable();


	LoadPlayers();

	// Declare your variables here
	// 
	// Maybe make an "isReloadable" boolean
	int Max_X_L = ConvertToInt(PairsMap, "MAX_X_L");
	int Max_X_R = ConvertToInt(PairsMap, "MAX_X_R");
	int GND = ConvertToInt(PairsMap, "GND");





	// Window Setup
	InitWindow(950, 600, "Untitled");
	SetTargetFPS(60);


	while (!WindowShouldClose()) {


		MovementAndCollision(Kumo, GND);
		MovementAndCollision(Fry, GND);

		//std::cout << GetFrameTime() << std::endl;

		BeginDrawing();

			ClearBackground(BLACK);
			DrawRectangle(Kumo.x, Kumo.y, 50, 50, RED);
			DrawRectangle(Fry.x, Fry.y, 50, 50, YELLOW);
			DrawRectangle(0, 500, 950, 10, DARKBLUE);

		EndDrawing();


		if (ChangeDetected() == true) {
			BinaryConvert();
			ReadBinary();
			WriteVariable();

			// Re-Assign your variables here but leave out the ones that are not supposed to be hot-reloaded

			Kumo.speed = ConvertToFloat(PairsMap, "Entities.Player.Kumo.Speed");
			Kumo.gravity = ConvertToInt(PairsMap, "Entities.Player.Kumo.Gravity");
			Kumo.JumpForce = ConvertToInt(PairsMap, "Entities.Player.Kumo.JumpForce");
			Kumo.left = ConvertToInt(PairsMap, "Entities.Player.Kumo.Controls.Left");
			Kumo.right = ConvertToInt(PairsMap, "Entities.Player.Kumo.Controls.Right");
			Kumo.up = ConvertToInt(PairsMap, "Entities.Player.Kumo.Controls.Up");
			Kumo.yVelocity = 0.0f;


			Fry.speed = ConvertToFloat(PairsMap, "Entities.Player.Fry.Speed");
			Fry.gravity = ConvertToInt(PairsMap, "Entities.Player.Fry.Gravity");
			Fry.JumpForce = ConvertToInt(PairsMap, "Entities.Player.Fry.JumpForce");
			Fry.left = ConvertToInt(PairsMap, "Entities.Player.Fry.Controls.Left");
			Fry.right = ConvertToInt(PairsMap, "Entities.Player.Fry.Controls.Right");
			Fry.up = ConvertToInt(PairsMap, "Entities.Player.Fry.Controls.Up");
			Fry.yVelocity = 0.0f;

		}

	}

	CloseWindow();

}





