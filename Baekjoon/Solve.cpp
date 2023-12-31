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

//#include <iostream>
//#include <vector>
//#include <cstring>
//
//const int MAX = 10001;
//
//std::vector<std::pair<int, int>> TREE[MAX];	// 트리를 저장할 벡터
//bool VISITED[MAX]; // 방문 여부를 저장할 배열
//int LENGTH; // 트리의 지름을 저장할 변수
//int BEST; // 가장 먼 노드를 저장할 변수
//
//void DFS(int node, int weight) // DFS로 트리의 지름을 찾는 함수
//{
//	VISITED[node] = true; // 현재 노드를 방문 처리
//
//	for (auto& edge : TREE[node]) // 현재 노드와 연결된 간선을 확인
//	{
//		int nextNode = edge.first;
//		int nextWeight = edge.second;
//
//		if (!VISITED[nextNode]) // 다음 노드를 방문하지 않았다면 재귀 호출
//		{
//			DFS(nextNode, weight + nextWeight);
//		}
//	}
//	if (weight > LENGTH) // 현재 노드에서 가장 먼 노드를 찾아 지름 갱신
//	{
//		LENGTH = weight;
//		BEST = node;
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
//		int parent, child, weight;
//		std::cin >> parent >> child >> weight;
//
//		TREE[parent].push_back({ child, weight });
//		TREE[child].push_back({ parent, weight });
//	}
//
//	DFS(1, 0); // 임의의 노드(1번 노드)에서 가장 먼 노드 찾기
//
//	std::memset(VISITED, false, sizeof(VISITED)); // 초기화
//	LENGTH = 0;
//
//	DFS(BEST, 0); // 가장 먼 노드에서 다시 가장 먼 노드 찾기
//
//	std::cout << LENGTH << '\n';
//}

/*
트리 순회 1991번

문제
이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.

예를 들어 위와 같은 이진 트리가 입력되면,

전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)
가 된다.

입력
첫째 줄에는 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)이 주어진다. 
둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 
노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 자식 노드가 없는 경우에는 .으로 표현한다.

출력
첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 
각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.

예제 입력 1			예제 출력 1
7					ABDCEFG
A B C				DBAECFG
B D .				DBEGFCA
C E F
E . .
F . G
D . .
G . .
*/

//#include <iostream>
//
//// 1. 가장 먼저 노드를 구성한다.
//struct Node
//{
//	char data;
//	Node* left;
//	Node* right;
//
//	Node(char d) : data(d), left(nullptr), right(nullptr) {}
//};
//
//// 2. 전위 순회 함수를 만든다.
//void PreOrder(Node* root)
//{
//	// 1. 널값이 아니라면
//	if (root)
//	{	// 2. 자기 자신 -> 왼쪽 -> 오른쪽 순으로 출력
//		std::cout << root->data;
//		PreOrder(root->left);
//		PreOrder(root->right);
//	}
//}
//
//// 3. 중위 순회 함수를 만든다.
//void InOrder(Node* root)
//{
//	// 1. 널값이 아니라면
//	if (root)
//	{	// 2. 왼쪽 -> 자기 자신 -> 오른쪽 순으로 출력
//		InOrder(root->left);
//		std::cout << root->data;
//		InOrder(root->right);
//	}
//}
//
//// 4. 후위 순회 함수를 만든다.
//void PostOrder(Node* root)
//{
//	// 1. 널값이 아니라면
//	if (root)
//	{
//		PostOrder(root->left);
//		PostOrder(root->right);
//		std::cout << root->data;
//	}
//}

/* ----- < 트리( TREE ) > ----- */

/*
Level 0							A			-( 출발지점 : root )
Level 1						B		C		-( parent node )
Level 2					D		E		G	-( child node )
Level 3				H		I				-( leaf node )

< 기본 원칙 >
	#. 트리의 원소를 노드( node )라고 부른다.
	#. 부모 노드와 자식 노드의 관계는 어떤 원소를 가리키냐에 따라, 그때 그때 다르다.
	#. 같은 레벨에 있는, 같은 부모를 갖는 노드들간의 관계를 sibling 관계라고 한다.
	#. 하나의 트리에는 오직 하나의 root node 만 존재한다.
	#. 두 node 를 연결하는 경로는 단 하나 뿐이다.
*/

/* --- < Binary Tree > --- */

/*
< Binary Tree > : 최대 2개의 자식을 가질 수 있는 트리를 말한다.
	#. < Full Binary Tree > : 자식이 있는 노드가 반드시 두 개의 자식을 가지고 있다.
	#. < Perfect Binary Tree > : 모든 노드가 두 개의 자식을 가지고 있다.
	#. < Complete Binary Tree > : 마지막 레벨을 제외한 모든 레벨의 노드가 있고, 추가될 때는 왼쪽부터 채운다.
*/

