#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct LINKED_TREE_AVL_NODE_s *LINKED_TREE_AVL_NODE;
typedef struct LINKED_TREE_AVL_NODE_s{
    LINKED_TREE_AVL_NODE right;
    LINKED_TREE_AVL_NODE left;
    int data;
    int height;
} LINKED_TREE_AVL_NODE_t[1];

typedef struct LINKED_TREE_AVL_s *LINKED_TREE_AVL;
typedef struct LINKED_TREE_AVL_s{
    LINKED_TREE_AVL_NODE root;
} LINKED_TREE_AVL_t[1];

typedef struct LINKED_STACK_NODE_s *LINKED_STACK_NODE;
typedef struct LINKED_STACK_NODE_s{
	LINKED_STACK_NODE next;
	LINKED_TREE_AVL_NODE data;
} LINKED_STACK_NODE_t[1];

typedef struct LINKED_STACK_s *LINKED_STACK;
typedef struct LINKED_STACK_s{
	LINKED_STACK_NODE head;
} LINKED_STACK_t[1];

LINKED_STACK linked_stack_init(){

	LINKED_STACK stack=(LINKED_STACK)malloc(sizeof(LINKED_STACK));
	stack->head=NULL;
	return stack;

}

void linked_stack_push(LINKED_STACK stack,LINKED_TREE_AVL_NODE data){

	LINKED_STACK_NODE node = (LINKED_STACK_NODE)malloc(sizeof(LINKED_STACK_NODE_t));

	if(node != NULL){
		node->data = data;
		node->next = stack->head;
		stack->head = node;
	}
	else{
		printf("Error @ linked_stack_push: Cannot allocate memory.\n");
	}
	printf("linked_stack_push:allocated memory.\n");
}

int node_repair(LINKED_TREE_AVL_NODE node,LINKED_TREE_AVL_NODE node1)
{

	LINKED_TREE_AVL_NODE cur = node;

	if(node->height > 0)
		{
			if(node->left->height <= -1)
			{
				node->left=left_rotation(node->left);

			}
			node=right_rotation(node);
			node->height=linked_tree_avl_height(node->left)-linked_tree_avl_height(node->right);
		}
	if(node->height < 0 )
	{
			if(node->right->height >= 1)
			{
				node->right=right_rotation(node->right);

			}
			
			node=left_rotation(node);
			node->height=linked_tree_avl_height(node->left)-linked_tree_avl_height(node->right);
	}
	if(cur!=node1)
	{

	if(node->data < node1->data)
			{

				node1->left=node;

			}
	if(node->data > node1->data)
			{

				node1->right=node;
			}
	}
	else
	{
		node1=node;
		return node;
	}

}



int left_rotation(LINKED_TREE_AVL_NODE node)
{
	LINKED_TREE_AVL_NODE gp,p,c;

	gp = node;
	p = node->right;
	c= p->left;

	p->left=gp;
	gp->right=c;
	return p;

}

int right_rotation(LINKED_TREE_AVL_NODE node)
{
	LINKED_TREE_AVL_NODE gp,p,c;

	gp = node;
	p = node->left;
	c = p->right;

	p->right = gp;
	gp->left = c;
	return p;
}


void *linked_stack_pop(LINKED_STACK stack){

	LINKED_STACK_NODE node;

	void *res = NULL;

	if(stack->head != NULL){

		node = stack->head;
		res = node->data;
		stack->head = node->next;
		free(node);
	} else{
		printf("Error @ linked_stack_pop: Empty stack is popped.\n");
	}
	printf("STACK POPED\n");
	return res;
}


LINKED_TREE_AVL linked_tree_avl_init(){
	LINKED_TREE_AVL new =(LINKED_TREE_AVL)malloc(sizeof(LINKED_TREE_AVL_t));
	new->root=NULL;
	return new;
}
LINKED_TREE_AVL_NODE linked_tree_avl_init_node(LINKED_TREE_AVL_NODE data){
	LINKED_TREE_AVL_NODE node=(LINKED_TREE_AVL_NODE)malloc(sizeof(LINKED_TREE_AVL_NODE_t));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	node->height = 0;
	return node;
}
int linked_tree_avl_height(LINKED_TREE_AVL_NODE node){

	if(node==NULL){
	   return 0;
	}
	int left_height=linked_tree_avl_height(node->left);
    int  right_height=linked_tree_avl_height(node->right);

        if(left_height>right_height)
		{
		return left_height+1;
		}
		else
		{
		return right_height+1;
		}
}

