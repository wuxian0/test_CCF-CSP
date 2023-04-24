#include <stdio.h>
#include <math.h>

int main()
{
    int n = 0;
    double r = 0.0;
    double answer=0.0;
    double temp = 0.0;
    int flag = 1;

    scanf("%d %lf",&n,&r);

    for(int i = 0; i <= n; i++)
    {
        scanf("%lf",&temp);
        answer += temp * (pow(1+r,(-1.0)*flag*i));

    }

    printf("%f",answer);

    return 0;
}