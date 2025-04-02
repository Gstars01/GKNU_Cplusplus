// 화면에서 출력되어야하는부분 :
// 필드
// 선택창
//|----------------------------------------
//|					you
//|
//|
//|
//|
//|
//|
//|	 card 1		 card 2		 card3 
//|	atk	: 10	atk : 10	atk	: 10
//|	hp	: 10	atk : 10	hp	: 10
//|
//|					you
//|------------------------------------------
//|	당신은 어떤 행동을 할까?
//|	1. 공격
//|	2. 스킬 사용
//|
//|

#include<iostream>
#include<windows.h>
using namespace std;
class Job {
protected:
	int atk, hp;
public:
	Job(int a, int b) :atk(a), hp(b) {}
	virtual int Skill() = 0;
};
class archer : public Job {
public:
	archer(int a, int b) :Job(a, b) {}
	int Skill() override {

	}

// card는 객체임 안쓸때는 빈 객체를 생성하여 0을 전달할것 
void draw(int Ai_Lp,int Player_Lp,int card1,int card2,int card3,int card4,int card5,int card6) {
	cout << "|----------------------------------------\n";
	cout << "|\t\tAI LP : "<<Ai_Lp<<"\n";
	cout << "|\n";
	cout << "|    " << card1 << "\t\t   " << card2 << "\t\t   " << card3 << "\n";
	cout << "| atk :\t" << card1 << "\tatk : " << card2 << "\tatk : " << card3 << "\n";
	cout << "| HP  :\t" << card1 << "\tHP  : " << card2 << "\tHP  : " << card3 << "\n";
	cout << "|\n";
	cout << "|\n";
	cout << "|\n";
	cout << "|    " << card1 << "\t\t   " << card2 << "\t\t   " << card3 << "\n";
	cout << "| atk :\t" << card1 << "\tatk : " << card2 << "\tatk : " << card3 << "\n";
	cout << "| HP  :\t" << card1 << "\tHP  : " << card2 << "\tHP  : " << card3 << "\n";
	cout << "|\n";
	cout << "|\t    Player LP : " << Ai_Lp << "\n";
	cout << "|----------------------------------------\n";
	cout << "|\t" << card6 << endl;
	cout << "|\t" << card6 << endl;
	cout << "|\t" << card6 << endl;
	cout << "|\t" << card6 << endl;
	cout << "|\t" << card6 << endl;
	cout << "|----------------------------------------\n";
	
}

void turn() {

}

void game() {
	system("cls");
	draw(1000,1000,10,10,10,10,10,10);
}

int main() {
	int choose;
	cout << "===Game !===\n1. Insert Coin\n2. end\ninput : ";
	cin >> choose;
	if (choose == 1) {
		game();
	}
	else if (choose == 2) {
		return 0;
	}
}
