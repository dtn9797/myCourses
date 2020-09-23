//
//  main.c
//  Cse2320 - Lab 5
//
//  Created by Duy Nguyen on 11/24/18.
//  Copyright © 2018 Duy Nguyen. All rights reserved.
//  Description:Determine strongly connected components of string-type by using double hashing technique.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;  // number of nodes
int e;  // number of edges
int m;  // size of hashtable
struct edge {
    int tail,head,type;
};
typedef struct edge edgeType;
edgeType *edgeTab;
int *firstEdge;  // Table indicating first in range of edges with a common tail

int *vertexStatus,*secondDFSrestarts;

//initilize hash table and vertex names
int *hash;
char **vertexNames;

//Convert string to int for storing in hash table
// m - hash table size
// str- input string for converting
int converStringasKey(int m,char str[]){
    int i,hash = 0;
    for (i=0;str[i]!=0;i++){
        hash = (hash *10 + str[i]) % m;
    }
    return hash;
}
//Check if a number is prime
// number - input number for checking prime
int isPrime(int number) {
    int i;
    for (i=2; i<number; i++) {
        if (number % i == 0 && i != number) return 0;
    }
    return 1;
}
//Determine the table size of hash table based on prime number and load factor no larger than 90%.
// vertexAmount - number of vertices
int computeHashTableSize(int vertexAmount) {
    while(1){
        ++vertexAmount;
        double loadFactor = (double)n/vertexAmount;
        if (isPrime(vertexAmount) && loadFactor<.9) {
            break;
        }
    }
    return vertexAmount;
}

//Assign input string as an assigned vertex numbers, the store input string in a table of vertex names and insert that assigned vertex numbers in a hash table
// m - size of hash table
// *hash- hash table
// **vertexNames- table of vertex names
// return an address index of a string which is stored in vertexNames table
int insertInHashTable (int m,int* hash,char str[25], char** vertexNames) {
    int currentNameIndex=0;
    int i,j;
    int h1,h2,key;
    key= converStringasKey(m, str);
    i=h1=key%m;
    h2=key%(m-1)+1;
    
    while (hash[i]!=(-1) && strcmp(str,vertexNames[hash[i]])!=0){
        i=(i+h2)%m;
    }
    if (hash[i]!=-1 && strcmp(str,vertexNames[hash[i]])==0){
        //        printf("Duplicate strings %s not inserted.\n",str);
        currentNameIndex = hash[i];
    }
    else {
        //find empty value index in vertexNames table
        for (j = 0 ;j < n;j++){
            if (strlen(vertexNames[j])==0){
                currentNameIndex=j;
                break;
            }
        }
        //add new currentNameIndex to vertexNames
        strcpy(vertexNames[currentNameIndex], str);
        //        printf("Just copied %s in index %d of vertex table.\n",vertexNames[currentNameIndex],currentNameIndex);
        hash[i]=currentNameIndex;
        //        printf("Stored %d in index %d of hashtabel.\n",currentNameIndex,i);
    }
    return currentNameIndex;
}

//Source code from : http://ranger.uta.edu/~weems/NOTES2320/dfsSCC.c
int tailThenHead(const void* xin, const void* yin)
// Used in calls to qsort() and bsearch() for read_input_file()
{
    int result;
    edgeType *x,*y;
    
    x=(edgeType*) xin;
    y=(edgeType*) yin;
    result=x->tail - y->tail;
    if (result!=0)
        return result;
    else
        return x->head - y->head;
}
//read input file
void read_input_file()
{
    int a,b,i,j;
    edgeType work;
    edgeType *ptr;
    
    scanf("%d %d",&n,&e);
    edgeTab=(edgeType*) malloc(e*sizeof(edgeType));
    //determine size of hashtable
    m = computeHashTableSize(n);
    //initilize hash table
    hash=(int*) malloc(m*sizeof(int));
    // Flag all slots as never-used
    for (i=0;i<m;i++)
        hash[i]=(-1);
    //ini vertex names
    vertexNames = malloc(n*sizeof(char*));
    for (i=0; i<n; i++) {
        vertexNames[i] = malloc(25*sizeof(char));
    }
    
    
    if (!edgeTab)
    {
        printf("edgeTab malloc failed %d\n",__LINE__);
        exit(0);
    }
    
    
    
    // read edges
    int currentIndex = -1;
    char s0[25],s1[25];
    for (i=0; i<e; i++)
    {
        scanf("%s %s",s0,s1);
        
        a= insertInHashTable(m, hash, s0, vertexNames );
        b= insertInHashTable(m, hash, s1, vertexNames);
        currentIndex = b;
        
        
        
        if (a<0 || a>=n || b<0 || b>=n)
        {
            printf("Invalid input %d %d at %d\n",a,b,__LINE__);
            exit(0);
        }
        edgeTab[i].tail=a;
        edgeTab[i].head=b;
    }
    
    // sort edges
    qsort(edgeTab,e,sizeof(edgeType),tailThenHead);
    
    // Coalesce duplicates into a single edge
    j=0;
    for (i=1; i<e; i++)
        if (edgeTab[j].tail==edgeTab[i].tail
            && edgeTab[j].head==edgeTab[i].head)
            ;
        else
        {
            j++;
            edgeTab[j].tail=edgeTab[i].tail;
            edgeTab[j].head=edgeTab[i].head;
        }
    e=j+1;
    
    // For each vertex as a tail, determine first in range of edgeTab entries
    firstEdge=(int*) malloc((n+1)*sizeof(int));
    if (!firstEdge)
    {
        printf("malloc failed %d\n",__LINE__);
        exit(0);
    }
    j=0;
    for (i=0; i<n; i++)
    {
        firstEdge[i]=j;
        for ( ;
             j<e && edgeTab[j].tail==i;
             j++)
            ;
    }
    firstEdge[n]=e;
}

