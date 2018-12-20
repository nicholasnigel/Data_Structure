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
void deleteNode(TreeNode node, Element x);
int isRight(TreeNode node);         //          To see if this node is right subtree of parent node
int isLeft(TreeNode node);          //          To see if this node is left subtree of parent node
void inOrder(TreeNode node);        //          Printing tree with in-order config
void preOrder(TreeNode node);
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
    node->parent = NULL;
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
    if(X < node->content)
    {
        if(!hasLeft(node))
        {
            TreeNode newNode = init(newNode, X);
            node->left = newNode;
            newNode->parent = node;
        }
        else Insert(node->left, X);
    }
    
    else if(X > node->content)
    {
        if(!hasRight(node))
        {
            TreeNode newNode = init(newNode, X);
            node->right = newNode;
            newNode->parent = node;
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
    while(sub->content != X && !isLeaf(sub))        //              while the node's content is not the expected and it doesn't reach leaf, keep findings
    {
        if(X > sub->content) sub = sub->right;
        if(X < sub->content) sub = sub->left;

    }
    return sub;

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

    while(ref->left != NULL)       //          while a node still has left, keep going to the left
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
    return (!hasRight(node) && !hasLeft(node));
}

/**
 * @brief checks whether node is left subtree of node
 * 
 * @param node 
 * @return int 
 */
int isLeft(TreeNode node)
{
    TreeNode parent = node->parent;
    return node->content < parent->content;
}

/**
 * @brief checks whether node is right subtree of node
 * 
 * @param node 
 * @return int 
 */
int isRight(TreeNode node)
{
    TreeNode parent = node->parent;
    return node->content > parent->content;
}

/**
 * @brief function to check whether a node has only one child or not
 * 
 * @param node 
 * @return int 
 */
int hasOneChild(TreeNode node)
{
    return (node->right != NULL && node->left == NULL) || (node->left != NULL && node->right == NULL);
}


/**
 * @brief delete a node and adjust the tree structure
 * 
 * @param node 
 * @param x     
 */
void deleteNode(TreeNode node, Element x)
{
    // Overall algo:
    // if leaf node : simply delete it and set its parent to point to null 
    // if only 1 child: replacement should be the only child itself with breaking any links
    // if 2 children: then get the smallest among right subtree

    TreeNode deleted = Find(node , x);      //          find the node with element x

    if(isLeaf(deleted))     //          if the node is leaf
    {
        if(isRight(deleted)) deleted->parent->right = NULL; 
        else if(isLeft(deleted)) deleted->parent->left = NULL;
        free(deleted);
        return;
    }
    
    
    if(hasOneChild(deleted))        //      if the node has only one child
    {   

        TreeNode replacement;
        replacement = (hasLeft(deleted)) ? deleted->left : deleted->right;      //              This is the replacement node
        
        deleted->content = replacement->content;
        deleted->left = replacement->left;
        deleted->right = replacement->right;        //              simply adopt the deleted with replacement   
        free(replacement);

    }
    
    //          by the time the code gets here, then the deleted has 2 nodes
    
    else 
    {
        TreeNode replacement = SmallestRightSubtree(deleted);
        printf("replacement: %d\n", replacement->content);
        if(isRight(replacement)) deleted->right = replacement->right;
        if(isLeft(replacement)) replacement->parent->left = replacement->right;
        
        deleted->content = replacement->content;        
        

    }
    
    

}

/**
 * @brief printing from the root in order
 * 
 * @param node 
 */
void inOrder(TreeNode node)
{
    if(node == NULL) return;
    inOrder(node->left);
    printf("%d\n",node->content);
    inOrder(node->right);
}

/**
 * @brief printing from root with pre-order config
 * 
 * @param node 
 */
void preOrder(TreeNode node)
{
    if(node == NULL) return;
    printf("%d\n", node->content);
    inOrder(node->left);
    inOrder(node->right);
    
}

