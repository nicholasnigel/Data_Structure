#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
/*
char* substring(char* str)
{
    char* sub;
    sub = malloc(26*sizeof(char));
    for(int i=1, j=0; i< strlen(str)+ 1; i++, j++)
    {
        sub[j] = str[i];
    }
    //printf("%s\n",sub );
    return sub;
}   
*/

void recon(char* str)
{
    int length = strlen(str);
    if(length == 0) return;
    printf("before %s: %d\n", str,length);
    char *new = substring(str);
    int length2 = strlen(new);
    recon(new);

}


int main(void)
{       
    Trie root = init(root);
    Insert(root, "test");
    if(root->n[20]->n[5] == NULL) printf("NULL");
   //recon(str);
   return 0;
}