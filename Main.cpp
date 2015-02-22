// Game.cpp : Defines the entry point for the console application.
// I decided to take a slightly different approach to this CourseWork, didn't go too over the top
// Developed By Allan. J Moore 21017984 - Bucks New Uni - Games Dev - CW3
// This is the secound time I wrote this(after HDD died) sorry if it gets sloppy. 

#include "stdafx.h"
#include "Game.h"

//Main Entry point for the application 
/*
*	Creates an object game to act as centeral point for application 
*	Game Loop Calls Update and Render Methods/ Memeber Functions 
*/
int _tmain(int argc, _TCHAR* argv[])
{
	std::cout<<"============================="<<std::endl;
	std::cout<<"Developed by Allan Moore     "<<std::endl;
	std::cout<<"21017984 Bucks new Uni       "<<std::endl;
	std::cout<<"CW3 - PathFinding 'Game'     "<<std::endl;
	std::cout<<"============================="<<std::endl;
	//Create Game Object -> On ye Old heap. 
	Game* game = new Game(); 

	//load game 
	game->load(); 
	game->initialise(); 

	//Set is running to true
	game->isRunning = true;

	//Main Game Loop. 
	while (game->isRunning){
		game->update();
		game->render(); 
	}

	//unload game
	game->unload(); 

	delete game; 
	game = nullptr; 
	//Finish.

	std::cout<<std::endl; 
	std::cout<<"Close Enough"<<std::endl;
	system("PAUSE");

	return 0;
}

