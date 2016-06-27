/*********************************************************************
** Program Filename:		flavorVault.cpp
** Author:				Morgan Brenner
** Date:					03/15/2016
** Description:			Pantry class implementation
*********************************************************************/
#include "flavorVault.hpp"
#include "contestant.hpp"

/*********************************************************************
** Function:				FlavorVault::FlavorVault()
** Description:			Default Constructor
*********************************************************************/
FlavorVault::FlavorVault()
	:Space("Flavor Vault")
{
	fillFlavorVault();
	std::srand(unsigned(std::time(0)));	/*seed for random_shuffle*/
}


/*********************************************************************
** Function:				FlavorVault::~FlavorVault()
** Description:			Destructor
*********************************************************************/
FlavorVault::~FlavorVault()
{
	while (flavorVault.size() > 0)
	{
		flavorVault.erase(flavorVault.begin());
	}

	delete i1;
	delete flavors;
}


/*********************************************************************
** Function:			void FlavorVault::fillFlavorVault()
** Description:		flavorVault vector filled with 25 flavors, with
**					type key = 2, to detect later
** Post-Conditions:		25 unique Ingredient*s in flavorVault
*********************************************************************/
void FlavorVault::fillFlavorVault()
{
	i1 = new Ingredient("apple", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("apricot", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("blueberry", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("cardamom", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("cherry", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("cinnamon", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("coconut", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("coffee", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("dark chocolate", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("frangipane", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("green tea", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("lavender", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("lemon", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("marzipan", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("mint", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("orange", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("passion fruit", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("peanut butter", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("pistachio", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("raspberry", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("rhubarb", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("star anise", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("strawberry", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("thyme", 2);
	flavorVault.push_back(i1);

	i1 = new Ingredient("white chocolate", 2);
	flavorVault.push_back(i1);

}


/*********************************************************************
** Function:		void FlavorVault::displayFlavorVault()
** Description:	Displays names of front 3 flavors in vector
*********************************************************************/
void FlavorVault::display3Flavors()
{
	for (unsigned int i = 0; i < 3; i++)
	{
		std::cout << "\t" << flavorVault.at(i)->getName() << std::endl;
	}
	std::cout << std::endl;
}


/*********************************************************************
** Function:		void FlavorVault::shuffleFlavorVault()
** Description:	Shuffles order of elements in flavorVault vector
*********************************************************************/
void FlavorVault::shuffleFlavorVault()
{
	std::random_shuffle(flavorVault.begin(), flavorVault.end());
}


/*********************************************************************
** Function:		std::string FlavorVault::concatenateFlavors()
** Description:	concatenates the names of 1st 3 flavors in vector
** Post-Conditions:	concatenated string stored in flavorCombo
*********************************************************************/
std::string FlavorVault::concatenateFlavors()
{
	flavorCombo.append(flavorVault.at(0)->getName());
	flavorCombo.append(1, ',');
	flavorCombo.append(1, ' ');
	flavorCombo.append(flavorVault.at(1)->getName());
	flavorCombo.append(1, ' ');
	flavorCombo.append(1, '&');
	flavorCombo.append(1, ' ');
	flavorCombo.append(flavorVault.at(2)->getName());

	return flavorCombo;
}


/*********************************************************************
** Function:		void FlavorVault::selectFlavors()
** Description:	Displays shuffled flavors, and allows user to 
**				reshuffle them up to 3 times, and allowing them
**				to select an set of flavors at any point. 
** Post-Conditions:	flavors set and string of flavors concatenated
*********************************************************************/
void FlavorVault::selectFlavors()
{
	int count = 0;
	int choice = 0;

	std::cout << "You may shuffle the flavor combinations for your cake up to 3 times." << std::endl;

	shuffleFlavorVault();
	display3Flavors();

	std::cout << "1: Choose This Combination" << std::endl;
	std::cout << "2: Reshuffle" << std::endl;
	std::cin >> choice;

	while (count < 3 && choice == 2)
	{
		shuffleFlavorVault();
		display3Flavors();
		count++;

		if (count < 3)
		{
			std::cout << "1: Choose This Combination" << std::endl;
			std::cout << "2: Reshuffle" << std::endl;
			std::cin >> choice;
		}
	}

	std::cout << "Your flavors are set: "; 
	concatenateFlavors();
	std::cout << flavorCombo << "." << std::endl;
}


/*********************************************************************
** Function:		void FlavorVault::pushFlavors()
** Description:	dynamically allocates new Ingredient with 
**				concatenated flavors as name, and pushes to 
**				front of Contestant's ingredientBasket so that
**				it can be easily accessed apart from the other 
**				ingredients 
** Pre-Conditions:	flavors concatenated 
*********************************************************************/
void FlavorVault::pushFlavors()
{
	flavors = new Ingredient(flavorCombo, 2);
	c1->addIngredientFront(flavors);
	c1->displayIngredientBasket();
}


/*********************************************************************
** Function:			FlavorVault::displayEnterMessage()
** Description:		Runs all FlavorVault functions
** Pre-Conditions:		FlavorVault entered in Game
** Post-Conditions:		Flavors selected and new Ingredient with
**					those flavors added to Contestant's basket
*********************************************************************/
void FlavorVault::displayEntryMessage()
{
	std::cout << "You're in the flavor vault!" << std::endl << std::endl;

	/*
	** Prevents re-selection of flavors after 1st time in FlavorVault
	*/
	if (c1->getBasketSize() != 0 && c1->getFront()->getType() == 2)
	{
		std::cout << "Looks like you already chose your flavors." << std::endl;
	}
	else
	{
		selectFlavors();
		pushFlavors();	
	}
}