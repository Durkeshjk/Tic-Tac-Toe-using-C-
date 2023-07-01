#include<iostream>
#include<stdlib.h>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row,col;
int choice;
bool draw=false;

void game_board(){
	cout<<"Player 1 [X] & Player 2 [O]"<<endl;
	cout<<" ------- ------- ------- "<<endl;
	cout<<"|\t\t|\t\t|\t\t|"<<endl;
	cout<<"|\t"<<board[0][0]<<"\t|\t"<<board[0][1]<<"\t|\t"<<board[0][2]<<"\t|"<<endl;
	cout<<" ------- ------- ------- "<<endl;
	cout<<"|\t\t|\t\t|\t\t|"<<endl;
	cout<<"|\t"<<board[1][0]<<"\t|\t"<<board[1][1]<<"\t|\t"<<board[1][2]<<"\t|"<<endl;
	cout<<" ------- ------- ------- "<<endl;
	cout<<"|\t\t|\t\t|\t\t|"<<endl;
	cout<<"|\t"<<board[2][0]<<"\t|\t"<<board[2][1]<<"\t|\t"<<board[2][2]<<"\t|"<<endl;
	cout<<" ------- ------- ------- "<<endl;
}

void player_turn(){
	if(turn=='X'){
		cout<<"Player 1 [X] turn :"<<"(choose any position)"<<endl;
	}
	else if(turn=='O'){
		cout<<"Player 2 [O] turn :"<<"(choose any position)"<<endl;
	}
	cin>>choice;
	switch(choice){
		case 1:
			row=0;
			col=0;
			break;
		case 2:
			row=0;
			col=1;
			break;
		case 3:
			row=0;
			col=2;
			break;
		case 4:
			row=1;
			col=0;
			break;
		case 5:
			row=1;
			col=1;
			break;
		case 6:
			row=1;
			col=2;
			break;
		case 7:
			row=2;
			col=0;
			break;
		case 8:
			row=2;
			col=1;
			break;
		case 9:
			row=2;
			col=2;
			break;
		default:
			cout<<"Invalid Movement"<<endl;
	}
	if(turn=='X' && board[row][col]!='X' && board[row][col]!='O'){
		board[row][col]='X';
		turn='O';
	}
	else if(turn=='O' && board[row][col]!='X' && board[row][col]!='O'){
		board[row][col]='O';
		turn='X';
	}
	else{
		cout<<"Box already filled! \n Choose other option!!"<<endl;
		player_turn();
	}
}

bool game_over(){
	for(int i=0;i<3;i++){
		if(  (board[i][0]==board[i][1]) && (board[i][0]==board[i][2])  ||  (board[0][i]==board[1][i]) && (board[0][i]==board[2][i])  ){
			return false;
		}
	}
	if( ( (board[0][0]==board[1][1]) && (board[0][0]==board[2][2]) ) || ( (board[0][2]==board[1][1]) && (board[0][2]==board[2][0]) ) ){
		return false;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if( board[i][j]!= 'X' && board[i][j]!= 'O'){
				return true;
			}
		}
	}
	draw=true;
	return false;
}

int main(){
	
	cout<<"\t\t\tWELCOME TO TIC-TAC-TOE\t\t\t"<<endl;
	cout<<"\t\t\t\tTwo Payer Game\t\t\t\t"<<endl;

    	while(game_over()){
    		game_board();
    		player_turn();
    		game_over();
    	}
    	
    	if(turn=='O' && draw==false){
    	    game_board();
    		cout<<"Congratulations !!! Player 1 [X] has won the game!!!"<<endl;
    	}
    	else if (turn=='X' && draw==false){
    	    game_board();
    		cout<<"Congratulations !!! Player 2 [O] has won the game!!!"<<endl;
    	}
    	else{
    	    game_board();
    		cout<<"Match Draw"<<endl;
    	}

}
