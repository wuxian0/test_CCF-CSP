/**
 * Z字形扫描
 * 
 * 100
 * 
 * 扫描 按对角线计算，flag为对角线方向扫，描完一条对角线，就变号 1 右上->左下；-1 左下->右上
 * 					flag起始为-1；
 * 
 * 循环变量sum 从0到对角线数量，sum值表示每条对角线的坐标和
 * 
 * 上三角区域 对角线起始位置，一个坐标为0
 * 当扫描过中心对角线 后 起始位置的坐标x y中较小值每次加1
 * 
 * 每条对角线扫描完成如何确认？ x y的坐标完成互换即可，使用init记录其中一个坐标
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int a[510][510];

	scanf("%d",&n);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}

	// 对角线数量
	int cnt = (n-1)*2 + 1;

	// 扫描方式，扫描完一条对角线，就变号 1 右上->左下；-1 左下->右上
	int flag = -1;

	// 下三角标志
	// 上三角 起始位置x,y有一个为0，下三角起始位置为 对角线编号-n的差值
	int down = 0;

	for(int sum = 0; sum <= cnt; sum++)
	{
		int x,y,init;
		if( sum >= n)
		{
			down++;
		}

		if(flag == -1)
		{
			// 矩阵对称，x y的值完成互换后结束
			x = sum - down;
			y = sum - x;
			init = x;
			while(y <= init)
			{
				printf("%d ", a[x][y]);
				x--;
				y++;
			}
		}
		else
		{
			y = sum - down;
			x = sum - y;
			init = y;
			while(x <= init)
			{
				printf("%d ", a[x][y]);
				x++;
				y--;
			}
		}

		flag *= (-1);
	}

	return 0;
}