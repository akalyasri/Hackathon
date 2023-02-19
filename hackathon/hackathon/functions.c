#include "header.h"


int printMenu(void) {
	system("cls");

	printf("***************	  MENU	 ****************\n");
	printf("*	1.	Rules                   *\n");
	printf("*	2.	Play Game               *\n");
	printf("*	3.	Exit                    *\n");
	printf("*****************************************\n");

	int menuInput = 0;
	printf("Select an option:\n");
	scanf("%d", &menuInput);


	return menuInput;

}

//int determineChoice(int menuInput, part** pH) {
//	while (menuInput != 3) {
//
//		switch (menuInput) {
//
//		case 1:
//			//print rules
//			printRules();
//			determineChoice(printMenu(), pH);
//			break;
//		
//		case 2: //play game
//			srand(time(NULL));
//			playGame(pH);
//			determineChoice(printMenu(), pH);
//			break;
//		}
//	}
//
//	menuInput = 3;
//	if (menuInput == 3) {
//		//exit
//		exitGame();		
//		
//	}
//	
//}


void printRules(void) {
	system("cls");

	printf("*****************	RULES	 *****************\n\n");

	printf("1. In the game of Snake, the player uses the\n");
	printf("   arrow keys to move a 'snake' around the board.\n");

	printf("2. As the snake finds food, it eats the food, \n");
	printf("   and thereby grows larger.\n");

	printf("3. The game ends when the snake either moves off\n");
	printf("   the screen or moves into itself.\n");

	printf("4. The goal is to make the snake as large\n");
	printf("   as possible before that happens.\n");

	system("pause");
	system("cls");

}

int exitGame(void) {
	system("cls");
	printf("Thanks for Playing!\n\n\n");
	
	printf("designed by CHAR STARS.\n");
	
	return 0;
}


void initList(part** pH)
{
	*pH = NULL;
}

void insertHead(part** pH, int y,int x)
{
	part* newNode = (part*)malloc(sizeof(part));
	newNode->pNext = NULL;
	newNode->pPrev = NULL;
	newNode->c = 'o';
	newNode->x = x;
	newNode->y = y;

	*pH = newNode;

}

void insertEnd(part** pH, int y, int x)
{
	part* current = *pH;
	part* temp = NULL;

	while (current->pNext != NULL)
	{
		current = current->pNext;
	}


	part* newNode = (part*)malloc(sizeof(part));
	newNode->pPrev = current; // containing the address of the previos node
	newNode->pNext = NULL; // indicating it is at the end of the list
	current->pNext = newNode; // the previos node is containing the address of the "new" last node
	newNode->pNext = NULL;


	newNode->c = 'o';
	newNode->x = x;
	newNode->y = y;
	current->pNext = newNode;


}

