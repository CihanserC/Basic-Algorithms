#include<stdio.h>
#include<stdlib.h>

typedef struct LINKED_STACK_NODE_s *LINKED_STACK_NODE;

typedef struct MAZE_POS_s *MAZE_POS;

typedef struct LINKED_STACK_NODE_s{

    LINKED_STACK_NODE next;
    void *data;
} LINKED_STACK_NODE_t[1];

typedef struct LINKED_STACK_s{
	LINKED_STACK_NODE head;
} LINKED_STACK_t[1] , *LINKED_STACK;

typedef struct MAZE_POS_s{
	int x;
	int y;
} MAZE_POS_t[1] , *MAZE_POS;


void *linked_stack_push(LINKED_STACK stack, void *data)
{

    LINKED_STACK_NODE node = (MAZE_POS)malloc(sizeof(MAZE_POS_t));
    if(node != NULL){
        node->data = data;
        node->next = stack->head;
        stack->head = node;
        
    } else{
   		 printf("\n Error at linked_stack_push: Can not allocate memory. \n");
    }
   

}


void *linked_stack_pop(LINKED_STACK stack)
{
    LINKED_STACK_NODE node;
    void *res=NULL;
    if(stack->head!= NULL)
    {
        node=stack->head;
        res=node->data;
        stack->head=node->next;
        free(node);
    } else{
            printf("Error at linked_stack_pop: Empty stack is popped.\n");
    }
    return res;

}



LINKED_STACK linked_stack_init()
{

    LINKED_STACK stack = (LINKED_STACK)malloc(sizeof(LINKED_STACK_t));
    stack->head=NULL;
    return stack;
}


void linked_stack_free(LINKED_STACK stack)
{
    LINKED_STACK_NODE node;
    void *res=NULL;
    while(stack->head != NULL)
	{
        
        node=stack->head;
        res=node->data;
        stack->head=node->next;
        free(node);
    }
    free(stack);
}

void *linked_stack_top(LINKED_STACK stack)
{
    LINKED_STACK_NODE node;
    void *res=NULL;
    node=stack->head;
    res=node->data;
    stack->head=node->next;
    int a=*(int *)res;
    printf("%d\n",a);
}

int linked_stack_is_empty(LINKED_STACK stack)
{
    LINKED_STACK_NODE node;
    node=stack->head;
    if(node != NULL){
        return 1;
    } else {
        return 0;
    }
    
}

