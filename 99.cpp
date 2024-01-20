#include<iostream>
#include<unistd.h>
#include<termios.h>
using namespace std;
 /* reads from keypress, doesn't echo */
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
int flag=0;
char input;
string status="";
void UserInput(){
    input=getch();
    if(input=='d'){
        flag+=1;
    }
    if(input=='a'){
        flag-=1;
    }
    if(input=='\n'){
        flag=-100;
        
    }
}

void GameRender1(){
    
    system("clear");
    if(flag%3==0 && flag!=-100){
        cout<<"\033[32mGo to make a map"<<"    "<<"\033[0mGo to the game"<<"    "<<"\033[0mGo to the history of games";
        status="map";
    }
    if((flag%3==1 || flag%3==-2) && flag!=-100){
        cout<<"\033[0mGo to make a map"<<"    "<<"\033[32mGo to the game"<<"    "<<"\033[0mGo to the history of games";
        status="game";
    }
    if((flag%3==2 || flag%3==-1) && flag!=-100){
        cout<<"\033[0mGo to make a map"<<"    "<<"\033[0mGo to the game"<<"    "<<"\033[32mGo to the history of games";
        status="history";

    }
    return;
}
void GameRender2(){
    system("clear");
    if (status=="map"){
        if(flag%2==0 && flag!=-100){
            cout<<"\033[32mcreate easy map"<<"    "<<"\033[0mcreate hard map";

                }
        if(flag%2!=0 && flag!=-100){
            cout<<"\033[0mcreate easy map"<<"    "<<"\033[32mcreate hard map";

                }
        }
}
int main(){
    system("clear");
    while(flag!=-100){
    GameRender1();
    UserInput();
    }

    flag=0;
    system("clear");
    while(flag!=-100){
    GameRender2();
    UserInput();
    }

}