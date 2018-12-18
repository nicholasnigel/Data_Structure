// Linked_List Implementation for queue ( doubly/circular linked list)
typedef int Type;
typedef struct Node *ptr;
typedef ptr Queue;
typedef ptr Position;

struct Node
{
    Type element;       //      content of node
    Position next;      //      next node
    Position prev;      //      previous node
};

//------------------------------------------------------------------
// Prototypes
//------------------------------------------------------------------
Queue init(Queue Q);    //      initializing queue
void Enqueue(Queue Q, Type X);  //      enqueue: insert to the back of the queue
void Dequeue(Queue Q);      //          dequeue: remove the front of the queue
int size(Queue Q);          //          get the size of queue
void DequeueAndEnqueue(Queue Q);        //     move the front of the queue to the back
void PrintQueue(Queue Q);       //          print the content of Queue
//------------------------------------------------------------------
// Functions
//------------------------------------------------------------------

/**
 * @brief initializer 
 * note: for head of the queue, next stores the front while prev stores the back
 * @param Q 
 * @return Queue 
 */
Queue init(Queue Q)
{
    Q = malloc(sizeof(struct Node));
    Q->next = NULL;     //      next is first element
    Q->prev = Q;        //      put previous node as itself , easier for recursion later on since prev is last element
    return Q;
}

/**
 * @brief Queue operation enqueue: to insert a new node into the back 
 * 
 * @param Q : Queue
 * @param X : Element
 */
void Enqueue(Queue Q, Type X) 
{
    Position newNode=  malloc(sizeof(struct Node));
    newNode->element = X;
    newNode->next = NULL;
    newNode->prev = Q->prev;
    Q->prev->next = newNode;
    Q->prev = newNode;
}

/**
 * @brief release the front of the queue and adjust
 * 
 * @param Q : Queue
 */
void Dequeue(Queue Q)
{
    Position Front = Q->next;
    Q->next = Front->next;
    Front->next->prev = Q;
    free(Front);
}

/**
 * @brief get the total content of the queue
 * 
 * @param Q : Queue
 * @return int : returning the number 
 */
int size(Queue Q) 
{
    int i = 0;
    Position p = Q;
    while(p->next != NULL)
    {
        p = p->next;
        i++;
    }
    return i;
}

void PrintQueue(Queue Q)
{
    Position P = Q;
    while( P->next != NULL)
    {
        P = P->next;
        printf("%d\n", P->element);
    }
}
