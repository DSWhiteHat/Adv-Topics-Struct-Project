#include <iostream>
#include <thread> 
#include <chrono>
#include <time.h>

using namespace std;

struct action
{
	char name[50];
	int accuracy;
	int strength;
};

struct character
{
	char name[50];
	int health;
	int strength;
	int accuracy;
	int defense;
	int mana;
	int speed;
	action actions[4];
};

void greeting();
character randomizeStats();
action[4] chooseActions();
void attack(character attacker, character target);
void gameOver();
void statKeeper();

int main()
{
	greeting();
}

void greeting()
{
	this_thread::sleep_for(std::chrono::seconds(2));
	cout << "\n\n\n\n\n\n\n\n\t                                                                              #                       ";
	this_thread::sleep_for(chrono::milliseconds(300));
	cout << "\n\t                  ###      ###                                                ##                       ";
	this_thread::sleep_for(chrono::milliseconds(300));
	cout << "\n\t######  ########  ###      ###       #######    #######    ###  ##  #######   ###  ##  #######  ####### ";
	this_thread::sleep_for(chrono::milliseconds(300));
	cout << "\n\t###           ##  ###      ###             ##              ###  ##        ##  #### ##        ##       ##";
	this_thread::sleep_for(chrono::milliseconds(300));
	cout << "\n\t###      #######  ###      ###        ##   ##   #######    #######   ##   ##  #######   ##   ##  ###### ";
	this_thread::sleep_for(chrono::milliseconds(300));
	cout << "\n\t###      ###  ##  ###      ###        ##   ##   ##         ###  ##   ##   ##  ### ###   ##   ##  ##  ## ";
	this_thread::sleep_for(chrono::milliseconds(300));
	cout << "\n\t######   ###  ##  #######  #######     #####    ##         ###  ##    #####   ###  ##    #####   ##   ##";
	this_thread::sleep_for(chrono::milliseconds(300));
	cout << "\n\t                                                           ###                      #                 ";

	char temp[50];
	cout << "\n\n\n\n\t\t\t\t\t Enter Any Key To Continue...";
	cin >> temp;
}

character randomizeStats()
{
	srand(time(0));
	
	char n [50];
	int h = 120 - (rand() % 40);
	int s = 20 - (rand() % 16);
	int a = 20 - (rand() % 16);
	int d = 20 - (rand() % 16);
	int m = 20 - (rand() % 16);
	int p = 20 - (rand() % 16);
	
	cout << "Type your hero's name... \n";
	cin >> n;

	character temp = { n, h, s, a, d, m, p };
	return temp;

}

action[4] chooseActions()
{
	action heal = { "Healing Surge", 100, 20 };
	action slash = { "Slashing Strike", 60, 20 };
	action lunge = { "Lunging Strike", 80, 15 };
	action parry = { "Swift Parry", 50, 1};

	cout << "Which actions will " << c.name << " take?";

}

void attack(character attacker, character target)
{
	cout << "Which action will " << attacker.name << " use?";

	for (int i = 0; i < 4; i++)
	{
		cout << "\n1)\t" << attacker.actions[i].name;
	}
}




