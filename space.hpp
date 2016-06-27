/*********************************************************************
** Program Filename:		space.hpp
** Author:				Morgan Brenner
** Date:					03/15/2016
** Description:			Space class interface
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>  
#include <string>
#include <vector>
#include <list>

class Contestant;			/*forward declaration*/

class Space
{
protected:
	std::string name;

	Space* up;
	Space* down;
	Space* left;
	Space* right;

	Contestant* c1;

public:

	Space();
	Space(std::string);
	~Space();

	void setName(std::string name);
	std::string getName();

	void setUp(Space* up);
	void setDown(Space* down);
	void setLeft(Space* left);
	void setRight(Space* right);

	Space* getUp() const;
	Space* getDown() const;
	Space* getLeft() const;
	Space* getRight() const;

	void setContestant(Contestant*);
	Contestant* getContestant();

	virtual void displayEntryMessage() = 0;
};


#endif