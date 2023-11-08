/*
트리의 부모 찾기 11725번

문제
루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.

출력
첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.

예제 입력 1			예제 출력 1
7					
1 6					4
6 3					6
3 5					1
4 1					3
2 4					1
4 7					4
*/

#include <iostream>
#include <vector>

const int MAX = 100001;

// 1. 정수형 벡터 타입의 배열 GRAPH를 MAX 만큼 크기를 할당한다.
//		=> 인접한 리스트로 그래프를 표현한다.
std::vector<int> GRAPH[MAX];
// 2. 각 노드의 부모 노드를 저장한다.
int PARENT[MAX];

void Dfs(int node)
{
	for (int i = 0; i < GRAPH[node].size(); i++)
	{
		// 3. 현재 노드에서 i번째 자식 노드를 next변수에 할당한다.
		int next = GRAPH[node][i];
		// 4. 자식 노드에게 부모 노드가 없을 경우
		if (PARENT[next] == 0)
		{
			// 5. 현재 노드를 부모로 지정한다.
			PARENT[next] = node;
			// 6. 재귀 호출을 하여 다음 노드를 탐색한다.
			Dfs(next);
		}
	}
}

int main()
{
	int N;
	std::cin >> N;

	for (int i = 1; i < N; i++)
	{
		int A, B;
		std::cin >> A >> B;
		GRAPH[A].push_back(B);
		GRAPH[B].push_back(A);
	}

	PARENT[1] = 1;

	Dfs(1);

	for (int i = 2; i <= N; i++)
	{
		std::cout << PARENT[i] << '\n';
	}
}