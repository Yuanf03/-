#include<iostream>
using namespace std;
const int N = 10000;
int W[N]={0},M[N]={0};//W[0]��Ӧ��Ů��ֻ�ܴӸúſ�ʼѡ
int M_pri[N][N]={0},W_pri[N][N]={0};

void getPri(int );
void G_S(int );
void output(int );
bool lovemore(int ,int ,int);

int main()
{
	int n;
	cin>>n;//���빲�ж��ٶ�
	getPri(n);
	G_S(n);
	output(n);
	return 0;
}

void getPri(int n)//����������ƫ����Ů�������Լ�Ů����ƫ������������
{

	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>M_pri[i][j];

	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>W_pri[i][j];
}

bool lovemore(int m,int w,int num)
{
	for (int i=1;i<=num;i++)
		if (W_pri[w][i] == W[w])//��ϲ��֮ǰ��
			return false;
		else if (W_pri[w][i] == m)//��ϲ�����ڵ�
			return true;
}

void G_S(int num)
{
	int m,w;
	while (M[0]!=num)//W[0]��¼�Ѿ�ƥ���Ů��
	{
		w=m=0;
		while (M[++m]!=0) ;
		w = M_pri[m][++M_pri[m][0]];//[0]��Ӧ��Ů��ֻ�ܴӸúſ�ʼѡ
		if (W[w])//���Ů���Ѿ�ƥ����
		{
			if (lovemore(m,w,num))//��ϲ�����ڵ�
			{
				M[W[w]] = 0;//֮ǰϲ����Ů������������
				M[m] = w;//��ǰ����ϲ��w��woman
				W[w] = m;//��Ů��ϲ����Ϊ��ǰ����
			}
			else
				continue;//w�������б���һ��
		}
		else //���Ů��û��Լ�ỹ������״̬
		{
			M[m]=w;M[0]++;
			W[w]=m;W[0]++;
		}
	}
}

void output(int num)//������Ľ��
{
	for (int i = 1;i<=num;i++)
		cout<<"("<<i<<", "<<M[i]<<")"<<endl;
}
