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
Position Top(Stack S);  //      return the node at top of the stack


//----------------------------
// Functions
//----------------------------