/*********************************************************************c
** Program Filename:		workSpace.hpp
** Author:				Morgan Brenner
** Date:					03/15/2016
** Description:			WorkSpace class interface
*********************************************************************/
#ifndef WORKSPACE_HPP
#define WORKSPACE_HPP

#include "space.hpp"
#include "ingredient.hpp"

class Contestant;		/*forward declaration*/

class WorkSpace : public Space
{
protected:
	std::vector < Ingredient* > oven;
	std::string cakeName;
	Ingredient* cake;

public:
	WorkSpace();
	~WorkSpace();

	void fillOven();
	void displayOven();
	void bakeCake();
	void takeCake();

	int searchOven(std::string);

	void addIngredient(Ingredient*);
	void removeIngredient();

	bool checkBasket();
	virtual void displayEntryMessage();
};

#endif