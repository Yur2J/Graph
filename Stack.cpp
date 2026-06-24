#include <iostream>
#include <stack>
using namespace std;
const int VertexCount = 6;
bool Visited[VertexCount] = {};

int AdjacencyMatrix[VertexCount][VertexCount] =
{
    { 0, 1, 0, 1, 0, 0 },
    { 1, 0, 1, 1, 0, 0 },
    { 0, 1, 0, 0, 0, 0 },
    { 1, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 1 },
    { 0, 0, 0, 0, 1, 0 }
};

void DFS(int Current)
{
    cout << "방문: " << Current << '\n';
    Visited[Current] = true;

    for (int Next = 0; Next < VertexCount; ++Next)
    {
        if (AdjacencyMatrix[Current][Next] == 0)
            continue;
        if (Visited[Next] == true)
            continue;

        DFS(Next);
    }
}

void DFSIterative(int Start)
{
    stack<int> VertexStack;

    VertexStack.push(Start);
    Visited[Start] = true;

    while (VertexStack.empty() == false)
    {
        int Current = VertexStack.top();
        VertexStack.pop();

        cout << "방문: " << Current << '\n';

        for (int Next = VertexCount - 1; Next >= 0; --Next)
        {
            if (AdjacencyMatrix[Current][Next] == 0)
            {
                continue;
            }

            if (Visited[Next] == true)
            {
                continue;
            }

            VertexStack.push(Next);
            Visited[Next] = true;
        }
    }
}

void SearchAll()
{
    for (int Current = 0; Current < VertexCount; ++Current)
    {
        if (Visited[Current] == true)
            continue;

        DFS(Current);
    }
}

void main()
{
    //SearchAll();
    DFS(0);
}