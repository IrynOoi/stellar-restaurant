#include <iostream>
#include <iomanip>
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
struct Receipt
{
	string name;
	int quantity;
	double pricePerEach;
};
Receipt receipt[20];


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

//global variables
double total = 0, price, TOTAL = 0, paid, balance, pricePerEach;
int quantity, order = 0, k = 0;
char option;
string name, ans, paymentmethod, opt7;
string Paymentmethod[5] = { "Cash","Touch N Go","Maybank QR","Visa","Debit / Credit Card" };

//function declaration (void for all to pass multiple value back to main)
void WesternFoodOrdering(string* name, int* quantity, double* pricePerEach);
void LocalFoodOrdering(string* name, int* quantity, double* pricePerEach);
void Drink(string* name, int* quantity, double* pricePerEach);
void calculation(double* TOTAL);
void Payment(double* Paid, double* Balance, string* paymentmethod, string* opt7);
void DisplayReceipt(double TOTAL, double Paid, double Balance, int order, string opt7);

int main()
{	// Define arrays for food items

	char option2;
	string option3; //option3 is a string since it has more than one alphabet
	string answer;
	int i = 0;

	//Display our homepage
	cout << "*************************************************************************" << endl;
	cout << "\t\t\tSTELLAR RESTAURANT" << endl;
	cout << "*************************************************************************" << endl;
	do {
		cout << "\tWelcome to our restaurant. You can start ordering by selecting " << endl;
		cout << "\t\tDINE IN (D)\t\tTAKE AWAY (T)" << endl;
		cout << "\t\t\tYour selection >> ";
		cin >> option;
		if (option != 'D' && option != 'd' && option != 'T' && option != 't')
			//put && because if user didn't enter one of it, all these statements will be false?
			cout << "\t\tYou've entered the wrong input :C" << endl;
	} while (option != 'D' && option != 'd' && option != 'T' && option != 't');
	/*The page will keep displaying welcome to ........... to ask user to choose whether he or she wants to dine in or take away if
		 the user didn't enter the correct input*/
	if (option == 'T' || option == 't' || option == 'D' || option == 'd')
	{
		do
		{
			do {
				order++;
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

					//Western food
					if (option3 == "WF" || option3 == "wf")
					{
						WesternFoodOrdering(&name, &quantity, &pricePerEach);
						receipt[i].quantity = quantity;
						receipt[i].name = name;
						receipt[i].pricePerEach = pricePerEach;
						i++;
						cout << "Do you wish to add more to your cart? :D (y/n) >> ";
						cin >> answer;
						break;
					}
					//Local food
					else if (option3 == "LF" || option3 == "lf")
					{
						LocalFoodOrdering(&name, &quantity, &pricePerEach);
						receipt[i].quantity = quantity;
						receipt[i].name = name;
						receipt[i].pricePerEach = pricePerEach;
						i++;
						cout << "Do you wish to add more to your cart? :D (y/n) >> ";
						cin >> answer;
						break;
					}
				}
				//Drinks
				else if (option2 == 'D' || option2 == 'd')
				{
					Drink(&name, &quantity, &pricePerEach);
					receipt[i].quantity = quantity;
					receipt[i].name = name;
					receipt[i].pricePerEach = pricePerEach;
					i++;
					cout << "Do you wish to add more to your cart? :D (y/n) >> ";
					cin >> answer;
					break;
				}
				else
					cout << "\tYou've entered the wrong input, please try again.";
			} while (option2 != 'F' && option2 != 'f' && option2 != 'D' && option2 != 'd');
			//if the user chooses other than F and D, it will loop back to the top where it asks user to choose food and drinks
		} while (answer == "Y" || answer == "y");
		//if the user chooses Y (to add more to the cart), it will loop back to the top where it asks user to choose food and drinks

		/*for (i = 0; i != 0; i++)
		{
			receipt[i].price = price;
			receipt[i].total = total;
			receipt[i].quantity = quantity;
		}*/
		calculation(&TOTAL);
		TOTAL = TOTAL;
	}
	else
		cout << "\t\tYou've entered the wrong input, please try again." << endl;
	//if user enters input other than F and D, this will be displayed
	Payment(&paid, &balance, &paymentmethod, &opt7);
	paymentmethod = paymentmethod;
	DisplayReceipt(TOTAL, paid, balance, order, opt7);

	return 0;
}

