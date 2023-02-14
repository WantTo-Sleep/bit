#include "MST.h"

void GraphCreat(Graph* graph)
{
	cin >> graph->vertexNum >> graph->edgeNum;
	for (int i = 0; i < graph->edgeNum; ++i)
	{
		cin >> graph->edges[i].small >> graph->edges[i].large >> graph->edges[i].weight;
	}
}

int MinSpaTree(Graph* graph)
{
	int weights = 0; // ��������������Ȩ
	int child[MaxVertex] = { 0 }; // �ж����ɵ����Ƿ�ɻ�
	for (int i = 0; i < graph->vertexNum; ++i)
	{
		child[i] = i;
	}

	// һ����һ�������������
	// ������������ = ������ + 1
	int edgeCount = 0;
	int i = 0; // ��������ÿһ����
	while (edgeCount < graph->vertexNum - 1)
	{
		if (HasLoop(graph, child, i))
		{
			++i;
			continue;
		}
		cout << graph->edges[i].small << " " << graph->edges[i].large << " " << graph->edges[i].weight << endl;
		weights += graph->edges[i].weight;
		edgeCount++;
		++i;
	}
	return weights;
}

bool HasLoop(Graph* graph, int* child, int i)
{
	int ver1 = graph->edges[i].small;
	int ver2 = graph->edges[i].large;
	// �ֱ�������������յ�
	while (ver1 != child[ver1])
	{
		ver1 = child[ver1];
	}
	while (ver2 != child[ver2])
	{
		ver2 = child[ver2];
	}

	if (ver1 == ver2)
	{
		return true;
	}
	else
	{
		if (ver1 > ver2)
		{
			child[ver2] = ver1;
		}
		else
		{
			child[ver1] = ver2;
		}
		return false;
	}
}