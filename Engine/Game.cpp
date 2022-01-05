/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"
#include "Config.h"

Game::Game( MainWindow& wnd )
	:
	cfg("config.txt"),
	wnd( wnd ),
	gfx( wnd ),
	brd(gfx, cfg),
	rng(std::random_device()()),
	snek({2,2}),
	nFood(cfg.GetFoodAmount()),
	nPoison(cfg.GetPoisonAmount()),
	snekSpeedUpFactor(cfg.GetSpeedupRate())
{
	for (int i = 0; i < nPoison; i++)
	{
		brd.SpawnContents(rng, snek, Board::CellContents::Poison);
	}
	for (int i = 0; i < nFood; i++)
	{
		brd.SpawnContents(rng, snek, Board::CellContents::Food);
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();

	if (gameIsStarted)
	{
		if (!gameIsOver)
		{
			if (wnd.kbd.KeyIsPressed(VK_RIGHT) && !(delta_loc.x == -1))
			{
				delta_loc = { 1, 0 };
			}
			if (wnd.kbd.KeyIsPressed(VK_LEFT) && !(delta_loc.x == 1))
			{
				delta_loc = { -1, 0 };
			}
			if (wnd.kbd.KeyIsPressed(VK_DOWN) && !(delta_loc.y == -1))
			{
				delta_loc = { 0, 1 };
			}
			if (wnd.kbd.KeyIsPressed(VK_UP) && !(delta_loc.y == 1))
			{
				delta_loc = { 0, -1 };
			}

			float snekModifiedMovePeriod = snekMovePeriod;
			if (wnd.kbd.KeyIsPressed(VK_CONTROL))
			{
				snekModifiedMovePeriod = std::min(snekMovePeriod, snekMovePeriodSpeedup);
			}

			snekMoveCounter += dt;
			if (snekMoveCounter >= snekModifiedMovePeriod)
			{
				snekMoveCounter -= snekModifiedMovePeriod;
				const Location next = snek.GetNextHeadLocation(delta_loc);
				const Board::CellContents contents = brd.GetContents(next);
				if (!brd.IsInsideBoard(next) || snek.IsInTileExceptEnd(next) || contents == Board::CellContents::Obstacle)
				{
					gameIsOver = true;
				}
				else if(contents == Board::CellContents::Food)
				{
					snek.Grow();
					snek.MoveBy(delta_loc);
					brd.ConsumeContents(next);
					brd.SpawnContents(rng, snek, Board::CellContents::Food);
					brd.SpawnContents(rng, snek, Board::CellContents::Obstacle);
				}
				else if (contents == Board::CellContents::Poison)
				{
					snek.MoveBy(delta_loc);
					brd.ConsumeContents(next);
					brd.SpawnContents(rng, snek, Board::CellContents::Poison);
					snekMovePeriod = std::max(snekMovePeriod - snekSpeedUpFactor, snekMovePeriodMin);
				}
				else
				{
					snek.MoveBy(delta_loc);
				}
			}
		}
	}
	else
	{
		gameIsStarted = wnd.kbd.KeyIsPressed(VK_RETURN);
	}

}

void Game::ComposeFrame()
{
	if (gameIsStarted)
	{
		brd.DrawBorder();
		brd.DrawCells();
		snek.Draw(brd);
		if (gameIsOver)
		{
			SpriteCodex::DrawGameOver(350, 265, gfx);
		}
	}
	else
	{
		SpriteCodex::DrawTitle(290, 225, gfx);
	}
}
