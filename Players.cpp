#include "Variables.h"
#include "Players.h"
#include "raylib.h"

void LoadPlayers() {


	Kumo.x = ConvertToInt(PairsMap, "x");
	Kumo.y = ConvertToInt(PairsMap, "y");
	Kumo.speed = ConvertToFloat(PairsMap, "Entities.Player.Kumo.Speed");
	Kumo.gravity = ConvertToInt(PairsMap, "Entities.Player.Kumo.Gravity");
	Kumo.JumpForce = ConvertToInt(PairsMap, "Entities.Player.Kumo.JumpForce");
	Kumo.yVelocity = 0.0f;
	Kumo.left = ConvertToInt(PairsMap, "Entities.Player.Kumo.Controls.Left");
	Kumo.right = ConvertToInt(PairsMap, "Entities.Player.Kumo.Controls.Right");
	Kumo.up = ConvertToInt(PairsMap, "Entities.Player.Kumo.Controls.Up");
	Kumo.isGrounded = false;


	Fry.x = ConvertToInt(PairsMap, "x");
	Fry.y = ConvertToInt(PairsMap, "y");
	Fry.speed = ConvertToFloat(PairsMap, "Entities.Player.Fry.Speed");
	Fry.gravity = ConvertToInt(PairsMap, "Entities.Player.Fry.Gravity");
	Fry.JumpForce = ConvertToInt(PairsMap, "Entities.Player.Fry.JumpForce");
	Fry.left = ConvertToInt(PairsMap, "Entities.Player.Fry.Controls.Left");
	Fry.right = ConvertToInt(PairsMap, "Entities.Player.Fry.Controls.Right");
	Fry.up = ConvertToInt(PairsMap, "Entities.Player.Fry.Controls.Up");
	Fry.isGrounded = false;
	Fry.yVelocity = 0.0f;

}


void MovementAndCollision(Player& Player, int GND) {

	float DeltaTime = GetFrameTime();

	if (Player.y >= GND) {
		Player.isGrounded = true;
		Player.y = GND;
		Player.yVelocity = 0.0f;
	}

	if (!Player.isGrounded) {
		Player.yVelocity += Player.gravity * DeltaTime;

	}

	if (IsKeyPressed(Player.up) && Player.isGrounded) {
		Player.yVelocity = Player.JumpForce;
		Player.isGrounded = false;
	}


	Player.y += Player.yVelocity * DeltaTime;


	if (IsKeyDown(Player.left)) {
		Player.x -= Player.speed;
	}
	else if (IsKeyDown(Player.right)) {
		Player.x += Player.speed;
	}

	if (Player.x <= 0) {
		Player.x = 0;
	}
	else if (Player.x >= 900) {
		Player.x = 900;
	}


}