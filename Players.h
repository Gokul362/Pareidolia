#pragma once
#include "Variables.h"
#include "Config.h"


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


		void LoadPlayers(std::string path, MapShortcut& map = PairsMap);
		void Reload(std::string path, MapShortcut& map = PairsMap);
		void MovementAndCollision(const Config& GameConfig);

};