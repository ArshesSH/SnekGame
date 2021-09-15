#pragma once

#include "Board.h"
#include "Snake.h"
#include "Goal.h"
#include <random>

class Obstacles
{
public:
	Obstacles(std::mt19937 rnd, const Board& brd, const Snake& snek, const Goal& goal);
	void Respawn(std::mt19937 rng, const Board& brd, const Snake& snek, const Goal& goal);
	void Draw(Board& brd);
	const Location& GetLocation();
private:
	static constexpr Color c = Colors::LightGray;
	static constexpr int obstacleDist = 10;
	Location loc;
};