int finishIndex;
//Source code from : http://ranger.uta.edu/~weems/NOTES2320/dfsSCC.c
void DFSvisit(int u)
{
    int i,v;
    
    vertexStatus[u]=GRAY;
    
    for (i=firstEdge[u];i<firstEdge[u+1];i++)
    {
        v=edgeTab[i].head;
        if (vertexStatus[v]==WHITE)
            DFSvisit(v);
    }
    vertexStatus[u]=BLACK;
    secondDFSrestarts[--finishIndex]=u;
}
//Source code from : http://ranger.uta.edu/~weems/NOTES2320/dfsSCC.c
void reverseEdges()
{
    int a,b,i,j;
    edgeType work;
    edgeType *ptr;
    
    for (i=0; i<e; i++)
    {
        a=edgeTab[i].tail;
        b=edgeTab[i].head;
        edgeTab[i].tail=b;
        edgeTab[i].head=a;
    }
    
    // sort edges
    qsort(edgeTab,e,sizeof(edgeType),tailThenHead);
    
    // For each vertex as a tail, determine first in range of edgeTab entries
    if (!firstEdge)
    {
        printf("malloc failed %d\n",__LINE__);
        exit(0);
    }
    j=0;
    for (i=0; i<n; i++)
    {
        firstEdge[i]=j;
        for ( ;
             j<e && edgeTab[j].tail==i;
             j++)
            ;
    }
    firstEdge[n]=e;
}
//Source code from : http://ranger.uta.edu/~weems/NOTES2320/dfsSCC.c
void DFSvisit2(int u)
{
    int i,v;
    //Translate key to input string & print to the end user
    printf("%s\n",vertexNames[u]); // Indicate that u is in SCC for this restart
    vertexStatus[u]=GRAY;
    
    for (i=firstEdge[u];i<firstEdge[u+1];i++)
    {
        v=edgeTab[i].head;
        if (vertexStatus[v]==WHITE)
            DFSvisit2(v);
    }
    vertexStatus[u]=BLACK;
}

int main()
{
    int a,b;
    int u,i,j,k,nextDFS;
    int SCCcount=0;
    read_input_file();
    
    vertexStatus=(int*) malloc(n*sizeof(int));
    secondDFSrestarts=(int*) malloc(n*sizeof(int));
    if (!vertexStatus || !secondDFSrestarts)
    {
        printf("malloc failed\n");
        exit(0);
    }
    // DFS code
    for (u=0;u<n;u++)
        vertexStatus[u]=WHITE;
    finishIndex=n;
    for (u=0;u<n;u++)
        if (vertexStatus[u]==WHITE)
            DFSvisit(u);
    
    reverseEdges();
    
    // DFS code
    for (u=0;u<n;u++)
        vertexStatus[u]=WHITE;
    //Print table size
    printf("Double hash table size is %d\n",m);
    for (i=0;i<n;i++)
        if (vertexStatus[secondDFSrestarts[i]]==WHITE)
        {
            SCCcount++;
            printf("SCC %d\n",SCCcount);
            DFSvisit2(secondDFSrestarts[i]);
        }
    
    free(hash);
    for (i=0;i<n;i++)
        free(vertexNames[i]);
    free(vertexNames);
    free(edgeTab);
    free(firstEdge);
    free(vertexStatus);
    free(secondDFSrestarts);
}






