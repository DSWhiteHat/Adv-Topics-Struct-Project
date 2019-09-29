#include <iostream>
#include <thread> 
#include <chrono>
#include <time.h>
#include <array>

using namespace std;

//Stores the possible actions for each player to take on their turn.
struct action
{
	char name[50];
	int accuracy;
	int strength;
};

//Stores all necessary player information.
struct character
{
	char name[50];
	array<action, 4> actions;
	int health;
	
	//Affects damage.
	int strength;

	//Affects how often you succeed.
	int accuracy;

	//Used to reset values.
	int originalStrength;
	int originalAccuracy;

	//Reduces Damage.
	int defense;

	//How powerful and how many spells you can cast.
	int mana;

	//When you move in combat.
	int speed;

	//Status effects.
	//Cannot physically attack.
	int bound;

	//Increases strength.
	int raging;

	//Increases accuracy.
	int trueStrike;

	//Chance to block strikes.
	int parrying;

	//Reduces incoming physical damage by half.
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

//Title Screen.
void greeting()
{
	//Ascii art: "Call of Honor"
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

//Pauses game until a key is entered. Clears terminal with new lines.
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

//Ascii art: "Player One"
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

//Ascii art: "Player Two"
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

//Creates random statistics for each player.
character randomizeStats()
{
	character temp;
	srand(time(0));
	
	//Input name.
	cout << "Type your hero's name... \n";
	cin >> temp.name;

	cout << '\n' << temp.name << "'s Randomized Stats:";
	this_thread::sleep_for(chrono::milliseconds(300));

	//Health: max 120, min 81.
	temp.health = 120 - (rand() % 40);
	cout << "\nHealth: " << temp.health;
	this_thread::sleep_for(chrono::milliseconds(300));

	//Strength: max 20, min 5.
	temp.strength = 20 - (rand() % 16);
	temp.originalStrength = temp.strength;
	cout << "\nStrength: " << temp.strength;
	this_thread::sleep_for(chrono::milliseconds(300));

	//Accuracy: max 20, min 5.
	temp.accuracy = 20 - (rand() % 16);
	temp.originalAccuracy = temp.accuracy;
	cout << "\nAccuracy: " << temp.accuracy;
	this_thread::sleep_for(chrono::milliseconds(300));

	//Defense: max 20, min 5.
	temp.defense = 20 - (rand() % 16);
	cout << "\nDefense: " << temp.defense;
	this_thread::sleep_for(chrono::milliseconds(300));

	//Mana: max 20, min 5.
	temp.mana = 20 - (rand() % 16);
	cout << "\nMana: " << temp.mana;
	this_thread::sleep_for(chrono::milliseconds(300));

	//Speed: max 20, min 5.
	temp.speed = 20 - (rand() % 16);
	cout << "\nSpeed: " << temp.speed;
	this_thread::sleep_for(chrono::milliseconds(300));

	enterToContinue();
	
	//Input action choices.
	array<action, 4> actions;
	actions = chooseActions();

	temp.actions = actions;

	//Sets status effects to false.
	temp.bound = false;
	temp.raging = false;
	temp.trueStrike = false;
	temp.parrying = false;
	temp.blocking = false;

	enterToContinue();

	return temp;

}

//Input action choices.
array<action, 4> chooseActions()
{
	array<action, 4> actions;

	//Every action in the game. Name, accuracy, and strength.
	action slash = { "Slashing Strike", 60, 20 };
	action lunge = { "Lunging Strike", 80, 15 };
	action parry = { "Swift Parry", 100, 1 };
	action block = { "Stallwart Block", 100, 1 };
	action heal = { "Spell of Healing Surge", 100, 20 };
	action trueStrike = { "Spell of True Strike", 90, 2 };
	action enrage = { "Spell of Enragement", 90, 2 };
	action fire = { "Spell of Searing Fire", 75, 20 };
	action bind = { "Spell of Physical Binding", 50, 2 };

	array<action, 9> choices = { slash, lunge, parry, block, heal, trueStrike, enrage, fire, bind};
	int choice;

	//Displays list.
	cout << "\nWhich actions will your hero take?\n";
	for (int i = 0; i < choices.size(); i++)
	{
		cout << i + 1 << ")\t" << choices.at(i).name << '\n';
		this_thread::sleep_for(chrono::milliseconds(300));
	}

	//Input of four choices.
	for (int i = 0; i < actions.size(); i++)
	{
		cin >> choice;
		actions[i] = choices[choice - 1];
	}

	return actions;
}

//Loops through turns until one player drops to zero hitpoints.
void combatManager(character &one, character &two)
{
	action first, second;
	while (one.health > 0 && two.health > 0)
	{
		printCharacter(one);
		printCharacter(two);

		enterToContinue();

		//Deciding who goes first.
		if (one.speed > two.speed)
		{
			//playerOne();
			first = attack(one);

			//playerTwo();
			second = attack(two);

			//Calculating the effects of the attacks.
			validateAttack(first, one, two);
			if (two.health <= 0)
			{
				break;
			}
			validateAttack(second, two, one);
		}
		//If player two goes first.
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

	//Determining which player caused the loop to break.
	if (one.health <= 0)
	{
		gameOver(false);
	}
	else
	{
		gameOver(true);
	}
}

//Displays name and stats for the passed character.
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

//Input choice of attack from the character's list of four.
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

//Calculates the effects of the attack.
void validateAttack(action attack, character &attacker, character &target)
{
	//The number the random generator has to beat for the attack to miss.
	int accuracy = attack.accuracy + attacker.accuracy;
	int temp = rand() % 100 + 1;

	cout << '\n' << attacker.name << " uses " << attack.name;

	//Miss.
	if (temp > accuracy)
	{
		cout << "\nThe action fails!";
	}
	//Hit.
	else
	{
		//Physical attacks.
		if (strcmp(attack.name, "Slashing Strike") == 0 || strcmp(attack.name, "Lunging Strike") == 0)
		{
			//Attacker is able to use physical attacks.
			if (attacker.bound == 0)
			{
				//Calculates damage.
				int temp = rand() % attack.strength + attacker.strength - target.defense;
				bool parried = false;

				//Chance to reduce damage if target is blocking.
				if (target.blocking > 0)
				{
					int block = 65 + target.accuracy;
					int temp2 = rand() % 100 + 1;

					if (temp2 < block)
					{
						temp /= 2;
					}
				}

				//If target is parrying, chance to fail.
				if (target.parrying > 0)
				{
					int parry = 50 + target.accuracy;
					int temp2 = rand() % 100 + 1;

					//Attack is parried.
					if (temp2 < parry)
					{
						cout << "\nBut the attack is parried by " << target.name << "!";
						parried = true;
					}
				}

				//Damage is above zero and the attack was not parried.
				if (temp > 0 && !parried)
				{
					target.health -= temp;
					cout << "\nThe attack deals " << temp << " damage!";
				}
				//Not parried but damage was zero or bellow.
				else if (!parried)
				{
					cout << "\nBut the attack does no damage!";
				}
			}
			//Attacker is unable to use physical attacks.
			else
			{
				cout << "\nBut is bound by a magical force!";
			}
		}
		//Parry.
		else if (strcmp(attack.name, "Swift Parry") == 0)
		{
			//Chance to negate attacks for a number of rounds dependent on the user's defense.
			attacker.parrying = rand() % (attacker.speed / 5) + 2;
			cout << '\n' << attacker.name << " takes an evasive stance!";
		}
		//Block.
		else if (strcmp(attack.name, "Stallwart Block") == 0)
		{
			//Chance to reduce damage for a number of rounds dependent on the user's defense.
			attacker.blocking = rand() % (attacker.defense / 5) + 2;
			cout << '\n' << attacker.name << " takes a defensive stance!";
		}
		//Healing spell.
		else if (strcmp(attack.name, "Spell of Healing Surge") == 0)
		{
			int mana = 0;
			//If mana is zero, attack fails. 
			if (attacker.mana == 0)
			{
				cout << "\nBut ran out of mana!";
			}
			//If mana is less than six, uses all remaining mana.
			else if (attacker.mana / 6 == 0)
			{
				cout << "\nAnd uses all his remaining mana!";
				mana = attacker.mana;
			}
			//Uses a random amount of mana from 2-5.
			else
			{
				mana = rand() % (attacker.mana / 4) + 2;
			}

			//If mana is being used.
			if (mana > 0)
			{
				int heal = mana * 5 + rand() % 5;
				attacker.health += heal;
				attacker.mana -= mana;
				cout << '\n' << attacker.name << " heals for " << heal << " points!";
			}
		}
		//Increase accuracy spell.
		else if (strcmp(attack.name, "Spell of True Strike") == 0)
		{
			//See Healing spell for how mana use is calculated.
			int mana = 0;
			if (attacker.mana == 0)
			{
				cout << "\nBut ran out of mana!";
			}
			else if (attacker.mana / 6 == 0)
			{
				cout << "\nAnd uses all his remaining mana!";
				mana = attacker.mana;
			}
			else
			{
				mana = rand() % (attacker.mana / 4) + 2;
			}

			if (mana > 0)
			{
				attacker.trueStrike = mana;
				attacker.accuracy += mana * 5;
				attacker.mana -= mana;
				cout << '\n' << attacker.name << "'s accuracy increases by " << mana * 5 << " points!";
			}
		}
		//Increase strength spell.
		else if (strcmp(attack.name, "Spell of Enragement") == 0)
		{
			int mana = 0;

			//See Healing spell for how mana use is calculated.
			if (attacker.mana == 0)
			{
				cout << "\nBut ran out of mana!";
			}
			else if (attacker.mana / 6 == 0)
			{
				cout << "\nAnd uses all his remaining mana!";
				mana = attacker.mana;
			}
			else
			{
				mana = rand() % (attacker.mana / 4) + 2;
			}

			if (mana > 0)
			{
				attacker.raging = mana;
				attacker.strength += mana * 3;
				attacker.mana -= mana;
				cout << '\n' << attacker.name << "'s strength increases by " << mana * 3 << " points!";
			}
		}
		//Damage spell, ignores half of defense stat and all of blocking.
		else if (strcmp(attack.name, "Spell of Searing Fire") == 0)
		{
			int mana = 0;

			//See Healing spell for how mana use is calculated.
			if (attacker.mana == 0)
			{
				cout << "\nBut ran out of mana!";
			}
			else if (attacker.mana / 6 == 0)
			{
				cout << "\nAnd uses all his remaining mana!";
				mana = attacker.mana;
			}
			else
			{
				mana = rand() % (attacker.mana / 4) + 2;
			}

			if (mana > 0)
			{
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
		}
		//Spell prevents opponent from using physical attacks.
		else if (strcmp(attack.name, "Spell of Physical Binding") == 0)
		{
			int mana = 0;

			//See Healing spell for how mana use is calculated.
			if (attacker.mana == 0)
			{
				cout << "\nBut ran out of mana!";
			}
			else if (attacker.mana / 6 == 0)
			{
				cout << "\nAnd uses all his remaining mana!";
				mana = attacker.mana;
			}
			else
			{
				mana = rand() % (attacker.mana / 4) + 2;
			}

			if (mana > 0)
			{
				target.bound = mana;
				attacker.mana -= mana;
				cout << '\n' << target.name << "'s arms become bound with shimmering purple energy!";
			}
		}
		//Catch-all.
		else
		{
			cout << "\nError";
		}

		//Decrementing status effects for the end of the turn.
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
				//Sets accuracy to its unincreased value.
				attacker.accuracy = attacker.originalAccuracy;
				cout << '\n' << attacker.name << "'s true strike wears off!";
			}
		}

		if (attacker.raging > 0)
		{
			attacker.raging--;
			if (attacker.raging == 0)
			{
				//Sets strength to its unincreased value.
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

//Asci art for "Game Over Player One" or "Game Over Player Two"
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