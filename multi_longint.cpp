/* #include<iostream>
#include<string>
using namespace std;
 */
/* int main(){
    string result(40,'\0'),num1,num2;
    cin>>num1>>num2;
    long long int y1=0,y2=0;
    for(int i=0;i<num2.size();i++)
        if(num2.size()-i>10)
            y1=y1*10+(num2[i]-'0');
        else
            y2=y2*10+(num2[i]-'0');
    for(int i=num1.size();i>=0;i--){
        int mult = num1[i]-'0';
        if (mult == 0)
            continue;
        long long int _y1 = y1*mult,_y2 = y2*mult;
        int cnt = 0;
        
    }
    strrev(result);
    cout<<result; 
    cout<<y1<<endl<<y2;
    return 0;
} */

#include<iostream>
#include<string>
using namespace std;

int main(){
    string num1,num2; 
    int buffer1[200]={0},buffer2[200]={0},result[200]={0};
    cin>>num1>>num2;
    int len1=num1.size(),len2=num2.size();
    for(int i=len1-1;i>=0;i--)
        buffer1[len1-1-i]=num1[i]-'0';//逆序读入数组，左对齐
    for(int i=len2-1;i>=0;i--)
        buffer2[len2-1-i]=num2[i]-'0';
    int temp,k;
    for(int i=0;i<len1;i++)
        for(int j=0;j<len2;j++){
            temp=buffer1[i]*buffer2[j];
            result[i+j]+=temp;
            k=i+j;
            while(result[k]>=10)
            {
                result[k+1]+=(result[k]/10);
                result[k]%=10;
                k++;
            }
        }

    int flag=0;
    for(int i=199;i>=0;i--){
        if(result[i]!=0 || flag==1){
            cout<<result[i];
            flag=1;
        }
    }
    cout<<endl;
    return 0;
}