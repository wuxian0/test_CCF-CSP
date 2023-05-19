/**
 * 归一化处理
 * 
 * 100
 * 
 * 直接计算
*/
#include<stdio.h>
#include<math.h>
int main(void)
{
    int n;
    double a[1000];

    double sum = 0.0;
    double avg = 0.0;
    double D = 0.0;
    double result = 0.0;

    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf",&a[i]);
        sum += a[i];
    }

    avg = sum / n;

    for (int i = 0; i < n; i++)
    {
        D += pow(a[i] - avg, 2);
    }
    D /= n;

    for (int i = 0; i < n; i++)
    {
        result = (a[i] - avg) / sqrt(D);
        printf("%f",result);
        printf("\n");
    }


    return 0;
}
