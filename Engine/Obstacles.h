#pragma once

#include "Board.h"
#include "Snake.h"
#include "Goal.h"
#include <random>

class Obstacles
{
public:
	Obstacles() = default;
	Obstacles(std::mt19937 rnd, const Board& brd, const Snake& snek, const Goal& goal);
	void Respawn(std::mt19937 rng, const Board& brd, const Snake& snek, const Goal& goal);
	void Draw(Board& brd);
	bool CheckHasObstacles(const Location& loc) const;
private:
	static constexpr Color c = Colors::LightGray;
	static constexpr int obstacleDist = 10;
	// board height & width from board.h
	static constexpr int brdHeight = 32;
	static constexpr int brdWidth = 24;
	bool hasObstacles[brdHeight * brdWidth] = { false };
};