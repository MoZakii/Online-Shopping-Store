#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>
#include<fstream>
#include <sstream>
#include <windows.h>
#include <stdio.h>
using namespace std;

const int maxShoppers = 25, maxOwners = 25, maxProds = 10, maxPass = 32;
int LogIndex = maxOwners,year = 0, day = 0, month = 0, LogID = 0, deletes = 1;

struct views {

	int x;
	int y;

};
struct num {
	int nump = 0;
	int index = 0;
	views num[100];

}c;
struct  save
{
	views sav[100];
	int amount[100];
	double sub[100];

}k;

struct Clothing
{
	char Size;
	char Type;
	string Color;
};
struct Address {
	string Country;
	string City;
};
struct numm {
	int nump = 0;
	int index = 0;
}h;

struct cart {
	int quantity;
	string buyproduct = { 0 };
	double index;
	double index2;
	double price;
	string shop;
	int arri;
	int arrj;
	double subtotal = 0;
} shopperCart[100];
struct Product
{
	string productName = { 0 };
	double productPrice = 0;
	double oldPrice = 0;
	string Category;
	Clothing Clothes;
	int Quantity = 0;
	int counter = 0;
	double sum = 0;
	double avgRating;
	int month = 0;
	int day = 0;
};
struct Shop
{
	string ShopName;
	Address Add;
	string Category;
	Product products[maxProds];
	int countProd = 0;
};
struct counts {
	int countOwn = 0;
	int countShopper = 0;
}s;
struct Owner
{
	string Name;
	int ID;
	char Password[maxPass];
	int PassNum;
	int Age;
	string Gender;
	Address Add;
	Shop Shops;
} Owners[maxOwners];
struct shopper {
	string name;
	int id;
	char pass[maxPass];
	int passnum;
	int age;
	string gender;
	Address Add;
	double purchaseHistory[10];
	int days[10];
	int months[10];
	int purchases = 0;
}Shoppers[maxShoppers];

void Open();
int login();
void registration();
void update(int j);
void SLchoice();
void sChoice();
void del(int j);
void save();
int RegOwner();
void RegShop(int);
void OLchoice();
void OEchoice();
int Lowner();
void Eowner(int);
void ProdChoice();
void addProds(int);
void removeProds(int);
void editProds(int j);
void viewProds(int);
void RegChoice();
void removeReg(int);
void Rating();
void discount(int);
void purchaseHistory(int k);
void search();
void viewproducts();
void chooseproduct();
void viewcart();
void deletee();
void cart();
void discCheck();
void gifts();
void ByCategory();
void fchoice();
void filters();
void priceFilter();
void ShopFilter();

int main() {

	Open();
	char c, choice;
	bool flag = true;
	cout << "**************************************************----------------******************************************************\n";
	cout << "************************************---- WELCOME TO THE ONLINE SHOPPING STORE ----**************************************\n";
	cout << "**************************************************----------------******************************************************\n\n\n";
	SYSTEMTIME st;
	GetSystemTime(&st);
	day = st.wDay;
	month = st.wMonth;
	year = st.wYear;
	discCheck();
	system("cls");
	cout << "\n\nToday's Date : " << day << " / " << month << " / "<< year <<" \n\n";

	do {
		cout << " [ 1 ] Shopper. \n\n";
		cout << " [ 2 ] Shop Owner. \n\n";
		cout << " [ X ] Exit. \n\n";
		cout << " Choice : ";
		cin >> choice;
		system("cls");
		if (choice == '1') {
			SLchoice();
			if (LogIndex != maxShoppers) {
				sChoice();
			}
		}
		else if (choice == '2') {
			RegChoice();
		}
		else if (choice == 'x' || choice == 'X') {
			break;
		}
		else {
			cout << "\n\n!! Invalid choice. !!\n\n";
			system("pause");
			system("cls");
		}
		if ((choice == '1' || choice == '2' || choice == 'x' || choice == 'X') && LogIndex != maxOwners && deletes != 0) {
			while (flag) {
				cout << "Would you like to Log Out (Y/N)? ";
				cin >> c;
				if ((c == 'Y') || (c == 'y')) {
					LogIndex = -1;
					choice = 'y';
					cout << "You logged out Successfully\n";
					system("pause");
					system("cls");
					flag = false;
					break;
				}
				else if (c == 'N' || c == 'n') {
					if (choice == '1') {
						sChoice();
					}
					else if (choice == '2') {
						OEchoice();
						ProdChoice();
					}
				}
				else {
					cout << "Invalid Choice";
				}
			}
		}
	} while (choice != '1' || choice != '2' || choice != 'x' || choice != 'X');
	save();
	return 0;
}

void Open() {

	ifstream Owner, Shopper, Products;
	Owner.open("Owners.txt");
	Owner >> s.countOwn;
	for (int i = 0; i < s.countOwn; i++) {
		Owner.ignore();
		getline(Owner, Owners[i].Name);
		getline(Owner, Owners[i].Gender);
		getline(Owner, Owners[i].Add.Country);
		getline(Owner, Owners[i].Add.City);
		getline(Owner, Owners[i].Shops.ShopName);
		getline(Owner, Owners[i].Shops.Category);
		getline(Owner, Owners[i].Shops.Add.Country);
		getline(Owner, Owners[i].Shops.Add.City);
		Owner >> Owners[i].ID;
		Owner >> Owners[i].Age;
		Owner >> Owners[i].PassNum;
		Owner >> Owners[i].Password;
	}
	Shopper.open("Shopper.txt");
	Shopper >> s.countShopper;
	for (int i = 0; i < s.countShopper; i++) {
		Shopper.ignore();
		getline(Shopper, Shoppers[i].name);
		getline(Shopper, Shoppers[i].gender);
		getline(Shopper, Shoppers[i].Add.Country);
		getline(Shopper, Shoppers[i].Add.City);
		Shopper >> Shoppers[i].id;
		Shopper >> Shoppers[i].age;
		Shopper >> Shoppers[i].passnum;
		Shopper >> Shoppers[i].pass;
		Shopper >> Shoppers[i].purchases;
		if (Shoppers[i].purchases != 0) {
			for (int j = 0; j < Shoppers[i].purchases; j++) {
				Shopper >> Shoppers[i].purchaseHistory[j];
				Shopper >> Shoppers[i].days[j];
				Shopper >> Shoppers[i].months[j];
			}
		}
	}
	Products.open("Products.txt");
	for (int i = 0; i < maxOwners; i++) {
		Products >> Owners[i].Shops.countProd;
		Products.ignore();
		Owners[0].Shops.products[1].productPrice;
		if (Owners[i].Shops.countProd != 0) {
			for (int j = 0; j < Owners[i].Shops.countProd; j++) {
				getline(Products, Owners[i].Shops.products[j].productName);
				getline(Products, Owners[i].Shops.products[j].Category);
				if (Owners[i].Shops.products[j].Category == "Clothing") {

					getline(Products, Owners[i].Shops.products[j].Clothes.Color);
					Products >> Owners[i].Shops.products[j].Clothes.Type;
					Products >> Owners[i].Shops.products[j].Clothes.Size;
					Products >> Owners[i].Shops.products[j].productPrice;
					Products >> Owners[i].Shops.products[j].Quantity;
					Products >> Owners[i].Shops.products[j].avgRating;
					Products >> Owners[i].Shops.products[j].oldPrice;
					Products >> Owners[i].Shops.products[j].sum;
					Products >> Owners[i].Shops.products[j].counter;
					Products >> Owners[i].Shops.products[j].month;
					Products >> Owners[i].Shops.products[j].day;
					Products.ignore();
				}
				else {
					Products >> Owners[i].Shops.products[j].productPrice;
					Products >> Owners[i].Shops.products[j].Quantity;
					Products >> Owners[i].Shops.products[j].avgRating;
					Products >> Owners[i].Shops.products[j].oldPrice;
					Products >> Owners[i].Shops.products[j].sum;
					Products >> Owners[i].Shops.products[j].counter;
					Products >> Owners[i].Shops.products[j].month;
					Products >> Owners[i].Shops.products[j].day;
					Products.ignore();
				}
			}
		}
	}
	Owner.close();
	Shopper.close();
	Products.close();

}

void save() {
	ofstream Owner, Shopper, Products;
	Owner.open("Owners.txt", ios::trunc);
	Owner << s.countOwn << endl;
	for (int i = 0; i < s.countOwn; i++) {
		if (Owners[i].ID != 0) {
			Owner << Owners[i].Name << endl << Owners[i].Gender << endl << Owners[i].Add.Country << endl << Owners[i].Add.City << endl << Owners[i].Shops.ShopName << endl << Owners[i].Shops.Category << endl << Owners[i].Shops.Add.Country << endl << Owners[i].Shops.Add.City << endl << Owners[i].ID << endl << Owners[i].Age << endl << Owners[i].PassNum << endl << Owners[i].Password << '\n';
		}
	}
	Shopper.open("Shopper.txt", ios::trunc);
	Shopper << s.countShopper << endl;
	for (int i = 0; i < s.countShopper; i++) {
		if (Shoppers[i].id != 0) {
			Shopper << Shoppers[i].name << endl << Shoppers[i].gender << endl << Shoppers[i].Add.Country << endl << Shoppers[i].Add.City << endl << Shoppers[i].id << endl << Shoppers[i].age << endl << Shoppers[i].passnum << endl << Shoppers[i].pass << endl;
			Shopper << Shoppers[i].purchases << endl;
			if (Shoppers[i].purchases != 0) {
				for (int j = 0; j < Shoppers[i].purchases; j++) {
					Shopper << Shoppers[i].purchaseHistory[j] << endl << Shoppers[i].days[j] << endl << Shoppers[i].months[j] << endl;
				}
			}
		}
	}
	Products.open("Products.txt", ios::trunc);
	for (int i = 0; i < maxOwners; i++) {
		Products << Owners[i].Shops.countProd << endl;
		if (Owners[i].Shops.countProd != 0) {
			for (int j = 0; j < Owners[i].Shops.countProd; j++) {
				if (Owners[i].Shops.Category == "Clothing") {
					Products << Owners[i].Shops.products[j].productName << endl << Owners[i].Shops.products[j].Category << endl << Owners[i].Shops.products[j].Clothes.Color << endl << Owners[i].Shops.products[j].Clothes.Type << endl << Owners[i].Shops.products[j].Clothes.Size << endl << Owners[i].Shops.products[j].productPrice << endl << Owners[i].Shops.products[j].Quantity << '\n' << Owners[i].Shops.products[j].avgRating << endl << Owners[i].Shops.products[j].oldPrice << endl << Owners[i].Shops.products[j].sum << endl << Owners[i].Shops.products[j].counter << endl << Owners[i].Shops.products[j].month << endl << Owners[i].Shops.products[j].day << endl;
				}
				else {
					Products << Owners[i].Shops.products[j].productName << endl << Owners[i].Shops.products[j].Category << endl << Owners[i].Shops.products[j].productPrice << endl << Owners[i].Shops.products[j].Quantity << '\n' << Owners[i].Shops.products[j].avgRating << endl << Owners[i].Shops.products[j].oldPrice << endl << Owners[i].Shops.products[j].sum << endl << Owners[i].Shops.products[j].counter << endl << Owners[i].Shops.products[j].month << endl << Owners[i].Shops.products[j].day << endl;
				}
			}
		}
	}
	Owner.close();
	Shopper.close();
	Products.close();
}

