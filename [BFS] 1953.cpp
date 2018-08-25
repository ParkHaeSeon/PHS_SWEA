#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int map[51][51] = { 0, };

bool visit[51][51] = { false, };

int R = 0, C = 0, L = 0;
int N = 0, M = 0, T = 0;


int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0 , 1 };
int dir[4] = { 0, 1, 2, 3 };
//			   ↑ ← ↓ →

bool go(int before, int after, int d)
{
	if (d == 0) // 위로 이동할 때
	{
		if (before == 3 || before == 5 || before == 6)
		{
			return false;
		}
		else
		{
			if (after == 1 || after == 2 || after == 5 || after == 6)
			{
				return true;
			}
		}

		return false;
	}
	else if (d == 1) // 왼쪽으로 이동할 때
	{
		if (before == 2 || before == 4 || before == 5)
		{
			return false;
		}
		else
		{
			if (after == 1 || after == 3 || after == 4 || after == 5)
			{
				return true;
			}
		}

		return false;
	}
	else if (d == 2) // 아래로 이동할 때
	{
		if (before == 3 || before == 4 || before == 7)
		{
			return false;
		}
		else
		{
			if (after == 1 || after == 2 || after == 4 || after == 7)
			{
				return true;
			}
		}

		return false;
	}
	else if (d == 3) // 오른쪽으로 이동할 때
	{
		if (before == 2 || before == 6 || before == 7)
		{
			return false;
		}
		else
		{
			if (after == 1 || after == 3 || after == 6 || after == 7)
			{
				return true;
			}
		}

		return false;
	}
}

void BFS(int r, int c)
{
	queue<pair<int, int> > q;

	q.push({ r, c });

	visit[r][c] = true;

	int thread = 0;

	while (!q.empty())
	{
		int qSize = q.size();

		while (qSize--)
		{
			int y = q.front().first;
			int x = q.front().second;

			q.pop();

			if (thread >= L - 1) return;

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				int direction = dir[i];

				if (0 <= ny && ny < N && 0 <= nx && nx < M && !visit[ny][nx] && map[ny][nx] != 0 && go(map[y][x], map[ny][nx], direction))
				{
					visit[ny][nx] = true;
					
					q.push({ ny, nx });
				}
			}
		}		

		++thread;
		
		// 내가 틀린 이유
		// if (thread >= L - 1) return;
	}
}

int getCount()
{
	int ret = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j])
			{
				++ret;
			}
		}
	}

	return ret;
}

int main(void)
{
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		memset(visit, false, sizeof(visit));

		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		BFS(R, C);
		
		printf("#%d %d\n", tc, getCount());
	}

	return 0;
}