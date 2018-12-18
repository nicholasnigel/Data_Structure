typedef int Element;
typedef struct Node *ptr;
typedef ptr TreeNode;



struct Node 
{
    Element content;        //          The content of each node
    TreeNode left;          //          The left subtree
    TreeNode right;         //          The right subtree
    TreeNode parent;        //          The parent node
};

//----------------------------------------
// Prototypes
//----------------------------------------

TreeNode init(TreeNode node, Element X);       //       Initialize the tree by its root, and the root should already contain something
void Insert(TreeNode node, Element X);      //          Inserting new node with corresponding element and insert in the right place
TreeNode Find(TreeNode node, Element X);
TreeNode SmallestRightSubtree(TreeNode node);       //          Finding the smallest node of the right subtree of current 'node'
int hasRight(TreeNode node);         //          Check whether a node has right subtree
int hasLeft(TreeNode node);          //          Check whether a node has left subtree
int isLeaf(TreeNode node);           //          Check whether a node is a leaf
//----------------------------------------------
// Functions
//----------------------------------------------
/**
 * @brief initializing
 * 
 * @param X 
 * @return TreeNode 
 */
TreeNode init(TreeNode node,Element X)
{   
    node = malloc(sizeof(struct Node));
    node->content = X;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * @brief Inserting a new element to X
 * 
 * @param node 
 * @param X 
 */
void Insert(TreeNode node, Element X)
{
    
    // considering if numbers must be unique
    if(X < node->content)    //          if number is smaller go to the left
    {
        if(node->left == NULL)
        {
            TreeNode newNode = malloc(sizeof(struct Node));
            newNode->content = X;
            node->left = newNode;
        }
        else Insert(node->left, X);     // else recursively add it

    }
    else if(X > node->content)       //       if number is bigger, trying to exclude if they are equal
    {   
        if(node->right == NULL)
        {
            TreeNode newNode = malloc(sizeof(struct Node));
            newNode->content = X;
            node->right = newNode;
        }
        else Insert(node->right, X);
    }

}

/**
 * @brief To find a node that contains element X
 * 
 * @param X : The content to be searched
 * @param node: root 
 * @return TreeNode 
 */
TreeNode Find(TreeNode node, Element X)
{
    TreeNode sub = node;
    if(sub->content == X) return sub;


    if(sub->left == NULL && sub->right == NULL) return NULL; //     if leaf node but not found yet then return nothing

    if(X < sub->content) Find(sub->left , X);           //          if smaller, explore in left subtree
    if(X > sub->content) Find(sub->right, X);           //          if bigger, explore in right subtree


}

/**
 * @brief finding the right subtree
 * 
 * @param node 
 * @return TreeNode 
 */
TreeNode SmallestRightSubtree(TreeNode node)
{
    if(node->right == NULL) return NULL;        //          If a node contains no right node then just return null
    TreeNode rightSubtree = node->right;        //          Get the right tree 
    TreeNode ref = rightSubtree;        //          as the reference node to be moved around

    while(rightSubtree->left != NULL)       //          while a node still has left, keep going to the left
    {
        ref = ref->left;
    }
    return ref;
    
}
/**
 * @brief checks whether node has right subtree
 * 
 * @param node 
 * @return int 
 */
int hasRight(TreeNode node)
{
    return node->right != NULL;
}

/**
 * @brief checks whether node has left subtree
 * 
 * @param node 
 * @return int 
 */
int hasLeft(TreeNode node)
{
    return node->left != NULL;
}

/**
 * @brief checks wheter node is leaf node
 * 
 * @param node 
 * @return int 
 */
int isLeaf(TreeNode node)
{
    return (hasRight(node) && hasLeft(node));
}