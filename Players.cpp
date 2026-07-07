#include "Variables.h"
#include "Players.h"
#include "raylib.h"

void Player::LoadPlayers(std::string path, MapShortcut& map) {

	x = std::get<int>(map[path + ".x"]);
	y = std::get<int>(map[path + ".y"]);
	speed = std::get<float>(map[path + ".Speed"]);
	gravity = std::get<int>(map[path + ".Gravity"]);
	JumpForce = std::get<int>(map[path + ".JumpForce"]);
	left = std::get<int>(map[path + ".Controls.Left"]);
	right = std::get<int>(map[path + ".Controls.Right"]);
	up = std::get<int>(map[path + ".Controls.Up"]);

	yVelocity = 0.0f;
	isGrounded = false;

}

void Player::Reload(std::string path, MapShortcut& map) {

	speed = std::get<float>(map[path + ".Speed"]);
	gravity = std::get<int>(map[path + ".Gravity"]);
	JumpForce = std::get<int>(map[path + ".JumpForce"]);
	left = std::get<int>(map[path + ".Controls.Left"]);
	right = std::get<int>(map[path + ".Controls.Right"]);
	up = std::get<int>(map[path + ".Controls.Up"]);

}

void Player::MovementAndCollision(const Config& GameConfig) {

	float DeltaTime = GetFrameTime();

	if (y >= GameConfig.GND) {
		isGrounded = true;
		y = GameConfig.GND;
		yVelocity = 0.0f;
	}

	if (!isGrounded) {
		yVelocity += gravity * DeltaTime;

	}

	if (IsKeyPressed(up) && isGrounded) {
		yVelocity = JumpForce;
		isGrounded = false;
	}


	y += yVelocity * DeltaTime;


	if (IsKeyDown(left)) {
		x -= speed;
	}
	else if (IsKeyDown(right)) {
		x += speed;
	}

	if (x <= GameConfig.Max_X_L) {
		x = GameConfig.Max_X_L;
	}
	else if (x >= GameConfig.Max_X_R) {
		x = GameConfig.Max_X_L;
	}


}