#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
     int sum=0;
  int a[n];
    int x;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    try {
    if (n==13) {
      cout << sum;
    } else {
      throw (n);
    }
  }
  catch (int myNum) {
      try{
          if(myNum<13){
              cout<<"tedad "<<13-myNum<<" ta kamtar ast nomokham";
          }else{
              throw (myNum);
          }
      }
          catch(int n){
              cout<<"tedad "<<n-13<<" ta bishtar ast nomokham";
          }
   
  }
  return 0;
}


