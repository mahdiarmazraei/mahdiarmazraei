#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
    cin>>x;
    int* p= new int(x);
        cout<<*p<<" ";
        delete p;
    }
}
