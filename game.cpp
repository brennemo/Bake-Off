/*********************************************************************
** Program Filename:		game.cpp
** Author:				Morgan Brenner
** Date:					03/15/2016
** Description:			Game class implementation
*********************************************************************/
#include "game.hpp"

/*********************************************************************
** Function:				Game::Game()
** Description:			Default Constructor
*********************************************************************/
Game::Game()
{
	cols = 5;
	rows = 4;
	world.resize(rows, std::vector < Space* >(cols, NULL));
	p1 = new Contestant;
	populateWorld();
}

/*********************************************************************
** Function:				Game::~Game()
** Description:			Destructor
*********************************************************************/
Game::~Game()
{
	delete s1;
}


/*********************************************************************
** Function:		void Game::populateWorld()		
** Description:	Fills inner cells of 2D array with spaces,
**				assigns their respective 4 pointers, and sets
**				Contestant's current location to upper left space
*********************************************************************/
void Game::populateWorld()
{
	s1 = new Outside;				/*row 1*/
	world[1][1] = s1;
	world[1][1]->setContestant(p1);

	s1 = new FlavorVault;
	world[1][2] = s1;	 
	world[1][2]->setContestant(p1);

	s1 = new Pantry;
	world[1][3] = s1;
	world[1][3]->setContestant(p1);

	s1 = new Outside;				/*row 2*/
	world[2][1] = s1;
	world[2][1]->setContestant(p1);
	
	s1 = new JudgingTable;
	world[2][2] = s1;
	world[2][2]->setContestant(p1);

	s1 = new WorkSpace;
	world[2][3] = s1;
	world[2][3]->setContestant(p1);
	
	/*Assign ptrs for each direction*/
	ptSpaces(1, 1);
	ptSpaces(1, 2);
	ptSpaces(1, 3);
	ptSpaces(2, 1);
	ptSpaces(2, 2);
	ptSpaces(2, 3);

	p1->setCurrentSpace(world[1][1]);

}



/*********************************************************************
** Function:			void Game::ptSpaces(int x, int y)
** Description:		Sets up, down, left, and right pointers
**					for space at world[x][y]
** Parameters:			int x, int y
*********************************************************************/
void Game::ptSpaces(int x, int y)
{
	if (world[x - 1][y] != NULL)
		world[x][y]->setUp(world[x - 1][y]);
			
	if (world[x + 1][y] != NULL)
		world[x][y]->setDown(world[x + 1][y]);
	
	if (world[x][y - 1] != NULL)
		world[x][y]->setLeft(world[x][y - 1]);
		
	if (world[x][y + 1] != NULL)
		world[x][y]->setRight(world[x][y + 1]);		
}


/*********************************************************************
** Function:		void Game::displayWorld()
** Description:	Prints map of world with arrows to hint at 
**				direction, and an asterisk to indicate the
**				current location
*********************************************************************/
void Game::displayWorld()
{	
	std::cout << "------------------------------------------------------------" << std::endl << std::endl;
	std::cout << std::left << std::setw(10) 
		<< world[1][1]->getName();
	if (p1->getCurrentSpace() == world[1][1])					/*Display current location*/
		std::cout << "*";

	std::cout << std::left << std::setw(10)<< "   --->"
		<< std::setw(10) << world[1][2]->getName();
	if (p1->getCurrentSpace() == world[1][2])					/*Display current location*/
		std::cout << "*";

	std::cout << std::left << std::setw(10) << "   --->"
		<< std::setw(10) << world[1][3]->getName();
	if (p1->getCurrentSpace() == world[1][3])					/*Display current location*/
		std::cout << "*";
	std::cout << std::endl; 
	std::cout << std::setw(45) << std::right << "|" << std::endl;
	std::cout << std::setw(45) << std::right << "|" << std::endl;
	std::cout << std::setw(45) << std::right << "v" << std::endl;

	std::cout << std::left << std::setw(10) 
		<< world[2][1]->getName();
	if (p1->getCurrentSpace() == world[2][1])					/*Display current location*/
		std::cout << "*";
	std::cout << std::left << std::setw(10) << "   <---"
		<< std::setw(10) << world[2][2]->getName();
	if (p1->getCurrentSpace() == world[2][2])					/*Display current location*/
		std::cout << "*";
	std::cout << std::left << std::setw(10) << "   <---"
		<< std::setw(10) << world[2][3]->getName();
	if (p1->getCurrentSpace() == world[2][3])					/*Display current location*/
		std::cout << "*";
	std::cout << std::endl << std::endl;

	
	std::cout << "* = You Are Here" << std::endl;

	std::cout << "------------------------------------------------------------" << std::endl << std::endl;
}


