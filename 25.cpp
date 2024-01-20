#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;
char c;
int flag=2;
void UserInout(){
	c=getchar();
	if(c==77){
		flag=1;
		cout<<flag;
	}
	if(c==75){
		flag=0;
		cout<<flag;
	}
	if(c=='\n'){
		flag=-1;
		cout<<flag;
	}
}
void GameRender(){
	system("CLS");
	if(c=='a'){
		cout<<1;
	}else{
		flag=-1;
	}
}
int main()
{
   while(flag!=-1){
	UserInout();
	GameRender();
   }
    
    
}