#include <iostream>
using namespace std;

#define MaxVertex 10
#define MaxEdge 20

typedef struct Edge
{
	int small; // һ���ߵ���������
	int large;
	int weight;
}Edge;

typedef struct Graph
{
	int vertexNum; // ��������
	int edgeNum; // �ߵ�����
	Edge edges[MaxEdge]; // �ߵļ���
}Graph;

void GraphCreat(Graph* graph);
int MinSpaTree(Graph* graph);
bool HasLoop(Graph* graph, int* child, int i);