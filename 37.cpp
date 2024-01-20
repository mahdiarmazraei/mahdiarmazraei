#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int re(int x){
    int y=x;
    int k=0;
    while(y!=0){
        k=k*10+y%10;
        y=y/10;
    }
    return k;
}
int gcd(int a,int b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
   
int lcm(int a, int b) 
{ 
    return (a / gcd(a, b)) * b; 
} 
int main() {
int n;
    cin>>n;
    int x;
    int max=-1;
    int min=1000000;
    for(int i=0;i<n;i++){
        cin>>x;
        x=re(x);
        if(x>max){
            max=x;
        }
        if(x<min){
            min=x;
        }
    }
    cout<<gcd(min,max)<<" "<<lcm(min,max);
}
