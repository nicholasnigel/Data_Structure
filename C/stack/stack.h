typedef int type;
typedef struct Node *ptrNode;
typedef ptrNode Stack;
typedef ptrNode Position;



struct Node 
{
    type element;
    Position next;
};

//----------------------------
// Prototypes
//----------------------------
Stack init(Stack S); //     initializing stack S
Position Top(Stack S);  //      return the node at top of the stack
void Push(Stack S, type X);     //        push X to stack s
void Pop(Stack S);          //      Pop the top of the stack
bool isEmpty(Stack S);      //      Checking whether stack is empty
void makeEmpty(Stack S);    //      make empty a stack
//----------------------------
// Functions
//----------------------------

/**
 * @brief Initialize Stack S
 * 
 * @param S : Stack as parameter (contains nothing at first)
 * @return Stack : the newly created Stack
 */
Stack init(Stack S)
{
    S = malloc(sizeof(struct Node));
    S->next = NULL;
    return S;
}

/**
 * @brief Check if Stack S is empty
 * 
 * @param S : Stack
 * @return true : if next is null
 * @return false : if next is not null
 */
bool isEmpty(Stack S)
{
    if(S->next == NULL) return true;
    else return false;

}

/**
 * @brief Push Element X into Stack S
 * 
 * @param S : Stack
 * @param X : Elements
 */
void Push(Stack S, type X) 
{
    // create node
    Position newNode = malloc(sizeof(struct Node));
    newNode->element = X;

    newNode->next = S->next;
    S->next = newNode;

}   

/**
 * @brief returning the top of the stack
 * 
 * @param S : stack
 * @return Position: the position 
 */
Position Top(Stack S)
{
    return S->next;
}

/**
 * @brief pop the stack
 * 
 * @param S 
 */
void Pop(Stack S)
{
    Position p = Top(S);
    S->next = p->next;
    free(p);
}

/**
 * @brief Get the Element object of a certain position.
 * 
 * @param P 
 * @return type 
 */
type getElement(Position P)
{
    return P->element;
}

/**
 * @brief empty the stack by freeing everything ( save space)
 * 
 * @param S 
 */
void makeEmpty(Stack S)
{
    while(!isEmpty(S))  //      as long as stack is still not empty keep popping
    {
        Pop(S);
    }
}