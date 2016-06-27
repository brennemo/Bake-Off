/*********************************************************************
** Program Filename:		game.hpp
** Author:				Morgan Brenner
** Date:					03/15/2016
** Description:			Game class interface
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "space.hpp"
#include "pantry.hpp"
#include "flavorVault.hpp"
#include "outside.hpp"
#include "workSpace.hpp"
#include "judgingTable.hpp"
#include "contestant.hpp"

#include <iostream>
#include <iomanip>
#include <list>

class Game
{
protected:
	std::vector <std::vector < Space*> > world;
	Space* s1;					//dummy variable 

	int cols;
	int rows;
	Contestant* p1;

public:
	Game();
	~Game();
	void populateWorld();

	void displayWorld();

	void ptSpaces(int x, int y);

	void goUp();
	void goDown();
	void goLeft();
	void goRight();

	void moveMenu();
	void runGame();
};


#endif