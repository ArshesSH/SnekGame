#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Config.h"
#include <vector>
#include <random>

class Board
{
public:
	enum class CellContents
	{
		Empty,
		Obstacle,
		Food,
		Poison
	};
public:
	Board(Graphics& gfx, const Config& cfg);
	~Board();
	Board( const Board& ) = delete;
	Board& operator=( const Board& ) = delete;
	void DrawCell(const Location& loc, Color c);
	int GetGridWidth() const;
	int GetGridHeight() const;
	bool IsInsideBoard(const Location& loc) const;
	void DrawBorder();
	CellContents GetContents(const Location& loc) const;
	void ConsumeContents(const Location& loc);
	void SpawnContents(std::mt19937& rng, const class Snake& snake, CellContents contentsType);
	void DrawCells();
private:
	static constexpr Color borderColor = Colors::Blue;
	static constexpr Color obstacleColor = Colors::White;
	static constexpr Color foodColor = Colors::Red;
	static constexpr Color poisonColor = { 142,0,255 };
	int dimension;
	static constexpr int cellPadding = 1;
	int width;
	int height;
	static constexpr int borderWidth = 4;
	static constexpr int borderPadding = 2;
	static constexpr int x = 70;
	static constexpr int y = 50;
	//std::vector<CellContents> contents;
	CellContents* contents = nullptr;
	Graphics& gfx;
};