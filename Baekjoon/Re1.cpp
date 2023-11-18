//#include <iostream>
//#include <vector>
//
//const int MAX = 100001;
//// 인접한 리스트 그래프를 표현
//// 각 배열 요소는 정점의 번호를 나타낸다. 
//// 예를 들어, graph[1]은 1번 정점과 연결된 정점들을 저장한다.
//// graph[2]는 2번 정점과 연결된 정점들을 저장하는 식이다.
//// 이러한 구조를 사용하면 그래프를 표현할 수 있다.
//// 이 그래프는 무방향성을 가지고 있으며, 각 정점은 연결된 모든 이웃 정점을 갖는 방향성이 없는 형태의 관계를 나타낸다.
//// 문제에서는 부모 노드를 찾아야 하기 때문에, 부모 노드를 찾아 나가기 위해 그래프를 이용하여 DFS(Depth - First Search)를 수행한다.
//// DFS는 재귀적으로 모든 연결된 노드를 방문하고 그 순서대로 부모 노드를 결정하는데, 
//// 그 과정에서 graph 배열을 사용하여 각 정점과 이어진 다른 정점을 효율적으로 관리한다.
//std::vector<int> GRAPH[MAX];
//// 각 노드의 부모 노드를 저장
//// 문제에서는 루트 노드가 1로 고정되어 있으므로 1을 제외한 모든 노드에 대해 해당 노드의 부모 노드를 저장한다.
//// 여기서 parent[i]는 i번 노드의 부모 노드를 저장한다.
//// 이는 DFS(Depth - First Search) 과정에서 i번 노드를 방문할 때, 
//// i번 노드와 연결된 다른 노드들을 탐색하면서 i번 노드의 부모 노드를 parent[i]에 저장한다.
//// 이를 통해 각 노드의 부모 노드를 기억하여 그래프의 트리 구조를 생성하게 된다.
//int PARENT[MAX];
//
//void DFS(int node)
//{
//	for (int i = 0; i < GRAPH[node].size(); i++)
//	{	// 현재 노드에서 i번째 자식 노드를 next변수에 할당
//		int next = GRAPH[node][i];
//		// 자식 노드에게 부모 노드가 없을 경우
//		if (PARENT[next] == 0)
//		{	// 부모 노드를 지정해 주고 재귀 호출을 하여 다음 노드를 탐색
//			PARENT[next] = node;
//			DFS(next);
//		}
//	}
//}
//int main()
//{
//	int N;
//	std::cin >> N;
//	for (int i = 1; i < N; i++)
//	{
//		int A, B;
//		std::cin >> A >> B;
//		GRAPH[A].push_back(B);
//		GRAPH[B].push_back(A);
//	}
//	PARENT[1] = 1;
//	DFS(1);
//	for (int i = 2; i <= N; i++)
//	{
//		std::cout << PARENT[i] << '\n';
//	}
//}

/*
1. 트리 ( Tree ) :
	트리는 그래프의 한 종류로, 사이클이 없는 연결된 무방향 그래프를 말한다.
	각 노드 간에는 정확히 하나의 경로가 존재하며, 루트( root ) 노드에서 다른 모든 노드로의 경로가 연결된다.
2. 트리의 지름 ( Diameter of a Tree ) :
	트리의 지름은 트리 내의 두 노드 간의 가장 긴 경로의 길이를 의미한다.
	특정 두 노드 사이의 거리 중 가장 긴 거리를 찾는 것이라 보면 된다.
*/

/*
1. 트리 구성 :
	주어진 입력을 통해 트리를 구성한다. 
	각 노드에 원소값 = 다른 노드와 그 노드와의 거리
2. DFS ( 깊이 우선 탐색 ) :
	트리의 지름을 찾기 위해 DFS 알고리즘을 사용한다.
	임의의 노드에서 시작하여 가장 먼 노드를 찾는 것이 목표다.

	첫 번째 : 임의의 노드에서 시작하여 DFS를 사용해 가장 먼 노드( A )를 찾는다.
	두 번째 : A에서 다시 DFS를 사용해 가장 먼 노드( B )를 찾는다.

	각 노드에서 제일 멀리있는 노드 까지 가는 길을 따라가 보면 항상 일부가 겹친다. 
	노드 간의 거리를 기준으로 경로를 결정하기 때문에 가장 긴 노드 거리는 결국 
	A 노드에서 가장 먼 거리에 있는 B 노드,
	B 노드에서 가장 먼 거리에 있는 A 노드의 경로가 겹칠 수 밖에 없다. 

	그러므로 모든 노드에서 부터의 가장 긴 경로에는 항상 가장 먼 경로인 A 이나 B 를 포함할 수 밖에 없다.

3. DFS 함수 :
	DFS( node ) 함수는 특정 노드에서 시작하여 해당 노드로부터 가장 먼 노드까지의 거리를 반환한다.
	이때, 방문한 노드는 visited 배열을 통해 표시한다.
	재귀적으로 자식 노드들을 탐색하면서 각 노드로부터의 거리를 계산하고, 가장 먼 거리를 업데이트한다.

4. 트리의 지름 구하기 :
	모든 노드에서 DFS를 수행하여 각 노드로부터 가장 먼 노드까지의 거리를 계산한다.
	이 중 가장 긴 거리를 트리가 지름이다.
*/

//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <algorithm>
//
//const int MAX = 100001;
//
//std::vector<std::pair<int, int>> TREE[MAX];
//bool VISITED[MAX];
//int RANGE;
//
//int DFS(int node)
//{
//	VISITED[node] = true;
//	std::vector<int> depths;
//
//	for (auto& edge : TREE[node])
//	{
//		int next = edge.first;
//		int length = edge.second;
//
//		if (!VISITED[next]) depths.push_back(DFS(next) + length);
//	}
//
//	int size = depths.size();
//	if (size == 0) return;
//	std::sort(depths.begin(), depths.end(), std::greater<int>());
//
//	if (size == 1)
//	{
//		RANGE = std::max(RANGE, depths[0]);
//	}
//	else
//	{
//		RANGE = std::max(RANGE, depths[0] + depths[1]);
//	}
//
//	return depths[0];
//}
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
//
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
//	std::cout << RANGE << '\n';
//}