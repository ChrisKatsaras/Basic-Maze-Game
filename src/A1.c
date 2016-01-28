/*                              A1.c
Student Name: Christopher Katsaras                        Student Number:  0795555
Date: January 24th/14                                     Course Name: CIS*2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/




#include <stdio.h>         /*Included the necessary libraries*/
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void printMaze(WINDOW *mazeArea);

struct location
{
    int y; 
    int x; 

};


struct location initial;                  
struct location ending;


int maze[20][40] = {
	{1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, /*arrays for maze are set up*/
	{1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,1},
	{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,1},
	{1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,1},
	{1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,1,1,1},
	{1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,0,0,0,1,1,1},
	{1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1},
	{1,0,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1},
	{1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};




int main()
{
	WINDOW *gameArea;
	int quitInt = 0;
	initial.x = 2;
	initial.y = 0;
    initscr ();
    noecho (); 
    cbreak ();
    gameArea = newwin(20, 40, 2, 20); /*Dimensions/ position of maze*/
    keypad(gameArea, TRUE);
    ending.x = 14;
    ending.y = 19;
    printMaze(gameArea); 
    wmove(gameArea, 0,2);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    wbkgd(gameArea, COLOR_PAIR(1));
    refresh ();
    
     
        


       
    do 
    {
        int direction = wgetch (gameArea); /*using if and else statements for movement based on key input*/
        
        if(direction == 'i') 
        {
			if (maze[initial.y-1][initial.x] == 0)
			{
				initial.y--;
			}

        }  
        else if(direction == 'k')
        {
			if (maze[initial.y+1][initial.x] == 0)
			{
				initial.y++;
			}
	    }
	    else if(direction == 'j')
	    {
			if (maze[initial.y][initial.x-1] == 0)
			{
				initial.x--;
			}
	    }
	    else if(direction == 'l')
	    {
			if (maze[initial.y][initial.x+1] == 0)
			{
				initial.x++;	
			}
	    }    
        else if(direction == 'q')
        {
			quitInt = 1;
	    }
	    wmove(gameArea, initial.y, initial.x);
	    wrefresh(gameArea);
    
    }while(((initial.x != 13) || (initial.y != 19))&& quitInt != 1);
    endwin();
    return(0);  
}
 
void printMaze(WINDOW *mazeArea) /* Function to print the maze*/
{
	int p;
	int o;
	
	for(p=0;p<40;p++)
	{
		for(o=0;o<20;o++)
		{
			if (maze[o][p] ==1)
			{
				mvwaddch(mazeArea, o, p, ACS_DIAMOND);
			}
			else
			{
				mvwaddch(mazeArea, o, p, ' ');
			}
	    }
    }
	
}