//calculation function definition
void calculation(double* TOTAL)
{
	cout << "Total price is RM ";
	if (option == 'D' || option == 'd')
	{
		*TOTAL = total;
		cout << "Total >> RM" << *TOTAL;
	}
	else if (option == 'T' || option == 't')
	{
		*TOTAL = total + TAKEAWAYEXTRA;
		cout << "RM0.20 is charged for takeaway.";
		cout << "\nTotal >> RM" << *TOTAL;
	}
}

//western food ordering function definition
void WesternFoodOrdering(string* name, int* quantity, double* pricePerEach)
{
	string option4;
	do {
		//Print out the western food list
		cout << "\t\tWestern food" << endl;
		for (int i = 0; i < 5; ++i)
		{
			cout << "\t\t" << i + 1 << ") " << westernFood[i].name << " (" << westernFood[i].code << ") - RM " << westernFood[i].price << endl;
		}
		cout << "\t\tYour selection : ";
		cin >> option4;
		if (option4 != "FCC" && option4 != "fcc" && option4 != "FC" && option4 != "fc" && option4 != "S" && option4 != "s" && option4 != "P" && option4 != "p" && option4 != "B" && option4 != "b")
			std::cout << "\t\t*******Wrong input dear :V*******" << endl;
	} while (option4 != "FCC" && option4 != "fcc" && option4 != "FC" && option4 != "fc" && option4 != "S" && option4 != "s" && option4 != "P" && option4 != "p" && option4 != "B" && option4 != "b");
	cout << "\t\tPlease enter the quantity >> ";
	cin >> *quantity;
	//if user enters alphabet
	while (1)
	{
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\t\tPlease enter a number." << endl
				<< "\t\tPlease enter the quantity >> ";
			cin >> *quantity;
		}
		if (!cin.fail())
			break;
	}
	if (option4 == "FCC" || option4 == "fcc") {
		price = 12 * *quantity;
		total += price;
		*name = westernFood[0].name;
		*pricePerEach = westernFood[0].price;
	}
	else if (option4 == "FC" || option4 == "fc") {
		price = 14.50 * *quantity;
		total += price;
		*name = westernFood[1].name;
		*pricePerEach = westernFood[1].price;
	}
	else if (option4 == "S" || option4 == "s") {
		price = 10.50 * *quantity;
		total += price;
		*name = westernFood[2].name;
		*pricePerEach = westernFood[2].price;
	}
	else if (option4 == "P" || option4 == "p") {
		price = 12.50 * *quantity;
		total += price;
		*name = westernFood[3].name;
		*pricePerEach = westernFood[3].price;
	}
	else if (option4 == "B" || option4 == "b") {
		price = 5.50 * *quantity;
		total += price;
		*name = westernFood[4].name;
		*pricePerEach = westernFood[4].price;
	}
}

