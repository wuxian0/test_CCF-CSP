/**
 * 田地丈量
 * 
 * 100%
 * 
 * 确认有相交区域->选择相交区域->计算面积
*/


#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int sumArea = 0;
	int n = 0;
	int xRight = 0;
	int yRight = 0;
	scanf("%d%d%d",&n, &xRight,&yRight);
	int xl = 0;
	int yl = 0;
	int xr = 0;
	int yr = 0;


	for(int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d",&xl, &yl, &xr, &yr);

		// 区域在目标区域外 跳过
		if((xl >= xRight) || (yl >= yRight) || (xr <= 0) || (yr <= 0))
		{
			continue;
		}
		
		// 选择相交部分
		if(xl < 0)
		{
			xl = 0;
		}

		if(yl < 0)
		{
			yl = 0;
		}
		if(xr > xRight)
		{
			xr = xRight;
		}
		if(yr > yRight)
		{
			yr = yRight;
		}
		// 计算面积
		sumArea += ((xr-xl) * (yr - yl));
	}

	printf("%d",sumArea);
	return 0;
}