void sChoice()
{
	char choice, cont;
	system("cls");
	do {
		cout << "\n Press -- 1 -- To Search For A Product. \n\n Press -- 2 -- To View All Products. \n\n Press -- 3 -- To Edit Your Information. \n\n Press -- 4 -- To view your Purchase History. \n\n Press -- 5 -- To Delete Your Account.  \n\n Press -- 6 -- To send Gifts. \n\n Press -- 7 -- Use Filters. \n\n";
		cout << "Choice : ";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case '1':
			search();
			break;
		case '2':
			viewproducts();
			break;
		case '3':
			update(LogIndex);
			break;
		case '4':
			purchaseHistory(LogIndex);
			break;
		case '5':
			del(LogIndex);
			cont = 'n';
			break;
		case '6':
			gifts();
			break;
		case '7':
			fchoice();
			break;
		default:
			cout << "\n\n!!!  Invalid Choice  !!!\n\n";
			break;
		}
		system("pause");
		system("cls");
		if (deletes != 0) {
			cout << "\n\nPress -- Y -- To Return To Menu. \n\npress -- E -- To Exit\n\n";
			cout << "Choice  : ";
			cin >> cont;
		}
	} while (cont == 'y' || cont == 'Y');
}

void search()
{
	string name;
	char add;
	bool flag = false;
	int x = 1, amount, l, z;
	cout << "\n\nEnter the Product's name: ";
	cin >> name;
	cout << "\n\n";

	for (int i = 0; i < maxShoppers; i++)
	{
		for (int j = 0; j < maxProds; j++)
		{
			if (name == Owners[i].Shops.products[j].productName)
			{
				cout << "-Product Name- " << "-  Product Price  -" << "-  Product Category  -" << "-  Product Quantity  -" << "-  Avg. Rating  -" << "- Size -" << "- Type -" << "- Color -" << "\n" << endl;
				if (Owners[i].Shops.products[j].Category == "Clothing") {
					cout << x << ". " << Owners[i].Shops.products[j].productName << "\t\t" << Owners[i].Shops.products[j].productPrice << "\t\t" << Owners[i].Shops.products[j].Category << "\t\t" << Owners[i].Shops.products[j].Quantity << "\t\t\t" << Owners[i].Shops.products[j].avgRating << "          " << Owners[i].Shops.products[j].Clothes.Size << "       " << Owners[i].Shops.products[j].Clothes.Type << "      " << Owners[i].Shops.products[j].Clothes.Color << "\n";
				}
				else {
					cout << x << ". " << Owners[i].Shops.products[j].productName << "\t\t" << Owners[i].Shops.products[j].productPrice << "\t\t" << Owners[i].Shops.products[j].Category << "\t\t" << Owners[i].Shops.products[j].Quantity << "\t\t\t" << Owners[i].Shops.products[j].avgRating << "\n";
				}
				flag = true;
				l = i;
				z = j;
				break;
			}

		}

	}if (flag == false)
		cout << "                                     Out Of Stock. \n\n\n ";
	else {
		cout << "\n\nAdd to to Cart [ Y / N ] :\n\n";
		cout << "choice : ";
		cin >> add;
		if (add == 'y' || add == 'Y') {

			cout << "\n\n How many do you want ?                                  ***press .0. to exit.*** \n\n ";
			cout << "Amount : ";
			cin >> amount;

			k.amount[c.index] = amount;
			Owners[l].Shops.products[z].Quantity -= amount;
			k.sav[c.index].x = l;
			k.sav[c.index].y = z;
			c.nump++;
			c.index++;

		}

	}
	system("pause");
	cart();
}

void viewproducts()
{

	char choice;

	int z = 0;
	int number = 1;
	cout << "-Product Name- " << "-  Product Price  -" << "-  Product Category  -" << "-  Product Quantity  -" << "-  Avg. Rating  -" << "- Size -" << "- Type -" << "- Color -" << "\n" << endl;
	for (int i = 0; i < maxShoppers; i++)
	{
		for (int j = 0; j < maxProds; j++)
		{
			if (Owners[i].Shops.products[j].productPrice != 0)
			{
				if (Owners[i].Shops.products[j].Category == "Clothing") {
					cout << number << ". " << Owners[i].Shops.products[j].productName << "\t\t" << Owners[i].Shops.products[j].productPrice << "$\t\t" << Owners[i].Shops.products[j].Category << "\t\t" << Owners[i].Shops.products[j].Quantity << "\t\t\t" << Owners[i].Shops.products[j].avgRating << "          " << Owners[i].Shops.products[j].Clothes.Size << "       " << Owners[i].Shops.products[j].Clothes.Type << "      " << Owners[i].Shops.products[j].Clothes.Color << "\n";
				}
				else {
					cout << number << ". " << Owners[i].Shops.products[j].productName << "\t\t" << Owners[i].Shops.products[j].productPrice << "$\t\t" << Owners[i].Shops.products[j].Category << "\t\t" << Owners[i].Shops.products[j].Quantity << "\t\t\t" << Owners[i].Shops.products[j].avgRating << "\n";
				}

				c.num[z].x = i;
				c.num[z].y = j;
				z++;
				number++;
			}
		}
	}
	cout << "\n\nDo You Want To Buy Anything ? [ Y / N ]. \n\n";
	cout << "choice : ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y') {
		chooseproduct();
		cart();
	}
	else
	{
		sChoice();
	}


}

void chooseproduct() {


	int searchnum;
	int amount;
	bool done = true;
	cout << " \n\n Enter The Number Of Product You Want To Add To Cart : \n\n";
	cout << " Choice : ";
	cin >> searchnum;

	do {
		cout << "\n\n How many do you want ?                                  ***press .0. to exit.*** \n\n ";
		cout << "Amount : ";
		cin >> amount;
		if (amount <= Owners[c.num[searchnum - 1].x].Shops.products[c.num[searchnum - 1].y].Quantity) {
			if (amount != 0) {
				cout << "\n\n  *-Your Product was added to cart-* \n\n" << endl;
				k.amount[c.index] = amount;
				Owners[c.num[searchnum - 1].x].Shops.products[c.num[searchnum - 1].y].Quantity -= amount;
				k.sav[c.index].x = c.num[searchnum - 1].x;
				k.sav[c.index].y = c.num[searchnum - 1].y;
				c.nump++;
				c.index++;
				done = false;
				break;
			}
			else
				break;
		}
		else if (amount == 0)
			break;
		else
			cout << " \n\n Your desired amount is unavailable , there are only ( " << Owners[c.num[searchnum - 1].x].Shops.products[c.num[searchnum - 1].y].Quantity << " ) in stock \n\n" << endl;
	} while (done);
	system("pause");
	system("cls");
};

void viewcart() {

	double total = 0, x = 1;
	cout << "\n\n************************************ - YOUR CART - *************************************\n\n" << endl;
	cout << "    NAME \t  " << "    QUANTITY \t  " << "    PRICE  \n\n";

	for (int i = 0; i < c.nump; i++) {
		if (Owners[k.sav[i].x].Shops.products[k.sav[i].y].productPrice != 0) {
			if (k.amount[i] != 0) {
				k.sub[i] = (k.amount[i] * Owners[k.sav[i].x].Shops.products[k.sav[i].y].productPrice);
				cout << x << ". " << Owners[k.sav[i].x].Shops.products[k.sav[i].y].productName << "\t\t" << k.amount[i] << "\t\t" << k.sub[i] << "$\n" << endl;
				total += k.sub[i];
				x++;
				cout << "\n";
			}
		}
	}
	cout << endl << "\nTOTAL :  $" << total << endl;

}

void deletee() {

	system("cls");
	bool flag = true;
	int deleteNum, x = 1;
	viewcart();

	cout << "\n\nEnter The Number Of The Product You Want To Delete  : \n\n";
	cout << "Number : ";
	cin >> deleteNum;
	Owners[k.sav[deleteNum - 1].x].Shops.products[k.sav[deleteNum - 1].y].Quantity += k.amount[deleteNum - 1];
	k.amount[deleteNum - 1] = 0;
	for (int i = 0; i < c.nump; i++) {
		if (i > deleteNum - 1) {
			k.sav[i - 1].x = k.sav[i].x;
			k.sav[i - 1].y = k.sav[i].y;
			k.amount[i - 1] = k.amount[i];
			k.sub[i - 1] = k.sub[i];
		}
	}
	c.nump--;
	c.index--;

}

void cart() {

	double total;
	system("cls");
	bool flag = true, flag1 = true, del = true;
	char choice, ratechoice;
	do {
		system("cls");
		int x = 1;
		cout << "Press -- V --  to View receipt. \n\nPress -- R -- to Return to Shopping. \n\nPress -- D -- to Delete From Your Cart\n\nPress -- C --  To Your Cart.\n\n" << endl;
		cout << "Choice : ";
		cin >> choice;
		switch (choice)
		{
		case 'd':
		case 'D':
		{
			deletee();
			break;
		}
		case 'v':
		case 'V':
		{
			total = 0;
			for (int i = 0; i < c.nump; i++) {

				shopperCart[i].buyproduct = Owners[k.sav[i].x].Shops.products[k.sav[i].y].productName;
				shopperCart[i].price = Owners[k.sav[i].x].Shops.products[k.sav[i].y].productPrice;
				shopperCart[i].quantity = k.amount[i];

			}
			system("cls");
			cout << "\n\n********************************** TOTAL ITEMS *********************************\n\n\n" << endl;
			cout << "       NAME \t\t\t  " << "   QUANTITY \t\t\t  " << "    PRICE \n\n";
			for (int i = 0; i < c.nump; i++) {

				shopperCart[i].subtotal = (shopperCart[i].quantity * shopperCart[i].price);
				cout << x << ". " << shopperCart[i].buyproduct << "\t\t" << shopperCart[i].quantity << "\t\t" << shopperCart[i].subtotal << '$' << endl;
				total += shopperCart[i].subtotal;
				cout << "\n";
				x++;


			}
			cout << "\n\n\n********************** TOTAL PRICE *********************\n\n" << endl;
			cout << "Total price : " << total << "$\n";
			Shoppers[LogID - 1].purchases++;
			while (true) {
				int i = 0;
				if (Shoppers[LogID - 1].purchaseHistory[9] == 0) {
					if (Shoppers[LogID - 1].purchaseHistory[i] == 0) {
						Shoppers[LogID - 1].purchaseHistory[i] = total;
						Shoppers[LogID - 1].days[i] = day;
						Shoppers[LogID - 1].months[i] = month;
						break;
					}
				}
				else {
					for (int j = 0; j < 10; j++) {
						Shoppers[LogID - 1].purchaseHistory[j] = Shoppers[LogID - 1].purchaseHistory[j + 1];
						Shoppers[LogID - 1].days[j] = Shoppers[LogID - 1].days[j + 1];
						Shoppers[LogID - 1].months[j] = Shoppers[LogID - 1].months[j + 1];
					}
					Shoppers[LogID - 1].purchaseHistory[9] = total;
					Shoppers[LogID - 1].days[9] = day;
					Shoppers[LogID - 1].months[9] = month;
				}
				i++;
			}
			flag = false;
			do {
				cout << "Would you like to Rate a Product? (Y/N) ";
				cin >> ratechoice;
				if (ratechoice == 'Y' || ratechoice == 'y')
				{
					Rating();
				}
				else
				{
					break;
				}
			} while (ratechoice == 'Y' || ratechoice == 'y');

			for (int i = 0; i > c.nump; i++) {
				k.sav[i].x = 0;
				k.sav[i].y = 0;
				k.sub[i] = 0;
				k.amount[i] = 0;
				shopperCart[i].buyproduct = { 0 };
				shopperCart[i].price = 0;
				shopperCart[i].quantity = 0;
				shopperCart[i].subtotal = 1;

			}

			c.index = 0;
			c.nump = 0;

			system("pause");
			break;
		}

		case 'c':
		case 'C':
		{
			viewcart();
			cout << "\n\n";
			system("pause");
			break;
		}
		case 'R':
		case 'r':
		{

			system("cls");
			sChoice();
			flag1 = false;
			break;

		}
		default:
		{
			cout << "!!! Enter a valid choice !!!" << endl;

			break; \
		}
		}

	} while (flag);
}

