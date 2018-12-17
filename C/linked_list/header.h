typedef int Type;
typedef struct Node *PtrNode;
typedef PtrNode List;
typedef PtrNode Position;

struct Node
{
    Type element;
    Position next;
};
//------------------------------
// Prototypes 
//------------------------------
List init(List L);  
void insert(List L, Type x);   
void printList(List L);
void deleteElement(List L, Type num);
Position FindPrev(List L, Type Num);
Position Find(List L, Type num);
int indexOf(List L, Type x);
Position findAtPos(List L, int pos);
List createSubList(List L, int index1, int index2);
int sizeOfList(List L);
//-------------------------------
// Functions
//-------------------------------


/**
 * @brief initializing a list data structure, simply create with malloc and turn next to null
 * asdsad
 * @return List 
 */
List init(List L) 
{
    L = malloc(sizeof(struct Node));
    L->next = NULL;
    return L;
}


/**
 * @brief create a new element with malloc and insert to place on the last first 
 * 
 * @param L type List
 * @param x type Element
 */
void insert(List L, Type x)
{

    Position newnode = malloc(sizeof(struct Node));
    Position p;
    newnode->element = x;
    p = L;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = newnode;
    newnode->next = NULL;
}

/**
 * @brief print content of list
 * 
 * @param L 
 */
void printList( List L)
{
    Position p = L;

    while(p->next != NULL) 
    {
        p = p->next;
        printf("%d\n", p->element );
    }

}

/**
 * @brief Deleting num from list L
 * 
 * @param L: List to search num from 
 * @param num: type to delete from the list
 */
void deleteElement(List L, Type num)
{   
    // find the element first (whether it exist or not)
    Position p,prev; 
    p = Find(L,num);
    if(p == NULL)
    {
        printf("Not Found");
        return;
    }
    // if it passes through here, it exists
    printf("Found\n");
    // given a previous position: 
    // prev->next = p->next, 
    prev = FindPrev(L,num);

    prev->next = p->next;
    free(p);
}   

/**
 * @brief find the node before the element num
 * 
 * @param L : Main List
 * @param Num : the main elemnet
 * @return Position : position of the node previous to element
 */
Position FindPrev(List L, Type Num)
{
    Position p;
    p = L;

    if(p->next->element == Num) return p;
    while(p->next!=NULL && p->next->element!= Num)  
    {
        p = p->next;
    }
    return p;

}

/**
 * @brief 
 * 
 * @param L : List L
 * @param num : num to find in the nodes
 */
Position Find(List L, Type num) 
{
    Position p;
    p = L;

    while(p->next!= NULL)
    {
        p = p->next;
        if(p->element == num) return p;
    }
    return NULL;
}

/**
 * @brief simple find element while keeping count of how many has the 
 * list iterated. assumption that it starts from 1 
 * 
 * @param L: List L 
 * @param x : the element
 * @return int : returns the index of thi
 */
int indexOf(List L, Type x) 
{
    Position P;
    P = L;
    if(P->next == NULL) return -1; // this means list is empty, so put a nonsense number

    int i = 0;
    while(P->next != NULL && P->element!= x)
    {
        P = P->next;
        i++;
    }
    return i;
}   

/**
 * @brief returns the node which is at position pos in list L
 * 
 * @param L : list to traverses
 * @param pos : the position( an integer)
 * @return Position : the node that should be returned
 */
Position findAtPos(List L, int pos)
{
    Position P;
    P = L;
    // traverse the list pos number of timess
    while(pos>=1 && P->next != NULL)
    {   P = P->next;
        pos--; 
    }
    return P;

}

/**
 * @brief size of list ( content size )
 * 
 * @param L : List involved
 * @return int : the size returned
 */
int sizeOfList(List L)
{
    Position P;
    P = L;

    if(P->next == NULL) return -1; // this means list is empty, so put a nonsense number

    int i = 0;
    while(P->next != NULL)
    {
        P = P->next;
        i++;
    }
    return i;
}

/**
 * @brief Create a Sub List object
 * 
 * @param L : The List
 * @param index1 : first index
 * @param index2 : second index 
 * @return List : the new list
 */
List createSubList(List L, int index1, int index2)
{
    // first checking whether index is out of bounds
    int size = sizeOfList(L);
    if(size < index1 || size < index2) return NULL;     // if it is supposed to be out of bound, then return null

    List newList = init(newList);
    int diff = index2 - index1;

    Position P = findAtPos(L , index1);
    while(diff>=1)
    {  
        Type elem = P->element;
        insert(newList,elem);
        diff--;
    }
    return newList;


}