#include<iostream>
#include<string>
#include<vector> 
using namespace std;

int X[]={1,0,-1,0};
int Y[]={0,1,0,-1};
int direction = 0;
int location[]={0,1,1};
int tran[]={1,5,3,4, 2,5,0,4, 3,5,1,4, 0,5,2,4, 1,0,3,2, 1,2,3,0};
int tran2[]={0,1,2,3, 0,4,2,5, 0,3,2,1, 0,6,2,7, 8,1,9,1, 11,3,12,3};
int tran3[]={0,1,2,3, 0,2,2,2, 0,3,2,1, 0,0,2,0, 1,1,1,1, 3,3,3,3};

                //0: x:0 y:y
                //1: x:x y:0
                //2: x:2 y:y
                //3: x:x y:2
                //4: x:2 y:x
                //5: x:2 y:2-x
                //6: x:0 y:2-x
                //7: x:0 y:x
                //8: x:2-y y:0
                //9: x:y y:0
                //10: x:2-x y:0
                //11: x:y y:2
                //12: x:2-y y:2
int main(){
    string temp,action;
    vector<vector<vector<char>>> cube(6);
    
    for(int i=0;i<6;i++){
        cube[i].resize(3);
        cin>>temp;
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++){
                cube[i][j].resize(3);
                cube[i][j][k]=temp[3*j+k];
            }
    }
    cin>>action;
    for(int i=0;i<action.size();i++){
        /* cout<<cube[location[0]][location[2]][location[1]]<<"   "<<location[0]<<": x: "<<location[1]<<" y: "<<location[2]<<endl; */
        if(action[i]=='L')
            direction = (direction-1+4)%4;
        else if(action[i]=='R')
            direction = (direction+1)%4;
        else{
            int t = 4*location[0]+direction;
            int x = location[1]+X[direction],y = location[2]+Y[direction];
            if(x<0||x>2||y<0||y>2){
                //0: x:0 y:y
                //1: x:x y:0
                //2: x:2 y:y
                //3: x:x y:2
                //4: x:2 y:x
                //5: x:2 y:2-x
                //6: x:0 y:2-x
                //7: x:0 y:x
                //8: x:2-y y:0
                //9: x:y y:0
                //10: x:2-x y:0
                //11: x:y y:2
                //12: x:2-y y:2
                switch(tran2[4*location[0]+direction]){
                    case 0:location[1]=0;
                    break;
                    case 1: location[2]=0;
                    break;
                    case 2: location[1]=2;
                    break;
                    case 3: location[2]=2;
                    break;
                    case 4: location[2]=location[1],location[1]=2;
                    break;
                    case 5: location[2]=2-location[1],location[1]=2;
                    break;
                    case 6: location[2]=2-location[1],location[1]=0;
                    break;
                    case 7: location[2]=location[1],location[1]=0;
                    break;
                    case 8: location[1]=2-location[2],location[2]=0;
                    break;
                    case 9:location[1]=location[2],location[2]=0;
                    break;
                    case 10:location[1]=2-location[1],location[1]=0;
                    break;
                    case 11: location[1]=location[2],location[2]=2;
                    break;
                    case 12:location[1]=2-location[2],location[2]=2;
                    break;
                }
                location[0] = tran[4*location[0]+direction];
                direction = tran3[t];
            }
            else
                location[1]=x,location[2]=y;
        }
        cout<<cube[location[0]][location[2]][location[1]];
    }
        
    return 0;
}