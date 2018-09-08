#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;


bool compare(int &a, int &b){
    return a>b;
}
const int maxn = 5e5+10;

int a[maxn];

int n;
int main(){
/*     int n;
    vector<int> number;
    int temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        number.push_back(temp);
    }
    sort(&number[0],&number[number.size()],compare);
    int result = number[0]*number[0];
    int sum = number[0];
    for(int i=1;i<number.size();i++)
    {
        if(number[i] == number[i-1])
            continue;
        sum += number[i];
        result = max(result,sum*number[i]);
    }
    printf("%d\n",result); */
    while(scanf("%d",&n) == 1){
		for(int i = 1; i <= n; i++)
		{
			scanf("%d",&a[i]);
		}
		int Max1 = 0;
		for(int i = 1; i <= n; i++){
			int Min1 = a[i];
			int sum = a[i];
			for(int j = i-1; j >=1; j--){
				if(a[j] >= Min1)  sum += a[j];
				else break;
			}
			for(int j = i+1; j <=n; j++){

				if(a[j] >= Min1)  sum += a[j];

				else break;				

			}
			Max1 = max(Max1,sum * Min1);
		}
		printf("%d\n",Max1);
	}	
    return 0;
}