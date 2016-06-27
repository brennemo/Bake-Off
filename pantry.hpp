/*********************************************************************
** Program Filename:		pantry.hpp
** Author:				Morgan Brenner
** Date:					03/15/2016
** Description:			Pantry class interface
*********************************************************************/
#ifndef PANTRY_HPP
#define PANTRY_HPP

#include "space.hpp"
#include "ingredient.hpp"

class Contestant;		/*forward declaration*/

class Pantry : public Space
{
protected:
	std::vector < Ingredient* > fridge;
	Ingredient* i1;			

	std::string flavorCombo;

public:
	Pantry();
	~Pantry();

	void fillPantry();
	void displayPantry();

	void retrievePantryItem();
	void checkBasket();

	virtual void displayEntryMessage();


};

#endif