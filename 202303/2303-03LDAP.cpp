/**
 * LDAP
 *
 * 0%
 * 
 * https://www.cnblogs.com/sy666/p/17253947.html
 *
*/

#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
int n,m;
map<int,int>q[3010];
char b[100010];
char *s;
bool dfs(int id){
    bool x,y;
    switch(*s){
        case '&':
            s++;s++;
            x=dfs(id);
            s++;s++;
            y=dfs(id);
            s++;
            return x&&y;
        case '|':
            s++;s++;
            x=dfs(id);
            s++;s++;
            y=dfs(id);
            s++;
            return x||y;
        default:
            int p1=0;
            while(*s>=48&&*s<=57){
                p1=p1*10+*s-48;
                s++;
            }
            char p=*s;
            s++;
            int p2=0;
            while(*s>=48&&*s<=57){
                p2=p2*10+*s-48;
                s++;
            }
            if(q[id].find(p1)==q[id].end())return false;
            if(p==':')return q[id][p1]==p2;
            else return q[id][p1]!=p2;
    }
}
struct node{
    int dn,id;
}a[3010];
bool operator <(node x,node y){
    return x.dn<y.dn;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].dn);
        a[i].id=i;
        int k;
        scanf("%d",&k);
        while(k--){
            int x,y;
            scanf("%d%d",&x,&y);
            q[i].insert(make_pair(x,y));
        }
    }
    sort(a+1,a+n+1);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%s",b);
        for(int j=1;j<=n;j++){
            s=b;
            if(dfs(a[j].id))printf("%d ",a[j].dn);
        }
        puts("");
    }
    return 0;
}