/*Problem 1707 等式数量
Accept: 369    Submit: 2104
Time Limit: 1000 mSec    Memory Limit : 32768 KB
Problem Description

    集合是基本的数学概念，它是集合论的研究对象。关于集合论最简单的说法，是在最原始的集合论《朴素集合论》中的定义：集合就是“一堆东西”。集合里的“东西”，叫作元素。若x是集合A中的元素，记作 x∈A。集合中的元素是互不相同的。
    表示相等关系的式子叫做等式。
    给你一个包含有N个整数的集合，如果从集合中找到三个不同的整数a,b,c使得a+b=c，那么我们说这个集合包含一个等式。
    你的任务是从集合中找出所有的等式数量。
Input
每组输入数据的第一行为一个整数N (3<=N<=5,000)，表示集合中一共有N个不同的整数。之后一行有N个整数，表示集合中的元素，元素的整数值大小为(-10,000,000~10,000,000)。
Output
对于每组数据输出一个整数占一行，表示该集合的等式数量。
Sample Input
4 3 1 2 5
Sample Output
2
Source
福州大学第六届程序设计竞赛 
*/

#include<stdio.h>
int main(int argc, char** argv)
{
	long posi[6001];  
	long nega[6001];
	long *p;
	long n;
	long num;
	long i,j,k;
	long posi_flag;
	long nega_flag;
	long a;
	while(scanf("%ld",&n) !=EOF)
	{
		posi[0]=0;
		nega[0]=0;
		num=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a);
			if(a>=0)
				p=posi;
			else
				p=nega;
			p[p[0]+1]=a;
			for(j=1;j<=p[0];j++)
			{
				if(a<p[j])
				{
					for(k=p[0];k>=j;k--)
						p[k+1]=p[k];
					p[j]=a;
					break;	
				}
				else if(a==p[j])
				{
					p[0]--;
					break;	
				}
			}
			p[0]++;
		}
		for(i=posi[0];i>=3;i--)
		{
			k=i-1;
			for(j=1;j<k;j++)
			{
				a=posi[i]-posi[j];
				if(a==posi[k])
				{
					k--;
					num++;
				}
			}
		}

		for(i=1;i<=nega[0]-2;i++)
		{
			k=i+1;
			for(j=nega[0];j>k;j--)
			{
				a=nega[j]+nega[k];
				if(a==nega[i])
				{
					k++;
					num++;
				}
			}
		}
		for(i=1;i<=nega[0];i++)
		{
			posi_flag=0;
			nega_flag=0;
			for(j=posi[0];j>=1;j--)
			{
				a=nega[i]+posi[j];
				if(a>=0)
				{
					if(posi_flag!=0)
						k=posi_flag-1;
					else
						k=j-1;
					while(k>=1)
					{
						if(posi[k]==a)
						{
							num++;
							posi_flag=k;
							break;
						}
						else
							k--;
					}
				}	
				else
				{
					if(nega_flag!=0)
						k=nega_flag-1;
					else
						k=i+1;
					while(k<=nega[0])
					{
						if(nega[k]==a && k !=i)
						{
							num++;
							nega_flag=k;
							break;
						}
						else
							k++;
					}
				}
			}
		}
		printf("%ld\n",num);
	}
	return 0;
}
