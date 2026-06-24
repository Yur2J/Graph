#include <iostream>

using namespace std;

// 백준 - 유기농 배추 문제 (DFS 이용)

int M, N, K;
int field[50][50] = {};
bool visited[50][50] = {};
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

void dfs(int y, int x)
{
    // 방문 표시
    visited[y][x] = true;

    // 연결이 되어있고, 아직 방문 안한놈 찾기
    for (int i = 0; i < 4; i++) // 4방위 확인
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        //범위초과 먼저 검증
        if (ny >= 0 && ny < N && nx >= 0 && nx < M)
        {
            if (field[ny][nx] == 1 && !visited[ny][nx])
                dfs(ny, nx); // 반복
        }
    }
}

int main()
{
    cin >> M >> N >> K;

    // 맵만들기
    for (int i = 0; i < K; i++)
    {
        int X, Y;
        cin >> X >> Y;
        field[Y][X] = 1;
    }

    // DFS 전체순회
    int worm_count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (field[i][j] == 1 && !visited[i][j])
            {
                dfs(i, j);
                worm_count++;
            }
        }
    }

    // 출력
    cout << worm_count << '\n';
}