/*********************************************************************
** Program Filename:		judgingTable.hpp
** Author:				Morgan Brenner
** Date:					03/15/2016
** Description:			JudgingTable class interface
*********************************************************************/
#ifndef JUDGINGTABLE_HPP
#define JUDGINGTABLE_HPP

#include "space.hpp"
#include "ingredient.hpp"

class Contestant;
class Game;

class JudgingTable : public Space
{
protected:
	std::vector < Ingredient* > table;
	std::vector < Ingredient* > npcFlavors;
	Ingredient* i1;
	Ingredient* cake1;
	Ingredient* cake2;
	Ingredient* award; 
	std::string flavorCombo1;
	std::string flavorCombo2;

public:
	JudgingTable();
	~JudgingTable();

	void makeNPCCakes(); 
	void fillNpcFlavors();
	void shuffleFlavors();
	std::string concatenateFlavors1();
	std::string concatenateFlavors2();
	
	void displayJudgingTable();
	virtual void displayEntryMessage();
};

#endif