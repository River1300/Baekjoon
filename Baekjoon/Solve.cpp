/*
Ʈ���� �θ� ã�� 11725��

����
��Ʈ ���� Ʈ���� �־�����. �̶�, Ʈ���� ��Ʈ�� 1�̶�� ������ ��, �� ����� �θ� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ����� ���� N (2 �� N �� 100,000)�� �־�����. ��° �ٺ��� N-1���� �ٿ� Ʈ�� �󿡼� ����� �� ������ �־�����.

���
ù° �ٺ��� N-1���� �ٿ� �� ����� �θ� ��� ��ȣ�� 2�� ������ ������� ����Ѵ�.

���� �Է� 1			���� ��� 1
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
//// 1. ������ ���� Ÿ���� �迭 GRAPH�� MAX ��ŭ ũ�⸦ �Ҵ��Ѵ�.
////		=> ������ ����Ʈ�� �׷����� ǥ���Ѵ�.
//std::vector<int> GRAPH[MAX];
//// 2. �� ����� �θ� ��带 �����Ѵ�.
//int PARENT[MAX];
//
//void Dfs(int node)
//{
//	for (int i = 0; i < GRAPH[node].size(); i++)
//	{
//		// 3. ���� ��忡�� i��° �ڽ� ��带 next������ �Ҵ��Ѵ�.
//		int next = GRAPH[node][i];
//		// 4. �ڽ� ��忡�� �θ� ��尡 ���� ���
//		if (PARENT[next] == 0)
//		{
//			// 5. ���� ��带 �θ�� �����Ѵ�.
//			PARENT[next] = node;
//			// 6. ��� ȣ���� �Ͽ� ���� ��带 Ž���Ѵ�.
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
Ʈ���� ���� 1167��

����
Ʈ���� �����̶�, Ʈ������ ������ �� �� ������ �Ÿ� �� ���� �� ���� ���Ѵ�. Ʈ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
Ʈ���� �Է����� �־�����. 
���� ù ��° �ٿ����� Ʈ���� ������ ���� V�� �־����� (2 �� V �� 100,000)
��° �ٺ��� V���� �ٿ� ���� ������ ������ ������ ���� �־�����. 
���� ��ȣ�� 1���� V���� �Ű��� �ִ�.
���� ���� ��ȣ�� �־�����, �̾ ����� ������ ������ �ǹ��ϴ� ������ �� ���� �־����µ�, 
�ϳ��� ������ȣ, �ٸ� �ϳ��� �� ���������� �Ÿ��̴�. 
���� ��� �� ��° ���� ��� ���� 3�� ���� 1�� �Ÿ��� 2�� �������� ����Ǿ� �ְ�, 
���� 4�ʹ� �Ÿ��� 3�� �������� ����Ǿ� �ִ� ���� �����ش�. 
�� ���� ���������� -1�� �Է����� �־�����. 
�־����� �Ÿ��� ��� 10,000 ������ �ڿ����̴�.

���
ù° �ٿ� Ʈ���� ������ ����Ѵ�.

���� �Է�				���� ��� 1
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
//// 1. �� ����� ���� ������ ����ġ�� ����
//std::vector<std::pair<int, int>> TREE[MAX];
//// 2. �湮 ���θ� ����
//bool VISITED[MAX];
//// 3. Ʈ���� ����
//int DIAMETER = 0;
//
//int DFS(int node)
//{
//	VISITED[node] = true;
//	// 4. �� �ڽ� ������ ���̸� ����
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
//	// 5. �ڽ� ������ ���̸� ������������ ����
//	std::sort(depths.begin(), depths.end(), std::greater<int>());
//
//	// 6. Ʈ���� ���� ����
//	if (size == 1)
//	{
//		DIAMETER = std::max(DIAMETER, depths[0]);
//	}
//	else
//	{
//		DIAMETER = std::max(DIAMETER, depths[0] + depths[1]);
//	}
//
//	// 7. �ش� ����� ���̴� ���� ���� �ڽ� ����� ���̿� ���� ����� ����ġ�� ���� ��
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
Ʈ���� ���� 1967��

����
Ʈ��(tree)�� ����Ŭ�� ���� ������ �׷����̴�. 
Ʈ�������� � �� ��带 �����ص� �� ���̿� ��ΰ� �׻� �ϳ��� �����ϰ� �ȴ�. 
Ʈ������ � �� ��带 �����ؼ� �������� �� ��� ��, ���� ��� �þ�� ��찡 ���� ���̴�. 
�̷� �� Ʈ���� ��� ������ �� �� ��带 ������ �� ������ �ϴ� �� �ȿ� ���� �ȴ�.
�̷� �� ��� ������ ����� ���̸� Ʈ���� �����̶�� �Ѵ�. 
��Ȯ�� �������ڸ� Ʈ���� �����ϴ� ��� ��ε� �߿��� ���� �� ���� ���̸� ���Ѵ�.
�Է����� ��Ʈ�� �ִ� Ʈ���� ����ġ�� �ִ� ������� �� ��, Ʈ���� ������ ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
�Ʒ��� ���� Ʈ���� �־����ٸ� Ʈ���� ������ 45�� �ȴ�.
Ʈ���� ���� 1���� n���� ��ȣ�� �Ű��� �ִ�.

�Է�
������ ù ��° ���� ����� ���� n(1 �� n �� 10,000)�̴�. 
��° �ٺ��� n-1���� �ٿ� �� ������ ���� ������ ���´�. 
������ ���� ������ �� ���� ������ �̷���� �ִ�. 
ù ��° ������ ������ �����ϴ� �� ��� �� �θ� ����� ��ȣ�� ��Ÿ����, �� ��° ������ �ڽ� ��带, �� ��° ������ ������ ����ġ�� ��Ÿ����. 
������ ���� ������ �θ� ����� ��ȣ�� ���� ���� ���� �Էµǰ�, �θ� ����� ��ȣ�� ������ �ڽ� ����� ��ȣ�� ���� ���� ���� �Էµȴ�. 
��Ʈ ����� ��ȣ�� �׻� 1�̶�� �����ϸ�, ������ ����ġ�� 100���� ũ�� ���� ���� �����̴�.

���
ù° �ٿ� Ʈ���� ������ ����Ѵ�.

���� �Է�			���� ���
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
//std::vector<std::pair<int, int>> TREE[MAX];	// Ʈ���� ������ ����
//bool VISITED[MAX]; // �湮 ���θ� ������ �迭
//int LENGTH; // Ʈ���� ������ ������ ����
//int BEST; // ���� �� ��带 ������ ����
//
//void DFS(int node, int weight) // DFS�� Ʈ���� ������ ã�� �Լ�
//{
//	VISITED[node] = true; // ���� ��带 �湮 ó��
//
//	for (auto& edge : TREE[node]) // ���� ���� ����� ������ Ȯ��
//	{
//		int nextNode = edge.first;
//		int nextWeight = edge.second;
//
//		if (!VISITED[nextNode]) // ���� ��带 �湮���� �ʾҴٸ� ��� ȣ��
//		{
//			DFS(nextNode, weight + nextWeight);
//		}
//	}
//	if (weight > LENGTH) // ���� ��忡�� ���� �� ��带 ã�� ���� ����
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
//	DFS(1, 0); // ������ ���(1�� ���)���� ���� �� ��� ã��
//
//	std::memset(VISITED, false, sizeof(VISITED)); // �ʱ�ȭ
//	LENGTH = 0;
//
//	DFS(BEST, 0); // ���� �� ��忡�� �ٽ� ���� �� ��� ã��
//
//	std::cout << LENGTH << '\n';
//}

/*
Ʈ�� ��ȸ 1991��

����
���� Ʈ���� �Է¹޾� ���� ��ȸ(preorder traversal), ���� ��ȸ(inorder traversal), ���� ��ȸ(postorder traversal)�� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ��� ���� ���� ���� Ʈ���� �ԷµǸ�,

���� ��ȸ�� ��� : ABDCEFG // (��Ʈ) (���� �ڽ�) (������ �ڽ�)
���� ��ȸ�� ��� : DBAECFG // (���� �ڽ�) (��Ʈ) (������ �ڽ�)
���� ��ȸ�� ��� : DBEGFCA // (���� �ڽ�) (������ �ڽ�) (��Ʈ)
�� �ȴ�.

�Է�
ù° �ٿ��� ���� Ʈ���� ����� ���� N(1 �� N �� 26)�� �־�����. 
��° �ٺ��� N���� �ٿ� ���� �� ���� ���� ���� �ڽ� ���, ������ �ڽ� ��尡 �־�����. 
����� �̸��� A���� ���ʴ�� ���ĺ� �빮�ڷ� �Ű�����, �׻� A�� ��Ʈ ��尡 �ȴ�. �ڽ� ��尡 ���� ��쿡�� .���� ǥ���Ѵ�.

���
ù° �ٿ� ���� ��ȸ, ��° �ٿ� ���� ��ȸ, ��° �ٿ� ���� ��ȸ�� ����� ����Ѵ�. 
�� �ٿ� N���� ���ĺ��� ���� ���� ����ϸ� �ȴ�.

���� �Է� 1			���� ��� 1
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
//// 1. ���� ���� ��带 �����Ѵ�.
//struct Node
//{
//	char data;
//	Node* left;
//	Node* right;
//
//	Node(char d) : data(d), left(nullptr), right(nullptr) {}
//};
//
//// 2. ���� ��ȸ �Լ��� �����.
//void PreOrder(Node* root)
//{
//	// 1. �ΰ��� �ƴ϶��
//	if (root)
//	{	// 2. �ڱ� �ڽ� -> ���� -> ������ ������ ���
//		std::cout << root->data;
//		PreOrder(root->left);
//		PreOrder(root->right);
//	}
//}
//
//// 3. ���� ��ȸ �Լ��� �����.
//void InOrder(Node* root)
//{
//	// 1. �ΰ��� �ƴ϶��
//	if (root)
//	{	// 2. ���� -> �ڱ� �ڽ� -> ������ ������ ���
//		InOrder(root->left);
//		std::cout << root->data;
//		InOrder(root->right);
//	}
//}
//
//// 4. ���� ��ȸ �Լ��� �����.
//void PostOrder(Node* root)
//{
//	// 1. �ΰ��� �ƴ϶��
//	if (root)
//	{
//		PostOrder(root->left);
//		PostOrder(root->right);
//		std::cout << root->data;
//	}
//}

/* ----- < Ʈ��( TREE ) > ----- */

