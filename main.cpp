#include<iostream>
using namespace std;
const int N = 10000;
int W[N]={0},M[N]={0};//W[0]对应该女生只能从该号开始选
int M_pri[N][N]={0},W_pri[N][N]={0};

void getPri(int );
void G_S(int );
void output(int );
bool lovemore(int ,int ,int);

int main()
{
	int n;
	cin>>n;//输入共有多少对
	getPri(n);
	G_S(n);
	output(n);
	return 0;
}

void getPri(int n)//输入男生更偏爱的女生号码以及女生更偏爱的男生号码
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
		if (W_pri[w][i] == W[w])//更喜欢之前的
			return false;
		else if (W_pri[w][i] == m)//更喜欢现在的
			return true;
}

void G_S(int num)
{
	int m,w;
	while (M[0]!=num)//W[0]记录已经匹配的女生
	{
		w=m=0;
		while (M[++m]!=0) ;
		w = M_pri[m][++M_pri[m][0]];//[0]对应该女生只能从该号开始选
		if (W[w])//如果女生已经匹配了
		{
			if (lovemore(m,w,num))//更喜欢现在的
			{
				M[W[w]] = 0;//之前喜欢该女生的男生自由
				M[m] = w;//当前男生喜欢w号woman
				W[w] = m;//该女生喜欢变为当前男生
			}
			else
				continue;//w继续找列表下一个
		}
		else //如果女生没有约会还是自由状态
		{
			M[m]=w;M[0]++;
			W[w]=m;W[0]++;
		}
	}
}

void output(int num)//输出最后的结果
{
	for (int i = 1;i<=num;i++)
		cout<<"("<<i<<", "<<M[i]<<")"<<endl;
}
