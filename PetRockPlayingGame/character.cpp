#include "character.h"

using namespace std;

character::character() : character::character("Default Name", "Default Description") {};

character::character(string enteredName, string enteredDescription)
{
	name = enteredName;
	description = enteredDescription;
}

void character::describe()
{
	cout << name << " " << description << endl;
}

void character::setAlive(bool status) {
	isAlive = status;
}