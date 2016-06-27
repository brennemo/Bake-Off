/*********************************************************************
** Program Filename:		outside.hpp
** Author:				Morgan Brenner
** Date:					03/15/2016
** Description:			Outside class interface
*********************************************************************/
#ifndef OUTSIDE_HPP
#define OUTSIDE_HPP

#include "space.hpp"

class Contestant;		/*forward declaration*/

class Outside : public Space
{

public:
	Outside();
	~Outside();

	virtual void displayEntryMessage();

};

#endif 