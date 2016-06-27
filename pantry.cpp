/*********************************************************************
** Program Filename:		pantry.cpp
** Author:				Morgan Brenner
** Date:					03/15/2016
** Description:			Pantry class implementation
** Input:
** Output:
*********************************************************************/
#include "pantry.hpp"
#include "contestant.hpp"

/*********************************************************************
** Function:				Pantry::Pantry()
** Description:			Default Constructor
*********************************************************************/
Pantry::Pantry()
	:Space("Pantry")
{
	fillPantry();
}


/*********************************************************************
** Function:				Pantry::~Pantry()
** Description:			Destructor
*********************************************************************/
Pantry::~Pantry()
{
	while (fridge.size() > 0)
	{
		fridge.erase(fridge.begin());
	}

	delete i1;
}


/*********************************************************************
** Function:				Pantry::populatePantry()
** Description:			Adds 4 Ingredients to fridge
*********************************************************************/
void Pantry::fillPantry()
{
	i1 = new Ingredient("flour", 1);
	fridge.push_back(i1);

	i1 = new Ingredient("eggs", 1);
	fridge.push_back(i1);

	i1 = new Ingredient("butter", 1);
	fridge.push_back(i1);

	i1 = new Ingredient("sugar", 1);
	fridge.push_back(i1);
}


/*********************************************************************
** Function:				Pantry::displayPantry()
** Description:			Displays names of Ingredients in fridge
**						if fridge is not empty
*********************************************************************/
void Pantry::displayPantry()
{
	if (fridge.size() == 0)
		std::cout << "The pantry and fridge are empty." << std::endl;
	else
	{
		std::cout << "Pantry & Fridge:" << std::endl; 
		for (unsigned int i = 0; i < fridge.size(); i++)
		{
			std::cout << "\t" << i + 1 << ". " << fridge.at(i)->getName() << std::endl;
		}
	}
	
	std::cout << std::endl;
}


/*********************************************************************
** Function:		void Pantry::retrievePantryItem()
** Description:	Provides user option of order in which to retrieve
**				items, and has them add them to their basket until
**				the fridge is empty
*********************************************************************/
void Pantry::retrievePantryItem()
{
	unsigned int n; 
	std::cout << "Enter the number of the item you wish to retrieve."; 
	std::cin >> n;
	
	while (n > fridge.size())
	{
		std::cout << "The number you entered is too large." << std::endl
			<< "Enter one of the numbers above.";
		std::cin >> n; 
	}

	getContestant()->addIngredient(fridge.at(n - 1));		/*add to contestant's basket*/
	fridge.erase(fridge.begin()+ (n - 1));				/*remove from fridge*/
	displayPantry();

}


/*********************************************************************
** Function:		void Pantry::checkBasket()
** Description:	Searches ingredientBasket for all 4 ingredients
**				required to proceed & displays whether all are
**				found or not
*********************************************************************/
void Pantry::checkBasket()
{
	if ((c1->findIngredient("flour") == true) && (c1->findIngredient("eggs") == true) && (c1->findIngredient("butter") == true) && (c1->findIngredient("sugar") == true))
	{
		std::cout << "You have all of the ingredients you need. " << std::endl 
			<< "Take your supplies to your workspace." << std::endl;
	}
}


/*********************************************************************
** Function:				void Pantry::displayEntryMessage()
** Description:			Runs all Pantry functions
** Pre-Conditions:			Pantry entered in Game
** Post-Conditions:			4 ingredients retrieved from pantry
*********************************************************************/
void Pantry::displayEntryMessage()
{
	std::cout << "You're in the pantry!" << std::endl << std::endl
		<< "Enter 1 to get your ingredients." << std::endl << std::endl;
	int choice;
	std::cin >> choice;
	while (choice != 1)
	{
		std::cout << "Enter 1 to continue." << std::endl;
		std::cin >> choice;
	}

	if (fridge.size() > 0)
	{
		displayPantry();
		for (int i = 0; i < 4; i++)
			retrievePantryItem();
	}
	else
	{
		std::cout << "You must have gotten everything from the pantry already." << std::endl;
	}

	checkBasket();
}