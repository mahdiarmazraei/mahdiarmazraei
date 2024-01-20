#include <iostream>
using namespace std;
int main(){
int n;
  int *p1, *p2, *p3;
    int* x=&n;
p1=x;
p2=x;
p3=x;

cin >> n;
cout<<*p1<<" "<<*p2<<" "<<*p3;
}
