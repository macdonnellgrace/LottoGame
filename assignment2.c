/*
Assignment 2 - TU856/1 Sem2

Date due: 20/03/2022
Authour: Grace MacDonnell C21307546

Desc:
This is a lotto game that takes in
Option 1 - User enters 6 integers
Option 2 - Displays the numbers entered by the user
Option 3 - Runs insertion sort on numbers
Option 4 - Compares user number to winning numbers and gives a certain prize depending on amount of correct numbers
Option 5 - Displays the frequency of the numbers the user has entered
Option 6 - Exits gracefully
*/

// ----------------------
// CONSTANTS & VARIABLES

#include <stdio.h>
#include <stdlib.h>

#define SIZE 6 // size of lotto list
#define MAX 43 // max lotto number
#define MIN 1 // min. lotto number

// Function signatures
int menu(int option);
int errorCheck(int option);
int enterNum(int *);
void printNum(int[]);
int sortNum(int[]);
int compareNum(int[], int[]);
void printFreq(int *, int *);
int exitProg(char confirm);

// ----------------------
// MAIN

int main()
{
    int userNum[SIZE] = {0};
    int winningNum[SIZE] = {1, 3, 5, 7, 9, 11};
    int freqNum[MAX] = {0};

    int on = 1;        // loop
    int optionOne = 0; // used in option 1
    register int i;

    printf("\n  ~~ _________________________ ~~\n");
    printf("\n     Welcome to the C Lottery! ");
    printf("\n  ~~ _________________________ ~~\n\n");

    while (on == 1)
    {
        int userOption = 0;
        int numSame = 0;

        // Gets user input
        userOption = menu(userOption);
        errorCheck(userOption);

        // Switch cases for menu options
        switch (userOption)
        {
        // OPTION 1 -
        case 1:
        {
            numSame = enterNum(userNum);

            if (numSame == 1)
            {
                enterNum(userNum);
            }

            optionOne = 1; // tells program user has already entered values
            printf("\n~> Your lotto numbers are saved!\n");

            break;
        } // end case 1

        // OPTION 2 - Display array of numbers
        case 2:
        {
            if (optionOne != 1)
            {
                printf("~> You haven't entered your lotto numbers yet!\n");
                break;
            }
            printNum(userNum);

            break;
        } // end case 2

        // OPTION 3 - Sorts numbers into ascending order
        case 3:
        {
            if (optionOne != 1)
            {
                printf("~> You haven't entered your lotto numbers yet!\n");
                break;
            }
            sortNum(userNum);

            break;
        } // end case 3

        // OPTION 4 - PLay lotto
        case 4:
        {
            if (optionOne != 1)
            {
                printf("You haven't entered your lotto numbers yet!\n");
                break;
            }
            compareNum(userNum, winningNum);
            optionOne = 0; // resets option 1

            break;
        } // end case 4

        // OPTION 5 - Display frequency of numbers
        case 5:
        {
            if (optionOne != 1)
            {
                printf("~> You haven't entered your lotto numbers yet!\n");
                break;
            }
            printFreq(freqNum, userNum);

            break;
        } // end case 5

        // OPTION 6 - Exit
        case 6:
        {
            on = exitProg(on);
            break;
        } // end case 6

        default:
        {
            printf("\n~> Invalid option, please try again.");

            break;
        } // end default

        } // end switch

    } // end while on

    return 0;
} // end main

// ---------------------
// FUNCTIONS

// Main menu
int menu(int option)
{
    printf("\n\t~>  LOTTO MENU  <~\t\t\n");
    printf("___________________________________\n\n"); // 37
    printf("|  1. Enter your lotto numbers    |\n");
    printf("|  2. Display your numbers\t  |\n");
    printf("|  3. Sort your lotto numbers\t  |\n");
    printf("|  4. Play the lotto! \t\t  |\n");
    printf("|  5. Display frequency of        |\n");
    printf("|     numbers entered \t\t  |\n");
    printf("|  6. ... Exit lotto\t\t  |\n");
    printf("___________________________________\n\n");

    // Gets input from user
    printf("~> Option: ");

    scanf("%1d", &option);
    return option;

} // end menu

// Error Checking
int errorCheck(int option)
{
    while (1)
    // 1 isn't a character so its not seen in the getchar() scan
    // If the character after the 1 is a new line (enter) it exits the loop
    // If not it will keep asking for a menu option
    {
        if (getchar() == '\n')
        {
            break;
        }
        else
        {
            return 1;
        }
    }
} // end errorcheck

