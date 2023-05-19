/**
 * 100
 * 
 * 填充自己写了一个，只考虑了上三角的填充，导致提交错误
 * 暴力 还是快 -_-'
*/
#include <stdio.h>
#include <math.h>

int Q[8][8] = {0};
int M[8][8] = {0};
int P[8][8] = {0};
long double MM[8][8] = {0};
long double sum = 0;
double pi = acos(-1);
int x[] = { 0,0,1,2,1,0,0,1,2,3,4,3,2,1,0,0,1,2,3,4,5,6,5,4,3,2,1,0,0,1,2,3,4,5,6,7,7,6,5,4,3,2,1,2,3,4,5,6,7,7,6,5,4,3,4,5,6,7,7,6,5,6,7,7 };
int y[] = { 0,1,0,0,1,2,3,2,1,0,0,1,2,3,4,5,4,3,2,1,0,0,1,2,3,4,5,6,7,6,5,4,3,2,1,0,1,2,3,4,5,6,7,7,6,5,4,3,2,3,4,5,6,7,7,6,5,4,5,6,7,7,6,7 };
int main()
{
    int n = 0;
    int T = 0;
    int count = 0;
    int row = 0;
    int col = 0;
    int flag = 1;

    for (int  i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            scanf("%d",&Q[i][j]);
        }
    }
    
    scanf("%d",&n);
    scanf("%d",&T);

    int ij = 0;
    while(count < n)
    {
        scanf("%d",&M[x[ij]][y[ij]]);
        ij++;
        count++;
    }
    
    if(T == 0)
    {
        for (int  i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                printf("%d ",M[i][j]);   
            }
            printf("\n");  
        }
        return 0;
    }

    if(T > 0)
    {
        for (int  i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                P[i][j] = M[i][j] * Q[i][j];
            } 
        }
    }
    if(T == 1)
    {
        for (int  i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                printf("%d ",P[i][j]);   
            }
            printf("\n");  
        }
        return 0;
    }

    for (int  i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            sum = 0.0;
            double a,b;
            for (int  u = 0; u < 8; u++)
            {
                for (int v = 0; v < 8; v++)
                {
                    if(u == 0){
                        a = sqrt(0.5);  
                    }
                    else{
                        a = 1;
                    }
                    if(v == 0){
                        b = sqrt(0.5);  
                    }
                    else{
                        b = 1;
                    }
                    sum +=  ( 1.0*a*b*P[u][v]* ( cos( pi*(i+0.5)*u/8.0 ) ) * (cos( pi*(j+0.5)*v/8.0 )) );  
                } 
            }
            MM[i][j] = (0.25 * sum + 128);
        }
    }




    for (int  i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            P[i][j] = (int)(MM[i][j] + 0.5);
            if(P[i][j] > 255)
            {
                P[i][j] = 255;
            }
            else if(P[i][j] < 0)
            {
                P[i][j] = 0;
            }
            printf("%d ",P[i][j]);   
        }
        printf("\n");  
    }
    return 0;
}