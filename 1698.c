/*
Problem 1698 最大乘积
Accept: 219    Submit: 882
Time Limit: 1000 mSec    Memory Limit : 32768 KB
Problem Description
    一个正整数一般可以分为几个互不相同的自然数的和，如3=1+2，4=1+3，5＝1+4=2+3，6=1+5＝2+4，…。 
    现在你的任务是将指定的正整数n分解成若干个互不相同的自然数的和，且使这些自然数的乘积最大。 
Input
只一个正整数n，(3<= n< 10000)。
Output
第一行是分解方案，相邻的数之间用一个空格分开，并且按由小到大的顺序。第二行是最大的乘积。
Sample Input
10
Sample Output
2 3 5 30 
*/
#include<stdio.h>
#include<string.h>
int main(int argc, char** argv)
{
	int products[500];
	int mul[1500];
	int i,j,k,h,n;
	int a,b,carry;
	while(scanf("%d",&n) !=EOF)
	{
		if(n==3)
			printf("1 2\n2\n");
		else if(n==4)
			printf("1 3\n3\n");
		else
		{	
			j=0;
			while(n>4)
			{
				if(j==0)
					a=2;
				else
					a=products[j]+1;
				b=n-a;
				if(b<=1 || b==a)
					break;
				else
				{
					for(i=1;i<=j;i++)
					{
						if(b==products[i])
						{
							a=n;
							break;
						}
					}
					j++;
					products[j]=a;
					n-=a;
				}
			}
			if(n!=0)
			{
				j++;
				products[j]=n;
			}
			for(i=j;i>=2;i--)
			{
				k=i-1;
				while(products[i]-products[i-1]>2)
				{
					products[i]--;
					products[k]++;
					k--;
				}
				if(products[i]-products[i-1]==2 && k>=1 && products[i]-products[k]>2)
				{
					products[i]--;
					products[k]++;
					k--;
				}
				i=k+1;
			}

			memset(mul,0,sizeof(mul));
			mul[0]=1;
			carry=0;
			for(i=1;i<=j;i++)
			{
				for(h=0;h<1499;h++)
					mul[h]*=products[i];
				for(h=0;h<1499;h++)
				{
					if(mul[h]>=10000)
					{
						mul[h+1]+=mul[h]/10000;
						mul[h]%=10000;
					}
				}
			}
			for(i=1;i<j;i++)
				printf("%d ",products[i]);
			printf("%d\n",products[i]);

			k=1499;
			while(mul[k]==0)
				k--;
			printf("%d",mul[k]);
			for(h=k-1;h>=0;h--)
			{
				printf("%04d",mul[h]);
			}
			printf("\n");
		}
	}
	return 0;
}
