#include "Obstacles.h"

Obstacles::Obstacles(std::mt19937 rng, const Board& brd, const Snake& snek, const Goal& goal)
{
	Respawn(rng, brd, snek, goal);
}

void Obstacles::Respawn(std::mt19937 rng, const Board& brd, const Snake& snek, const Goal& goal)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetGridWidth() - obstacleDist);
	std::uniform_int_distribution<int> yDist(0, brd.GetGridHeight() - obstacleDist);

	Location newLoc;
	const Location golLoc = goal.GetLocation();

	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snek.IsInTile(newLoc) || (golLoc.x == newLoc.x && golLoc.y == newLoc.y));

	loc = newLoc;
}

void Obstacles::Draw(Board& brd)
{
	brd.DrawCell(loc, c);
}

const Location& Obstacles::GetLocation()
{
	return loc;
}

