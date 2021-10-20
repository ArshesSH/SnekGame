#pragma once
#include "Board.h"
#include "Snake.h"
#include "Goal.h"
#include "Obstacles.h"
#include <random>

class Poison
{
public:
	Poison() = default;
	Poison(const std::mt19937 rnd, const Board& brd, const Snake& snek, const Goal& goal, const Obstacles& obstacle);
private:
	Color color = { 142,0,255 };
	static constexpr int brdHeight = 32;
	static constexpr int brdWidth = 24;
	bool hasObstacles[brdHeight * brdWidth] = { false };
};