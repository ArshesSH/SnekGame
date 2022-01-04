#include "Config.h"

#include <fstream>

Config::Config( const std::string fileName )
{
	std::ifstream in( fileName );

	for ( std::string str; std::getline( in, str ); )
	{
		if ( str == "[Tile Size]" )
		{
			in >> tileSize;
		}
		else if ( str.compare( "[Speedup Rate]" ) == 0 )
		{
			in >> speedupRate;
		}
		else if ( str.compare( "[Board Size]" ) == 0 )
		{
			in >> boardWidth >> boardHeight;
		}
		else if ( str.compare( "[Poison Amount]" ) == 0 )
		{
			in >> nPoison;
		}
		else if ( str.compare( "[Goal Amount]" ) == 0 )
		{
			in >> nFood;
		}
	}


	//if ( in.is_open() )
	//{
	//	while ( !in.eof() )
	//	{
	//		std::string str;
	//		std::getline( in, str );

	//		if ( str.compare( "[Tile Size]" ) == 0 )
	//		{
	//			std::getline( in, str );
	//			tileSize = std::stoi( str );
	//		}
	//		else if ( str.compare( "[Speedup Rate]" ) == 0 )
	//		{
	//			std::getline( in, str );
	//			speedupRate = std::stof( str );
	//		}
	//		else if ( str.compare( "[Board Size]" ) == 0 )
	//		{
	//			std::getline( in, str, ' ' );
	//			boardWidth = std::stoi( str );
	//			std::getline( in, str );
	//			boardHeight = std::stoi( str );
	//		}
	//		else if ( str.compare( "[Poison Amount]" ) == 0 )
	//		{
	//			std::getline( in, str );
	//			nPoison = std::stoi( str );
	//		}
	//		else if ( str.compare( "[Goal Amount]" ) == 0 )
	//		{
	//			std::getline( in, str );
	//			nFood = std::stoi( str );
	//		}
	//	}
	//}
}

void Config::SaveConfig()
{
	std::ofstream out( "config.txt" );
	out << "[Tile Size]\n" << tileSize << "\n\n[Speedup Rate]\n" << speedupRate << "\n\n[Board Size]\n" << boardWidth << " " << boardHeight
		<< "\n\n[Poison Amount]\n" << nPoison << "\n\n[Goal Amount]\n" << nFood;
	out.close();
}