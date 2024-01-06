#include <iostream>
using namespace std;
#define TAKEAWAYEXTRA 0.20
//RM0.20 will be charged if the user choose "take away"
struct FoodItem
{
	string code;
	string name;
	double price;
};
struct DrinkItem
{
	string code;
	string name;
	double price;
};
void WesternFoodOrdering(string option3, FoodItem westernFood[], double& price, double& total, int& quantity, char& ans);
void LocalFoodOrdering(string);
char DrinkOrdering(string);
void calculation(double price, int quantity, double total);
string BillingSystem();
//???? ???array ???????struct
string Payment(string);

int main()
{	// Define arrays for food items

	char option, option2, ans;
	string option3; //option3 is a string since it has more than one alphabet
	double price, total = 0;
	int quantity;

	//Declare array for westernFood,localFood,drinks
	FoodItem westernFood[5] =
	{
		{"FCC", "Fried Chicken Chop", 12.00},
		{"FC", "Fish and Chips", 14.50},
		{"S", "Spaghetti", 10.50},
		{"P", "Pizza", 12.50},
		{"B", "Burger", 5.50}
	};
	FoodItem localFood[5] =
	{
		{"NL", "Nasi Lemak", 7.00},
		{"AL", "Assam Laksa", 7.00},
		{"CM", "Curry Mee", 7.00},
		{"RC", "Roti Canai", 1.50},
		{"NK", "Nasi Kerabu", 7.00}
	};
	DrinkItem drinks[5] =
	{
		{"M", "Milo", 2.50},
		{"TT", "Teh Tarik", 2.50},
		{"KO", "Kopi O", 2.00},
		{"LT", "Lemon Tea", 3.00},
		{"OJ", "Orange Juice", 3.50}
	};
	//Display our homepage
	cout << "*************************************************************************" << endl;
	cout << "\t\t\tSTELLAR RESTAURANT" << endl;
	cout << "*************************************************************************" << endl;
	do {
		std::cout << "\tWelcome to our restaurant. You can ordering by selecting " << endl;

		cout << "\t\tDINE IN (D)\t\tTAKE AWAY (T)" << endl;
		cout << "\t\t\tYour selection >> ";
		cin >> option;
		if (option != 'D' && option != 'd' && option != 'T' && option != 't')
			//put && because if user didn't enter one of it, all these statements will be false?
			std::cout << "\t\tYou've entered the wrong input :C" << endl;
	} while (option != 'D' && option != 'd' && option != 'T' && option != 't');
	/*The page will keep displaying welcome to ........... to ask user to choose whether he or she wants to dine in or take away if
		 the user didn't enter the correct input*/

	if (option == 'T' || option == 't' || option == 'D' || option == 'd')
	{
		do
		{
			do {
				cout << "\n\tPlease enter F for FOOD and D for DRINKS >> ";
				cin >> option2;

				if (option2 == 'F' || option2 == 'f')
				{
					do {
						cout << "\n\t We do offer both Western and Local food. :D" << endl;
						cout << "   Please enter WF for Western Food and LF for Local Food >> ";
						cin >> option3;
						if (option3 != "WF" && option3 != "wf" && option3 != "LF" && option3 != "lf")
						{
							cout << "\tYou've entered the wrong input, pls try again :V" << endl;
						}
					} while (option3 != "WF" && option3 != "wf" && option3 != "LF" && option3 != "lf");
				}
				if (option3 == "WF" || option3 == "wf")
				{
					WesternFoodOrdering(option3, westernFood, price, total, quantity, ans);
				}
				else if (option3 == "LF" || option3 == "lf")
				{
					string option5;
					do {
						//Print out the local food list
						cout << "Western food" << endl;
						for (int i = 0; i < 5; ++i)
						{
							std::cout << i + 1 << ": " << localFood[i].name << " (" << localFood[i].code << ") - RM " << westernFood[i].price << endl;
						}
						cin >> option5;
						if (option5 != "NL" && option5 != "nl" && option5 != "AL" && option5 != "al" && option5 != "CM" && option5 != "cm" && option5 != "RC" && option5 != "rc" && option5 != "NK" && option5 != "nk")
							std::cout << "Hmmmm....seems like you've entered wrong input. Please try againnnnnnnnnnnnnnnnnnnnnnnnnnnn" << endl;
						break;
					} while (option5 != "NL" && option5 != "nl" && option5 != "AL" && option5 != "al" && option5 != "CM" && option5 != "cm" && option5 != "RC" && option5 != "rc" && option5 != "NK" && option5 != "nk");
					cout << "\t\tPlease enter the quantity >> ";
					cin >> quantity;
					if (option5 == "NL" || option5 == "nl") {
						price = 7 * quantity;
						total += price;
					}
					else if (option5 == "AL" || option5 == "al") {
						price = 7 * quantity;
						total += price;
					}
					else if (option5 == "CM" || option5 == "cm") {
						price = 7 * quantity;
						total += price;
					}
					else if (option5 == "RC" || option5 == "rc") {
						price = 1.50 * quantity;
						total += price;
					}
					else if (option5 == "NK" || option5 == "nk") {
						price = 7 * quantity;
						total += price;
					}
					cout << "Do you wish to add more to your cart? :D (y/n) >> ";
					cin >> ans;
					break;
				}
				//Drinks
				else if (option2 == 'D' || option2 == 'd')
				{
					string option6;
					do {
						std::cout << "Drink Items:" << endl;
						for (int i = 0; i < 5; ++i) {
							std::cout << "\t\t" << i + 1 << ") " << drinks[i].name << " (" << drinks[i].code << ") - RM " << drinks[i].price << endl;
						}

						cout << "\t\tYour selection :";
						cin >> option6;
						if (option6 != "M" && option6 != "m" && option6 != "TT" && option6 != "tt" && option6 != "KO" && option6 != "ko" && option6 != "LT" && option6 != "lt" && option6 != "OJ" && option6 != "oj")
							std::cout << "\t\tni hao :D wrong input le :C" << endl;
					} while (option6 != "M" && option6 != "m" && option6 != "TT" && option6 != "tt" && option6 != "KO" && option6 != "ko" && option6 != "LT" && option6 != "lt" && option6 != "OJ" && option6 != "oj");
					cout << "\t\tPlease enter the quantity >> ";
					cin >> quantity;
					if (option6 == "M" || option6 == "m") {
						price = 2.50 * quantity;
						total += price;
					}
					else if (option6 == "T" || option6 == "tt") {
						price = 2.50 * quantity;
						total += price;
					}
					else if (option6 == "KO" || option6 == "ko") {
						price = 2 * quantity;
						total += price;
					}
					else if (option6 == "LT" || option6 == "lt") {
						price = 3 * quantity;
						total += price;
					}
					else if (option6 == "OJ" || option6 == "oj") {
						price = 3.50 * quantity;
						total += price;
					}
					cout << "Do you wish to add more to your cart? :D (y/n) >> ";
					cin >> ans;
					break;
				}
				else
					cout << "\tYou've entered the wrong input, please try again.";

			} while (option2 != 'F' && option2 != 'f' && option2 != 'D' && option2 != 'd');
			//if the user chooses other than F and D, it will loop back to the top where it asks user to choose food and drinks
		} while (ans == 'Y' || ans == 'y');
		//if the user chooses Y (to add more to the cart), it will loop back to the top where it asks user to choose food and drinks
		cout << "Total price is RM ";
		if (option == 'D' || option == 'd')
		{
			cout << total;
		}
		else if (option == 'T' || option == 't')
		{
			cout << total + TAKEAWAYEXTRA;
		}
	}
	else
		cout << "\t\tYou've entered the wrong input, please try again." << endl;
	//if user enters input other than F and D, this will be displayed

	string option7, card;
	double paid, balance;
	do {
		cout << "\n\t\tPlease choose your preferred payment method :" << endl;
		cout << "\t\t1: Cash - (C)" << endl;
		cout << "\t\t2: Touch N Go - (TNG)" << endl;
		cout << "\t\t3: Maybank QR - (MQR)" << endl;
		cout << "\t\t4: Visa - (V)" << endl;
		cout << "\t\t5: Debit / Credit Card - (DC)" << endl;
		cout << "\t\tI preferred to pay by ";
		cin >> option7;
	} while (option7 != "C" && option7 != "c" && option7 != "TNG" && option7 != "tng" && option7 != "MQR" && option7 != "mqr" && option7 != "V" && option7 != "v" && option7 != "DC" && option7 != "dc");
	if (option7 == "C" || option7 == "c")
	{
		cout << "\t\tAmount paid >> RM ";
		cin >> paid;
		balance = paid - total;
		cout << "\t\tBalance >> RM " << balance;
	}
	else if (option7 == "TNG" || option7 == "tng" || option7 == "MQR" || option7 == "mqr")
	{
		cout << "Please scan the QR code displayed on the screen. Thankiuuu ~~";
	}
	else if (option7 == "V" || option7 == "v" || option7 == "DC" || option7 == "dc") {
		cout << "\t\tDo you wish to pay (P) or wave (W)? :D";
		cin >> card;
		if (card == "P" || card == "p")
			cout << "Please hold on a minute...";
		else if (card == "W" || card == "w")
			cout << "\t\tPlease wave your card here :D";
	}
	return 0;
}

