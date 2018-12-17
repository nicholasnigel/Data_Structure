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


//----------------------------
// Functions
//----------------------------