/*
Level 0							A			-( ������� : root )
Level 1						B		C		-( parent node )
Level 2					D		E		G	-( child node )
Level 3				H		I				-( leaf node )

< �⺻ ��Ģ >
	#. Ʈ���� ���Ҹ� ���( node )��� �θ���.
	#. �θ� ���� �ڽ� ����� ����� � ���Ҹ� ����Ű�Ŀ� ����, �׶� �׶� �ٸ���.
	#. ���� ������ �ִ�, ���� �θ� ���� ���鰣�� ���踦 sibling ������ �Ѵ�.
	#. �ϳ��� Ʈ������ ���� �ϳ��� root node �� �����Ѵ�.
	#. �� node �� �����ϴ� ��δ� �� �ϳ� ���̴�.
*/

/* --- < Binary Tree > --- */

/*
< Binary Tree > : �ִ� 2���� �ڽ��� ���� �� �ִ� Ʈ���� ���Ѵ�.
	#. < Full Binary Tree > : �ڽ��� �ִ� ��尡 �ݵ�� �� ���� �ڽ��� ������ �ִ�.
	#. < Perfect Binary Tree > : ��� ��尡 �� ���� �ڽ��� ������ �ִ�.
	#. < Complete Binary Tree > : ������ ������ ������ ��� ������ ��尡 �ְ�, �߰��� ���� ���ʺ��� ä���.
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
���� ������ �� ���Ҹ� ��, ũ�⿡ ���� ���� �����Ѵ�.
���� ���İ� �⺻ ������ �����ϴ�.
���� ����(bubble sort) �˰����� ��ü���� ����
ù ��° ���ҿ� �� ��° ���Ҹ�, �� ��° ���ҿ� �� ��° ���Ҹ�, �� ��°�� �� ��°��, �� �̷� ������ (������ - 1)��° ���ҿ� ������ ���Ҹ� ���Ͽ� �����ϸ鼭 ���Ҹ� �����Ѵ�.
1ȸ�� ��ȯ�� �ϰ� ���� ���� ū �ڷᰡ �� �ڷ� �̵��ϹǷ� 2ȸ�� ��ȯ������ �� ���� �ִ� ���Ҵ� ���Ŀ��� ���ܵǰ�, 2ȸ�� ��ȯ�� �����ϰ� ���� ������ �� ��° ���ұ����� ���Ŀ��� ���ܵȴ�. 
�̷��� ������ ��ȯ�� ������ ���Ŀ��� ���ܵǴ� �����Ͱ� �ϳ��� �þ��.
*/

