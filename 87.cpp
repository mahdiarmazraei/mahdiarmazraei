#include <iostream>
#include <string>

using namespace std;
int main() {
   int n;
    cin>>n;
    string x;
   
    int a1,b1,a2,b2,a3,b3;
    for(int i=0;i<n;i++){
    
        for(int j=0;j<3;j++){
            cin>>x;
            if(j==0){
               
                a1=(x[10]-'0')*10+x[11]-'0';
                b1=(x[13]-'0')*10+x[14]-'0';
                cout<<a1<<" "<<b1;
            }
            if(j==1){
                
                 a2=(x[9]-'0')*10+x[10]-'0';
                b2=(x[12]-'0')*10+x[13]-'0';
            }
            if(j==2){
                a3=(x[9]-'0')*10+x[10]-'0';
                b3=(x[12]-'0')*10+x[13]-'0';
                }
            }
           
        }
        
        // if(a2>b1 || a3>b2 || b3<24 || a1>15){
        //         cout<<"YES"<<endl;
        //     }else{
        //         cout<<"NO"<<endl;
        //     }
        
    }