//local food ordering function definition
void LocalFoodOrdering(string* name, int* quantity, double* pricePerEach)
{
	string option5;
	do {
		//Print out the local food list
		cout << "\t\tLocal food" << endl;
		for (int i = 0; i < 5; ++i)
		{
			cout << "\t\t" << i + 1 << ") " << localFood[i].name << " (" << localFood[i].code << ") - RM " << localFood[i].price << endl;
		}
		cout << "\t\tYour selection : ";
		cin >> option5;
		if (option5 != "NL" && option5 != "nl" && option5 != "AL" && option5 != "al" && option5 != "CM" && option5 != "cm" && option5 != "RC" && option5 != "rc" && option5 != "NK" && option5 != "nk")
			cout << "Hmmmm....seems like you've entered wrong input. Please try againnnnnnnnnnnnnnnnnnnnnnnnnnnn" << endl;
	} while (option5 != "NL" && option5 != "nl" && option5 != "AL" && option5 != "al" && option5 != "CM" && option5 != "cm" && option5 != "RC" && option5 != "rc" && option5 != "NK" && option5 != "nk");
	cout << "\t\tPlease enter the quantity >> ";
	cin >> *quantity;
	//if user enters alphabet
	while (1)
	{
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\t\tPlease enter a number." << endl
				<< "\t\tPlease enter the quantity >> ";
			cin >> *quantity;
		}
		if (!cin.fail())
			break;
	}
	if (option5 == "NL" || option5 == "nl") {
		price = 7 * *quantity;
		total += price;
		*name = localFood[0].name;
		*pricePerEach = localFood[0].price;
	}
	else if (option5 == "AL" || option5 == "al") {
		price = 7 * *quantity;
		total += price;
		*name = localFood[1].name;
		*pricePerEach = localFood[1].price;
	}
	else if (option5 == "CM" || option5 == "cm") {
		price = 7 * *quantity;
		total += price;
		*name = localFood[2].name;
		*pricePerEach = localFood[2].price;
	}
	else if (option5 == "RC" || option5 == "rc") {
		price = 1.50 * *quantity;
		total += price;
		*name = localFood[3].name;
		*pricePerEach = localFood[3].price;
	}
	else if (option5 == "NK" || option5 == "nk") {
		price = 7 * *quantity;
		total += price;
		*name = localFood[4].name;
		*pricePerEach = localFood[4].price;
	}
}

