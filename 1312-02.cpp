/**
 * ISBN号码
 * 
 * 100
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
    char str[15] = {NULL};

    scanf("%s",&str);
    
    int sum = 0;
    int index = 0;
    int mult = 1;
    while(index < 12)
    {
        if(str[index] != '-')
        {
            sum += (str[index] - '0')*(mult);
            mult++;
        }

        index++;
    }
    sum %= 11;
    if( (sum == 10) )
    {
        if( str[12] == 'X' )
        {
            printf("Right");
            return 0;
        }
        else
        {
            str[12] = 'X';
            printf("%s\n",str);
        }
    }
    else
    {
        if( (str[12]-'0') == sum )
        {
            printf("Right");
            return 0;
        }
        else
        {
            str[12] = sum + '0';
            printf("%s\n",str);
            return 0;
        }

    }
	return 0;
}