void registration() {
	int i, j, k, passNum1, passNum2;
	char  pass1[maxPass], pass2[maxPass];
	bool flag = true, passFlag = true, genflag = true;
	char choice;

	system("cls");
	for (i = 0; i < maxShoppers; i++) {
		if (Shoppers[i].age == 0)
		{
			cout << "\n\nEnter your name : ";
			cin >> Shoppers[i].name;
			Shoppers[i].id = i + 1;
			cout << "\nYour ID is : " << Shoppers[i].id << endl;

			while (flag)
			{
				do
				{
					cout << "\nPassword (at least 6 digits): ";
					char a;
					passFlag = true;
					for (j = 0; j < maxPass;)
					{
						a = _getch();
						if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
						{
							pass1[j] = a;
							++j;
							cout << "*";
						}
						if (a == '\b' && j >= 1)
						{
							cout << "\b \b";
							--j;
						}
						if (a == '\r')
						{
							pass1[j] = '\0';
							break;
						}
						Shoppers[i].passnum = j;
						passNum1 = j;
					}
					cout << endl;
				} while (j <= 5);

				do
				{
					cout << "\nConfirm Password : ";
					char a;
					for (k = 0; k < maxPass;)
					{
						a = _getch();
						if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))

						{
							pass2[k] = a;
							++k;
							cout << "*";
						}
						if (a == '\b' && k >= 1)
						{
							cout << "\b \b";
							--k;
						}
						if (a == '\r')
						{
							pass2[k] = '\0';
							break;
						}
						passNum2 = k;
					}
					cout << endl;
				} while (k <= 5);

				if (passNum1 == passNum2)
				{
					for (int num = 0; num < passNum1; num++)
					{
						if (pass1[num] != pass2[num])
						{
							cout << "\nPasswords do not match" << endl;
							passFlag = false;
							break;
						}
					}
					if (passFlag)
					{
						for (int m = 0; m < passNum1; m++)
						{
							Shoppers[i].pass[m] = pass1[m];
						}
						flag = false;
						break;
					}
				}
				else
				{
					cout << "Passwords do not match" << endl;
					flag = true;
				}
			}
			cout << endl << "\nEnter Your Age : ";
			cin >> Shoppers[i].age;
			cout << "\nEnter Your Gender [ M / F ] : ";
			while (genflag)
			{
				cin >> choice;
				if (choice == 'M' || choice == 'm')
				{
					Shoppers[i].gender = "Male";
					genflag = false;
				}
				else if (choice == 'F' || choice == 'f')
				{
					Shoppers[i].gender = "Female";
					genflag = false;
				}
				else
				{
					cout << "Please Enter A Valid Gender [ M / F ] : ";
				}
			}
			Shoppers[i].gender = choice;
			cout << "\nEnter Your Address: \n\n";
			cout << "               Country : ";
			cin >> Shoppers[i].Add.Country;
			cout << "               City : ";
			cin >> Shoppers[i].Add.City;
			cout << endl << "\n ************ You Have Registered Successfully ************ \n\n" << endl;
			s.countShopper++;
			system("pause");
			break;
		}
	}

}

void SLchoice()
{
	char c;
	bool pass = true;
	char Loginchoice;

	do {

		do {
			system("cls");
			cout << "\n\n Press -- 1 -- To Login. \n\n Press -- 2 -- To Register\n\n";
			cout << "Choice :  ";
			cin >> Loginchoice;
			if (Loginchoice == '1') {
				LogIndex = login();
				pass = false;
			}
			else if (Loginchoice == '2') {
				registration();
			}
			else
				cout << "\n\n !!! Invalid Choice !!!\n\n";

		} while (pass);


		if (LogIndex == maxShoppers) {
			cout << "\n\n Would You Like To Try Again ?  [ Y / N ] \n\n ";
			cout << " Choice : ";
			cin >> c;
		}
		else {
			c = 'n';
		}
		system("cls");
	} while (c == 'y' || c == 'Y');
}

int login() {

	int j;
	bool flag;
	bool tri = false;
	int  i;
	char LogPass[maxPass];
	system("cls");
	cout << " \n Enter Your Data\n";
	cout << endl << "Enter your ID : ";
	cin >> LogID;
	char a;
	cout << endl << "Password : ";
	for (j = 0;;)
	{
		a = _getch();
		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
		{
			LogPass[j] = a;
			++j;
			cout << "*";
		}
		if (a == '\b' && j >= 1)
		{
			cout << "\b \b";
			--j;
		}
		if (a == '\r')
		{
			LogPass[j] = '\0';
			break;
		}
	}

	for (i = 0; i < maxShoppers; i++)
	{
		flag = true;
		if (j > Shoppers[i].passnum || j < Shoppers[i].passnum) {
			flag = false;
		}
		else if (j == Shoppers[i].passnum) {
			for (int x = 0; x < Shoppers[i].passnum; x++)
			{
				if (LogPass[x] != Shoppers[i].pass[x])
				{
					flag = false;
				}
			}
		}
		if (LogID == Shoppers[i].id && (flag))
		{
			cout << "\n\n ************************* You have successfully Logged In. ************************* \n\n";
			tri = false;
			system("pause");
			break;
		}
	}
	if (flag == false)
	{
		cout << "\n\n\nEither the ID or Password is incorrect\n\n" << endl;
		i = maxShoppers;
	}
	return i;
}

void update(int j) {

	char editchoices, gender, regedit, newPass1[maxPass], newPass2[maxPass], oldPass[maxPass];
	bool flagSame = true, flag = true, flagPass = true, flagnum = true;
	int l;
	cout << "\n\n\n ***************  Editing your information ****************************\n\n";
	cout << "Would You Like To Edit Your Registration Data. ?  [ Y / N ] ? : \n\n";
	cout << "Choice : ";
	cin >> editchoices;
	system("cls");
	while (editchoices == 'Y' || editchoices == 'y') {
		cout << "What Do You Want To Edit ? : \n\n" << endl;
		cout << "[ 1 ] Name. \n\n[ 2 ] Password. \n\n[ 3 ] Age. \n\n[ 4 ] Gender. \n\n[ 5 ] Address. \n\n" << endl;
		cout << "Choice : "; cin >> regedit;
		switch (regedit) {
		case '1': cout << "\n\nNew Name : ";
			cin >> Shoppers[j].name;
			break;

		case '2':
			int i, newPassNum1, newPassNum2;
			flag = true;
			do {
				do {
					cout << "\nOld Password : ";
					char a;
					flagPass = true;
					flagSame = true;
					for (l = 0;;)
					{
						a = _getch();
						if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
						{
							oldPass[l] = a;
							++l;
							cout << "*";
						}
						if (a == '\b' && l >= 1)
						{
							cout << "\b \b";
							--l;
						}
						if (a == '\r')
						{
							oldPass[l] = '\0';
							break;
						}
					}
				} while (l <= 5);
				if (l == Shoppers[j].passnum) {
					for (int o = 0; o < Shoppers[j].passnum; o++) {
						if (oldPass[o] != Shoppers[j].pass[o]) {
							flagSame = false;
						}
					}
				}
				else {
					flagSame = false;
				}
				if (flagSame) {
					while (flag) {
						do
						{
							cout << "\nNew Password : ";
							char a;
							for (i = 0; i < maxPass;)
							{
								a = _getch();
								if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))

								{
									newPass1[i] = a;
									++i;
									cout << "*";
								}
								if (a == '\b' && i >= 1)

								{
									cout << "\b \b";
									--i;
								}
								if (a == '\r')
								{
									newPass1[i] = '\0';
									break;
								}
								newPassNum1 = i;
							}
							cout << endl;
						} while (i <= 5);

						int k;
						do
						{
							cout << "\nConfirm Password : ";
							char a;
							for (k = 0; k < maxPass;)
							{
								a = _getch();
								if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))

								{
									newPass2[k] = a;
									++k;
									cout << "*";
								}
								if (a == '\b' && k >= 1)

								{
									cout << "\b \b";
									--k;
								}
								if (a == '\r')
								{
									newPass2[k] = '\0';
									break;
								}
								newPassNum2 = k;
							}
							cout << endl;
						} while (k <= 5);
						if (newPassNum1 == newPassNum2)
						{
							for (int num = 0; num < newPassNum1; num++)
							{
								if (newPass1[num] != newPass2[num])
								{
									flagPass = false;
								}
							}
							if (flagPass)
							{
								for (int m = 0; m < newPassNum1; m++)
								{
									Shoppers[j].pass[m] = newPass1[m];
									flagnum = false;
								}
								flag = false;
								break;
							}
							else {
								cout << "The Passwords don't match.\n";
								flag = true;
							}
						}
						else {
							cout << "The Passwords don't match.\n";
							flag = true;
						}
					}
				}
				else {
					cout << "\nWrong Password";
					flagnum = true;
				}
			} while (flagnum);
			break;

		case '3': cout << "\n\nNew Age : ";
			cin >> Shoppers[j].age;
			break;

		case '4': cout << "\n\nNew Gender [ M / F ] : ";
			cin >> gender;
			if (gender == 'M' || gender == 'm')
			{
				Shoppers[j].gender = "Male";
			}
			else if (gender == 'F' || gender == 'f')
			{
				Shoppers[j].gender = "Female";
			}
			else { cout << "Error"; }
			break;

		case '5': cout << "\n\nNew Address : ";
			cout << "\n\nCountry :  ";
			cin >> Shoppers[j].Add.Country;
			cout << "\n\nCity : ";
			cin >> Shoppers[j].Add.City;
			break;

		default:
			cout << "Invalid Choice";
		}
		cout << "\nDo you want to edit anything else  ? [ Y / N ]\n\n" << endl;
		cout << "Choice : ";
		cin >> editchoices;
	}
	sChoice();

}