void reID(part** pH)
{
	part* current = *pH;
	int ID = 1;
	while (current = NULL)
	{
		current->ID = ID;
		current = current->pNext;
		ID++;

	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int searchList(part** pH, int y, int x)
{
	part* current = *pH;

	while (current != NULL)
	{
		if (current->y == y && current->x == x)
		{
			return 1;
		}
		current = current->pNext;
	}
	return 0;
}

int searchApple(int appleY,int appleX,int y, int x)
{
	if (appleY == y && appleX == x)
	{
		return 1;
	}

	return 0;
}

int directionX(part** pH)
{
	part* current = *pH;
	if (current->orientation == LEFT)
	{
		return current->x + 1;

	}
	else if(current->orientation == RIGHT)
	{
		return current->x - 1;
	}
	else
	{
		return current->x;
	}
}

int directionY(part** pH)
{
	part* current = *pH;
	if (current->orientation == UP)
	{
		return current->y + 1;

	}
	else if (current->orientation == DOWN)
	{
		return current->y - 1;
	}
	else
	{
		return current->y;
	}
}

int userInput(part**pH,char t)
{
	part* current = *pH;

	if (t == 'w') //UP
	{
		current->orientation = UP;
		return UP;
	}
	else if (t == 'd') //right
	{
		current->orientation = RIGHT;
		return RIGHT;
	}
	else if (t == 's') //down
	{
		current->orientation = DOWN;
		return DOWN;
	}
	else if (t == 'a') // left
	{
		current->orientation = LEFT;
		return LEFT;
	}

}

int hitApple(part** pH,struct appleLocation *apple)
{
	part* current = *pH;
	
	if (current->y == apple->y && current->x == apple->x)
	{
		apple->x = (rand() % (9 - 0 + 1)) + 0;
		apple->y = (rand() % (9 - 0 + 1)) + 0;
		return 1;
	}
	return 0;
}

int boundCheck(part** pH,int row, int col)
{
	part* current = *pH;
	if (current->y >= 0  && current->y < row && current->x >= 0 && current->x < col)
	{
		return 0;
	}
		else
	{
		return 1;
	}


}

int followSnake(part**pH)
{
	part* current = *pH;
	part* before = *pH;

	int tempX;
	int tempY;

	static int try = 0;

	while (current->pNext != NULL)
	{
		current = current->pNext;
	}

	while (current->pPrev != NULL)
	{
		before = current->pPrev;
		current->x = before->x;
		current->y = before->y;
		current = current->pPrev;
	}



	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void snake(part** pH)
{
	int input;
	part* current = *pH;
		input = userInput(pH,_getch());
		if (input == UP)
		{
			followSnake(pH);
			current->y = current->y - 1;
		}
		else if (input == RIGHT)
		{
			followSnake(pH);
			current->x = current->x + 1;
		}
		else if (input == DOWN)
		{
			followSnake(pH);
			current->y = current->y + 1;
		}
		else if (input == LEFT)
		{
			followSnake(pH);
			current->x = current->x - 1;
		}
}

void playGame(part** pH)
{
	struct appleLocation apple;

	char boardPlayer1[10][10] = { {'\0'}, {'\0'} };

	initboard(boardPlayer1, 10, 10);
	


	int orientation = -1;

	insertHead(pH, 5, 8);

	apple.x = (rand() %(9 - 0 + 1)) + 0;
	apple.y = (rand() % (9 - 0 + 1)) + 0;

	while (boundCheck(pH, 10, 10) == 0)
	{

		system("cls");
		printboard3(pH,boardPlayer1, 10, 10,apple.y,apple.x);
		snake(pH);
		if (hitApple(pH, &apple) == 1)
		{
			insertEnd(pH, directionY(pH), directionX(pH));

		}
		followSnake(pH);
	}

}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void initboard(char board[][10], int num_rows, int num_cols) //fills the board (2d array) with ~
{
	int row_index = 0, col_index = 0;

	for (; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			board[row_index][col_index] = '~';
		}
	}
}

void printboard(char board[][10], int num_rows, int num_cols) // prints the "ocean"
{
	/*
	*   0 1 2 3
	* 0 ~ ~ b
	* 1 ~ ~ b
	*/

	int row_index = 0, col_index = 0;

	printf("%4d%3d%3d%3d%3d%3d%3d%3d%3d%3d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9); //prints the column grid numbers
	for (; row_index < num_rows; ++row_index)
	{
		printf("%d", row_index); // prints the horizonal grid numbers
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			printf("%3c", board[row_index][col_index]); // printing the ocean
		}

		putchar('\n');
	}
}


void printboard2(part **pH,char board[][10], int num_rows, int num_cols) // prints the "ocean"
{
	/*
	*   0 1 2 3
	* 0 ~ ~ b
	* 1 ~ ~ b
	*/

	int rowIndex = 0, colIndex = 0;

	printf("%4c%3c%3c%3c%3c%3c%3c%3c%3c%3c\n", '_', '_', '_', '_', '_', '_', '_', '_', '_', '_'); //prints the column grid numbers
	for (; rowIndex < num_rows; ++rowIndex)
	{
		printf("|");
		for (colIndex = 0; colIndex < num_cols; ++colIndex)
		{
			if (searchList(pH, rowIndex, colIndex) == 1)
			{
				board[rowIndex][colIndex] = 'o';
				printf("%3c", board[rowIndex][colIndex]); // printing the ocean

			}
			else
			{
				board[rowIndex][colIndex] = ' ';
				printf("%3c", board[rowIndex][colIndex]); // printing the ocean
		
			}
			
		}
		printf("%3c",'|');

		putchar('\n');
	}
	printf("%4c%3c%3c%3c%3c%3c%3c%3c%3c%3c\n", '_', '_', '_', '_', '_', '_', '_', '_', '_', '_');
}

void printboard3(part** pH, char board[][10], int num_rows, int num_cols,int appleY,int appleX) // prints the "ocean"
{
	/*
	*   0 1 2 3
	* 0 ~ ~ b
	* 1 ~ ~ b
	*/

	int rowIndex = 0, colIndex = 0;

	printf("%4c%3c%3c%3c%3c%3c%3c%3c%3c%3c\n", '_', '_', '_', '_', '_', '_', '_', '_', '_', '_'); //prints the column grid numbers
	for (; rowIndex < num_rows; ++rowIndex)
	{
		printf("|");
		for (colIndex = 0; colIndex < num_cols; ++colIndex)
		{
			
			if (searchList(pH, rowIndex, colIndex) == 1)
			{
				board[rowIndex][colIndex] = 'o';
				printf("%3c", board[rowIndex][colIndex]); // printing the ocean

			}
			else if (searchApple(appleY, appleX,rowIndex,colIndex) == 1)
			{
				board[rowIndex][colIndex] = 'x';
				printf("%3c", board[rowIndex][colIndex]);
			}
			else
			{
				board[rowIndex][colIndex] = ' ';
				printf("%3c", board[rowIndex][colIndex]); // printing the ocean

			}

		}
		printf("%3c", '|');

		putchar('\n');
	}
	printf("%4c%3c%3c%3c%3c%3c%3c%3c%3c%3c\n", '_', '_', '_', '_', '_', '_', '_', '_', '_', '_');
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////