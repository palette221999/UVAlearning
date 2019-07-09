#include<cstdio>
#include<algorithm>
using namespace std;

const int max_n=10000;
const char dirname[][10]={"L","turn","R"}; 
int order[max_n];//输入的第i只蚂蚁是左数第order[i]只蚂蚁 
struct ant
{
	int x;//距离木棍左端的距离 
	int d;//朝向，-1左 0转向中 1右
	int id;//输入顺序
	bool operator<(const ant& a) const{
		return x<a.x;
	} 
}start[max_n],end[max_n];//开始状态与结束状态
 
int main()
{
	//输入数据 初始化数据 
	int L,T,n;
	scanf("%d %d %d",&L,&T,&n);
	for(int i=0;i<n;i++)
	{
		int x,d;
		char c;
		scanf("%d %c",&x,&c);
		d=(c=='L'?-1:1);
		start[i]=(ant){x,d,i};
		end[i]=(ant){x+T*d,d,0}; //这里的id未知 
	} 
	//计算order数组
	sort(start,start+n);
	for(int i=0;i<n;i++)
	{
		order[start[i].id]=i;
	} 
	//计算结束状态
	sort(end,end+n);
	for(int i=0;i<n-1;i++)
	{
		if(end[i].x==end[i+1].x)
		{
			end[i].d=0;
			end[i+1].d=0; 
		}
	} 
	//输出结果
	for(int i=0;i<n;i++)
	{
		int a=order[i];
		if(end[a].x<0||end[a].x>L)
			printf("Fell Off\n");
		else printf("%d %s\n",end[a].x,dirname[end[a].d+1]); 
	} 
	return 0;
} 
