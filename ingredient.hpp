/*********************************************************************
** Program Filename:		ingredient.hpp
** Author:				Morgan Brenner
** Date:					03/15/2016
** Description:			Ingredient class interface
*********************************************************************/
#ifndef INGREDIENT_HPP
#define INGREDIENT_HPP

#include <string>

class Ingredient
{
protected:
	std::string name;
	int type; 

public:
	Ingredient();
	Ingredient(std::string name, int type);
	~Ingredient();

	void setName(std::string name);
	std::string getName();
	int getType();
};

#endif