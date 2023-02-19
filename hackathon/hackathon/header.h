#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <string.h>
#include <time.h>
#include <stdlib.h>





 enum
{
	UP,
	RIGHT,
	DOWN,
	LEFT

};


typedef struct Part
{
	int x;
	int y;
	char c;
	int orientation;
	int ID;
	struct Part* pNext;
	struct Part* pPrev;

}part;

struct appleLocation
{
	int x;
	int y;
};


void initboard(char board[][10], int num_rows, int num_cols);
void printboard(char board[][10], int num_rows, int num_cols); // prints the "ocean"


void insertHead(part** pH, int y, int x);
void initList(part** pH);
void insertEnd(part** pH, int y, int x);

void playGame(part** pH);



int searchList(part** pH, int y, int x);
void printboard2(part** pH, char board[][10], int num_rows, int num_cols);
void printboard3(part** pH, char board[][10], int num_rows, int num_cols, int appleY, int appleX);




int printMenu(void);
int determineChoice(int menuInput, part** pH);
void printRules(void);
int exitGame(void);
