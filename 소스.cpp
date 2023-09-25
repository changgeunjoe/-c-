#include<iostream>
//포지션의 포인터
#include<stdlib.h>
using namespace std;
char board[20][20];
struct Position {
	int x, y;//플레이어의 좌표 
};
void move(Position *position,char INPUT);
void MakeBoard();
void DrawBoard();
int main() {
	MakeBoard();
	int P_Hp;//플레이어 체력
	int P_Attack;//플레이어 공격력
	Position* P_position=new Position;//플레이어 포지션 동적 할당
	P_position->x = 4, P_position->y = 4;
	char keyboard;//키보드입력
	DrawBoard();
	while (true)//게임 파이프라인 
	{
		cin >> keyboard;
		system("cls");
		MakeBoard();
		move(P_position,keyboard);	
		DrawBoard();
	}
}

void move(Position *position,  char INPUT)
{
	switch (INPUT)
	{
	case 'a':
		position->y -= 1;
		break;
	case 'd':
		position->y += 1;
		break;
	case 'w':
		position->x -= 1;
		break;
	case 's':
		position->x += 1;
		break;
	default:
		break;
	}
	board[position->x][position->y]='#';
}

void MakeBoard()
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			board[i][j] = '+';
		}
	}
	//나중에 보드판 초기화할수있음
}

void DrawBoard()
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout<<board[i][j];
		}
		cout << endl;
	}
}
