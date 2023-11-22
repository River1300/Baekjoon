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

//#include <iostream>
//#include <vector>
//
//const int MAX = 100001;
//
//// 1. 정수형 벡터 타입의 배열 GRAPH를 MAX 만큼 크기를 할당한다.
////		=> 인접한 리스트로 그래프를 표현한다.
//std::vector<int> GRAPH[MAX];
//// 2. 각 노드의 부모 노드를 저장한다.
//int PARENT[MAX];
//
//void Dfs(int node)
//{
//	for (int i = 0; i < GRAPH[node].size(); i++)
//	{
//		// 3. 현재 노드에서 i번째 자식 노드를 next변수에 할당한다.
//		int next = GRAPH[node][i];
//		// 4. 자식 노드에게 부모 노드가 없을 경우
//		if (PARENT[next] == 0)
//		{
//			// 5. 현재 노드를 부모로 지정한다.
//			PARENT[next] = node;
//			// 6. 재귀 호출을 하여 다음 노드를 탐색한다.
//			Dfs(next);
//		}
//	}
//}
//
//int main()
//{
//	int N;
//	std::cin >> N;
//
//	for (int i = 1; i < N; i++)
//	{
//		int A, B;
//		std::cin >> A >> B;
//		GRAPH[A].push_back(B);
//		GRAPH[B].push_back(A);
//	}
//
//	PARENT[1] = 1;
//
//	Dfs(1);
//
//	for (int i = 2; i <= N; i++)
//	{
//		std::cout << PARENT[i] << '\n';
//	}
//}

/*
트리의 지름 1167번

문제
트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다. 트리의 지름을 구하는 프로그램을 작성하시오.

입력
트리가 입력으로 주어진다. 
먼저 첫 번째 줄에서는 트리의 정점의 개수 V가 주어지고 (2 ≤ V ≤ 100,000)
둘째 줄부터 V개의 줄에 걸쳐 간선의 정보가 다음과 같이 주어진다. 
정점 번호는 1부터 V까지 매겨져 있다.
먼저 정점 번호가 주어지고, 이어서 연결된 간선의 정보를 의미하는 정수가 두 개씩 주어지는데, 
하나는 정점번호, 다른 하나는 그 정점까지의 거리이다. 
예를 들어 네 번째 줄의 경우 정점 3은 정점 1과 거리가 2인 간선으로 연결되어 있고, 
정점 4와는 거리가 3인 간선으로 연결되어 있는 것을 보여준다. 
각 줄의 마지막에는 -1이 입력으로 주어진다. 
주어지는 거리는 모두 10,000 이하의 자연수이다.

출력
첫째 줄에 트리의 지름을 출력한다.

예제 입력				예제 출력 1
5						11
1 3 2 -1
2 4 4 -1
3 1 2 4 3 -1
4 2 4 3 3 5 6 -1
5 4 6 -1
*/

//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <algorithm>
//
//const int MAX = 100001;
//
//// 1. 각 노드의 연결 정보와 가중치를 저장
//std::vector<std::pair<int, int>> TREE[MAX];
//// 2. 방문 여부를 저장
//bool VISITED[MAX];
//// 3. 트리의 지름
//int DIAMETER = 0;
//
//int DFS(int node)
//{
//	VISITED[node] = true;
//	// 4. 각 자식 노드들의 깊이를 저장
//	std::vector<int> depths;
//
//	for (auto& edge : TREE[node])
//	{
//		int next = edge.first;
//		int weight = edge.second;
//
//		if (!VISITED[next])
//		{
//			depths.push_back(DFS(next) + weight);
//		}
//	}
//
//	int size = depths.size();
//	if (size == 0) return 0;
//	// 5. 자식 노드들의 깊이를 내립차순으로 정렬
//	std::sort(depths.begin(), depths.end(), std::greater<int>());
//
//	// 6. 트리의 지름 갱신
//	if (size == 1)
//	{
//		DIAMETER = std::max(DIAMETER, depths[0]);
//	}
//	else
//	{
//		DIAMETER = std::max(DIAMETER, depths[0] + depths[1]);
//	}
//
//	// 7. 해당 노드의 깊이는 가장 깊은 자식 노드의 깊이와 현재 노드의 가중치를 합한 값
//	return depths[0];
//}
//
//int main()
//{
//	int V;
//	std::cin >> V;
//
//	for (int i = 0; i < V; i++)
//	{
//		int node;
//		std::cin >> node;
//
//		int vertex, weight;
//		while (true)
//		{
//			std::cin >> vertex;
//			if (vertex == -1) break;
//
//			std::cin >> weight;
//			TREE[node].emplace_back(vertex, weight);
//		}
//	}
//
//	DFS(1);
//
//	std::cout << DIAMETER << '\n';
//}