void del(int j) {
	char choice;
	cout << endl << "Are you sure you want to Delete your Account. ? [ Y / N ] \n\n ";
	cout << "Choice : ";
	cin >> choice;
	switch (choice) {
	case'y':
	case'Y':

		Shoppers[j].name = { 0 };
		Shoppers[j].id = 0;
		for (int i = 0; i < maxPass; i++) {
			Shoppers[j].pass[i] = { 0 };
		}
		Shoppers[j].passnum = 0;
		Shoppers[j].purchases = 0;
		Shoppers[j].age = 0;
		for (int i = 0; i < 10; i++) {

			Shoppers[j].months[i] = 0;
			Shoppers[j].days[i] = 0;
			Shoppers[j].purchaseHistory[i] = 0;
		}
		Shoppers[j].gender = { 0 };
		Shoppers[j].Add.City = { 0 };
		Shoppers[j].Add.Country = { 0 };
		s.countShopper--;

		cout << "\n\n               ***  Your Account has been Deleted. *** \n\n" << endl;
		break;
	default:
		break;

	}
	deletes = 0;
}

void RegChoice()
{
	int RegIndex;
	bool flag = false, flag1 = true;
	char choice;
	cout << " \n***************************************************   WELCOME  ****************************************************** \n";
	do {
		cout << "\nPress -- 1 -- To Login.\n ";
		cout << "\nPress -- 2 -- To Register.\n";
		cout << "\n\n Choice :  ";
		cin >> choice;
		system("cls");
		do {
			switch (choice) {
			case '1':
				OLchoice();
				flag1 = false;
				break;
			case '2':
				do
				{

					{
						RegIndex = RegOwner();
						system("cls");
						RegShop(RegIndex);
						system("cls");
						cout << "\nPress -- 1 --  T0 Continue. \n\n";
						cout << "\nPress -- 2 --  T0 Register Again. \n\n";
						cout << "Choice : ";
						cin >> choice;
						system("cls");
					}
				} while (choice == '2');
				break;
			default:
				cout << "Invalid Choice";
				flag = true;
				break;
			}
		} while (flag);
	} while (flag1);
}

int RegOwner()
{
	int i, j, k, passNum1, passNum2;
	char gender, pass1[maxPass], pass2[maxPass];
	bool flag = true, passFlag = true, genflag = true;
	for (j = 0; j < maxOwners; j++)
	{
		if (Owners[j].Age == 0)
		{
			cout << "\nEnter Your Name: ";
			cin >> Owners[j].Name;
			Owners[j].ID = j + 1;
			cout << "\nYour ID Is :" << Owners[j].ID << endl;

			while (flag)
			{
				do
				{
					cout << "\nPassword (at least 6 digits): ";
					char a;
					passFlag = true;
					for (i = 0; i < maxPass;)
					{
						a = _getch();
						if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
						{
							pass1[i] = a;
							++i;
							cout << "*";
						}
						if (a == '\b' && i >= 1)
						{
							cout << "\b \b";
							--i;
						}
						if (a == '\r')
						{
							pass1[i] = '\0';
							break;
						}
						Owners[j].PassNum = i;
						passNum1 = i;
					}
					cout << endl;
				} while (i <= 5);

				do
				{
					cout << "\nConfirm Password : ";
					char a;
					for (k = 0; k < maxPass;)
					{
						a = _getch();
						if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))

						{
							pass2[k] = a;
							++k;
							cout << "*";
						}
						if (a == '\b' && k >= 1)
						{
							cout << "\b \b";
							--k;
						}
						if (a == '\r')
						{
							pass2[k] = '\0';
							break;
						}
						passNum2 = k;
					}
					cout << endl;
				} while (k <= 5);

				if (passNum1 == passNum2)
				{
					for (int num = 0; num < passNum1; num++)
					{
						if (pass1[num] != pass2[num])
						{
							cout << "\nPasswords do not match" << endl;
							passFlag = false;
							break;
						}
					}
					if (passFlag)
					{
						for (int m = 0; m < passNum1; m++)
						{
							Owners[j].Password[m] = pass1[m];
						}
						flag = false;
						break;
					}
				}
				else
				{
					cout << "Passwords do not match" << endl;
					flag = true;
				}
			}
			cout << "\nEnter Your Age : ";
			cin >> Owners[j].Age;
			cout << "\nEnter Your Gender [ M / F ] : ";
			while (genflag)
			{
				cin >> gender;
				if (gender == 'M' || gender == 'm')
				{
					Owners[j].Gender = "Male";
					genflag = false;
				}
				else if (gender == 'F' || gender == 'f')
				{
					Owners[j].Gender = "Female";
					genflag = false;
				}
				else
				{
					cout << "Please Enter A Valid Gender [ M / F ] : ";
				}
			}
			Owners[j].Gender = gender;
			cout << "\nEnter your Address. \n\n    Country : ";
			cin >> Owners[j].Add.Country;
			cout << "    City : "; cin >> Owners[j].Add.City;
			cout << "         \n\n  ************************** You Have Registered Successfully ************************* *" << endl << endl;
			s.countOwn++;
			system("pause");
			break;
		}
	}
	return j;
}

void RegShop(int i)
{

	string shopName;
	char categoryChoice, gameChoice, bookChoice;
	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
	do {
		cout << "\nEnter your Shop name: ";
		cin >> shopName;
		flag1 = false;
		for (int j = 0; j < maxOwners; j++)
		{
			if (shopName == Owners[j].Shops.ShopName)
			{
				cout << "\n\n !! This Shop is already taken. !!";
				flag1 = true;
				break;
			}
		}
	} while (flag1);
	Owners[i].Shops.ShopName = shopName;
	cout << "\nEnter Your Shop's Address. \n\n      Country : ";
	cin >> Owners[i].Shops.Add.Country;
	cout << "      City : ";
	cin >> Owners[i].Shops.Add.City;
	cout << "\n\nChoose One Of Our Available Categories :\n\n[ 1 ] Phones & Tablets. \n\n[ 2 ] Electronics. \n\n[ 3 ] Makeup & Accessories. \n\n[ 4 ] Clothing. \n\n[ 5 ] Shoes & Bags. \n\n[ 6 ] Books. \n\n[ 7 ] Gaming.\n";
	cout << endl << "\nChoice : "; cin >> categoryChoice;
	do {
		switch (categoryChoice) {
		case '1':
			Owners[i].Shops.Category = "Phones&Tablets";
			break;
		case '2':
			Owners[i].Shops.Category = "Electronics";
			break;
		case '3':
			Owners[i].Shops.Category = "Makeup&Acessories";
			break;
		case '4':
			Owners[i].Shops.Category = "Clothing";
			break;
		case '5':
			Owners[i].Shops.Category = "Shoes&Bags";
			break;
		case '6':
			Owners[i].Shops.Category = "Books";
			cout << "[ 1 ] Novels.\t[ 2 ] Magazines.\t[ 3 ] Short Stories.\n\n Choice :";
			cin >> bookChoice;
			do {
				switch (bookChoice) {
				case '1':
					Owners[i].Shops.Category = "Books_Novels";
					break;
				case '2':
					Owners[i].Shops.Category = "Books_Magazines";
					break;
				case '3':
					Owners[i].Shops.Category = "Books_ShortStories";
					break;
				default:
					cout << "\n\n!! Invalid choice. !!\n\n";
					flag4 = true;
					break;
				}
			} while (flag4);
			break;
		case '7':
			cout << "[ 1 ] Pc Games.    [ 2 ] PS4 Games.    [ 3 ] Xbox Games.\n\n Choice : ";
			cin >> gameChoice;
			do {
				switch (gameChoice) {
				case '1':
					Owners[i].Shops.Category = "Gaming_PC";
					break;
				case '2':
					Owners[i].Shops.Category = "Gaming_PS4";
					break;
				case '3':
					Owners[i].Shops.Category = "Gaming_Xbox";
					break;
				default:
					cout << "\n\n!!  Invalid choice. !! \n\n";
					flag3 = true;
					break;
				}
			} while (flag3);
			break;
		default:
			flag2 = true;
			cout << "\n\n !! Invalid Choice !! \n\n";
			cout << "choice : "; cin >> categoryChoice;
			cout << "\n " << endl;
		}
	} while (flag2);
}

int Lowner()
{
	int j;
	bool flag = true;
	int LogID, i;
	char LogPass[maxPass];
	cout << "\nPlease Enter Your Login Data :" << endl;
	cout << "\n\nID :";
	cin >> LogID;

	cout << "\nPassword :";
	char a;
	for (j = 0;;)
	{
		a = _getch();
		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
		{
			LogPass[j] = a;
			++j;
			cout << "*";
		}
		if (a == '\b' && j >= 1)
		{
			cout << "\b \b";
			--j;
		}
		if (a == '\r')
		{
			LogPass[j] = '\0';
			break;
		}
	}

	for (i = 0; i < maxOwners; i++)
	{
		flag = true;
		if (j > Owners[i].PassNum || j < Owners[i].PassNum) {
			flag = false;
		}
		else if (j == Owners[i].PassNum) {
			for (int x = 0; x < Owners[i].PassNum; x++)
			{
				if (LogPass[x] != Owners[i].Password[x])
				{
					flag = false;
				}
			}
		}
		if (LogID == Owners[i].ID && (flag))
		{
			cout << "\n             ***************************  You have successfully Logged In. ************************* \n";
			system("pause");
			system("cls");
			break;
		}

	}
	if (flag == false)
	{
		cout << "\nEither the ID or Password is incorrect\n\n" << endl;
		i = maxOwners;
	}
	return i;
}