//#include <iostream>
//#include <stack>
//#include <queue>
//
//namespace MyTree
//{
//	struct Node
//	{
//		int mData;
//		Node* mLeft;
//		Node* mRight;
//
//		Node(int data, Node* pLeft, Node* pRight) : mData{ data }, mLeft{ pLeft }, mRight{ pRight }{}
//	};
//
//	class BinaryTree
//	{
//	private:
//		Node* mpRoot;
//
//	public:
//		BinaryTree()
//		{
//			mpRoot = CreateNode(0);
//		}
//
//		Node* CreateNode(int data)
//		{
//			return new Node(data, nullptr, nullptr);
//		}
//
//		Node* GetRoot() { return mpRoot; }
//
//		Node* InsertLeft(Node* parent, int data)
//		{
//			parent->mLeft = CreateNode(data);
//			return parent->mLeft;
//		}
//
//		Node* InsertRight(Node* parent, int data)
//		{
//			parent->mRight = CreateNode(data);
//			return parent->mRight;
//		}
//
//	public:
//		void Visit(Node* node) { std::cout << node->mData << "-> "; }
//
//		void DepthFirst()
//		{
//			std::stack<Node*> stack;
//			stack.push(GetRoot());
//
//			while (!stack.empty())
//			{
//				auto node = stack.top();
//				Visit(node);
//				stack.pop();
//				if (node->mRight != nullptr)
//				{
//					stack.push(node->mRight);
//				}
//				if (node->mLeft != nullptr)
//				{
//					stack.push(node->mLeft);
//				}
//			}
//		}
//
//		void BreadthFirst()
//		{
//			std::queue<Node*> queue;
//			queue.push(GetRoot());
//
//			while (!queue.empty())
//			{
//				auto node = queue.front();
//
//				Visit(node);
//				queue.pop();
//				if (node->mLeft != nullptr)
//				{
//					queue.push(node->mLeft);
//				}
//				if (node->mRight != nullptr)
//				{
//					queue.push(node->mRight);
//				}
//			}
//		}
//
//		void Pre_Order(Node* pNode)
//		{
//			if (pNode == nullptr)
//			{
//				return;
//			}
//
//			Visit(pNode);
//			Pre_Order(pNode->mLeft);
//			Pre_Order(pNode->mRight);
//		}
//
//		void In_Order(Node* pNode)
//		{
//			if (pNode == nullptr)
//			{
//				return;
//			}
//
//			In_Order(pNode->mLeft);
//			Visit(pNode);
//			In_Order(pNode->mRight);
//		}
//
//		void Post_Order(Node* pNode)
//		{
//			if (pNode == nullptr)
//			{
//				return;
//			}
//
//			Post_Order(pNode->mLeft);
//			Post_Order(pNode->mRight);
//			Visit(pNode);
//		}
//
//		public:
//			int Sum(Node* pNode)
//			{
//				if (pNode == nullptr)
//				{
//					return 0;
//				}
//
//				return Sum(pNode->mLeft) + pNode->mData + Sum(pNode->mRight);
//			}
//
//			bool Search(Node* pNode, int value)
//			{
//				if (pNode == nullptr)
//				{
//					return false;
//				}
//
//				return Search(pNode->mLeft, value) || pNode->mData == value || Search(pNode->mRight, value);
//			}
//	};
//}
//
//int main()
//{
//	MyTree::BinaryTree myTree;
//
//	auto pRoot = myTree.GetRoot();
//	pRoot->mData = 1;
//
//	auto pNode = myTree.InsertLeft(pRoot, 2);
//	myTree.InsertLeft(pNode, 4);
//	myTree.InsertRight(pNode, 5);
//
//	pNode = myTree.InsertRight(pRoot, 3);
//	myTree.InsertLeft(pNode, 6);
//	myTree.InsertRight(pNode, 7);
//}

/* --- < Bubble sort > --- */

/*
서로 인접한 두 원소를 비교, 크기에 따라 서로 스왑한다.
선택 정렬과 기본 개념이 유사하다.
버블 정렬(bubble sort) 알고리즘의 구체적인 개념
첫 번째 원소와 두 번째 원소를, 두 번째 원소와 세 번째 원소를, 세 번째와 네 번째를, … 이런 식으로 (마지막 - 1)번째 원소와 마지막 원소를 비교하여 스왑하면서 원소를 정렬한다.
1회차 순환을 하고 나면 가장 큰 자료가 맨 뒤로 이동하므로 2회차 순환에서는 맨 끝에 있는 원소는 정렬에서 제외되고, 2회차 순환을 수행하고 나면 끝에서 두 번째 원소까지는 정렬에서 제외된다. 
이렇게 정렬을 순환할 때마다 정렬에서 제외되는 데이터가 하나씩 늘어난다.
*/

//#include <iostream>
//
//void BubbleSort(int list[], int N)
//{
//	int i, j, temp;
//
//	for (i = N - 1; i > 0; i--)	// 반복할 가이드 라인( 0 ~ N - 1 까지의 원소를 순회 )
//	{
//		for (j = 0; j < i; j++)	// j가 i(가이드 라인)를 넘어가지 않을 때 까지 반복
//		{
//			if (list[j] < list[j + 1])	// 순회를 하며 인접해 있는 원소를 비교
//			{
//				temp = list[j];
//				list[j] = list[j + 1];
//				list[j + 1] = temp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[5] = { 6,3,2,7,1 };
//
//	BubbleSort(arr, 5);
//
//	for (int i = 0; i < 5; i++) std::cout << arr[i] << '\n';
//}