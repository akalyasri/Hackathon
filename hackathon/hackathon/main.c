#include "header.h"


part *pHead = NULL;

int orientation = -1;


int timeout(int seconds)
{
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {}

    return  1;
}

int main()
{

   // determineChoice(printMenu(), &pHead);

    int userInput = printMenu();

    while (userInput != 3) {

        switch (userInput) {
        case 1:
            printRules();
            break;
        case 2:
            playGame(&pHead);
            break;
        }

        userInput = printMenu();

    }
    if (userInput == 3) {
        exitGame();
    }

  
   // printf("Hello");
	
}