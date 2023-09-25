#include<iostream>
//포지션의 포인터
#include<stdlib.h>
using namespace std;
char board[20][20];
struct Position {
	int x, y;//플레이어의 좌표 
};
void move(Position *position,char INPUT);
void Enemymove(Position* position);
void MakeBoard();
void DrawBoard();


class Character
{
public:
	Character();//생성자
	~Character();//소멸자
	int GetHP();//체력을 얻어오는 함수
	void SetHP();//체력을 설정하는 함수
private://이거는 나만 쓸 수 있어
	Position* P_position;//포지션
	int n_Hp;//체력
	int n_Attack;//공격력
};

Character::Character()
{
	n_Hp = 100;
	n_Attack = 10;
	P_position = new Position;
}

Character::~Character()
{
}
int main() {
	MakeBoard();
	//int P_Hp;//플레이어 체력
	//int P_Attack;//플레이어 공격력
	//Position* P_position=new Position;//플레이어 포지션 동적 할당

	Character Player();
	Position* E_position = new Position;//적 포지션 동적 할당
	
	char keyboard;//키보드입력
	DrawBoard();
	while (true)//게임 파이프라인 
	{
		cin >> keyboard;
		system("cls");
		MakeBoard();
	//	move(P_position,keyboard);	
		Enemymove(E_position);
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
	board[position->x][position->y]='#';//플레어는 #
}

void Enemymove(Position* position)
{
	board[position->x][position->y] = '@';//적은 @
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
