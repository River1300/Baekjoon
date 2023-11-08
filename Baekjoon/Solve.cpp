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

#include <iostream>
#include <vector>

const int MAX = 100001;

// 1. ������ ���� Ÿ���� �迭 GRAPH�� MAX ��ŭ ũ�⸦ �Ҵ��Ѵ�.
//		=> ������ ����Ʈ�� �׷����� ǥ���Ѵ�.
std::vector<int> GRAPH[MAX];
// 2. �� ����� �θ� ��带 �����Ѵ�.
int PARENT[MAX];

void Dfs(int node)
{
	for (int i = 0; i < GRAPH[node].size(); i++)
	{
		// 3. ���� ��忡�� i��° �ڽ� ��带 next������ �Ҵ��Ѵ�.
		int next = GRAPH[node][i];
		// 4. �ڽ� ��忡�� �θ� ��尡 ���� ���
		if (PARENT[next] == 0)
		{
			// 5. ���� ��带 �θ�� �����Ѵ�.
			PARENT[next] = node;
			// 6. ��� ȣ���� �Ͽ� ���� ��带 Ž���Ѵ�.
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