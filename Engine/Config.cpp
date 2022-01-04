#include "Config.h"

Config::Config()
{
	LoadConfig();
}

void Config::SaveConfig()
{
	std::ofstream out( "config.txt" );
	out << "[Tile Size]\n" << tileSize << "\n\n[Speedup Rate]\n" << speedupRate << "\n\n[Board Size]\n" << boardWidth << " " << boardHeight
		<< "\n\n[Poison Amount]\n" << nPoison << "\n\n[Goal Amount]\n" << nFood;
	out.close();
}

void Config::LoadConfig()
{
	std::ifstream in( "config.txt" );

	if ( in.is_open() )
	{
		while ( !in.eof() )
		{
			std::string str;
			std::getline( in, str );

			if ( str.compare( "[Tile Size]" ) == 0 )
			{
				std::getline( in, str );
				tileSize = std::stoi( str );
			}
			else if ( str.compare( "[Speedup Rate]" ) == 0 )
			{
				std::getline( in, str );
				speedupRate = std::stof( str );
			}
			else if ( str.compare( "[Board Size]" ) == 0 )
			{
				std::getline( in, str, ' ');
				boardWidth = std::stoi( str );
				std::getline( in, str, ' ' );
				boardHeight = std::stoi( str );
			}
			else if ( str.compare( "[Poison Amount]" ) == 0 )
			{
				std::getline( in, str );
				nPoison = std::stoi( str );
			}
			else if ( str.compare( "[Goal Amount]" ) == 0 )
			{
				std::getline( in, str );
				nFood = std::stoi( str );
			}
		}
	}
}