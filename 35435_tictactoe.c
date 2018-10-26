#include <stdio.h>
#include <conio.h>

//initiliaze variables
char square [10] = {'0','1','2','3','4','5','6','7','8','9'}; // array
int player = 1, i, choice,menu; 
char mark, again;

void playagain();
void back();

void board() // papan permainan
{
    system ("cls");
    printf ("\n\n\tTic Tac Toe\n\n");

    printf ("Player 1 (X) - Player 2 (O)\n\n\n");

    printf ("\t     |     |     \n");
    printf ("\t  %c  |  %c  |  %c \n", square[1],square[2],square[3]);
    printf ("\t_____|_____|_____\n");
    printf ("\t     |     |     \n");
    printf ("\t  %c  |  %c  |  %c \n", square[4],square[5],square[6]);
    printf ("\t_____|_____|_____\n");
    printf ("\t     |     |     \n");
    printf ("\t  %c  |  %c  |  %c \n", square[7],square[8],square[9]);
    printf ("\t     |     |     \n\n");

}
int wincondition() // fungsi untuk kondisi menang
{
    if (square[1] == square[2] && square [2] == square [3])
        return 1;
    else if (square[4] == square[5] && square [5] == square [6])
        return 1;
    else if (square[7] == square[8] && square [8] == square [9])
        return 1;
    else if (square[1] == square[4] && square [4] == square [7])
        return 1;
    else if (square[2] == square[5] && square [5] == square [8])
        return 1;
    else if (square[3] == square[6] && square [6] == square [9])
        return 1;
    else if (square[1] == square[5] && square [5] == square [9])
        return 1;
    else if (square[3] == square[5] && square [5] == square [7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}
int getinput () // fungsi input permainan
{
    do
    {
        board();
        player = (player % 2) ? 1 : 2;
        printf("Player %d, enter a number : ", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O';
        if (choice == 1 && square [1] == '1')
            square[1] = mark;
        else if (choice == 2 && square [2] == '2')
            square[2] = mark;
        else if (choice == 3 && square [3] == '3')
            square[3] = mark;
        else if (choice == 4 && square [4] == '4')
            square[4] = mark;
        else if (choice == 5 && square [5] == '5')
            square[5] = mark;
        else if (choice == 6 && square [6] == '6')
            square[6] = mark;
        else if (choice == 7 && square [7] == '7')
            square[7] = mark;
        else if (choice == 8 && square [8] == '8')
            square[8] = mark;
        else if (choice == 9 && square [9] == '9')
            square[9] = mark;
        else
        {
            printf ("Invalid move ");
            player--;
            getchar();
        }
        i = wincondition();

        player ++;
    }
    while (i == -1);
    board();
    if (i==1)
   	{
		printf ("===>\aPlayer %d win!!", --player);
        playagain();
    }
    else
    {
    	printf ("===>\aGame draw");
    getch();
	}
        

    return 0;
}
int RESET () // fungsi untuk me reset kembali papan permainan ketika sudah selsai bermain
{
  if (square [1] != '1')
    square [1]= '1';
  if (square [2] != '2')
    square [2] = '2';
  if (square [3] != '3')
    square [3] = '3';
  if (square [4] != '4')
    square [4] = '4';
  if (square [5] != '5')
    square [5] = '5';
  if (square [6] != '6')
    square [6] = '6';
  if (square [7] != '7')
    square [7] = '7';
  if (square [8] != '8')
    square [8] = '8';
  if (square [9] != '9')
    square [9] = '9';
}

void playagain ()// fungsi yang akan menanyakan user unutk bermain lagi atau keluar dari permainan
	{
		 printf ("\n\n Wanna Play Again!! (y/n)) ");
        scanf ("%s", &again);
        if (again == 'y'||again == 'Y')
        {
        	RESET();
        	getinput();
		}
		else if (again == 'n'||again == 'N')
		{
			out();
		}
	}

void back()
{
	printf("Press 1 to back to menu! ");
	scanf("%s", &again);
	if (again == '1')
	{
		system("cls");
		main();
	} 

}
	

void out ()
{
	return 0;
}

int main ()
{	
	int menu;
	printf("\t\t\tWELCOME TO TIC TAC TOE!\n\n");
	printf("Choose The Menu: \n\n");
	printf("[1]. Play The Game!\n");
	printf("[2]. How To Play\n");
	printf("[3]. Exit\n\n");
	printf("Your Choice: ");
	scanf ("%d", &menu);
	system("cls");
	if	(menu==1)
	{
		getinput();
		RESET();
	} 
	if (menu==2)
	{
		printf("\t\tHow To Play\n\n");
		printf("[1]. Press menu number 1 to play the game\n\n");
		printf("[2]. Now you and your friend become player 1 and player 2\n\n");
		printf("[3]. Player 1 symbol is 'X' and player 2 symbol is 'O'\n\n");
		printf("[4]. Choose number from 1-9 until your symbol become a row to win the game\n\n");
		printf("[5]. After won a game the system will ask you to play again or not\n\n");
		printf("[6]. Press Enter to choose the option. 'y' is for yes to play again or you can choose 'n' for no to quit the game\n\n");
		back();
	}
	if (menu==3)
	{
		return 0;
	}
	else
	{
		printf("Error Input\n");
		system("PAUSE");
		system("cls");
		return main();
	}
    return 0;
}