// ---------------- OPTION 1 - Enter numbers
int enterNum(int *array)
{
    register int i = 0;
    register int j = 0;
    int check;

    printf("~> Please enter your 6 lotto numbers:\n");

    // for each lotto number
    for (i = 0; i < SIZE; i++)
    {

        // input is taken from the user and checked
        scanf("%d", &*(array + i));
        check = errorCheck(*(array + i));

        // if the error check returns a true value
        if (check == 1)
        {
            printf("~> Invalid option, please try again\n");
            
            // decrements the loop to stop it continuing 
            i--; 
        } // end if check = 1

        // checks if number is within range
        if ((*(array + i) > (MAX-1)) || (*(array + i) < MIN))
        {
            printf("~> The number is not within a range of 1 - 42, try again\n");
            i--;
        } // end if MAX MIN

    } // end for

    // for every number in the lotto list
    for (i = 0; i < SIZE; i++)
    {
        // gets single number
        int current = *(array + i);

        // checks the current number against every other number in the list
        // before continuing on to the next element in the list
        for (j = 0; j < SIZE; j++)
        {
            // the number being checked against the current element
            int check = *(array + j);

            // if the number is being checked against itself in the list it ignores it
            if (i == j)
            {
                break;
            } // end if i = j

            // if a number mathces the element being checked
            else if (current == check)
            {
                printf("~> The numbers have to all be unique!\n");

                return 1;
            } // end if current = check

        } // end for j

    } // end for

} // end enterNum

// --------------- OPTION 2 - Print numbers
void printNum(int *array)
{
    register int i;

    printf("\n~> Here are your lotto numbers: \n\n");

    // prints each number in the list
    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", *(array + i));
    } // end for

    printf("\n");

} // end enterNum

// ------------- OPTION 3 - Sort numbers into ascending order
int sortNum(int *array)
{
    register int i = 0;
    register int j = 0;
    int current, next, temp = 0;

    // Uses bubble sort algorithm as data set is small
    for (i = 0; i < SIZE - 1; i++)
    {
        for (j = 0; j < SIZE - i - 1; j++)
        {
            current = *(array + j);
            next = *(array + j + 1);

            if (current > next)
            {
                // swaps elements with each other using temporary array
                temp = current;
                *(array + j) = next;
                *(array + j + 1) = temp;

            } // end if

        } // end for

    } // end for

    printf("...\n~> Your numbers have been sorted!");

} // end sortNum

// --------------- OPTION 4 - Compare user numbers to winning numbers
int compareNum(int *array1, int *array2)
{
    register int i;
    int current = 0;
    int correct = 0;

    // for every lotto number in the list
    for (i = 0; i < SIZE; i++)
    {
        current = *(array1 + i); // current lotto number

        for (i = 0; i < SIZE; i++)
        {
            if (current == *(array2 + i))
            {
                // correct counter is incremented and loop is incremented
                correct++;
                current++;

                break;
            } // end if
            else
            {
                printf("");

            } // end else

        } // end for 2

    } // end for 1

    // Lists possible prize winnings along with score
    printf("\n~> You got %d out of %d correct\n\n", correct, SIZE);
    switch (correct)
    {

    case 3:
    {
        printf("You won a cinema pass, congratulations!\n");
        break;
    } // end 3

    case 4:
    {
        printf("You won a weekend away, congratulations!\n");
        break;
    } // end 4

    case 5:
    {
        printf("You won a new car, congratulations!\n");
        break;
    } // end 5

    case 6:
    {
        printf("You won the jackpot, congratulations!\n");
        break;
    } // end 6

    default:
    {
        printf("Better luck next time!\n");
        break;
    } // end def.

    } // end switch compareNum

} // end compareNum

// ------------------------ OPTION 5 - Display num. frequency
void printFreq(int *num, int *index)
{
    register int i;

    // for i in the list
    for (i = 0; i < SIZE; i++)
    {
        // the num list uses the user's number as an index value
        // it then adds 1 to the corresponding index in the list
        // e.g. user enter's a lotto number of 5, the 5th index of the freq. list is incremented
        *(num + (*(index + i))) = *(num + (*(index + i))) + 1;

    } // end for

    printf("\n~> The frequency of the numbers you have entered are: \n\n");

    // for every possible number the user could enter
    for (i = 1; i < MAX; i++)
    {
        if (*(num + i) > 0) // if there is a value in index i
        {
            printf("The number %d has been entered %d times\n", i, *(num + i));
        } // end if

    } // end for

} // end printFreq

// --------------- OPTION 6 - Exit

int exitProg(char confirm)
{
    // Gets user input to confirm closing of program
    printf("Are you sure? y/N: ");
    scanf("%c", &confirm);

    if (confirm == 'y' || confirm == 'Y')
    {
        printf("\n   ~> Thanks for playing! <~");
        // sets the loop to 0 = false
        return 0;
    } // end if 'y'

    else
    {
        // option is ignored
        return 1;
    } // end else 'y'
}