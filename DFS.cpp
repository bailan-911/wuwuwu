#include<iostream>
using namespace std;
typedef char vertexType;
typedef int edgeType;
#define maxsize 100;
typedef struct {
	vertexType vertex[10];
	edgeType  edge[100][100];
	int vertex_num;
	int edge_num;
}Mat_graph;
int visit[100];//记录已经访问的点
void createGraph(Mat_graph *G)//造图
{
	G->vertex_num = 9;
	G->edge_num = 15;
	G->vertex[0] = 'A';
	G->vertex[1] = 'B';
	G->vertex[2] = 'C';
	G->vertex[3] = 'D';
	G->vertex[4] = 'E';
	G->vertex[5] = 'F';
	G->vertex[6] = 'G';
	G->vertex[7] = 'H';
	G->vertex[8] = 'I';
	//
	for (int i = 0;i < G->edge_num;i++)
	{
		for (int j = 0;j < G->edge_num;j++)
		{
			G->edge[i][j] = 0;
		}
	}
	//A-B,A-F
	G->edge[0][1] = 1;
	G->edge[0][5] = 1;
	//B-C B-G B-I
	G->edge[1][2] = 1;
	G->edge[1][6] = 1;
	G->edge[1][8] = 1;
	//C-D C-I
	G->edge[2][3] = 1;
	G->edge[2][8] = 1;
	//D-E D-G D-H D-I
	G->edge[3][4] = 1;
	G->edge[3][6] = 1;
	G->edge[3][7] = 1;
	G->edge[3][8] = 1;
	//F-G 
	G->edge[5][6] = 1;
	//G-H
	G->edge[6][7] = 1;
	for (int i = 0;i < G->vertex_num;i++)
	{
		for (int j = 0;j < G->vertex_num;j++)
		{
			G->edge[j][i] = G->edge[i][j];
		}
	}
}
void DFS(Mat_graph* G, int i)
{
	visit[i] = 1;
	cout << G->vertex[i]<< endl;
	for (int j= 0;j < G->vertex_num;j++)
	{
		if (visit[j] == 0 && G->edge[i][j] == 1)
			DFS(G, j);
	}
}
int main()
{
	Mat_graph g;
	createGraph(&g);
	DFS(&g, 0);
	return 0;
}