/*
트리의 지름 1967번

문제
트리(tree)는 사이클이 없는 무방향 그래프이다. 
트리에서는 어떤 두 노드를 선택해도 둘 사이에 경로가 항상 하나만 존재하게 된다. 
트리에서 어떤 두 노드를 선택해서 양쪽으로 쫙 당길 때, 가장 길게 늘어나는 경우가 있을 것이다. 
이럴 때 트리의 모든 노드들은 이 두 노드를 지름의 끝 점으로 하는 원 안에 들어가게 된다.
이런 두 노드 사이의 경로의 길이를 트리의 지름이라고 한다. 
정확히 정의하자면 트리에 존재하는 모든 경로들 중에서 가장 긴 것의 길이를 말한다.
입력으로 루트가 있는 트리를 가중치가 있는 간선들로 줄 때, 트리의 지름을 구해서 출력하는 프로그램을 작성하시오. 
아래와 같은 트리가 주어진다면 트리의 지름은 45가 된다.
트리의 노드는 1부터 n까지 번호가 매겨져 있다.

입력
파일의 첫 번째 줄은 노드의 개수 n(1 ≤ n ≤ 10,000)이다. 
둘째 줄부터 n-1개의 줄에 각 간선에 대한 정보가 들어온다. 
간선에 대한 정보는 세 개의 정수로 이루어져 있다. 
첫 번째 정수는 간선이 연결하는 두 노드 중 부모 노드의 번호를 나타내고, 두 번째 정수는 자식 노드를, 세 번째 정수는 간선의 가중치를 나타낸다. 
간선에 대한 정보는 부모 노드의 번호가 작은 것이 먼저 입력되고, 부모 노드의 번호가 같으면 자식 노드의 번호가 작은 것이 먼저 입력된다. 
루트 노드의 번호는 항상 1이라고 가정하며, 간선의 가중치는 100보다 크지 않은 양의 정수이다.

출력
첫째 줄에 트리의 지름을 출력한다.

예제 입력			예제 출력
12					45
1 2 3
1 3 2
2 4 5
3 5 11
3 6 9
4 7 1
4 8 7
5 9 15
5 10 4
6 11 6
6 12 10
*/

#include <iostream>
#include <vector>
#include <cstring>

const int MAX = 10001;

std::vector<std::pair<int, int>> TREE[MAX];	// 트리를 저장할 벡터
bool VISITED[MAX]; // 방문 여부를 저장할 배열
int LENGTH; // 트리의 지름을 저장할 변수
int BEST; // 가장 먼 노드를 저장할 변수

void DFS(int node, int weight) // DFS로 트리의 지름을 찾는 함수
{
	VISITED[node] = true; // 현재 노드를 방문 처리

	for (auto& edge : TREE[node]) // 현재 노드와 연결된 간선을 확인
	{
		int nextNode = edge.first;
		int nextWeight = edge.second;

		if (!VISITED[nextNode]) // 다음 노드를 방문하지 않았다면 재귀 호출
		{
			DFS(nextNode, weight + nextWeight);
		}
	}
	if (weight > LENGTH) // 현재 노드에서 가장 먼 노드를 찾아 지름 갱신
	{
		LENGTH = weight;
		BEST = node;
	}
}

int main()
{
	int N;
	std::cin >> N;

	for (int i = 1; i < N; i++)
	{
		int parent, child, weight;
		std::cin >> parent >> child >> weight;

		TREE[parent].push_back({ child, weight });
		TREE[child].push_back({ parent, weight });
	}

	DFS(1, 0); // 임의의 노드(1번 노드)에서 가장 먼 노드 찾기

	std::memset(VISITED, false, sizeof(VISITED)); // 초기화
	LENGTH = 0;

	DFS(BEST, 0); // 가장 먼 노드에서 다시 가장 먼 노드 찾기

	std::cout << LENGTH << '\n';
}