#include <iostream>
#include <vector>

const int MAX = 100001;
// 인접한 리스트 그래프를 표현
// 각 배열 요소는 정점의 번호를 나타낸다. 
// 예를 들어, graph[1]은 1번 정점과 연결된 정점들을 저장한다.
// graph[2]는 2번 정점과 연결된 정점들을 저장하는 식이다.
// 이러한 구조를 사용하면 그래프를 표현할 수 있다.
// 이 그래프는 무방향성을 가지고 있으며, 각 정점은 연결된 모든 이웃 정점을 갖는 방향성이 없는 형태의 관계를 나타낸다.
// 문제에서는 부모 노드를 찾아야 하기 때문에, 부모 노드를 찾아 나가기 위해 그래프를 이용하여 DFS(Depth - First Search)를 수행한다.
// DFS는 재귀적으로 모든 연결된 노드를 방문하고 그 순서대로 부모 노드를 결정하는데, 
// 그 과정에서 graph 배열을 사용하여 각 정점과 이어진 다른 정점을 효율적으로 관리한다.
std::vector<int> GRAPH[MAX];
// 각 노드의 부모 노드를 저장
// 문제에서는 루트 노드가 1로 고정되어 있으므로 1을 제외한 모든 노드에 대해 해당 노드의 부모 노드를 저장한다.
// 여기서 parent[i]는 i번 노드의 부모 노드를 저장한다.
// 이는 DFS(Depth - First Search) 과정에서 i번 노드를 방문할 때, 
// i번 노드와 연결된 다른 노드들을 탐색하면서 i번 노드의 부모 노드를 parent[i]에 저장한다.
// 이를 통해 각 노드의 부모 노드를 기억하여 그래프의 트리 구조를 생성하게 된다.
int PARENT[MAX];

void DFS(int node)
{
	for (int i = 0; i < GRAPH[node].size(); i++)
	{	// 현재 노드에서 i번째 자식 노드를 next변수에 할당
		int next = GRAPH[node][i];
		// 자식 노드에게 부모 노드가 없을 경우
		if (PARENT[next] == 0)
		{	// 부모 노드를 지정해 주고 재귀 호출을 하여 다음 노드를 탐색
			PARENT[next] = node;
			DFS(next);
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
	DFS(1);
	for (int i = 2; i <= N; i++)
	{
		std::cout << PARENT[i] << '\n';
	}
}