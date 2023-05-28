/**
 * 打酱油
 * 
 * 100
 * 
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    int cnt4 = 0;
    int cnt7 = 0;
    int cnt1 = 0;

    scanf("%d",&n);
    
    cnt7 = n/50;
    if(cnt7)
    {
        n %= 50;
    }
    
    cnt4 = n/30;
    if(cnt4)
    {
        n %= 30;
    }

    cnt1 = n/10;

    printf("%d",cnt7*7+cnt4*4+cnt1);
	

	return 0;
}