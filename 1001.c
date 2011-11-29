/*
Problem 1001 Duplicate Pair
Accept: 3659    Submit: 17359
Time Limit: 1000 mSec    Memory Limit : 65536 KB
Problem Description

An array of length n, with address from 1 to n inclusive, contains entries from the set {1,2,...,n-1} and there's exactly two elements with the same value. Your task is to find out the value.

Input
Input contains several cases.
Each case includes a number n (1<n<=10^6), which is followed by n integers.
The input is ended up with the end of file.

Output
Your must output the value for each case, one per line.
Sample Input
2 1 1 4 1 2 3 2
Sample Output
1 2
Source
IBM Challenge 2004.1 
*/
#include<stdio.h>
#include<string.h>
#define N  1000
int main(int argc, char** argv)
{
	char ints[N];
	long long n;
	long long sum;
	long long i,num;
	long long d;
	long long eat_n;
	int map[256];
	n=0;
	sum=0;
	num=0;
	eat_n=0;
	memset(map,0,256);
	i='0';
	while(i<='9')
	{
		map[i]=1;
		i++;
	}
	while((d=fread(ints,1,sizeof(ints),stdin)) !=0)
	{
		i=0;
		if(eat_n==0)
		{
			while(ints[i] !='\n')
			{
				n= (n<<3)+(n<<1)+ints[i]-'0';
				i++;
			}
			eat_n=1;
			i++;
		}
		while(i<d)
		{
			if(map[ints[i]]==1)
			{
				num=num*10+ints[i]-'0';
				i++;
			}
			else if(ints[i]=='\n')
			{
				sum+=num;
				printf("%lld\n",sum-(n-1)*n/2);
				sum=0;
				num=0;
				n=0;
				eat_n=0;
				i++;
				while(i<d)
				{
					if(ints[i]=='\n')
					{
						eat_n=1;
						i++;
						break;
					}
					else 
						n= (n<<3)+(n<<1)+ints[i]-'0';
					i++;
				}
			}
			else
			{
				sum+=num;
				num=0;
				i++;
			}
		}
	}
	return 0;
}
