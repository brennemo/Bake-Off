/*********************************************************************
** Program Filename:		flavorVault.hpp
** Author:				Morgan Brenner
** Date:					03/15/2016
** Description:			Pantry class interface
*********************************************************************/
#ifndef FLAVORVAULT_HPP
#define FLAVORVAULT_HPP

#include "space.hpp"
#include "ingredient.hpp"

class Contestant;

class FlavorVault: public Space
{
protected:
	std::vector < Ingredient* > flavorVault;
	Ingredient* i1;				/*placeholder variable*/
	std::string flavorCombo;
	Ingredient* flavors;

public:
	FlavorVault();
	~FlavorVault();

	void fillFlavorVault();
	void display3Flavors();

	void shuffleFlavorVault();
	std::string concatenateFlavors();

	void selectFlavors();
	void pushFlavors();

	virtual void displayEntryMessage();
};

#endif