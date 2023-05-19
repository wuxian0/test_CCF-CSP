/**
 * 游戏
 * 
 * 100
 * 
*/

#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
	int kids[1010] = {0};

	int n,k;
	scanf("%d%d",&n,&k);
	int count = n;

	int num = 1;

	int index = 0;
	while(count > 1)
	{
		//已经淘汰判断
		if( kids[index] == 1)
		{
			index = (index + 1 ) % (n);
			continue;
		}
		// printf("%d 报数 %d\n", index + 1, num);

		if( (num%10 == k ) || (num%k == 0))
		{
			kids[index] = 1;
			count--;
			// printf("淘汰%d\n",index +1);
		}
		index = (index + 1 ) % (n);
		num++;
	}

	for(int i = 0; i < n; i++)
	{
		if(kids[i] == 0)
		{
			printf("%d\n",i+1);
		}
	}
	return 0;
}