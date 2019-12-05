#include<stdio.h>
#include<assert.h>
#include<stdint.h>
#include<stddef.h>
#include "graph.h"
#include "queue.h"

int main()
{
	printf("yen maga neenu \n");
	Graph *g = graph_new(5);
	g = graph_adjacent_list(g);
	printf("\n");
	printf("DFS: \t");
	g=graph_dfs(g,0);

	printf("\n");
	printf("BFS: \t");
	g=graph_bfs(g,0);
	return 0;
}