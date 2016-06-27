/*********************************************************************
** Program Filename:		workSpace.cpp
** Author:				Morgan Brenner
** Date:					03/15/2016
** Description:			WorkSpace class implementation
** Input:
** Output:
*********************************************************************/
#include "workSpace.hpp"
#include "contestant.hpp"

/*********************************************************************
** Function:		WorkSpace::WorkSpace()
** Description:	Constructor
*********************************************************************/
WorkSpace::WorkSpace()
	:Space("Workspace")
{
	cakeName = "";
}


/*********************************************************************
** Function:		WorkSpace::~WorkSpace()
** Description:	Destructor 
*********************************************************************/
WorkSpace::~WorkSpace()
{
	while (oven.size() > 0)
	{
		oven.erase(oven.begin());
	}

	delete cake; 
}


/*********************************************************************
** Function:		void WorkSpace::fillOven()
** Description:	Adds ingredients of type 1 (flour, sugar, butter, 
**				& eggs), which are at the back of Contestant's
**				ingrwedientBasket, to oven, while removing them
**				from basket
*********************************************************************/
void WorkSpace::fillOven()
{
	while (c1->getBasketSize() != 0 && c1->getBack()->getType() == 1)
	{
		oven.push_back(c1->getBack());
		c1->removeIngredient();
	}			   
}


/*********************************************************************
** Function:		void WorkSpace::displayOven()		
** Description:	Displays the names of Ingredients in oven
*********************************************************************/
void WorkSpace::displayOven()
{
	if (oven.size() == 0)
	{
		std::cout << "The oven is empty." << std::endl;
	}
	else
	{
		for (unsigned int i = 0; i < oven.size(); i++)
		{
			std::cout << oven.at(i)->getName() << " ";
		}
	}
	std::cout << std::endl;
}


/*********************************************************************
** Function:		int WorkSpace::searchOven(std::string s)
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int WorkSpace::searchOven(std::string s)
{
	//Gaddis p. 604
	unsigned int index = 0;
	int position = -1;
	bool found = false;

	while (index < oven.size() && !found)
	{
		if (oven.at(index)->getName() == s)
		{
			found = true;
			position = index;
		}
		index++;
	}
	return position; 
}


/*********************************************************************
** Function:		void WorkSpace::bakeCake()
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void WorkSpace::bakeCake()
{
	while (oven.size() > 0)
	{
		removeIngredient();
	}

	if (c1->getBasketSize() != 0 && c1->getFront()->getType() == 2)
	{
		cakeName.append(c1->getFront()->getName());
		cakeName.append(1, ' ');
		cakeName.append("cake");
	}
	else
	{
		cakeName = "cake";
	}

	cake = new Ingredient(cakeName, 3);
	addIngredient(cake);
								 
	/*
	** Remove the "flavor" ingredient
	*/
	if (c1->getBasketSize() != 0 && c1->getFront()->getType() == 2)
	{
		c1->removeIngredientFront();
	}
}


/*********************************************************************
** Function:		void WorkSpace::takeCake()
** Description:	Adds finished cake to Contestant's basket
** Pre-Conditions:	front item in oven is type 3, i.e. a cake
*********************************************************************/
void WorkSpace::takeCake()
{
	if (oven.front()->getType() == 3)
	{
		c1->addIngredient(oven.front());
		c1->displayIngredientBasket();
	}
	else
	{
		std::cout << "The cake isn't in the oven." << std::endl;
	}
	
}


/*********************************************************************
** Function:		void WorkSpace::addIngredient(Ingredient* i)
** Description:	Adds Ingredient* to end of oven vector
** Parameters:		Ingredient* i
*********************************************************************/
void WorkSpace::addIngredient(Ingredient* i)
{
	oven.push_back(i);
}


/*********************************************************************
** Function:		void WorkSpace::removeIngredient()
** Description:	Removes last item from oven vector 
*********************************************************************/
void WorkSpace::removeIngredient()
{
	if (oven.size() == 0)
		std::cout << "There's nothing left to remove." << std::endl;

	else
		oven.pop_back();
}


/*********************************************************************
** Function:			bool WorkSpace::checkBasket()
** Description:		Checks if flavors & 4 ingredients are in basket,
**					and displays message for 1st missing ingredient
**					encountered; otherwise tells user to proceed
*********************************************************************/
bool WorkSpace::checkBasket()
{
	if (c1->getBasketSize() > 0)
	{
		if (c1->getFront()->getType() != 2)
		{
			std::cout << "You still need to pick your flavors." << std::endl
				<< "Go back to the pantry, and come back when you have them." << std::endl;
			return false;
		}
	

		if (c1->findIngredient("flour") == false)
		{
			std::cout << "You still need to get flour." << std::endl
				<< "Go back to the pantry, and come back when you have it." << std::endl; 
			return false;
		}


		if (c1->findIngredient("butter") == false)
		{
			std::cout << "You still need to get butter." << std::endl
				<< "Go back to the pantry, and come back when you have it." << std::endl;
			return false;
		}


		if (c1->findIngredient("sugar") == false)
		{
			std::cout << "You still need to get sugar." << std::endl
				<< "Go back to the pantry, and come back when you have it." << std::endl;
			return false;
		}


		if (c1->findIngredient("eggs") == false)
		{
			std::cout << "You still need to get eggs." << std::endl
				<< "Go back to the pantry, and come back when you have it." << std::endl;
			return false;
		}


		else
		{
			std::cout << "You have all of the ingredients you need." << std::endl;
			std::cout << "Put the mixed ingredients into the oven." << std::endl << std::endl; 
			return true;
		}
	}
	else
	{
		std::cout << "Your basket is empty." << std::endl
			<< "Go back to the pantry, and come back when you have your ingredients." << std::endl;
		return false;
	}

}


/*********************************************************************
** Function:		void WorkSpace::displayEntryMessage()			
** Description:	Fills oven with ingredients, and replaces them
**				with a cake; adds to Contestant's basket  
** Pre-Conditions:	WorkSpace entered in Game
*********************************************************************/
void WorkSpace::displayEntryMessage()
{
	if (checkBasket() == true)		/*make sure all 4 ingredients are in basket*/
	{
		std::cout << "You're now at your workspace." << std::endl
			<< "Enter 1 to use the mixer and oven to bake your cake." << std::endl << std::endl;
		int choice;
		std::cin >> choice;
		while (choice != 1)
		{
			std::cout << "Enter 1 to continue." << std::endl;
			std::cin >> choice;
		}

		fillOven();
		bakeCake(); 
		takeCake();
	}
}

