/*********************************************************************
** Program Filename:		ingredient.cpp
** Author:				Morgan Brenner
** Date:					03/15/2016
** Description:			Ingredient class implementation
*********************************************************************/
#include "ingredient.hpp"

/*********************************************************************
** Function:				Ingredient::Ingredient()
** Description:			Default Constructor
*********************************************************************/
Ingredient::Ingredient()
{
	setName("");
	this->type = 0;
}


/*********************************************************************
** Function:				Ingredient::Ingredient(std::string name)
** Description:			Constructor
** Parameters:				std::string name
*********************************************************************/
Ingredient::Ingredient(std::string name, int type)
{
	setName(name);
	this->type = type;
}


/*********************************************************************
** Function:				Ingredient::~Ingredient()
** Description:			Destructor
*********************************************************************/
Ingredient::~Ingredient()
{

}


/*********************************************************************
** Function:				Ingredient::setName(std::string name)
** Description:			Mutator
** Parameters:				std::string name
*********************************************************************/
void Ingredient::setName(std::string name)
{
	this->name = name;
}


/*********************************************************************
** Function:				Ingredient::getName()
** Description:			Accessor
*********************************************************************/
std::string Ingredient::getName()
{
	return this->name;
}


int Ingredient::getType()
{
	return this->type;
}