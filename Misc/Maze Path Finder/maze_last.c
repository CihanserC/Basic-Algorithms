#include<stdio.h>
#include<stdlib.h>
#include"maze_functions.h"

int main()
{

	LINKED_STACK_t stack;
	MAZE_POS node = (MAZE_POS)malloc(sizeof(MAZE_POS_t));

	int x;
	int y;
	
    int maze[8][8] = {
        {0,0,0,1,0,0,0,0},
        {0,1,1,1,0,0,1,0},
        {0,1,0,1,0,0,1,0},
        {0,1,0,1,1,1,1,0},
        {0,1,0,0,0,0,1,1},
        {0,1,1,0,1,1,1,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0}};
        
	y=3;
	x=0;
	node->y=y;
	node->x=x;
	
	linked_stack_push(stack,node);
	
	
	while(x!=7 && y!=7)
	{
		
	
		if(maze[x+1][y]==1)
		{
			maze[x][y]=2;
			x=x+1;
			node->x=x;
			node->y=y;
			
			printf("Node : %d - Coordinates : (%d,%d)\n",maze[x][y],x,y);
			linked_stack_push(stack,node);
			
		}else if(maze[x][y+1]==1)
		{
			maze[x][y]=2;
			y=y+1;
			node->x=x;
			node->y=y;
			printf("Node : %d - Coordinates : (%d,%d)\n",maze[x][y],x,y);
			linked_stack_push(stack,node);
			
		}else if(maze[x][y-1]==1) 
		{
			maze[x][y]=2;
			y=y-1;
			node->x=x;
			node->y=y;
			printf("Node : %d - Coordinates : (%d,%d)\n",maze[x][y],x,y);
			linked_stack_push(stack,node);
			
		}else if(maze[x-1][y]==1)
		{
			maze[x][y]=2;
			x=x-1;
			node->x=x;
			node->y=y;
			printf("Node : %d - Coordinates : (%d,%d)\n",maze[x][y],x,y);
			linked_stack_push(stack,node);
			
		}
		
	} 
	
	printf("\n\n\n You escaped from maze !!!");
	linked_stack_free(stack);

}

