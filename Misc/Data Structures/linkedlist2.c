void array_stack_push(ARRAY_STACK stack, void *data)
{
 /*No fullness control!*/
stack->array[stack->size] = data;
 stack->size++;
 }

 void *array_stack_pop(ARRAY_STACK stack)
{ 
/*No emptiness control!*/
 stack->size--;
 return stack->array[stack->size];
}

typedef struct LINKED_STACK_NODE_s *LINKED_STACK_NODE;
 typedef struct LINKED_STACK_NODE_s{
 LINKED_STACK_NODE next;
 void *data;
 } LINKED_STACK_NODE_t[1];

 typedef struct LINKED_STACK_s{
 LINKED_STACK_NODE head;
 } LINKED_STACK_t[1], *LINKED_STACK;


//-------------PUSH------------------
void linked_stack_push(LINKED_STACK stack, void *data)
{
 LINKED_STACK_NODE node = (LINKED_STACK_NODE)malloc(sizeof(LINKED_STACK_NODE_t));
 
 if(node != NULL)
 {
 node->data = data;
 node->next = stack->head;
 stack->head = node;
 }
 else
 {
 printf("Error @ linked_stack_push: Cannot allocate memory.\n");
 }
 
 }
//--------------------POP----------------------
void *linked_stack_pop(LINKED_STACK stack)
{
 LINKED_STACK_NODE node;
 void *res = NULL;

 if(stack->head != NULL)
 {
 node = stack->head;
 res = node->data;
 stack->head = node->next;
 free(node);
 }
 else
 {
 printf("Error @ linked_stack_pop: Empty stack is popped.\n");
 }
 return res;
 }
//---------------------------------------------QUEUES

function enqueue(data){
 if((head == 0 && tail == max - 1) || (head == tail + 1))
 {
 printf("Queue is full.");
 }
 else
 {
 if(tail == -1)
 {
 tail = 0, head = 0
 }else if(tail == max - 1)
 {
 tail = 0
 }else
 {
 tail = tail + 1
 }
 queue[tail] = data
 }
 }
 
 //------------------------------------
 
 
 function dequeue()
 {
 data = null;
 if(head == -1)
 {
 printf("Queue is empty.");
 }else
 {
 data = queue[head]
 if(head == tail)
 {
 head = -1, tail = -1
 }else if(head == max - 1)
 {
 head = 0
 }else
 {
 head = head + 1
 }
 }
 return data;
 }
 
 //------------------
 typedef struct LINKED_QUEUE_NODE_s *LINKED_QUEUE_NODE;
 typedef struct LINKED_QUEUE_NODE_s{
 LINKED_QUEUE_NODE next;
 void *data;
 } LINKED_QUEUE_NODE_t[1];

 typedef struct LINKED_QUEUE_s *LINKED_QUEUE;
 typedef struct LINKED_QUEUE_s{
 LINKED_QUEUE_NODE head;
 LINKED_QUEUE_NODE tail;
 } LINKED_QUEUE_t[1];
 
 //---------------------------
 
 enqueue(data)
 {
 node = allocate()
 if(node != NULL)
 {
 node->data = data
 node->next = NULL
 if(head == NULL)
 {
 head = node
 }
 else
 {
 tail->next = node
 }
 tail = node
 }
 else
 {
 printf("Cannot allocate");
}
}


dequeue()
{
 res = null
 node = head
 if(node != NULL)
 {
 if(node == tail)
 {
 head = tail = NULL
 }
 else
 {
 head = node->next
 }
 res = node->data
 free(node)
 }
 else
 {
 printf("Queue Empty!");
 }
 return res ;
 }


dequeue()
{
 res = null
 node = head
 if(node != NULL)
 {
  head = node->next
  res = node->data
 free(node)
 }
 else
 {
 print("Queue Empty!");
 }
 return res ;
 }



























