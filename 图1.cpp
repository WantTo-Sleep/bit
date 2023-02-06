#include <iostream>
#include <vector>

using namespace std;

// 定义顶点的结构
typedef struct Vertex
{
	char name;
	vector<Vertex*> neighbors;
}Graph;

void GraphAddEdge(Graph* graph, char ver1, char ver2, int verNum)
{
	// NULL
	int g1 = 0, g2 = 0;
	for (int i = 0; i < verNum; ++i)
	{
		if (graph[i].name == ver1)
			g1 = &graph[i];
		if (graph[i].name == ver2)
			g2 = &graph[i];
	}

}

void GraphPrint(Graph* graph, int verNum)
{
	for (int i = 0; i < verNum; ++i)
	{
		printf("%c", graph[i].name);
		// unsigned int
		for (int j = 0; j < graph[i].neighbors.size(); ++j)
		{
			printf("->%c", graph[i].neighbors[j]->name);
		}
		printf("\n");
	}
}

int main()
{
	int a = 10;
	int* p = &10;
	//Vertex ver1;
	//Vertex ver2;
	//ver1.neighbors.push_back(&ver2);
	int verNum = 0, edgeNum = 0;
	cin >> verNum >> edgeNum;
	
	Graph* graph = (Graph*)malloc(sizeof(Graph) * verNum);
	if (graph == NULL)
	{
		perror("graph malloc");
		exit(-1);
	}

	// 读入顶点名称
	for (int i = 0; i < verNum; ++i)
	{
		char name;
		cin >> name;
		graph[i].name = name;
	}

	// 读入边
	for (int i = 0; i < edgeNum; ++i)
	{
		char ver1, ver2;
		cin >> ver1 >> ver2;
		GraphAddEdge(graph, ver1, ver2, verNum);
	}

	GraphPrint(graph, verNum);

	return 0;
}



// 无向图
//    A   B   C   D   E
// A  0   1   1   0   1
// B  1   0   1   0   0
// C  1   1   0   1   0
// D  0   0   1   0   1
// E  1   0   0   1   0
// 
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#define N 5
//
//typedef char VertexType;
////                数组指针
//void GraphAddEdge(int (*arr)[N], VertexType ver1, VertexType ver2, VertexType* verName)
//{
//	int i = 0, j = 0;
//	while (ver1 != verName[i])
//	{
//		++i;
//	}
//	while (ver2 != verName[j])
//	{
//		++j;
//	}
//	// *(*(arr+i)+j)
//	arr[i][j] = arr[j][i] = 1;
//}
//
//int main()
//{
//	// 顶点的数量
//	int verNum = 0;
//	int edgeNum = 0;
//	scanf("%d%d", &verNum, &edgeNum);
//	getchar();
//	int arr[N][N] = { 0 };
//
//	// 读入顶点的名字
//	VertexType* verName = (VertexType*)malloc(sizeof(VertexType) * verNum);
//	if (verName == NULL)
//	{
//		perror("verName");
//	}
//
//	for (int i = 0; i < verNum; ++i)
//	{
//		scanf("%c", verName + i);
//	}
//	getchar();
//
//	// 读顶点的边
//	while (edgeNum--)
//	{
//		VertexType ver1, ver2;
//		scanf("%c%c", &ver1, &ver2);
//		getchar();
//		GraphAddEdge(arr, ver1, ver2, verName);
//	}
//
//	for (int i = 0; i < verNum; ++i)
//	{
//		for (int j = 0; j < verNum; ++j)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	// 输出每个顶点的度
//	for (int i = 0; i < verNum; ++i)
//	{
//		printf("%c:", verName[i]);
//		int sum = 0;
//		for (int j = 0; j < verNum; ++j)
//		{
//			sum += arr[i][j];
//		}
//		printf("%d\n", sum);
//	}
//
//	free(verName);
//	return 0;
//}