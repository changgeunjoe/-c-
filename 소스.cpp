#include<iostream>
//�������� ������
#include<stdlib.h>
using namespace std;
char board[20][20];
struct Position {
	int x, y;//�÷��̾��� ��ǥ 
};
void move(Position *position,char INPUT);
void Enemymove(Position* position);
void MakeBoard();
void DrawBoard();


class Character
{
public:
	Character();//������
	~Character();//�Ҹ���
	int GetHP();//ü���� ������ �Լ�
	void SetHP();//ü���� �����ϴ� �Լ�
private://�̰Ŵ� ���� �� �� �־�
	Position* P_position;//������
	int n_Hp;//ü��
	int n_Attack;//���ݷ�
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
	//int P_Hp;//�÷��̾� ü��
	//int P_Attack;//�÷��̾� ���ݷ�
	//Position* P_position=new Position;//�÷��̾� ������ ���� �Ҵ�

	Character Player();
	Position* E_position = new Position;//�� ������ ���� �Ҵ�
	
	char keyboard;//Ű�����Է�
	DrawBoard();
	while (true)//���� ���������� 
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
	board[position->x][position->y]='#';//�÷���� #
}

void Enemymove(Position* position)
{
	board[position->x][position->y] = '@';//���� @
}

void MakeBoard()
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			board[i][j] = '+';
		}
	}
	//���߿� ������ �ʱ�ȭ�Ҽ�����
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
