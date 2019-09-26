#include <iostream>
#include <thread> 
#include <chrono>

using namespace std;

struct character
{
	char name[50];
	int health;
	int strength;
	int attack;
	int defense;
	int mana;
	int stamina;
};

void greeting();
character randomizeStats();
void attack();
void gameOver();
void statKeeper();

int main()
{
	this_thread::sleep_for(std::chrono::seconds(3));
	greeting();
}

void greeting()
{
	cout << "\n\n\n\n\n\n\n\n\t                                                                              #                       "
		<< "\n\t                  ###      ###                                                ##                       "
		<< "\n\t######  ########  ###      ###       #######    #######    ###  ##  #######   ###  ##  #######  ####### "
		<< "\n\t###           ##  ###      ###             ##              ###  ##        ##  #### ##        ##       ##"
		<< "\n\t###      #######  ###      ###        ##   ##   #######    #######   ##   ##  #######   ##   ##  ###### "
		<< "\n\t###      ###  ##  ###      ###        ##   ##   ##         ###  ##   ##   ##  ### ###   ##   ##  ##  ## "
		<< "\n\t######   ###  ##  #######  #######     #####    ##         ###  ##    #####   ###  ##    #####   ##   ##"
		<< "\n\t                                                           ###                      #                 ";

	char temp[50];
	cout << "\n\n\n\n\t\t\t\t\t Enter Any Key To Continue...";
	cin >> temp;
}




void attack()
{

}