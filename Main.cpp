#include "raylib.h"
#include "Main.h"
#include "FileWatcher.h"
#include "Serializer.h"
#include "BinaryReader.h"
#include "Variables.h"
#include "Config.h"


// Non framework #includes
#include "Players.h"


int main() {

	// Initial Boot 
	BinaryConvert();
	ReadBinary();
	WriteVariable();


	Player Kumo;
	Player Fry;
	Kumo.LoadPlayers("Entities.Player.Kumo");
	Fry.LoadPlayers("Entities.Player.Fry");


	Config GameConfig;
	GameConfig.Load();





	// Window Setup
	InitWindow(950, 600, "Untitled");
	SetTargetFPS(60);


	while (!WindowShouldClose()) {


		Kumo.MovementAndCollision(GameConfig);
		Fry.MovementAndCollision(GameConfig);

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

			Kumo.Reload("Entities.Player.Kumo");
			Fry.Reload("Entities.Player.Fry");


		}

	}

	CloseWindow();

}





