/**
 * 空模版
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
	int a[16][11] = {0};
	int b[5][5] = {0};
	int left;

	for(int i = 15; i >= 1; i--)
	{
		for(int j = 1; j <= 10 ; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	for(int i = 4; i >= 1; i--)
	{
		for(int j = 1; j <= 4 ; j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	scanf("%d",&left);
	// 板块下面全零行时，将板块下移？
	while((b[1][1] == 0) && (b[1][2] == 0)&&(b[1][3] == 0)&&(b[1][4] == 0))
	{
		for(int i = 1; i <=3; i++)
		{
			for(int j = 1; j <= 4; j++)
			{
				b[i][j] = b[i+1][j];
			}
		}
		b[4][1] = 0;
		b[4][2] = 0;
		b[4][3] = 0;
		b[4][4] = 0;
	}

	// 起始行判断，从上向下
	int downRow = 12;
	for(int i = 12; i >=0)

	// 判断
	int flag = 0;
	for(int i = 1; i <= 12; i++)
	{
		flag = 1;
		for(int j = 1; j <= 4; j++)
		{
			for(int h = 1; h <= 4; h++)
			{
				if( a[i+j-1][h+left-1] == 1 && b[j][h] == 1)
				{
					flag = 0;
					// printf("%d\n",i);
					break;
				}
			}
			if(flag == 0)
			{
				break;
			}
		}
		if(flag == 0)
		{
			continue;
		}
		else
		{
			for(int j = 1; j <= 4; j++)
			{
				for(int h = 1; h <= 4; h++)
				{
					if( a[i+j-1][h+left-1] == 1 || b[j][h] == 1)
					{
						a[i+j-1][h+left-1] = 1;
					}
				}
			}
			break;
		}
	}
	for(int i = 15; i >= 1; i--)
	{
		for(int j = 1; j <= 10 ; j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	

	return 0;
}