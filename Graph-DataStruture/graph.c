#include<stdio.h>
#include<assert.h>
#include<stdint.h>
#include<stddef.h>
#include<stdlib.h>
#include "graph.h"
#include "queue.h"
#include<string.h>
// #define DATA_TYPE Node*
// Graph *graph_new(int32_t s);
Graph *graph_new(uint32_t s)
{
	printf("coming here \n");
	s = (s>0 & s<MAX)?s:MAX;
	Graph *g;
	g->size=s;
	g->neighbors=(Node **)malloc(g->size*sizeof(Node *));
	int32_t i;
	for(i=0;i<g->size;i++)
	{
		g->neighbors[i]=NULL;
	}
	return g;
}

static Node * get_node(int32_t v)
{
	Node *new_node = (Node *) malloc (sizeof(Node));
	new_node->data = v;
	new_node->next = NULL;
	return new_node;
}

static int32_t get_neighbor(int32_t v)
{
	int32_t id;
	printf("Enter Neighbors of node %d. If No neighbors then press 9999: ",v );
	scanf("%d",&id);
	return id;
}

Graph *graph_adjacent_list(Graph *g)
{
	printf("yake\n");
	assert(g!=NULL);
	Node *vertex,*endVertex;
	int32_t neighbors;
	int32_t i;

	for(i=0;i<g->size;i++)
	{
		printf("barthidiya!! \n");
		g->neighbors[i] = get_node(i);
		neighbors = get_neighbor(i);

		while(neighbors!=9999)
		{
			vertex = get_node(neighbors);
			if(g->neighbors[i]->next==NULL)
			{
				g->neighbors[i]->next = vertex;
			}
			else
			{
				endVertex->next = vertex;
			}
			endVertex=vertex;
			neighbors = get_neighbor(i);
		}
	}
return g;
}

static void make_null(Graph *g)
{
	for(int i =0 ; i<g->size;i++)
	{
		visited[i]=FALSE;
	}
}

static void _main_dfs_(Graph *g,int32_t v)
{
	Node *vertex;
	printf("%d \t",v);
	visited[v]=TRUE;
	for(vertex = g->neighbors[v];vertex!=NULL;vertex=vertex->next)
	{
		if(!visited[vertex->data])
		{
			_main_dfs_(g,vertex->data);
		}
	}
}

Graph *graph_dfs(Graph *g,int32_t v)
{
	assert(g!=NULL);
	make_null(g);
	_main_dfs_(g,v);
	return g;
}

Graph *graph_bfs(Graph *g,int32_t s)
{
	assert(g!=NULL);
	make_null(g);
	Queue q = queue_new(g->size);
	// Queue_Result res;
	Queue_Result *res = (Queue_Result*) malloc(sizeof(Queue_Result));
	printf("%d \t", s);
	visited[s]=TRUE;
	queue_add(&q,g->neighbors[s],res);
	while(q.count!=0)
	{
		queue_delete(&q,res);
		Node *temp = res->data;
		int32_t id = temp->data;
		for(Node *vertex=g->neighbors[id];vertex!=NULL;vertex=vertex->next)
		{
			if(!visited[vertex->data])
			{
				printf("%d \t",vertex->data);
				queue_add(&q,vertex,res);
				visited[vertex->data]=TRUE;
			}
		}
	}
	return g;
}