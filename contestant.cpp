/*********************************************************************
** Program Filename:		contestant.cpp
** Author:				Morgan Brenner
** Date:					03/15/2016
** Description:			Contestant class implementation
*********************************************************************/
#include "contestant.hpp"
#include "space.hpp"

/*********************************************************************
** Function:				Contestant::Contestant()
** Description:			Default Constructor
*********************************************************************/
Contestant::Contestant()
{
	setCurrentSpace(NULL);
	setName("Contestant");
}


/*********************************************************************
** Function:				Contestant::~Contestant()
** Description:			Destructor
*********************************************************************/
Contestant::~Contestant()
{
	while (ingredientBasket.size() > 0)
	{
		ingredientBasket.erase(ingredientBasket.begin());
	}
}


/*********************************************************************
** Function:				Contestant::setCurrentSpace(Space* currentSpace)
** Description:			Mutator
** Parameters:				Space* currentSpace
*********************************************************************/
void Contestant::setCurrentSpace(Space* currentSpace)
{
	this->currentSpace = currentSpace;
}


/*********************************************************************
** Function:				Contestant::getCurrentSpace()
** Description:			Accessor
*********************************************************************/
Space* Contestant::getCurrentSpace()
{
	return this->currentSpace;
}


/*********************************************************************
** Function:		void Contestant::setName(std::string name)
** Description:	mutator
** Parameters:		std::string name
*********************************************************************/
void Contestant::setName(std::string name)
{
	this->name = name;
}


/*********************************************************************
** Function:		std::string Contestant::getName()
** Description:	accessor
*********************************************************************/
std::string Contestant::getName()
{
	return this->name;
}


/*********************************************************************
** Function:		void Contestant::moveUp()
** Description:	Moves contestant up and prints previous & current
**				locations
** Post-Conditions: Contestant's location moved to location pointed to
**				by location's up pointer
*********************************************************************/
void Contestant::moveUp()
{
	std::cout << this->name << " moves up from " << currentSpace->getName() << " to ";
	setCurrentSpace(currentSpace->getUp());
	std::cout << currentSpace->getName() << "." << std::endl;
}


/*********************************************************************
** Function:		void Contestant::moveDown()
** Description:	Moves contestant down and prints previous & current
**				locations
** Post-Conditions: Contestant's location moved to location pointed to
**				by location's down pointer
*********************************************************************/
void Contestant::moveDown()
{
	std::cout << this->name << " moves down from " << currentSpace->getName() << " to ";
	setCurrentSpace(currentSpace->getDown());
	std::cout << currentSpace->getName() << "." << std::endl;
}								  


/*********************************************************************
** Function:		void Contestant::moveLeft()
** Description:	Moves contestant left and prints previous & current
**				locations
** Post-Conditions: Contestant's location moved to location pointed to
**				by location's left pointer
*********************************************************************/
void Contestant::moveLeft()
{
	std::cout << this->name << " moves left from " << currentSpace->getName() << " to ";
	setCurrentSpace(currentSpace->getLeft());
	std::cout << currentSpace->getName() << "." << std::endl;
}

/*********************************************************************
** Function:		void Contestant::moveRight()
** Description:	Moves contestant right and prints previous & current
**				locations
** Post-Conditions: Contestant's location moved to location pointed to
**				by location's right pointer
*********************************************************************/
void Contestant::moveRight()
{
	std::cout << this->name << " moves right from " << currentSpace->getName() << " to ";
	setCurrentSpace(currentSpace->getRight());
	std::cout << currentSpace->getName() << "." << std::endl;
}


/*********************************************************************
** Function:		void Contestant::addIngredient(Ingredient* i)
** Description:	pushes ptr to Ingredient to back of list
** Parameters:		Ingredient* i
*********************************************************************/
void Contestant::addIngredient(Ingredient* i)
{
	ingredientBasket.push_back(i);
}


/*********************************************************************
** Function:		void Contestant::addIngredientFront(Ingredient* i)
** Description:	pushes ptr to Ingredient to front of list
** Parameters:		Ingredient* i
*********************************************************************/
void Contestant::addIngredientFront(Ingredient* i)
{
	ingredientBasket.push_front(i);
}


/*********************************************************************
** Function:		void Contestant::removeIngredient()
** Description:	removes back of ingredientBasket list
*********************************************************************/
void Contestant::removeIngredient()
{
	if (ingredientBasket.size() == 0)
		std::cout << "There's nothing left to remove." << std::endl;

	else
		ingredientBasket.pop_back();
}


/*********************************************************************
** Function:		void Contestant::removeIngredientFront()
** Description:	removes front of ingredientBasket list
*********************************************************************/
void Contestant::removeIngredientFront()
{
	if (ingredientBasket.size() == 0)
		std::cout << "There's nothing left to remove." << std::endl;

	else
		ingredientBasket.pop_front();
}


/*********************************************************************
** Function:		bool Contestant::findIngredient(std::string s)
** Description:	Uses iterators to traverse a list & perform a 
**				linear search for Ingredients with data member
**				name = string s
** Parameters:		std::string s
*********************************************************************/

bool Contestant::findIngredient(std::string s)
{
	std::list < Ingredient* >::iterator iter;
	std::list < Ingredient* >::iterator startSearch = ingredientBasket.begin();
	std::list < Ingredient* >::iterator endSearch = ingredientBasket.end();

	/*Gaddis p. 604*/ 
	iter = startSearch;
	bool found = false;

	if (ingredientBasket.size() > 0)
	{
		while (iter != endSearch && !found)
		{
			if ((*iter)->getName() == s)
			{
				found = true;
			}
			iter++;
		}
	}

	return found;
} 


/*********************************************************************
** Function:		void Contestant::displayIngredientBasket()
** Description:	Displays names of items in ingredientBasket if
**				list has 1 or more items
*********************************************************************/
void Contestant::displayIngredientBasket()
{
	std::list < Ingredient* >::iterator iter;
	
	if (ingredientBasket.size() == 0)
	{
		std::cout << "Your ingredient basket is empty." << std::endl;
	}	
	else
	{
		std::cout << "Your Basket:" << std::endl;
		/*Gaddis Ch. 17 p. 1054*/
		for (iter = ingredientBasket.begin(); iter != ingredientBasket.end(); iter++)
		{
			std::cout << (*iter)->getName() << std::endl;
		}
	}
}


/*********************************************************************
** Function:		int Contestant::getBasketSize()
** Description:	accessor
*********************************************************************/
int Contestant::getBasketSize()
{
	return ingredientBasket.size();
}


/*********************************************************************
** Function:		Ingredient* Contestant::getFront()
** Description:	accessor
*********************************************************************/
Ingredient* Contestant::getFront()
{
	return ingredientBasket.front();
}


/*********************************************************************
** Function:		Ingredient* Contestant::getBack()
** Description:	accessor
*********************************************************************/
Ingredient* Contestant::getBack()
{
	return ingredientBasket.back();
}

