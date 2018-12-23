typedef struct Node *ptr;
typedef ptr Trie;

struct Node
{
    char character;     //              Conttain 1 character each node
    Trie n[26];     //              Each correspond to a trie node containing only 1 character
    int alphabet[26];       //              denoting which alphabets are connected to this node of trie
};

//------------------------
//  Prototypes
//------------------------
Trie init(Trie root);       //          initializing the trie node
int alphabetToInt(char x);      //          converting character to int (corresponding to lexicographical)
void Insert(Trie node, char* str);      //          insert new string into the trie
char* substring(char* str);     //          getting substring from index1 to the end
//------------------------
// Functions
//------------------------

/**
 * @brief converting char to int, ASCII related
 * 
 * @param x 
 * @return int 
 */
int alphabetToInt(char x)
{
    return (int)(x-96);
}

/**
 * @brief initializer
 * 
 * @param root 
 * @return Trie 
 */
Trie init(Trie root)
{
    root = malloc(sizeof(struct Node));
    return root;
}

/**
 * @brief Insert new string into the trie
 * 
 * @param root 
 * @param str 
 */
void Insert(Trie node, char* str)
{
    //          recursively create a new node if one doesn't exist in each position
    char character = str[0];        //              get first character of string
    int alp = alphabetToInt(character);     //              get the index of alphabet ( case insensitive )
    if(strlen(str) == 0  ) return;
    
    if(node->n[alp] == NULL) node->n[alp] = malloc(sizeof(struct Node));
    char *sub = substring(str);

    Insert(node->n[alp], sub);
    
}

/**
 * @brief returning the substring of a given string( in here index 1 to end of str)
 * 
 * @param str 
 * @return char* 
 */
char* substring(char* str)
{
    char* sub;
    sub = malloc(26*sizeof(char));
    for(int i=1, j=0; i< strlen(str)+ 1; i++, j++)
    {
        sub[j] = str[i];
    }
    return sub;
}