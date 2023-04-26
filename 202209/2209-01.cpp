/**
 * 100
 * 
 * 题目很长，不要被吓倒，计算方法都给出来了，直接套用就好了
 * m%c[i] = sum + c[i-1] * b[i] 
*/

#include<stdio.h>

int main(){
    int n,m;

    int a[21] = {0};
    int c[21] = {0};
    int b[21] = {0};
    c[0] = 1;
    int sum = 0;


    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        c[i] = c[i-1] *a[i];
        if(i==1)
        {
            sum += 0;
        }
        else{
            sum += c[i-2]*b[i-1];
        }
        b[i] = (m%c[i] - sum)/c[i-1];
    }
    for(int i = 1; i<=n; i++)
    {
        printf("%d ",b[i]);
    }
    printf("\n");

    return 0;
}