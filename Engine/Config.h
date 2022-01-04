#pragma once
#include <fstream>
#include <string>

class Config
{
public:
	Config();
	void SaveConfig();
	void LoadConfig();
	float GetSpeedupRate()
	{
		return speedupRate;
	}
	int GetTileSize()
	{
		return tileSize;
	}
	int GetBoardWidth()
	{
		return boardWidth;
	}
	int GetBoardHeight()
	{
		return boardHeight;
	}
	int GetPoisonAmount()
	{
		return nPoison;
	}
	int GetFoodAmount()
	{
		return nFood;
	}
private:
	float speedupRate = 0.15f;
	int tileSize = 20;
	int boardWidth = 32;
	int boardHeight = 24;
	int nPoison = 240;
	int nFood = 12;
};