//#include <iostream>
//
//void BubbleSort(int list[], int N)
//{
//	int i, j, temp;
//
//	for (i = N - 1; i > 0; i--)	// �ݺ��� ���̵� ����( 0 ~ N - 1 ������ ���Ҹ� ��ȸ )
//	{
//		for (j = 0; j < i; j++)	// j�� i(���̵� ����)�� �Ѿ�� ���� �� ���� �ݺ�
//		{
//			if (list[j] < list[j + 1])	// ��ȸ�� �ϸ� ������ �ִ� ���Ҹ� ��
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

/* --- < Merge sort > --- */

/*
���� ����(divide and conquer) ���
������ ���� 2���� ������ �и��ϰ� ������ �ذ��� ����, ����� ��Ƽ� ������ ������ �ذ��ϴ� �����̴�.
���� ���� ����� �밳 ��ȯ ȣ���� �̿��Ͽ� �����Ѵ�.
�ϳ��� ����Ʈ�� �� ���� �յ��� ũ��� �����ϰ� ���ҵ� �κ� ����Ʈ�� ������ ����, 
�� ���� ���ĵ� �κ� ����Ʈ�� ���Ͽ� ��ü�� ���ĵ� ����Ʈ�� �ǰ� �ϴ� ����̴�.

����(Divide): �Է� �迭�� ���� ũ���� 2���� �κ� �迭�� �����Ѵ�.
����(Conquer): �κ� �迭�� �����Ѵ�. �κ� �迭�� ũ�Ⱑ ����� ���� ������ ��ȯ ȣ�� �� �̿��Ͽ� �ٽ� ���� ���� ����� �����Ѵ�.
����(Combine): ���ĵ� �κ� �迭���� �ϳ��� �迭�� �����Ѵ�.
*/