void Eowner(int j) {
	char editchoice, gender, continuechoice, regedit, shopEdit, categoryChoice, gameChoice, bookChoice, newPass1[maxPass], newPass2[maxPass], oldPass[maxPass];
	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false, flagSame = true, flag = true, flagPass = true, choiceFlag = true, flagnum = true;
	int l;
	cout << "**************  Editing your information **************** \n";
	do {
		cout << "\n\nPress -- R -- to edit your registration data. \n\npress -- S -- to Edit Your Shop Data.  \n\nPress -- D -- To Delete Your Account. \n\nPress -- x --  To Exit. \n\n ";
		cout << "\n Choice : ";
		cin >> editchoice;

		system("cls");
		if (editchoice == 'R' || editchoice == 'r')
		{
			cout << "\n\n What do you want to edit ? " << endl;
			cout << "[ 1 ] Name \n\n[ 2 ] Password \n\n[ 3 ] Age \n\n[ 4 ] Gender \n\n[ 5 ] Address \n\n[ 6 ] Stop \n\n" << endl;
			cout << "Choice : ";
			cin >> regedit;
			switch (regedit)
			{
			case '1':
				cout << "\n\nNew Name : ";
				cin >> Owners[j].Name;
				break;

			case '2':
				int i, newPassNum1, newPassNum2;
				flag = true;
				do {
					do {
						cout << "Old Password : ";
						char a;
						flagPass = true;
						flagSame = true;
						for (l = 0;;)
						{
							a = _getch();
							if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
							{
								oldPass[l] = a;
								++l;
								cout << "*";
							}
							if (a == '\b' && l >= 1)
							{
								cout << "\b \b";
								--l;
							}
							if (a == '\r')
							{
								oldPass[l] = '\0';
								break;
							}
						}
					} while (l <= 5);
					if (l == Owners[j].PassNum) {
						for (int o = 0; o < Owners[j].PassNum; o++) {
							if (oldPass[o] != Owners[j].Password[o]) {
								flagSame = false;
							}
						}
					}
					else {
						flagSame = false;
					}
					if (flagSame) {
						while (flag) {
							do
							{
								cout << "\nNew Password : ";
								char a;
								for (i = 0; i < maxPass;)
								{
									a = _getch();
									if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))

									{
										newPass1[i] = a;
										++i;
										cout << "*";
									}
									if (a == '\b' && i >= 1)

									{
										cout << "\b \b";
										--i;
									}
									if (a == '\r')
									{
										newPass1[i] = '\0';
										break;
									}
									newPassNum1 = i;
								}
								cout << endl;
							} while (i <= 5);

							int k;
							do
							{
								cout << "\nConfirm Password : ";
								char a;
								for (k = 0; k < maxPass;)
								{
									a = _getch();
									if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))

									{
										newPass2[k] = a;
										++k;
										cout << "*";
									}
									if (a == '\b' && k >= 1)

									{
										cout << "\b \b";
										--k;
									}
									if (a == '\r')
									{
										newPass2[k] = '\0';
										break;
									}
									newPassNum2 = k;
								}
								cout << endl;
							} while (k <= 5);
							if (newPassNum1 == newPassNum2)
							{
								for (int num = 0; num < newPassNum1; num++)
								{
									if (newPass1[num] != newPass2[num])
									{
										flagPass = false;
									}
								}
								if (flagPass)
								{
									for (int m = 0; m < newPassNum1; m++)
									{
										Owners[j].Password[m] = newPass1[m];
										flagnum = false;
									}
									flag = false;
									break;
								}
								else {
									cout << "The Passwords don't match.\n";
									flag = true;
								}
							}
							else {
								cout << "The Passwords don't match.\n";
								flag = true;
							}
						}
					}
					else {
						cout << "\nWrong Password";
						flagnum = true;
					}
				} while (flagnum);
				break;

			case '3':
				cout << "\n\nNew Age : ";
				cin >> Owners[j].Age;
				break;

			case '4':
				cout << "\n\nNew Gender(M/F) : ";
				while (true)
				{
					cin >> gender;
					if (gender == 'M' || gender == 'm')
					{
						Owners[j].Gender = "Male";
						break;
					}
					else if (gender == 'F' || gender == 'f')
					{
						Owners[j].Gender = "Female";
						break;
					}
					else
					{
						cout << "\n\nPlease enter a valid gender(M/F) : ";
					}
				}
				break;
			case '5':
				cout << "\n\nNew Address.\nCountry : ";
				cin >> Owners[j].Add.Country;
				cout << "City : "; cin >> Owners[j].Add.City;
				break;
			case '6':
				break;
			default:
				cout << "\n\n !! Invalid choice !! \n\n";
				break;
			}
		}
		else if (editchoice == 'S' || editchoice == 's')
		{
			cout << "What Do You Want To Edit ?\n\n" << endl;
			cout << "[ 1 ] Shop Name \n\n[ 2 ] Address \n\n[ 3 ] Category \n\n[ 4 ] Stop\n\n\n";
			cout << "Choice: "; cin >> shopEdit;
			cout << "\n" << endl;
			do {
				switch (shopEdit)
				{
				case '1':
					cout << "New Shop Name : ";
					cin >> Owners[j].Shops.ShopName;
					break;
				case '2':
					cout << "New Shop Address.\nCountry : ";
					cin >> Owners[j].Shops.Add.Country;
					cout << "City : "; cin >> Owners[j].Shops.Add.City;
					break;
				case '3':
					cout << "Choose one of our available Categories : [ 1 ] Phones & Tablets. \n\n[ 2 ] Electronics. \n\n[ 3 ] Makeup & Accessories. \n\n[ 4 ] Clothing. \n\n[ 5 ] Shoes & Bags. \n\n[ 6 ] Books. \n\n[ 7 ] Gaming.\n";
					cout << "\n\n\n Choice : "; cin >> categoryChoice;
					do {
						switch (categoryChoice) {
						case '1':
							Owners[j].Shops.Category = "Phones&Tablets";
							break;
						case '2':
							Owners[j].Shops.Category = "Electronics";
							break;
						case '3':
							Owners[j].Shops.Category = "Makeup&Acessories";
							break;
						case '4':
							Owners[j].Shops.Category = "Clothing";
							break;
						case '5':
							Owners[j].Shops.Category = "Shoes&Bags";
							break;
						case '6':
							Owners[j].Shops.Category = "Books";
							cout << "[ 1 ] Novels.\t[ 2 ] Magazines.\t[ 3 ] Short Stories.\n\n Choice : ";
							cin >> bookChoice;
							do {
								switch (bookChoice) {
								case '1':
									Owners[j].Shops.Category = "Books_Novels";
									break;
								case '2':
									Owners[j].Shops.Category = "Books_Magazines";
									break;
								case '3':
									Owners[j].Shops.Category = "Books_ShortStories";
									break;
								default:
									cout << "Invalid choice.";
									flag4 = true;
									break;
								}
							} while (flag4);
							break;
						case '7':
							cout << "[ 1 ] Pc Games.\t[ 2 ] PS4 Games.\t[ 3 ] Xbox Games.\n\n Choice : ";
							cin >> gameChoice;
							do {
								switch (gameChoice) {
								case '1':
									Owners[j].Shops.Category = "Gaming_PC";
									break;
								case '2':
									Owners[j].Shops.Category = "Gaming_PS4";
									break;
								case '3':
									Owners[j].Shops.Category = "Gaming_Xbox";
									break;
								default:
									cout << "Invalid choice.";
									flag3 = true;
									break;
								}
							} while (flag3);
							break;
						default:
							flag2 = true;
							cout << "Invalid Choice\n";
							cout << "choice : "; cin >> categoryChoice;
						}
					} while (flag2);
				case '4':
					break;
				default:
					cout << "Invalid Input";
					flag1 = true;
					break;
				}
			} while (flag1);
		}
		else if (editchoice == 'D' || editchoice == 'd')
		{
			removeReg(LogIndex);
			continuechoice = 'n';
		}
		else if (editchoice == 'X' || editchoice == 'x') {
			break;
		}
		else
		{
			cout << "\n\nInvalid Choice\n";
		}
		if (deletes != 0) {
			while (choiceFlag)
			{
				cout << "Would You Like To Continue  ? [ Y / N ] \n\n";
				cout << "Choice : ";
				cin >> continuechoice;
				if (continuechoice == 'Y' || continuechoice == 'y' || continuechoice == 'N' || continuechoice == 'n')
				{
					choiceFlag = false;
				}
				else
				{
					cout << "\n\n !!  Invalid Input !!";
				}
			}
		}
	} while (continuechoice == 'Y' || continuechoice == 'y');
}

void OEchoice()
{
	char Editchoice;
	if (LogIndex != maxOwners) {
		cout << "Do You Want To Edit Your Data ? [ Y / N ].\n\n";
		cout << "Choice :  ";
		cin >> Editchoice;
		switch (Editchoice)
		{
		case'y':
		case'Y':
			system("cls");
			Eowner(LogIndex);
			break;
		default:
			cout << "\n\nYou May Continue\n\n";
			break;
		}
	}
}

void OLchoice()
{
	char Logchoice;
	cout << "Do You Want To Login ? [ Y / N ]. \n\n";
	cout << "Choice : ";
	cin >> Logchoice;
	system("cls");
	while (Logchoice == 'y' || Logchoice == 'Y')
	{
		LogIndex = Lowner();

		if (LogIndex == maxOwners)
		{
			cout << "\n\nWould You Like To Try Again?  [ Y / N ]  \n\n";
			cout << "Choice : ";
			cin >> Logchoice;
			system("cls");
		}
		else
		{
			Logchoice = 'o';
		}
	}
	if (Logchoice == 'n' || Logchoice == 'N') {
		LogIndex = maxOwners;
	}
	if (LogIndex != maxOwners) {
		OEchoice();
		if (deletes != 0) {
			ProdChoice();
		}
	}
}

void ProdChoice()
{
	char choice;
	do
	{
		cout << "Press  -- A -- To Add A Product.\n\nPress -- R -- To Remove A Product.\n\nPress -- V -- To View Your Products.\n\nPress -- E -- To Edit a product\n\nPress -- D -- To Discount a product\n\n";
		cout << "Choice : ";
		char choices;
		cin >> choices;
		cout << "\n" << endl;
		switch (choices)
		{
		case 'a':
		case 'A':
			system("cls");
			addProds(LogIndex);
			break;
		case 'r':
		case 'R':
			removeProds(LogIndex);
			break;
		case 'v':
		case 'V':
			system("cls");
			viewProds(LogIndex);
			break;
		case 'd':
		case 'D':
			system("cls");
			discount(LogIndex);
			break;
		case 'e':
		case 'E':
			system("cls");
			editProds(LogIndex);
			break;
		default:
			cout << "\n\n !! Invalid answer !! \n\n";
		}
		system("cls");
		cout << "Do You Want To Continue [ Y / N ] : \n\n";
		cout << "Choice : ";
		cin >> choice;
		cout << endl;
	} while (choice == 'y' || choice == 'Y');
}

void addProds(int j)
{
	do
	{

		char choice;

		for (int i = 0; i <= maxProds; i++)
		{

			if (Owners[j].Shops.products[i].productPrice != 0)
			{
				continue;
			}

			else if (Owners[j].Shops.products[i].productPrice == 0)
			{

				cout << "\n\nProduct's name : ";
				cin >> Owners[j].Shops.products[i].productName;

				cout << "\n\nProduct's Price : $";
				cin >> Owners[j].Shops.products[i].productPrice;

				if (Owners[j].Shops.Category == "Clothing") {
					cout << "\n\nType [ M / F ] : "; cin >> Owners[j].Shops.products[i].Clothes.Type;
					cout << "\n\nColor : "; cin >> Owners[j].Shops.products[i].Clothes.Color;
					cout << "\n\nSize [ S / M / L ] : "; cin >> Owners[j].Shops.products[i].Clothes.Size;
					cout << "\n\nProduct's Category : ";
					Owners[j].Shops.products[i].Category = Owners[j].Shops.Category;
					cout << Owners[j].Shops.products[i].Category;
				}
				else {
					cout << "\n\nProduct's Category : ";
					Owners[j].Shops.products[i].Category = Owners[j].Shops.Category;
					cout << Owners[j].Shops.products[i].Category << endl;
				}
				cout << "\n\nProduct's Quantity : ";
				cin >> Owners[j].Shops.products[i].Quantity;
				cout << endl;
				Owners[j].Shops.countProd++;
				break;
			}
		}
		cout << "Do You Want To Enter a Product ? [ Y / N ] : \n\n";
		cout << "Choice :  ";
		cin >> choice;

		if (choice == 'N' || choice == 'n')
		{
			break;
		}
		else if (choice == 'Y' || choice == 'y')
		{
			continue;
		}
	} while (true);
}

