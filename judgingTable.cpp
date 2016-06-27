/*********************************************************************
** Program Filename:		judgingTable.cpp
** Author:				Morgan Brenner
** Date:					03/15/2016
** Description:			JudgingTable class implementation
*********************************************************************/
#include "judgingTable.hpp"
#include "contestant.hpp"


/*********************************************************************
** Function:				JudgingTable::JudgingTable()
** Description:			Default Constructor
*********************************************************************/
JudgingTable::JudgingTable()
	:Space("Judging Table")
{
	fillNpcFlavors();
	std::srand(unsigned(std::time(0)));
}


/*********************************************************************
** Function:				JudgingTable::~JudgingTable()
** Description:			Destructor
*********************************************************************/
JudgingTable::~JudgingTable()
{
	while (table.size() > 0)
	{
		table.erase(table.begin());
	}

	while (npcFlavors.size() > 0)
	{
		npcFlavors.erase(npcFlavors.begin());
	}
	
	delete cake1;
	delete cake2;
	delete i1;
}


/*********************************************************************
** Function:			void JudgingTable::fillNpcFlavors()
** Description:		npcFlavors vector filled with 10 flavors, with
**					type key = 2
** Post-Conditions:		10 unique Ingredient*s in npcFlavors
*********************************************************************/
void JudgingTable::fillNpcFlavors()
{
	i1 = new Ingredient("artichoke", 2);
	npcFlavors.push_back(i1);

	i1 = new Ingredient("bbq sauce", 2);
	npcFlavors.push_back(i1);

	i1 = new Ingredient("black pepper", 2);
	npcFlavors.push_back(i1);

	i1 = new Ingredient("durian", 2);
	npcFlavors.push_back(i1);

	i1 = new Ingredient("hops", 2);
	npcFlavors.push_back(i1);
	
	i1 = new Ingredient("horseradish", 2);
	npcFlavors.push_back(i1);

	i1 = new Ingredient("liver", 2);
	npcFlavors.push_back(i1);

	i1 = new Ingredient("marmite", 2);
	npcFlavors.push_back(i1);	

	i1 = new Ingredient("mayonnaise", 2);
	npcFlavors.push_back(i1);

	i1 = new Ingredient("soy sauce", 2);
	npcFlavors.push_back(i1);
}


/*********************************************************************
** Function:		void JudgingTable::shuffleFlavors()
** Description:	Shuffles order of elements in npcFlavors vector
*********************************************************************/
void JudgingTable::shuffleFlavors()
{
	std::random_shuffle(npcFlavors.begin(), npcFlavors.end());
}


/*********************************************************************
** Function:		std::string JudgingTable::concatenateFlavors1()
** Description:	concatenates the names of 1st 3 flavors in vector
** Post-Conditions:	concatenated string stored in flavorCombo1
*********************************************************************/
std::string JudgingTable::concatenateFlavors1()
{
	flavorCombo1.append(npcFlavors.at(0)->getName());
	flavorCombo1.append(1, ',');
	flavorCombo1.append(1, ' ');
	flavorCombo1.append(npcFlavors.at(1)->getName());
	flavorCombo1.append(1, ' ');
	flavorCombo1.append(1, '&');
	flavorCombo1.append(1, ' ');
	flavorCombo1.append(npcFlavors.at(2)->getName());
	flavorCombo1.append(1, ' ');
	flavorCombo1.append("cake");

	return flavorCombo1;
}


/*********************************************************************
** Function:		std::string JudgingTable::concatenateFlavors2()
** Description:	concatenates the names of 1st 3 flavors in vector
** Post-Conditions:	concatenated string stored in flavorCombo2
*********************************************************************/
std::string JudgingTable::concatenateFlavors2()
{
	flavorCombo2.append(npcFlavors.at(0)->getName());
	flavorCombo2.append(1, ',');
	flavorCombo2.append(1, ' ');
	flavorCombo2.append(npcFlavors.at(1)->getName());
	flavorCombo2.append(1, ' ');
	flavorCombo2.append(1, '&');
	flavorCombo2.append(1, ' ');
	flavorCombo2.append(npcFlavors.at(2)->getName());
	flavorCombo2.append(1, ' ');
	flavorCombo2.append("cake");

	return flavorCombo2;
}


/*********************************************************************
** Function:		void JudgingTable::makeNPCCakes()
** Description:	dynamically allocates memory for 2 other 
**				contestants' cakes and adds them to judges' table
*********************************************************************/
void JudgingTable::makeNPCCakes()
{
	cake1 = new Ingredient(flavorCombo1, 3);
	cake2 = new Ingredient(flavorCombo2, 3);
	table.push_back(cake1);
	table.push_back(cake2);
}


/*********************************************************************
** Function:		void JudgingTable::displayJudgingTable()		
** Description:	prints names of contestants' cakes
*********************************************************************/
void JudgingTable::displayJudgingTable()
{
	for (unsigned int i = 0; i < table.size(); i++)
	{
		std::cout << "Contestant " << i + 1 << ": \t" << table.at(i)->getName() << std::endl;
	}
	std::cout << std::endl;
}



/*********************************************************************
** Function:				JudgingTable::displayEnterMessage()
** Description:			Runs all JudgingTable functions			
** Pre-Conditions:			JudgingTable entered in Game
** Post-Conditions:			Contestant's cake replaced with award
*********************************************************************/
void JudgingTable::displayEntryMessage()
{
	/*
	** Get randomized flavor combinations and makes 
	** 2 cakes with those names
	*/
	shuffleFlavors();
	concatenateFlavors1();
	shuffleFlavors();
	concatenateFlavors2();
	makeNPCCakes();


	/*
	** Give user option to continue
	*/
	std::cout << "You're now at the judging table." << std::endl
		<< "Enter 1 to place your finished cake on upon the gingham altar." << std::endl << std::endl;
	
	int choice1;
	int choice2;

	std::cin >> choice1;
	while (choice1 != 1)
	{
		std::cout << "Enter 1 to continue." << std::endl;
		std::cin >> choice1;
	}

	/*
	** Prevent judging if user's basket does not contain a cake
	*/
	if (c1->getBasketSize() == 0 || c1->getFront()->getType() != 3)
	{
		std::cout << "Looks like you don't have a cake yet." << std::endl;
	}

	/*
	** Give user option to continue
	*/
	else if (c1->getFront()->getType() == 3)
	{
		table.push_back(c1->getFront());
		c1->removeIngredientFront();

		displayJudgingTable();
		std::cout << "You're contestant #3. Press 1 to continue to judging.";
		std::cin >> choice2;

		while (choice2 != 1)
		{
			std::cout << "Enter 1 to continue." << std::endl;
			std::cin >> choice2;
		}

		/*
		** Contestant wins game, is given award
		*/
		std::cout << "It looks like your opponents each had a bit of an off day." << std::endl
			<< "The judges have unanimously named you Star Baker! Go outside for your final interview." << std::endl;
		award = new Ingredient("star baker award", 4);
		c1->addIngredientFront(award);
		c1->displayIngredientBasket();
	}

}