void Drink(string* name, int* quantity, double* pricePerEach)
{
	string option6;
	do {
		//print out drinks list
		cout << "\t\tDrink Items:" << endl;
		for (int i = 0; i < 5; ++i) {
			cout << "\t\t" << i + 1 << ") " << drinks[i].name << " (" << drinks[i].code << ") - RM " << drinks[i].price << endl;
		}
		cout << "\t\tYour selection : ";
		cin >> option6;
		if (option6 != "M" && option6 != "m" && option6 != "TT" && option6 != "tt" && option6 != "KO" && option6 != "ko" && option6 != "LT" && option6 != "lt" && option6 != "OJ" && option6 != "oj")
			cout << "\t\tni hao :D wrong input le :C" << endl;
	} while (option6 != "M" && option6 != "m" && option6 != "TT" && option6 != "tt" && option6 != "KO" && option6 != "ko" && option6 != "LT" && option6 != "lt" && option6 != "OJ" && option6 != "oj");
	cout << "\t\tPlease enter the quantity >> ";
	cin >> *quantity;
	//if user enters alphabet
	while (1)
	{
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\t\tPlease enter a number." << endl
				<< "\t\tPlease enter the quantity >> ";
			cin >> *quantity;
		}
		if (!cin.fail())
			break;
	}
	if (option6 == "M" || option6 == "m") {
		price = 2.50 * *quantity;
		total += price;
		*name = drinks[0].name;
		*pricePerEach = drinks[0].price;

	}
	else if (option6 == "T" || option6 == "tt") {
		price = 2.50 * *quantity;
		total += price;
		*name = drinks[1].name;
		*pricePerEach = drinks[1].price;
	}
	else if (option6 == "KO" || option6 == "ko") {
		price = 2 * *quantity;
		total += price;
		*name = drinks[2].name;
		*pricePerEach = drinks[2].price;
	}
	else if (option6 == "LT" || option6 == "lt") {
		price = 3 * *quantity;
		total += price;
		*name = drinks[3].name;
		*pricePerEach = drinks[3].price;
	}
	else if (option6 == "OJ" || option6 == "oj") {
		price = 3.50 * *quantity;
		total += price;
		*name = drinks[4].name;
		*pricePerEach = drinks[4].price;
	}
}
//payment function definition
void Payment(double* Paid, double* Balance, string* paymentmethod, string* opt7)
{
	string option7, card;
	do {
		cout << "\n\t\tPlease choose your preferred payment method :" << endl;
		cout << "\t\t1: Cash - (C)" << endl;
		cout << "\t\t2: Touch N Go - (TNG)" << endl;
		cout << "\t\t3: Maybank QR - (MQR)" << endl;
		cout << "\t\t4: Visa - (V)" << endl;
		cout << "\t\t5: Debit / Credit Card - (DC)" << endl;
		cout << "\t\tI preferred to pay by ";
		cin >> option7;
		if (option7 != "C" && option7 != "c" && option7 != "TNG" && option7 != "tng" && option7 != "MQR" && option7 != "mqr" && option7 != "V" && option7 != "v" && option7 != "DC" && option7 != "dc")
		{
			cout << "\tSorry we do not offer the following payment method. Please enter another payment method that is listed." << endl;
		}
	} while (option7 != "C" && option7 != "c" && option7 != "TNG" && option7 != "tng" && option7 != "MQR" && option7 != "mqr" && option7 != "V" && option7 != "v" && option7 != "DC" && option7 != "dc");

	if (option7 == "C" || option7 == "c")
	{
		//if user chooses dine in
		if (option == 'D' || option == 'd')
		{
			cout << "\t\tAmount paid >> RM ";
			cin >> paid;
			//if user enters alphabet
			while (1)
			{
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\t\tPlease enter a number." << endl
						<< "\t\tAmount paid >> RM ";
					cin >> paid;
				}
				if (!cin.fail())
					break;
			}
			balance = paid - total;
			cout << "\t\tBalance >> RM " << balance;
		}
		//if user chooses takeaway
		else {
			cout << "\t\tAmount paid >> RM ";
			cin >> paid;
			//if user enters alphabet
			while (1)
			{
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\t\tPlease enter a number." << endl
						<< "\t\tAmount paid >> RM ";
					cin >> paid;
				}
				if (!cin.fail())
					break;
			}
			balance = paid - TOTAL;
			cout << "\t\tBalance >> RM " << balance;
		}
		*paymentmethod = Paymentmethod[0];
		*opt7 = "C";
	}
	else if (option7 == "TNG" || option7 == "tng" || option7 == "MQR" || option7 == "mqr")
	{
		cout << "Please scan the QR code displayed on the screen. Thankiuuu ~~";
		if (option7 == "TNG" || option7 == "tng")
			*paymentmethod = Paymentmethod[1];
		*opt7 = "TNG";
		if (option7 == "MQR" || option7 == "mqr")
			*paymentmethod = Paymentmethod[2];
		*opt7 = "MQR";
	}
	else if (option7 == "V" || option7 == "v" || option7 == "DC" || option7 == "dc") {

		if (option7 == "V" || option7 == "v")
			*paymentmethod = Paymentmethod[3];
		*opt7 = "V";
		if (option7 == "DC" || option7 == "dc")
			*paymentmethod = Paymentmethod[4];
		*opt7 = "DC";
		cout << "\t\tDo you wish to pay (P) or wave (W)? :D >> ";
		cin >> card;
		if (card == "P" || card == "p")
			cout << "Please hold on a minute...";
		else if (card == "W" || card == "w")
			cout << "\t\tPlease wave your card here :D";
		*opt7 = option7;
	}
}
void DisplayReceipt(double TOTAL, double Paid, double Balance, int order, string opt7)
{
	int j;
	cout << "\n\n\n\n***********************************************************************" << endl;
	cout << "\t\t\t\tRECEIPT" << endl;
	cout << "***********************************************************************" << endl;
	cout << "  Item Name" << setw(25) << "Item Quantity" << setw(7) << "Price" << setw(10) << "Subtotal" << endl;
	for (j = 0; j < order; j++)
	{
		cout << j + 1 << ": " << receipt[j].name;
		cout << setw(10) << receipt[j].quantity << setw(10) << receipt[j].pricePerEach << setw(10) << receipt[j].quantity * receipt[j].pricePerEach << endl;
	}
	cout << "\nPayment Method:\t " << paymentmethod;
	cout << "\nGrand Total   :\t" << TOTAL << endl;
	if (opt7 == "C")
	{
		cout << "Paid        :\t" << Paid << endl;
		cout << "Balance     :\t" << Balance << endl;
	}
	else
		cout << "\nPaid. Thankyou, please come again.";
}