/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  console
 *
 *        Version:  1.0
 *        Created:  2014年10月27日 09时02分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  keetle
 *   Organization:  
 *
 * =====================================================================================
 */



#include	<stdlib.h>
#include	<stdio.h>

char *menu[] = {
	"a - add new record",
	"d - delete record",
	"q - quit",
	NULL,
};

int getchoice(char *greet, char *choices[]);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
	int choice = 0;
	do
	{
		choice = getchoice("please select an action", menu);
		if(choice != 'q')
		{
			printf("You have choice: %c\n", choice);
		}
	}while(choice != 'q');
	printf("Program will exit right now!\n");
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

int getchoice(char *greet, char *choices[])
{
	int chosen = 0;
	int selected;
	char **option;

	do
	{
		printf("choice: %s\n", greet);
		option = choices;
		while(*option)
		{
			printf("%s\n", *option);
			option++;
		}
		//selected = getchar();
		
		do
		{	
			printf("console>>");
			selected = getchar();
		}while(selected == '\n');
		
		option = choices;
		while(*option)
		{
			if(selected == *option[0])
			{
				chosen = 1;
				break;
			}
			option++;
		}
		if(!chosen)
		{
			printf("Incorrect choice, select again\n");
		}
	}while(!chosen);
	return selected;
}
