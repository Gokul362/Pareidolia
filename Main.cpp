#include "raylib.h"
#include "Main.h"
#include "FileWatcher.h"
#include "Serializer.h"
#include "BinaryReader.h"
#include "Variables.h"


int main() {

	// Initial Boot 
	BinaryConvert();
	ReadBinary();
	WriteVariable();


	// Declare your variables here
	int x = ConvertToInt(PairsMap, "x");
	float y = ConvertToFloat(PairsMap, "y");
	int speed = ConvertToFloat(PairsMap, "Entities.Player.Kumo.Speed");
	int gravity = ConvertToInt(PairsMap, "Entities.Player.Kumo.Gravity"); // Maybe make an "isReloadable" boolean
	int Max_X_L = ConvertToInt(PairsMap, "MAX_X_L");
	int Max_X_R = ConvertToInt(PairsMap, "MAX_X_R");
	int GND = ConvertToInt(PairsMap, "GND");
	int JumpForce = ConvertToInt(PairsMap, "Entities.Player.Kumo.JumpForce");

	float yVelocity = 0.0f;
	bool isGrounded = false;

	// Window Setup
	InitWindow(950, 600, "Untitled");
	SetTargetFPS(60);


	while (!WindowShouldClose()) {

		float DeltaTime = GetFrameTime();

		if (y > GND) {
			isGrounded = true;
			y = GND;
		}
		
		if (!isGrounded) {
			yVelocity += gravity * DeltaTime;

		}
		
		if (IsKeyPressed(KEY_W) && isGrounded) {
			yVelocity = JumpForce;
			isGrounded = false;
		}


		y += yVelocity * DeltaTime;
		//std::cout << y << std::endl;


		if (IsKeyDown(KEY_A)) {
			x -= speed;
		}
		else if (IsKeyDown(KEY_D)) {
			x += speed;
		}

		if (x <= 0) {
			x = 0;
		}
		else if (x >= 900) {
			x = 900;
		}

		BeginDrawing();

			ClearBackground(BLACK);
			DrawRectangle(x, y, 50, 50, RED); 
			DrawRectangle(0, 500, 950, 10, DARKBLUE);

		EndDrawing();


		if (ChangeDetected() == true) {
			BinaryConvert();
			ReadBinary();
			WriteVariable();

			// Re-Assign your variables here but leave out the ones that are not supposed to be hot-reloaded
			x = ConvertToInt(PairsMap, "x");
			y = ConvertToFloat(PairsMap, "y");
			speed = ConvertToFloat(PairsMap, "Entities.Player.Kumo.Speed");
			gravity = ConvertToInt(PairsMap, "Entities.Player.Kumo.Gravity");
			Max_X_L = ConvertToInt(PairsMap, "MAX_X_L");
			Max_X_R = ConvertToInt(PairsMap, "MAX_X_R");
			JumpForce = ConvertToInt(PairsMap, "Entities.Player.Kumo.JumpForce");

		}

	}

	CloseWindow();

}





