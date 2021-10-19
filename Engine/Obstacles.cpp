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
	} while (snek.IsInTile(newLoc) || CheckHasObstacles(newLoc) || (golLoc.x == newLoc.x && golLoc.y == newLoc.y));

	hasObstacles[newLoc.y * brdWidth + newLoc.x] = true;
}

void Obstacles::Draw(Board& brd)
{
	for (int y = 0; y < brdHeight; y++)
	{
		for (int x = 0; x < brdWidth; x++)
		{
			if (CheckHasObstacles({x, y}))
			{
				brd.DrawCell({ x, y }, c);
			}
		}
	}
}

bool Obstacles::CheckHasObstacles(const Location& loc) const
{
	return hasObstacles[loc.y * brdWidth + loc.x];
}

