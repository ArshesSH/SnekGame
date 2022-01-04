#pragma once

#include <string>

class Config
{
public:
	Config(const std::string fileName);
	void SaveConfig();
	float GetSpeedupRate() const
	{
		return speedupRate;
	}
	int GetTileSize() const
	{
		return tileSize;
	}
	int GetBoardWidth() const
	{
		return boardWidth;
	}
	int GetBoardHeight() const
	{
		return boardHeight;
	}
	int GetPoisonAmount() const
	{
		return nPoison;
	}
	int GetFoodAmount() const
	{
		return nFood;
	}
private:
	float speedupRate;
	int tileSize;
	int boardWidth;
	int boardHeight;
	int nPoison;
	int nFood;
};