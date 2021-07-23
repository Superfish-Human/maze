#include<bits/stdc++.h>
using namespace std;
int m[8][8];
int goalx=-1;
int goaly=-1;
int playerx=-1;
int playery=-1;
int moves=0;
char control;
string whatever;
void clscr(){
	cout << string( 100, '\n' );
	return;
}
void findGoal(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(m[i][j]==2){
				goalx=i;
				goaly=j;
			}
			if(m[i][j]==3){
				playerx=i;
				playery=j;
			}
		}
	}
	return;
}
void printm(){
	clscr();
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(m[i][j]==0){
				cout<<" ";
			}else{
				cout<<m[i][j];
			}
		}
		cout<<endl;
	} 
	return;
}
void inputm(){
	cout<<"empty=0, wall=1, goal=2, player=3"<<endl;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cin>>m[i][j];
		}
	}//input map
	return;
}
void playm(){
	printm();
	cout<<"empty=0, wall=1, goal=2, player=3"<<endl;
	cout<<"Moves: "<<moves<<endl;
	cout<<"w=up, a=left, s=down, d=right"<<endl;
	cout<<"enter move: ";
	cin>>control;
	if(control=='a'||control=='A'){
		if(m[playerx][playery-1]!=1&&playery-1>=0){
			m[playerx][playery-1]=3;
			m[playerx][playery]=0;
			playery-=1;
		}//move up
	}
	if(control=='d'||control=='D'){
		if(m[playerx][playery+1]!=1&&playery+1<=8-1){
			m[playerx][playery+1]=3;
			m[playerx][playery]=0;
			playery+=1;
		}//move down
	}
	if(control=='w'||control=='W'){
		if(m[playerx-1][playery]!=1&&playerx-1>=0){
			m[playerx-1][playery]=3;
			m[playerx][playery]=0;
			playerx-=1;
		}//move left
	}
	if(control=='s'||control=='S'){
		if(m[playerx+1][playery]!=1&&playerx+1<=8-1){
			m[playerx+1][playery]=3;
			m[playerx][playery]=0;
			playerx+=1;
		}//move right
	}
	moves++;
	if(playerx==goalx&&playery==goaly){
		return;
	}else{
		playm();
	}//win
}
int main(){
	cout<<"Enter Map Data..."<<endl;
	inputm();
	cout<<"loading..."<<endl;
	findGoal();
	if(goalx==-1||goaly==-1||playerx==-1||playery==-1){
		cout<<"Error 404: Not Found"<<endl;
		return 0;
	}//start and end point
	playm();
	cout<<"FINISH"<<endl;
	cout<<"Moves: "<<moves<<endl; 
	cout<<"Written by Superfish in C++"<<endl;
	cout<<"Discord: SuperfishMEMZ#9454"<<endl;
	cout<<"Source code located at https://github.com/sfmemz/maze"<<endl;
	cin>>whatever;
	return 0;
} 