void linked_tree_insert(LINKED_TREE_AVL tree, int data,LINKED_STACK stack) {

    LINKED_TREE_AVL_NODE node = tree->root;



    if (tree->root == NULL) {
        tree->root = linked_tree_avl_init_node(data);
        linked_stack_push(stack,tree->root);

    } else {

        while (node != NULL) {
            if (data < node->data) {
                if (node->left == NULL) {
                	linked_stack_push(stack,node);
                    node->left = linked_tree_avl_init_node(data);
                    linked_stack_push(stack,node->left);
                    height_upgrade(stack,tree);
                    node = NULL;
                } else {
                	linked_stack_push(stack,node);
                    node = node->left;
                }

            } else if (data > node->data) {
                if (node->right == NULL ) {
                	linked_stack_push(stack,node);
                    node->right = linked_tree_avl_init_node(data);
                    linked_stack_push(stack,node->right);
                    height_upgrade(stack,tree);
                    node = NULL;
                } else {
                	linked_stack_push(stack,node);
                    node = node->right;
                }
            } else {
                printf("dublicate empty\n");
                node = NULL;
            }
        }
    }
}

int height_upgrade(LINKED_STACK stack,LINKED_TREE_AVL tree)
{


	LINKED_STACK_NODE node = (LINKED_STACK_NODE)malloc(sizeof(LINKED_STACK_NODE_t));

	node = stack->head;

	while(node!=NULL)
	{
		node->data->height=linked_tree_avl_height(node->data->left)-linked_tree_avl_height(node->data->right);
		if(node->data->height < -1 || node->data->height > 1 )
		{
			if(node->next!=NULL)
			{
				node_repair(node->data,node->next->data);

			}
			else
			{
				tree->root=node_repair(node->data,node->data);

			}

		}
		node = node->next;
	}
	stack->head=NULL;
}


void linked_tree_print_horizontal_recursive(LINKED_TREE_AVL_NODE node, int l) {
                if (node != NULL) {
                               linked_tree_print_horizontal_recursive(node->right, l + 1);
                               int i;
                               for (i = 0; i < l; i++) {
                                               printf("    ");
                               }
                               printf("%d", node->data);
                               printf("\n");
                               linked_tree_print_horizontal_recursive(node->left, l + 1);
                }
}

void linked_tree_print_horizontal(LINKED_TREE_AVL tree) {
                printf("\n");
                int cnt = 0;
                linked_tree_print_horizontal_recursive(tree->root, cnt);
}

int delete(LINKED_TREE_AVL tree , int data , LINKED_STACK stack)
	{
		LINKED_TREE_AVL_NODE node = tree->root;

		while(node->data!=data)
		{
			if(data < node->data)
			{

				linked_stack_push(stack,node);
				node = node->left;
			}
			if(data > node->data)
			{

				linked_stack_push(stack,node);
				node = node->right;
			}
		}

		if(node->left!=NULL && node->right!=NULL)
		{
			linked_stack_push(stack,node);
			int temp = findmax(node->left,stack);
			LINKED_STACK_NODE node_stack = (LINKED_STACK_NODE)malloc(sizeof(LINKED_STACK_NODE_t));
			node_stack = stack->head;
			node->data = temp;
			LINKED_TREE_AVL_NODE temp1 = node_stack->data->left;
			
			node_stack->next->data->left=NULL;
			node_stack->next->data->left=temp1;
			height_upgrade(stack,tree);
		}
		else
		{
			printf("\nUÐRADI\n");
			linked_stack_push(stack,node);
			LINKED_STACK_NODE node_stack = (LINKED_STACK_NODE)malloc(sizeof(LINKED_STACK_NODE_t));
			node_stack = stack->head;
			LINKED_TREE_AVL_NODE temp;
			
			
			if(node->left==NULL)
			{
				temp = node->right;
			}
			else
			{
				temp = node->left;
			}
			
			if(node_stack->next!=NULL)
			{
				if(node_stack->data->data < node_stack->next->data->data)
				{
					node_stack->next->data->left=NULL;
					node_stack->next->data->left=temp;
					height_upgrade(stack,tree);
				}
				else
				{
					node_stack->next->data->right=NULL;
					node_stack->next->data->right=temp;
					height_upgrade(stack,tree);
				}

			}
			else
			{
				height_upgrade(stack,tree);
			}
		}
	}

findmax(LINKED_TREE_AVL_NODE node,LINKED_STACK stack)
{
    LINKED_TREE_AVL_NODE current = node;
 	linked_stack_push(stack,node);
    
    while (current->right != NULL)
    {
        current = current->right;
 		linked_stack_push(stack,current);
 	}
 		
    return current->data;
}


void main(){

	LINKED_STACK stack = linked_stack_init();
	srand(250);
	LINKED_TREE_AVL tree = linked_tree_avl_init();
	int i;
	int r;

	linked_tree_insert(tree,1,stack);
	linked_tree_insert(tree,3,stack);
	linked_tree_insert(tree,4,stack);
	linked_tree_insert(tree,5,stack);
	linked_tree_insert(tree,-1,stack);
	linked_tree_insert(tree,0,stack);
	linked_tree_insert(tree,-2,stack);
	delete(tree,3,stack);

	linked_tree_print_horizontal_recursive(tree->root,0);


}