//#include <iostream>
//
//int sorted[5];
//
//void Merge(int list[], int left, int mid, int right)
//{
//	int i, j, k, l;
//	i = left;
//	j = mid + 1;
//	k = left;
//
//	while (i <= mid && j <= right)
//	{
//		if (list[i] <= list[j]) sorted[k++] = list[i++];
//		else sorted[k++] = list[j++];
//	}
//
//	if (i > mid)
//	{
//		for (l = j; l <= right; l++) sorted[k++] = list[l];
//	}
//	else
//	{
//		for (l = i; l <= mid; l++) sorted[k++] = list[l];
//	}
//
//	for (l = left; l <= right; l++)
//		list[l] = sorted[l];
//}
//
//void Merge_Sort(int list[], int left, int right)
//{
//	int mid;
//
//	if (left < right)
//	{
//		mid = (left + right) / 2;	// �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ����
//		Merge_Sort(list, left, mid);	// �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ����
//		Merge_Sort(list, mid + 1, right);	  // �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ����
//		Merge(list, left, mid, right);	    // �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ����
//	}
//}
//
//int main()
//{
//	int list[5]{ 7,9,3,4,1 };
//
//	Merge_Sort(list, 0, 4);
//
//	for (int i = 0; i < 5; i++) std::cout << list[i] << '\n';
//}

/* --- < Quick sort > --- */

