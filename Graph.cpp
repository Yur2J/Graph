#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

// 인접행렬 방식 명시적 그래프로 나타내기
const int VertexCount = 6;
int AdjacencyMatrix[VertexCount][VertexCount] =
{
	{0, 1, 0, 1, 0, 0},
	{1, 0, 1, 1, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{1, 1, 0, 0, 1, 0},
	{0, 0, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 0}
};
bool Visited[VertexCount] = {};

// 나중에 재귀 방식 말고 Stack으로도 만들어보기 (재귀X 조건 있을 수 있음)
void DFS(int Current)
{
	cout << "방문: " << Current << '\n';
	Visited[Current] = true; // 방문 도장 찍기

	for (int Next = 0; Next < VertexCount; Next++)
	{
		if (AdjacencyMatrix[Current][Next] == 0) // 연결 여부 확인
			continue;

		if (Visited[Next] == true) // 방문한 적 있는지?
			continue;

		DFS(Next);
	}
}

void SearchAll()
{
	for (int Current = 0; Current < VertexCount; Current++) // 모든 정점 확인
	{
		if (Visited[Current] == true)
			continue;

		DFS(Current); 		// DFS 총 2번 (connect가 2번)

		//// 아직 방문하지 않은 정점을 시작점으로 DFS 함수 실행
		//if (Visited[Current] == false)
		//{
		//	cout << "방문하지 않은 정점 = " << Current << '\n';

		//	DFS(Current);
		//}
	}
}

void main()
{
	SearchAll();
}