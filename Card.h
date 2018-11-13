#pragma once
#include <string>
#include <ctime>
#include <stdlib.h>
using namespace std;
class Card
{
private:
	char suit;
	char face;
	short value;
	static bool randomizerSeeded; //probably based off time classwide
public:

	Card();
	~Card();
	

	//behaviors
	string toString();
	bool flipAcetoOne();
	//accessorss and mutators
	inline char getSuit(){return suit;}
	inline char getFace() { return face; }
	inline short getValue() { return value; }


};

