/*********************************************************************
** Program Filename:		contestant.hpp
** Author:				Morgan Brenner
** Date:					03/15/2016
** Description:			Contestant class interface
*********************************************************************/
#ifndef CONTESTANT_HPP
#define CONTESTANT_HPP

#include "ingredient.hpp"

#include <list>
#include <algorithm>

class Space;			/*forward declaration*/

class Contestant
{
protected:
	std::string name;
	Space* currentSpace;
	std::list < Ingredient* > ingredientBasket;

public:
	Contestant();
	~Contestant();

	void setCurrentSpace(Space* currentSpace);
	Space* getCurrentSpace();

	void setName(std::string name);
	std::string getName();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void addIngredient(Ingredient*);
	void addIngredientFront(Ingredient*);
	void removeIngredient();	    
	void removeIngredientFront();	    

	bool findIngredient(std::string s);
	void displayIngredientBasket();
	int getBasketSize();
	Ingredient* getFront();
	Ingredient* getBack();
};

#endif