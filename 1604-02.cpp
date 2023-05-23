/**
 * 俄罗斯方块
 * 
 * 100
 *  ^
 * / \
 *  |
 * 之前判断完重合边界，又从重合边界循环比较
 * 修改：边界确认后直接复制板块到方格图中
 * 
 *  80
 *  ^
 * / \
 *  |
 * 没有判断:当板块中某一个方块的下边缘与方格图上的方块上边缘重合或者达到下边界时，板块不再移动
 * 对策：添加了从上向下移动，40 -> 80
 * 
 *  40
 *  ^
 * / \
 *  |
 * 
 * 板块最下面一行为0是，可以忽略
 * 对策：将板块中的图像(1)按行下移 20->40
 * 
 * 20
 * 
 * 
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
	int flag = 0;
	for(int i = downRow; i > 0; i--)
	{
		flag = 1;
		for(int j = 1; j <= 4; j++)
		{
			for(int h = 1; h <= 4; h++)
			{
				if( a[i+j-1][h+left-1] == 1 && b[j][h] == 1)
				{
					flag = 0;
					break;
				}
			}
			if(flag == 0)
			{break;}
		}
		if(flag == 0)
		{
			downRow = i+1;
			break;
		}
		else
		{
			downRow = i;
		}

	}

	// 判断

	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			a[downRow+i-1][j+left-1] = (a[downRow+i-1][j+left-1] || b[i][j] );
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