void removeProds(int j)
{
	int i;
	bool same = false;
	string name;
	char choice, continuechoice;
	do
	{
		cout << "\n\nWhat is the name of the product you want to remove ?? \n\n";
		cout << "Name : ";
		cin >> name;
		cout << "\n\nAre You Sure You Want To Remove This Product [ Y / N ] ?\n\n";
		cout << "choice : ";
		cin >> continuechoice;
		if (continuechoice == 'Y' || continuechoice == 'y')
		{
			for (i = 0; i < maxProds; i++)
			{
				if (name == Owners[j].Shops.products[i].productName)
				{
					same = true;
					break;
				}
			}
			if (same == true)
			{
				Owners[j].Shops.products[i].productName = { 0 };
				Owners[j].Shops.products[i].productPrice = 0;
				Owners[j].Shops.products[i].Quantity = 0;
				Owners[j].Shops.countProd--;
				if (Owners[j].Shops.products[i].Category == "Clothing") {
					Owners[j].Shops.products[i].Clothes.Type = { 0 };
					Owners[j].Shops.products[i].Clothes.Color = { 0 };
					Owners[j].Shops.products[i].Clothes.Size = { 0 };
					Owners[j].Shops.products[i].Category = { 0 };
				}
				else {
					Owners[j].Shops.products[i].Category = { 0 };
				}
			}
			else if (same == false)
				cout << "This product doesn't exist. \n\n";
			cout << "\nDo You Want To Remove Another Product? [ Y / N ] : ";
			cout << " Choice : ";
			cin >> choice;
			cout << "\n" << endl;
			if (choice == 'N' || choice == 'n')
			{
				break;
			}

			else if (choice == 'Y' || choice == 'y')
			{
				continue;
			}
			else {
				break;
			}
		}
	} while (true);

}

void editProds(int j) {

	int i;
	bool same = false;
	string name;
	char choice, c;
	do
	{
		cout << "\n\nWhat is the name of the product you want to edit ?? \n\n";
		cout << "Name : ";
		cin >> name;
		for (i = 0; i < maxProds; i++)
		{
			if (name == Owners[j].Shops.products[i].productName)
			{
				same = true;
				break;
			}
		}
		if (same == true)
		{
			cout << "1 ) Product's Name\n\n2 ) Product's Price\n\n3 ) Product's Quantity\n\n";
			cout << "Choice : "; cin >> c;
			switch (c)
			{
			case '1':
				cout << "\nProduct's Name : "; cin >> Owners[j].Shops.products[i].productName;
				break;
			case '2':
				cout << "\nPrice : "; cin >> Owners[j].Shops.products[i].productPrice;
				Owners[i].Shops.products[j].month = 0;
				break;
			case '3':
				cout << "\nQuantity : "; cin >> Owners[j].Shops.products[i].Quantity;
				break;
			default:
				cout << "\nInvalid Choice";
				break;
			}
		}
		else if (same == false)
			cout << "This product doesn't exist. \n\n";
		cout << "\nDo You Want To Edit Another Product? [ Y / N ] : ";
		cout << " Choice : ";
		cin >> choice;
		cout << "\n" << endl;
		if (choice == 'N' || choice == 'n')
		{
			break;
		}

		else if (choice == 'Y' || choice == 'y')
		{
			continue;
		}
		else {
			break;
		}
	} while (true);
}

void viewProds(int j)
{
	char choice;
	do
	{
		cout << "-- Product's Name --\t-- Product's Price -- \t-- Product's Category -- \t-- Product's Quantity --\n\n";
		for (int i = 0; i < maxProds; i++)
		{
			if (Owners[j].Shops.products[i].productPrice != 0)
			{
				cout << Owners[j].Shops.products[i].productName << "  \t  " << Owners[j].Shops.products[i].productPrice << "$" << "   \t  " << Owners[j].Shops.products[i].Category << "  \t " << Owners[j].Shops.products[i].Quantity << endl << endl;
			}
		}
		cout << "\n\nDo you want to view your products? [ Y / N ] : \n\n";
		cout << "Choice : ";
		cin >> choice;
		if (choice == 'n' || choice == 'N')
		{
			break;
		}
		else if (choice == 'y' || choice == 'Y')
		{
			continue;
		}
	} while (true);
}

void removeReg(int j)
{
	char choice;
	cout << "\n\nYou Are About To Delete Your Account , Are You Sure ? [ Y / N ] \n\n";
	cout << "Choice : ";
	cin >> choice;
	switch (choice)
	{

	case 'y':
	case 'Y':
		Owners[j].Name = { 0 };
		Owners[j].ID = 0;
		for (int i = 0; i < maxPass; i++)
		{
			Owners[j].Password[i] = { 0 };
		}
		Owners[j].Age = 0;
		Owners[j].PassNum = 0;
		Owners[j].Gender = { 0 };
		Owners[j].Add.Country = { 0 };
		Owners[j].Add.City = { 0 };
		Owners[j].Shops.ShopName = { 0 };
		Owners[j].Shops.Category = { 0 };
		Owners[j].Shops.Add.Country = { 0 };
		Owners[j].Shops.Add.City = { 0 };
		s.countOwn--;
		for (int i = 0; i < maxProds; i++)
		{
			Owners[j].Shops.products[i].productName = { 0 };
			if (Owners[j].Shops.products[i].Category == "Clothing")
			{
				Owners[j].Shops.countProd = 0;
				Owners[j].Shops.products[i].Category = { 0 };
				Owners[j].Shops.products[i].productPrice = 0;
				Owners[j].Shops.products[i].sum = 0;
				Owners[j].Shops.products[i].Quantity = 0;
				Owners[j].Shops.products[i].oldPrice = 0;
				Owners[j].Shops.products[i].month = 0;
				Owners[j].Shops.products[i].day = 0;
				Owners[j].Shops.products[i].counter = 0;
				Owners[j].Shops.products[i].avgRating = 0;
				Owners[j].Shops.products[i].Clothes.Size = { 0 };
				Owners[j].Shops.products[i].Clothes.Type = { 0 };
				Owners[j].Shops.products[i].Clothes.Color = { 0 };
			}
			else {
				Owners[j].Shops.products[i].Category = { 0 };
				Owners[j].Shops.products[i].productPrice = 0;
				Owners[j].Shops.products[i].sum = 0;
				Owners[j].Shops.products[i].Quantity = 0;
				Owners[j].Shops.products[i].oldPrice = 0;
				Owners[j].Shops.products[i].month = 0;
				Owners[j].Shops.products[i].day = 0;
				Owners[j].Shops.products[i].counter = 0;
				Owners[j].Shops.products[i].avgRating = 0;
			}
		}
		cout << "\n\n\n                ************  Your Account Has Been Successfully Deleted **********" << endl;
		break;
	default:
		break;
	}
	deletes = 0;
}

void Rating()
{
	int ratenum, rating = 0;
	bool rate = true, flag = true;

	do {
		cout << "Enter the number of the product you'd like to rate : ";
		cin >> ratenum;
		if (ratenum <= c.nump)
		{
			flag = false;
			do
			{
				cout << "Enter your Rating (1 -> 5) : ";
				cin >> rating;
				if (rating >= 1 && rating <= 5)
				{
					rate = false;
					Owners[k.sav[ratenum - 1].x].Shops.products[k.sav[ratenum - 1].y].counter++;
					Owners[k.sav[ratenum - 1].x].Shops.products[k.sav[ratenum - 1].y].sum += rating;
					Owners[k.sav[ratenum - 1].x].Shops.products[k.sav[ratenum - 1].y].avgRating = Owners[k.sav[ratenum - 1].x].Shops.products[k.sav[ratenum - 1].y].sum / Owners[k.sav[ratenum - 1].x].Shops.products[k.sav[ratenum - 1].y].counter;
					cout << "The Rating of " << Owners[k.sav[ratenum - 1].x].Shops.products[k.sav[ratenum - 1].y].productName << " is " << Owners[k.sav[ratenum - 1].x].Shops.products[k.sav[ratenum - 1].y].avgRating << endl;
					break;
				}
				else
				{
					cout << "Invalid Rating.";
					rate = true;
				}

			} while (rate);

		}
		else
		{
			cout << "Invalid Number.";
			flag = true;
		}
	} while (flag);
}

void discount(int j)
{
	double percentage, discount;
	string prodName;
	bool flag = false, choice = true, flag2 = true;
	do {
		cout << "Enter the name of a Product : ";
		cin >> prodName;
		for (int i = 0; i < maxProds; i++)
		{
			if (Owners[j].Shops.products[i].productName == prodName)
			{
				while (choice)
				{
					cout << "Enter the Discount percentage : %";
					cin >> percentage;
					if (percentage <= 100)
					{
						choice = false;
						do {
							cout << "Please Enter the day and month when the sale ends : \n";
							cout << "Day :"; cin >> Owners[j].Shops.products[i].day;
							cout << "Month :"; cin >> Owners[j].Shops.products[i].month;
							if (day <= 31 && month <= 12)
							{
								if (Owners[j].Shops.products[i].month >= month)
								{
									if (Owners[j].Shops.products[i].month == month) {
										if (Owners[j].Shops.products[i].day >= day)
										{
											flag2 = false;
											flag = false;
											discount = Owners[j].Shops.products[i].productPrice * (percentage / 100);
											Owners[j].Shops.products[i].oldPrice = Owners[j].Shops.products[i].productPrice;
											Owners[j].Shops.products[i].productPrice = Owners[j].Shops.products[i].productPrice - discount;
										}
									}
									else {
										flag2 = false;
										flag = false;
										discount = Owners[j].Shops.products[i].productPrice * (percentage / 100);
										Owners[j].Shops.products[i].oldPrice = Owners[j].Shops.products[i].productPrice;
										Owners[j].Shops.products[i].productPrice = Owners[j].Shops.products[i].productPrice - discount;

									}
								}
							}
							if (flag2) {
								cout << "Wrong Date.";
							}
						} while (flag2);
					}
					else
					{
						cout << "The Discount cannot be more than a 100% ";
						choice = true;
					}
				}
			}
		}
		if (flag)
		{
			cout << "The product you have entered does not exist , please re-enter it\n";
			flag = true;
		}
	} while (flag);
}

void purchaseHistory(int k)
{
	cout << "Your purchase History is : ";
	for (int l = 0; l < 10; l++)
	{
		if (Shoppers[k].purchaseHistory[l] != 0)
		{
			cout << "You bought for " << Shoppers[k].purchaseHistory[l] << "$ on " << Shoppers[k].days[l] << "/" << Shoppers[k].months[l] << endl << endl;
		}
	}
}

void discCheck()
{
	for (int i = 0; i < maxOwners; i++)
	{
		for (int j = 0; j < maxProds; j++)
		{
			if (Owners[i].Shops.products[j].productPrice != 0) {
				if (Owners[i].Shops.products[j].month != 0) {
					if (Owners[i].Shops.products[j].month < month)
					{
						Owners[i].Shops.products[j].productPrice = Owners[i].Shops.products[j].oldPrice;
					}
					else if (Owners[i].Shops.products[j].month == month)
					{
						if (Owners[i].Shops.products[j].day < day)
						{
							Owners[i].Shops.products[j].productPrice = Owners[i].Shops.products[j].oldPrice;
						}
					}
				}
			}
		}
	}
}

