/*
Cameron Coppoletta
CIS247C
*/

#include <iostream>
#include <string>
#include <conio.h>
#include "Card.h"
#include <vector> //STL apparently! c


using namespace std;
/// Entry point 


//prototypes

string showCards( vector<Card> cards);
short sumCardValues(vector<Card> cards);
void playHand(short &cash);
//pass by refference


int main()
{

	//adjusting and showing cash
	short cash = 100;
	cout << "Welcome to Blackjack Extreme\n";
	cout << "You are starting out with: $" << cash << endl;
	cout << "\nPress any key to continue...";
	//How to sys pause
	_getch();

	//create the loop 
	short choice = 0;

	// run the app loop

	do 
	{
		system("cls"); //does not work on mac heads up
		cout << "Menu\n" << endl;
		cout << "1) Play a hand" << endl;
		cout << "2) Show current cash balance" << endl;
		cout << "3) Exit" << endl;

		cout << "\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			playHand(cash);
			break;
		case 2:
			cout << "\nYour current cash balance: $" << cash << endl;
			break;
		case 3:
			cout << "\nThank you for playing Extreme BlackJack!" << endl;
			cout << "Your final cash position: $"<< cash << endl;
			break;
		default:
			cout << "\nERROR Please select from the menu." << endl;
			break;
		}
		cout << "\nPress any key to continue...";
		_getch();
		
	}
	
	while (choice != 3);
	return 0;
}

///show the cards and the vector

string showCards(vector<Card> cards)
{
	string output = "";
	for (short i = 0; i < cards.size(); i++)
	{
		output += cards[i].toString() + " ";
	}
	return output;

}
/// Adds the total value of the cards
short sumCardValues(vector<Card> cards)
{
	short total = 0;

	for each (Card c in cards)
	{
		total = total + c.getValue();	
	}
	return total;
}
///Play a single hand of blackjack
void playHand(short &cash)
{
	vector<Card> dealerCards;
	vector<Card>playerCards;
	short dealerCardsTotal = 0;
	short playerCardsTotal = 0;

	short bet = 0;
	cout << "\nEnter bet amount: ";
	cin >> bet;

	Card card1;
	Card card2;
	dealerCards.push_back(card1);
	dealerCards.push_back(card2);
	dealerCardsTotal = sumCardValues(dealerCards);

	cout << "\nDealer is showing: " << dealerCards[0].toString() << endl;

	// create the players setup

	playerCards.push_back(Card()); // Puts a card for the player directly into the array list.
	playerCards.push_back(Card());
	playerCardsTotal = sumCardValues(playerCards);

	cout << "\nHere are your cards: " << showCards(playerCards) << endl;

	char answer = '?';
	do
	{
		cout << "\nDo you want to hit or stand (H/S)? ";
		cin.sync(); //cin.ignore mac perhaps
		cin >> answer;
		cin.sync();

		if (toupper(answer) == 'H')
		{
			Card c;
			cout << "\nYou were dealt this card" << c.toString() << endl;
			playerCards.push_back(c);
			playerCardsTotal = sumCardValues(playerCards);

			if (playerCardsTotal > 21)

			{
				{
					if (c.getValue() == 11)

						cout << " \nYour total is " << playerCardsTotal << endl;
					c.flipAcetoOne();
					cout << " However you have an Ace that was converted to '1' value" << endl;
					playerCardsTotal = sumCardValues(playerCards);
					cout << "\nYour new total is " << playerCardsTotal << endl;

					if (playerCardsTotal <= 21)
						break;

				}



			}

// was difficult was with curly brackets. 

			cout << "\nHere are your cards: " << showCards(playerCards) << endl;
			cout << "Your total is " << playerCardsTotal << endl;
			if (playerCardsTotal > 21)
				answer = 'S';
			
		}

		} while (toupper(answer) != 'S');
		if (playerCardsTotal > 21)
		{

			cout << "\nYou Busted!" << endl;
			cash = cash - bet;
		}
		else
		{
			do 
			{
				if (dealerCardsTotal < 17)
				{
					Card c;
					cout << "\nDealer was dealt: " << c.toString() << endl;
					dealerCards.push_back(c);
					cout << "\nDealer cards: " << showCards(dealerCards) << endl;
					dealerCardsTotal = sumCardValues(dealerCards);
					cout << "Dealer total: " << dealerCardsTotal << endl;
				}
			} while (dealerCardsTotal < 17);
			cout << "\nYour cards: " << showCards(playerCards) << " (" << playerCardsTotal << ")" << endl;
			cout << "Dealer cards: " << showCards(dealerCards) << " (" << dealerCardsTotal << ")" << endl;
			if (dealerCardsTotal > 21)
			{
				cout << "\nDealer busted!" << endl;
 cash = cash + bet;
			}
			else if (dealerCardsTotal > playerCardsTotal)
			{
				cout << "\nDealer wins." << endl;
				cash = cash - bet;
			}
			else if (playerCardsTotal > dealerCardsTotal)
			{
				cout << "\nYou wins." << endl;
				cash = cash + bet;
			}
			else 
			{
				cout << "It's a push to the dealer, a tie" << endl;
			}
		}
		cout << "\nYour current cash balance: $" << cash << endl;
		}
