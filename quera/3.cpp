#include <iostream> 
#include<stdlib.h> 
using namespace std; 

int main(){
 
    int n;
    cin>>n;
    	
    int *p;
    
    p = (int*) malloc(sizeof(int)*n); 
        
    for(int i=0;i<n;i++){
        	cin >> *(p+i); 
    } 
    for(int i=0;i<n;i++){
        	cout << *(p+i) <<" "; 
    } 
    
}

