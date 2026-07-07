#pragma once
#include <iostream>

class Player {

	public:
		int x;
		int y;
		float speed;
		int gravity;
		int JumpForce;
		float yVelocity;

		int left;
		int right;
		int up;

		bool isGrounded;

};

inline Player Kumo;
inline Player Fry;

void LoadPlayers();
void MovementAndCollision(Player& Player, int GND);