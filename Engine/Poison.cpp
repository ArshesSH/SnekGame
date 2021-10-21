#include "Poison.h"

Poison::Poison(std::mt19937 rng, const Board& brd, const Snake& snek)
{
	Spawn(rng, brd, snek);
}

void Poison::Spawn(std::mt19937 rng, const Board& brd, const Snake& snek)
{
	std::uniform_int_distribution<int> ranNum(0, 4);

	for (int y = 0; y < brdHeight - 1; y++)
	{
		for (int x = 0; x < brdWidth - 1; x++)
		{
			if (ranNum(rng) == 0)
			{
				hasObstacles[y * brdWidth + x]= true;
			}
		}
	}
}

bool Poison::CheckHasPoison(const Location& loc) const
{
	return hasObstacles[loc.y * brdWidth + loc.x];
}

void Poison::Draw(Board& brd)
{
	for (int y = 0; y < brdHeight; y++)
	{
		for (int x = 0; x < brdWidth; x++)
		{
			if (CheckHasPoison({ x, y }))
			{
				brd.DrawCell({ x, y }, color);
			}
		}
	}
}

