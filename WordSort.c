//Name: Chris Pini
//Student #: H994E783
//Assignment #: Assignment 7
//Program Name: program7
//Description: This program sorts a list of words entered by the user in alphabetical order.

#include <stdio.h>
#include <string.h>

//Constants used for our program.
#define NUM_WORDS 10
#define LENGTH 20

void sort(char words[][LENGTH], int num);

int main(void)
{
	int i;
	char input[NUM_WORDS][LENGTH];
	
	//This loop receives all the words from the user but stops when the word limit is reached or when they enter 0.
	for (i = 0; i < NUM_WORDS; i++)
	{
		printf("Enter a word: ");
		scanf("%s", input[i]);
		
		//A string compare that ends the loop when 0 is entered.
		if (strcmp(input[i], "0") == 0)
		{
			break;
		}
	}
	
	//Send our array of words into our sort function.
	sort(input, i);
	
	return 0;
}

void sort(char words[][LENGTH], int num)
{
	int i, j, min_index;
	char temp[LENGTH];
	
	//This is our selection sort, modified code from the powerpoint you showed us using strcmp and strcpy instead.
	for (i = 0; i < num - 1; i++)
	{
		min_index = i;
		
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(words[j], words[min_index]) < 0)
			{
				min_index = j;
			}
		}
		
		if (i != min_index)
		{
			strcpy(temp, words[i]);
			strcpy(words[i], words[min_index]);
			strcpy(words[min_index], temp);
		}
	}
	
	//Everything down here just prints out our results.
	printf("\nYour sorted list is: ");
	
	for (i = 0; i < num; i++)
	{
		printf("%s ", words[i]);
	}
	
	printf("\n");
}