/*
���� ���� �˰����� �ϳ���, ��������� �ſ� ���� ���� �ӵ��� �ڶ��ϴ� ���� ���

����Ʈ �ȿ� �ִ� �� ��Ҹ� �����Ѵ�. 
�̷��� �� ���Ҹ� �ǹ�(pivot) �̶�� �Ѵ�.
�ǹ��� �������� �ǹ����� ���� ��ҵ��� ��� �ǹ��� �������� �Ű����� �ǹ����� ū ��ҵ��� ��� �ǹ��� ���������� �Ű�����.
�ǹ��� ������ ���� ����Ʈ�� ������ ����Ʈ�� �ٽ� �����Ѵ�.
���ҵ� �κ� ����Ʈ�� ���Ͽ� ��ȯ ȣ�� �� �̿��Ͽ� ������ �ݺ��Ѵ�.
�κ� ����Ʈ������ �ٽ� �ǹ��� ���ϰ� �ǹ��� �������� 2���� �κ� ����Ʈ�� ������ ������ �ݺ��Ѵ�.
�κ� ����Ʈ���� �� �̻� ������ �Ұ����� ������ �ݺ��Ѵ�.
����Ʈ�� ũ�Ⱑ 0�̳� 1�� �� ������ �ݺ��Ѵ�.

�� ����(quick sort) �˰����� ��ü���� ����

�ϳ��� ����Ʈ�� �ǹ�(pivot)�� �������� �� ���� ��յ��� ũ��� �����ϰ� ���ҵ� �κ� ����Ʈ�� ������ ����, �� ���� ���ĵ� �κ� ����Ʈ�� ���Ͽ� ��ü�� ���ĵ� ����Ʈ�� �ǰ� �ϴ� ����̴�.

����(Divide): �Է� �迭�� �ǹ��� �������� ��յ��ϰ� 2���� �κ� �迭(�ǹ��� �߽����� ����: �ǹ����� ���� ��ҵ�, ������: �ǹ����� ū ��ҵ�)�� �����Ѵ�.
����(Conquer): �κ� �迭�� �����Ѵ�. �κ� �迭�� ũ�Ⱑ ����� ���� ������ ��ȯ ȣ�� �� �̿��Ͽ� �ٽ� ���� ���� ����� �����Ѵ�.
����(Combine): ���ĵ� �κ� �迭���� �ϳ��� �迭�� �պ��Ѵ�.

��ȯ ȣ���� �ѹ� ����� ������ �ּ��� �ϳ��� ����(�ǹ�)�� ���������� ��ġ�� �������Ƿ�, �� �˰����� �ݵ�� �����ٴ� ���� ������ �� �ִ�.
*/

#include <iostream>

// 1. �ǹ��� �������� 2���� �κ� ����Ʈ�� ������.
// 2. �ǹ����� ���� ���� ��� ���� �κ� ����Ʈ��, ū ���� ������ �κ� ����Ʈ�� �ű��.
int Partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];	// ������ ����Ʈ�� ���� ���� �����͸� �ǹ����� ����(������ ���� �ǹ����� ����)

	do {/* low�� high�� ������ ������ �ݺ�( low < high ) */
		do {/* list[low]�� �ǹ����� ������ ��� low�� ���� */
			low++;
		} while (low <= right && list[low] < pivot);
		do {/* list[high]�� �ǹ����� ũ�� ��� high�� ���� */
			high--;
		} while (high >= left && list[high] > pivot);

		if (low < high)
		{
			int temp = list[low];
			list[low] = list[high];
			list[high] = temp;
		}
	} while (low < high);

	int temp = list[left];
	list[left] = list[high];
	list[high] = temp;

	return high;
}

void QuickSort(int list[], int left, int right) 
{
	/* ������ ������ 2�� �̻��� �������̸�(����Ʈ�� ũ�Ⱑ 0�̳� 1�� �ƴϸ�) */
	if (left < right)
	{
		int q = Partition(list, left, right); // q: �ǹ��� ��ġ

		// �ǹ��� ������ 2���� �κ� ����Ʈ�� ������� ��ȯ ȣ��
		QuickSort(list, left, q - 1);
		QuickSort(list, q + 1, right);
	}
}


int main()
{
	int list[5] = { 5, 3, 8, 4, 9 };
	QuickSort(list, 0, 4);
	for (int i = 0; i < 5; i++) 
	{
		std::cout << list[i];
	}
}