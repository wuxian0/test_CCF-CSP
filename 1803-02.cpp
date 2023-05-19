/**
 * 碰撞的小球
 * 
 * 100
 * 
 * 如果a坐标1，b坐标2，一秒后为 0 1，那么下一秒呢。还是说不会发生 
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

typedef struct 
{
	int id;
	int pos;
	int v = 1;
}Ball;

bool sortByPos(Ball a, Ball b)
{
	if(a.pos < b.pos)
	{
		return true;
	}
	return false;
}

bool sortById(Ball a, Ball b)
{
	if(a.id < b.id)
	{
		return true;
	}
	return false;
}

int main()
{
	int n,L,t;
	Ball ball[110];

	scanf("%d%d%d", &n, &L, &t);

	// 起始坐标
	for(int i =1; i <= n; i++)
	{
		scanf("%d",&ball[i].pos);
		ball[i].id = i;
	}
	sort(ball+1, ball+n+1, sortByPos);

	// for(int i =1; i <= n; i++)
	// {
	// 	printf("%d %d",ball[i].id, ball[i].pos);
	// }

	for(int tt = 1; tt <= t; tt++)
	{
		// printf("时间：%d\n", tt);
		// 更新位置，判断与前一个球是否碰撞
		// 最左端球撞墙
		// 最右端球撞墙
		for(int i = 1; i <= n; i++)
		{
			ball[i].pos += ball[i].v;
			// 端点碰撞，超出坐标，原地不动
			// if(ball[i].pos < 0)
			// {

			// }
			// printf("%d 坐标为：%d 速度为：%d \n", i, ball[i].pos,ball[i].v);

			// 两端反弹
			if(ball[i].pos == 0 || ball[i].pos == L)
			{
				ball[i].v *= (-1);
				// printf("%d 端点： %d \n", i, ball[i].pos);
			}
			
			if(i == 1)
			{
				continue;
			}

			// 编号2开始判断与前一个球的碰撞
			if(ball[i].pos == ball[i-1].pos)
			{
				ball[i].v *= (-1);
				ball[i-1].v *= (-1);
				
				// printf("%d %d 发生碰撞，位置：%d - %d\n",i-1, i, ball[i-1].pos, ball[i].pos);
			}
		}
		// printf("\n\n");
	}
	sort(ball+1, ball+n+1, sortById);

	for(int i =1; i <= n; i++)
	{
		printf("%d ",ball[i].pos);
	}

	return 0;
}