void gifts() {
	do {
		int choice1;
		char choice2;
		cout << "Do you want to send the gift to a Man or a Woman." << endl;
		cout << "[1] MAN. \n\n";
		cout << "[2] WOMAN.\n\n";
		cout << "Choice:";
		cin >> choice1;
		system("pause");
		system("cls");
		cout << "-Product Name- " << "-  Product Price  -" << "-  Product Category  -" << "-  Product Quantity  -" << "-  Avg. Rating  -" << "- Size -" << "- Type -" << "- Color -" << "\n" << endl;
		if (choice1 == 1) {
			for (int i = 0; i < maxOwners; i++) {
				for (int j = 0; j < maxProds; j++) {
					if (Owners[i].Shops.products[j].productPrice != 0) {
						if (Owners[i].Shops.products[j].Category == "Clothing") {
							if (Owners[i].Shops.products[j].Clothes.Type == 'm') {
								cout << Owners[i].Shops.products[j].productName << "  \t  " << Owners[i].Shops.products[j].productPrice << "$" << "   \t  " << Owners[i].Shops.products[j].Category << "  \t " << Owners[i].Shops.products[j].Quantity << "  \t  " << Owners[i].Shops.products[j].Clothes.Size << "  \t  " << Owners[i].Shops.products[j].Clothes.Type << "   \t  " << Owners[i].Shops.products[j].Clothes.Color << endl;

							}
						}
						else {
							if (Owners[i].Shops.products[j].Category != "Makeup&Acessories") {
								cout << Owners[i].Shops.products[j].productName << "  \t  " << Owners[i].Shops.products[j].productPrice << "$" << "   \t  " << Owners[i].Shops.products[j].Category << "  \t " << Owners[i].Shops.products[j].Quantity << endl;
							}
						}
					}

				}
			}
		}
		else if (choice1 == 2) {
			for (int i = 0; i < maxOwners; i++) {
				for (int j = 0; j < maxProds; j++) {
					if (Owners[i].ID != 0) {
						if (Owners[i].Shops.products[j].Category == "Clothing") {
							if (Owners[i].Shops.products[j].Clothes.Type == 'f') {
								cout << Owners[i].Shops.products[j].productName << "  \t  " << Owners[i].Shops.products[j].productPrice << "$" << "   \t  " << Owners[i].Shops.products[j].Category << "  \t " << Owners[i].Shops.products[j].Quantity << "  \t  " << Owners[i].Shops.products[j].Clothes.Type << "   \t  " << Owners[i].Shops.products[j].Clothes.Size << "  \t  " << Owners[i].Shops.products[j].Clothes.Color << endl;

							}
						}
						else {
							cout << Owners[j].Shops.products[i].productName << "  \t  " << Owners[j].Shops.products[i].productPrice << "$" << "   \t  " << Owners[j].Shops.products[i].Category << "  \t " << Owners[j].Shops.products[i].Quantity << endl << endl;
						}
					}
				}
			}
		}
		else
			cout << "invalid choice.\n\n";

		cout << "Do you want to send another Gift (Y/N)\n";
		cout << "Choice:";
		cin >> choice2;
		if (choice2 == 'y' || choice1 == 'Y')
		{
			continue;
		}
		else if (choice2 == 'n' || choice2 == 'N')
		{
			break;
		}
	} while (true);
}

void ByCategory()
{
	string shopName;
	char categoryChoice, gameChoice, bookChoice;
	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false, flag = false;

	cout << "\n\nChoose One Of Our Available Categories :\n\n[ 1 ] Phones & Tablets. \n\n[ 2 ] Electronics. \n\n[ 3 ] Makeup & Accessories. \n\n[ 4 ] Clothing. \n\n[ 5 ] Shoes & Bags. \n\n[ 6 ] Books. \n\n[ 7 ] Gaming.\n";
	cout << endl << "\nChoice : "; cin >> categoryChoice;
	do {
		switch (categoryChoice) {
		case '1':

			for (int i = 0; i < maxShoppers; i++)
			{
				for (int j = 0; j < maxProds; j++)
				{
					if (Owners[i].Shops.Category == "Phones&Tablets")
					{
						cout << Owners[i].Shops.products[j].productName << "\t\t" << Owners[i].Shops.products[j].productPrice << "\t\t" << Owners[i].Shops.products[j].Quantity << "\t\t\t" << Owners[i].Shops.products[j].avgRating << "\n";
						flag = true;
					}
				}
			}
			break;

		case '2':

			for (int i = 0; i < maxShoppers; i++)
			{
				for (int j = 0; j < maxProds; j++)
				{
					if (Owners[i].Shops.Category == "Electronics")
					{
						cout << Owners[i].Shops.products[j].productName << "\t\t" << Owners[i].Shops.products[j].productPrice << "\t\t" << Owners[i].Shops.products[j].Quantity << "\t\t\t" << Owners[i].Shops.products[j].avgRating << "\n";
						flag = true;
					}
				}
			}

			break;
		case '3':

			for (int i = 0; i < maxShoppers; i++)
			{
				for (int j = 0; j < maxProds; j++)
				{
					if (Owners[i].Shops.Category == "Makeup&Acessories")
					{
						cout << Owners[i].Shops.products[j].productName << "\t\t" << Owners[i].Shops.products[j].productPrice << "\t\t" << Owners[i].Shops.products[j].Quantity << "\t\t\t" << Owners[i].Shops.products[j].avgRating << "\n";
						flag = true;
					}
				}
			}
			break;
		case '4':

			for (int i = 0; i < maxShoppers; i++)
			{
				for (int j = 0; j < maxProds; j++)
				{
					if (Owners[i].Shops.Category == "Clothing")
					{
						cout << ". " << Owners[i].Shops.products[j].productName << "\t\t" << Owners[i].Shops.products[j].Quantity << "\t\t\t" << Owners[i].Shops.products[j].avgRating << "          " << Owners[i].Shops.products[j].Clothes.Size << "       " << Owners[i].Shops.products[j].Clothes.Type << "      " << Owners[i].Shops.products[j].Clothes.Color << "\n";
						flag = true;
					}
				}
			}
			break;
		case '5':

			for (int i = 0; i < maxShoppers; i++)
			{
				for (int j = 0; j < maxProds; j++)
				{
					if (Owners[i].Shops.Category == "Shoes&Bags")
					{
						cout << Owners[i].Shops.products[j].productName << "\t\t" << Owners[i].Shops.products[j].productPrice << "\t\t" << Owners[i].Shops.products[j].Quantity << "\t\t\t" << Owners[i].Shops.products[j].avgRating << "\n";
						flag = true;
					}
				}
			}
			break;
		case '6':

			cout << "[ 1 ] Novels.\t[ 2 ] Magazines.\t[ 3 ] Short Stories.\n\n Choice :";
			cin >> bookChoice;
			do {
				switch (bookChoice) {
				case '1':

					for (int i = 0; i < maxShoppers; i++)
					{
						for (int j = 0; j < maxProds; j++)
						{
							if (Owners[i].Shops.Category == "Books_Novels")
							{
								cout << Owners[i].Shops.products[j].productName << "\t\t" << Owners[i].Shops.products[j].productPrice << "\t\t" << Owners[i].Shops.products[j].Quantity << "\t\t\t" << Owners[i].Shops.products[j].avgRating << "\n";
								flag = true;
							}
						}
					}
					break;
				case '2':
					for (int i = 0; i < maxShoppers; i++)
					{
						for (int j = 0; j < maxProds; j++)
						{
							if (Owners[i].Shops.Category == "Books_Magazines")
							{
								cout << Owners[i].Shops.products[j].productName << "\t\t" << Owners[i].Shops.products[j].productPrice << "\t\t" << Owners[i].Shops.products[j].Quantity << "\t\t\t" << Owners[i].Shops.products[j].avgRating << "\n";
								flag = true;
							}
						}
					}

					break;
				case '3':
					for (int i = 0; i < maxShoppers; i++)
					{
						for (int j = 0; j < maxProds; j++)
						{
							if (Owners[i].Shops.Category == "Books_ShortStories")
							{
								cout << Owners[i].Shops.products[j].productName << "\t\t" << Owners[i].Shops.products[j].productPrice << "\t\t" << Owners[i].Shops.products[j].Quantity << "\t\t\t" << Owners[i].Shops.products[j].avgRating << "\n";
								flag = true;
							}
						}
					}

					break;
				default:
					cout << "\n\n!! Invalid choice. !!\n\n";
					flag4 = true;
					break;
				}
			} while (flag4);
			break;
		case '7':
			cout << "[ 1 ] Pc Games.    [ 2 ] PS4 Games.    [ 3 ] Xbox Games.\n\n Choice : ";
			cin >> gameChoice;
			do {
				switch (gameChoice) {
				case '1':
					for (int i = 0; i < maxShoppers; i++)
					{
						for (int j = 0; j < maxProds; j++)
						{
							if (Owners[i].Shops.Category == "Gaming_PC")
							{
								cout << Owners[i].Shops.products[j].productName << "\t\t" << Owners[i].Shops.products[j].productPrice << "\t\t" << Owners[i].Shops.products[j].Quantity << "\t\t\t" << Owners[i].Shops.products[j].avgRating << "\n";
								flag = true;
							}
						}
					}
					break;
				case '2':
					for (int i = 0; i < maxShoppers; i++)
					{
						for (int j = 0; j < maxProds; j++)
						{
							if (Owners[i].Shops.Category == "Gaming_PS4")
							{
								cout << Owners[i].Shops.products[j].productName << "\t\t" << Owners[i].Shops.products[j].productPrice << "\t\t" << Owners[i].Shops.products[j].Quantity << "\t\t\t" << Owners[i].Shops.products[j].avgRating << "\n";
								flag = true;
							}
						}
					}
					break;
				case '3':
					for (int i = 0; i < maxShoppers; i++)
					{
						for (int j = 0; j < maxProds; j++)
						{
							if (Owners[i].Shops.Category == "Gaming_Xbox")
							{
								cout << Owners[i].Shops.products[j].productName << "\t\t" << Owners[i].Shops.products[j].productPrice << "\t\t" << Owners[i].Shops.products[j].Quantity << "\t\t\t" << Owners[i].Shops.products[j].avgRating << "\n";
								flag = true;
							}
						}
					}

					break;
				default:
					cout << "\n\n!!  Invalid choice. !! \n\n";
					flag3 = true;
					break;
				}
			} while (flag3);
			break;
		default:
			flag2 = true;
			cout << "\n\n !! Invalid Choice !! \n\n";
			cout << "choice : "; cin >> categoryChoice;
			cout << "\n " << endl;
		}
	} while (flag2);

	if (flag == false) {
		cout << "There are no Products available by this Category \n";
	}
}

