#include<cstdio>
#include<algorithm>
using namespace std;

const int max_n=20000;
int main()
{
	int n,m;
	int head[max_n],power[max_n];
	while(scanf("%d %d",&n,&m)==2&&n&&m)
	{
		for (int i=0;i<n;i++)
			scanf("%d",&head[i]);
		for (int i=0;i<m;i++)
			scanf("%d",&power[i]);
		sort(head,head+n);
		sort(power,power+m);
		int cur_id=0;//��ǰ��Ҫ������ͷ�ı�� 
		int cost=0;//��Ҫ�Ľ���� 
		for (int i=0;i<m;i++)
		{
			if(power[i]>=head[cur_id])
			{
				cost+=power[i];
				++cur_id;
				if(cur_id==n)
					break;
			}
		}
		if(cur_id<n)
			printf("�޽�");
		else printf("������С�����Ϊ��%d\n",cost); 
	}
	return 0;
} 