void WesternFoodOrdering(string option3, FoodItem westernFood[], double& price, double& total, int& quantity, char& ans)
{

	string option4;
	do {
		//Print out the western food list
		std::cout << "Western food" << endl;
		for (int i = 0; i < 5; ++i)
		{
			cout << i + 1 << ") " << westernFood[i].name << " (" << westernFood[i].code << ") - RM " << westernFood[i].price << endl;
		}
		cin >> option4;
		if (option4 != "FCC" && option4 != "fcc" && option4 != "FC" && option4 != "fc" && option4 != "S" && option4 != "s" && option4 != "P" && option4 != "p" && option4 != "B" && option4 != "b")
			std::cout << "\t\t*******Wrong input dear :V*******";
	} while (option4 != "FCC" && option4 != "fcc" && option4 != "FC" && option4 != "fc" && option4 != "S" && option4 != "s" && option4 != "P" && option4 != "p" && option4 != "B" && option4 != "b");
	cout << "\t\tPlease enter the quantity >> ";
	cin >> quantity;

	if (option4 == "FCC" || option4 == "fcc") {
		price = 12 * quantity;
		total += price;
	}
	else if (option4 == "FC" || option4 == "fc") {
		price = 14.50 * quantity;
		total += price;
	}
	else if (option4 == "S" || option4 == "s") {
		price = 10.50 * quantity;
		total += price;
	}
	else if (option4 == "P" || option4 == "p") {
		price = 12.50 * quantity;
		total += price;
	}
	else if (option4 == "B" || option4 == "b") {
		price = 5.50 * quantity;
		total += price;
	}

	cout << "Do you wish to add more to your cart? :D (y/n) >> ";
	cin >> ans;


}

