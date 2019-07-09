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
		int cur_id=0;//当前需要砍掉的头的编号 
		int cost=0;//需要的金币数 
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
			printf("无解");
		else printf("所需最小金币数为：%d\n",cost); 
	}
	return 0;
} 
