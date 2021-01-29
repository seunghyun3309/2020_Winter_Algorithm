#include <iostream>
#include <algorithm>
using namespace std;

struct Test {
	int seo;
	int meon;
};

Test test[100010];

bool comp(Test t1, Test t2)
{
	if (t1.seo < t2.seo)
	{
		return true;
	}
	else if (t1.seo == t2.seo)
	{
		if (t1.meon < t2.meon)
			return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		int cnt = 1;// �Ǹ����� ����� �ݵ�� ä��

		for (int i = 0; i < N; i++)
		{
			cin >> test[i].seo >> test[i].meon;
		}

		sort(test, test + N, comp);

		int max_rank = test[0].meon;
		for (int i = 1; i < N; i++)
		{
			if (test[i].meon < max_rank) // �׵��� �ְ� ���� ������� ��������
			{
				cnt++; //ä��
				max_rank = test[i].meon; //�ְ� ���� ��� ������Ʈ
			}
		}

		cout << cnt << endl; // 
	}
	return 0;
}