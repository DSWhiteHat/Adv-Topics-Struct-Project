#include <iostream>
#include <thread> 
#include <chrono>
#include <time.h>
#include <array>

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
	array<action, 4> actions;
	int health;
	int strength;
	int accuracy;
	int originalStrength;
	int originalAccuracy;
	int defense;
	int mana;
	int speed;
	int bound;
	int raging;
	int trueStrike;
	int parrying;
	int blocking;
};

void greeting();
void enterToContinue();
void playerOne();
void playerTwo();
character randomizeStats();
array<action, 4> chooseActions();
void combatManager(character &one, character &two);
void printCharacter(character c);
action attack(character attacker);
void validateAttack(action attack, character &attacker, character &target);
void gameOver(bool winner);

int main()
{
	//greeting();

	//playerOne();
	character one = randomizeStats();

	//playerTwo();
	character two = randomizeStats();

	combatManager(one, two);
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

	enterToContinue();
}

void enterToContinue()
{
	char temp[50];
	cout << "\n\n\n\n\t\t\t\t\t Enter Any Key To Continue...";
	cin >> temp;

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
	for (int i = 0; i < 20; i++)
	{
		cout << '\n';
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

void playerOne()
{
	cout << "\n\t                                                                      #";
	cout << "\n\t                  ###                                                 ##";
	cout << "\n\t         #######  ###    ######## ###  ## ######## #######   #######  ###  ## ########";
	cout << "\n\t               ## ###          ## ###  ##                ##        ## #### ##";
	cout << "\n\t          ######  ###     ####### #######  #######  ######    ##   ## #######  #######";
	cout << "\n\t          ###     ###     ###  ##   ###    ###      ##  ##    ##   ## ### ###  ###";
	cout << "\n\t          ###     ####### ###  ##   ###    #######  ##   ##    #####  ###  ##  #######";
	cout << "\n\t                                    ###                                     #";
	enterToContinue();
}

void playerTwo()
{
	cout << "\n\t                                                                            ##";
	cout << "\n\t                  ###                                                       ##";
	cout << "\n\t         #######  ###    ######## ###  ## ######## #######    ######## ##   ## #######";
	cout << "\n\t               ## ###          ## ###  ##                ##      ###   ## # ##       ##";
	cout << "\n\t          ######  ###     ####### #######  #######  ######       ###   #######  ##   ##";
	cout << "\n\t          ###     ###     ###  ##   ###    ###      ##  ##       ###   ### ###  ##   ##";
	cout << "\n\t          ###     ####### ###  ##   ###    #######  ##   ##      ###   ##   ##   #####";
	cout << "\n\t                                    ###";
	enterToContinue();
}

character randomizeStats()
{
	character temp;
	srand(time(0));
	
	cout << "Type your hero's name... \n";
	cin >> temp.name;

	cout << '\n' << temp.name << "'s Randomized Stats:";
	this_thread::sleep_for(chrono::milliseconds(300));

	temp.health = 120 - (rand() % 40);
	cout << "\nHealth: " << temp.health;
	this_thread::sleep_for(chrono::milliseconds(300));

	temp.strength = 20 - (rand() % 16);
	temp.originalStrength = temp.strength;
	cout << "\nStrength: " << temp.strength;
	this_thread::sleep_for(chrono::milliseconds(300));

	temp.accuracy = 20 - (rand() % 16);
	temp.originalAccuracy = temp.accuracy;
	cout << "\nAccuracy: " << temp.accuracy;
	this_thread::sleep_for(chrono::milliseconds(300));

	temp.defense = 20 - (rand() % 16);
	cout << "\nDefense: " << temp.defense;
	this_thread::sleep_for(chrono::milliseconds(300));

	temp.mana = 20 - (rand() % 16);
	cout << "\nMana: " << temp.mana;
	this_thread::sleep_for(chrono::milliseconds(300));

	temp.speed = 20 - (rand() % 16);
	cout << "\nSpeed: " << temp.speed;
	this_thread::sleep_for(chrono::milliseconds(300));

	enterToContinue();
	
	array<action, 4> actions;
	actions = chooseActions();

	temp.actions = actions;

	temp.bound = false;
	temp.raging = false;
	temp.trueStrike = false;
	temp.parrying = false;
	temp.blocking = false;

	enterToContinue();

	return temp;

}

array<action, 4> chooseActions()
{
	array<action, 4> actions;

	action slash = { "Slashing Strike", 60, 20 };
	action lunge = { "Lunging Strike", 80, 15 };
	action parry = { "Swift Parry", 50, 1 };
	action block = { "Stallwart Block", 50, 1 };
	action heal = { "Spell of Healing Surge", 100, 20 };
	action trueStrike = { "Spell of True Strike", 90, 2 };
	action enrage = { "Spell of Enragement", 90, 2 };
	action fire = { "Spell of Searing Fire", 75, 20 };
	action bind = { "Spell of Physical Binding", 50, 2 };

	array<action, 9> choices = { slash, lunge, parry, block, heal, trueStrike, enrage, fire, bind};
	int choice;

	cout << "\nWhich actions will your hero take?\n";
	for (int i = 0; i < choices.size(); i++)
	{
		cout << i + 1 << ")\t" << choices.at(i).name << '\n';
		this_thread::sleep_for(chrono::milliseconds(300));
	}

	for (int i = 0; i < actions.size(); i++)
	{
		cin >> choice;
		actions[i] = choices[choice - 1];
	}

	return actions;
}

void combatManager(character &one, character &two)
{
	action first, second;
	while (one.health > 0 && two.health > 0)
	{
		printCharacter(one);
		printCharacter(two);

		enterToContinue();

		if (one.speed > two.speed)
		{
			//playerOne();
			first = attack(one);

			//playerTwo();
			second = attack(two);

			validateAttack(first, one, two);
			if (two.health <= 0)
			{
				break;
			}
			validateAttack(second, two, one);
		}
		else
		{
			//playerTwo();
			first = attack(two);

			//PlayerOne();
			second = attack(one);

			validateAttack(first, two, one);
			if (one.health <= 0)
			{
				break;
			}
			validateAttack(second, one, two);
		}


	}

	if (one.health <= 0)
	{
		gameOver(false);
	}
	else
	{
		gameOver(true);
	}
}

void printCharacter(character c)
{
	cout << "\n\n" << c.name << ":";
	cout << "\nHealth: " << c.health;
	cout << "\nStrength: " << c.strength;
	cout << "\nAccuracy: " << c.accuracy;
	cout << "\nDefense: " << c.defense;
	cout << "\nMana: " << c.mana;
	cout << "\nSpeed: " << c.speed;

}

action attack(character attacker)
{
	int choice = 0;
	cout << "\nWhich action will " << attacker.name << " use?";

	for (int i = 0; i < 4; i++)
	{
		cout << '\n' << i + 1 << ")\t" << attacker.actions[i].name;
	}
	cout << '\n';
	cin >> choice;

	return attacker.actions.at(choice - 1);
}

void validateAttack(action attack, character &attacker, character &target)
{
	int accuracy = attack.accuracy + attacker.accuracy;
	int temp = rand() % 100 + 1;

	cout << '\n' << attacker.name << " uses " << attack.name;
	if (temp > accuracy)
	{
		cout << "\nThe action fails!";
	}
	else
	{
		if (strcmp(attack.name, "Slashing Strike") == 0 || strcmp(attack.name, "Lunging Strike") == 0)
		{
			if (attacker.bound == 0)
			{
				int temp = rand() % attack.strength + attacker.strength - target.defense;
				bool parried = false;

				if (target.blocking > 0)
				{
					temp /= 2;
				}

				if (target.parrying > 0)
				{
					int parry = 50 + target.accuracy;
					int temp2 = rand() % 100 + 1;

					if (temp2 < parry)
					{
						cout << "\nBut the attack is parried by " << target.name << "!";
						parried = true;
					}
				}

				if (temp > 0 && !parried)
				{
					target.health -= temp;
					cout << "\nThe attack deals " << temp << " damage!";
				}
				else if (!parried)
				{
					cout << "\nBut the attack does no damage!";
				}
			}
			else
			{
				cout << "\nBut is bound by a magical force!";
			}
		}
		else if (strcmp(attack.name, "Swift Parry") == 0)
		{
			attacker.parrying = rand() % (attacker.speed / 5) + 2;
			cout << '\n' << attacker.name << " takes an evasive stance!";
		}
		else if (strcmp(attack.name, "Stallwart Block") == 0)
		{
			attacker.blocking = rand() % (attacker.defense / 5) + 2;
			cout << '\n' << attacker.name << " takes a defensive stance!";
		}
		else if (strcmp(attack.name, "Spell of Healing Surge") == 0)
		{
			int mana = 0;
			if (attacker.mana == 0)
			{
				cout << "And uses all his remaining mana!";
			}
			else if (attacker.mana / 5 == 0)
			{
				cout << "\nBut ran out of mana!";
				mana = attacker.mana;
			}
			else
			{
				mana = rand() % (attacker.mana / 4) + 2;
			}

			int heal = mana * 5 + rand() % 5;
			attacker.health += heal;
			attacker.mana -= mana;
			cout << '\n' << attacker.name << " heals for " << heal << " points!";
		}
		else if (strcmp(attack.name, "Spell of True Strike") == 0)
		{
			int mana = 0;
			if (attacker.mana == 0)
			{
				cout << "\nAnd uses all his remaining mana!";
			}
			else if (attacker.mana / 6 == 0)
			{
				cout << "\nBut ran out of mana!";
				mana = attacker.mana;
			}
			else
			{
				mana = rand() % (attacker.mana / 4) + 2;
			}
			attacker.trueStrike = mana;
			attacker.accuracy += mana * 5;
			attacker.mana -= mana;
			cout << '\n' << attacker.name << "'s accuracy increases by " << mana * 5 << " points!";
		}
		else if (strcmp(attack.name, "Spell of Enragement") == 0)
		{
			int mana = 0;
			if (attacker.mana == 0)
			{
				cout << "\nAnd uses all his remaining mana!";
			}
			else if (attacker.mana / 5 == 0)
			{
				cout << "\nBut ran out of mana!";
				mana = attacker.mana;
			}
			else
			{
				mana = rand() % (attacker.mana / 4) + 2;
			}

			attacker.raging = mana;
			attacker.strength += mana * 3;
			attacker.mana -= mana;
			cout << '\n' << attacker.name << "'s strength increases by " << mana * 3 << " points!";
		}
		else if (strcmp(attack.name, "Spell of Searing Fire") == 0)
		{
			int mana = 0;
			if (attacker.mana == 0)
			{
				cout << "\nAnd uses all his remaining mana!";
			}
			else if (attacker.mana / 5 == 0)
			{
				cout << "\nBut ran out of mana!";
				mana = attacker.mana;
			}
			else
			{
				mana = rand() % (attacker.mana / 4) + 2;
			}

			int health = rand() % attack.strength + mana - (target.defense / 2);
		
			if (health > 0)
			{
				target.health -= health;
				cout << "\nThe attack deals " << health << " damage!";
			}
			else
			{
				cout << "\nBut the attack deals no damage!";
			}

			attacker.mana -= mana;
		}
		else if (strcmp(attack.name, "Spell of Physical Binding") == 0)
		{
			int mana = 0;
			if (attacker.mana == 0)
			{
				cout << "\nAnd uses all his remaining mana!";
			}
			else if (attacker.mana / 5 == 0)
			{
				cout << "\nBut ran out of mana!";
				mana = attacker.mana;
			}
			else
			{
				mana = rand() % (attacker.mana / 4) + 2;
			}
			target.bound = mana;
			attacker.mana -= mana;
			cout << '\n' << target.name << "'s arms become bound with shimmering purple energy!";
		}
		else
		{
			cout << "\nError";
		}

		if (attacker.parrying > 0)
		{
			attacker.parrying--;
			if (attacker.parrying == 0)
			{
				cout << '\n' << attacker.name << "'s parry wears off!";
			}
		}

		if (attacker.trueStrike > 0)
		{
			attacker.trueStrike--;
			if (attacker.trueStrike == 0)
			{
				attacker.accuracy = attacker.originalAccuracy;
				cout << '\n' << attacker.name << "'s true strike wears off!";
			}
		}

		if (attacker.raging > 0)
		{
			attacker.raging--;
			if (attacker.raging == 0)
			{
				attacker.strength = attacker.originalStrength;
				cout << '\n' << attacker.name << "'s rage wears off!";
			}
		}

		if (attacker.blocking > 0)
		{
			attacker.blocking--;
			if (attacker.blocking == 0)
			{
				cout << '\n' << attacker.name << "'s block wears off!";
			}
		}

		if (attacker.bound > 0)
		{
			attacker.bound--;
			if (attacker.bound == 0)
			{
				cout << '\n' << attacker.name << "'s magical bindings wear off!";
			}
		}
	}
}

void gameOver(bool winner)
{
	cout << "\n\t            ###### ######## ##   ## ########  #######  ###  ## ######## #######";
	cout << "\n\t           ###           ## ### ###                 ## ###  ##                ##";
	cout << "\n\t           ###  ##  ####### #######  #######   ##   ## ###  ##  #######  ######";
	cout << "\n\t           ###  ##  ###  ## ## # ##  ###       ##   ##  #####   ###      ##  ##";
	cout << "\n\t            ######  ###  ## ##   ##  #######    #####    ###    #######  ##   ##";
	cout << "\n\t                            ## ";

	if (winner)
	{
		cout << "\n\t                                                                      #";
		cout << "\n\t                  ###                                                 ##";
		cout << "\n\t         #######  ###    ######## ###  ## ######## #######   #######  ###  ## ########";
		cout << "\n\t               ## ###          ## ###  ##                ##        ## #### ##";
		cout << "\n\t          ######  ###     ####### #######  #######  ######    ##   ## #######  #######";
		cout << "\n\t          ###     ###     ###  ##   ###    ###      ##  ##    ##   ## ### ###  ###";
		cout << "\n\t          ###     ####### ###  ##   ###    #######  ##   ##    #####  ###  ##  #######";
		cout << "\n\t                                    ###                                     #";
	}
	else
	{
		cout << "\n\t                                                                            ##";
		cout << "\n\t                  ###                                                       ##";
		cout << "\n\t         #######  ###    ######## ###  ## ######## #######    ######## ##   ## #######";
		cout << "\n\t               ## ###          ## ###  ##                ##      ###   ## # ##       ##";
		cout << "\n\t          ######  ###     ####### #######  #######  ######       ###   #######  ##   ##";
		cout << "\n\t          ###     ###     ###  ##   ###    ###      ##  ##       ###   ### ###  ##   ##";
		cout << "\n\t          ###     ####### ###  ##   ###    #######  ##   ##      ###   ##   ##   #####";
		cout << "\n\t                                    ###";
	}
}





