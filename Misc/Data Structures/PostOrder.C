/* Some important notes about the algo.
   In a binary tree starting from the root there always exists
   a path to reach any node.But for any particular node this
   path is unique.Each of these paths are extendible upto some
   leaf node.So if we cover every path once upto the leaf nodes we
   cover up all the nodes once .

   1>Here the leftmost path to the leaf node is covered first.
   2>Then to choose the next leftmost path upto the leaf,
     we return to that point from where this 2nd path bifercates from
	 the first path and the new path is covered from there.
   3>This process is followed until we return to root again but do
     not find a new next leftmost path.
	 So a>pushing a node means covering a path.
	    b>Poping a node means returning back.
		This way all the nodes are visited.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 20
struct node
{
	int info;
	int son;/* 0 if left son,1 if right son,-1 if root*/
	struct node *ls;/* pointer to left son */
	struct node *rs;/* pointer to right son */	
};

typedef struct node node;

void mk_tree(node *);
void push(node *stc[],node *son,int *t);
node *pop(node *stc[],int *t);
void post_ord(node *stc[],node *root,int *t);
main()
{
	node *st=NULL;/* pointer to the top of the stack */
	node *root=NULL;/* pointer to the root of the tree */
	node *new_nd=NULL;
	int val;
	node *stc[SIZE];/* this number can be increased */
	int top=-1;/* holds index of topmost element.*/
	printf("\n enter info ");
    scanf(" %d",&val);
	new_nd=malloc(1*sizeof(node));
	new_nd->info=val;
	new_nd->ls=NULL;
	new_nd->rs=NULL;
    new_nd->son=-1;

	root=new_nd;	
	mk_tree(root);	
    post_ord(stc,root,&top);
    printf("\n ");
}

/* Create the binary search tree */
void mk_tree(node *root)/* create the tree */
{
	node *new_nd=NULL;
	int val;
	do
	{
		node *p;
		node *q;
		printf("\n enter info 0 to stop ");
        scanf(" %d",&val);
        if(val==0)
			break;
        new_nd=(node *)malloc(1*sizeof(node));
		new_nd->info=val;
		new_nd->ls=NULL;
		new_nd->rs=NULL;
		new_nd->son=0;
		
		p=q=root;
		/* Reach the node where the new node will be inserted */
		while((val!=p->info)&&(q!=NULL))
		{
			p=q;
			if(val<p->info)
				q=p->ls;
			else				
				 q=p->rs;
			/* At this point q is son of p or q==NULL*/
		}
        if(val<p->info)
		{
			p->ls=new_nd;
			new_nd->son=0;
			
		}
		else
			if(val>p->info)
			{
				p->rs=new_nd;
				new_nd->son=1;
				
			}
			else
				printf("\n duplicate type another no. ");
	}while(1);
}

void push(node *stc[],node *son,int *t)
{
	if(*t<(SIZE-1))
		stc[++(*t)]=son;
	else
		printf("\n stack is full ");
}

node *pop(node *stc[],int *t)
{
	node *ret=NULL;
	if(*t!=-1)
	{
		ret=stc[(*t)--];
		return ret;
	}
	else
	{
		printf("\n stack is already empty ");
		return ret;
	}
}

/* Traverse the tree in post order  */          
void post_ord(node *stc[],node *root,int *t)
{	
	node *top=root;	
	printf("\n ");
	do
	{		
		push(stc,top,t);		
		if(top->ls!=NULL)
		{			
			top=top->ls;
			if((top->ls==NULL)&&(top->rs==NULL))
				printf(" %d",top->info);/* print left son */
			continue;
		}
		else
			if(top->rs!=NULL)
			{
				top=top->rs;
				if((top->ls==NULL)&&(top->rs==NULL))
                    printf(" %d",top->info);/* print right son */
				continue;
			}
			else
			{				
				while(*t!=-1)/* stack yet not empty */
				{
					top=pop(stc,t);
					
					if(top->son==1)/* poped element was right son*/
					{
						top=stc[*t];
                        printf(" %d",top->info);/* print root*/
						continue;
					}
					else
						if(top->son==0)/* It was left son*/
						{
							top=stc[*t];
							if(top->rs==NULL)
								printf(" %d",top->info);/* print root*/
							if(top->rs!=NULL)
							{
								top=top->rs;
								if((top->ls==NULL)&&(top->rs==NULL))
                                    printf(" %d",top->info);/* print right son */
							    break;
							}
						}
				}
			}				

	}while(*t!=-1);
}


	
    








	