void filters()
{
	char filterchoice, priceChoice = { 0 };
	const int row = 50, col = 6;
	string filters[row][col] = { {"[$1 - $20]" , "[$20 - $50]" , "[$50 - $200]" , "[$200 - $500]" , "[$500 - $1000]" , "[$1000+]"} , {""} };
	bool flag = true, flag2 = false;
	do {
		cout << "Do you want to filter products by Prices (Y/N)? ";
		cin >> filterchoice;
		if (filterchoice == 'Y' || filterchoice == 'y')
		{
			flag = false;
			flag2 = true;
			for (int i = 0; i < maxOwners; i++)
			{
				for (int j = 0; j < maxProds; j++)
				{
					if (Owners[i].Shops.products[j].productPrice >= 1 && Owners[i].Shops.products[j].productPrice <= 20)
					{
						for (int k = 1; k < row; k++)
						{
							filters[k][0] = Owners[i].Shops.products[j].productName;
						}
					}
					if (Owners[i].Shops.products[j].productPrice >= 20 && Owners[i].Shops.products[j].productPrice <= 50)
					{
						for (int k = 1; k < row; k++)
						{
							filters[k][1] = Owners[i].Shops.products[j].productName;
						}
					}
					if (Owners[i].Shops.products[j].productPrice > 50 && Owners[i].Shops.products[j].productPrice <= 200)
					{
						for (int k = 1; k < row; k++)
						{
							filters[k][2] = Owners[i].Shops.products[j].productName;
						}
					}
					if (Owners[i].Shops.products[j].productPrice >= 200 && Owners[i].Shops.products[j].productPrice <= 500)
					{
						for (int k = 1; k < row; k++)
						{
							filters[k][3] = Owners[i].Shops.products[j].productName;
						}
					}
					if (Owners[i].Shops.products[j].productPrice >= 500 && Owners[i].Shops.products[j].productPrice < 1000)
					{
						for (int k = 1; k < row; k++)
						{
							filters[k][4] = Owners[i].Shops.products[j].productName;
						}
					}
					if (Owners[i].Shops.products[j].productPrice >= 1000)
					{
						for (int k = 1; k < row; k++)
						{
							filters[k][5] = Owners[i].Shops.products[j].productName;
						}
					}
				}
			}
		}
		else if (filterchoice == 'N' || filterchoice == 'n')
		{
			flag2 = false;
			flag = false;
		}
		else
		{
			cout << "Error, Invalid Choice";
			flag = true;
		}
	} while (flag);
	if (flag2) {
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (filters[i][j] != "")
				{
					cout << j + 1 << ") " << filters[i][j] << endl;
				}
			}
		}
	}
}

void fchoice() {

	char choice;
	bool flag = true;
	cout << "Filter by :\n1 ) Price\n2 ) Category\n3 ) Shop \n";
	cout << "Choice : ";
	cin >> choice;
	do {
		switch (choice)
		{
		case '1':
			filters();
			priceFilter();
			flag = false;
			break;
		case '2':
			ByCategory();
			flag = false;
			break;
		case '3':
			ShopFilter();
			flag = false;
			break;
		default:
			cout << "Invalid Choice.";
			flag = true;
			break;
		}
	} while (flag);
}

void priceFilter()
{
	char choice;
	cout << "\n1] ($1 - $20)\n2] ($20 - $50)\n3] ($50 - $200)\n4] ($200 - $500)\n5] ($500 - $1000)\n6] ($1000+)" << endl << endl;
	cout << "Choice : ";
	cin >> choice;
	switch (choice)
	{
	case '1':
		for (int i = 0; i < maxOwners; i++)
		{
			for (int j = 0; j < maxProds; j++)
			{
				if (Owners[i].Shops.products[j].productPrice >= 1 && Owners[i].Shops.products[j].productPrice <= 20)
				{
					cout << "Name : " << Owners[i].Shops.products[j].productName << endl;
					cout << "Price : " << Owners[i].Shops.products[j].productPrice << endl;
					cout << "Quantity : " << Owners[i].Shops.products[j].Quantity << endl;
					cout << "Rating : " << Owners[i].Shops.products[j].avgRating << endl;
					cout << "Category : " << Owners[i].Shops.products[j].Category << endl;
					if (Owners[i].Shops.products[j].Category == "Clothing")
					{
						cout << "Type : " << Owners[i].Shops.products[j].Clothes.Type << endl;
						cout << "Size : " << Owners[i].Shops.products[j].Clothes.Size << endl;
						cout << "Color : " << Owners[i].Shops.products[j].Clothes.Color << endl;
					}
					cout << endl << endl;
				}
			}
		}
		break;

	case '2':
		for (int i = 0; i < maxOwners; i++)
		{

			for (int j = 0; j < maxProds; j++)
			{
				if (Owners[i].Shops.products[j].productPrice >= 20 && Owners[i].Shops.products[j].productPrice <= 50)
				{
					cout << "Name : " << Owners[i].Shops.products[j].productName << endl;
					cout << "Price : " << Owners[i].Shops.products[j].productPrice << endl;
					cout << "Quantity : " << Owners[i].Shops.products[j].Quantity << endl;
					cout << "Rating : " << Owners[i].Shops.products[j].avgRating << endl;
					cout << "Category : " << Owners[i].Shops.products[j].Category << endl;
					if (Owners[i].Shops.products[j].Category == "Clothing")
					{
						cout << "Type : " << Owners[i].Shops.products[j].Clothes.Type << endl;
						cout << "Size : " << Owners[i].Shops.products[j].Clothes.Size << endl;
						cout << "Color : " << Owners[i].Shops.products[j].Clothes.Color << endl;
					}
					cout << endl << endl;
				}
			}

		}
		break;

	case '3':
		for (int i = 0; i < maxOwners; i++)
		{
			for (int j = 0; j < maxProds; j++)
			{
				if (Owners[i].Shops.products[j].productPrice >= 50 && Owners[i].Shops.products[j].productPrice <= 200)
				{
					cout << "Name : " << Owners[i].Shops.products[j].productName << endl;
					cout << "Price : " << Owners[i].Shops.products[j].productPrice << endl;
					cout << "Quantity : " << Owners[i].Shops.products[j].Quantity << endl;
					cout << "Rating : " << Owners[i].Shops.products[j].avgRating << endl;
					cout << "Category : " << Owners[i].Shops.products[j].Category << endl;
					if (Owners[i].Shops.products[j].Category == "Clothing")
					{
						cout << "Type : " << Owners[i].Shops.products[j].Clothes.Type << endl;
						cout << "Size : " << Owners[i].Shops.products[j].Clothes.Size << endl;
						cout << "Color : " << Owners[i].Shops.products[j].Clothes.Color << endl;
					}
					cout << endl << endl;
				}
			}
		}

		break;

	case '4':for (int i = 0; i < maxOwners; i++)
	{
		for (int j = 0; j < maxProds; j++)
		{
			if (Owners[i].Shops.products[j].productPrice >= 200 && Owners[i].Shops.products[j].productPrice <= 500)
			{
				cout << "Name : " << Owners[i].Shops.products[j].productName << endl;
				cout << "Price : " << Owners[i].Shops.products[j].productPrice << endl;
				cout << "Quantity : " << Owners[i].Shops.products[j].Quantity << endl;
				cout << "Rating : " << Owners[i].Shops.products[j].avgRating << endl;
				cout << "Category : " << Owners[i].Shops.products[j].Category << endl;
				if (Owners[i].Shops.products[j].Category == "Clothing")
				{
					cout << "Type : " << Owners[i].Shops.products[j].Clothes.Type << endl;
					cout << "Size : " << Owners[i].Shops.products[j].Clothes.Size << endl;
					cout << "Color : " << Owners[i].Shops.products[j].Clothes.Color << endl;
				}
				cout << endl << endl;
			}
		}
	}
			 break;

	case '5':for (int i = 0; i < maxOwners; i++)
	{
		for (int j = 0; j < maxProds; j++)
		{
			if (Owners[i].Shops.products[j].productPrice >= 500 && Owners[i].Shops.products[j].productPrice <= 1000)
			{
				cout << "Name : " << Owners[i].Shops.products[j].productName << endl;
				cout << "Price : " << Owners[i].Shops.products[j].productPrice << endl;
				cout << "Quantity : " << Owners[i].Shops.products[j].Quantity << endl;
				cout << "Rating : " << Owners[i].Shops.products[j].avgRating << endl;
				cout << "Category : " << Owners[i].Shops.products[j].Category << endl;
				if (Owners[i].Shops.products[j].Category == "Clothing")
				{
					cout << "Type : " << Owners[i].Shops.products[j].Clothes.Type << endl;
					cout << "Size : " << Owners[i].Shops.products[j].Clothes.Size << endl;
					cout << "Color : " << Owners[i].Shops.products[j].Clothes.Color << endl;
				}
				cout << endl << endl;
			}
		}
	}
			 break;

	case '6':for (int i = 0; i < maxOwners; i++)
	{
		for (int j = 0; j < maxProds; j++)
		{
			if (Owners[i].Shops.products[j].productPrice > 1000)
			{
				cout << "Name : " << Owners[i].Shops.products[j].productName << endl;
				cout << "Category : " << Owners[i].Shops.products[j].Category << endl;
				cout << "Price : " << Owners[i].Shops.products[j].productPrice << endl;
				cout << "Rating : " << Owners[i].Shops.products[j].avgRating << endl;
				cout << "Quantity : " << Owners[i].Shops.products[j].Quantity << endl;
				if (Owners[i].Shops.products[j].Category == "Clothing")
				{
					cout << "Type : " << Owners[i].Shops.products[j].Clothes.Type << endl;
					cout << "Size : " << Owners[i].Shops.products[j].Clothes.Size << endl;
					cout << "Color : " << Owners[i].Shops.products[j].Clothes.Color << endl;
				}
				cout << endl << endl;
			}
		}
	}
			 break;
	default: cout << "Error";
	}
}

void ShopFilter()
{
	int choice;
	for (int i = 0; i < maxOwners; i++)
	{
		if (Owners[i].Shops.ShopName != "") {
			cout << i + 1 << " - " << Owners[i].Shops.ShopName << endl;
		}
	}
	cout << "Choice : ";
	cin >> choice;
	if (choice > 25)
	{
		cout << "Invalid Number";
	}
	cout << "Shop : " << Owners[choice - 1].Shops.ShopName;
	for (int j = 0; j < maxProds; j++) {
		cout << "Name : " << Owners[choice - 1].Shops.products[j].productName << endl;
		cout << "Price : " << Owners[choice - 1].Shops.products[j].productPrice << endl;
		cout << "Quantity : " << Owners[choice - 1].Shops.products[j].Quantity << endl;
		cout << "Rating : " << Owners[choice - 1].Shops.products[j].avgRating << endl;
		cout << "Category : " << Owners[choice - 1].Shops.products[j].Category << endl;
		if (Owners[choice - 1].Shops.products[j].Category == "Clothing")
		{
			cout << "Type : " << Owners[choice - 1].Shops.products[j].Clothes.Type << endl;
			cout << "Size : " << Owners[choice - 1].Shops.products[j].Clothes.Size << endl;
			cout << "Color : " << Owners[choice - 1].Shops.products[j].Clothes.Color << endl;
		}
		cout << endl << endl;
	}
}