iterative Postorder(node){
	
	s=empty_stack;
	lastnodevisited=null;
	
	while(! s.isEmpty() || node!=NULL){
		
		if(node!=NULL){
			s.push(node);
			node=node->left;
		}
		else{
			
			peeknode=s->peek();	
			if(peeknode->right!=NULL && lastnodevisited != peeknode->right){
				node=peeknode->right;
				
			}else{
				visit(peeknode);
				lastnodevisited=s.pop();
			}
			
		}
	}
	
	
}

//************************************************

void postOrderTraversalIterative(BinaryTree *root) {
  if (!root) return;
  stack<BinaryTree*> s;
  s.push(root);
  BinaryTree *prev = NULL;
  while (!s.empty()) {
    BinaryTree *curr = s.top();
    // we are traversing down the tree
    if (!prev || prev->left == curr || prev->right == curr) {
      if (curr->left) {
        s.push(curr->left);
      } else if (curr->right) {
        s.push(curr->right);
      } else {
        cout << curr->data << " ";
        s.pop();
      }
    } 
    // we are traversing up the tree from the left
    else if (curr->left == prev) {
      if (curr->right) {
        s.push(curr->right);
      } else {
        cout << curr->data << " ";
        s.pop();
      }
    }
    // we are traversing up the tree from the right
    else if (curr->right == prev) {
      cout << curr->data << " ";
      s.pop();
    }
    prev = curr;  // record previously traversed node
  }
}

//************************************************
void postOrderTraversalIterative(BinaryTree *root) {
  if (!root) return;
  stack<BinaryTree*> s;
  s.push(root);
  BinaryTree *prev = NULL;
  while (!s.empty()) {
    BinaryTree *curr = s.top();
    if (!prev || prev->left == curr || prev->right == curr) {
      if (curr->left)
        s.push(curr->left);
      else if (curr->right)
        s.push(curr->right);
    } else if (curr->left == prev) {
      if (curr->right)
        s.push(curr->right);
    } else {
      cout << curr->data << " ";
      s.pop();
    }
    prev = curr;
  }
}

//************************************************

void postOrderTraversalIterativeTwoStacks(BinaryTree *root) {
  if (!root) return;
  stack<BinaryTree*> s;
  stack<BinaryTree*> output;
  s.push(root);
  while (!s.empty()) {
    BinaryTree *curr = s.top();
    output.push(curr);
    s.pop();
    if (curr->left)
      s.push(curr->left);
    if (curr->right)
      s.push(curr->right);
  }
  while (!output.empty()) {
    cout << output.top()->data << " ";
    output.pop();
  }
}
//************************************************

struct Node* peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}

//************************************************

// An iterative function to do postorder traversal of a given binary tree
void postOrderIterative(struct Node* root)
{
    // Check for empty tree
    if (root == NULL)
        return;
     
    struct Stack* stack = createStack(MAX_SIZE);
    do
    {
        // Move to leftmost node
        while (root)
        {
            // Push root's right child and then root to stack.
            if (root->right)
                push(stack, root->right);
            push(stack, root);
 
            // Set root as root's left child  
            root = root->left;
        }
 
        // Pop an item from stack and set it as root    
        root = pop(stack);
 
        // If the popped item has a right child and the right child is not
        // processed yet, then make sure right child is processed before root
        if (root->right && peek(stack) == root->right)
        {
            pop(stack);  // remove right child from stack
            push(stack, root);  // push root back to stack
            root = root->right; // change root so that the right 
                                // child is processed next
        }
        else  // Else print root's data and set root as NULL
        {
            printf("%d ", root->data);
            root = NULL;
        }
    } while (!isEmpty(stack));
}

//************************************************

// Driver program to test above functions
int main()
{
    // Let us construct the tree shown in above figure
    struct Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    printf("Post order traversal of binary tree is :\n");
    printf("[");
    postOrderIterative(root);
    printf("]");
     
 
    return 0;
}


//************************************************
