/*********************************************************************
** Program Filename:		space.cpp
** Author:				Morgan Brenner
** Date:					03/15/2016
** Description:			Space class implementation
*********************************************************************/
#include "space.hpp"
#include "contestant.hpp"

/*********************************************************************
** Function:				Space::Space()
** Description:			Default Constructor
*********************************************************************/
Space::Space()
{
	setName("");
	setUp(NULL);
	setDown(NULL);
	setLeft(NULL);
	setRight(NULL);

	this->c1 = NULL;
}


/*********************************************************************
** Function:				Space::Space(std::string name)
** Description:			Constructor
** Parameters:				std::string name
*********************************************************************/
Space::Space(std::string name)
{
	setName(name);
}


/*********************************************************************
** Function:				Space::~Space()
** Description:			Destructor
*********************************************************************/
Space::~Space()
{

}


/*********************************************************************
** Function:				Space::setName(std::string name)
** Description:			Mutator
** Parameters:				std::string name
*********************************************************************/
void Space::setName(std::string name)
{
	this->name = name;
}


/*********************************************************************
** Function:				Space::getName()
** Description:			Accessor
*********************************************************************/
std::string Space::getName()
{
	return this->name;
}


/*********************************************************************
** Function:				Space::setUp(Space* up)
** Description:			Mutator
** Parameters:				Space* up
*********************************************************************/
void Space::setUp(Space* up)
{
	this->up = up;
}


/*********************************************************************
** Function:				Space::setDown(Space* down)
** Description:			Mutator
** Parameters:				Space* down
*********************************************************************/
void Space::setDown(Space* down)
{
	this->down = down;
}


/*********************************************************************
** Function:				Space::setLeft(Space* left)
** Description:			Mutator
** Parameters:				Space* left
*********************************************************************/
void Space::setLeft(Space* left)
{
	this->left = left;
}


/*********************************************************************
** Function:				Space::setRight(Space* right)
** Description:			Mutator
** Parameters:				Space* right
*********************************************************************/
void Space::setRight(Space* right)
{
	this->right = right;
}


/*********************************************************************
** Function:				Space::getUp() const
** Description:			Accessor
*********************************************************************/
Space* Space::getUp() const
{
	return this->up;
}


/*********************************************************************
** Function:				Space::getDown() const
** Description:			Accessor
*********************************************************************/
Space* Space::getDown() const
{
	return this->down;
}


/*********************************************************************
** Function:				Space::getLeft() const
** Description:			Accessor
*********************************************************************/
Space* Space::getLeft() const
{
	return this->left;
}


/*********************************************************************
** Function:				Space::getRight() const
** Description:			Accessor
*********************************************************************/
Space* Space::getRight() const
{
	return this->right;
}


/*********************************************************************
** Function:				void Space::setContestant(Contestant* c1)
** Description:			Mutator
** Parameters:				Space* right
*********************************************************************/
void Space::setContestant(Contestant* c1)
{
	this->c1 = c1;
}


/*********************************************************************
** Function:				Contestant* Space::getContestant()
** Description:			Accessor
*********************************************************************/
Contestant* Space::getContestant()
{
	return c1;
}   