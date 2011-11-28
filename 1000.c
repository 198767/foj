/*
Problem 1000 A+B Problem
Accept: 6836    Submit: 15983
Time Limit: 1000 mSec    Memory Limit : 32768 KB
Problem Description
Calculate a + b.
Input
The input will consist of a series of pairs of integers a and b,separated by a space, one pair of integers per line.
Output
For each pair of input integers a and b you should output the sum of a and b in one line,and with one line of output for each line in input.
Sample Input
1 5 2 3
Sample Output
6 5 
*/
#include<stdio.h>
int main(int argc, char** argv)
{
	int a,b;
	while(scanf("%d %d",&a,&b) !=EOF)
	{
		printf("%d\n",a+b);
	}
	return 0;
}
