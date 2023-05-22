/**
 * 工资计算
 * 
 * 100
 * 
 * 倒推
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
    int a[10] = {0};
    int b[7] = {3500, 5000, 8000, 12500, 38500, 58500, 83500};
    float c[8] = {0, 0.97, 0.9, 0.8, 0.75, 0.7, 0.65, 0.55};

    a[0] = 3500;
    a[1] = a[0] + 1500 * ( 1 - 0.03);
    a[2] = a[1] + (4500 -1500) * ( 1 - 0.1);
    a[3] = a[2] + (9000 - 4500) * ( 1 - 0.2);
    a[4] = a[3] + (35000 - 9000) * ( 1 - 0.25);
    a[5] = a[4] + (55000 - 35000) * ( 1 - 0.3);
    a[6] = a[5] + (80000 - 55000) * ( 1 - 0.35);
    // a[7] = a[5] + (55000 - 35000) * ( 1 - 0.3);
    int T;
    scanf("%d", &T);
    if( T <= 3500)
    {
        printf("%d",T);
        return 0;
    }
    for(int i = 1; i <= 6; i++)
    {
        if( T <= a[i])
        {
            T = (T - a[i-1])/c[i] + b[i-1];
            printf("%d",T);
            return 0;
        }
    }

    T = (T - a[6]) / c[7] + b[6];
    printf("%d",T);	

	return 0;
}