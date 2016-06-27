/*********************************************************************
** Program Filename:		outside.cpp
** Author:				Morgan Brenner
** Date:					03/15/2016
** Description:			Outside class implementation
*********************************************************************/
#include "outside.hpp"
#include "contestant.hpp"

/*********************************************************************
** Function:				Outside::Outside()
** Description:			Default Constructor
*********************************************************************/
Outside::Outside()
	:Space("Outside")
{

}


/*********************************************************************
** Function:				Outside::~Outside()
** Description:			Destructor
*********************************************************************/
Outside::~Outside()
{

}


/*********************************************************************
** Function:				Outside::displayEnterMessage()
** Description:			Runs all Outside functions
*********************************************************************/
void Outside::displayEntryMessage()
{
	/*
	** If Contestant has award, end game. 
	*/
	if (c1->getBasketSize() == 0 || c1->getBack()->getType() != 4)
		std::cout << "Nothing out here but a couple of sheep." << std::endl << std::endl;
	else
	{
		std::cout << "Congratulations on your Bake Off victory!" << std::endl
			<< "GAME OVER" << std::endl << std::endl;
	}

}