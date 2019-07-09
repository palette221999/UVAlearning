#include<cstdio>
#include<algorithm>
using namespace std;

const int max_n=10000;
const char dirname[][10]={"L","turn","R"}; 
int order[max_n];//����ĵ�iֻ������������order[i]ֻ���� 
struct ant
{
	int x;//����ľ����˵ľ��� 
	int d;//����-1�� 0ת���� 1��
	int id;//����˳��
	bool operator<(const ant& a) const{
		return x<a.x;
	} 
}start[max_n],end[max_n];//��ʼ״̬�����״̬
 
int main()
{
	//�������� ��ʼ������ 
	int L,T,n;
	scanf("%d %d %d",&L,&T,&n);
	for(int i=0;i<n;i++)
	{
		int x,d;
		char c;
		scanf("%d %c",&x,&c);
		d=(c=='L'?-1:1);
		start[i]=(ant){x,d,i};
		end[i]=(ant){x+T*d,d,0}; //�����idδ֪ 
	} 
	//����order����
	sort(start,start+n);
	for(int i=0;i<n;i++)
	{
		order[start[i].id]=i;
	} 
	//�������״̬
	sort(end,end+n);
	for(int i=0;i<n-1;i++)
	{
		if(end[i].x==end[i+1].x)
		{
			end[i].d=0;
			end[i+1].d=0; 
		}
	} 
	//������
	for(int i=0;i<n;i++)
	{
		int a=order[i];
		if(end[a].x<0||end[a].x>L)
			printf("Fell Off\n");
		else printf("%d %s\n",end[a].x,dirname[end[a].d+1]); 
	} 
	return 0;
} 