/*********************************************************************
** Function:	void Game::goUp()
** Description: Moves contestant up if cell is not null
*********************************************************************/
void Game::goUp()
{
	if (p1->getCurrentSpace()->getUp() == NULL)
	{
		std::cout << "There's nothing up there. Try going another way." << std::endl << std::endl;
	}

	else
	{
		p1->moveUp();
		p1->getCurrentSpace()->displayEntryMessage();
	}
}


/*********************************************************************
** Function:	void Game::goDown()
** Description: Moves contestant down if cell is not null
*********************************************************************/
void Game::goDown()
{
	if (p1->getCurrentSpace()->getDown() == NULL)
	{
		std::cout << "There's nothing down there. Try going another way." << std::endl << std::endl;
	}

	else
	{
		p1->moveDown();
		p1->getCurrentSpace()->displayEntryMessage();
	}
}


/*********************************************************************
** Function:		void Game::goLeft()
** Description:	Moves contestant left if cell is not null
*********************************************************************/
void Game::goLeft()
{
	if (p1->getCurrentSpace()->getLeft() == NULL)
	{
		std::cout << "There's nothing to the left. Try going another way." << std::endl << std::endl;
	}

	else
	{
		p1->moveLeft();
		p1->getCurrentSpace()->displayEntryMessage();
	}
}


/*********************************************************************
** Function:		void Game::goRight()
** Description:	Moves contestant right if cell is not null
*********************************************************************/
void Game::goRight()
{
	if (p1->getCurrentSpace()->getRight() == NULL)
	{
		std::cout << "There's nothing to the right. Try going another way." << std::endl << std::endl;
	}

	else
	{
		p1->moveRight();
		p1->getCurrentSpace()->displayEntryMessage();
	}
}


/*********************************************************************
** Function:		void Game::moveMenu()
** Description:	Repeatedly displays map and move menu options
*********************************************************************/
void Game::moveMenu()
{
	int choice;
	
	do
	{
		displayWorld();
	
		/* Display menu choices*/
		std::cout << "1: Move Up" << std::endl;
		std::cout << "2: Move Down" << std::endl;
		std::cout << "3: Move Left" << std::endl;
		std::cout << "4: Move Right" << std::endl;
		std::cout << "5: Quit" << std::endl;

		std::cin >> choice;
		std::cout << std::endl;

		if (choice == 1)		
			goUp();

		else if (choice == 2)	
			goDown();

		else if (choice == 3)	
			goLeft();

		else if (choice == 4)	
			goRight();

		else if (choice != 5)
		{
			std::cout << "\n Please enter 1, 2, 3 or 4. \n";
			std::cin >> choice;
		}
	} while (choice != 5);
}


/*********************************************************************
** Function:		Game::runGame() 
** Description:	Displays game instructions 
**				and runs all Game functions
*********************************************************************/
void Game::runGame() 
{
	std::cout << "Welcome to Bake Off, the game inspired by the BBC baking competition of the same name." << std::endl;
	std::cout << "You have reached the final round, and there are only 3 contestants left, including yourself." << std::endl;
	std::cout << "The final challenge is to create a 3-tiered wedding cake. " << std::endl << std::endl;
	std::cout << "Your mission:" << std::endl;
	std::cout << "\t 1.  Move to the flavor vault to get the 3 flavors for each of your tiers." << std::endl;
	std::cout << "\t 2.  Move to the pantry to get the ingredients for your cake." << std::endl;
	std::cout << "\t 3.  Take your ingredients back to your workspace, and mix and bake your cake." << std::endl;
	std::cout << "\t 4.  Take your finished cake to the judging table." << std::endl;
	std::cout << "\t 5.  Take your prize and winning cake outside to show to your friends and family." << std::endl << std::endl;
	
	moveMenu();
}