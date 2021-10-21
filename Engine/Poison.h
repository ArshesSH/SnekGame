#pragma once
#include "Board.h"
#include "Snake.h"
#include <random>

class Poison
{
public:
	Poison(std::mt19937 rng, const Board& brd, const Snake& snek);
	void Spawn(std::mt19937 rng, const Board& brd, const Snake& snek);
	bool CheckHasPoison(const Location& loc) const;
	void Draw(Board& brd);
private:
	Color color = { 142,0,255 };
	static constexpr int poisonDist = 10;
	static constexpr int brdWidth = 32;
	static constexpr int brdHeight = 24;
	static constexpr int poisonCount = brdHeight * brdWidth / 2;
	bool hasObstacles[brdHeight * brdWidth] = { false };
};