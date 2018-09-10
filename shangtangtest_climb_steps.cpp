//shangtang document question.
//methoud  the number of steps is n, the number of climb's style is m
// f(n) = f(n-1) + f(n-2) +....+ f(n-m) = 2*f(n-1) - f(n-m-1)
//__________ 
//  f(n)   |___________
//            f(n-1)  |___________
//                       f(n-2)  |
//                               .......__________
//                                        f(n-m) |

#include<stdio.h>
#include<vector>

using namespace std;

int main(){
    int m,n;
    scanf("%d %d",&n,&m);
    vector<int> f(m+2,0);
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=n;i++){
        if(i<=m)
            f[i%(m+2)]=2*f[(i-1)%(m+2)];
        else
            f[i%(m+2)] = (2*f[(i-1)%(m+2)] - f[(i-m-1)%(m+2)] + 10007)%10007;
    }
    
    printf("f[%d]=%d\n",n,f[n%(m+2)]);
    return 0;
}