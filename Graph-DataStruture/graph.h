#ifndef _graph_gr_
#define _graph_gr_

#include<stdio.h>
#include<assert.h>
#include<stdint.h>
#include<stddef.h>
#define MAX 32
uint32_t visited[MAX];
#define TRUE 1
#define FALSE 0

typedef struct _node_ Node;
typedef struct _graph_ Graph;

struct _node_ {
	int32_t data;
	Node *next;
};

struct _graph_ {
	int32_t size;
	Node **neighbors;
	int32_t count;
};

// uint32_t graph_adjacent_list(Graph *g);
Graph *graph_adjacent_list(Graph *g);

Graph *graph_dfs(Graph *g,int32_t v);
Graph *graph_new(uint32_t s);
Graph *graph_bfs(Graph *g,int32_t s);


#endif