//
//  main.c
//  Lab 6
//
//  Created by Duy Nguyen on 11/30/18.
//  Copyright © 2018 Duy Nguyen. All rights reserved.
//
// Description: Determine a Euclidean Minimum Spanning Tree (EMST) for a set of 2-d points interpreted as the vertices of a weighted undirected graph.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numVertices,numEdges;
int *parent,numTrees;
int *weight;

struct edge {
    int tail,head;
    double weight;
};
//Edge of undirected graph
typedef struct edge edgeType;
//Array of edges in undirected grpah
edgeType *edgeTab;

// Get from the following source code :http://ranger.uta.edu/~weems/NOTES2320/kruskal.c
int find(int x)
// Find root of tree containing x
{
    int i,j,root;

    // Find root
    for (i=x;
         parent[i]!=i;
         i=parent[i])
        ;
    root=i;
    // path compression - make all nodes on path
    // point directly at the root
    for (i=x;
         parent[i]!=i;
         j=parent[i],parent[i]=root,i=j)
        ;
    return root;
}
// Get from the following source code :http://ranger.uta.edu/~weems/NOTES2320/kruskal.c
void unionFunc(int i,int j)
// i and j must be roots!
{
    if (weight[i]>weight[j])
    {
        parent[j]=i;
        weight[i]+=weight[j];
    }
    else
    {
        parent[i]=j;
        weight[j]+=weight[i];
    }
    numTrees--;
}
// Get from the following source code :http://ranger.uta.edu/~weems/NOTES2320/kruskal.c
// Modified this method for comparing double types instead of int types

int weightAscending(const void* xin, const void* yin)
// Used in call to qsort()
{
    edgeType *x,*y;

    x=(edgeType*) xin;
    y=(edgeType*) yin;
    // Return 0 if both weight are equal
    // Return 1 if weight of x is gretar than weight of y
    // Return -1 if weight of y is gretar than weight of x
    if (x->weight == y->weight)
        return 0;
    else if(x->weight > y->weight)
        return 1;
    else
        return -1;
}

int main()
{
    int i,j;
    int root1,root2;
    int **vertices;
    double MSTweight=0;

    scanf("%d",&numVertices);
    numEdges = numVertices*(numVertices-1)/2;

    edgeTab=(edgeType*) malloc(numEdges*sizeof(edgeType));
    parent=(int*) malloc(numVertices*sizeof(int));
    weight=(int*) malloc(numVertices*sizeof(int));
    vertices = (int**) malloc(numVertices*sizeof(int*));
    for (i=0; i<numVertices; i++) {
        vertices[i] = (int *) malloc(2*sizeof(int));
    }
    if (!edgeTab || !parent || !weight)
    {
        printf("error 2\n");
        exit(0);
    }

    for (i=0; i<numVertices; i++) {
        scanf("%d %d",&vertices[i][0], &vertices[i][1]);
    }
    int k=0;

    for (i=0; i<numVertices-1; i++) {
        for (j = i+1; j<numVertices; j++) {
            (edgeTab[k]).tail = i;//1
            (edgeTab[k]).head = j;//2
            int x1 = vertices[i][0];
            int x2 =vertices[j][0];
            int y1 =vertices[i][1];
            int y2 =vertices[j][1];
            //Compute the distance between 2-d points
            double distance = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
            (edgeTab[k]).weight = distance;
            k++;
        }
    }

    for (i=0; i<numVertices; i++) {
        printf("%d %d %d\n",i,vertices[i][0], vertices[i][1]);
    }

    for (i=0;i<numVertices;i++)
    {
        parent[i]=i;
        weight[i]=1;
    }
    numTrees=numVertices;
    qsort(edgeTab,numEdges,sizeof(edgeType),weightAscending);
    printf("After sorting:\n");
    for (i=0; i<numVertices; i++) {
        printf("%f \n",(edgeTab[i]).weight);
    }
    k = 0;
    for (i=0;i<numEdges;i++)
    {
        root1=find(edgeTab[i].tail);
        root2=find(edgeTab[i].head);
        // exit the loop if n-1 edges are included
        if (k==numVertices-1) break;
        if (root1==root2){
            printf("%d %d \t %f discarded\n",edgeTab[i].tail,edgeTab[i].head,
                   edgeTab[i].weight);
        }
        else
        {
            printf("%d %d \t %f included\n",edgeTab[i].tail,edgeTab[i].head,
                   edgeTab[i].weight);
            MSTweight+=edgeTab[i].weight;
            unionFunc(root1,root2);
            ++k;
        }
    }
    if (numTrees!=1)
        printf("MST does not exist\n");
    printf("Sum of weights of spanning edges %f\n",MSTweight);
    
    //Free all allocated memory.
    free(edgeTab);
    for(i=0;i<numVertices;i++)
        free(vertices[i]);
    free(vertices);
    free(parent);
    free(weight);
}





