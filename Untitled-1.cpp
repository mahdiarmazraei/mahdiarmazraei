#include <iostream>
#include <string>
using namespace std;
struct bank {
  int Deposit=0;
  int Withdrawal=0;
  int Report[500]={};
  int Balance=0;
};
int main() {
    int n;
    string x;
    cin>>x;
    cin>>x;
    cin>>x;
    cin>>n;
    struct bank p1;
    p1.Balance=n;
    string ky;
    string val;
    int i=0;
    
do {
  cin>>ky;
    
    if(ky=="Deposit"){
        cin>>val;
        n=stoi(val);
        p1.Report[i]=n;
        i++;
        cout<<"You have successfully deposited "<<n<<"$ to your account"<<endl;
        p1.Balance+=n;
    }
    
     if(ky=="Withdrawal"){
        cin>>val;
        n=stoi(val);
         if(n<=p1.Balance){
            p1.Report[i]=-n;
             i++;
              cout<<"You have successfully withdrawn "<<n<<"$ from your account"<<endl;
             p1.Balance-=n;
         }else{
             cout<<"Insufficient Balance!"<<endl;
         }
     }
    
         if(ky=="Balance"){  
        cout<<p1.Balance<<"$"<<endl;
    }
    
        if(ky=="Report"){  
            for(int j=0;j<i;j++){
                if(p1.Report[j]<0){
                    cout<<"Withdrawal of "<<-p1.Report[j]<<"$"<<endl;
                }else{
                    cout<<"Deposit of "<<p1.Report[j]<<"$"<<endl;
                }
            }
    }
    
}
while (ky!="-1");
}
