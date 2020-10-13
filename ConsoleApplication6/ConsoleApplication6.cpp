#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include <string.h>
#include <conio.h>
#include<fstream>
#include <sstream>
#include <windows.h>
#include <stdio.h>
#include <SFML\Audio.hpp>


using namespace std;

const int maxShoppers = 25, maxOwners = 25, maxProds = 10, maxPass = 32;
int LogIndex = maxOwners, day = 0, month = 0, LogID = 0;
sf::Music music;

struct views {

	int x;
	int y;

};

struct num {
	int nump = 0;
	int index = 0;
	views num[15];

}cv;
struct  save
{
	views sav[15];
	int amount[15];
	int sub[15];

}kk;
struct Clothing
{
	string Size;
	string Type;
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
	int price;
	string shop;
	int subtotal = 0;
} shopperCart[15];
struct Product
{
	string productName = { 0 };
	int productPrice = 0;
	int oldPrice = 0;
	string Category;
	Clothing Clothes;
	int Quantity = 0;
	int counter = 0;
	int sum = 0;
	int avgRating;
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
	string Password;
	int PassNum;
	int Age;
	string Gender;
	Address Add;
	Shop Shops;
} Owners[maxOwners];
struct see {
	int a[75];
	int b[75];
}m;
struct shopper {
	string name;
	int id;
	string pass;
	int passnum;
	int age;
	string gender;
	Address Add;
	int purchaseHistory[10] = { 0 };
	int days[10] = { 0 };
	int months[10] = { 0 };
	int purchases = 0;
}Shoppers[maxShoppers];


sf::RenderWindow window(sf::VideoMode(920, 800), "  StoreSome", sf::Style::Close | sf::Style::Default);
sf::RectangleShape photo(sf::Vector2f(920.0f, 800.0f));
sf::RectangleShape phot(sf::Vector2f(920.0f, 800.0f));

using namespace std;
int shopprofile(int x);
int shopperprofile(int x);
int ownerprofile(int x);
int shopperchoice();
void welcomewindow();
int ownerchoice();
void welcome();
int regshoper();
int regowner();
int loginowner();
int loginshopper();
void scchoice();
int search();
void regshop();
int prodchoice();
int editshoper();
int editshop();
int editowner();
int addproduct();
void viewproduct();
void homepageOwner();
int discount();
int remove();
int viewproductsOwner();
int editprod();
void deleteshopper();
int cart();
int receipt(int ind);
void prodmenu();
int filtersmenu();
int giftsmenu();
void deleteOwner();
int purchaseHistory(int HI);
int viewbysearch(string s);
int bycategory();
int byshop();
int byprice();
int viewbyprice(int x, int y);
int viewbystring(string s, int nums);
int rating();
int RegOwner(string name, string Password, int passnum, int age, string gender, string country, string city);
void Lowner(int id, string pass, int j);
void ogRegShop(int i, string categoryChoice, string name, string country, string city);
void editprods(int j, bool flag, bool flag2, bool flag3, string Newname, int price, int quantity, string name);
int Regshopper(string name, string Password, int passnum, int age, string gender, string country, string city);
void Lshopper(int id, string pass, int j);
void addProds(int j, string name, int price, int quantity, string type, string size, string color);
void Eowner(int j, bool fname, bool fgender, bool fpass, bool fage, bool fcountry, bool fcity, string name, string newpass, int passnum, string gender, int age, string city, string country);
void Eshopper(int j, bool fname, bool fgender, bool fpass, bool fage, bool fcountry, bool fcity, string name, string newpass, int passnum, string gender, int age, string city, string country);
void editShopdata(int j, bool fname, bool fcountry, bool fcity, bool fcategory, string name, string country, string city, string category);
int removeProds(int j, string name);
void seearch(string name);
void discounts(int j, string name, int discount, int month2, int day2);
void ogRating(int ratenum, int rating);
void del(int j);
void removeReg(int j);
void deletee(int deletenum);
void discCheck();
void open();
void save();


int main() {

	

	photo.setPosition(0, 0);
	sf::Texture wallpaper;
	wallpaper.loadFromFile("AdobeStock_7086941111444.jpg");
	photo.setTexture(&wallpaper);

	phot.setPosition(0, 0);
	sf::Texture wall;
	wall.loadFromFile("pexels-photo.jpg");
	phot.setTexture(&wall);

	if (!music.openFromFile("music.wav")) {
		cout << "ERROR" << std::endl;
	}
	music.play();
	music.setLoop(true);

	SYSTEMTIME st;
	GetSystemTime(&st);
	day = st.wDay;
	month = st.wMonth;
	discCheck();


	welcomewindow();
	welcome();



	return 0;
}


void open() {

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
	Owners[0].Add.Country;
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
				}
				Products.ignore();
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
	int x;
	Owner << s.countOwn << endl;
	x = s.countOwn;
	for (int i = 0; i < x; i++) {
		if (Owners[i].Age != 0) {
			Owner << Owners[i].Name << endl << Owners[i].Gender << endl << Owners[i].Add.Country << endl << Owners[i].Add.City << endl << Owners[i].Shops.ShopName << endl << Owners[i].Shops.Category << endl << Owners[i].Shops.Add.Country << endl << Owners[i].Shops.Add.City << endl << Owners[i].ID << endl << Owners[i].Age << endl << Owners[i].PassNum << endl << Owners[i].Password << '\n';
		}
		else
			x++;
	}
	Shopper.open("Shopper.txt", ios::trunc);
	int y;
	Shopper << s.countShopper << endl;
	y = s.countShopper;
	for (int i = 0; i < y; i++) {
		if (Shoppers[i].age != 0) {
			Shopper << Shoppers[i].name << endl << Shoppers[i].gender << endl << Shoppers[i].Add.Country << endl << Shoppers[i].Add.City << endl << Shoppers[i].id << endl << Shoppers[i].age << endl << Shoppers[i].passnum << endl << Shoppers[i].pass << endl;
			Shopper << Shoppers[i].purchases << endl;
			if (Shoppers[i].purchases != 0) {
				for (int j = 0; j < Shoppers[i].purchases; j++) {
					Shopper << Shoppers[i].purchaseHistory[j] << endl << Shoppers[i].days[j] << endl << Shoppers[i].months[j] << endl;
				}
			}
		}
		else
			y++;
	}
	Products.open("Products.txt", ios::trunc);
	int z;
	for (int i = 0; i < maxOwners; i++) {
		Products << Owners[i].Shops.countProd << endl;
		z = Owners[i].Shops.countProd;
		if (Owners[i].Shops.countProd != 0) {
			for (int j = 0; j < z; j++) {
				if (Owners[i].Shops.products[j].Category != "") {
					if (Owners[i].Shops.Category == "Clothing") {
						Products << Owners[i].Shops.products[j].productName << endl << Owners[i].Shops.products[j].Category << endl << Owners[i].Shops.products[j].Clothes.Color << endl << Owners[i].Shops.products[j].Clothes.Type << endl << Owners[i].Shops.products[j].Clothes.Size << endl << Owners[i].Shops.products[j].productPrice << endl << Owners[i].Shops.products[j].Quantity << '\n' << Owners[i].Shops.products[j].avgRating << endl << Owners[i].Shops.products[j].oldPrice << endl << Owners[i].Shops.products[j].sum << endl << Owners[i].Shops.products[j].counter << endl << Owners[i].Shops.products[j].month << endl << Owners[i].Shops.products[j].day << endl;
					}
					else {
						Products << Owners[i].Shops.products[j].productName << endl << Owners[i].Shops.products[j].Category << endl << Owners[i].Shops.products[j].productPrice << endl << Owners[i].Shops.products[j].Quantity << '\n' << Owners[i].Shops.products[j].avgRating << endl << Owners[i].Shops.products[j].oldPrice << endl << Owners[i].Shops.products[j].sum << endl << Owners[i].Shops.products[j].counter << endl << Owners[i].Shops.products[j].month << endl << Owners[i].Shops.products[j].day << endl;
					}
				}
				else
					z++;
			}
		}
	}
	Owner.close();
	Shopper.close();
	Products.close();
}

void welcome() {

	open();

	sf::Font font;
	font.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString(" User ");
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::White);
	text.setPosition(450, 500);
	text.setStyle(sf::Text::Bold);

	sf::Text textn;
	textn.setFont(font);
	textn.setString(" Owner ");
	textn.setCharacterSize(40);
	textn.setFillColor(sf::Color::White);
	textn.setPosition(150, 500);
	textn.setStyle(sf::Text::Bold);

	sf::RectangleShape choiceb(sf::Vector2f(86.0f, 25.0f));
	choiceb.setPosition(sf::Vector2f(695, 700));
	choiceb.setFillColor(sf::Color::Transparent);
	choiceb.setOutlineColor(sf::Color::Red);
	choiceb.setOutlineThickness(4);

	sf::Font fontr;
	fontr.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textr;
	textr.setFont(fontr);
	textr.setString("  Theme ");
	textr.setCharacterSize(20);
	textr.setFillColor(sf::Color::Red);
	textr.setPosition(696, 700);
	textr.setStyle(sf::Text::Bold);

	sf::Texture wallpaper;


	sf::RectangleShape choice(sf::Vector2f(200.0f, 80.0f));
	choice.setPosition(sf::Vector2f(150, 490));
	choice.setFillColor(sf::Color::Transparent);
	choice.setOutlineThickness(5);
	choice.setOutlineColor(sf::Color::White);
	sf::RectangleShape choicee(sf::Vector2f(200.0f, 80.0f));
	choicee.setPosition(sf::Vector2f(450, 490));
	choicee.setFillColor(sf::Color::Transparent);
	choicee.setOutlineThickness(5);
	choicee.setOutlineColor(sf::Color::White);

	int flag = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i local_position = sf::Mouse::getPosition(window);
				cout << '(' << local_position.x << ',' << local_position.y << ')' << endl;
				if (local_position.x >= 146 && local_position.x <= 352 && local_position.y >= 487 && local_position.y <= 570) {

					window.clear();
					ownerchoice();
					break;
				}
				else if (local_position.x >= 690 && local_position.x <= 783 && local_position.y >= 696 && local_position.y <= 728) {
					flag++;
					if (flag >= 4)
					{
						flag = 0;
					}
					cout << "theme" << endl;

				}
				else if (local_position.x >= 446 && local_position.x <= 651 && local_position.y >= 487 && local_position.y <= 570) {

					shopperchoice();
					break;
				}
			}
		}
		if (flag == 0) {
			wallpaper.loadFromFile("AdobeStock_7086941111444.jpg");
			photo.setTexture(&wallpaper);
		}
		else if (flag == 1) {
			wallpaper.loadFromFile("lol.jpg");
			photo.setTexture(&wallpaper);
		}
		else if (flag == 2) {
			wallpaper.loadFromFile("lila.jpg");
			photo.setTexture(&wallpaper);
		}
		else if (flag == 3) {
			wallpaper.loadFromFile("black.jpg");
			photo.setTexture(&wallpaper);
		}
		window.draw(photo);
		window.draw(text);
		window.draw(textn);
		window.draw(choice);
		window.draw(choicee);
		window.draw(choiceb);
		window.draw(textr);

		window.display();
	}
}

void welcomewindow() {

	sf::Clock clock;
	sf::Time elapsed = clock.getElapsedTime();
	while (window.isOpen())
	{

		sf::Time elapsed = clock.getElapsedTime();
		cout << elapsed.asSeconds() << endl;

		window.draw(phot);
		window.display();
		if (elapsed.asSeconds() > 6.5)
			break;
	}

}

int regowner() {


	sf::RectangleShape choice40(sf::Vector2f(80.0f, 30.0f));
	choice40.setPosition(sf::Vector2f(812, 748));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::Red);
	choice40.setOutlineThickness(3);

	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" BACK ");
	text10.setCharacterSize(20);
	text10.setFillColor(sf::Color::Red);
	text10.setPosition(820, 750);
	text10.setStyle(sf::Text::Bold);

	sf::RectangleShape choice1(sf::Vector2f(550.0f, 20.0f));
	choice1.setPosition(sf::Vector2f(200, 20));
	choice1.setFillColor(sf::Color::White);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(7);

	sf::RectangleShape choice2(sf::Vector2f(550.0f, 20.0f));
	choice2.setPosition(sf::Vector2f(200, 60));
	choice2.setFillColor(sf::Color::White);
	choice2.setOutlineColor(sf::Color::White);
	choice2.setOutlineThickness(7);

	sf::RectangleShape choice3(sf::Vector2f(550.0f, 20.0f));
	choice3.setPosition(sf::Vector2f(200, 100));
	choice3.setFillColor(sf::Color::White);
	choice3.setOutlineColor(sf::Color::White);
	choice3.setOutlineThickness(7);

	sf::RectangleShape choice4(sf::Vector2f(550.0f, 20.0f));
	choice4.setPosition(sf::Vector2f(200, 140));
	choice4.setFillColor(sf::Color::White);
	choice4.setOutlineColor(sf::Color::White);
	choice4.setOutlineThickness(7);

	sf::RectangleShape choice5(sf::Vector2f(150.0f, 20.0f));
	choice5.setPosition(sf::Vector2f(200, 260));
	choice5.setFillColor(sf::Color::White);
	choice5.setOutlineColor(sf::Color::White);
	choice5.setOutlineThickness(7);

	sf::RectangleShape choice6(sf::Vector2f(150.0f, 20.0f));
	choice6.setPosition(sf::Vector2f(600, 260));
	choice6.setFillColor(sf::Color::White);
	choice6.setOutlineColor(sf::Color::White);
	choice6.setOutlineThickness(7);


	sf::RectangleShape choice71(sf::Vector2f(150.0f, 20.0f));
	choice71.setPosition(sf::Vector2f(200, 180));
	choice71.setFillColor(sf::Color::Transparent);
	choice71.setOutlineThickness(3);
	choice71.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice72(sf::Vector2f(150.0f, 20.0f));
	choice72.setPosition(sf::Vector2f(400, 180));
	choice72.setFillColor(sf::Color::Transparent);
	choice72.setOutlineThickness(3);
	choice72.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice8(sf::Vector2f(200.0f, 80.0f));
	choice8.setPosition(sf::Vector2f(450, 490));
	choice8.setFillColor(sf::Color::Transparent);
	choice8.setOutlineThickness(5);
	choice8.setOutlineColor(sf::Color::White);

	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String name;
	sf::Text textname(name, fontname, 25);
	textname.setFillColor(sf::Color::Black);
	textname.setPosition(200, 14);

	sf::Font fontpass;
	fontpass.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String passout;
	sf::Text textpass(passout, fontpass, 25);
	textpass.setFillColor(sf::Color::Black);
	textpass.setPosition(200, 55);

	sf::Font fontc;
	fontc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String confout;
	sf::Text textconf(confout, fontc, 25);
	textconf.setFillColor(sf::Color::Black);
	textconf.setPosition(200, 95);

	sf::Font fontage;
	fontage.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String age;
	sf::Text textage(age, fontage, 25);
	textage.setFillColor(sf::Color::Black);
	textage.setPosition(200, 135);

	sf::Font fontgend;
	fontgend.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String gender;
	sf::Text textgend(gender, fontage, 25);
	textgend.setFillColor(sf::Color::Black);
	textgend.setPosition(200, 175);

	sf::Font fontcity;
	fontcity.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String city;
	sf::Text textcity(city, fontcity, 25);
	textcity.setFillColor(sf::Color::Black);
	textcity.setPosition(200, 255);

	sf::Font fontcountry;
	fontcountry.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String country;
	sf::Text textcountry(country, fontcountry, 25);
	textcountry.setFillColor(sf::Color::Black);
	textcountry.setPosition(600, 255);


	sf::Font fonta;
	fonta.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texta;
	texta.setFont(fonta);
	texta.setString("Name             : ");
	texta.setCharacterSize(30);
	texta.setFillColor(sf::Color::White);
	texta.setPosition(10, 10);
	texta.setStyle(sf::Text::Regular);

	sf::Font fontb;
	fontb.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textb;
	textb.setFont(fontb);
	textb.setString("Password     : ");
	textb.setCharacterSize(30);
	textb.setFillColor(sf::Color::White);
	textb.setPosition(10, 50);
	textb.setStyle(sf::Text::Regular);

	sf::Font fontz;
	fontz.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textz;
	textz.setFont(fontz);
	textz.setString("C.Password :");
	textz.setCharacterSize(30);
	textz.setFillColor(sf::Color::White);
	textz.setPosition(10, 90);
	textz.setStyle(sf::Text::Regular);

	sf::Font fontl;
	fontl.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textc;
	textc.setFont(fontc);
	textc.setString("Age                : ");
	textc.setCharacterSize(30);
	textc.setFillColor(sf::Color::White);
	textc.setPosition(10, 130);
	textc.setStyle(sf::Text::Regular);

	sf::Font fontd;
	fontd.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textd;
	textd.setFont(fontd);
	textd.setString("Gender          : ");
	textd.setCharacterSize(30);
	textd.setFillColor(sf::Color::White);
	textd.setPosition(10, 170);
	textd.setStyle(sf::Text::Regular);

	sf::Font fontq;
	fontq.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textq;
	textq.setFont(fonta);
	textq.setString("    Male ");
	textq.setCharacterSize(20);
	textq.setFillColor(sf::Color::White);
	textq.setPosition(235, 177);
	textq.setStyle(sf::Text::Regular);

	sf::Font fontw;
	fontw.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textw;
	textw.setFont(fonta);
	textw.setString(" Female ");
	textw.setCharacterSize(20);
	textw.setFillColor(sf::Color::White);
	textw.setPosition(435, 177);
	textw.setStyle(sf::Text::Regular);

	sf::Font fonte;
	fonte.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texte;
	texte.setFont(fonte);
	texte.setString("Adress. ");
	texte.setCharacterSize(30);
	texte.setFillColor(sf::Color::White);
	texte.setPosition(10, 210);
	texte.setStyle(sf::Text::Regular);

	sf::Font fontf;
	fontf.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textf;
	textf.setFont(fontf);
	textf.setString("city                 :");
	textf.setCharacterSize(30);
	textf.setFillColor(sf::Color::White);
	textf.setPosition(10, 250);
	textf.setStyle(sf::Text::Regular);

	sf::Font fontg;
	fontg.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textg;
	textg.setFont(fontg);
	textg.setString("Country           :");
	textg.setCharacterSize(30);
	textg.setFillColor(sf::Color::White);
	textg.setPosition(400, 250);
	textg.setStyle(sf::Text::Regular);

	sf::Font font;
	font.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("      Next   ");
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::White);
	text.setPosition(430, 500);
	text.setStyle(sf::Text::Bold);

	sf::Font fontid;
	fontid.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textid;
	textid.setFont(font);
	textid.setString("    Your ID Is : ");
	textid.setCharacterSize(40);
	textid.setFillColor(sf::Color::White);
	textid.setPosition(190, 430);
	textid.setStyle(sf::Text::Bold);

	sf::Font fontk;
	fontk.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textk;
	textk.setFont(fontz);
	textk.setString("  ** Please fill the spaces ** ");
	textk.setCharacterSize(28);
	textk.setFillColor(sf::Color::White);
	textk.setPosition(190, 430);
	textk.setStyle(sf::Text::Bold);

	sf::Font fontn;
	fontn.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textn;
	textn.setFont(fontz);
	textn.setString("  ** Password Must Be At Least 6 Digits **  ");
	textn.setCharacterSize(28);
	textn.setFillColor(sf::Color::White);
	textn.setPosition(150, 430);
	textn.setStyle(sf::Text::Bold);

	sf::String pass;
	sf::String conf;


	sf::Font fontj;
	fontj.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textj;
	textj.setFont(fontz);
	textj.setString("  ** password Does Not Match ** ");
	textj.setCharacterSize(28);
	textj.setFillColor(sf::Color::White);
	textj.setPosition(190, 430);
	textj.setStyle(sf::Text::Bold);

	int active, age1;
	bool fill = false;
	bool password = false;
	bool numpassword = false;

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 193 && localposition.x <= 750 && localposition.y >= 16 && localposition.y <= 40) {
					active = 1;
					cout << "name" << endl;

				}
				else if (localposition.x >= 808 && localposition.x <= 893 && localposition.y >= 747 && localposition.y <= 778) {
					return 0;
					cout << "back" << endl;

				}
				else if (localposition.x >= 193 && localposition.x <= 750 && localposition.y >= 55 && localposition.y <= 82) {
					active = 2;
					cout << "password" << endl;
				}
				else if (localposition.x >= 193 && localposition.x <= 750 && localposition.y >= 95 && localposition.y <= 128) {
					active = 3;
					cout << "confirmation" << endl;

				}
				else if (localposition.x >= 193 && localposition.x <= 750 && localposition.y >= 133 && localposition.y <= 165) {
					active = 4;
					cout << "age" << endl;

				}
				else if (localposition.x >= 197 && localposition.x <= 350 && localposition.y >= 177 && localposition.y <= 199) {
					active = 5;
					textq.setFillColor(sf::Color::Red);
					textw.setFillColor(sf::Color::White);
					choice71.setOutlineColor(sf::Color::Red);
					choice72.setOutlineColor(sf::Color::White);
					cout << "male" << endl;
					gender = ("Male");

				}
				else if (localposition.x >= 397 && localposition.x <= 551 && localposition.y >= 177 && localposition.y <= 200) {
					active = 5;
					textw.setFillColor(sf::Color::Red);
					textq.setFillColor(sf::Color::White);
					choice72.setOutlineColor(sf::Color::Red);
					choice71.setOutlineColor(sf::Color::White);
					cout << "female" << endl;
					gender = ("Female");

				}
				else if (localposition.x >= 193 && localposition.x <= 355 && localposition.y >= 255 && localposition.y <= 283) {
					active = 6;
					cout << "city" << endl;

				}
				else if (localposition.x >= 595 && localposition.x <= 753 && localposition.y >= 255 && localposition.y <= 283) {
					active = 7;
					cout << "country" << endl;

				}
				else if (localposition.x >= 443 && localposition.x <= 652 && localposition.y >= 485 && localposition.y <= 569 && gender.getSize() == 0 || age.getSize() == 0 || name.getSize() == 0 || city.getSize() == 0 && country.getSize() == 0) {
					fill = true;
					password = false;
					numpassword = false;
				}
				else if (localposition.x >= 443 && localposition.x <= 652 && localposition.y >= 485 && localposition.y <= 569 && gender.getSize() > 0 && age.getSize() > 0 && pass.getSize() > 5 && pass == conf && name.getSize() > 0 && city.getSize() > 0 && country.getSize() > 0) {

					istringstream(age) >> age1;


					LogIndex = RegOwner(name, pass, passout.getSize(), age1, gender, country, city);
					LogID = LogIndex;
					regshop();
				}
				else if (localposition.x >= 443 && localposition.x <= 652 && localposition.y >= 485 && localposition.y <= 569 && (gender == ("Male") || gender == ("Female")) && age.getSize() > 0 && pass.getSize() > 5 && conf.getSize() > 5 && (conf != pass) && name.getSize() > 0 && city.getSize() > 0 && country.getSize() > 0) {

					numpassword = false;
					fill = false;
					password = true;
				}
				else if (localposition.x >= 443 && localposition.x <= 652 && localposition.y >= 485 && localposition.y <= 569 && gender.getSize() > 0 && age.getSize() > 0 && pass.getSize() <= 5 || conf.getSize() <= 5 && (pass != conf || pass == conf) && name.getSize() > 0 && city.getSize() > 0 && country.getSize() > 0) {
					password = false;
					numpassword = true;
					fill = false;
				}

				else

					active = 0;

			}
			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					name += event.text.unicode;
					textname.setString(name);
				}
				else if (active == 1 && event.text.unicode == 8 && name.getSize() > 0)
				{
					name.erase(name.getSize() - 1, name.getSize());
					textname.setString(name);
				}
				if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					pass += event.text.unicode;
					passout += "*";
					textpass.setString(passout);

				}
				else if (active == 2 && event.text.unicode == 8 && pass.getSize() > 0) {
					pass.erase(pass.getSize() - 1, pass.getSize());
					passout.erase(passout.getSize() - 1, passout.getSize());
					textpass.setString(passout);
				}
				if (active == 3 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					conf += event.text.unicode;
					confout += "*";
					textconf.setString(confout);
				}
				else if (active == 3 && event.text.unicode == 8 && conf.getSize() > 0) {
					conf.erase(conf.getSize() - 1, conf.getSize());
					confout.erase(confout.getSize() - 1, confout.getSize());
					textconf.setString(confout);
				}
				if (active == 4 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					age += event.text.unicode;
					textage.setString(age);
				}
				else if (active == 4 && event.text.unicode == 8 && age.getSize() > 0) {
					age.erase(age.getSize() - 1, age.getSize());
					textage.setString(age);
				}
				if (active == 6 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					city += event.text.unicode;
					textcity.setString(city);
				}
				else if (active == 6 && event.text.unicode == 8 && city.getSize() > 0) {
					city.erase(city.getSize() - 1, city.getSize());
					textcity.setString(city);
				}
				if (active == 7 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					country += event.text.unicode;
					textcountry.setString(country);
				}
				else if (active == 7 && event.text.unicode == 8 && country.getSize() > 0) {
					country.erase(country.getSize() - 1, country.getSize());
					textcountry.setString(country);
				}
			}


			window.clear();
			window.draw(photo);
			window.draw(texta);
			window.draw(textb);
			window.draw(textc);
			window.draw(textd);
			window.draw(texte);
			window.draw(textf);
			window.draw(textg);
			window.draw(textz);
			window.draw(text);
			window.draw(textw);
			window.draw(textq);
			window.draw(text10);
			window.draw(choice1);
			window.draw(choice2);
			window.draw(choice3);
			window.draw(choice4);
			window.draw(choice5);
			window.draw(choice6);
			window.draw(choice71);
			window.draw(choice40);
			window.draw(choice72);
			window.draw(choice8);
			window.draw(textname);
			window.draw(textpass);
			window.draw(textconf);
			window.draw(textage);
			window.draw(textgend);
			window.draw(textcity);
			window.draw(textcountry);
			if (fill)
				window.draw(textk);
			if (password)
				window.draw(textj);
			if (numpassword)
				window.draw(textn);

			window.display();

		}
	}
}

int regshoper() {

	sf::RectangleShape choice40(sf::Vector2f(80.0f, 30.0f));
	choice40.setPosition(sf::Vector2f(812, 748));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::Red);
	choice40.setOutlineThickness(3);

	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" BACK ");
	text10.setCharacterSize(20);
	text10.setFillColor(sf::Color::Red);
	text10.setPosition(820, 750);
	text10.setStyle(sf::Text::Bold);

	sf::RectangleShape choice1(sf::Vector2f(550.0f, 20.0f));
	choice1.setPosition(sf::Vector2f(200, 20));
	choice1.setFillColor(sf::Color::White);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(7);

	sf::RectangleShape choice2(sf::Vector2f(550.0f, 20.0f));
	choice2.setPosition(sf::Vector2f(200, 60));
	choice2.setFillColor(sf::Color::White);
	choice2.setOutlineColor(sf::Color::White);
	choice2.setOutlineThickness(7);

	sf::RectangleShape choice3(sf::Vector2f(550.0f, 20.0f));
	choice3.setPosition(sf::Vector2f(200, 100));
	choice3.setFillColor(sf::Color::White);
	choice3.setOutlineColor(sf::Color::White);
	choice3.setOutlineThickness(7);

	sf::RectangleShape choice4(sf::Vector2f(550.0f, 20.0f));
	choice4.setPosition(sf::Vector2f(200, 140));
	choice4.setFillColor(sf::Color::White);
	choice4.setOutlineColor(sf::Color::White);
	choice4.setOutlineThickness(7);

	sf::RectangleShape choice5(sf::Vector2f(150.0f, 20.0f));
	choice5.setPosition(sf::Vector2f(200, 260));
	choice5.setFillColor(sf::Color::White);
	choice5.setOutlineColor(sf::Color::White);
	choice5.setOutlineThickness(7);

	sf::RectangleShape choice6(sf::Vector2f(150.0f, 20.0f));
	choice6.setPosition(sf::Vector2f(600, 260));
	choice6.setFillColor(sf::Color::White);
	choice6.setOutlineColor(sf::Color::White);
	choice6.setOutlineThickness(7);


	sf::RectangleShape choice71(sf::Vector2f(150.0f, 20.0f));
	choice71.setPosition(sf::Vector2f(200, 180));
	choice71.setFillColor(sf::Color::Transparent);
	choice71.setOutlineThickness(3);
	choice71.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice72(sf::Vector2f(150.0f, 20.0f));
	choice72.setPosition(sf::Vector2f(400, 180));
	choice72.setFillColor(sf::Color::Transparent);
	choice72.setOutlineThickness(3);
	choice72.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice8(sf::Vector2f(200.0f, 80.0f));
	choice8.setPosition(sf::Vector2f(450, 490));
	choice8.setFillColor(sf::Color::Transparent);
	choice8.setOutlineThickness(5);
	choice8.setOutlineColor(sf::Color::White);

	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String name;
	sf::Text textname(name, fontname, 25);
	textname.setFillColor(sf::Color::Black);
	textname.setPosition(200, 14);

	sf::Font fontpass;
	fontpass.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String passout;
	sf::Text textpass(passout, fontpass, 25);
	textpass.setFillColor(sf::Color::Black);
	textpass.setPosition(200, 55);

	sf::Font fontc;
	fontc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String confout;
	sf::Text textconf(confout, fontc, 25);
	textconf.setFillColor(sf::Color::Black);
	textconf.setPosition(200, 95);

	sf::Font fontage;
	fontage.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String age;
	sf::Text textage(age, fontage, 25);
	textage.setFillColor(sf::Color::Black);
	textage.setPosition(200, 135);

	sf::Font fontgend;
	fontgend.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String gender;
	sf::Text textgend(gender, fontage, 25);
	textgend.setFillColor(sf::Color::Black);
	textgend.setPosition(200, 175);

	sf::Font fontcity;
	fontcity.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String city;
	sf::Text textcity(city, fontcity, 25);
	textcity.setFillColor(sf::Color::Black);
	textcity.setPosition(200, 255);

	sf::Font fontcountry;
	fontcountry.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String country;
	sf::Text textcountry(country, fontcountry, 25);
	textcountry.setFillColor(sf::Color::Black);
	textcountry.setPosition(600, 255);


	sf::Font fonta;
	fonta.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texta;
	texta.setFont(fonta);
	texta.setString("Name             : ");
	texta.setCharacterSize(30);
	texta.setFillColor(sf::Color::White);
	texta.setPosition(10, 10);
	texta.setStyle(sf::Text::Regular);

	sf::Font fontb;
	fontb.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textb;
	textb.setFont(fontb);
	textb.setString("Password     : ");
	textb.setCharacterSize(30);
	textb.setFillColor(sf::Color::White);
	textb.setPosition(10, 50);
	textb.setStyle(sf::Text::Regular);

	sf::Font fontz;
	fontz.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textz;
	textz.setFont(fontz);
	textz.setString("C.Password :");
	textz.setCharacterSize(30);
	textz.setFillColor(sf::Color::White);
	textz.setPosition(10, 90);
	textz.setStyle(sf::Text::Regular);

	sf::Font fontl;
	fontl.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textc;
	textc.setFont(fontc);
	textc.setString("Age                : ");
	textc.setCharacterSize(30);
	textc.setFillColor(sf::Color::White);
	textc.setPosition(10, 130);
	textc.setStyle(sf::Text::Regular);

	sf::Font fontd;
	fontd.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textd;
	textd.setFont(fontd);
	textd.setString("Gender          : ");
	textd.setCharacterSize(30);
	textd.setFillColor(sf::Color::White);
	textd.setPosition(10, 170);
	textd.setStyle(sf::Text::Regular);

	sf::Font fontq;
	fontq.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textq;
	textq.setFont(fonta);
	textq.setString("    Male ");
	textq.setCharacterSize(20);
	textq.setFillColor(sf::Color::White);
	textq.setPosition(235, 177);
	textq.setStyle(sf::Text::Regular);

	sf::Font fontw;
	fontw.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textw;
	textw.setFont(fonta);
	textw.setString(" Female ");
	textw.setCharacterSize(20);
	textw.setFillColor(sf::Color::White);
	textw.setPosition(435, 177);
	textw.setStyle(sf::Text::Regular);

	sf::Font fonte;
	fonte.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texte;
	texte.setFont(fonte);
	texte.setString("Adress. ");
	texte.setCharacterSize(30);
	texte.setFillColor(sf::Color::White);
	texte.setPosition(10, 210);
	texte.setStyle(sf::Text::Regular);

	sf::Font fontf;
	fontf.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textf;
	textf.setFont(fontf);
	textf.setString("city                 :");
	textf.setCharacterSize(30);
	textf.setFillColor(sf::Color::White);
	textf.setPosition(10, 250);
	textf.setStyle(sf::Text::Regular);

	sf::Font fontg;
	fontg.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textg;
	textg.setFont(fontg);
	textg.setString("Country           :");
	textg.setCharacterSize(30);
	textg.setFillColor(sf::Color::White);
	textg.setPosition(400, 250);
	textg.setStyle(sf::Text::Regular);

	sf::Font font;
	font.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("    Register   ");
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::White);
	text.setPosition(430, 500);
	text.setStyle(sf::Text::Bold);

	sf::Font fontid;
	fontid.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textid;
	textid.setFont(font);
	textid.setString("    Your ID Is : ");
	textid.setCharacterSize(40);
	textid.setFillColor(sf::Color::White);
	textid.setPosition(190, 430);
	textid.setStyle(sf::Text::Bold);

	sf::Font fontk;
	fontk.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textk;
	textk.setFont(fontz);
	textk.setString("  ** Please fill the spaces ** ");
	textk.setCharacterSize(28);
	textk.setFillColor(sf::Color::White);
	textk.setPosition(190, 430);
	textk.setStyle(sf::Text::Bold);

	sf::Font fontn;
	fontn.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textn;
	textn.setFont(fontz);
	textn.setString("  ** Password Must Be At Least 6 Digits **  ");
	textn.setCharacterSize(28);
	textn.setFillColor(sf::Color::White);
	textn.setPosition(150, 430);
	textn.setStyle(sf::Text::Bold);

	sf::String pass;
	sf::String conf;


	sf::Font fontj;
	fontj.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textj;
	textj.setFont(fontz);
	textj.setString("  ** password Does Not Match ** ");
	textj.setCharacterSize(28);
	textj.setFillColor(sf::Color::White);
	textj.setPosition(190, 430);
	textj.setStyle(sf::Text::Bold);

	int active, age1;
	bool fill = false;
	bool password = false;
	bool numpassword = false;

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 193 && localposition.x <= 750 && localposition.y >= 16 && localposition.y <= 40) {
					active = 1;
					cout << "name" << endl;

				}
				else if (localposition.x >= 808 && localposition.x <= 893 && localposition.y >= 747 && localposition.y <= 778) {
					return 0;
					cout << "back" << endl;

				}
				else if (localposition.x >= 193 && localposition.x <= 750 && localposition.y >= 55 && localposition.y <= 82) {
					active = 2;
					cout << "password" << endl;
				}
				else if (localposition.x >= 193 && localposition.x <= 750 && localposition.y >= 95 && localposition.y <= 128) {
					active = 3;
					cout << "confirmation" << endl;

				}
				else if (localposition.x >= 193 && localposition.x <= 750 && localposition.y >= 133 && localposition.y <= 165) {
					active = 4;
					cout << "age" << endl;

				}
				else if (localposition.x >= 197 && localposition.x <= 350 && localposition.y >= 177 && localposition.y <= 199) {
					active = 5;
					textw.setFillColor(sf::Color::White);
					textq.setFillColor(sf::Color::Red);
					choice72.setOutlineColor(sf::Color::White);
					choice71.setOutlineColor(sf::Color::Red);
					cout << "male" << endl;
					gender = ("Male");

				}
				else if (localposition.x >= 397 && localposition.x <= 551 && localposition.y >= 177 && localposition.y <= 200) {
					active = 5;
					textw.setFillColor(sf::Color::Red);
					textq.setFillColor(sf::Color::White);
					choice72.setOutlineColor(sf::Color::Red);
					choice71.setOutlineColor(sf::Color::White);
					cout << "female" << endl;
					gender = ("Female");

				}
				else if (localposition.x >= 193 && localposition.x <= 355 && localposition.y >= 255 && localposition.y <= 283) {
					active = 6;
					cout << "city" << endl;

				}
				else if (localposition.x >= 595 && localposition.x <= 753 && localposition.y >= 255 && localposition.y <= 283) {
					active = 7;
					cout << "country" << endl;

				}
				else if (localposition.x >= 443 && localposition.x <= 652 && localposition.y >= 485 && localposition.y <= 569 && gender.getSize() == 0 || age.getSize() == 0 || name.getSize() == 0 || city.getSize() == 0 && country.getSize() == 0) {
					fill = true;
					password = false;
					numpassword = false;
				}
				else if (localposition.x >= 443 && localposition.x <= 652 && localposition.y >= 485 && localposition.y <= 569 && gender.getSize() > 0 && age.getSize() > 0 && pass.getSize() > 5 && pass == conf && name.getSize() > 0 && city.getSize() > 0 && country.getSize() > 0) {


					istringstream(age) >> age1;


					LogIndex = Regshopper(name, pass, passout.getSize(), age1, gender, country, city);

					LogID = LogIndex;

					scchoice();
				}
				else if (localposition.x >= 443 && localposition.x <= 652 && localposition.y >= 485 && localposition.y <= 569 && (gender == ("Male") || gender == ("Female")) && age.getSize() > 0 && pass.getSize() > 5 && conf.getSize() > 5 && pass != conf && name.getSize() > 0 && city.getSize() > 0 && country.getSize() > 0) {

					numpassword = false;
					fill = false;
					password = true;
				}
				else if (localposition.x >= 443 && localposition.x <= 652 && localposition.y >= 485 && localposition.y <= 569 && gender.getSize() > 0 && age.getSize() > 0 && pass.getSize() <= 5 || conf.getSize() <= 5 && (pass != conf || pass == conf) && name.getSize() > 0 && city.getSize() > 0 && country.getSize() > 0) {
					password = false;
					numpassword = true;
					fill = false;
				}

				else

					active = 0;

			}
			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					name += event.text.unicode;
					textname.setString(name);
				}
				else if (active == 1 && event.text.unicode == 8 && name.getSize() > 0)
				{
					name.erase(name.getSize() - 1, name.getSize());
					textname.setString(name);
				}
				if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					pass += event.text.unicode;
					passout += "*";
					textpass.setString(passout);
				}
				else if (active == 2 && event.text.unicode == 8 && pass.getSize() > 0) {
					pass.erase(pass.getSize() - 1, pass.getSize());
					passout.erase(passout.getSize() - 1, passout.getSize());
					textpass.setString(passout);
				}
				if (active == 3 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					conf += event.text.unicode;
					confout += "*";
					textconf.setString(confout);
				}
				else if (active == 3 && event.text.unicode == 8 && conf.getSize() > 0) {
					conf.erase(conf.getSize() - 1, conf.getSize());
					confout.erase(confout.getSize() - 1, confout.getSize());
					textconf.setString(confout);
				}
				if (active == 4 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					age += event.text.unicode;
					textage.setString(age);
				}
				else if (active == 4 && event.text.unicode == 8 && age.getSize() > 0) {
					age.erase(age.getSize() - 1, age.getSize());
					textage.setString(age);
				}
				if (active == 6 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					city += event.text.unicode;
					textcity.setString(city);
				}
				else if (active == 6 && event.text.unicode == 8 && city.getSize() > 0) {
					city.erase(city.getSize() - 1, city.getSize());
					textcity.setString(city);
				}
				if (active == 7 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					country += event.text.unicode;
					textcountry.setString(country);
				}
				else if (active == 7 && event.text.unicode == 8 && country.getSize() > 0) {
					country.erase(country.getSize() - 1, country.getSize());
					textcountry.setString(country);
				}
			}


			window.clear();
			window.draw(photo);
			window.draw(texta);
			window.draw(textb);
			window.draw(textc);
			window.draw(textd);
			window.draw(texte);
			window.draw(textf);
			window.draw(textg);
			window.draw(textz);
			window.draw(text);
			window.draw(textw);
			window.draw(text10);
			window.draw(textq);
			window.draw(choice1);
			window.draw(choice2);
			window.draw(choice3);
			window.draw(choice4);
			window.draw(choice5);
			window.draw(choice6);
			window.draw(choice71);
			window.draw(choice72);
			window.draw(choice40);
			window.draw(choice8);
			window.draw(textname);
			window.draw(textpass);
			window.draw(textconf);
			window.draw(textage);
			window.draw(textgend);
			window.draw(textcity);
			window.draw(textcountry);
			if (fill)
				window.draw(textk);
			if (password)
				window.draw(textj);
			if (numpassword)
				window.draw(textn);

			window.display();

		}
	}
}

void regshop() {

	sf::RectangleShape choice1(sf::Vector2f(550.0f, 20.0f));
	choice1.setPosition(sf::Vector2f(200, 20));
	choice1.setFillColor(sf::Color::White);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(7);

	sf::RectangleShape choice2(sf::Vector2f(150.0f, 20.0f));
	choice2.setPosition(sf::Vector2f(600, 115));
	choice2.setFillColor(sf::Color::White);
	choice2.setOutlineColor(sf::Color::White);
	choice2.setOutlineThickness(7);


	sf::RectangleShape choice3(sf::Vector2f(150.0f, 20.0f));
	choice3.setPosition(sf::Vector2f(200, 115));
	choice3.setFillColor(sf::Color::White);
	choice3.setOutlineThickness(7);
	choice3.setOutlineColor(sf::Color::White);


	sf::RectangleShape choice8(sf::Vector2f(200.0f, 80.0f));
	choice8.setPosition(sf::Vector2f(450, 490));
	choice8.setFillColor(sf::Color::Transparent);
	choice8.setOutlineThickness(5);
	choice8.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice10(sf::Vector2f(330.0f, 40.0f));
	choice10.setPosition(sf::Vector2f(30, 190));
	choice10.setFillColor(sf::Color::Transparent);
	choice10.setOutlineColor(sf::Color::White);
	choice10.setOutlineThickness(3);

	sf::RectangleShape choice20(sf::Vector2f(330.0f, 40.0f));
	choice20.setPosition(sf::Vector2f(30, 260));
	choice20.setFillColor(sf::Color::Transparent);
	choice20.setOutlineColor(sf::Color::White);
	choice20.setOutlineThickness(3);

	sf::RectangleShape choice30(sf::Vector2f(330.0f, 40.0f));
	choice30.setPosition(sf::Vector2f(30, 330));
	choice30.setFillColor(sf::Color::Transparent);
	choice30.setOutlineColor(sf::Color::White);
	choice30.setOutlineThickness(3);

	sf::RectangleShape choice40(sf::Vector2f(330.0f, 40.0f));
	choice40.setPosition(sf::Vector2f(30, 400));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::White);
	choice40.setOutlineThickness(3);

	sf::RectangleShape choice50(sf::Vector2f(330.0f, 40.0f));
	choice50.setPosition(sf::Vector2f(30, 470));
	choice50.setFillColor(sf::Color::Transparent);
	choice50.setOutlineColor(sf::Color::White);
	choice50.setOutlineThickness(3);

	sf::RectangleShape choice60(sf::Vector2f(330.0f, 40.0f));
	choice60.setPosition(sf::Vector2f(30, 540));
	choice60.setFillColor(sf::Color::Transparent);
	choice60.setOutlineColor(sf::Color::White);
	choice60.setOutlineThickness(3);

	sf::RectangleShape choice70(sf::Vector2f(330.0f, 40.0f));
	choice70.setPosition(sf::Vector2f(30, 610));
	choice70.setFillColor(sf::Color::Transparent);
	choice70.setOutlineColor(sf::Color::White);
	choice70.setOutlineThickness(3);

	sf::Font font1;
	font1.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text1;
	text1.setFont(font1);
	text1.setString(" Phones & Tablets ");
	text1.setCharacterSize(30);
	text1.setFillColor(sf::Color::White);
	text1.setPosition(50, 188);
	text1.setStyle(sf::Text::Bold);

	sf::Font font2;
	font2.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text2;
	text2.setFont(font2);
	text2.setString("      Electronics ");
	text2.setCharacterSize(30);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(60, 258);
	text2.setStyle(sf::Text::Bold);

	sf::Font font3;
	font3.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text3;
	text3.setFont(font3);
	text3.setString(" Makeup & Accessories ");
	text3.setCharacterSize(30);
	text3.setFillColor(sf::Color::White);
	text3.setPosition(30, 328);
	text3.setStyle(sf::Text::Bold);

	sf::Font font4;
	font4.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text4;
	text4.setFont(font4);
	text4.setString("        Clothing ");
	text4.setCharacterSize(30);
	text4.setFillColor(sf::Color::White);
	text4.setPosition(60, 398);
	text4.setStyle(sf::Text::Bold);

	sf::Font font5;
	font5.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text5;
	text5.setFont(font5);
	text5.setString("       Shoes & Bags ");
	text5.setCharacterSize(30);
	text5.setFillColor(sf::Color::White);
	text5.setPosition(58, 468);
	text5.setStyle(sf::Text::Bold);

	sf::Font font8;
	font8.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text8;
	text8.setFont(font8);
	text8.setString(" ** This Name Is Already Taken ** ");
	text8.setCharacterSize(30);
	text8.setFillColor(sf::Color::White);
	text8.setPosition(420, 600);
	text8.setStyle(sf::Text::Bold);

	sf::Font font6;
	font6.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text6;
	text6.setFont(font5);
	text6.setString("         Books ");
	text6.setCharacterSize(30);
	text6.setFillColor(sf::Color::White);
	text6.setPosition(62, 538);
	text6.setStyle(sf::Text::Bold);

	sf::Font font7;
	font7.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text7;
	text7.setFont(font5);
	text7.setString("         Gaming ");
	text7.setCharacterSize(30);
	text7.setFillColor(sf::Color::White);
	text7.setPosition(60, 608);
	text7.setStyle(sf::Text::Bold);

	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String name;
	sf::Text textname(name, fontname, 25);
	textname.setFillColor(sf::Color::Black);
	textname.setPosition(200, 14);

	sf::Font fontcity;
	fontcity.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String city;
	sf::Text textcity(city, fontcity, 25);
	textcity.setFillColor(sf::Color::Black);
	textcity.setPosition(200, 107);

	sf::Font fontcountry;
	fontcountry.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String country;
	sf::Text textcountry(country, fontcountry, 25);
	textcountry.setFillColor(sf::Color::Black);
	textcountry.setPosition(600, 110);

	sf::String category;

	sf::Font fonta;
	fonta.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texta;
	texta.setFont(fonta);
	texta.setString("Shop Name  : ");
	texta.setCharacterSize(30);
	texta.setFillColor(sf::Color::White);
	texta.setPosition(10, 10);
	texta.setStyle(sf::Text::Regular);

	sf::Font fontb;
	fontb.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textb;
	textb.setFont(fontb);
	textb.setString("Shop Adress. ");
	textb.setCharacterSize(30);
	textb.setFillColor(sf::Color::White);
	textb.setPosition(10, 60);
	textb.setStyle(sf::Text::Regular);

	sf::Font fontc;
	fontc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textc;
	textc.setFont(fontc);
	textc.setString("city                 :");
	textc.setCharacterSize(30);
	textc.setFillColor(sf::Color::White);
	textc.setPosition(10, 105);
	textc.setStyle(sf::Text::Regular);

	sf::Font fontd;
	fontd.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textd;
	textd.setFont(fontd);
	textd.setString("Country           :");
	textd.setCharacterSize(30);
	textd.setFillColor(sf::Color::White);
	textd.setPosition(400, 105);
	textd.setStyle(sf::Text::Regular);

	sf::Font font;
	font.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("    Register ");
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::White);
	text.setPosition(430, 500);
	text.setStyle(sf::Text::Bold);

	sf::Font fontk;
	fontk.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textk;
	textk.setFont(fontk);
	textk.setString("  ** Please fill the spaces ** ");
	textk.setCharacterSize(28);
	textk.setFillColor(sf::Color::White);
	textk.setPosition(390, 400);
	textk.setStyle(sf::Text::Bold);
	bool same = false;
	int active;
	bool fill = false;
	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 193 && localposition.x <= 750 && localposition.y >= 16 && localposition.y <= 40) {
					active = 1;
					cout << "name" << endl;

				}
				else if (localposition.x >= 595 && localposition.x <= 758 && localposition.y >= 95 && localposition.y <= 140) {
					active = 2;
					cout << "country" << endl;
				}
				else if (localposition.x >= 193 && localposition.x <= 360 && localposition.y >= 95 && localposition.y <= 140) {
					active = 3;
					cout << "city" << endl;

				}
				else if (localposition.x >= 28 && localposition.x <= 362 && localposition.y >= 189 && localposition.y <= 227) {
					category = ("Phones&Tablets");
					cout << "phones & tablets" << endl;
					choice10.setOutlineColor(sf::Color::Red);
					choice20.setOutlineColor(sf::Color::White);
					choice30.setOutlineColor(sf::Color::White);
					choice40.setOutlineColor(sf::Color::White);
					choice50.setOutlineColor(sf::Color::White);
					choice60.setOutlineColor(sf::Color::White);
					choice70.setOutlineColor(sf::Color::White);
					text1.setFillColor(sf::Color::Red);
					text2.setFillColor(sf::Color::White);
					text3.setFillColor(sf::Color::White);
					text4.setFillColor(sf::Color::White);
					text5.setFillColor(sf::Color::White);
					text6.setFillColor(sf::Color::White);
					text7.setFillColor(sf::Color::White);
				}
				else if (localposition.x >= 28 && localposition.x <= 362 && localposition.y >= 259 && localposition.y <= 295) {
					category = ("Electronics");
					cout << "electronics" << endl;
					choice10.setOutlineColor(sf::Color::White);
					choice20.setOutlineColor(sf::Color::Red);
					choice30.setOutlineColor(sf::Color::White);
					choice40.setOutlineColor(sf::Color::White);
					choice50.setOutlineColor(sf::Color::White);
					choice60.setOutlineColor(sf::Color::White);
					choice70.setOutlineColor(sf::Color::White);
					text1.setFillColor(sf::Color::White);
					text2.setFillColor(sf::Color::Red);
					text3.setFillColor(sf::Color::White);
					text4.setFillColor(sf::Color::White);
					text5.setFillColor(sf::Color::White);
					text6.setFillColor(sf::Color::White);
					text7.setFillColor(sf::Color::White);
				}
				else if (localposition.x >= 28 && localposition.x <= 362 && localposition.y >= 327 && localposition.y <= 370) {
					category = ("Makeup&Accessories");
					cout << "makeup & accessories" << endl;
					choice10.setOutlineColor(sf::Color::White);
					choice20.setOutlineColor(sf::Color::White);
					choice30.setOutlineColor(sf::Color::Red);
					choice40.setOutlineColor(sf::Color::White);
					choice50.setOutlineColor(sf::Color::White);
					choice60.setOutlineColor(sf::Color::White);
					choice70.setOutlineColor(sf::Color::White);
					text1.setFillColor(sf::Color::White);
					text2.setFillColor(sf::Color::White);
					text3.setFillColor(sf::Color::Red);
					text4.setFillColor(sf::Color::White);
					text5.setFillColor(sf::Color::White);
					text6.setFillColor(sf::Color::White);
					text7.setFillColor(sf::Color::White);
				}
				else if (localposition.x >= 28 && localposition.x <= 362 && localposition.y >= 399 && localposition.y <= 439) {
					category = ("Clothing");
					cout << "clothing" << endl;
					choice10.setOutlineColor(sf::Color::White);
					choice20.setOutlineColor(sf::Color::White);
					choice30.setOutlineColor(sf::Color::White);
					choice40.setOutlineColor(sf::Color::Red);
					choice50.setOutlineColor(sf::Color::White);
					choice60.setOutlineColor(sf::Color::White);
					choice70.setOutlineColor(sf::Color::White);
					text1.setFillColor(sf::Color::White);
					text2.setFillColor(sf::Color::White);
					text3.setFillColor(sf::Color::White);
					text4.setFillColor(sf::Color::Red);
					text5.setFillColor(sf::Color::White);
					text6.setFillColor(sf::Color::White);
					text7.setFillColor(sf::Color::White);
				}
				else if (localposition.x >= 28 && localposition.x <= 362 && localposition.y >= 469 && localposition.y <= 505) {
					category = ("Shoes&Bags");
					cout << "shoes & bags" << endl;
					choice10.setOutlineColor(sf::Color::White);
					choice20.setOutlineColor(sf::Color::White);
					choice30.setOutlineColor(sf::Color::White);
					choice40.setOutlineColor(sf::Color::White);
					choice50.setOutlineColor(sf::Color::Red);
					choice60.setOutlineColor(sf::Color::White);
					choice70.setOutlineColor(sf::Color::White);
					text1.setFillColor(sf::Color::White);
					text2.setFillColor(sf::Color::White);
					text3.setFillColor(sf::Color::White);
					text4.setFillColor(sf::Color::White);
					text5.setFillColor(sf::Color::Red);
					text6.setFillColor(sf::Color::White);
					text7.setFillColor(sf::Color::White);
				}
				else if (localposition.x >= 28 && localposition.x <= 362 && localposition.y >= 541 && localposition.y <= 575) {
					category = ("Books");
					cout << "books" << endl;
					choice10.setOutlineColor(sf::Color::White);
					choice20.setOutlineColor(sf::Color::White);
					choice30.setOutlineColor(sf::Color::White);
					choice40.setOutlineColor(sf::Color::White);
					choice50.setOutlineColor(sf::Color::White);
					choice60.setOutlineColor(sf::Color::Red);
					choice70.setOutlineColor(sf::Color::White);
					text1.setFillColor(sf::Color::White);
					text2.setFillColor(sf::Color::White);
					text3.setFillColor(sf::Color::White);
					text4.setFillColor(sf::Color::White);
					text5.setFillColor(sf::Color::White);
					text6.setFillColor(sf::Color::Red);
					text7.setFillColor(sf::Color::White);
				}
				else if (localposition.x >= 28 && localposition.x <= 362 && localposition.y >= 607 && localposition.y <= 649) {
					category = ("Gaming");
					cout << "gaming" << endl;
					choice10.setOutlineColor(sf::Color::White);
					choice20.setOutlineColor(sf::Color::White);
					choice30.setOutlineColor(sf::Color::White);
					choice40.setOutlineColor(sf::Color::White);
					choice50.setOutlineColor(sf::Color::White);
					choice60.setOutlineColor(sf::Color::White);
					choice70.setOutlineColor(sf::Color::Red);
					text1.setFillColor(sf::Color::White);
					text2.setFillColor(sf::Color::White);
					text3.setFillColor(sf::Color::White);
					text4.setFillColor(sf::Color::White);
					text5.setFillColor(sf::Color::White);
					text6.setFillColor(sf::Color::White);
					text7.setFillColor(sf::Color::Red);
				}
				else if (localposition.x >= 443 && localposition.x <= 652 && localposition.y >= 485 && localposition.y <= 569 && name.getSize() > 0 && city.getSize() > 0 && country.getSize() > 0) {
					same = false;
					for (int i = 0; i < maxOwners; i++) {
						if (Owners[i].Shops.ShopName == name) {
							same = true;
						}
					}
					if (same == false) {
						ogRegShop(LogIndex, category, name, country, city);
						homepageOwner();
					}

				}
				else if (localposition.x >= 443 && localposition.x <= 652 && localposition.y >= 485 && localposition.y <= 569 && (name.getSize() > 0 || city.getSize() == 0 || country.getSize() == 0))
				{
					fill = true;
					same = true;
				}
				else

					active = 0;

			}
			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					name += event.text.unicode;
					textname.setString(name);
				}
				else if (active == 1 && event.text.unicode == 8 && name.getSize() > 0)
				{
					name.erase(name.getSize() - 1, name.getSize());
					textname.setString(name);
				}
				if (active == 3 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					city += event.text.unicode;
					textcity.setString(city);
				}
				else if (active == 3 && event.text.unicode == 8 && city.getSize() > 0) {
					city.erase(city.getSize() - 1, city.getSize());
					textcity.setString(city);
				}
				if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					country += event.text.unicode;
					textcountry.setString(country);
				}
				else if (active == 2 && event.text.unicode == 8 && country.getSize() > 0) {
					country.erase(country.getSize() - 1, country.getSize());
					textcountry.setString(country);
				}
			}


			window.clear();
			window.draw(photo);
			window.draw(texta);
			window.draw(textb);
			window.draw(textc);
			window.draw(textd);
			window.draw(text);
			if (fill)
				window.draw(textk);
			if (same)
				window.draw(text8);
			window.draw(choice8);
			window.draw(choice1);
			window.draw(choice10);
			window.draw(choice20);
			window.draw(choice30);
			window.draw(choice40);
			window.draw(choice40);
			window.draw(choice50);
			window.draw(choice60);
			window.draw(choice70);
			window.draw(choice2);
			window.draw(choice3);
			window.draw(textname);
			window.draw(text1);
			window.draw(text2);
			window.draw(text3);
			window.draw(text4);
			window.draw(text5);
			window.draw(text6);

			window.draw(text7);
			window.draw(textcity);
			window.draw(textcountry);

			window.display();

		}
	}

}

int prodchoice() {

	sf::RectangleShape choice1(sf::Vector2f(320.0f, 60.0f));
	choice1.setPosition(sf::Vector2f(250, 50));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineThickness(5);
	choice1.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice2(sf::Vector2f(320.0f, 60.0f));
	choice2.setPosition(sf::Vector2f(250, 175));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineThickness(5);
	choice2.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice3(sf::Vector2f(320.0f, 60.0f));
	choice3.setPosition(sf::Vector2f(250, 300));
	choice3.setFillColor(sf::Color::Transparent);
	choice3.setOutlineThickness(5);
	choice3.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice4(sf::Vector2f(320.0f, 60.0f));
	choice4.setPosition(sf::Vector2f(250, 425));
	choice4.setFillColor(sf::Color::Transparent);
	choice4.setOutlineThickness(5);
	choice4.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice5(sf::Vector2f(320.0f, 60.0f));
	choice5.setPosition(sf::Vector2f(250, 550));
	choice5.setFillColor(sf::Color::Transparent);
	choice5.setOutlineThickness(5);
	choice5.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice6(sf::Vector2f(100.0f, 22.0f));
	choice6.setPosition(sf::Vector2f(685, 20));
	choice6.setFillColor(sf::Color::Transparent);
	choice6.setOutlineColor(sf::Color::Red);
	choice6.setOutlineThickness(3);

	sf::Font fonta;
	fonta.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texta;
	texta.setFont(fonta);
	texta.setString(" ADD PRODUCT ");
	texta.setCharacterSize(30);
	texta.setFillColor(sf::Color::White);
	texta.setPosition(289, 60);
	texta.setStyle(sf::Text::Bold);

	sf::Font fontb;
	fontb.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textb;
	textb.setFont(fontb);
	textb.setString("  REMOVE PRODUCT ");
	textb.setCharacterSize(30);
	textb.setFillColor(sf::Color::White);
	textb.setPosition(272, 185);
	textb.setStyle(sf::Text::Bold);

	sf::Font fontc;
	fontc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textc;
	textc.setFont(fontc);
	textc.setString("EDIT PRODUCT ");
	textc.setCharacterSize(30);
	textc.setFillColor(sf::Color::White);
	textc.setPosition(300, 310);
	textc.setStyle(sf::Text::Bold);

	sf::Font fontd;
	fontd.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textd;
	textd.setFont(fontd);
	textd.setString("   VIEW YOUR PRODUCTS ");
	textd.setCharacterSize(29);
	textd.setFillColor(sf::Color::White);
	textd.setPosition(226, 435);
	textd.setStyle(sf::Text::Bold);

	sf::Font fonte;
	fonte.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texte;
	texte.setFont(fonte);
	texte.setString("   DISCOUNT PRODUCT  ");
	texte.setCharacterSize(30);
	texte.setFillColor(sf::Color::White);
	texte.setPosition(240, 560);
	texte.setStyle(sf::Text::Bold);

	sf::Font font0;
	font0.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text0;
	text0.setFont(font0);
	text0.setString(" Back ");
	text0.setCharacterSize(20);
	text0.setFillColor(sf::Color::Red);
	text0.setPosition(708, 18);
	text0.setStyle(sf::Text::Bold);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << "{" << localposition.x << "-" << localposition.y << "]" << endl;
				if (localposition.x >= 245 && localposition.x <= 574 && localposition.y >= 44 && localposition.y <= 114) {
					cout << "add" << endl;
					addproduct();
				}
				else if (localposition.x >= 245 && localposition.x <= 574 && localposition.y >= 168 && localposition.y <= 238) {
					cout << "remove" << endl;
					remove();
				}
				else if (localposition.x >= 245 && localposition.x <= 574 && localposition.y >= 295 && localposition.y <= 363) {
					cout << "edit" << endl;
					editprod();
				}
				else if (localposition.x >= 245 && localposition.x <= 574 && localposition.y >= 421 && localposition.y <= 487) {
					cout << "view" << endl;
					viewproductsOwner();
				}
				else if (localposition.x >= 245 && localposition.x <= 574 && localposition.y >= 544 && localposition.y <= 611) {
					cout << "discount" << endl;
					discount();

				}
				else if (localposition.x >= 681 && localposition.x <= 786 && localposition.y >= 17 && localposition.y <= 43) {
					return 0;
				}

			}
			window.clear();
			window.draw(photo);
			window.draw(texta);
			window.draw(textb);
			window.draw(textc);
			window.draw(textd);
			window.draw(texte);
			window.draw(text0);
			window.draw(choice1);
			window.draw(choice2);
			window.draw(choice3);
			window.draw(choice4);
			window.draw(choice5);
			window.draw(choice6);
			window.display();
		}
	}


}

int loginshopper() {

	sf::RectangleShape choice40(sf::Vector2f(80.0f, 30.0f));
	choice40.setPosition(sf::Vector2f(812, 748));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::Red);
	choice40.setOutlineThickness(3);

	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" BACK ");
	text10.setCharacterSize(20);
	text10.setFillColor(sf::Color::Red);
	text10.setPosition(820, 750);
	text10.setStyle(sf::Text::Bold);

	sf::RectangleShape choice1(sf::Vector2f(550.0f, 20.0f));
	choice1.setPosition(sf::Vector2f(200, 20));
	choice1.setFillColor(sf::Color::White);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(7);

	sf::RectangleShape choice2(sf::Vector2f(550.0f, 20.0f));
	choice2.setPosition(sf::Vector2f(200, 60));
	choice2.setFillColor(sf::Color::White);
	choice2.setOutlineColor(sf::Color::White);
	choice2.setOutlineThickness(7);

	sf::Font fonta;
	fonta.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texta;
	texta.setFont(fonta);
	texta.setString("ID                   : ");
	texta.setCharacterSize(30);
	texta.setFillColor(sf::Color::White);
	texta.setPosition(10, 10);
	texta.setStyle(sf::Text::Regular);

	sf::Font fontb;
	fontb.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textb;
	textb.setFont(fontb);
	textb.setString("Password    : ");
	textb.setCharacterSize(30);
	textb.setFillColor(sf::Color::White);
	textb.setPosition(10, 50);
	textb.setStyle(sf::Text::Regular);

	sf::Font fontq;
	fontq.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textq;
	textq.setFont(fontq);
	textq.setString("           ** Either Password Or ID Is Incorrect ** ");
	textq.setCharacterSize(40);
	textq.setFillColor(sf::Color::White);
	textq.setPosition(30, 300);
	textq.setStyle(sf::Text::Regular);

	sf::Font fontd;
	fontd.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textn;
	textn.setFont(fontd);
	textn.setString("     login ");
	textn.setCharacterSize(40);
	textn.setFillColor(sf::Color::White);
	textn.setPosition(150, 500);
	textn.setStyle(sf::Text::Bold);

	sf::RectangleShape choice(sf::Vector2f(200.0f, 80.0f));
	choice.setPosition(sf::Vector2f(150, 490));
	choice.setFillColor(sf::Color::Transparent);
	choice.setOutlineThickness(5);
	choice.setOutlineColor(sf::Color::White);

	sf::Font fontid;
	fontid.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String id;
	sf::Text textid(id, fontid, 25);
	textid.setFillColor(sf::Color::Black);
	textid.setPosition(200, 14);

	sf::String passout;


	sf::Font fontpass;
	fontpass.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String pass;
	sf::Text textpass(pass, fontpass, 25);
	textpass.setFillColor(sf::Color::Black);
	textpass.setPosition(200, 55);
	int active, id1;
	bool w = false;
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 193 && localposition.x <= 750 && localposition.y >= 16 && localposition.y <= 40) {
					active = 1;
					cout << "name" << endl;

				}
				else if (localposition.x >= 193 && localposition.x <= 750 && localposition.y >= 55 && localposition.y <= 82) {
					active = 2;
					cout << "password" << endl;

				}
				else if (localposition.x >= 145 && localposition.x <= 354 && localposition.y >= 485 && localposition.y <= 570 && pass.getSize() > 5 && id.getSize() > 0) {

					istringstream(id) >> id1;

					Lshopper(id1, pass, pass.getSize());
					w = true;
				}
				else if (localposition.x >= 808 && localposition.x <= 893 && localposition.y >= 747 && localposition.y <= 778) {
					return 0;
					cout << "back" << endl;

				}
				else
					active = 0;
			}
			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					id += event.text.unicode;
					textid.setString(id);
				}
				else if (active == 1 && event.text.unicode == 8 && id.getSize() > 0)
				{
					id.erase(id.getSize() - 1, id.getSize());
					textid.setString(id);
				}
				if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					pass += event.text.unicode;
					passout += "*";
					textpass.setString(passout);

				}
				else if (active == 2 && event.text.unicode == 8 && pass.getSize() > 0) {
					passout.erase(passout.getSize() - 1, passout.getSize());
					pass.erase(pass.getSize() - 1, pass.getSize());
					textpass.setString(passout);
				}

			}
		}
		window.clear();
		window.draw(photo);
		window.draw(choice1);
		window.draw(choice2);
		window.draw(texta);
		window.draw(textb);
		window.draw(text10);
		window.draw(choice40);
		window.draw(textn);
		window.draw(textpass);
		if (w)
			window.draw(textq);
		window.draw(textid);
		window.draw(choice);
		window.display();

	}


}

void scchoice() {

	sf::RectangleShape choice0(sf::Vector2f(110.0f, 25.0f));
	choice0.setPosition(sf::Vector2f(770, 15));
	choice0.setFillColor(sf::Color::Transparent);
	choice0.setOutlineThickness(3);
	choice0.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice01(sf::Vector2f(110.0f, 25.0f));
	choice01.setPosition(sf::Vector2f(770, 50));
	choice01.setFillColor(sf::Color::Transparent);
	choice01.setOutlineThickness(3);
	choice01.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice02(sf::Vector2f(110.0f, 25.0f));
	choice02.setPosition(sf::Vector2f(770, 85));
	choice02.setFillColor(sf::Color::Transparent);
	choice02.setOutlineThickness(3);
	choice02.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice1(sf::Vector2f(320.0f, 80.0f));
	choice1.setPosition(sf::Vector2f(250, 100));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineThickness(5);
	choice1.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice2(sf::Vector2f(320.0f, 80.0f));
	choice2.setPosition(sf::Vector2f(250, 225));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineThickness(5);
	choice2.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice3(sf::Vector2f(320.0f, 80.0f));
	choice3.setPosition(sf::Vector2f(250, 350));
	choice3.setFillColor(sf::Color::Transparent);
	choice3.setOutlineThickness(5);
	choice3.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice4(sf::Vector2f(320.0f, 80.0f));
	choice4.setPosition(sf::Vector2f(250, 475));
	choice4.setFillColor(sf::Color::Transparent);
	choice4.setOutlineThickness(5);
	choice4.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice5(sf::Vector2f(320.0f, 80.0f));
	choice5.setPosition(sf::Vector2f(250, 600));
	choice5.setFillColor(sf::Color::Transparent);
	choice5.setOutlineThickness(5);
	choice5.setOutlineColor(sf::Color::White);

	sf::Font fontz;
	fontz.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textz;
	textz.setFont(fontz);
	textz.setString(" VIEW CART ");
	textz.setCharacterSize(20);
	textz.setFillColor(sf::Color::White);
	textz.setPosition(770, 15);
	textz.setStyle(sf::Text::Regular);

	sf::Font fontq;
	fontq.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textq;
	textq.setFont(fontq);
	textq.setString("   PROFILE ");
	textq.setCharacterSize(20);
	textq.setFillColor(sf::Color::White);
	textq.setPosition(770, 50);
	textq.setStyle(sf::Text::Regular);

	sf::Font fontp;
	fontp.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textp;
	textp.setFont(fontp);
	textp.setString("   LOG OUT ");
	textp.setCharacterSize(20);
	textp.setFillColor(sf::Color::White);
	textp.setPosition(770, 85);
	textp.setStyle(sf::Text::Regular);

	sf::Font fonta;
	fonta.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texta;
	texta.setFont(fonta);
	texta.setString(" VIEW PRODUCTS ");
	texta.setCharacterSize(30);
	texta.setFillColor(sf::Color::White);
	texta.setPosition(283, 118);
	texta.setStyle(sf::Text::Bold);

	sf::Font fontb;
	fontb.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textb;
	textb.setFont(fontb);
	textb.setString(" SEARCH ");
	textb.setCharacterSize(30);
	textb.setFillColor(sf::Color::White);
	textb.setPosition(333, 243);
	textb.setStyle(sf::Text::Bold);

	sf::Font fontc;
	fontc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textc;
	textc.setFont(fontc);
	textc.setString(" EDIT INFORMATION ");
	textc.setCharacterSize(30);
	textc.setFillColor(sf::Color::White);
	textc.setPosition(270, 368);
	textc.setStyle(sf::Text::Bold);

	sf::Font fontd;
	fontd.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textd;
	textd.setFont(fontd);
	textd.setString(" PURCHASE HISTORY ");
	textd.setCharacterSize(30);
	textd.setFillColor(sf::Color::White);
	textd.setPosition(255, 494);
	textd.setStyle(sf::Text::Bold);

	sf::Font fontx;
	fontx.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textx;
	textx.setFont(fontx);
	textx.setString(" Check Your ID at Your Profile.   ");
	textx.setCharacterSize(25);
	textx.setFillColor(sf::Color::White);
	textx.setPosition(233, 734);
	textx.setStyle(sf::Text::Bold);

	sf::Font fonte;
	fonte.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texte;
	texte.setFont(fonte);
	texte.setString(" DELETE ACCOUNT  ");
	texte.setCharacterSize(30);
	texte.setFillColor(sf::Color::White);
	texte.setPosition(280, 618);
	texte.setStyle(sf::Text::Bold);


	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << "{" << localposition.x << "-" << localposition.y << "]" << endl;
				if (localposition.x >= 245 && localposition.x <= 570 && localposition.y >= 93 && localposition.y <= 177) {
					cout << "view" << endl;
					prodmenu();

				}
				else if (localposition.x >= 245 && localposition.x <= 570 && localposition.y >= 221 && localposition.y <= 302) {
					cout << "srearch" << endl;
					search();
				}
				else if (localposition.x >= 245 && localposition.x <= 570 && localposition.y >= 345 && localposition.y <= 428) {
					cout << "edit" << endl;
					editshoper();

				}
				else if (localposition.x >= 767 && localposition.x <= 883 && localposition.y >= 10 && localposition.y <= 41) {
					cout << "cart" << endl;
					cart();

				}
				else if (localposition.x >= 767 && localposition.x <= 883 && localposition.y >= 45 && localposition.y <= 77) {
					cout << "profile" << endl;
					shopperprofile(LogID);

				}
				else if (localposition.x >= 767 && localposition.x <= 883 && localposition.y >= 81 && localposition.y <= 111) {
					cout << "logout" << endl;
					save();
					welcome();

				}
				else if (localposition.x >= 245 && localposition.x <= 570 && localposition.y >= 470 && localposition.y <= 553) {
					cout << "purchase" << endl;
					purchaseHistory(LogIndex);
				}
				else if (localposition.x >= 245 && localposition.x <= 570 && localposition.y >= 593 && localposition.y <= 680) {
					cout << "delete" << endl;
					deleteshopper();
				}


			}
			window.clear();
			window.draw(photo);
			window.draw(texta);
			window.draw(textb);
			window.draw(textc);
			window.draw(textd);
			window.draw(texte);
			window.draw(textz);
			window.draw(textq);
			window.draw(textx);
			window.draw(textp);
			window.draw(choice0);
			window.draw(choice01);
			window.draw(choice02);
			window.draw(choice1);
			window.draw(choice2);
			window.draw(choice3);
			window.draw(choice4);
			window.draw(choice5);
			window.display();
		}
	}
}

int search() {



	sf::RectangleShape choice1(sf::Vector2f(330.0f, 20.0f));
	choice1.setPosition(sf::Vector2f(300, 25));
	choice1.setFillColor(sf::Color::White);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(7);

	sf::RectangleShape choices(sf::Vector2f(86.0f, 25.0f));
	choices.setPosition(sf::Vector2f(695, 23));
	choices.setFillColor(sf::Color::Transparent);
	choices.setOutlineColor(sf::Color::Red);
	choices.setOutlineThickness(4);

	sf::RectangleShape choiceb(sf::Vector2f(86.0f, 25.0f));
	choiceb.setPosition(sf::Vector2f(695, 700));
	choiceb.setFillColor(sf::Color::Transparent);
	choiceb.setOutlineColor(sf::Color::Red);
	choiceb.setOutlineThickness(4);

	sf::Font fontb;
	fontb.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textb;
	textb.setFont(fontb);
	textb.setString(" Search ");
	textb.setCharacterSize(20);
	textb.setFillColor(sf::Color::Red);
	textb.setPosition(696, 23);
	textb.setStyle(sf::Text::Bold);

	sf::Font fontr;
	fontr.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textr;
	textr.setFont(fontr);
	textr.setString("   back ");
	textr.setCharacterSize(20);
	textr.setFillColor(sf::Color::Red);
	textr.setPosition(696, 700);
	textr.setStyle(sf::Text::Bold);

	sf::Font fonta;
	fonta.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texta;
	texta.setFont(fonta);
	texta.setString(" Enter Product Name   : ");
	texta.setCharacterSize(20);
	texta.setFillColor(sf::Color::White);
	texta.setPosition(30, 20);
	texta.setStyle(sf::Text::Bold);

	sf::Font fonto;
	fonto.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texto;
	texto.setFont(fonto);
	texto.setString(" Out Of Stock  ");
	texto.setCharacterSize(30);
	texto.setFillColor(sf::Color::White);
	texto.setPosition(350, 100);
	texto.setStyle(sf::Text::Bold);

	sf::Font fonts;
	fonts.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String searchh;
	sf::Text texts(searchh, fonts, 25);
	texts.setFillColor(sf::Color::Black);
	texts.setPosition(310, 20);

	int active = 0;
	bool found = false;

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 293 && localposition.x <= 638 && localposition.y >= 16 && localposition.y <= 52) {
					active = 1;
					cout << "search " << endl;

				}
				else if (localposition.x >= 691 && localposition.x <= 783 && localposition.y >= 19 && localposition.y <= 48 && searchh.getSize() > 0) {
					seearch(searchh);
					if (m.a[0] != -1) {
						viewbysearch(searchh);
						cout << "search " << endl;
					}
					else if (m.a[0] == -1)
						found = true;

				}
				else if (localposition.x >= 690 && localposition.x <= 783 && localposition.y >= 696 && localposition.y <= 728) {
					return 0;
					cout << "back" << endl;

				}
				else
				{
					active = 0;
				}
			}
			if (event.type == sf::Event::TextEntered) {
				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					searchh += event.text.unicode;
					texts.setString(searchh);

				}
				else if (active == 1 && event.text.unicode == 8 && searchh.getSize() > 0) {
					searchh.erase(searchh.getSize() - 1, searchh.getSize());
					texts.setString(searchh);
				}

			}


		}
		window.clear();
		window.draw(photo);
		window.draw(texta);
		window.draw(textr);
		window.draw(choice1);
		window.draw(texts);
		window.draw(choices);
		window.draw(choiceb);
		window.draw(textb);
		if (found)
			window.draw(texto);
		window.display();

	}


}

int loginowner() {

	sf::RectangleShape choice40(sf::Vector2f(80.0f, 30.0f));
	choice40.setPosition(sf::Vector2f(812, 748));

	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::Red);
	choice40.setOutlineThickness(3);

	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" BACK ");
	text10.setCharacterSize(20);
	text10.setFillColor(sf::Color::Red);
	text10.setPosition(820, 750);
	text10.setStyle(sf::Text::Bold);

	sf::RectangleShape choice1(sf::Vector2f(550.0f, 20.0f));
	choice1.setPosition(sf::Vector2f(200, 20));
	choice1.setFillColor(sf::Color::White);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(7);

	sf::RectangleShape choice2(sf::Vector2f(550.0f, 20.0f));
	choice2.setPosition(sf::Vector2f(200, 60));
	choice2.setFillColor(sf::Color::White);
	choice2.setOutlineColor(sf::Color::White);
	choice2.setOutlineThickness(7);

	sf::Font fonta;
	fonta.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texta;
	texta.setFont(fonta);
	texta.setString("ID                   : ");
	texta.setCharacterSize(30);
	texta.setFillColor(sf::Color::White);
	texta.setPosition(10, 10);
	texta.setStyle(sf::Text::Regular);

	sf::Font fontb;
	fontb.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textb;
	textb.setFont(fontb);
	textb.setString("Password    : ");
	textb.setCharacterSize(30);
	textb.setFillColor(sf::Color::White);
	textb.setPosition(10, 50);
	textb.setStyle(sf::Text::Regular);

	sf::Font fontd;
	fontd.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textn;
	textn.setFont(fontd);
	textn.setString("     login ");
	textn.setCharacterSize(40);
	textn.setFillColor(sf::Color::White);
	textn.setPosition(150, 500);
	textn.setStyle(sf::Text::Bold);


	sf::Font fontq;
	fontq.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textq;
	textq.setFont(fontq);
	textq.setString("           ** Either Password Or ID Is Incorrect ** ");
	textq.setCharacterSize(40);
	textq.setFillColor(sf::Color::White);
	textq.setPosition(30, 300);
	textq.setStyle(sf::Text::Regular);

	sf::RectangleShape choice(sf::Vector2f(200.0f, 80.0f));
	choice.setPosition(sf::Vector2f(150, 490));
	choice.setFillColor(sf::Color::Transparent);
	choice.setOutlineThickness(5);
	choice.setOutlineColor(sf::Color::White);
	sf::String pass1;
	sf::Font fontid;
	fontid.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String id;
	sf::Text textid(id, fontid, 25);
	textid.setFillColor(sf::Color::Black);
	textid.setPosition(200, 14);

	sf::Font fontpass;
	fontpass.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String pass;
	sf::Text textpass(pass, fontpass, 25);
	textpass.setFillColor(sf::Color::Black);
	textpass.setPosition(200, 55);
	int active, id1;;
	bool w = false;
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);

				if (localposition.x >= 193 && localposition.x <= 750 && localposition.y >= 16 && localposition.y <= 40) {
					active = 1;
					cout << "name" << endl;

				}
				else if (localposition.x >= 193 && localposition.x <= 750 && localposition.y >= 55 && localposition.y <= 82) {
					active = 2;
					cout << "password" << endl;

				}
				else if (localposition.x >= 145 && localposition.x <= 354 && localposition.y >= 485 && localposition.y <= 570 && pass.getSize() > 5 && id.getSize() > 0) {

					istringstream(id) >> id1;

					Lowner(id1, pass1, pass.getSize());
					w = true;
				}
				else if (localposition.x >= 808 && localposition.x <= 893 && localposition.y >= 747 && localposition.y <= 778) {
					return 0;
					cout << "back" << endl;

				}
				else
					active = 0;
			}
			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					id += event.text.unicode;
					textid.setString(id);
				}
				else if (active == 1 && event.text.unicode == 8 && id.getSize() > 0)
				{
					id.erase(id.getSize() - 1, id.getSize());
					textid.setString(id);
				}
				if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					pass1 += event.text.unicode;
					pass += "*";
					textpass.setString(pass);

				}
				else if (active == 2 && event.text.unicode == 8 && pass.getSize() > 0) {
					pass1.erase(pass1.getSize() - 1, pass1.getSize());
					pass.erase(pass.getSize() - 1, pass.getSize());
					textpass.setString(pass);
				}

			}
		}
		window.clear();
		window.draw(photo);
		window.draw(choice1);
		window.draw(choice2);
		window.draw(texta);
		window.draw(textb);
		window.draw(textn);
		window.draw(text10);
		window.draw(choice40);

		if (w)
			window.draw(textq);
		window.draw(textpass);
		window.draw(textid);
		window.draw(choice);
		window.display();

	}



}

int ownerchoice() {

	sf::RectangleShape choice40(sf::Vector2f(80.0f, 30.0f));
	choice40.setPosition(sf::Vector2f(812, 748));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::Red);
	choice40.setOutlineThickness(3);

	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" BACK ");
	text10.setCharacterSize(20);
	text10.setFillColor(sf::Color::Red);
	text10.setPosition(820, 750);
	text10.setStyle(sf::Text::Bold);

	sf::Font font;
	font.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("     login ");
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::White);
	text.setPosition(450, 500);
	text.setStyle(sf::Text::Bold);

	sf::Text textn;
	textn.setFont(font);
	textn.setString("Registration ");
	textn.setCharacterSize(35);
	textn.setFillColor(sf::Color::White);
	textn.setPosition(150, 500);
	textn.setStyle(sf::Text::Bold);

	sf::RectangleShape choice(sf::Vector2f(200.0f, 80.0f));
	choice.setPosition(sf::Vector2f(150, 490));
	choice.setFillColor(sf::Color::Transparent);
	choice.setOutlineThickness(5);
	choice.setOutlineColor(sf::Color::White);
	sf::RectangleShape choicee(sf::Vector2f(200.0f, 80.0f));
	choicee.setPosition(sf::Vector2f(450, 490));
	choicee.setFillColor(sf::Color::Transparent);
	choicee.setOutlineThickness(5);
	choicee.setOutlineColor(sf::Color::White);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i local_position = sf::Mouse::getPosition(window);
				textn.setFillColor(sf::Color::White);
				text.setFillColor(sf::Color::White);
				choicee.setOutlineColor(sf::Color::White);
				choice.setOutlineColor(sf::Color::White);
				cout << '(' << local_position.x << ',' << local_position.y << ')' << endl;
				if (local_position.x >= 146 && local_position.x <= 352 && local_position.y >= 487 && local_position.y <= 570) {

					window.clear();
					regowner();
					break;
				}
				else if (local_position.x >= 446 && local_position.x <= 651 && local_position.y >= 487 && local_position.y <= 570) {

					loginowner();
					break;
				}
				else if (local_position.x >= 808 && local_position.x <= 893 && local_position.y >= 747 && local_position.y <= 778) {
					return 0;
					cout << "back" << endl;

				}
			}
		}
		window.draw(photo);
		window.draw(choice);
		window.draw(choicee);
		window.draw(text);
		window.draw(text10);
		window.draw(choice40);
		window.draw(textn);
		window.display();
	}
}

int shopperchoice() {

	sf::RectangleShape choice40(sf::Vector2f(80.0f, 30.0f));
	choice40.setPosition(sf::Vector2f(812, 748));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::Red);
	choice40.setOutlineThickness(3);

	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" BACK ");
	text10.setCharacterSize(20);
	text10.setFillColor(sf::Color::Red);
	text10.setPosition(820, 750);
	text10.setStyle(sf::Text::Bold);

	sf::Font font;
	font.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("     login ");
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::White);
	text.setPosition(450, 500);
	text.setStyle(sf::Text::Bold);

	sf::Text textn;
	textn.setFont(font);
	textn.setString("Registration ");
	textn.setCharacterSize(35);
	textn.setFillColor(sf::Color::White);
	textn.setPosition(150, 500);
	textn.setStyle(sf::Text::Bold);

	sf::RectangleShape choice(sf::Vector2f(200.0f, 80.0f));
	choice.setPosition(sf::Vector2f(150, 490));
	choice.setFillColor(sf::Color::Transparent);
	choice.setOutlineThickness(5);
	choice.setOutlineColor(sf::Color::White);
	sf::RectangleShape choicee(sf::Vector2f(200.0f, 80.0f));
	choicee.setPosition(sf::Vector2f(450, 490));
	choicee.setFillColor(sf::Color::Transparent);
	choicee.setOutlineThickness(5);
	choicee.setOutlineColor(sf::Color::White);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i local_position = sf::Mouse::getPosition(window);
				textn.setFillColor(sf::Color::White);
				text.setFillColor(sf::Color::White);
				choicee.setOutlineColor(sf::Color::White);
				choice.setOutlineColor(sf::Color::White);
				cout << '(' << local_position.x << ',' << local_position.y << ')' << endl;
				if (local_position.x >= 146 && local_position.x <= 352 && local_position.y >= 487 && local_position.y <= 570) {

					window.clear();
					regshoper();
					break;
				}
				else if (local_position.x >= 446 && local_position.x <= 651 && local_position.y >= 487 && local_position.y <= 570) {

					loginshopper();
					break;
				}
				else if (local_position.x >= 808 && local_position.x <= 893 && local_position.y >= 747 && local_position.y <= 778) {
					return 0;
					cout << "back" << endl;

				}
			}
		}
		window.draw(photo);
		window.draw(choice);
		window.draw(choicee);
		window.draw(text);
		window.draw(text10);
		window.draw(choice40);
		window.draw(textn);
		window.display();
	}

}

int editshoper() {


	sf::RectangleShape choiceback(sf::Vector2f(80.0f, 22.0f));
	choiceback.setPosition(sf::Vector2f(700, 50));
	choiceback.setFillColor(sf::Color::Transparent);
	choiceback.setOutlineColor(sf::Color::Red);
	choiceback.setOutlineThickness(3);

	sf::RectangleShape choice1(sf::Vector2f(330.0f, 40.0f));
	choice1.setPosition(sf::Vector2f(250, 10));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(3);

	sf::RectangleShape choice2(sf::Vector2f(330.0f, 40.0f));
	choice2.setPosition(sf::Vector2f(250, 130));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineColor(sf::Color::White);
	choice2.setOutlineThickness(3);

	sf::RectangleShape choice3(sf::Vector2f(330.0f, 40.0f));
	choice3.setPosition(sf::Vector2f(250, 310));
	choice3.setFillColor(sf::Color::Transparent);
	choice3.setOutlineColor(sf::Color::White);
	choice3.setOutlineThickness(3);

	sf::RectangleShape choice4(sf::Vector2f(330.0f, 40.0f));
	choice4.setPosition(sf::Vector2f(250, 460));
	choice4.setFillColor(sf::Color::Transparent);
	choice4.setOutlineColor(sf::Color::White);
	choice4.setOutlineThickness(3);

	sf::RectangleShape choice5(sf::Vector2f(330.0f, 40.0f));
	choice5.setPosition(sf::Vector2f(250, 610));
	choice5.setFillColor(sf::Color::Transparent);
	choice5.setOutlineColor(sf::Color::White);
	choice5.setOutlineThickness(3);

	sf::RectangleShape choicename(sf::Vector2f(330.0f, 22.0f));
	choicename.setPosition(sf::Vector2f(178, 88));
	choicename.setFillColor(sf::Color::White);
	choicename.setOutlineColor(sf::Color::White);
	choicename.setOutlineThickness(3);

	sf::RectangleShape choicem(sf::Vector2f(170.0f, 50.0f));
	choicem.setPosition(sf::Vector2f(160, 380));
	choicem.setFillColor(sf::Color::Transparent);
	choicem.setOutlineColor(sf::Color::White);
	choicem.setOutlineThickness(3);

	sf::RectangleShape choicef(sf::Vector2f(170.0f, 50.0f));
	choicef.setPosition(sf::Vector2f(515, 380));
	choicef.setFillColor(sf::Color::Transparent);
	choicef.setOutlineColor(sf::Color::White);
	choicef.setOutlineThickness(3);

	sf::RectangleShape choicenpass(sf::Vector2f(330.0f, 22.0f));
	choicenpass.setPosition(sf::Vector2f(250, 220));
	choicenpass.setFillColor(sf::Color::White);
	choicenpass.setOutlineColor(sf::Color::White);
	choicenpass.setOutlineThickness(3);

	sf::RectangleShape choiceopass(sf::Vector2f(330.0f, 22.0f));
	choiceopass.setPosition(sf::Vector2f(250, 260));
	choiceopass.setFillColor(sf::Color::White);
	choiceopass.setOutlineColor(sf::Color::White);
	choiceopass.setOutlineThickness(3);

	sf::RectangleShape choiceocpass(sf::Vector2f(330.0f, 22.0f));
	choiceocpass.setPosition(sf::Vector2f(250, 182));
	choiceocpass.setFillColor(sf::Color::White);
	choiceocpass.setOutlineColor(sf::Color::White);
	choiceocpass.setOutlineThickness(3);

	sf::RectangleShape choiceage(sf::Vector2f(330.0f, 22.0f));
	choiceage.setPosition(sf::Vector2f(170, 535));
	choiceage.setFillColor(sf::Color::White);
	choiceage.setOutlineColor(sf::Color::White);
	choiceage.setOutlineThickness(3);

	sf::RectangleShape choicecity(sf::Vector2f(250.0f, 22.0f));
	choicecity.setPosition(sf::Vector2f(150, 680));
	choicecity.setFillColor(sf::Color::White);
	choicecity.setOutlineColor(sf::Color::White);
	choicecity.setOutlineThickness(3);

	sf::RectangleShape choicecountry(sf::Vector2f(250.0f, 22.0f));
	choicecountry.setPosition(sf::Vector2f(150, 720));
	choicecountry.setFillColor(sf::Color::White);
	choicecountry.setOutlineColor(sf::Color::White);
	choicecountry.setOutlineThickness(3);

	sf::RectangleShape choicesave(sf::Vector2f(80.0f, 22.0f));
	choicesave.setPosition(sf::Vector2f(700, 20));
	choicesave.setFillColor(sf::Color::Transparent);
	choicesave.setOutlineColor(sf::Color::Red);
	choicesave.setOutlineThickness(3);


	sf::String sgender;
	sf::String opass;
	sf::String npass;
	sf::String cpass;

	sf::Font fontage;
	fontage.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String age;
	sf::Text textage(age, fontage, 25);
	textage.setFillColor(sf::Color::Black);
	textage.setPosition(174, 530);

	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String name;
	sf::Text textname(age, fontage, 25);
	textname.setFillColor(sf::Color::Black);
	textname.setPosition(180, 83);

	sf::Font fontpasso;
	fontpasso.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String passo;
	sf::Text textpasso(age, fontage, 30);
	textpasso.setFillColor(sf::Color::Black);
	textpasso.setPosition(250, 215);

	sf::Font fontpasson;
	fontpasson.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String passon;
	sf::Text textpasson(age, fontage, 30);
	textpasson.setFillColor(sf::Color::Black);
	textpasson.setPosition(250, 255);

	sf::Font fontpassonc;
	fontpassonc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String passonc;
	sf::Text textpassonc(age, fontage, 30);
	textpassonc.setFillColor(sf::Color::Black);
	textpassonc.setPosition(250, 177);

	sf::Font fontcity;
	fontcity.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String city;
	sf::Text textcity(age, fontage, 25);
	textcity.setFillColor(sf::Color::Black);
	textcity.setPosition(155, 715);

	sf::Font fontcountry;
	fontcountry.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String country;
	sf::Text textcountry(age, fontage, 25);
	textcountry.setFillColor(sf::Color::Black);
	textcountry.setPosition(155, 675);

	sf::Font font0;
	font0.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text0;
	text0.setFont(font0);
	text0.setString(" Save ");
	text0.setCharacterSize(20);
	text0.setFillColor(sf::Color::Red);
	text0.setPosition(708, 18);
	text0.setStyle(sf::Text::Bold);

	sf::Font font01;
	font01.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text01;
	text01.setFont(font01);
	text01.setString(" Back");
	text01.setCharacterSize(22);
	text01.setFillColor(sf::Color::Red);
	text01.setPosition(707, 46);
	text01.setStyle(sf::Text::Bold);

	sf::Font font1;
	font1.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text1;
	text1.setFont(font1);
	text1.setString(" Edit Name ");
	text1.setCharacterSize(30);
	text1.setFillColor(sf::Color::White);
	text1.setPosition(325, 10);
	text1.setStyle(sf::Text::Bold);

	sf::Font font2;
	font2.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text2;
	text2.setFont(font2);
	text2.setString("Edit Password ");
	text2.setCharacterSize(30);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(305, 130);
	text2.setStyle(sf::Text::Bold);

	sf::Font font3;
	font3.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text3;
	text3.setFont(font3);
	text3.setString("Edit Gender ");
	text3.setCharacterSize(30);
	text3.setFillColor(sf::Color::White);
	text3.setPosition(325, 310);
	text3.setStyle(sf::Text::Bold);

	sf::Font font4;
	font4.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text4;
	text4.setFont(font4);
	text4.setString("Edit  Age ");
	text4.setCharacterSize(30);
	text4.setFillColor(sf::Color::White);
	text4.setPosition(330, 460);
	text4.setStyle(sf::Text::Bold);

	sf::Font font5;
	font5.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text5;
	text5.setFont(font5);
	text5.setString("  Edit Address ");
	text5.setCharacterSize(30);
	text5.setFillColor(sf::Color::White);
	text5.setPosition(320, 610);
	text5.setStyle(sf::Text::Bold);

	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString("New Name: ");
	text10.setCharacterSize(30);
	text10.setFillColor(sf::Color::White);
	text10.setPosition(10, 80);
	text10.setStyle(sf::Text::Bold);

	sf::Font font30;
	font30.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text30;
	text30.setFont(font30);
	text30.setString(" Old Password   :");
	text30.setCharacterSize(30);
	text30.setFillColor(sf::Color::White);
	text30.setPosition(10, 172);
	text30.setStyle(sf::Text::Bold);

	sf::Font font31;
	font31.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text31;
	text31.setFont(font31);
	text31.setString(" New Password :");
	text31.setCharacterSize(30);
	text31.setFillColor(sf::Color::White);
	text31.setPosition(10, 210);
	text31.setStyle(sf::Text::Bold);

	sf::Font font32;
	font32.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text32;
	text32.setFont(font31);
	text32.setString("C.New Password:");
	text32.setCharacterSize(30);
	text32.setFillColor(sf::Color::White);
	text32.setPosition(10, 250);
	text32.setStyle(sf::Text::Bold);

	sf::Font font40;
	font40.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text40;
	text40.setFont(font40);
	text40.setString("    Male ");
	text40.setCharacterSize(40);
	text40.setFillColor(sf::Color::White);
	text40.setPosition(160, 380);
	text40.setStyle(sf::Text::Regular);

	sf::Font font41;
	font41.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text41;
	text41.setFont(font41);
	text41.setString(" Female ");
	text41.setCharacterSize(40);
	text41.setFillColor(sf::Color::White);
	text41.setPosition(530, 380);
	text41.setStyle(sf::Text::Regular);

	sf::Font font50;
	font50.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text50;
	text50.setFont(font50);
	text50.setString(" New Age : ");
	text50.setCharacterSize(30);
	text50.setFillColor(sf::Color::White);
	text50.setPosition(10, 525);
	text50.setStyle(sf::Text::Bold);

	sf::Font font70;
	font70.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text70;
	text70.setFont(font50);
	text70.setString(" City       : ");
	text70.setCharacterSize(30);
	text70.setFillColor(sf::Color::White);
	text70.setPosition(10, 710);
	text70.setStyle(sf::Text::Bold);

	sf::Font font60;
	font60.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text60;
	text60.setFont(font50);
	text60.setString(" Country : ");
	text60.setCharacterSize(30);
	text60.setFillColor(sf::Color::White);
	text60.setPosition(10, 670);
	text60.setStyle(sf::Text::Bold);

	bool bname = false;
	bool bpass = false;
	bool bgender = false;
	bool bage = false;
	bool badress = false;
	int active = 0, intage = 0;
	bool fname = false, fgender = false, fage = false, fcountry = false, fcity = false, fpass = false;

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 247 && localposition.x <= 582 && localposition.y >= 8 && localposition.y <= 47) {
					cout << "edit name " << endl;
					bname = true;
				}
				else if (localposition.x >= 175 && localposition.x <= 509 && localposition.y >= 86 && localposition.y <= 110 && bname) {
					cout << "new name" << endl;
					active = 1;
					fname = true;
					cout << active;

				}
				else if (localposition.x >= 697 && localposition.x <= 781 && localposition.y >= 16 && localposition.y <= 43 && (name.getSize() > 0 || age.getSize() > 0 || (passo.getSize() > 5 && passon.getSize() > 5 && npass == cpass && passonc.getSize() > 0 && opass == Owners[LogIndex].Password) || country.getSize() > 0 || city.getSize() > 0)) {
					istringstream(age) >> intage;
					Eshopper(LogIndex, fname, fgender, fpass, fage, fcountry, fcity, name, npass, passo.getSize(), sgender, intage, city, country);
					scchoice();
				}
				else if (localposition.x >= 247 && localposition.x <= 582 && localposition.y >= 127 && localposition.y <= 169) {
					cout << "edit password" << endl;
					bpass = true;
				}
				else if (localposition.x >= 245 && localposition.x <= 581 && localposition.y >= 216 && localposition.y <= 239 && bpass) {
					cout << "new" << endl;
					active = 2;
					cout << active;

				}
				else if (localposition.x >= 245 && localposition.x <= 581 && localposition.y >= 178 && localposition.y <= 203 && bpass) {
					cout << "old" << endl;
					active = 7;
					cout << active;

				}
				else if (localposition.x >= 245 && localposition.x <= 581 && localposition.y >= 256 && localposition.y <= 281 && bpass) {
					cout << "confrmation" << endl;
					active = 3;
					cout << active;
					fpass = true;
				}
				else if (localposition.x >= 247 && localposition.x <= 582 && localposition.y >= 309 && localposition.y <= 351) {

					cout << "edit gender" << endl;

					bgender = true;
				}
				else if (localposition.x >= 155 && localposition.x <= 330 && localposition.y >= 379 && localposition.y <= 430 && bgender) {
					cout << "male" << endl;
					choicef.setOutlineColor(sf::Color::White);
					text41.setFillColor(sf::Color::White);
					choicem.setOutlineColor(sf::Color::Red);
					text40.setFillColor(sf::Color::Red);
					sgender = ("Male");
					fgender = true;
				}
				else if (localposition.x >= 510 && localposition.x <= 686 && localposition.y >= 379 && localposition.y <= 430 && bgender) {
					cout << "female" << endl;
					choicef.setOutlineColor(sf::Color::Red);
					text41.setFillColor(sf::Color::Red);
					choicem.setOutlineColor(sf::Color::White);
					text40.setFillColor(sf::Color::White);
					sgender = ("Female");
					fgender = true;

				}
				else if (localposition.x >= 247 && localposition.x <= 582 && localposition.y >= 458 && localposition.y <= 500) {
					cout << "edit age" << endl;
					bage = true;

				}
				else if (localposition.x >= 696 && localposition.x <= 781 && localposition.y >= 47 && localposition.y <= 72) {
					cout << "back" << endl;
					return 0;

				}
				else if (localposition.x >= 167 && localposition.x <= 500 && localposition.y >= 530 && localposition.y <= 558 && bage) {
					cout << "age" << endl;
					active = 4;
					fage = true;
					cout << active;

				}
				else if (localposition.x >= 247 && localposition.x <= 582 && localposition.y >= 606 && localposition.y <= 651) {
					cout << "edit address" << endl;
					badress = true;
				}

				else if (localposition.x >= 147 && localposition.x <= 403 && localposition.y >= 714 && localposition.y <= 743 && badress) {
					cout << "city" << endl;
					active = 5;
					fcity = true;
					cout << active;
				}
				else if (localposition.x >= 147 && localposition.x <= 403 && localposition.y >= 677 && localposition.y <= 703 && badress) {
					cout << "country" << endl;
					active = 6;
					fcountry = true;
					cout << active;

				}
				else
				{
					active = 0;
					cout << active;
				}
			}
			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					name += event.text.unicode;
					textname.setString(name);
				}
				else if (active == 1 && event.text.unicode == 8 && name.getSize() > 0)
				{
					name.erase(name.getSize() - 1, name.getSize());
					textname.setString(name);
				}
				if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					npass += event.text.unicode;
					passo += "*";
					textpasso.setString(passo);

				}
				else if (active == 2 && event.text.unicode == 8 && passo.getSize() > 0) {
					npass.erase(npass.getSize() - 1, npass.getSize());
					passo.erase(passo.getSize() - 1, passo.getSize());
					textpasso.setString(passo);
				}
				if (active == 3 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					cpass += event.text.unicode;
					passon += "*";
					textpasson.setString(passon);
				}
				else if (active == 3 && event.text.unicode == 8 && passon.getSize() > 0) {
					passon.erase(passon.getSize() - 1, passon.getSize());
					cpass.erase(cpass.getSize() - 1, cpass.getSize());
					textpasson.setString(passon);
				}
				if (active == 4 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {

					age += event.text.unicode;
					textage.setString(age);
				}
				else if (active == 4 && event.text.unicode == 8 && age.getSize() > 0) {
					age.erase(age.getSize() - 1, age.getSize());
					textage.setString(age);
				}
				if (active == 5 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {

					city += event.text.unicode;
					textcity.setString(city);
				}
				else if (active == 5 && event.text.unicode == 8 && city.getSize() > 0) {
					city.erase(city.getSize() - 1, city.getSize());
					textcity.setString(city);
				}

				if (active == 6 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {

					country += event.text.unicode;
					textcountry.setString(country);
				}
				else if (active == 6 && event.text.unicode == 8 && country.getSize() > 0) {
					country.erase(country.getSize() - 1, country.getSize());
					textcountry.setString(country);
				}
				if (active == 7 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					opass += event.text.unicode;
					passonc += "*";
					textpassonc.setString(passonc);
				}
				else if (active == 7 && event.text.unicode == 8 && passonc.getSize() > 0) {
					passonc.erase(passonc.getSize() - 1, passonc.getSize());
					opass.erase(opass.getSize() - 1, opass.getSize());
					textpassonc.setString(passonc);
				}


			}
		}

		window.clear();
		window.draw(photo);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(choice1);
		window.draw(choice2);
		window.draw(choice3);
		window.draw(choice4);
		window.draw(choice5);
		window.draw(text0);
		window.draw(text01);
		window.draw(choicesave);
		window.draw(choiceback);

		if (bgender) {
			window.draw(choicef);
			window.draw(text40);
			window.draw(text41);
			window.draw(choicem);
		}
		if (bname) {

			window.draw(choicename);
			window.draw(text10);
			window.draw(textname);
		}
		if (bpass) {

			window.draw(text30);
			window.draw(text31);
			window.draw(text32);
			window.draw(choicenpass);
			window.draw(choiceopass);
			window.draw(choiceocpass);
			window.draw(textpassonc);
			window.draw(textpasso);
			window.draw(textpasson);
		}
		if (bage) {
			window.draw(text50);
			window.draw(choiceage);
			window.draw(textage);
		}
		if (badress) {

			window.draw(text60);
			window.draw(text70);
			window.draw(choicecountry);
			window.draw(choicecity);
			window.draw(textcountry);
			window.draw(textcity);

		}
		window.display();
	}


}

int editowner() {


	sf::RectangleShape choice1(sf::Vector2f(330.0f, 40.0f));
	choice1.setPosition(sf::Vector2f(250, 10));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(3);

	sf::RectangleShape choice2(sf::Vector2f(330.0f, 40.0f));
	choice2.setPosition(sf::Vector2f(250, 130));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineColor(sf::Color::White);
	choice2.setOutlineThickness(3);

	sf::RectangleShape choice3(sf::Vector2f(330.0f, 40.0f));
	choice3.setPosition(sf::Vector2f(250, 310));
	choice3.setFillColor(sf::Color::Transparent);
	choice3.setOutlineColor(sf::Color::White);
	choice3.setOutlineThickness(3);

	sf::RectangleShape choice4(sf::Vector2f(330.0f, 40.0f));
	choice4.setPosition(sf::Vector2f(250, 460));
	choice4.setFillColor(sf::Color::Transparent);
	choice4.setOutlineColor(sf::Color::White);
	choice4.setOutlineThickness(3);

	sf::RectangleShape choice5(sf::Vector2f(330.0f, 40.0f));
	choice5.setPosition(sf::Vector2f(250, 610));
	choice5.setFillColor(sf::Color::Transparent);
	choice5.setOutlineColor(sf::Color::White);
	choice5.setOutlineThickness(3);

	sf::RectangleShape choicename(sf::Vector2f(330.0f, 22.0f));
	choicename.setPosition(sf::Vector2f(178, 88));
	choicename.setFillColor(sf::Color::White);
	choicename.setOutlineColor(sf::Color::White);
	choicename.setOutlineThickness(3);

	sf::RectangleShape choicem(sf::Vector2f(170.0f, 50.0f));
	choicem.setPosition(sf::Vector2f(160, 380));
	choicem.setFillColor(sf::Color::Transparent);
	choicem.setOutlineColor(sf::Color::White);
	choicem.setOutlineThickness(3);

	sf::RectangleShape choicef(sf::Vector2f(170.0f, 50.0f));
	choicef.setPosition(sf::Vector2f(515, 380));
	choicef.setFillColor(sf::Color::Transparent);
	choicef.setOutlineColor(sf::Color::White);
	choicef.setOutlineThickness(3);

	sf::RectangleShape choicenpass(sf::Vector2f(330.0f, 22.0f));
	choicenpass.setPosition(sf::Vector2f(250, 220));
	choicenpass.setFillColor(sf::Color::White);
	choicenpass.setOutlineColor(sf::Color::White);
	choicenpass.setOutlineThickness(3);

	sf::RectangleShape choiceopass(sf::Vector2f(330.0f, 22.0f));
	choiceopass.setPosition(sf::Vector2f(250, 260));
	choiceopass.setFillColor(sf::Color::White);
	choiceopass.setOutlineColor(sf::Color::White);
	choiceopass.setOutlineThickness(3);

	sf::RectangleShape choiceocpass(sf::Vector2f(330.0f, 22.0f));
	choiceocpass.setPosition(sf::Vector2f(250, 182));
	choiceocpass.setFillColor(sf::Color::White);
	choiceocpass.setOutlineColor(sf::Color::White);
	choiceocpass.setOutlineThickness(3);

	sf::RectangleShape choiceage(sf::Vector2f(330.0f, 22.0f));
	choiceage.setPosition(sf::Vector2f(170, 535));
	choiceage.setFillColor(sf::Color::White);
	choiceage.setOutlineColor(sf::Color::White);
	choiceage.setOutlineThickness(3);

	sf::RectangleShape choicecity(sf::Vector2f(250.0f, 22.0f));
	choicecity.setPosition(sf::Vector2f(150, 720));
	choicecity.setFillColor(sf::Color::White);
	choicecity.setOutlineColor(sf::Color::White);
	choicecity.setOutlineThickness(3);

	sf::RectangleShape choicecountry(sf::Vector2f(250.0f, 22.0f));
	choicecountry.setPosition(sf::Vector2f(150, 680));
	choicecountry.setFillColor(sf::Color::White);
	choicecountry.setOutlineColor(sf::Color::White);
	choicecountry.setOutlineThickness(3);

	sf::RectangleShape choicesave(sf::Vector2f(100.0f, 22.0f));
	choicesave.setPosition(sf::Vector2f(685, 20));
	choicesave.setFillColor(sf::Color::Transparent);
	choicesave.setOutlineColor(sf::Color::Red);
	choicesave.setOutlineThickness(3);

	sf::RectangleShape choiceshop(sf::Vector2f(100.0f, 22.0f));
	choiceshop.setPosition(sf::Vector2f(685, 50));
	choiceshop.setFillColor(sf::Color::Transparent);
	choiceshop.setOutlineColor(sf::Color::Red);
	choiceshop.setOutlineThickness(3);

	sf::String opass;
	sf::String npass;
	sf::String cpass;
	sf::String sgender;


	sf::Font fontage;
	fontage.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String age;
	sf::Text textage(age, fontage, 25);
	textage.setFillColor(sf::Color::Black);
	textage.setPosition(174, 530);

	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String name;
	sf::Text textname(age, fontage, 25);
	textname.setFillColor(sf::Color::Black);
	textname.setPosition(180, 83);

	sf::Font fontpasso;
	fontpasso.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String passo;
	sf::Text textpasso(age, fontage, 30);
	textpasso.setFillColor(sf::Color::Black);
	textpasso.setPosition(250, 215);

	sf::Font fontpasson;
	fontpasson.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String passon;
	sf::Text textpasson(age, fontage, 30);
	textpasson.setFillColor(sf::Color::Black);
	textpasson.setPosition(250, 255);

	sf::Font fontpassonc;
	fontpassonc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String passonc;
	sf::Text textpassonc(age, fontage, 30);
	textpassonc.setFillColor(sf::Color::Black);
	textpassonc.setPosition(250, 177);

	sf::Font fontcity;
	fontcity.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String city;
	sf::Text textcity(age, fontage, 25);
	textcity.setFillColor(sf::Color::Black);
	textcity.setPosition(155, 720);

	sf::Font fontcountry;
	fontcountry.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String country;
	sf::Text textcountry(age, fontage, 25);
	textcountry.setFillColor(sf::Color::Black);
	textcountry.setPosition(155, 679);

	sf::Font font0;
	font0.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text0;
	text0.setFont(font0);
	text0.setString(" Back ");
	text0.setCharacterSize(20);
	text0.setFillColor(sf::Color::Red);
	text0.setPosition(708, 18);
	text0.setStyle(sf::Text::Bold);

	sf::Font font01;
	font01.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text01;
	text01.setFont(font01);
	text01.setString("Shop Data");
	text01.setCharacterSize(19);
	text01.setFillColor(sf::Color::Red);
	text01.setPosition(690, 48);
	text01.setStyle(sf::Text::Bold);

	sf::Font font1;
	font1.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text1;
	text1.setFont(font1);
	text1.setString(" Edit Name ");
	text1.setCharacterSize(30);
	text1.setFillColor(sf::Color::White);
	text1.setPosition(325, 10);
	text1.setStyle(sf::Text::Bold);

	sf::Font font2;
	font2.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text2;
	text2.setFont(font2);
	text2.setString("Edit Password ");
	text2.setCharacterSize(30);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(305, 130);
	text2.setStyle(sf::Text::Bold);

	sf::Font font3;
	font3.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text3;
	text3.setFont(font3);
	text3.setString("Edit Gender ");
	text3.setCharacterSize(30);
	text3.setFillColor(sf::Color::White);
	text3.setPosition(325, 310);
	text3.setStyle(sf::Text::Bold);

	sf::Font font4;
	font4.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text4;
	text4.setFont(font4);
	text4.setString("Edit  Age ");
	text4.setCharacterSize(30);
	text4.setFillColor(sf::Color::White);
	text4.setPosition(330, 460);
	text4.setStyle(sf::Text::Bold);

	sf::Font font5;
	font5.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text5;
	text5.setFont(font5);
	text5.setString("  Edit Address ");
	text5.setCharacterSize(30);
	text5.setFillColor(sf::Color::White);
	text5.setPosition(320, 610);
	text5.setStyle(sf::Text::Bold);

	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString("New Name: ");
	text10.setCharacterSize(30);
	text10.setFillColor(sf::Color::White);
	text10.setPosition(10, 80);
	text10.setStyle(sf::Text::Bold);

	sf::Font font30;
	font30.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text30;
	text30.setFont(font30);
	text30.setString(" Old Password   :");
	text30.setCharacterSize(30);
	text30.setFillColor(sf::Color::White);
	text30.setPosition(10, 172);
	text30.setStyle(sf::Text::Bold);

	sf::Font font31;
	font31.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text31;
	text31.setFont(font31);
	text31.setString(" New Password :");
	text31.setCharacterSize(30);
	text31.setFillColor(sf::Color::White);
	text31.setPosition(10, 210);
	text31.setStyle(sf::Text::Bold);

	sf::Font font32;
	font32.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text32;
	text32.setFont(font31);
	text32.setString("C.New Password:");
	text32.setCharacterSize(30);
	text32.setFillColor(sf::Color::White);
	text32.setPosition(10, 250);
	text32.setStyle(sf::Text::Bold);

	sf::Font font40;
	font40.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text40;
	text40.setFont(font40);
	text40.setString("    Male ");
	text40.setCharacterSize(40);
	text40.setFillColor(sf::Color::White);
	text40.setPosition(160, 380);
	text40.setStyle(sf::Text::Regular);

	sf::Font font41;
	font41.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text41;
	text41.setFont(font41);
	text41.setString(" Female ");
	text41.setCharacterSize(40);
	text41.setFillColor(sf::Color::White);
	text41.setPosition(530, 380);
	text41.setStyle(sf::Text::Regular);

	sf::Font font50;
	font50.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text50;
	text50.setFont(font50);
	text50.setString(" New Age : ");
	text50.setCharacterSize(30);
	text50.setFillColor(sf::Color::White);
	text50.setPosition(10, 525);
	text50.setStyle(sf::Text::Bold);

	sf::Font font70;
	font70.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text70;
	text70.setFont(font50);
	text70.setString(" City       : ");
	text70.setCharacterSize(30);
	text70.setFillColor(sf::Color::White);
	text70.setPosition(10, 710);
	text70.setStyle(sf::Text::Bold);

	sf::Font font60;
	font60.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text60;
	text60.setFont(font50);
	text60.setString(" Country : ");
	text60.setCharacterSize(30);
	text60.setFillColor(sf::Color::White);
	text60.setPosition(10, 670);
	text60.setStyle(sf::Text::Bold);

	bool bname = false;
	bool bpass = false;
	bool bgender = false;
	bool bage = false;
	bool badress = false;
	bool fname = false, fgender = false, fpass = false, fage = false, fcountry = false, fcity = false;
	int active = 0;
	int  intage = 0;

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 247 && localposition.x <= 582 && localposition.y >= 8 && localposition.y <= 47) {
					cout << "edit name " << endl;
					bname = true;
				}
				else if (localposition.x >= 175 && localposition.x <= 509 && localposition.y >= 86 && localposition.y <= 110 && bname) {
					cout << "new name" << endl;
					active = 1;
					cout << active;
					fname = true;

				}
				else if (localposition.x >= 681 && localposition.x <= 786 && localposition.y >= 48 && localposition.y <= 73 && (name.getSize() > 0 || age.getSize() > 0 || (passo.getSize() > 5 && passon.getSize() > 5 && npass == cpass && passonc.getSize() > 0 && opass == Owners[LogIndex].Password) || country.getSize() > 0 || city.getSize() > 0)) {
					cout << "Shop Data";
					istringstream(age) >> intage;
					Eowner(LogIndex, fname, fgender, fpass, fage, fcountry, fcity, name, npass, passo.getSize(), sgender, intage, city, country);
					editshop();
				}
				else if (localposition.x >= 681 && localposition.x <= 786 && localposition.y >= 17 && localposition.y <= 43) {
					cout << "Back";
					return 0;
				}
				else if (localposition.x >= 247 && localposition.x <= 582 && localposition.y >= 127 && localposition.y <= 169) {
					cout << "edit password" << endl;
					bpass = true;
				}
				else if (localposition.x >= 245 && localposition.x <= 581 && localposition.y >= 216 && localposition.y <= 239 && bpass) {
					cout << "new" << endl;
					active = 2;
					cout << active;

				}
				else if (localposition.x >= 245 && localposition.x <= 581 && localposition.y >= 178 && localposition.y <= 203 && bpass) {
					cout << "old" << endl;
					active = 7;
					cout << active;

				}
				else if (localposition.x >= 245 && localposition.x <= 581 && localposition.y >= 256 && localposition.y <= 281 && bpass) {
					cout << "confrmation" << endl;
					active = 3;
					cout << active;
					fpass = true;

				}
				else if (localposition.x >= 247 && localposition.x <= 582 && localposition.y >= 309 && localposition.y <= 351) {
					cout << "edit gender" << endl;

					bgender = true;
				}
				else if (localposition.x >= 155 && localposition.x <= 330 && localposition.y >= 379 && localposition.y <= 430 && bgender) {
					cout << "male" << endl;
					choicem.setOutlineColor(sf::Color::Red);
					text40.setFillColor(sf::Color::Red);
					choicef.setOutlineColor(sf::Color::White);
					text41.setFillColor(sf::Color::White);
					sgender = ("Male");
					fgender = true;
				}
				else if (localposition.x >= 510 && localposition.x <= 686 && localposition.y >= 379 && localposition.y <= 430 && bgender) {
					cout << "female" << endl;
					choicef.setOutlineColor(sf::Color::Red);
					text41.setFillColor(sf::Color::Red);
					choicem.setOutlineColor(sf::Color::White);
					text40.setFillColor(sf::Color::White);
					sgender = ("Female");
					fgender = true;
				}
				else if (localposition.x >= 247 && localposition.x <= 582 && localposition.y >= 458 && localposition.y <= 500) {
					cout << "edit age" << endl;
					bage = true;

				}
				else if (localposition.x >= 167 && localposition.x <= 500 && localposition.y >= 530 && localposition.y <= 558 && bage) {
					cout << "age" << endl;
					active = 4;
					cout << active;
					fage = true;
				}
				else if (localposition.x >= 247 && localposition.x <= 582 && localposition.y >= 606 && localposition.y <= 651) {
					cout << "edit address" << endl;
					badress = true;

				}
				else if (localposition.x >= 147 && localposition.x <= 403 && localposition.y >= 677 && localposition.y <= 703 && badress) {
					cout << "country" << endl;
					active = 5;
					cout << active;
					fcountry = true;
				}
				else if (localposition.x >= 147 && localposition.x <= 403 && localposition.y >= 714 && localposition.y <= 743 && badress) {
					cout << "city" << endl;
					active = 6;
					cout << active;
					fcity = true;
				}
				else
				{
					active = 0;
					cout << active;
				}
			}
			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					name += event.text.unicode;
					textname.setString(name);
				}
				else if (active == 1 && event.text.unicode == 8 && name.getSize() > 0)
				{
					name.erase(name.getSize() - 1, name.getSize());
					textname.setString(name);
				}
				if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					npass += event.text.unicode;
					passo += "*";
					textpasso.setString(passo);

				}
				else if (active == 2 && event.text.unicode == 8 && passo.getSize() > 0) {
					npass.erase(npass.getSize() - 1, npass.getSize());
					passo.erase(passo.getSize() - 1, passo.getSize());
					textpasso.setString(passo);
				}
				if (active == 3 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					cpass += event.text.unicode;
					passon += "*";
					textpasson.setString(passon);
				}
				else if (active == 3 && event.text.unicode == 8 && passon.getSize() > 0) {
					passon.erase(passon.getSize() - 1, passon.getSize());
					cpass.erase(cpass.getSize() - 1, cpass.getSize());
					textpasson.setString(passon);
				}
				if (active == 4 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {

					age += event.text.unicode;
					textage.setString(age);
				}
				else if (active == 4 && event.text.unicode == 8 && age.getSize() > 0) {
					age.erase(age.getSize() - 1, age.getSize());
					textage.setString(age);
				}
				if (active == 5 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {

					country += event.text.unicode;
					textcountry.setString(country);
				}
				else if (active == 5 && event.text.unicode == 8 && country.getSize() > 0) {
					country.erase(country.getSize() - 1, country.getSize());
					textcountry.setString(country);
				}

				if (active == 6 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {

					city += event.text.unicode;
					textcity.setString(city);
				}
				else if (active == 6 && event.text.unicode == 8 && city.getSize() > 0) {
					city.erase(city.getSize() - 1, city.getSize());
					textcity.setString(city);
				}
				if (active == 7 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					opass += event.text.unicode;
					passonc += "*";
					textpassonc.setString(passonc);
				}
				else if (active == 7 && event.text.unicode == 8 && passonc.getSize() > 0) {
					passonc.erase(passonc.getSize() - 1, passonc.getSize());
					opass.erase(opass.getSize() - 1, opass.getSize());
					textpassonc.setString(passonc);
				}


			}
		}

		window.clear();
		window.draw(photo);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(choice1);
		window.draw(choice2);
		window.draw(choice3);
		window.draw(choice4);
		window.draw(choice5);
		window.draw(text0);
		window.draw(choicesave);
		window.draw(text01);
		window.draw(choiceshop);
		if (bgender) {
			window.draw(choicef);
			window.draw(text40);
			window.draw(text41);
			window.draw(choicem);
		}
		if (bname) {

			window.draw(choicename);
			window.draw(text10);
			window.draw(textname);
		}
		if (bpass) {

			window.draw(text30);
			window.draw(text31);
			window.draw(text32);
			window.draw(choicenpass);
			window.draw(choiceopass);
			window.draw(choiceocpass);
			window.draw(textpassonc);
			window.draw(textpasso);
			window.draw(textpasson);
		}
		if (bage) {
			window.draw(text50);
			window.draw(choiceage);
			window.draw(textage);
		}
		if (badress) {

			window.draw(text60);
			window.draw(text70);
			window.draw(choicecountry);
			window.draw(choicecity);
			window.draw(textcountry);
			window.draw(textcity);

		}
		window.display();
	}


}

int editshop() {

	sf::RectangleShape choice1(sf::Vector2f(330.0f, 40.0f));
	choice1.setPosition(sf::Vector2f(250, 10));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(3);

	sf::RectangleShape choice2(sf::Vector2f(330.0f, 40.0f));
	choice2.setPosition(sf::Vector2f(250, 130));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineColor(sf::Color::White);
	choice2.setOutlineThickness(3);

	sf::RectangleShape choicesave(sf::Vector2f(80.0f, 22.0f));
	choicesave.setPosition(sf::Vector2f(700, 20));
	choicesave.setFillColor(sf::Color::Transparent);
	choicesave.setOutlineColor(sf::Color::Red);
	choicesave.setOutlineThickness(3);

	sf::RectangleShape choiceback(sf::Vector2f(80.0f, 22.0f));
	choiceback.setPosition(sf::Vector2f(700, 50));
	choiceback.setFillColor(sf::Color::Transparent);
	choiceback.setOutlineColor(sf::Color::Red);
	choiceback.setOutlineThickness(3);

	sf::RectangleShape choicename(sf::Vector2f(330.0f, 22.0f));
	choicename.setPosition(sf::Vector2f(178, 88));
	choicename.setFillColor(sf::Color::White);
	choicename.setOutlineColor(sf::Color::White);
	choicename.setOutlineThickness(3);

	sf::RectangleShape choicecat(sf::Vector2f(330.0f, 40.0f));
	choicecat.setPosition(sf::Vector2f(250, 280));
	choicecat.setFillColor(sf::Color::Transparent);
	choicecat.setOutlineColor(sf::Color::White);
	choicecat.setOutlineThickness(3);

	sf::RectangleShape choicecountry(sf::Vector2f(250.0f, 22.0f));
	choicecountry.setPosition(sf::Vector2f(150, 190));
	choicecountry.setFillColor(sf::Color::White);
	choicecountry.setOutlineColor(sf::Color::White);
	choicecountry.setOutlineThickness(3);

	sf::RectangleShape choicecity(sf::Vector2f(250.0f, 22.0f));
	choicecity.setPosition(sf::Vector2f(150, 230));
	choicecity.setFillColor(sf::Color::White);
	choicecity.setOutlineColor(sf::Color::White);
	choicecity.setOutlineThickness(3);

	sf::RectangleShape choice10(sf::Vector2f(330.0f, 40.0f));
	choice10.setPosition(sf::Vector2f(400, 400));
	choice10.setFillColor(sf::Color::Transparent);
	choice10.setOutlineColor(sf::Color::White);
	choice10.setOutlineThickness(3);

	sf::RectangleShape choice20(sf::Vector2f(330.0f, 40.0f));
	choice20.setPosition(sf::Vector2f(400, 470));
	choice20.setFillColor(sf::Color::Transparent);
	choice20.setOutlineColor(sf::Color::White);
	choice20.setOutlineThickness(3);

	sf::RectangleShape choice30(sf::Vector2f(330.0f, 40.0f));
	choice30.setPosition(sf::Vector2f(400, 540));
	choice30.setFillColor(sf::Color::Transparent);
	choice30.setOutlineColor(sf::Color::White);
	choice30.setOutlineThickness(3);

	sf::RectangleShape choice40(sf::Vector2f(330.0f, 40.0f));
	choice40.setPosition(sf::Vector2f(30, 400));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::White);
	choice40.setOutlineThickness(3);

	sf::RectangleShape choice50(sf::Vector2f(330.0f, 40.0f));
	choice50.setPosition(sf::Vector2f(30, 470));
	choice50.setFillColor(sf::Color::Transparent);
	choice50.setOutlineColor(sf::Color::White);
	choice50.setOutlineThickness(3);

	sf::RectangleShape choice60(sf::Vector2f(330.0f, 40.0f));
	choice60.setPosition(sf::Vector2f(30, 540));
	choice60.setFillColor(sf::Color::Transparent);
	choice60.setOutlineColor(sf::Color::White);
	choice60.setOutlineThickness(3);

	sf::RectangleShape choice70(sf::Vector2f(330.0f, 40.0f));
	choice70.setPosition(sf::Vector2f(30, 610));
	choice70.setFillColor(sf::Color::Transparent);
	choice70.setOutlineColor(sf::Color::White);
	choice70.setOutlineThickness(3);

	sf::Font font1;
	font1.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text1;
	text1.setFont(font1);
	text1.setString(" Phones & Tablets ");
	text1.setCharacterSize(30);
	text1.setFillColor(sf::Color::White);
	text1.setPosition(420, 398);
	text1.setStyle(sf::Text::Bold);

	sf::Font font2;
	font2.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text2;
	text2.setFont(font2);
	text2.setString("      Electronics ");
	text2.setCharacterSize(30);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(420, 468);
	text2.setStyle(sf::Text::Bold);

	sf::Font font3;
	font3.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text3;
	text3.setFont(font3);
	text3.setString(" Makeup & Accessories ");
	text3.setCharacterSize(30);
	text3.setFillColor(sf::Color::White);
	text3.setPosition(400, 538);
	text3.setStyle(sf::Text::Bold);

	sf::Font font4;
	font4.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text4;
	text4.setFont(font4);
	text4.setString("        Clothing ");
	text4.setCharacterSize(30);
	text4.setFillColor(sf::Color::White);
	text4.setPosition(60, 398);
	text4.setStyle(sf::Text::Bold);

	sf::Font font5;
	font5.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text5;
	text5.setFont(font5);
	text5.setString("       Shoes & Bags ");
	text5.setCharacterSize(30);
	text5.setFillColor(sf::Color::White);
	text5.setPosition(58, 468);
	text5.setStyle(sf::Text::Bold);

	sf::Font font6;
	font6.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text6;
	text6.setFont(font5);
	text6.setString("         Books ");
	text6.setCharacterSize(30);
	text6.setFillColor(sf::Color::White);
	text6.setPosition(62, 538);
	text6.setStyle(sf::Text::Bold);

	sf::Font font7;
	font7.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text7;
	text7.setFont(font5);
	text7.setString("         Gaming ");
	text7.setCharacterSize(30);
	text7.setFillColor(sf::Color::White);
	text7.setPosition(60, 608);
	text7.setStyle(sf::Text::Bold);

	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String name;
	sf::Text textname(name, fontname, 25);
	textname.setFillColor(sf::Color::Black);
	textname.setPosition(180, 83);

	sf::Font fontcountry;
	fontcountry.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String country;
	sf::Text textcountry(country, fontcountry, 25);
	textcountry.setFillColor(sf::Color::Black);
	textcountry.setPosition(150, 185);

	sf::Font fontcity;
	fontcity.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String city;
	sf::Text textcity(city, fontcity, 25);
	textcity.setFillColor(sf::Color::Black);
	textcity.setPosition(150, 225);

	sf::Font font0;
	font0.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text0;
	text0.setFont(font0);
	text0.setString(" Save ");
	text0.setCharacterSize(20);
	text0.setFillColor(sf::Color::Red);
	text0.setPosition(708, 18);
	text0.setStyle(sf::Text::Bold);

	sf::Font font00;
	font00.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text00;
	text00.setFont(font0);
	text00.setString(" Back ");
	text00.setCharacterSize(22);
	text00.setFillColor(sf::Color::Red);
	text00.setPosition(707, 46);
	text00.setStyle(sf::Text::Bold);

	sf::Font font03;
	font03.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text03;
	text03.setFont(font0);
	text03.setString(" Edit Category ");
	text03.setCharacterSize(30);
	text03.setFillColor(sf::Color::White);
	text03.setPosition(320, 280);
	text03.setStyle(sf::Text::Bold);

	sf::Font font01;
	font01.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text01;
	text01.setFont(font01);
	text01.setString(" Edit Name ");
	text01.setCharacterSize(30);
	text01.setFillColor(sf::Color::White);
	text01.setPosition(325, 10);
	text01.setStyle(sf::Text::Bold);

	sf::Font font02;
	font02.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text02;
	text02.setFont(font02);
	text02.setString("  Edit Address ");
	text02.setCharacterSize(30);
	text02.setFillColor(sf::Color::White);
	text02.setPosition(305, 130);
	text02.setStyle(sf::Text::Bold);

	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString("New Name: ");
	text10.setCharacterSize(30);
	text10.setFillColor(sf::Color::White);
	text10.setPosition(10, 80);
	text10.setStyle(sf::Text::Bold);

	sf::Font font20;
	font20.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text20;
	text20.setFont(font20);
	text20.setString(" City       : ");
	text20.setCharacterSize(30);
	text20.setFillColor(sf::Color::White);
	text20.setPosition(10, 220);
	text20.setStyle(sf::Text::Bold);

	sf::Font font30;
	font30.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text30;
	text30.setFont(font30);
	text30.setString(" Country : ");
	text30.setCharacterSize(30);
	text30.setFillColor(sf::Color::White);
	text30.setPosition(10, 180);
	text30.setStyle(sf::Text::Bold);

	bool badress = false;
	bool bname = false;
	bool cate = false;
	int active = 0, categoryChoice = 0;
	bool fname = false, fcountry = false, fcity = false, fcategory = false;
	sf::String category;

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 247 && localposition.x <= 582 && localposition.y >= 8 && localposition.y <= 47) {
					cout << "edit name " << endl;
					bname = true;
				}
				else if (localposition.x >= 175 && localposition.x <= 509 && localposition.y >= 86 && localposition.y <= 110 && bname) {
					cout << "new name" << endl;
					active = 1;
					cout << active;
					fname = true;
				}
				else if (localposition.x >= 698 && localposition.x <= 783 && localposition.y >= 47 && localposition.y <= 75) {
					cout << "back" << endl;
					return 0;

				}
				else if (localposition.x >= 247 && localposition.x <= 582 && localposition.y >= 127 && localposition.y <= 169) {
					cout << "edit address" << endl;
					badress = true;
				}
				else if (localposition.x >= 248 && localposition.x <= 581 && localposition.y >= 273 && localposition.y <= 320) {
					cout << "edit category" << endl;
					cate = true;
				}
				else if (localposition.x >= 147 && localposition.x <= 403 && localposition.y >= 225 && localposition.y <= 253 && badress) {
					cout << "city" << endl;
					active = 3;
					fcity = true;
					cout << active;
				}
				else if (localposition.x >= 147 && localposition.x <= 403 && localposition.y >= 186 && localposition.y <= 213 && badress) {
					cout << "country" << endl;
					active = 2;
					fcountry = true;
					cout << active;
				}
				else if (localposition.x >= 697 && localposition.x <= 781 && localposition.y >= 16 && localposition.y <= 43 && (name.getSize() > 0 || city.getSize() > 0 || country.getSize() > 0)) {
					cout << "save";
					editShopdata(LogIndex, fname, fcountry, fcity, fcategory, name, country, city, category);
					homepageOwner();
				}
				else if (localposition.x >= 397 && localposition.x <= 731 && localposition.y >= 398 && localposition.y <= 439) {
					category = ("Phones&Tablets");
					cout << "Phones & tablets" << endl;
					choice10.setOutlineColor(sf::Color::Red);
					choice20.setOutlineColor(sf::Color::White);
					choice30.setOutlineColor(sf::Color::White);
					choice40.setOutlineColor(sf::Color::White);
					choice50.setOutlineColor(sf::Color::White);
					choice60.setOutlineColor(sf::Color::White);
					choice70.setOutlineColor(sf::Color::White);
					text1.setFillColor(sf::Color::Red);
					text2.setFillColor(sf::Color::White);
					text3.setFillColor(sf::Color::White);
					text4.setFillColor(sf::Color::White);
					text5.setFillColor(sf::Color::White);
					text6.setFillColor(sf::Color::White);
					text7.setFillColor(sf::Color::White);
					fcategory = true;
				}
				else if (localposition.x >= 396 && localposition.x <= 731 && localposition.y >= 468 && localposition.y <= 512) {
					category = ("Electronics");
					cout << "electronics" << endl;
					choice10.setOutlineColor(sf::Color::White);
					choice20.setOutlineColor(sf::Color::Red);
					choice30.setOutlineColor(sf::Color::White);
					choice40.setOutlineColor(sf::Color::White);
					choice50.setOutlineColor(sf::Color::White);
					choice60.setOutlineColor(sf::Color::White);
					choice70.setOutlineColor(sf::Color::White);
					text1.setFillColor(sf::Color::White);
					text2.setFillColor(sf::Color::Red);
					text3.setFillColor(sf::Color::White);
					text4.setFillColor(sf::Color::White);
					text5.setFillColor(sf::Color::White);
					text6.setFillColor(sf::Color::White);
					text7.setFillColor(sf::Color::White);
					fcategory = true;
				}
				else if (localposition.x >= 397 && localposition.x <= 734 && localposition.y >= 538 && localposition.y <= 581) {
					category = ("Makeup&Accessories");
					cout << "makeup & accessories" << endl;
					choice10.setOutlineColor(sf::Color::White);
					choice20.setOutlineColor(sf::Color::White);
					choice30.setOutlineColor(sf::Color::Red);
					choice40.setOutlineColor(sf::Color::White);
					choice50.setOutlineColor(sf::Color::White);
					choice60.setOutlineColor(sf::Color::White);
					choice70.setOutlineColor(sf::Color::White);
					text1.setFillColor(sf::Color::White);
					text2.setFillColor(sf::Color::White);
					text3.setFillColor(sf::Color::Red);
					text4.setFillColor(sf::Color::White);
					text5.setFillColor(sf::Color::White);
					text6.setFillColor(sf::Color::White);
					text7.setFillColor(sf::Color::White);
					fcategory = true;
				}
				else if (localposition.x >= 28 && localposition.x <= 362 && localposition.y >= 399 && localposition.y <= 439) {
					category = ("Clothing");
					cout << "clothing" << endl;
					choice10.setOutlineColor(sf::Color::White);
					choice20.setOutlineColor(sf::Color::White);
					choice30.setOutlineColor(sf::Color::White);
					choice40.setOutlineColor(sf::Color::Red);
					choice50.setOutlineColor(sf::Color::White);
					choice60.setOutlineColor(sf::Color::White);
					choice70.setOutlineColor(sf::Color::White);
					text1.setFillColor(sf::Color::White);
					text2.setFillColor(sf::Color::White);
					text3.setFillColor(sf::Color::White);
					text4.setFillColor(sf::Color::Red);
					text5.setFillColor(sf::Color::White);
					text6.setFillColor(sf::Color::White);
					text7.setFillColor(sf::Color::White);
					fcategory = true;
				}
				else if (localposition.x >= 28 && localposition.x <= 362 && localposition.y >= 469 && localposition.y <= 505) {
					category = ("Shoes&Bags");
					cout << "shoes & bags" << endl;
					choice10.setOutlineColor(sf::Color::White);
					choice20.setOutlineColor(sf::Color::White);
					choice30.setOutlineColor(sf::Color::White);
					choice40.setOutlineColor(sf::Color::White);
					choice50.setOutlineColor(sf::Color::Red);
					choice60.setOutlineColor(sf::Color::White);
					choice70.setOutlineColor(sf::Color::White);
					text1.setFillColor(sf::Color::White);
					text2.setFillColor(sf::Color::White);
					text3.setFillColor(sf::Color::White);
					text4.setFillColor(sf::Color::White);
					text5.setFillColor(sf::Color::Red);
					text6.setFillColor(sf::Color::White);
					text7.setFillColor(sf::Color::White);
					fcategory = true;
				}
				else if (localposition.x >= 28 && localposition.x <= 362 && localposition.y >= 541 && localposition.y <= 575) {
					category = ("Books");
					cout << "books" << endl;
					choice10.setOutlineColor(sf::Color::White);
					choice20.setOutlineColor(sf::Color::White);
					choice30.setOutlineColor(sf::Color::White);
					choice40.setOutlineColor(sf::Color::White);
					choice50.setOutlineColor(sf::Color::White);
					choice60.setOutlineColor(sf::Color::Red);
					choice70.setOutlineColor(sf::Color::White);
					text1.setFillColor(sf::Color::White);
					text2.setFillColor(sf::Color::White);
					text3.setFillColor(sf::Color::White);
					text4.setFillColor(sf::Color::White);
					text5.setFillColor(sf::Color::White);
					text6.setFillColor(sf::Color::Red);
					text7.setFillColor(sf::Color::White);
					fcategory = true;
				}
				else if (localposition.x >= 28 && localposition.x <= 362 && localposition.y >= 607 && localposition.y <= 649) {
					category = ("Gaming");
					cout << "gaming" << endl;
					choice10.setOutlineColor(sf::Color::White);
					choice20.setOutlineColor(sf::Color::White);
					choice30.setOutlineColor(sf::Color::White);
					choice40.setOutlineColor(sf::Color::White);
					choice50.setOutlineColor(sf::Color::White);
					choice60.setOutlineColor(sf::Color::White);
					choice70.setOutlineColor(sf::Color::Red);
					text1.setFillColor(sf::Color::White);
					text2.setFillColor(sf::Color::White);
					text3.setFillColor(sf::Color::White);
					text4.setFillColor(sf::Color::White);
					text5.setFillColor(sf::Color::White);
					text6.setFillColor(sf::Color::White);
					text7.setFillColor(sf::Color::Red);
					fcategory = true;
				}
				else
				{
					active = 0;
					cout << active;
				}
			}
			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					name += event.text.unicode;
					textname.setString(name);
				}
				else if (active == 1 && event.text.unicode == 8 && name.getSize() > 0)
				{
					name.erase(name.getSize() - 1, name.getSize());
					textname.setString(name);
				}
				if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {

					country += event.text.unicode;
					textcountry.setString(country);
				}
				else if (active == 2 && event.text.unicode == 8 && country.getSize() > 0) {
					country.erase(country.getSize() - 1, country.getSize());
					textcountry.setString(country);
				}
				if (active == 3 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {

					city += event.text.unicode;
					textcity.setString(city);
				}
				else if (active == 3 && event.text.unicode == 8 && city.getSize() > 0) {
					city.erase(city.getSize() - 1, city.getSize());
					textcity.setString(city);
				}
			}
		}

		window.clear();
		window.draw(photo);
		window.draw(text01);
		window.draw(text00);
		window.draw(text02);
		window.draw(choice1);
		window.draw(choice2);
		window.draw(choicesave);
		window.draw(choiceback);
		window.draw(text0);
		window.draw(text03);
		window.draw(choicecat);


		if (bname) {

			window.draw(choicename);
			window.draw(text10);
			window.draw(textname);
		}
		if (badress) {

			window.draw(text30);
			window.draw(text20);
			window.draw(choicecountry);
			window.draw(choicecity);
			window.draw(textcountry);
			window.draw(textcity);

		}
		if (cate) {
			window.draw(text1);
			window.draw(text2);
			window.draw(text3);
			window.draw(text4);
			window.draw(text5);
			window.draw(text6);
			window.draw(text7);
			window.draw(choice10);
			window.draw(choice20);
			window.draw(choice30);
			window.draw(choice40);
			window.draw(choice50);
			window.draw(choice60);
			window.draw(choice70);
		}
		window.display();

	}
}

int addproduct() {

	sf::RectangleShape choice1(sf::Vector2f(330.0f, 20.0f));
	choice1.setPosition(sf::Vector2f(175, 30));
	choice1.setFillColor(sf::Color::White);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(3);

	sf::RectangleShape choice2(sf::Vector2f(330.0f, 20.0f));
	choice2.setPosition(sf::Vector2f(175, 80));
	choice2.setFillColor(sf::Color::White);
	choice2.setOutlineColor(sf::Color::White);
	choice2.setOutlineThickness(3);

	sf::RectangleShape choice3(sf::Vector2f(330.0f, 20.0f));
	choice3.setPosition(sf::Vector2f(175, 130));
	choice3.setFillColor(sf::Color::White);
	choice3.setOutlineColor(sf::Color::White);
	choice3.setOutlineThickness(3);

	sf::RectangleShape choice40(sf::Vector2f(100.0f, 30.0f));
	choice40.setPosition(sf::Vector2f(170, 173));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::White);
	choice40.setOutlineThickness(2);

	sf::RectangleShape choice41(sf::Vector2f(125.0f, 30.0f));
	choice41.setPosition(sf::Vector2f(370, 173));
	choice41.setFillColor(sf::Color::Transparent);
	choice41.setOutlineColor(sf::Color::White);
	choice41.setOutlineThickness(2);

	sf::RectangleShape choice42(sf::Vector2f(100.0f, 30.0f));
	choice42.setPosition(sf::Vector2f(570, 173));
	choice42.setFillColor(sf::Color::Transparent);
	choice42.setOutlineColor(sf::Color::White);
	choice42.setOutlineThickness(2);

	sf::RectangleShape choice51(sf::Vector2f(100.0f, 30.0f));
	choice51.setPosition(sf::Vector2f(250, 220));
	choice51.setFillColor(sf::Color::Transparent);
	choice51.setOutlineColor(sf::Color::White);
	choice51.setOutlineThickness(3);

	sf::RectangleShape choice52(sf::Vector2f(100.0f, 30.0f));
	choice52.setPosition(sf::Vector2f(450, 220));
	choice52.setFillColor(sf::Color::Transparent);
	choice52.setOutlineColor(sf::Color::White);
	choice52.setOutlineThickness(3);

	sf::RectangleShape choice6(sf::Vector2f(330.0f, 20.0f));
	choice6.setPosition(sf::Vector2f(175, 280));
	choice6.setFillColor(sf::Color::White);
	choice6.setOutlineColor(sf::Color::White);
	choice6.setOutlineThickness(3);

	sf::RectangleShape choice7(sf::Vector2f(80.0f, 20.0f));
	choice7.setPosition(sf::Vector2f(670, 670));
	choice7.setFillColor(sf::Color::Transparent);
	choice7.setOutlineColor(sf::Color::Red);
	choice7.setOutlineThickness(3);

	sf::RectangleShape choice8(sf::Vector2f(80.0f, 20.0f));
	choice8.setPosition(sf::Vector2f(670, 720));
	choice8.setFillColor(sf::Color::Transparent);
	choice8.setOutlineColor(sf::Color::Red);
	choice8.setOutlineThickness(3);

	sf::Font font1;
	font1.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text1;
	text1.setFont(font1);
	text1.setString(" Name       :");
	text1.setCharacterSize(30);
	text1.setFillColor(sf::Color::White);
	text1.setPosition(10, 20);
	text1.setStyle(sf::Text::Bold);

	sf::Font font2;
	font2.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text2;
	text2.setFont(font1);
	text2.setString(" Price        : ");
	text2.setCharacterSize(30);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(10, 70);
	text2.setStyle(sf::Text::Bold);

	sf::Font font3;
	font3.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text3;
	text3.setFont(font1);
	text3.setString(" quantity  : ");
	text3.setCharacterSize(30);
	text3.setFillColor(sf::Color::White);
	text3.setPosition(10, 120);
	text3.setStyle(sf::Text::Bold);

	sf::Font font4;
	font4.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text4;
	text4.setFont(font1);
	text4.setString(" size     :  ");
	text4.setCharacterSize(30);
	text4.setFillColor(sf::Color::White);
	text4.setPosition(10, 170);
	text4.setStyle(sf::Text::Bold);

	sf::Font font41;
	font41.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text41;
	text41.setFont(font41);
	text41.setString(" Small ");
	text41.setCharacterSize(25);
	text41.setFillColor(sf::Color::White);
	text41.setPosition(173, 170);
	text41.setStyle(sf::Text::Bold);

	sf::Font font42;
	font42.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text42;
	text42.setFont(font42);
	text42.setString(" Medium ");
	text42.setCharacterSize(25);
	text42.setFillColor(sf::Color::White);
	text42.setPosition(373, 170);
	text42.setStyle(sf::Text::Bold);

	sf::Font font43;
	font43.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text43;
	text43.setFont(font43);
	text43.setString(" Large ");
	text43.setCharacterSize(25);
	text43.setFillColor(sf::Color::White);
	text43.setPosition(573, 170);
	text43.setStyle(sf::Text::Bold);

	sf::Font font5;
	font5.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text5;
	text5.setFont(font1);
	text5.setString(" Type    : ");
	text5.setCharacterSize(30);
	text5.setFillColor(sf::Color::White);
	text5.setPosition(10, 220);
	text5.setStyle(sf::Text::Bold);

	sf::Font font51;
	font51.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text51;
	text51.setFont(font51);
	text51.setString(" Female ");
	text51.setCharacterSize(25);
	text51.setFillColor(sf::Color::White);
	text51.setPosition(250, 220);
	text51.setStyle(sf::Text::Bold);

	sf::Font font52;
	font52.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text52;
	text52.setFont(font52);
	text52.setString("   Male ");
	text52.setCharacterSize(25);
	text52.setFillColor(sf::Color::White);
	text52.setPosition(450, 220);
	text52.setStyle(sf::Text::Bold);

	sf::Font font6;
	font6.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text6;
	text6.setFont(font1);
	text6.setString(" Color       :  ");
	text6.setCharacterSize(30);
	text6.setFillColor(sf::Color::White);
	text6.setPosition(10, 270);
	text6.setStyle(sf::Text::Bold);

	sf::Font font7;
	font7.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text7;
	text7.setFont(font1);
	text7.setString(" Save  ");
	text7.setCharacterSize(24);
	text7.setFillColor(sf::Color::Red);
	text7.setPosition(672, 663);
	text7.setStyle(sf::Text::Bold);

	sf::Font font8;
	font8.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text8;
	text8.setFont(font8);
	text8.setString(" Back  ");
	text8.setCharacterSize(24);
	text8.setFillColor(sf::Color::Red);
	text8.setPosition(672, 713);
	text8.setStyle(sf::Text::Bold);

	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String name;
	sf::Text textname(name, fontname, 25);
	textname.setFillColor(sf::Color::Black);
	textname.setPosition(175, 25);

	sf::Font fontprice;
	fontprice.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String price;
	sf::Text textprice(price, fontprice, 25);
	textprice.setFillColor(sf::Color::Black);
	textprice.setPosition(175, 75);

	sf::Font fontquantity;
	fontquantity.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String quantity;
	sf::Text textquantity(quantity, fontquantity, 25);
	textquantity.setFillColor(sf::Color::Black);
	textquantity.setPosition(175, 125);

	sf::Font fontcolor;
	fontcolor.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String color;
	sf::Text textcolor(color, fontcolor, 25);
	textcolor.setFillColor(sf::Color::Black);
	textcolor.setPosition(175, 275);

	bool clothing = false;
	if (Owners[LogID].Shops.Category == "Clothing") {
		clothing = true;
	}
	int active = 0, intprice = 0, intquantity = 0;
	string type = "", size = "";

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 171 && localposition.x <= 507 && localposition.y >= 26 && localposition.y <= 52) {
					cout << "name " << endl;
					active = 1;
				}
				else if (localposition.x >= 171 && localposition.x <= 507 && localposition.y >= 77 && localposition.y <= 101) {
					cout << "price" << endl;
					active = 2;

				}

				else if (localposition.x >= 171 && localposition.x <= 507 && localposition.y >= 125 && localposition.y <= 151) {
					cout << "quantity" << endl;
					active = 3;

				}
				else if (localposition.x >= 170 && localposition.x <= 272 && localposition.y >= 171 && localposition.y <= 203 && clothing) {
					cout << "small" << endl;
					choice40.setOutlineColor(sf::Color::Red);
					choice41.setOutlineColor(sf::Color::White);
					choice42.setOutlineColor(sf::Color::White);
					text41.setFillColor(sf::Color::Red);
					text42.setFillColor(sf::Color::White);
					text43.setFillColor(sf::Color::White);
					size = "s";

					cout << active;
				}
				else if (localposition.x >= 368 && localposition.x <= 495 && localposition.y >= 171 && localposition.y <= 203 && clothing) {
					cout << "medium" << endl;
					choice40.setOutlineColor(sf::Color::White);
					choice41.setOutlineColor(sf::Color::Red);
					choice42.setOutlineColor(sf::Color::White);
					text41.setFillColor(sf::Color::White);
					text42.setFillColor(sf::Color::Red);
					text43.setFillColor(sf::Color::White);
					size = "m";
					cout << active;
				}
				else if (localposition.x >= 568 && localposition.x <= 672 && localposition.y >= 171 && localposition.y <= 203 && clothing) {
					cout << "large" << endl;
					choice40.setOutlineColor(sf::Color::White);
					choice41.setOutlineColor(sf::Color::White);
					choice42.setOutlineColor(sf::Color::Red);
					text41.setFillColor(sf::Color::White);
					text42.setFillColor(sf::Color::White);
					text43.setFillColor(sf::Color::Red);
					size = "l";
					cout << active;
				}
				else if (localposition.x >= 246 && localposition.x <= 350 && localposition.y >= 215 && localposition.y <= 251 && clothing) {
					cout << "female" << endl;
					text51.setFillColor(sf::Color::Red);
					text52.setFillColor(sf::Color::White);
					choice51.setOutlineColor(sf::Color::Red);
					choice52.setOutlineColor(sf::Color::White);
					type = "Female";
				}
				else if (localposition.x >= 447 && localposition.x <= 553 && localposition.y >= 217 && localposition.y <= 249 && clothing) {
					cout << "male" << endl;
					text51.setFillColor(sf::Color::White);
					text52.setFillColor(sf::Color::Red);
					choice51.setOutlineColor(sf::Color::White);
					choice52.setOutlineColor(sf::Color::Red);
					type = "Male";
				}
				else if (localposition.x >= 171 && localposition.x <= 506 && localposition.y >= 277 && localposition.y <= 300 && clothing) {
					cout << "color" << endl;
					active = 4;
					cout << active;
				}
				else if (localposition.x >= 667 && localposition.x <= 751 && localposition.y >= 667 && localposition.y <= 692) {
					istringstream(price) >> intprice;
					istringstream(quantity) >> intquantity;
					addProds(LogIndex, name, intprice, intquantity, type, size, color);
					prodchoice();
				}
				else if (localposition.x >= 667 && localposition.x <= 751 && localposition.y >= 716 && localposition.y <= 739) {
					return 0;
				}
				else
				{
					active = 0;

				}
			}
			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					name += event.text.unicode;
					textname.setString(name);
				}
				else if (active == 1 && event.text.unicode == 8 && name.getSize() > 0)
				{
					name.erase(name.getSize() - 1, name.getSize());
					textname.setString(name);
				}
				if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					price += event.text.unicode;
					textprice.setString(price);
				}
				else if (active == 2 && event.text.unicode == 8 && price.getSize() > 0)
				{
					price.erase(price.getSize() - 1, price.getSize());
					textprice.setString(price);
				}
				if (active == 3 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					quantity += event.text.unicode;
					textquantity.setString(quantity);
				}
				else if (active == 3 && event.text.unicode == 8 && quantity.getSize() > 0)
				{
					quantity.erase(quantity.getSize() - 1, quantity.getSize());
					textquantity.setString(quantity);
				}
				if (active == 4 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					color += event.text.unicode;
					textcolor.setString(color);
				}
				else if (active == 4 && event.text.unicode == 8 && color.getSize() > 0)
				{
					color.erase(color.getSize() - 1, color.getSize());
					textcolor.setString(color);
				}
			}
		}

		window.draw(photo);
		window.draw(choice1);
		window.draw(choice2);
		window.draw(choice3);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text7);
		window.draw(text8);
		window.draw(choice7);
		window.draw(choice8);
		window.draw(textname);
		window.draw(textprice);
		window.draw(textquantity);
		if (clothing) {

			window.draw(choice41);
			window.draw(choice40);
			window.draw(choice42);
			window.draw(choice51);
			window.draw(choice52);
			window.draw(choice6);
			window.draw(text41);
			window.draw(text42);
			window.draw(text43);
			window.draw(text51);
			window.draw(text52);
			window.draw(text6);
			window.draw(text5);
			window.draw(text4);
			window.draw(textcolor);

		}

		window.display();
	}

}

void homepageOwner() {

	sf::RectangleShape choice1(sf::Vector2f(320.0f, 80.0f));
	choice1.setPosition(sf::Vector2f(290, 200));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineThickness(5);
	choice1.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice2(sf::Vector2f(320.0f, 80.0f));
	choice2.setPosition(sf::Vector2f(290, 380));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineThickness(5);
	choice2.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice5(sf::Vector2f(320.0f, 80.0f));
	choice5.setPosition(sf::Vector2f(290, 560));
	choice5.setFillColor(sf::Color::Transparent);
	choice5.setOutlineThickness(5);
	choice5.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice3(sf::Vector2f(100.0f, 22.0f));
	choice3.setPosition(sf::Vector2f(785, 20));
	choice3.setFillColor(sf::Color::Transparent);
	choice3.setOutlineColor(sf::Color::Red);
	choice3.setOutlineThickness(3);

	sf::RectangleShape choice4(sf::Vector2f(100.0f, 22.0f));
	choice4.setPosition(sf::Vector2f(785, 60));
	choice4.setFillColor(sf::Color::Transparent);
	choice4.setOutlineColor(sf::Color::Red);
	choice4.setOutlineThickness(3);


	sf::Font fonta;
	fonta.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texta;
	texta.setFont(fonta);
	texta.setString("            Edit  ");
	texta.setCharacterSize(30);
	texta.setFillColor(sf::Color::White);
	texta.setPosition(320, 219);
	texta.setStyle(sf::Text::Bold);

	sf::Font fontb;
	fontb.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textb;
	textb.setFont(fontb);
	textb.setString("        Products  ");
	textb.setCharacterSize(30);
	textb.setFillColor(sf::Color::White);
	textb.setPosition(320, 400);
	textb.setStyle(sf::Text::Bold);

	sf::Font fonte;
	fonte.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texte;
	texte.setFont(fonte);
	texte.setString("   Delete Account  ");
	texte.setCharacterSize(30);
	texte.setFillColor(sf::Color::White);
	texte.setPosition(320, 578);
	texte.setStyle(sf::Text::Bold);

	sf::Font fontx;
	fontx.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textx;
	textx.setFont(fontx);
	textx.setString("      Check Your ID at Your Profile.   ");
	textx.setCharacterSize(25);
	textx.setFillColor(sf::Color::White);
	textx.setPosition(233, 734);
	textx.setStyle(sf::Text::Bold);

	sf::Font fontc;
	fontc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textc;
	textc.setFont(fontc);
	textc.setString("Log Out");
	textc.setCharacterSize(20);
	textc.setFillColor(sf::Color::Red);
	textc.setPosition(800, 58);
	textc.setStyle(sf::Text::Bold);

	sf::Font fontv;
	fontv.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textv;
	textv.setFont(fontv);
	textv.setString(" Profile ");
	textv.setCharacterSize(20);
	textv.setFillColor(sf::Color::Red);
	textv.setPosition(800, 18);
	textv.setStyle(sf::Text::Bold);


	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << "{" << localposition.x << "-" << localposition.y << "]" << endl;

				if (localposition.x >= 281 && localposition.x <= 615 && localposition.y >= 193 && localposition.y <= 285) {
					cout << "edit" << endl;
					editowner();

				}
				else if (localposition.x >= 281 && localposition.x <= 620 && localposition.y >= 371 && localposition.y <= 466) {
					cout << "Products" << endl;
					prodchoice();
				}
				else if (localposition.x >= 781 && localposition.x <= 888 && localposition.y >= 17 && localposition.y <= 44) {

					ownerprofile(LogID);
				}

				else if (localposition.x >= 781 && localposition.x <= 888 && localposition.y >= 57 && localposition.y <= 84) {
					save();
					welcome();
				}
				else if (localposition.x >= 283 && localposition.x <= 616 && localposition.y >= 555 && localposition.y <= 643) {
					cout << "delete" << endl;
					deleteOwner();
				}
			}
			window.clear();
			window.draw(photo);
			window.draw(texta);
			window.draw(textb);
			window.draw(textc);
			window.draw(texte);
			window.draw(textx);
			window.draw(textv);
			window.draw(choice1);
			window.draw(choice2);
			window.draw(choice3);
			window.draw(choice4);
			window.draw(choice5);
			window.display();
		}
	}
}

int discount() {

	sf::RectangleShape choice1(sf::Vector2f(400.0f, 20.0f));
	choice1.setPosition(sf::Vector2f(290, 110));
	choice1.setFillColor(sf::Color::White);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(7);

	sf::RectangleShape choice2(sf::Vector2f(400.0f, 20.0f));
	choice2.setPosition(sf::Vector2f(290, 210));
	choice2.setFillColor(sf::Color::White);
	choice2.setOutlineColor(sf::Color::White);
	choice2.setOutlineThickness(7);

	sf::RectangleShape choice3(sf::Vector2f(400.0f, 20.0f));
	choice3.setPosition(sf::Vector2f(290, 310));
	choice3.setFillColor(sf::Color::White);
	choice3.setOutlineColor(sf::Color::White);
	choice3.setOutlineThickness(7);

	sf::RectangleShape choice4(sf::Vector2f(400.0f, 20.0f));
	choice4.setPosition(sf::Vector2f(290, 410));
	choice4.setFillColor(sf::Color::White);
	choice4.setOutlineColor(sf::Color::White);
	choice4.setOutlineThickness(7);

	sf::RectangleShape choice5(sf::Vector2f(100.0f, 30.0f));
	choice5.setPosition(sf::Vector2f(500, 500));
	choice5.setFillColor(sf::Color::Transparent);
	choice5.setOutlineColor(sf::Color::White);
	choice5.setOutlineThickness(5);

	sf::RectangleShape choice6(sf::Vector2f(100.0f, 22.0f));
	choice6.setPosition(sf::Vector2f(685, 20));
	choice6.setFillColor(sf::Color::Transparent);
	choice6.setOutlineColor(sf::Color::Red);
	choice6.setOutlineThickness(3);

	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String name;
	sf::Text textname(name, fontname, 25);
	textname.setFillColor(sf::Color::Black);
	textname.setPosition(290, 105);


	sf::Font fontdiscount;
	fontdiscount.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String discount;
	sf::Text textdiscount(discount, fontdiscount, 25);
	textdiscount.setFillColor(sf::Color::Black);
	textdiscount.setPosition(290, 205);

	sf::Font fontday;
	fontday.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String sday;
	sf::Text textday(sday, fontday, 25);
	textday.setFillColor(sf::Color::Black);
	textday.setPosition(290, 405);

	sf::Font fontmonth;
	fontmonth.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String smonth;
	sf::Text textmonth(smonth, fontmonth, 25);
	textmonth.setFillColor(sf::Color::Black);
	textmonth.setPosition(290, 305);


	sf::Font fonta;
	fonta.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texta;
	texta.setFont(fonta);
	texta.setString(" Product Name  :  ");
	texta.setCharacterSize(30);
	texta.setFillColor(sf::Color::White);
	texta.setPosition(40, 100);
	texta.setStyle(sf::Text::Bold);

	sf::Font fontb;
	fontb.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textb;
	textb.setFont(fontb);
	textb.setString(" Discount            : ");
	textb.setCharacterSize(30);
	textb.setFillColor(sf::Color::White);
	textb.setPosition(40, 200);
	textb.setStyle(sf::Text::Bold);

	sf::Font fontc;
	fontc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textc;
	textc.setFont(fontc);
	textc.setString(" Month                : ");
	textc.setCharacterSize(30);
	textc.setFillColor(sf::Color::White);
	textc.setPosition(40, 300);
	textc.setStyle(sf::Text::Bold);

	sf::Font fontd;
	fontd.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textd;
	textd.setFont(fontd);
	textd.setString(" Day                     : ");
	textd.setCharacterSize(30);
	textd.setFillColor(sf::Color::White);
	textd.setPosition(40, 400);
	textd.setStyle(sf::Text::Bold);

	sf::Font fonte;
	fonte.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texte;
	texte.setFont(fonte);
	texte.setString("  ** Please fill in all of the Spaces ** ");
	texte.setCharacterSize(28);
	texte.setFillColor(sf::Color::White);
	texte.setPosition(200, 445);
	texte.setStyle(sf::Text::Bold);

	sf::Font fontf;
	fontf.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textf;
	textf.setFont(fontf);
	textf.setString(" Save ");
	textf.setCharacterSize(28);
	textf.setFillColor(sf::Color::White);
	textf.setPosition(510, 495);
	textf.setStyle(sf::Text::Bold);

	sf::Font font0;
	font0.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text0;
	text0.setFont(font0);
	text0.setString(" Back ");
	text0.setCharacterSize(20);
	text0.setFillColor(sf::Color::Red);
	text0.setPosition(708, 18);
	text0.setStyle(sf::Text::Bold);

	sf::Font fontg;
	fontg.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textg;
	textg.setFont(fontg);
	textg.setString(" **The Product's Name you entered is incorrect** ");
	textg.setCharacterSize(30);
	textg.setFillColor(sf::Color::White);
	textg.setPosition(100, 560);
	textg.setStyle(sf::Text::Bold);


	bool fill = false, found = false, displaynameError = false;
	int active = 0, day2, month2, discount2;
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 282 && localposition.x <= 696 && localposition.y >= 100 && localposition.y <= 135) {
					active = 1;
					cout << "Name" << endl;

				}
				else if (localposition.x >= 282 && localposition.x <= 695 && localposition.y >= 202 && localposition.y <= 235) {
					active = 2;
					cout << "Percentage" << endl;

				}
				else if (localposition.x >= 282 && localposition.x <= 695 && localposition.y >= 302 && localposition.y <= 333) {
					active = 3;
					cout << "Month" << endl;

				}
				else if (localposition.x >= 282 && localposition.x <= 695 && localposition.y >= 402 && localposition.y <= 434) {
					active = 4;
					cout << "Day" << endl;

				}
				else if (localposition.x >= 350 && localposition.x <= 750 && localposition.y >= 493 && localposition.y <= 538) {
					active = 5;
					cout << "Save" << endl;
					if (name == "" || discount == "" || smonth == "" || sday == "") {
						fill = true;
					}
					else
						fill = false;
					if (fill == false) {
						istringstream(discount) >> discount2;
						istringstream(smonth) >> month2;
						istringstream(sday) >> day2;
						for (int i = 0; i < maxProds; i++) {
							if (Owners[LogID].Shops.products[i].productName == name) {
								found = true;
								if (discount2 <= 100) {
									if (day2 <= 31 && month2 <= 12) {
										if (month2 >= month) {
											if (month2 == month) {
												if (day2 > day) {
													discounts(LogIndex, name, discount2, month2, day2);
													prodchoice();
												}
											}
											else
											{
												discounts(LogIndex, name, discount2, month2, day2);
												prodchoice();
											}
										}
									}
								}
							}
						}

					}
					if (found == false)
					{
						displaynameError = true;
					}

				}
				else if (localposition.x >= 680 && localposition.x <= 786 && localposition.y >= 18 && localposition.y <= 42) {
					cout << "Back" << endl;
					return 0;
				}
				else
					active = 0;
			}

			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					name += event.text.unicode;
					textname.setString(name);
				}
				else if (active == 1 && event.text.unicode == 8 && name.getSize() > 0) {
					name.erase(name.getSize() - 1, name.getSize());
					textname.setString(name);
				}
				if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					discount += event.text.unicode;
					textdiscount.setString(discount);
				}
				else if (active == 2 && event.text.unicode == 8 && discount.getSize() > 0) {
					discount.erase(discount.getSize() - 1, discount.getSize());
					textdiscount.setString(discount);
				}
				if (active == 3 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					smonth += event.text.unicode;
					textmonth.setString(smonth);
				}
				else if (active == 3 && event.text.unicode == 8 && smonth.getSize() > 0) {
					smonth.erase(smonth.getSize() - 1, smonth.getSize());
					textmonth.setString(smonth);
				}
				if (active == 4 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					sday += event.text.unicode;
					textday.setString(sday);
				}
				else if (active == 4 && event.text.unicode == 8 && sday.getSize() > 0) {
					sday.erase(sday.getSize() - 1, sday.getSize());
					textday.setString(sday);
				}

			}
		}
		window.clear();
		window.draw(photo);
		window.draw(texta);
		window.draw(textb);
		window.draw(textc);
		window.draw(textd);
		window.draw(textf);
		window.draw(text0);
		window.draw(choice1);
		window.draw(choice2);
		window.draw(choice3);
		window.draw(choice4);
		window.draw(choice5);
		window.draw(choice6);
		window.draw(textname);
		window.draw(textdiscount);
		window.draw(textmonth);
		window.draw(textday);
		if (fill) {
			window.draw(texte);
		}
		if (displaynameError) {
			window.draw(textg);
		}
		window.display();
	}
}

int remove() {

	sf::RectangleShape choice1(sf::Vector2f(400.0f, 20.0f));
	choice1.setPosition(sf::Vector2f(280, 110));
	choice1.setFillColor(sf::Color::White);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(7);

	sf::RectangleShape choice2(sf::Vector2f(150.0f, 30.0f));
	choice2.setPosition(sf::Vector2f(400, 205));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineColor(sf::Color::White);
	choice2.setOutlineThickness(4);

	sf::RectangleShape choice2a(sf::Vector2f(150.0f, 30.0f));
	choice2a.setPosition(sf::Vector2f(300, 355));
	choice2a.setFillColor(sf::Color::Transparent);
	choice2a.setOutlineColor(sf::Color::White);
	choice2a.setOutlineThickness(5);

	sf::RectangleShape choice2b(sf::Vector2f(150.0f, 30.0f));
	choice2b.setPosition(sf::Vector2f(500, 355));
	choice2b.setFillColor(sf::Color::Transparent);
	choice2b.setOutlineColor(sf::Color::White);
	choice2b.setOutlineThickness(5);

	sf::RectangleShape choice3(sf::Vector2f(400.0f, 120.0f));
	choice3.setPosition(sf::Vector2f(270, 300));
	choice3.setFillColor(sf::Color::Transparent);
	choice3.setOutlineColor(sf::Color::White);
	choice3.setOutlineThickness(2);

	sf::RectangleShape choice5(sf::Vector2f(100.0f, 30.0f));
	choice5.setPosition(sf::Vector2f(745, 20));
	choice5.setFillColor(sf::Color::Transparent);
	choice5.setOutlineColor(sf::Color::White);
	choice5.setOutlineThickness(5);

	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String name;
	sf::Text textname(name, fontname, 25);
	textname.setFillColor(sf::Color::Black);
	textname.setPosition(290, 105);

	sf::Font fonta;
	fonta.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texta;
	texta.setFont(fonta);
	texta.setString(" Product's Name  :  ");
	texta.setCharacterSize(30);
	texta.setFillColor(sf::Color::White);
	texta.setPosition(30, 100);
	texta.setStyle(sf::Text::Bold);

	sf::Font fontb;
	fontb.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textb;
	textb.setFont(fontb);
	textb.setString(" Remove ");
	textb.setCharacterSize(30);
	textb.setFillColor(sf::Color::White);
	textb.setPosition(415, 200);
	textb.setStyle(sf::Text::Bold);

	sf::Font fontc;
	fontc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textc;
	textc.setFont(fontc);
	textc.setString(" Are you sure ? ");
	textc.setCharacterSize(28);
	textc.setFillColor(sf::Color::White);
	textc.setPosition(395, 300);
	textc.setStyle(sf::Text::Bold);

	sf::Font fontd;
	fontd.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textd;
	textd.setFont(fontd);
	textd.setString(" Yes ");
	textd.setCharacterSize(30);
	textd.setFillColor(sf::Color::White);
	textd.setPosition(340, 350);
	textd.setStyle(sf::Text::Bold);

	sf::Font fonte;
	fonte.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texte;
	texte.setFont(fonte);
	texte.setString("  No ");
	texte.setCharacterSize(30);
	texte.setFillColor(sf::Color::White);
	texte.setPosition(545, 350);
	texte.setStyle(sf::Text::Bold);

	sf::Font fontf;
	fontf.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textf;
	textf.setFont(fontf);
	textf.setString(" Back ");
	textf.setCharacterSize(28);
	textf.setFillColor(sf::Color::White);
	textf.setPosition(750, 15);
	textf.setStyle(sf::Text::Bold);

	sf::Font fontg;
	fontg.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textg;
	textg.setFont(fontf);
	textg.setString(" **Product is unavailable** ");
	textg.setCharacterSize(30);
	textg.setFillColor(sf::Color::White);
	textg.setPosition(300, 500);
	textg.setStyle(sf::Text::Bold);


	bool fill = false;
	int active = 0, check = 1;
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 282 && localposition.x <= 696 && localposition.y >= 100 && localposition.y <= 135) {
					active = 1;
					cout << "Name" << endl;

				}
				else if (localposition.x >= 395 && localposition.x <= 550 && localposition.y >= 202 && localposition.y <= 235) {
					cout << "Remove" << endl;
					if (name != "")
					{
						fill = true;
					}
					else fill = false;

				}
				else if (localposition.x >= 295 && localposition.x <= 450 && localposition.y >= 350 && localposition.y <= 390) {
					cout << "Yes" << endl;
					check = removeProds(LogIndex, name);
					if (check != 0) {
						prodchoice();
					}
				}
				else if (localposition.x >= 495 && localposition.x <= 650 && localposition.y >= 350 && localposition.y <= 390) {
					cout << "No" << endl;
					prodchoice();
				}
				else if (localposition.x >= 740 && localposition.x <= 850 && localposition.y >= 15 && localposition.y <= 50) {
					cout << "Back" << endl;
					return 0;
				}
				else
					active = 0;
			}

			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					name += event.text.unicode;
					textname.setString(name);
				}
				else if (active == 1 && event.text.unicode == 8 && name.getSize() > 0) {
					name.erase(name.getSize() - 1, name.getSize());
					textname.setString(name);
				}
			}
		}
		window.clear();
		window.draw(photo);
		window.draw(texta);
		window.draw(textb);
		window.draw(textf);
		window.draw(choice1);
		if (fill) {
			window.draw(textc);
			window.draw(textd);
			window.draw(texte);
			window.draw(choice2a);
			window.draw(choice2b);
			window.draw(choice3);
		};
		window.draw(choice2);
		window.draw(choice5);
		window.draw(textname);
		if (check == 0)
		{
			window.draw(textg);
		}
		window.display();
	}
}

void viewproduct() {

	int a[75];
	int z = 0;
	float hi = 50, ho = 50;
	bool next = false;
	bool done = false;
	bool type = false;
	int k = 0, n = 0;



	sf::Font font100;
	font100.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text100;
	text100.setFont(font100);
	text100.setString(" Your Desired Quantity Is Unavalible.  ");
	text100.setCharacterSize(22);
	text100.setFillColor(sf::Color::White);
	text100.setPosition(340, 705);
	text100.setStyle(sf::Text::Bold);

	sf::Font font200;
	font200.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text200;
	text200.setFont(font200);
	text200.setString(" Invalid number.  ");
	text200.setCharacterSize(22);
	text200.setFillColor(sf::Color::White);
	text200.setPosition(340, 705);
	text200.setStyle(sf::Text::Bold);


	string nump[75];
	string price[75];
	string averating[75];
	string quantity[75];

	sf::String p;
	sf::Font fontp;
	fontp.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textp[75];

	sf::String name;
	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textname[75];


	sf::String num;
	sf::Font fontnum;
	fontnum.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textnum[75];

	sf::String cate;
	sf::Font fontcate;
	fontcate.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcate[75];

	sf::Font fontprice;
	fontprice.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textprice[75];

	sf::Font fontsize;
	fontsize.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textsize[75];

	sf::Font fontrating;
	fontrating.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textrating[75];

	sf::Font fontquantity;
	fontquantity.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textquantity[75];

	sf::Font fonttype;
	fonttype.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texttype[75];

	sf::Font fontcolor;
	fontcolor.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcolor[75];

	sf::RectangleShape choice1(sf::Vector2f(100.0f, 30.0f));
	choice1.setPosition(sf::Vector2f(5, 10));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineColor(sf::Color::Blue);
	choice1.setOutlineThickness(3);

	sf::RectangleShape choice2(sf::Vector2f(100.0f, 30.0f));
	choice2.setPosition(sf::Vector2f(120, 10));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineColor(sf::Color::Blue);
	choice2.setOutlineThickness(3);

	sf::RectangleShape choice3(sf::Vector2f(100.0f, 30.0f));
	choice3.setPosition(sf::Vector2f(235, 10));
	choice3.setFillColor(sf::Color::Transparent);
	choice3.setOutlineColor(sf::Color::Blue);
	choice3.setOutlineThickness(3);

	sf::RectangleShape choice4(sf::Vector2f(100.0f, 30.0f));
	choice4.setPosition(sf::Vector2f(350, 10));
	choice4.setFillColor(sf::Color::Transparent);
	choice4.setOutlineColor(sf::Color::Blue);
	choice4.setOutlineThickness(3);

	sf::RectangleShape choice5(sf::Vector2f(100.0f, 30.0f));
	choice5.setPosition(sf::Vector2f(465, 10));
	choice5.setFillColor(sf::Color::Transparent);
	choice5.setOutlineColor(sf::Color::Blue);
	choice5.setOutlineThickness(3);

	sf::RectangleShape choice6(sf::Vector2f(100.0f, 30.0f));
	choice6.setPosition(sf::Vector2f(580, 10));
	choice6.setFillColor(sf::Color::Transparent);
	choice6.setOutlineColor(sf::Color::Blue);
	choice6.setOutlineThickness(3);

	sf::RectangleShape choice7(sf::Vector2f(100.0f, 30.0f));
	choice7.setPosition(sf::Vector2f(695, 10));
	choice7.setFillColor(sf::Color::Transparent);
	choice7.setOutlineColor(sf::Color::Blue);
	choice7.setOutlineThickness(3);

	sf::RectangleShape choice8(sf::Vector2f(100.0f, 30.0f));
	choice8.setPosition(sf::Vector2f(810, 10));
	choice8.setFillColor(sf::Color::Transparent);
	choice8.setOutlineColor(sf::Color::Blue);
	choice8.setOutlineThickness(3);


	sf::RectangleShape choice10(sf::Vector2f(130.0f, 30.0f));
	choice10.setPosition(sf::Vector2f(520, 745));
	choice10.setFillColor(sf::Color::Transparent);
	choice10.setOutlineColor(sf::Color::Blue);
	choice10.setOutlineThickness(3);

	sf::RectangleShape choice20(sf::Vector2f(80.0f, 30.0f));
	choice20.setPosition(sf::Vector2f(320, 745));
	choice20.setFillColor(sf::Color::Transparent);
	choice20.setOutlineColor(sf::Color::Blue);
	choice20.setOutlineThickness(3);

	sf::RectangleShape choice30(sf::Vector2f(50.0f, 25.0f));
	choice30.setPosition(sf::Vector2f(220, 748));
	choice30.setFillColor(sf::Color::White);
	choice30.setOutlineColor(sf::Color::White);
	choice30.setOutlineThickness(3);

	sf::RectangleShape choice40(sf::Vector2f(80.0f, 30.0f));
	choice40.setPosition(sf::Vector2f(812, 748));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::Red);
	choice40.setOutlineThickness(3);

	sf::RectangleShape choice50(sf::Vector2f(130.0f, 30.0f));
	choice50.setPosition(sf::Vector2f(665, 745));
	choice50.setFillColor(sf::Color::Transparent);
	choice50.setOutlineColor(sf::Color::Blue);
	choice50.setOutlineThickness(3);

	sf::Font fontc;
	fontc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String c;
	sf::Text textc(c, fontc, 25);
	textc.setFillColor(sf::Color::Black);
	textc.setPosition(218, 743);

	sf::RectangleShape choice33(sf::Vector2f(50.0f, 25.0f));
	choice33.setPosition(sf::Vector2f(220, 715));
	choice33.setFillColor(sf::Color::White);
	choice33.setOutlineColor(sf::Color::White);
	choice33.setOutlineThickness(3);

	sf::Font fontq;
	fontq.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String q;
	sf::Text textq(q, fontq, 25);
	textq.setFillColor(sf::Color::Black);
	textq.setPosition(220, 715);

	sf::Font font60;
	font60.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text60;
	text60.setFont(font60);
	text60.setString(" Product quantity:  ");
	text60.setCharacterSize(22);
	text60.setFillColor(sf::Color::Blue);
	text60.setPosition(15, 715);
	text60.setStyle(sf::Text::Bold);

	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" BACK ");
	text10.setCharacterSize(20);
	text10.setFillColor(sf::Color::Red);
	text10.setPosition(820, 750);
	text10.setStyle(sf::Text::Bold);

	sf::Font font20;
	font20.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text20;
	text20.setFont(font20);
	text20.setString("  Next Page ");
	text20.setCharacterSize(22);
	text20.setFillColor(sf::Color::Blue);
	text20.setPosition(520, 745);
	text20.setStyle(sf::Text::Bold);

	sf::Font font30;
	font30.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text30;
	text30.setFont(font30);
	text30.setString(" Add ");
	text30.setCharacterSize(22);
	text30.setFillColor(sf::Color::Blue);
	text30.setPosition(330, 745);
	text30.setStyle(sf::Text::Bold);

	sf::Font font40;
	font40.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text40;
	text40.setFont(font40);
	text40.setString(" Previous ");
	text40.setCharacterSize(22);
	text40.setFillColor(sf::Color::Blue);
	text40.setPosition(680, 745);
	text40.setStyle(sf::Text::Bold);

	sf::Font font50;
	font50.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text50;
	text50.setFont(font50);
	text50.setString(" Product number :  ");
	text50.setCharacterSize(22);
	text50.setFillColor(sf::Color::Blue);
	text50.setPosition(15, 748);
	text50.setStyle(sf::Text::Bold);

	sf::Font font1;
	font1.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text1;
	text1.setFont(font1);
	text1.setString(" NAME ");
	text1.setCharacterSize(22);
	text1.setFillColor(sf::Color::Blue);
	text1.setPosition(14, 10);
	text1.setStyle(sf::Text::Bold);

	sf::Font font2;
	font2.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text2;
	text2.setFont(font2);
	text2.setString(" PRICE ");
	text2.setCharacterSize(22);
	text2.setFillColor(sf::Color::Blue);
	text2.setPosition(130, 10);
	text2.setStyle(sf::Text::Bold);

	sf::Font font3;
	font3.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text3;
	text3.setFont(font3);
	text3.setString(" CATEGORY  ");
	text3.setCharacterSize(18);
	text3.setFillColor(sf::Color::Blue);
	text3.setPosition(232, 14);
	text3.setStyle(sf::Text::Bold);

	sf::Font font4;
	font4.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text4;
	text4.setFont(font4);
	text4.setString("  QUANTITY ");
	text4.setCharacterSize(19);
	text4.setFillColor(sf::Color::Blue);
	text4.setPosition(340, 13);
	text4.setStyle(sf::Text::Bold);

	sf::Font font5;
	font5.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text5;
	text5.setFont(font5);
	text5.setString("  RATING ");
	text5.setCharacterSize(21);
	text5.setFillColor(sf::Color::Blue);
	text5.setPosition(461, 11);
	text5.setStyle(sf::Text::Bold);

	sf::Font font00;
	font00.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text00;
	text00.setFont(font00);
	text00.setString("** Please Choose Number **");
	text00.setCharacterSize(22);
	text00.setFillColor(sf::Color::Blue);
	text00.setPosition(340, 705);
	text00.setStyle(sf::Text::Bold);

	sf::Font font6;
	font6.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text6;
	text6.setFont(font6);
	text6.setString(" SIZE ");
	text6.setCharacterSize(22);
	text6.setFillColor(sf::Color::Blue);
	text6.setPosition(598, 10);
	text6.setStyle(sf::Text::Bold);

	sf::Font font7;
	font7.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text7;
	text7.setFont(font7);
	text7.setString(" TYPE ");
	text7.setCharacterSize(22);
	text7.setFillColor(sf::Color::Blue);
	text7.setPosition(710, 10);
	text7.setStyle(sf::Text::Bold);

	sf::Font font8;
	font8.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text8;
	text8.setFont(font8);
	text8.setString(" COLOR ");
	text8.setCharacterSize(22);
	text8.setFillColor(sf::Color::Blue);
	text8.setPosition(820, 10);
	text8.setStyle(sf::Text::Bold);
	k = 0, n = 0;
	for (int i = 0; i < maxOwners; i++) {
		for (int j = 0; j < maxProds; j++) {
			if (Owners[i].Shops.products[j].Quantity != 0) {
				textname[k].setString(Owners[i].Shops.products[j].productName);
				textcate[k].setString(Owners[i].Shops.products[j].Category);
				textsize[k].setString(Owners[i].Shops.products[j].Clothes.Size);
				texttype[k].setString(Owners[i].Shops.products[j].Clothes.Type);
				textcolor[k].setString(Owners[i].Shops.products[j].Clothes.Color);
				textp[k].setString(") ");
				m.a[k] = i;
				m.b[k] = j;
				k++;
			}
		}
	}


	k = 0;
	for (int i = 0; i < 75; i++) {
		a[i] = i + 1;
	}

	for (int i = 0; i < 75; i++) {
		long long price1 = a[i];
		while (price1 != 0)
		{
			int m = price1 % 10;
			nump[i] += m + '0';
			price1 /= 10;
		}
		reverse(nump[i].begin(), nump[i].end());
		textnum[i].setString(nump[i]);
	}

	for (int i = 0; i < maxOwners; i++) {
		for (int j = 0; j < maxProds; j++) {
			if (Owners[i].Shops.products[j].Quantity != 0) {

				long long price2 = Owners[i].Shops.products[j].productPrice;
				long long price3 = Owners[i].Shops.products[j].Quantity;
				long long price4 = Owners[i].Shops.products[j].avgRating;

				while (price2 != 0) {
					int remainder = price2 % 10;
					price[k] += remainder + '0';
					price2 /= 10;
				}

				while (price3 != 0) {
					int remainder1 = price3 % 10;
					quantity[k] += remainder1 + '0';
					price3 /= 10;
				}

				while (price4 != 0)
				{
					int remainder2 = price4 % 10;
					averating[k] += remainder2 + '0';
					price4 /= 10;
				}


				reverse(price[k].begin(), price[k].end());
				textprice[k].setString(price[k]);
				reverse(quantity[k].begin(), quantity[k].end());
				textquantity[k].setString(quantity[k]);
				reverse(averating[k].begin(), averating[k].end());
				textrating[k].setString(averating[k]);
				k++;
			}
		}
	}
	int cc, qq;
	bool more = false, nmore = false;
	int active = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 216 && localposition.x <= 273 && localposition.y >= 743 && localposition.y <= 774) {
					active = 1;
					cout << "nump" << endl;

				}
				else if (localposition.x >= 316 && localposition.x <= 402 && localposition.y >= 742 && localposition.y <= 776) {
					cout << "add" << endl;

					istringstream(c) >> cc;
					istringstream(q) >> qq;

					if (c.getSize() == 0 || q.getSize() == 0)
						type = true;

					if (c.getSize() == 0 || q.getSize() == 0)
						type = true;

					else  if (c.getSize() > 0 && q.getSize() > 0) {
						if (cc <= k) {
							Owners[0].Shops.products[2].Quantity;
							if (qq <= Owners[m.a[cc - 1]].Shops.products[m.b[cc - 1]].Quantity && qq != 0) {
								kk.sub[cv.index] = (qq * Owners[m.a[cc - 1]].Shops.products[m.b[cc - 1]].productPrice);
								kk.amount[cv.index] = qq;
								Owners[m.a[cc - 1]].Shops.products[m.b[cc - 1]].Quantity -= qq;
								kk.sav[cv.index].x = m.a[cc - 1];
								kk.sav[cv.index].y = m.b[cc - 1];
								cv.nump++;
								cv.index++;
								cout << qq << "  " << cc;

								for (int i = 1; i < 5; i++) {
									c.erase(c.getSize() - 1, c.getSize());
									textc.setString(c);
									if (c.getSize() == 0)
										break;
								}
								for (int i = 1; i < 5; i++) {
									q.erase(q.getSize() - 1, q.getSize());
									textq.setString(q);
									if (q.getSize() == 0)
										break;
								}
								type = false;
								more = false;
								nmore = false;

							}
							else {
								type = false;
								nmore = false;
								more = true;
							}
						}
						else {
							type = false;
							nmore = true;
							more = false;
						}
					}
				}
				else if (localposition.x >= 216 && localposition.x <= 270 && localposition.y >= 12 && localposition.y <= 741) {

					active = 2;
					cout << "quant" << endl;


				}

				else if (localposition.x >= 517 && localposition.x <= 652 && localposition.y >= 742 && localposition.y <= 779 && next == false) {
					next = true;
					cout << "next" << endl;

				}
				else if (localposition.x >= 661 && localposition.x <= 797 && localposition.y >= 742 && localposition.y <= 774 && next == true) {
					next = false;
					cout << "previous" << endl;

				}
				else if (localposition.x >= 808 && localposition.x <= 893 && localposition.y >= 747 && localposition.y <= 778) {

					cout << "back" << endl;
					prodmenu();
				}

				else
					active = 0;
			}

			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					c += event.text.unicode;
					textc.setString(c);
				}
				else if (active == 1 && event.text.unicode == 8 && c.getSize() > 0) {
					c.erase(c.getSize() - 1, c.getSize());
					textc.setString(c);
				}
				if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					q += event.text.unicode;
					textq.setString(q);
				}
				else if (active == 2 && event.text.unicode == 8 && q.getSize() > 0) {
					q.erase(q.getSize() - 1, q.getSize());
					textq.setString(q);
				}

			}
		}

		for (; n < k && n < 32; n++) {


			textname[n].setPosition(32, hi);
			textname[n].setFont(fontname);
			textname[n].setCharacterSize(20);
			textprice[n].setPosition(165, hi);
			textprice[n].setFont(fontprice);
			textprice[n].setCharacterSize(20);
			textquantity[n].setPosition(400, hi);
			textquantity[n].setFont(fontprice);
			textquantity[n].setCharacterSize(20);
			textrating[n].setPosition(510, hi);
			textrating[n].setFont(fontprice);
			textrating[n].setCharacterSize(20);
			textcate[n].setPosition(232, ho);
			textcate[n].setFont(fontprice);
			textcate[n].setCharacterSize(15);
			textsize[n].setPosition(620, hi);
			textsize[n].setFont(fontname);
			textsize[n].setCharacterSize(20);
			texttype[n].setPosition(720, hi);
			texttype[n].setFont(fontname);
			texttype[n].setCharacterSize(20);
			textcolor[n].setPosition(840, hi);
			textcolor[n].setFont(fontname);
			textcolor[n].setCharacterSize(20);
			textnum[n].setPosition(1, hi);
			textnum[n].setFont(fontnum);
			textnum[n].setCharacterSize(20);
			textp[n].setPosition(23, hi);
			textp[n].setFont(fontp);
			textp[n].setCharacterSize(20);
			hi += 20;
			ho += 20.2;

		}
		hi = 50, ho = 50;
		for (n = 32; n < k; n++) {


			textname[n].setPosition(32, hi);
			textname[n].setFont(fontname);
			textname[n].setCharacterSize(20);
			textprice[n].setPosition(165, hi);
			textprice[n].setFont(fontprice);
			textprice[n].setCharacterSize(20);
			textquantity[n].setPosition(400, hi);
			textquantity[n].setFont(fontprice);
			textquantity[n].setCharacterSize(20);
			textrating[n].setPosition(510, hi);
			textrating[n].setFont(fontprice);
			textrating[n].setCharacterSize(20);
			textcate[n].setPosition(232, ho);
			textcate[n].setFont(fontprice);
			textcate[n].setCharacterSize(15);
			textsize[n].setPosition(620, hi);
			textsize[n].setFont(fontname);
			textsize[n].setCharacterSize(20);
			texttype[n].setPosition(720, hi);
			texttype[n].setFont(fontname);
			texttype[n].setCharacterSize(20);
			textcolor[n].setPosition(840, hi);
			textcolor[n].setFont(fontname);
			textcolor[n].setCharacterSize(20);
			textnum[n].setPosition(1, hi);
			textnum[n].setFont(fontnum);
			textnum[n].setCharacterSize(20);
			textp[n].setPosition(23, hi);
			textp[n].setFont(fontp);
			textp[n].setCharacterSize(20);
			hi += 20;
			ho += 20.2;


		}

		window.draw(photo);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);
		window.draw(text8);
		window.draw(choice1);
		window.draw(choice2);
		window.draw(choice3);
		window.draw(choice4);
		window.draw(choice5);
		window.draw(choice6);
		window.draw(choice7);
		window.draw(choice8);

		window.draw(choice33);
		window.draw(textq);
		window.draw(text60);
		window.draw(choice20);
		window.draw(choice30);
		window.draw(choice30);

		window.draw(choice40);

		window.draw(text10);
		if (type)
			window.draw(text00);
		if (more)
			window.draw(text100);
		if (nmore)
			window.draw(text200);
		window.draw(text30);
		window.draw(text50);

		window.draw(textc);
		if (next == false) {
			window.draw(text20);
			window.draw(choice10);
			for (n = 0; n < 32; n++) {

				window.draw(textname[n]);
				window.draw(textprice[n]);
				window.draw(textcate[n]);
				window.draw(textquantity[n]);
				window.draw(textrating[n]);
				window.draw(textsize[n]);
				window.draw(texttype[n]);
				window.draw(textcolor[n]);
				window.draw(textnum[n]);
				window.draw(textp[n]);
			}
		}
		if (next) {
			window.draw(text40);
			window.draw(choice50);
			;
			for (n = 32; n < k; n++) {

				window.draw(textname[n]);
				window.draw(textprice[n]);
				window.draw(textcate[n]);
				window.draw(textquantity[n]);
				window.draw(textrating[k]);
				window.draw(textsize[n]);
				window.draw(texttype[n]);
				window.draw(textcolor[n]);
				window.draw(textnum[n]);
				window.draw(textp[n]);
			}
		}
		window.display();
	}
}

int viewproductsOwner() {

	int number = 1;
	int z = 0;
	float hi = 50;

	string price[10];
	string averating[10];
	string quantity[10];

	sf::String name;
	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textname[10];
	int k = 0, n = 0;

	sf::String cate;
	sf::Font fontcate;
	fontcate.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcate[10];

	sf::Font fontprice;
	fontprice.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textprice[10];

	sf::Font fontsize;
	fontsize.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textsize[10];

	sf::Font fontrating;
	fontrating.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textrating[10];

	sf::Font fontquantity;
	fontquantity.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textquantity[10];

	sf::Font fonttype;
	fonttype.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texttype[10];

	sf::Font fontcolor;
	fontcolor.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcolor[10];

	sf::RectangleShape choice1(sf::Vector2f(120.0f, 30.0f));
	choice1.setPosition(sf::Vector2f(12, 10));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineColor(sf::Color::Blue);
	choice1.setOutlineThickness(3);

	sf::RectangleShape choice4(sf::Vector2f(120.0f, 30.0f));
	choice4.setPosition(sf::Vector2f(273, 10));
	choice4.setFillColor(sf::Color::Transparent);
	choice4.setOutlineColor(sf::Color::Blue);
	choice4.setOutlineThickness(3);

	sf::RectangleShape choice5(sf::Vector2f(120.0f, 30.0f));
	choice5.setPosition(sf::Vector2f(403, 10));
	choice5.setFillColor(sf::Color::Transparent);
	choice5.setOutlineColor(sf::Color::Blue);
	choice5.setOutlineThickness(3);

	sf::RectangleShape choice2(sf::Vector2f(120.0f, 30.0f));
	choice2.setPosition(sf::Vector2f(143, 10));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineColor(sf::Color::Blue);
	choice2.setOutlineThickness(3);

	sf::RectangleShape choice6(sf::Vector2f(120.0f, 30.0f));
	choice6.setPosition(sf::Vector2f(533, 10));
	choice6.setFillColor(sf::Color::Transparent);
	choice6.setOutlineColor(sf::Color::Blue);
	choice6.setOutlineThickness(3);

	sf::RectangleShape choice7(sf::Vector2f(120.0f, 30.0f));
	choice7.setPosition(sf::Vector2f(663, 10));
	choice7.setFillColor(sf::Color::Transparent);
	choice7.setOutlineColor(sf::Color::Blue);
	choice7.setOutlineThickness(3);

	sf::RectangleShape choice8(sf::Vector2f(120.0f, 30.0f));
	choice8.setPosition(sf::Vector2f(793, 10));
	choice8.setFillColor(sf::Color::Transparent);
	choice8.setOutlineColor(sf::Color::Blue);
	choice8.setOutlineThickness(3);

	sf::RectangleShape choice40(sf::Vector2f(80.0f, 30.0f));
	choice40.setPosition(sf::Vector2f(812, 748));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::Red);
	choice40.setOutlineThickness(3);

	sf::Font fontc;
	fontc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String c;
	sf::Text textc(c, fontc, 25);
	textc.setFillColor(sf::Color::Black);
	textc.setPosition(215, 748);


	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" BACK ");
	text10.setCharacterSize(20);
	text10.setFillColor(sf::Color::Red);
	text10.setPosition(820, 750);
	text10.setStyle(sf::Text::Bold);

	sf::Font font1;
	font1.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text1;
	text1.setFont(font1);
	text1.setString("     NAME ");
	text1.setCharacterSize(22);
	text1.setFillColor(sf::Color::Blue);
	text1.setPosition(14, 10);
	text1.setStyle(sf::Text::Bold);

	sf::Font font2;
	font2.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text2;
	text2.setFont(font2);
	text2.setString("  PRICE ");
	text2.setCharacterSize(22);
	text2.setFillColor(sf::Color::Blue);
	text2.setPosition(160, 10);
	text2.setStyle(sf::Text::Bold);

	sf::Font font4;
	font4.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text4;
	text4.setFont(font4);
	text4.setString("  QUANTITY ");
	text4.setCharacterSize(22);
	text4.setFillColor(sf::Color::Blue);
	text4.setPosition(265, 10);
	text4.setStyle(sf::Text::Bold);

	sf::Font font5;
	font5.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text5;
	text5.setFont(font5);
	text5.setString("  RATING ");
	text5.setCharacterSize(22);
	text5.setFillColor(sf::Color::Blue);
	text5.setPosition(411, 10);
	text5.setStyle(sf::Text::Bold);

	sf::Font font6;
	font6.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text6;
	text6.setFont(font6);
	text6.setString(" SIZE ");
	text6.setCharacterSize(22);
	text6.setFillColor(sf::Color::Blue);
	text6.setPosition(560, 10);
	text6.setStyle(sf::Text::Bold);

	sf::Font font7;
	font7.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text7;
	text7.setFont(font7);
	text7.setString(" TYPE ");
	text7.setCharacterSize(22);
	text7.setFillColor(sf::Color::Blue);
	text7.setPosition(690, 10);
	text7.setStyle(sf::Text::Bold);

	sf::Font font8;
	font8.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text8;
	text8.setFont(font8);
	text8.setString(" COLOR ");
	text8.setCharacterSize(22);
	text8.setFillColor(sf::Color::Blue);
	text8.setPosition(810, 10);
	text8.setStyle(sf::Text::Bold);
	k = 0, n = 0;

	for (int j = 0; j < maxProds; j++) {
		if (Owners[LogIndex].Shops.products[j].productPrice != 0) {
			textname[k].setString(Owners[LogIndex].Shops.products[j].productName);
			textsize[k].setString(Owners[LogIndex].Shops.products[j].Clothes.Size);
			texttype[k].setString(Owners[LogIndex].Shops.products[j].Clothes.Type);
			textcolor[k].setString(Owners[LogIndex].Shops.products[j].Clothes.Color);
			n++;
			k++;
		}
	}

	k = 0, n = 0;

	for (int j = 0; j < maxProds; j++) {
		if (Owners[LogIndex].Shops.products[j].productPrice != 0) {
			long long price2 = Owners[LogIndex].Shops.products[j].productPrice;
			long long price3 = Owners[LogIndex].Shops.products[j].Quantity;
			long long price4 = Owners[LogIndex].Shops.products[j].avgRating;

			while (price2 != 0) {
				int remainder = price2 % 10;
				price[k] += remainder + '0';
				price2 /= 10;
			}
			while (price3 != 0) {
				int remainder1 = price3 % 10;
				quantity[k] += remainder1 + '0';
				price3 /= 10;
			}
			while (price4 != 0)
			{
				int remainder2 = price4 % 10;
				averating[k] += remainder2 + '0';
				price4 /= 10;
			}

			reverse(price[k].begin(), price[k].end());
			textprice[k].setString(price[k]);
			reverse(quantity[k].begin(), quantity[k].end());
			textquantity[k].setString(quantity[k]);
			reverse(averating[k].begin(), averating[k].end());
			textrating[k].setString(averating[k]);
			n++;
			k++;
		}
	}

	k = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 810 && localposition.x <= 895 && localposition.y >= 749 && localposition.y <= 780) {

					cout << "back" << endl;
					return 0;

				}

			}

		}

		for (; k < n; k++) {


			textname[k].setPosition(5, hi);
			textname[k].setFont(fontname);
			textname[k].setCharacterSize(20);
			textprice[k].setPosition(150, hi);
			textprice[k].setFont(fontprice);
			textprice[k].setCharacterSize(20);
			textquantity[k].setPosition(320, hi);
			textquantity[k].setFont(fontprice);
			textquantity[k].setCharacterSize(20);
			textrating[k].setPosition(510, hi);
			textrating[k].setFont(fontprice);
			textrating[k].setCharacterSize(20);
			textsize[k].setPosition(580, hi);
			textsize[k].setFont(fontname);
			textsize[k].setCharacterSize(20);
			texttype[k].setPosition(720, hi);
			texttype[k].setFont(fontname);
			texttype[k].setCharacterSize(20);
			textcolor[k].setPosition(840, hi);
			textcolor[k].setFont(fontname);
			textcolor[k].setCharacterSize(20);
			hi += 20;

		}

		window.draw(photo);
		window.draw(text1);
		window.draw(text2);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);
		window.draw(text8);
		window.draw(choice1);
		window.draw(choice2);
		window.draw(choice4);
		window.draw(choice5);
		window.draw(choice6);
		window.draw(choice7);
		window.draw(choice8);
		window.draw(choice40);
		window.draw(text10);
		window.draw(textc);

		k = 0;
		for (; k < n; k++) {

			window.draw(textname[k]);
			window.draw(textprice[k]);
			window.draw(textquantity[k]);
			window.draw(textrating[k]);
			window.draw(textsize[k]);
			window.draw(texttype[k]);
			window.draw(textcolor[k]);
		}

		window.display();
	}
}

int editprod() {


	sf::RectangleShape choice1(sf::Vector2f(330.0f, 40.0f));
	choice1.setPosition(sf::Vector2f(250, 20));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(3);

	sf::RectangleShape choice2(sf::Vector2f(330.0f, 40.0f));
	choice2.setPosition(sf::Vector2f(250, 130));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineColor(sf::Color::White);
	choice2.setOutlineThickness(3);

	sf::RectangleShape choice4(sf::Vector2f(330.0f, 40.0f));
	choice4.setPosition(sf::Vector2f(250, 250));
	choice4.setFillColor(sf::Color::Transparent);
	choice4.setOutlineColor(sf::Color::White);
	choice4.setOutlineThickness(3);

	sf::RectangleShape choicename(sf::Vector2f(330.0f, 22.0f));
	choicename.setPosition(sf::Vector2f(230, 88));
	choicename.setFillColor(sf::Color::White);
	choicename.setOutlineColor(sf::Color::White);
	choicename.setOutlineThickness(3);

	sf::RectangleShape choiceprice(sf::Vector2f(330.0f, 22.0f));
	choiceprice.setPosition(sf::Vector2f(230, 195));
	choiceprice.setFillColor(sf::Color::White);
	choiceprice.setOutlineColor(sf::Color::White);
	choiceprice.setOutlineThickness(3);

	sf::RectangleShape choiceq(sf::Vector2f(330.0f, 22.0f));
	choiceq.setPosition(sf::Vector2f(230, 320));
	choiceq.setFillColor(sf::Color::White);
	choiceq.setOutlineColor(sf::Color::White);
	choiceq.setOutlineThickness(3);

	sf::RectangleShape choicesave(sf::Vector2f(100.0f, 22.0f));
	choicesave.setPosition(sf::Vector2f(685, 20));
	choicesave.setFillColor(sf::Color::Transparent);
	choicesave.setOutlineColor(sf::Color::Red);
	choicesave.setOutlineThickness(3);

	sf::RectangleShape choiceb(sf::Vector2f(100.0f, 22.0f));
	choiceb.setPosition(sf::Vector2f(685, 60));
	choiceb.setFillColor(sf::Color::Transparent);
	choiceb.setOutlineColor(sf::Color::Red);
	choiceb.setOutlineThickness(3);

	sf::RectangleShape choiceSearch(sf::Vector2f(350.0f, 40.0f));
	choiceSearch.setPosition(sf::Vector2f(350, 460));
	choiceSearch.setFillColor(sf::Color::White);
	choiceSearch.setOutlineColor(sf::Color::White);
	choiceSearch.setOutlineThickness(3);

	sf::Font fontquantity;
	fontquantity.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String quantity;
	sf::Text textquantity(quantity, fontquantity, 25);
	textquantity.setFillColor(sf::Color::Black);
	textquantity.setPosition(230, 315);

	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String name;
	sf::Text textname(name, fontname, 25);
	textname.setFillColor(sf::Color::Black);
	textname.setPosition(230, 83);

	sf::Font fontprice;
	fontprice.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String price;
	sf::Text textprice(price, fontprice, 30);
	textprice.setFillColor(sf::Color::Black);
	textprice.setPosition(230, 185);

	sf::Font fontsearchname;
	fontsearchname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String searchname;
	sf::Text textsearchname(searchname, fontsearchname, 30);
	textsearchname.setFillColor(sf::Color::Black);
	textsearchname.setPosition(355, 460);

	sf::Font font0;
	font0.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text0;
	text0.setFont(font0);
	text0.setString(" Save ");
	text0.setCharacterSize(20);
	text0.setFillColor(sf::Color::Red);
	text0.setPosition(708, 18);
	text0.setStyle(sf::Text::Bold);

	sf::Font font01;
	font01.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text01;
	text01.setFont(font01);
	text01.setString(" Back ");
	text01.setCharacterSize(20);
	text01.setFillColor(sf::Color::Red);
	text01.setPosition(708, 58);
	text01.setStyle(sf::Text::Bold);



	sf::Font font1;
	font1.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text1;
	text1.setFont(font1);
	text1.setString(" Edit Name ");
	text1.setCharacterSize(30);
	text1.setFillColor(sf::Color::White);
	text1.setPosition(325, 20);
	text1.setStyle(sf::Text::Bold);

	sf::Font font2;
	font2.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text2;
	text2.setFont(font2);
	text2.setString("     Edit Price ");
	text2.setCharacterSize(30);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(305, 130);
	text2.setStyle(sf::Text::Bold);

	sf::Font font4;
	font4.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text4;
	text4.setFont(font4);
	text4.setString("Edit Quantity ");
	text4.setCharacterSize(30);
	text4.setFillColor(sf::Color::White);
	text4.setPosition(330, 250);
	text4.setStyle(sf::Text::Bold);



	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" New Name     : ");
	text10.setCharacterSize(30);
	text10.setFillColor(sf::Color::White);
	text10.setPosition(10, 80);
	text10.setStyle(sf::Text::Bold);

	sf::Font font30;
	font30.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text30;
	text30.setFont(font30);
	text30.setString(" New Price      : ");
	text30.setCharacterSize(30);
	text30.setFillColor(sf::Color::White);
	text30.setPosition(10, 185);
	text30.setStyle(sf::Text::Bold);

	sf::Font font50;
	font50.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text50;
	text50.setFont(font50);
	text50.setString(" New Quantity : ");
	text50.setCharacterSize(30);
	text50.setFillColor(sf::Color::White);
	text50.setPosition(10, 310);
	text50.setStyle(sf::Text::Bold);

	sf::Font font70;
	font70.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text70;
	text70.setFont(font70);
	text70.setString("Product's Name      : ");
	text70.setCharacterSize(35);
	text70.setFillColor(sf::Color::White);
	text70.setPosition(30, 460);
	text70.setStyle(sf::Text::Bold);

	sf::Font font80;
	font80.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text80;
	text80.setFont(font80);
	text80.setString("  --The Product is not available--      ");
	text80.setCharacterSize(35);
	text80.setFillColor(sf::Color::White);
	text80.setPosition(100, 520);
	text80.setStyle(sf::Text::Bold);


	bool bname = false;
	bool bprice = false;
	bool bquantity = false;
	bool flag = false, flag2 = false, flag3 = false;
	bool searchflag1 = false, searchflag2 = false;

	int active = 0, intprice, intquantity;


	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 247 && localposition.x <= 583 && localposition.y >= 7 && localposition.y <= 52) {
					cout << "edit name " << endl;
					bname = true;
				}
				else if (localposition.x >= 227 && localposition.x <= 566 && localposition.y >= 85 && localposition.y <= 111 && bname) {
					cout << "new name" << endl;
					active = 1;
					flag = true;
				}
				else if (localposition.x >= 683 && localposition.x <= 786 && localposition.y >= 59 && localposition.y <= 84) {
					cout << "Back" << endl;
					return 0;
				}
				else if (localposition.x >= 683 && localposition.x <= 786 && localposition.y >= 18 && localposition.y <= 49 && (price.getSize() > 0 || name.getSize() > 0 || quantity.getSize() > 0)) {
					cout << "save" << endl;
					istringstream(price) >> intprice;
					istringstream(quantity) >> intquantity;

					for (int i = 0; i < maxProds; i++)
					{
						if (Owners[LogID].Shops.products[i].productName == searchname)
						{
							searchflag1 = true;
							editprods(LogID, flag, flag2, flag3, name, intprice, intquantity, searchname);
							prodchoice();
						}
						if (searchflag1 == false) {
							searchflag2 = true;
						}
					}


				}
				else if (localposition.x >= 246 && localposition.x <= 582 && localposition.y >= 127 && localposition.y <= 172) {
					cout << "edit price" << endl;
					bprice = true;

				}

				else if (localposition.x >= 227 && localposition.x <= 566 && localposition.y >= 190 && localposition.y <= 217 && bprice) {
					cout << "new price" << endl;
					active = 2;
					flag2 = true;
				}

				else if (localposition.x >= 247 && localposition.x <= 583 && localposition.y >= 247 && localposition.y <= 293) {
					cout << "edit qunatity" << endl;
					bquantity = true;

				}
				else if (localposition.x >= 227 && localposition.x <= 556 && localposition.y >= 317 && localposition.y <= 344 && bquantity) {
					cout << "new quantity" << endl;
					active = 3;
					flag3 = true;
				}
				else if (localposition.x >= 350 && localposition.x <= 700 && localposition.y >= 460 && localposition.y <= 495) {
					cout << "search Name" << endl;
					active = 4;

				}
				else
					active = 0;


			}
			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					name += event.text.unicode;
					textname.setString(name);
				}
				else if (active == 1 && event.text.unicode == 8 && name.getSize() > 0)
				{
					name.erase(name.getSize() - 1, name.getSize());
					textname.setString(name);
				}
				if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					price += event.text.unicode;
					textprice.setString(price);

				}
				else if (active == 2 && event.text.unicode == 8 && price.getSize() > 0) {
					price.erase(price.getSize() - 1, price.getSize());
					textprice.setString(price);
				}
				if (active == 4 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {

					searchname += event.text.unicode;
					textsearchname.setString(searchname);
				}
				else if (active == 4 && event.text.unicode == 8 && searchname.getSize() > 0) {
					searchname.erase(searchname.getSize() - 1, searchname.getSize());
					textsearchname.setString(searchname);
				}
				if (active == 3 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {

					quantity += event.text.unicode;
					textquantity.setString(quantity);
				}
				else if (active == 3 && event.text.unicode == 8 && quantity.getSize() > 0) {
					quantity.erase(quantity.getSize() - 1, quantity.getSize());
					textquantity.setString(quantity);
				}
			}
		}

		window.clear();
		window.draw(photo);
		window.draw(text1);
		window.draw(text2);
		window.draw(text4);
		window.draw(choice1);
		window.draw(choice2);
		window.draw(choice4);
		window.draw(text0);
		window.draw(text01);
		window.draw(choicesave);
		window.draw(choiceb);
		window.draw(text70);
		window.draw(choiceSearch);
		window.draw(textsearchname);

		if (bname) {

			window.draw(choicename);
			window.draw(text10);
			window.draw(textname);
		}
		if (bprice) {

			window.draw(text30);
			window.draw(choiceprice);
			window.draw(textprice);
		}
		if (bquantity) {

			window.draw(text50);
			window.draw(choiceq);
			window.draw(textquantity);
		}
		if (searchflag2) {
			window.draw(text80);
		}

		window.display();
	}
}

void deleteOwner() {


	sf::RectangleShape choice1(sf::Vector2f(100.0f, 70.0f));
	choice1.setPosition(sf::Vector2f(250, 400));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(3);

	sf::RectangleShape choice2(sf::Vector2f(100.0f, 70.0f));
	choice2.setPosition(sf::Vector2f(600, 400));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineColor(sf::Color::White);
	choice2.setOutlineThickness(3);

	sf::Font font1;
	font1.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text1;
	text1.setFont(font1);
	text1.setString(" Do You Want To Delete Your Account  ?");
	text1.setCharacterSize(40);
	text1.setFillColor(sf::Color::White);
	text1.setPosition(100, 250);
	text1.setStyle(sf::Text::Bold);

	sf::Font font2;
	font2.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text2;
	text2.setFont(font2);
	text2.setString(" YES ");
	text2.setCharacterSize(40);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(255, 410);
	text2.setStyle(sf::Text::Bold);

	sf::Font font3;
	font3.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text3;
	text3.setFont(font3);
	text3.setString(" NO ");
	text3.setCharacterSize(40);
	text3.setFillColor(sf::Color::White);
	text3.setPosition(610, 410);
	text3.setStyle(sf::Text::Bold);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 245 && localposition.x <= 352 && localposition.y >= 395 && localposition.y <= 471) {
					removeReg(LogIndex);
					save();
					welcome();
					cout << "YES " << endl;

				}

				else if (localposition.x >= 597 && localposition.x <= 702 && localposition.y >= 397 && localposition.y <= 472) {
					homepageOwner();
					cout << "NO" << endl;

				}
			}
		}

		window.clear();
		window.draw(photo);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(choice1);
		window.draw(choice2);
		window.display();
	}


}

void deleteshopper() {


	sf::RectangleShape choice1(sf::Vector2f(100.0f, 70.0f));
	choice1.setPosition(sf::Vector2f(250, 400));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(3);

	sf::RectangleShape choice2(sf::Vector2f(100.0f, 70.0f));
	choice2.setPosition(sf::Vector2f(600, 400));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineColor(sf::Color::White);
	choice2.setOutlineThickness(3);

	sf::Font font1;
	font1.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text1;
	text1.setFont(font1);
	text1.setString(" Do You Want To Delete Your Account  ?");
	text1.setCharacterSize(40);
	text1.setFillColor(sf::Color::White);
	text1.setPosition(100, 250);
	text1.setStyle(sf::Text::Bold);

	sf::Font font2;
	font2.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text2;
	text2.setFont(font2);
	text2.setString(" YES ");
	text2.setCharacterSize(40);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(255, 410);
	text2.setStyle(sf::Text::Bold);

	sf::Font font3;
	font3.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text3;
	text3.setFont(font3);
	text3.setString(" NO ");
	text3.setCharacterSize(40);
	text3.setFillColor(sf::Color::White);
	text3.setPosition(610, 410);
	text3.setStyle(sf::Text::Bold);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 245 && localposition.x <= 352 && localposition.y >= 395 && localposition.y <= 471) {
					del(LogIndex);
					save();
					welcome();
					cout << "YES " << endl;

				}
				else if (localposition.x >= 597 && localposition.x <= 702 && localposition.y >= 397 && localposition.y <= 472) {
					scchoice();
					cout << "NO" << endl;



				}
			}
		}

		window.clear();
		window.draw(photo);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(choice1);
		window.draw(choice2);
		window.display();
	}


}

int receipt(int ind) {

	int  a[75];
	float hi = 50;
	int k = 0, n = 0;


	string nump[75];
	string price[75];
	string quantity[75];
	string f;

	sf::String p;
	sf::Font fontp;
	fontp.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textp[75];


	sf::Font fontt;
	fontt.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textt;
	textt.setPosition(200, 700);
	textt.setFont(fontt);
	textt.setCharacterSize(25);

	sf::String name;
	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textname[75];

	sf::String num;
	sf::Font fontnum;
	fontnum.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textnum[75];

	sf::Font fontprice;
	fontprice.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textprice[75];

	sf::Font fontquantity;
	fontquantity.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textquantity[75];

	sf::RectangleShape choice1(sf::Vector2f(200.0f, 30.0f));
	choice1.setPosition(sf::Vector2f(100, 10));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(3);

	sf::RectangleShape choice2(sf::Vector2f(200.0f, 30.0f));
	choice2.setPosition(sf::Vector2f(400, 10));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineColor(sf::Color::White);
	choice2.setOutlineThickness(3);

	sf::RectangleShape choice4(sf::Vector2f(200.0f, 30.0f));
	choice4.setPosition(sf::Vector2f(700, 10));
	choice4.setFillColor(sf::Color::Transparent);
	choice4.setOutlineColor(sf::Color::White);
	choice4.setOutlineThickness(3);

	sf::RectangleShape choice40(sf::Vector2f(80.0f, 30.0f));
	choice40.setPosition(sf::Vector2f(812, 748));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::Red);
	choice40.setOutlineThickness(3);

	sf::RectangleShape choice50(sf::Vector2f(110.0f, 30.0f));
	choice50.setPosition(sf::Vector2f(692, 748));
	choice50.setFillColor(sf::Color::Transparent);
	choice50.setOutlineColor(sf::Color::Red);
	choice50.setOutlineThickness(3);

	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" DONE ");
	text10.setCharacterSize(20);
	text10.setFillColor(sf::Color::Red);
	text10.setPosition(820, 750);
	text10.setStyle(sf::Text::Bold);

	sf::Font font00;
	font00.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text00;
	text00.setFont(font00);
	text00.setString("   RATE ");
	text00.setCharacterSize(20);
	text00.setFillColor(sf::Color::Red);
	text00.setPosition(700, 750);
	text00.setStyle(sf::Text::Bold);

	sf::Font font60;
	font60.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text60;
	text60.setFont(font60);
	text60.setString("  Total price :  ");
	text60.setCharacterSize(25);
	text60.setFillColor(sf::Color::White);
	text60.setPosition(20, 700);
	text60.setStyle(sf::Text::Bold);

	sf::Font font1;
	font1.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text1;
	text1.setFont(font1);
	text1.setString(" NAME ");
	text1.setCharacterSize(22);
	text1.setFillColor(sf::Color::White);
	text1.setPosition(150, 10);
	text1.setStyle(sf::Text::Bold);

	sf::Font font2;
	font2.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text2;
	text2.setFont(font2);
	text2.setString(" PRICE ");
	text2.setCharacterSize(22);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(450, 10);
	text2.setStyle(sf::Text::Bold);

	sf::Font font4;
	font4.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text4;
	text4.setFont(font4);
	text4.setString("  QUANTITY ");
	text4.setCharacterSize(19);
	text4.setFillColor(sf::Color::White);
	text4.setPosition(740, 13);
	text4.setStyle(sf::Text::Bold);


	k = 0, n = 0;
	int total = 0;
	for (int i = 0; i < cv.nump; i++) {

		shopperCart[i].buyproduct = Owners[kk.sav[i].x].Shops.products[kk.sav[i].y].productName;
		shopperCart[i].price = Owners[kk.sav[i].x].Shops.products[kk.sav[i].y].productPrice;
		shopperCart[i].quantity = kk.amount[i];

	}
	for (int i = 0; i < cv.nump; i++) {
		shopperCart[i].subtotal = (shopperCart[i].quantity * shopperCart[i].price);
		total += shopperCart[i].subtotal;

	}

	long long tot = total;

	if (tot == 0) {
		f = "0";
		textt.setString(f);
	}
	else
	{
		while (tot != 0)
		{
			int j = tot % 10;
			f += j + '0';
			tot /= 10;
		}

		reverse(f.begin(), f.end());
		textt.setString(f);
	}


	for (int i = 0; i < cv.nump; i++) {

		if (kk.amount[i] != 0) {
			textname[k].setString(shopperCart[i].buyproduct);
			textp[k].setString(") ");
			k++;
		}
	}

	k = 0;
	for (int i = 0; i < 20; i++) {
		a[i] = i + 1;
	}

	for (int i = 0; i < 20; i++) {
		long long price1 = a[i];
		while (price1 != 0)
		{
			int m = price1 % 10;
			nump[i] += m + '0';
			price1 /= 10;
		}
		reverse(nump[i].begin(), nump[i].end());
		textnum[i].setString(nump[i]);
	}
	for (int i = 0; i < cv.nump; i++) {

		if (kk.amount[i] != 0) {

			long long price2 = shopperCart[i].price;
			long long price3 = shopperCart[i].quantity;

			while (price2 != 0) {
				int remainder = price2 % 10;
				price[i] += remainder + '0';
				price2 /= 10;
			}
			while (price3 != 0) {
				int remainder1 = price3 % 10;
				quantity[i] += remainder1 + '0';
				price3 /= 10;
			}

			reverse(price[i].begin(), price[i].end());
			textprice[k].setString(price[i]);
			reverse(quantity[i].begin(), quantity[i].end());
			textquantity[k].setString(quantity[i]);
			k++;
		}
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;

				if (localposition.x >= 808 && localposition.x <= 893 && localposition.y >= 747 && localposition.y <= 778) {
					//purchase history

					for (int i = 0; i > cv.nump; i++) {
						kk.sav[i].x = 0;
						kk.sav[i].y = 0;
						kk.sub[i] = 0;
						kk.amount[i] = 0;
						shopperCart[i].buyproduct = { 0 };
						shopperCart[i].price = 0;
						shopperCart[i].quantity = 0;
						shopperCart[i].subtotal = 1;
					}

					cv.index = 0;
					cv.nump = 0;

					Shoppers[LogID].purchases++;
					while (true) {
						int i = 0;
						if (Shoppers[LogID].purchaseHistory[9] == 0) {
							if (Shoppers[LogID].purchaseHistory[i] == 0) {
								Shoppers[LogID].purchaseHistory[i] = total;
								Shoppers[LogID].days[i] = day;
								Shoppers[LogID].months[i] = month;
								break;
							}
						}
						else {
							for (int j = 0; j < 10; j++) {
								Shoppers[LogID].purchaseHistory[j] = Shoppers[LogID].purchaseHistory[j + 1];
								Shoppers[LogID].days[j] = Shoppers[LogID].days[j + 1];
								Shoppers[LogID].months[j] = Shoppers[LogID].months[j + 1];
							}
							Shoppers[LogID].purchaseHistory[9] = total;
							Shoppers[LogID].days[9] = day;
							Shoppers[LogID].months[9] = month;
							break;
						}
						i++;
					}

					return 0;
					cout << "back" << endl;

				}
				else if (localposition.x >= 687 && localposition.x <= 805 && localposition.y >= 744 && localposition.y <= 779) {
					rating();
					cout << "Rate" << endl;

				}

			}
		}

		for (; n < cv.nump; n++) {


			textname[n].setPosition(150, hi);
			textname[n].setFont(fontname);
			textname[n].setCharacterSize(20);
			textprice[n].setPosition(490, hi);
			textprice[n].setFont(fontprice);
			textprice[n].setCharacterSize(20);
			textquantity[n].setPosition(800, hi);
			textquantity[n].setFont(fontprice);
			textquantity[n].setCharacterSize(20);
			textnum[n].setPosition(1, hi);
			textnum[n].setFont(fontnum);
			textnum[n].setCharacterSize(20);
			textp[n].setPosition(25, hi);
			textp[n].setFont(fontp);
			textp[n].setCharacterSize(18);
			hi += 30;

		}

		window.draw(photo);
		window.draw(text60);
		window.draw(textt);
		window.draw(text1);
		window.draw(text2);
		window.draw(text4);
		window.draw(text00);
		window.draw(choice1);
		window.draw(choice2);
		window.draw(choice4);
		window.draw(choice40);
		window.draw(choice50);
		window.draw(text10);


		for (n = 0; n < cv.nump; n++) {

			window.draw(textname[n]);
			window.draw(textprice[n]);
			window.draw(textquantity[n]);
			window.draw(textnum[n]);
			window.draw(textp[n]);
		}



		window.draw(textt);
		window.display();
	}

}

int cart() {

	int number = 1, a[75];
	int z = 0;
	float hi = 50, ho = 50;
	bool next = false;

	bool type = false;
	int k = 0, n = 0;


	string nump[75];
	string price[75];
	string averating[75];
	string quantity[75];
	string f;

	sf::String p;
	sf::Font fontp;
	fontp.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textp[75];


	sf::Font fontt;
	fontt.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textt;
	textt.setPosition(200, 700);
	textt.setFont(fontt);
	textt.setCharacterSize(25);

	sf::String name;
	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textname[75];


	sf::String num;
	sf::Font fontnum;
	fontnum.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textnum[75];

	sf::String cate;
	sf::Font fontcate;
	fontcate.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcate[75];

	sf::Font fontprice;
	fontprice.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textprice[75];

	sf::Font fontsize;
	fontsize.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textsize[75];

	sf::Font fontrating;
	fontrating.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textrating[75];

	sf::Font fontquantity;
	fontquantity.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textquantity[75];

	sf::Font fonttype;
	fonttype.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texttype[75];

	sf::Font fontcolor;
	fontcolor.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcolor[75];

	sf::RectangleShape choice1(sf::Vector2f(100.0f, 30.0f));
	choice1.setPosition(sf::Vector2f(5, 10));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(3);

	sf::RectangleShape choice2(sf::Vector2f(100.0f, 30.0f));
	choice2.setPosition(sf::Vector2f(120, 10));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineColor(sf::Color::White);
	choice2.setOutlineThickness(3);

	sf::RectangleShape choice3(sf::Vector2f(100.0f, 30.0f));
	choice3.setPosition(sf::Vector2f(235, 10));
	choice3.setFillColor(sf::Color::Transparent);
	choice3.setOutlineColor(sf::Color::White);
	choice3.setOutlineThickness(3);

	sf::RectangleShape choice4(sf::Vector2f(100.0f, 30.0f));
	choice4.setPosition(sf::Vector2f(350, 10));
	choice4.setFillColor(sf::Color::Transparent);
	choice4.setOutlineColor(sf::Color::White);
	choice4.setOutlineThickness(3);

	sf::RectangleShape choice5(sf::Vector2f(100.0f, 30.0f));
	choice5.setPosition(sf::Vector2f(465, 10));
	choice5.setFillColor(sf::Color::Transparent);
	choice5.setOutlineColor(sf::Color::White);
	choice5.setOutlineThickness(3);

	sf::RectangleShape choice6(sf::Vector2f(100.0f, 30.0f));
	choice6.setPosition(sf::Vector2f(580, 10));
	choice6.setFillColor(sf::Color::Transparent);
	choice6.setOutlineColor(sf::Color::White);
	choice6.setOutlineThickness(3);

	sf::RectangleShape choice7(sf::Vector2f(100.0f, 30.0f));
	choice7.setPosition(sf::Vector2f(695, 10));
	choice7.setFillColor(sf::Color::Transparent);
	choice7.setOutlineColor(sf::Color::White);
	choice7.setOutlineThickness(3);

	sf::RectangleShape choice8(sf::Vector2f(100.0f, 30.0f));
	choice8.setPosition(sf::Vector2f(810, 10));
	choice8.setFillColor(sf::Color::Transparent);
	choice8.setOutlineColor(sf::Color::White);
	choice8.setOutlineThickness(3);

	sf::RectangleShape choice20(sf::Vector2f(80.0f, 30.0f));
	choice20.setPosition(sf::Vector2f(320, 745));
	choice20.setFillColor(sf::Color::Transparent);
	choice20.setOutlineColor(sf::Color::White);
	choice20.setOutlineThickness(3);

	sf::RectangleShape choice30(sf::Vector2f(50.0f, 25.0f));
	choice30.setPosition(sf::Vector2f(220, 748));
	choice30.setFillColor(sf::Color::White);
	choice30.setOutlineColor(sf::Color::White);
	choice30.setOutlineThickness(3);

	sf::RectangleShape choice40(sf::Vector2f(80.0f, 30.0f));
	choice40.setPosition(sf::Vector2f(812, 748));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::Red);
	choice40.setOutlineThickness(3);

	sf::RectangleShape choice50(sf::Vector2f(110.0f, 30.0f));
	choice50.setPosition(sf::Vector2f(692, 748));
	choice50.setFillColor(sf::Color::Transparent);
	choice50.setOutlineColor(sf::Color::Red);
	choice50.setOutlineThickness(3);

	sf::Font fontc;
	fontc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String c;
	sf::Text textc(c, fontc, 25);
	textc.setFillColor(sf::Color::Black);
	textc.setPosition(218, 743);


	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" BACK ");
	text10.setCharacterSize(20);
	text10.setFillColor(sf::Color::Red);
	text10.setPosition(820, 750);
	text10.setStyle(sf::Text::Bold);

	sf::Font font00;
	font00.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text00;
	text00.setFont(font00);
	text00.setString(" RECEIPT ");
	text00.setCharacterSize(20);
	text00.setFillColor(sf::Color::Red);
	text00.setPosition(700, 750);
	text00.setStyle(sf::Text::Bold);


	sf::Font font30;
	font30.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text30;
	text30.setFont(font30);
	text30.setString(" DEL ");
	text30.setCharacterSize(22);
	text30.setFillColor(sf::Color::White);
	text30.setPosition(330, 745);
	text30.setStyle(sf::Text::Bold);

	sf::Font font40;
	font40.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text40;
	text40.setFont(font30);
	text40.setString("** Please Choose Number **");
	text40.setCharacterSize(22);
	text40.setFillColor(sf::Color::White);
	text40.setPosition(450, 700);
	text40.setStyle(sf::Text::Bold);

	sf::Font font50;
	font50.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text50;
	text50.setFont(font50);
	text50.setString("  Delete number :  ");
	text50.setCharacterSize(22);
	text50.setFillColor(sf::Color::White);
	text50.setPosition(20, 748);
	text50.setStyle(sf::Text::Bold);

	sf::Font font60;
	font60.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text60;
	text60.setFont(font60);
	text60.setString("  Total price :  ");
	text60.setCharacterSize(25);
	text60.setFillColor(sf::Color::White);
	text60.setPosition(20, 700);
	text60.setStyle(sf::Text::Bold);

	sf::Font font1;
	font1.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text1;
	text1.setFont(font1);
	text1.setString(" NAME ");
	text1.setCharacterSize(22);
	text1.setFillColor(sf::Color::White);
	text1.setPosition(14, 10);
	text1.setStyle(sf::Text::Bold);

	sf::Font font2;
	font2.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text2;
	text2.setFont(font2);
	text2.setString(" PRICE ");
	text2.setCharacterSize(22);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(130, 10);
	text2.setStyle(sf::Text::Bold);

	sf::Font font3;
	font3.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text3;
	text3.setFont(font3);
	text3.setString(" CATEGORY  ");
	text3.setCharacterSize(18);
	text3.setFillColor(sf::Color::White);
	text3.setPosition(232, 14);
	text3.setStyle(sf::Text::Bold);

	sf::Font font4;
	font4.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text4;
	text4.setFont(font4);
	text4.setString("  QUANTITY ");
	text4.setCharacterSize(19);
	text4.setFillColor(sf::Color::White);
	text4.setPosition(340, 13);
	text4.setStyle(sf::Text::Bold);

	sf::Font font5;
	font5.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text5;
	text5.setFont(font5);
	text5.setString("  RATING ");
	text5.setCharacterSize(21);
	text5.setFillColor(sf::Color::White);
	text5.setPosition(461, 11);
	text5.setStyle(sf::Text::Bold);

	sf::Font font6;
	font6.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text6;
	text6.setFont(font6);
	text6.setString(" SIZE ");
	text6.setCharacterSize(22);
	text6.setFillColor(sf::Color::White);
	text6.setPosition(598, 10);
	text6.setStyle(sf::Text::Bold);

	sf::Font font7;
	font7.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text7;
	text7.setFont(font7);
	text7.setString(" TYPE ");
	text7.setCharacterSize(22);
	text7.setFillColor(sf::Color::White);
	text7.setPosition(710, 10);
	text7.setStyle(sf::Text::Bold);

	sf::Font font8;
	font8.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text8;
	text8.setFont(font8);
	text8.setString(" COLOR ");
	text8.setCharacterSize(22);
	text8.setFillColor(sf::Color::White);
	text8.setPosition(820, 10);
	text8.setStyle(sf::Text::Bold);
	k = 0, n = 0;
	int total = 0;
	for (int i = 0; i < cv.nump; i++) {
		total += kk.sub[i];
	}

	long long tot = total;

	if (tot == 0) {
		f = "0";
		textt.setString(f);
	}
	else
	{
		while (tot != 0)
		{
			int j = tot % 10;
			f += j + '0';
			tot /= 10;
		}

		reverse(f.begin(), f.end());
		textt.setString(f);
	}


	for (int i = 0; i < cv.nump; i++) {

		if (kk.amount[i] != 0) {
			textname[k].setString(Owners[kk.sav[i].x].Shops.products[kk.sav[i].y].productName);
			textcate[k].setString(Owners[kk.sav[i].x].Shops.products[kk.sav[i].y].Category);
			textsize[k].setString(Owners[kk.sav[i].x].Shops.products[kk.sav[i].y].Clothes.Size);
			texttype[k].setString(Owners[kk.sav[i].x].Shops.products[kk.sav[i].y].Clothes.Type);
			textcolor[k].setString(Owners[kk.sav[i].x].Shops.products[kk.sav[i].y].Clothes.Color);
			textp[k].setString(") ");
			k++;
		}
	}

	k = 0;
	for (int i = 0; i < 20; i++) {
		a[i] = i + 1;
	}

	for (int i = 0; i < 20; i++) {
		long long price1 = a[i];
		while (price1 != 0)
		{
			int m = price1 % 10;
			nump[i] += m + '0';
			price1 /= 10;
		}
		reverse(nump[i].begin(), nump[i].end());
		textnum[i].setString(nump[i]);
	}
	for (int i = 0; i < cv.nump; i++) {

		if (kk.amount[i] != 0) {

			long long price2 = Owners[kk.sav[i].x].Shops.products[kk.sav[i].y].productPrice;
			long long price3 = kk.amount[i];
			long long price4 = Owners[kk.sav[i].x].Shops.products[kk.sav[i].y].avgRating;

			while (price2 != 0) {
				int remainder = price2 % 10;
				price[i] += remainder + '0';
				price2 /= 10;
			}
			while (price3 != 0) {
				int remainder1 = price3 % 10;
				quantity[i] += remainder1 + '0';
				price3 /= 10;
			}
			while (price4 != 0)
			{
				int remainder2 = price4 % 10;
				averating[i] += remainder2 + '0';
				price4 /= 10;
			}


			reverse(price[i].begin(), price[i].end());
			textprice[k].setString(price[i]);
			reverse(quantity[i].begin(), quantity[i].end());
			textquantity[k].setString(quantity[i]);
			reverse(averating[i].begin(), averating[i].end());
			textrating[k].setString(averating[i]);
			k++;
		}
	}
	int active = 0;
	int dele;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 216 && localposition.x <= 273 && localposition.y >= 743 && localposition.y <= 774) {
					active = 1;
					cout << "nump" << endl;

				}
				else if (localposition.x >= 316 && localposition.x <= 402 && localposition.y >= 742 && localposition.y <= 776) {

					cout << "delete" << endl;
					if (c.getSize() == 0)
						type = true;
					else {

						istringstream(c) >> dele;
						deletee(dele);
						cart();
					}

				}
				else if (localposition.x >= 808 && localposition.x <= 893 && localposition.y >= 747 && localposition.y <= 778) {
					return 0;
					cout << "back" << endl;

				}
				else if (localposition.x >= 687 && localposition.x <= 805 && localposition.y >= 744 && localposition.y <= 779) {
					receipt(LogID);
					cout << "recipt" << endl;

				}

				else
					active = 0;
			}

			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					c += event.text.unicode;
					textc.setString(c);
				}
				else if (active == 1 && event.text.unicode == 8 && c.getSize() > 0) {
					c.erase(c.getSize() - 1, c.getSize());
					textc.setString(c);
				}

			}
		}

		for (; n < cv.nump; n++) {


			textname[n].setPosition(32, hi);
			textname[n].setFont(fontname);
			textname[n].setCharacterSize(20);
			textprice[n].setPosition(165, hi);
			textprice[n].setFont(fontprice);
			textprice[n].setCharacterSize(20);
			textquantity[n].setPosition(400, hi);
			textquantity[n].setFont(fontprice);
			textquantity[n].setCharacterSize(20);
			textrating[n].setPosition(510, hi);
			textrating[n].setFont(fontprice);
			textrating[n].setCharacterSize(20);
			textcate[n].setPosition(232, ho);
			textcate[n].setFont(fontprice);
			textcate[n].setCharacterSize(15);
			textsize[n].setPosition(620, hi);
			textsize[n].setFont(fontname);
			textsize[n].setCharacterSize(20);
			texttype[n].setPosition(720, hi);
			texttype[n].setFont(fontname);
			texttype[n].setCharacterSize(20);
			textcolor[n].setPosition(840, hi);
			textcolor[n].setFont(fontname);
			textcolor[n].setCharacterSize(20);
			textnum[n].setPosition(1, hi);
			textnum[n].setFont(fontnum);
			textnum[n].setCharacterSize(20);
			textp[n].setPosition(23, hi);
			textp[n].setFont(fontp);
			textp[n].setCharacterSize(18);
			hi += 20;
			ho += 20.2;


		}

		window.draw(photo);
		window.draw(text60);
		window.draw(textt);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);
		window.draw(text8);
		window.draw(text00);
		window.draw(choice1);
		window.draw(choice2);
		window.draw(choice3);
		window.draw(choice4);
		window.draw(choice5);
		window.draw(choice6);
		window.draw(choice7);
		window.draw(choice8);

		window.draw(choice20);
		window.draw(choice30);
		window.draw(choice40);
		window.draw(choice50);
		if (type)
			window.draw(text40);
		window.draw(text10);

		window.draw(text30);
		window.draw(text50);

		window.draw(textc);



		for (n = 0; n < cv.nump; n++) {

			window.draw(textname[n]);
			window.draw(textprice[n]);
			window.draw(textcate[n]);
			window.draw(textquantity[n]);
			window.draw(textrating[n]);
			window.draw(textsize[n]);
			window.draw(texttype[n]);
			window.draw(textcolor[n]);
			window.draw(textnum[n]);
			window.draw(textp[n]);
		}



		window.draw(textt);
		window.display();
	}

}

int purchaseHistory(int  HI) {


	int n = 0, k = 0, a[10];
	float hi = 70;

	string nump[10];
	string price[10];
	string day[10];
	string month[10];

	sf::String p;
	sf::Font fontp;
	fontp.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textp[75];


	sf::Font fontnum;
	fontnum.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textnum[75];


	sf::Font fontday;
	fontday.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textday[75];

	sf::Font fontmonth;
	fontmonth.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textmonth[75];

	sf::Font fontprice;
	fontprice.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textprice[75];


	sf::RectangleShape choice40(sf::Vector2f(80.0f, 30.0f));
	choice40.setPosition(sf::Vector2f(812, 748));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::Red);
	choice40.setOutlineThickness(3);

	sf::RectangleShape choice1(sf::Vector2f(190.0f, 40.0f));
	choice1.setPosition(sf::Vector2f(90, 12));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(3);

	sf::RectangleShape choice2(sf::Vector2f(190.0f, 40.0f));
	choice2.setPosition(sf::Vector2f(340, 12));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineColor(sf::Color::White);
	choice2.setOutlineThickness(3);

	sf::RectangleShape choice3(sf::Vector2f(190.0f, 40.0f));
	choice3.setPosition(sf::Vector2f(590, 12));
	choice3.setFillColor(sf::Color::Transparent);
	choice3.setOutlineColor(sf::Color::White);
	choice3.setOutlineThickness(3);

	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" BACK ");
	text10.setCharacterSize(20);
	text10.setFillColor(sf::Color::Red);
	text10.setPosition(820, 750);
	text10.setStyle(sf::Text::Bold);

	sf::Font font1;
	font1.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text1;
	text1.setFont(font1);
	text1.setString(" Total Price ");
	text1.setCharacterSize(30);
	text1.setFillColor(sf::Color::White);
	text1.setPosition(100, 10);
	text1.setStyle(sf::Text::Bold);

	sf::Font font2;
	font2.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text2;
	text2.setFont(font2);
	text2.setString("      Day ");
	text2.setCharacterSize(30);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(350, 10);
	text2.setStyle(sf::Text::Bold);

	sf::Font font3;
	font3.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text3;
	text3.setFont(font3);
	text3.setString("     Month  ");
	text3.setCharacterSize(30);
	text3.setFillColor(sf::Color::White);
	text3.setPosition(600, 14);
	text3.setStyle(sf::Text::Bold);

	k = 0, n = 0;
	for (int i = 0; i < 10; i++) {

		textp[i].setString(") ");

	}

	for (int i = 0; i < 10; i++) {
		a[i] = i + 1;
	}

	for (int i = 0; i < 10; i++) {
		long long price1 = a[i];
		while (price1 != 0)
		{
			int m = price1 % 10;
			nump[i] += m + '0';
			price1 /= 10;
		}
		reverse(nump[i].begin(), nump[i].end());
		textnum[i].setString(nump[i]);
	}


	for (int i = 0; i < 10; i++) {

		if (Shoppers[HI].purchaseHistory[i] != 0) {

			long long price2 = Shoppers[HI].purchaseHistory[i];
			long long price3 = Shoppers[HI].days[i];
			long long price4 = Shoppers[HI].months[i];

			while (price2 != 0) {
				int remainder = price2 % 10;
				price[i] += remainder + '0';
				price2 /= 10;
			}
			while (price3 != 0) {
				int remainder1 = price3 % 10;
				day[i] += remainder1 + '0';
				price3 /= 10;
			}
			while (price4 != 0)
			{
				int remainder2 = price4 % 10;
				month[i] += remainder2 + '0';
				price4 /= 10;
			}


			reverse(price[i].begin(), price[i].end());
			textprice[k].setString(price[i]);
			reverse(day[i].begin(), day[i].end());
			textday[k].setString(day[i]);
			reverse(month[i].begin(), month[i].end());
			textmonth[k].setString(month[i]);
			k++;
		}

	}

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 809 && localposition.x <= 893 && localposition.y >= 743 && localposition.y <= 779) {
					return 0;
					cout << "back" << endl;

				}
			}
		}

		for (; n < k; n++) {



			textprice[n].setPosition(165, hi);
			textprice[n].setFont(fontprice);
			textprice[n].setCharacterSize(20);
			textday[n].setPosition(430, hi);
			textday[n].setFont(fontprice);
			textday[n].setCharacterSize(20);
			textmonth[n].setPosition(680, hi);
			textmonth[n].setFont(fontprice);
			textmonth[n].setCharacterSize(20);
			textnum[n].setPosition(1, hi);
			textnum[n].setFont(fontnum);
			textnum[n].setCharacterSize(20);
			textp[n].setPosition(23, hi);
			textp[n].setFont(fontp);
			textp[n].setCharacterSize(20);
			hi += 50;



		}

		window.clear();
		window.draw(photo);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text10);
		window.draw(choice1);
		window.draw(choice2);
		window.draw(choice3);
		window.draw(choice40);
		for (n = 0; n < k; n++) {

			window.draw(textprice[n]);
			window.draw(textday[n]);
			window.draw(textmonth[n]);
			window.draw(textnum[n]);
			window.draw(textp[n]);
		}
		window.display();
	}

}

void prodmenu() {


	sf::RectangleShape choice0(sf::Vector2f(80.0f, 25.0f));
	choice0.setPosition(sf::Vector2f(770, 15));
	choice0.setFillColor(sf::Color::Transparent);
	choice0.setOutlineThickness(3);
	choice0.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice01(sf::Vector2f(320.0f, 80.0f));
	choice01.setPosition(sf::Vector2f(250, 350));
	choice01.setFillColor(sf::Color::Transparent);
	choice01.setOutlineThickness(5);
	choice01.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice1(sf::Vector2f(320.0f, 80.0f));
	choice1.setPosition(sf::Vector2f(250, 100));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineThickness(5);
	choice1.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice5(sf::Vector2f(320.0f, 80.0f));
	choice5.setPosition(sf::Vector2f(250, 600));
	choice5.setFillColor(sf::Color::Transparent);
	choice5.setOutlineThickness(5);
	choice5.setOutlineColor(sf::Color::White);

	sf::Font fontz;
	fontz.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textz;
	textz.setFont(fontz);
	textz.setString("  BACK ");
	textz.setCharacterSize(20);
	textz.setFillColor(sf::Color::White);
	textz.setPosition(770, 15);
	textz.setStyle(sf::Text::Regular);

	sf::Font fontq;
	fontq.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textq;
	textq.setFont(fontq);
	textq.setString(" VIEW ALL ");
	textq.setCharacterSize(40);
	textq.setFillColor(sf::Color::White);
	textq.setPosition(310, 360);
	textq.setStyle(sf::Text::Regular);

	sf::Font fonta;
	fonta.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texta;
	texta.setFont(fonta);
	texta.setString(" FILTERS ");
	texta.setCharacterSize(40);
	texta.setFillColor(sf::Color::White);
	texta.setPosition(310, 110);
	texta.setStyle(sf::Text::Bold);

	sf::Font fontb;
	fontb.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textb;
	textb.setFont(fontb);
	textb.setString(" GIFTS  ");
	textb.setCharacterSize(40);
	textb.setFillColor(sf::Color::White);
	textb.setPosition(330, 620);
	textb.setStyle(sf::Text::Bold);



	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << "{" << localposition.x << "-" << localposition.y << "]" << endl;
				if (localposition.x >= 245 && localposition.x <= 580 && localposition.y >= 94 && localposition.y <= 182) {
					cout << "filters" << endl;
					filtersmenu();

				}
				else if (localposition.x >= 245 && localposition.x <= 576 && localposition.y >= 343 && localposition.y <= 437) {
					cout << "view all" << endl;
					viewproduct();
				}
				else if (localposition.x >= 245 && localposition.x <= 577 && localposition.y >= 593 && localposition.y <= 684) {
					cout << "gifts" << endl;
					giftsmenu();
				}
				else if (localposition.x >= 767 && localposition.x <= 852 && localposition.y >= 10 && localposition.y <= 43) {
					scchoice();
					cout << "back" << endl;

				}

			}
			window.clear();
			window.draw(photo);
			window.draw(texta);
			window.draw(textb);
			window.draw(textz);
			window.draw(textq);
			window.draw(choice0);
			window.draw(choice01);
			window.draw(choice1);
			window.draw(choice5);
			window.display();
		}
	}

}

int filtersmenu() {


	sf::RectangleShape choice0(sf::Vector2f(80.0f, 25.0f));
	choice0.setPosition(sf::Vector2f(770, 15));
	choice0.setFillColor(sf::Color::Transparent);
	choice0.setOutlineThickness(3);
	choice0.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice01(sf::Vector2f(320.0f, 80.0f));
	choice01.setPosition(sf::Vector2f(250, 350));
	choice01.setFillColor(sf::Color::Transparent);
	choice01.setOutlineThickness(5);
	choice01.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice1(sf::Vector2f(320.0f, 80.0f));
	choice1.setPosition(sf::Vector2f(250, 100));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineThickness(5);
	choice1.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice5(sf::Vector2f(320.0f, 80.0f));
	choice5.setPosition(sf::Vector2f(250, 600));
	choice5.setFillColor(sf::Color::Transparent);
	choice5.setOutlineThickness(5);
	choice5.setOutlineColor(sf::Color::White);

	sf::Font fontz;
	fontz.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textz;
	textz.setFont(fontz);
	textz.setString("  BACK ");
	textz.setCharacterSize(20);
	textz.setFillColor(sf::Color::White);
	textz.setPosition(770, 15);
	textz.setStyle(sf::Text::Regular);

	sf::Font fontq;
	fontq.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textq;
	textq.setFont(fontq);
	textq.setString(" By Shop ");
	textq.setCharacterSize(40);
	textq.setFillColor(sf::Color::White);
	textq.setPosition(310, 360);
	textq.setStyle(sf::Text::Regular);

	sf::Font fonta;
	fonta.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texta;
	texta.setFont(fonta);
	texta.setString(" By Category ");
	texta.setCharacterSize(40);
	texta.setFillColor(sf::Color::White);
	texta.setPosition(290, 110);
	texta.setStyle(sf::Text::Bold);

	sf::Font fontb;
	fontb.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textb;
	textb.setFont(fontb);
	textb.setString(" By Price  ");
	textb.setCharacterSize(40);
	textb.setFillColor(sf::Color::White);
	textb.setPosition(315, 620);
	textb.setStyle(sf::Text::Bold);



	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << "{" << localposition.x << "-" << localposition.y << "]" << endl;
				if (localposition.x >= 245 && localposition.x <= 580 && localposition.y >= 94 && localposition.y <= 182) {
					cout << "category" << endl;
					bycategory();

				}
				else if (localposition.x >= 245 && localposition.x <= 576 && localposition.y >= 343 && localposition.y <= 437) {
					cout << "shop" << endl;
					byshop();

				}
				else if (localposition.x >= 245 && localposition.x <= 577 && localposition.y >= 593 && localposition.y <= 684) {
					cout << "Price" << endl;
					byprice();

				}
				else if (localposition.x >= 767 && localposition.x <= 852 && localposition.y >= 10 && localposition.y <= 43) {
					cout << "back" << endl;
					return 0;

				}

			}
			window.clear();
			window.draw(photo);
			window.draw(texta);
			window.draw(textb);
			window.draw(textz);
			window.draw(textq);
			window.draw(choice0);
			window.draw(choice01);
			window.draw(choice1);
			window.draw(choice5);
			window.display();
		}
	}

}

int giftsmenu() {
	sf::Font font;
	font.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString(" Women ");
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::White);
	text.setPosition(525, 365);
	text.setStyle(sf::Text::Bold);

	sf::Text textn;
	textn.setFont(font);
	textn.setString(" Men ");
	textn.setCharacterSize(40);
	textn.setFillColor(sf::Color::White);
	textn.setPosition(235, 365);
	textn.setStyle(sf::Text::Bold);

	sf::Font fontz;
	fontz.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textz;
	textz.setFont(fontz);
	textz.setString("  BACK ");
	textz.setCharacterSize(20);
	textz.setFillColor(sf::Color::White);
	textz.setPosition(810, 15);
	textz.setStyle(sf::Text::Regular);

	sf::RectangleShape choice0(sf::Vector2f(80.0f, 25.0f));
	choice0.setPosition(sf::Vector2f(810, 15));
	choice0.setFillColor(sf::Color::Transparent);
	choice0.setOutlineThickness(3);
	choice0.setOutlineColor(sf::Color::White);
	sf::RectangleShape choice(sf::Vector2f(270.0f, 80.0f));
	choice.setPosition(sf::Vector2f(150, 350));
	choice.setFillColor(sf::Color::Transparent);
	choice.setOutlineThickness(5);
	choice.setOutlineColor(sf::Color::White);
	sf::RectangleShape choicee(sf::Vector2f(270.0f, 80.0f));
	choicee.setPosition(sf::Vector2f(470, 350));
	choicee.setFillColor(sf::Color::Transparent);
	choicee.setOutlineThickness(5);
	choicee.setOutlineColor(sf::Color::White);

	string g;
	int nums = 3;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i local_position = sf::Mouse::getPosition(window);
				cout << '(' << local_position.x << ',' << local_position.y << ')' << endl;
				if (local_position.x >= 145 && local_position.x <= 424 && local_position.y >= 346 && local_position.y <= 434) {

					cout << "Man\n";
					g = ("m");
					viewbystring(g, nums);

					break;
				}
				else if (local_position.x >= 466 && local_position.x <= 743 && local_position.y >= 344 && local_position.y <= 434) {

					g = ("f");
					viewbystring(g, nums);
					cout << "Woman\n";

					break;
				}
				else if (local_position.x >= 804 && local_position.x <= 891 && local_position.y >= 14 && local_position.y <= 42) {
					cout << "back\n";
					return 0;
					break;
				}
			}
		}
		window.draw(photo);
		window.draw(choice);
		window.draw(choice0);
		window.draw(choicee);
		window.draw(text);
		window.draw(textn);
		window.draw(textz);
		window.display();
	}
}

int viewbystring(string s, int nums) {

	int number = 1, a[35], x[35], y[35];
	int z = 0;
	float hi = 50, ho = 50;
	bool next = false;

	bool type = false;
	int k = 0, n = 0;

	string g;

	sf::RectangleShape choice33(sf::Vector2f(50.0f, 25.0f));
	choice33.setPosition(sf::Vector2f(220, 715));
	choice33.setFillColor(sf::Color::White);
	choice33.setOutlineColor(sf::Color::White);
	choice33.setOutlineThickness(3);

	sf::Font fontq;
	fontq.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String q;
	sf::Text textq(q, fontq, 25);
	textq.setFillColor(sf::Color::Black);
	textq.setPosition(220, 715);

	sf::Font font60;
	font60.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text60;
	text60.setFont(font60);
	text60.setString(" Product quantity:  ");
	text60.setCharacterSize(22);
	text60.setFillColor(sf::Color::Blue);
	text60.setPosition(15, 715);
	text60.setStyle(sf::Text::Bold);

	sf::Font font100;
	font100.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text100;
	text100.setFont(font100);
	text100.setString(" Your Desired Quantity Is Unavalible.  ");
	text100.setCharacterSize(22);
	text100.setFillColor(sf::Color::White);
	text100.setPosition(250, 650);
	text100.setStyle(sf::Text::Bold);

	sf::Font font200;
	font200.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text200;
	text200.setFont(font200);
	text200.setString(" Invalid number.  ");
	text200.setCharacterSize(22);
	text200.setFillColor(sf::Color::White);
	text200.setPosition(340, 650);
	text200.setStyle(sf::Text::Bold);

	string nump[35];
	string price[35];
	string averating[35];
	string quantity[35];

	sf::String p;
	sf::Font fontp;
	fontp.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textp[35];

	sf::String name;
	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textname[35];


	sf::String num;
	sf::Font fontnum;
	fontnum.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textnum[35];

	sf::String cate;
	sf::Font fontcate;
	fontcate.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcate[35];

	sf::Font fontprice;
	fontprice.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textprice[35];

	sf::Font fontsize;
	fontsize.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textsize[35];

	sf::Font fontrating;
	fontrating.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textrating[35];

	sf::Font fontquantity;
	fontquantity.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textquantity[35];

	sf::Font fonttype;
	fonttype.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texttype[35];

	sf::Font fontcolor;
	fontcolor.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcolor[35];

	sf::RectangleShape choice1(sf::Vector2f(100.0f, 30.0f));
	choice1.setPosition(sf::Vector2f(5, 10));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineColor(sf::Color::Blue);
	choice1.setOutlineThickness(3);

	sf::RectangleShape choice2(sf::Vector2f(100.0f, 30.0f));
	choice2.setPosition(sf::Vector2f(120, 10));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineColor(sf::Color::Blue);
	choice2.setOutlineThickness(3);

	sf::RectangleShape choice3(sf::Vector2f(100.0f, 30.0f));
	choice3.setPosition(sf::Vector2f(235, 10));
	choice3.setFillColor(sf::Color::Transparent);
	choice3.setOutlineColor(sf::Color::Blue);
	choice3.setOutlineThickness(3);

	sf::RectangleShape choice4(sf::Vector2f(100.0f, 30.0f));
	choice4.setPosition(sf::Vector2f(350, 10));
	choice4.setFillColor(sf::Color::Transparent);
	choice4.setOutlineColor(sf::Color::Blue);
	choice4.setOutlineThickness(3);

	sf::RectangleShape choice5(sf::Vector2f(100.0f, 30.0f));
	choice5.setPosition(sf::Vector2f(465, 10));
	choice5.setFillColor(sf::Color::Transparent);
	choice5.setOutlineColor(sf::Color::Blue);
	choice5.setOutlineThickness(3);

	sf::RectangleShape choice6(sf::Vector2f(100.0f, 30.0f));
	choice6.setPosition(sf::Vector2f(580, 10));
	choice6.setFillColor(sf::Color::Transparent);
	choice6.setOutlineColor(sf::Color::Blue);
	choice6.setOutlineThickness(3);

	sf::RectangleShape choice7(sf::Vector2f(100.0f, 30.0f));
	choice7.setPosition(sf::Vector2f(695, 10));
	choice7.setFillColor(sf::Color::Transparent);
	choice7.setOutlineColor(sf::Color::Blue);
	choice7.setOutlineThickness(3);

	sf::RectangleShape choice8(sf::Vector2f(100.0f, 30.0f));
	choice8.setPosition(sf::Vector2f(810, 10));
	choice8.setFillColor(sf::Color::Transparent);
	choice8.setOutlineColor(sf::Color::Blue);
	choice8.setOutlineThickness(3);




	sf::RectangleShape choice20(sf::Vector2f(80.0f, 30.0f));
	choice20.setPosition(sf::Vector2f(320, 745));
	choice20.setFillColor(sf::Color::Transparent);
	choice20.setOutlineColor(sf::Color::Blue);
	choice20.setOutlineThickness(3);

	sf::RectangleShape choice30(sf::Vector2f(50.0f, 25.0f));
	choice30.setPosition(sf::Vector2f(220, 748));
	choice30.setFillColor(sf::Color::White);
	choice30.setOutlineColor(sf::Color::White);
	choice30.setOutlineThickness(3);

	sf::RectangleShape choice40(sf::Vector2f(80.0f, 30.0f));
	choice40.setPosition(sf::Vector2f(812, 748));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::Red);
	choice40.setOutlineThickness(3);


	sf::Font fontc;
	fontc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String c;
	sf::Text textc(c, fontc, 25);
	textc.setFillColor(sf::Color::Black);
	textc.setPosition(218, 743);


	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" BACK ");
	text10.setCharacterSize(20);
	text10.setFillColor(sf::Color::Red);
	text10.setPosition(820, 750);
	text10.setStyle(sf::Text::Bold);


	sf::Font font30;
	font30.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text30;
	text30.setFont(font30);
	text30.setString(" Add ");
	text30.setCharacterSize(22);
	text30.setFillColor(sf::Color::Blue);
	text30.setPosition(330, 745);
	text30.setStyle(sf::Text::Bold);

	sf::Font font40;
	font40.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text40;
	text40.setFont(font30);
	text40.setString("** Please Choose a Number **");
	text40.setCharacterSize(22);
	text40.setFillColor(sf::Color::White);
	text40.setPosition(450, 745);
	text40.setStyle(sf::Text::Bold);

	sf::Font font50;
	font50.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text50;
	text50.setFont(font50);
	text50.setString(" Product number :  ");
	text50.setCharacterSize(22);
	text50.setFillColor(sf::Color::Blue);
	text50.setPosition(15, 748);
	text50.setStyle(sf::Text::Bold);

	sf::Font font1;
	font1.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text1;
	text1.setFont(font1);
	text1.setString(" NAME ");
	text1.setCharacterSize(22);
	text1.setFillColor(sf::Color::Blue);
	text1.setPosition(14, 10);
	text1.setStyle(sf::Text::Bold);

	sf::Font font2;
	font2.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text2;
	text2.setFont(font2);
	text2.setString(" PRICE ");
	text2.setCharacterSize(22);
	text2.setFillColor(sf::Color::Blue);
	text2.setPosition(130, 10);
	text2.setStyle(sf::Text::Bold);

	sf::Font font3;
	font3.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text3;
	text3.setFont(font3);
	text3.setString(" CATEGORY  ");
	text3.setCharacterSize(18);
	text3.setFillColor(sf::Color::Blue);
	text3.setPosition(232, 14);
	text3.setStyle(sf::Text::Bold);

	sf::Font font4;
	font4.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text4;
	text4.setFont(font4);
	text4.setString("  QUANTITY ");
	text4.setCharacterSize(19);
	text4.setFillColor(sf::Color::Blue);
	text4.setPosition(340, 13);
	text4.setStyle(sf::Text::Bold);

	sf::Font font5;
	font5.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text5;
	text5.setFont(font5);
	text5.setString("  RATING ");
	text5.setCharacterSize(21);
	text5.setFillColor(sf::Color::Blue);
	text5.setPosition(461, 11);
	text5.setStyle(sf::Text::Bold);

	sf::Font font6;
	font6.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text6;
	text6.setFont(font6);
	text6.setString(" SIZE ");
	text6.setCharacterSize(22);
	text6.setFillColor(sf::Color::Blue);
	text6.setPosition(598, 10);
	text6.setStyle(sf::Text::Bold);

	sf::Font font7;
	font7.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text7;
	text7.setFont(font7);
	text7.setString(" TYPE ");
	text7.setCharacterSize(22);
	text7.setFillColor(sf::Color::Blue);
	text7.setPosition(710, 10);
	text7.setStyle(sf::Text::Bold);

	sf::Font font8;
	font8.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text8;
	text8.setFont(font8);
	text8.setString(" COLOR ");
	text8.setCharacterSize(22);
	text8.setFillColor(sf::Color::Blue);
	text8.setPosition(820, 10);
	text8.setStyle(sf::Text::Bold);

	if (nums == 3) {
		for (int i = 0; i < maxOwners; i++) {
			for (int j = 0; j < maxProds; j++) {
				if (Owners[i].Shops.products[j].Quantity != 0) {
					if (s == "m") {
						if (Owners[i].Shops.products[j].Category != ("Clothing") && Owners[i].Shops.products[j].Category != ("Makeup&Accessories")) {

							textname[k].setString(Owners[i].Shops.products[j].productName);
							textcate[k].setString(Owners[i].Shops.products[j].Category);
							textsize[k].setString(Owners[i].Shops.products[j].Clothes.Size);
							texttype[k].setString(Owners[i].Shops.products[j].Clothes.Type);
							textcolor[k].setString(Owners[i].Shops.products[j].Clothes.Color);
							textp[k].setString(") ");
							m.a[k] = i;
							m.b[k] = j;
							k++;
						}
						else if (Owners[i].Shops.products[j].Category == ("Clothing") && Owners[i].Shops.products[j].Clothes.Type == "Male")
						{
							textname[k].setString(Owners[i].Shops.products[j].productName);
							textcate[k].setString(Owners[i].Shops.products[j].Category);
							textsize[k].setString(Owners[i].Shops.products[j].Clothes.Size);
							texttype[k].setString(Owners[i].Shops.products[j].Clothes.Type);
							textcolor[k].setString(Owners[i].Shops.products[j].Clothes.Color);
							textp[k].setString(") ");
							m.a[k] = i;
							m.b[k] = j;
							k++;
						}
					}
					else {
						if (Owners[i].Shops.products[j].Category != ("Clothing")) {

							textname[k].setString(Owners[i].Shops.products[j].productName);
							textcate[k].setString(Owners[i].Shops.products[j].Category);
							textsize[k].setString(Owners[i].Shops.products[j].Clothes.Size);
							texttype[k].setString(Owners[i].Shops.products[j].Clothes.Type);
							textcolor[k].setString(Owners[i].Shops.products[j].Clothes.Color);
							textp[k].setString(") ");
							m.a[k] = i;
							m.b[k] = j;
							k++;
						}
						else if (Owners[i].Shops.products[j].Category == ("Clothing") && Owners[i].Shops.products[j].Clothes.Type == "Female")
						{
							textname[k].setString(Owners[i].Shops.products[j].productName);
							textcate[k].setString(Owners[i].Shops.products[j].Category);
							textsize[k].setString(Owners[i].Shops.products[j].Clothes.Size);
							texttype[k].setString(Owners[i].Shops.products[j].Clothes.Type);
							textcolor[k].setString(Owners[i].Shops.products[j].Clothes.Color);
							textp[k].setString(") ");
							m.a[k] = i;
							m.b[k] = j;
							k++;
						}
					}
				}
			}
		}
	}

	else if (nums == 1) {
		for (int i = 0; i < maxOwners; i++) {
			for (int j = 0; j < maxProds; j++) {
				if (Owners[i].Shops.ShopName == s && Owners[i].Shops.products[j].Quantity != 0) {
					textname[k].setString(Owners[i].Shops.products[j].productName);
					textcate[k].setString(Owners[i].Shops.products[j].Category);
					textsize[k].setString(Owners[i].Shops.products[j].Clothes.Size);
					texttype[k].setString(Owners[i].Shops.products[j].Clothes.Type);
					textcolor[k].setString(Owners[i].Shops.products[j].Clothes.Color);
					textp[k].setString(") ");
					m.a[k] = i;
					m.b[k] = j;
					k++;
				}
			}
		}
	}

	else if (nums == 2) {
		for (int i = 0, k = 0; i < maxOwners; i++) {
			for (int j = 0; j < maxProds; j++) {
				if (Owners[i].Shops.products[j].Category == s && Owners[i].Shops.products[j].Quantity != 0) {
					textname[k].setString(Owners[i].Shops.products[j].productName);
					textcate[k].setString(Owners[i].Shops.products[j].Category);
					textsize[k].setString(Owners[i].Shops.products[j].Clothes.Size);
					texttype[k].setString(Owners[i].Shops.products[j].Clothes.Type);
					textcolor[k].setString(Owners[i].Shops.products[j].Clothes.Color);
					textp[k].setString(") ");
					m.a[k] = i;
					m.b[k] = j;
					k++;
				}
			}
		}
	}

	k = 0;
	for (int i = 0; i < 35; i++) {
		a[i] = i + 1;
	}

	for (int i = 0; i < 35; i++) {
		long long price1 = a[i];
		while (price1 != 0)
		{
			int m = price1 % 10;
			nump[i] += m + '0';
			price1 /= 10;
		}
		reverse(nump[i].begin(), nump[i].end());
		textnum[i].setString(nump[i]);
	}
	if (nums == 1) {
		for (int i = 0; i < maxOwners; i++) {
			for (int j = 0; j < maxProds; j++) {
				if (Owners[i].Shops.ShopName == s && Owners[i].Shops.products[j].Quantity != 0) {

					long long price2 = Owners[i].Shops.products[j].productPrice;
					long long price3 = Owners[i].Shops.products[j].Quantity;
					long long price4 = Owners[i].Shops.products[j].avgRating;

					while (price2 != 0) {
						int remainder = price2 % 10;
						price[k] += remainder + '0';
						price2 /= 10;
					}
					while (price3 != 0) {
						int remainder1 = price3 % 10;
						quantity[k] += remainder1 + '0';
						price3 /= 10;
					}
					while (price4 != 0)
					{
						int remainder2 = price4 % 10;
						averating[k] += remainder2 + '0';
						price4 /= 10;
					}


					reverse(price[k].begin(), price[k].end());
					textprice[k].setString(price[k]);
					reverse(quantity[k].begin(), quantity[k].end());
					textquantity[k].setString(quantity[k]);
					reverse(averating[k].begin(), averating[k].end());
					textrating[k].setString(averating[k]);
					k++;
				}
			}
		}
	}
	else if (nums == 2) {
		for (int i = 0; i < maxOwners; i++) {
			for (int j = 0; j < maxProds; j++) {
				if (Owners[i].Shops.products[j].Category == s && Owners[i].Shops.products[j].Quantity != 0) {

					long long price2 = Owners[i].Shops.products[j].productPrice;
					long long price3 = Owners[i].Shops.products[j].Quantity;
					long long price4 = Owners[i].Shops.products[j].avgRating;

					while (price2 != 0) {
						int remainder = price2 % 10;
						price[k] += remainder + '0';
						price2 /= 10;
					}
					while (price3 != 0) {
						int remainder1 = price3 % 10;
						quantity[k] += remainder1 + '0';
						price3 /= 10;
					}
					while (price4 != 0)
					{
						int remainder2 = price4 % 10;
						averating[k] += remainder2 + '0';
						price4 /= 10;
					}


					reverse(price[k].begin(), price[k].end());
					textprice[k].setString(price[k]);
					reverse(quantity[k].begin(), quantity[k].end());
					textquantity[k].setString(quantity[k]);
					reverse(averating[k].begin(), averating[k].end());
					textrating[k].setString(averating[k]);
					k++;
				}
			}
		}
	}

	else if (nums == 3) {
		for (int i = 0; i < maxOwners; i++) {
			for (int j = 0; j < maxProds; j++) {
				if (Owners[i].Shops.products[j].Quantity != 0) {
					if (s == "m") {
						if (Owners[i].Shops.products[j].Category != ("Clothing") && Owners[i].Shops.products[j].Category != ("Makeup&Accessories")) {

							long long price2 = Owners[i].Shops.products[j].productPrice;
							long long price3 = Owners[i].Shops.products[j].Quantity;
							long long price4 = Owners[i].Shops.products[j].avgRating;

							while (price2 != 0) {
								int remainder = price2 % 10;
								price[k] += remainder + '0';
								price2 /= 10;
							}
							while (price3 != 0) {
								int remainder1 = price3 % 10;
								quantity[k] += remainder1 + '0';
								price3 /= 10;
							}
							while (price4 != 0)
							{
								int remainder2 = price4 % 10;
								averating[k] += remainder2 + '0';
								price4 /= 10;
							}


							reverse(price[k].begin(), price[k].end());
							textprice[k].setString(price[k]);
							reverse(quantity[k].begin(), quantity[k].end());
							textquantity[k].setString(quantity[k]);
							reverse(averating[k].begin(), averating[k].end());
							textrating[k].setString(averating[k]);
							k++;
						}
						else if (Owners[i].Shops.products[j].Category == ("Clothing") && Owners[i].Shops.products[j].Clothes.Type == "Male") {

							long long price2 = Owners[i].Shops.products[j].productPrice;
							long long price3 = Owners[i].Shops.products[j].Quantity;
							long long price4 = Owners[i].Shops.products[j].avgRating;

							while (price2 != 0) {
								int remainder = price2 % 10;
								price[k] += remainder + '0';
								price2 /= 10;
							}
							while (price3 != 0) {
								int remainder1 = price3 % 10;
								quantity[k] += remainder1 + '0';
								price3 /= 10;
							}
							while (price4 != 0)
							{
								int remainder2 = price4 % 10;
								averating[k] += remainder2 + '0';
								price4 /= 10;
							}


							reverse(price[k].begin(), price[k].end());
							textprice[k].setString(price[k]);
							reverse(quantity[k].begin(), quantity[k].end());
							textquantity[k].setString(quantity[k]);
							reverse(averating[k].begin(), averating[k].end());
							textrating[k].setString(averating[k]);
							k++;
						}
						else
							continue;
					}
					else {
						if (Owners[i].Shops.products[j].Category != ("Clothing")) {

							long long price2 = Owners[i].Shops.products[j].productPrice;
							long long price3 = Owners[i].Shops.products[j].Quantity;
							long long price4 = Owners[i].Shops.products[j].avgRating;

							while (price2 != 0) {
								int remainder = price2 % 10;
								price[k] += remainder + '0';
								price2 /= 10;
							}
							while (price3 != 0) {
								int remainder1 = price3 % 10;
								quantity[k] += remainder1 + '0';
								price3 /= 10;
							}
							while (price4 != 0)
							{
								int remainder2 = price4 % 10;
								averating[k] += remainder2 + '0';
								price4 /= 10;
							}


							reverse(price[k].begin(), price[k].end());
							textprice[k].setString(price[k]);
							reverse(quantity[k].begin(), quantity[k].end());
							textquantity[k].setString(quantity[k]);
							reverse(averating[k].begin(), averating[k].end());
							textrating[k].setString(averating[k]);
							k++;
						}
						else if (Owners[i].Shops.products[j].Category == ("Clothing") && Owners[i].Shops.products[j].Clothes.Type == "Female") {
							long long price2 = Owners[i].Shops.products[j].productPrice;
							long long price3 = Owners[i].Shops.products[j].Quantity;
							long long price4 = Owners[i].Shops.products[j].avgRating;

							while (price2 != 0) {
								int remainder = price2 % 10;
								price[k] += remainder + '0';
								price2 /= 10;
							}
							while (price3 != 0) {
								int remainder1 = price3 % 10;
								quantity[k] += remainder1 + '0';
								price3 /= 10;
							}
							while (price4 != 0)
							{
								int remainder2 = price4 % 10;
								averating[k] += remainder2 + '0';
								price4 /= 10;
							}


							reverse(price[k].begin(), price[k].end());
							textprice[k].setString(price[k]);
							reverse(quantity[k].begin(), quantity[k].end());
							textquantity[k].setString(quantity[k]);
							reverse(averating[k].begin(), averating[k].end());
							textrating[k].setString(averating[k]);
							k++;
						}
						else
							continue;

					}
				}
			}
		}
	}
	int cc, qq;
	bool more = false, nmore = false;
	int active = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 216 && localposition.x <= 273 && localposition.y >= 743 && localposition.y <= 774) {
					active = 1;
					cout << "nump" << endl;

				}
				else if (localposition.x >= 316 && localposition.x <= 402 && localposition.y >= 742 && localposition.y <= 776) {
					cout << "add" << endl;

					istringstream(c) >> cc;
					istringstream(q) >> qq;

					if (c.getSize() == 0 || q.getSize() == 0)
						type = true;

					if (c.getSize() == 0 || q.getSize() == 0)
						type = true;

					else  if (c.getSize() > 0 && q.getSize() > 0) {
						if (cc <= k) {


							if (qq <= Owners[m.a[cc - 1]].Shops.products[m.b[cc - 1]].Quantity && qq != 0) {
								kk.sub[cv.index] = (qq * Owners[m.a[cc - 1]].Shops.products[m.b[cc - 1]].productPrice);
								kk.amount[cv.index] = qq;
								Owners[m.a[cc - 1]].Shops.products[m.b[cc - 1]].Quantity -= qq;
								kk.sav[cv.index].x = m.a[cc - 1];
								kk.sav[cv.index].y = m.b[cc - 1];
								cv.nump++;
								cv.index++;
								cout << qq << "  " << cc;

								for (int i = 1; i < 5; i++) {
									c.erase(c.getSize() - 1, c.getSize());
									textc.setString(c);
									if (c.getSize() == 0)
										break;
								}
								for (int i = 1; i < 5; i++) {
									q.erase(q.getSize() - 1, q.getSize());
									textq.setString(q);
									if (q.getSize() == 0)
										break;
								}
								type = false;
								more = false;
								nmore = false;

							}
							else {
								type = false;
								nmore = false;
								more = true;
							}
						}
						else {
							type = false;
							nmore = true;
							more = false;
						}
					}
				}

				else if (localposition.x >= 216 && localposition.x <= 270 && localposition.y >= 12 && localposition.y <= 741) {

					active = 2;
					cout << "quant" << endl;


				}

				else if (localposition.x >= 808 && localposition.x <= 893 && localposition.y >= 747 && localposition.y <= 778) {

					return 0;

					cout << "back" << endl;

				}

				else
					active = 0;
			}

			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					c += event.text.unicode;
					textc.setString(c);
				}
				else if (active == 1 && event.text.unicode == 8 && c.getSize() > 0) {
					c.erase(c.getSize() - 1, c.getSize());
					textc.setString(c);
				}
				if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					q += event.text.unicode;
					textq.setString(q);
				}
				else if (active == 2 && event.text.unicode == 8 && q.getSize() > 0) {
					q.erase(q.getSize() - 1, q.getSize());
					textq.setString(q);
				}

			}
		}

		for (; n < k; n++) {


			textname[n].setPosition(32, hi);
			textname[n].setFont(fontname);
			textname[n].setCharacterSize(20);
			textprice[n].setPosition(165, hi);
			textprice[n].setFont(fontprice);
			textprice[n].setCharacterSize(20);
			textquantity[n].setPosition(400, hi);
			textquantity[n].setFont(fontprice);
			textquantity[n].setCharacterSize(20);
			textrating[n].setPosition(510, hi);
			textrating[n].setFont(fontprice);
			textrating[n].setCharacterSize(20);
			textcate[n].setPosition(232, ho);
			textcate[n].setFont(fontprice);
			textcate[n].setCharacterSize(15);
			textsize[n].setPosition(620, hi);
			textsize[n].setFont(fontname);
			textsize[n].setCharacterSize(20);
			texttype[n].setPosition(720, hi);
			texttype[n].setFont(fontname);
			texttype[n].setCharacterSize(20);
			textcolor[n].setPosition(840, hi);
			textcolor[n].setFont(fontname);
			textcolor[n].setCharacterSize(20);
			textnum[n].setPosition(1, hi);
			textnum[n].setFont(fontnum);
			textnum[n].setCharacterSize(20);
			textp[n].setPosition(23, hi);
			textp[n].setFont(fontp);
			textp[n].setCharacterSize(18);
			hi += 20;
			ho += 20.2;


		}

		window.draw(photo);

		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);
		window.draw(text8);
		window.draw(choice1);
		window.draw(choice2);
		window.draw(choice3);
		window.draw(choice4);
		window.draw(choice5);
		window.draw(choice6);
		window.draw(choice7);
		window.draw(choice8);
		window.draw(choice33);
		window.draw(textq);
		window.draw(text60);
		window.draw(choice20);
		window.draw(choice30);
		window.draw(choice40);
		if (type)
			window.draw(text40);
		if (more)
			window.draw(text100);
		if (nmore)
			window.draw(text200);
		window.draw(text10);

		window.draw(text30);
		window.draw(text50);

		window.draw(textc);



		for (n = 0; n < k; n++) {

			window.draw(textname[n]);
			window.draw(textprice[n]);
			window.draw(textcate[n]);
			window.draw(textquantity[n]);
			window.draw(textrating[n]);
			window.draw(textsize[n]);
			window.draw(texttype[n]);
			window.draw(textcolor[n]);
			window.draw(textnum[n]);
			window.draw(textp[n]);
		}




		window.display();
	}

}

int viewbysearch(string s) {

	int number = 1, a[10];
	int z = 0;
	float hi = 50, ho = 50;
	bool next = false;

	bool type = false;
	int k = 0, n = 0;

	string g;

	sf::RectangleShape choice33(sf::Vector2f(50.0f, 25.0f));
	choice33.setPosition(sf::Vector2f(220, 715));
	choice33.setFillColor(sf::Color::White);
	choice33.setOutlineColor(sf::Color::White);
	choice33.setOutlineThickness(3);

	sf::Font fontq;
	fontq.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String q;
	sf::Text textq(q, fontq, 25);
	textq.setFillColor(sf::Color::Black);
	textq.setPosition(220, 715);

	sf::Font font60;
	font60.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text60;
	text60.setFont(font60);
	text60.setString(" Product quantity:  ");
	text60.setCharacterSize(22);
	text60.setFillColor(sf::Color::Blue);
	text60.setPosition(15, 715);
	text60.setStyle(sf::Text::Bold);


	sf::Font font100;
	font100.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text100;
	text100.setFont(font100);
	text100.setString(" Your Desired Quantity Is Unavalible.  ");
	text100.setCharacterSize(22);
	text100.setFillColor(sf::Color::White);
	text100.setPosition(250, 650);
	text100.setStyle(sf::Text::Bold);

	sf::Font font200;
	font200.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text200;
	text200.setFont(font200);
	text200.setString(" Invalid number.  ");
	text200.setCharacterSize(22);
	text200.setFillColor(sf::Color::White);
	text200.setPosition(340, 650);
	text200.setStyle(sf::Text::Bold);


	string nump[10];
	string price[10];
	string averating[10];
	string quantity[10];

	sf::String p;
	sf::Font fontp;
	fontp.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textp[10];

	sf::String name;
	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textname[10];


	sf::String num;
	sf::Font fontnum;
	fontnum.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textnum[10];

	sf::String cate;
	sf::Font fontcate;
	fontcate.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcate[10];

	sf::Font fontprice;
	fontprice.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textprice[10];

	sf::Font fontsize;
	fontsize.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textsize[10];

	sf::Font fontrating;
	fontrating.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textrating[10];

	sf::Font fontquantity;
	fontquantity.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textquantity[10];

	sf::Font fonttype;
	fonttype.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texttype[10];

	sf::Font fontcolor;
	fontcolor.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcolor[10];

	sf::RectangleShape choice1(sf::Vector2f(100.0f, 30.0f));
	choice1.setPosition(sf::Vector2f(5, 10));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineColor(sf::Color::Blue);
	choice1.setOutlineThickness(3);

	sf::RectangleShape choice2(sf::Vector2f(100.0f, 30.0f));
	choice2.setPosition(sf::Vector2f(120, 10));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineColor(sf::Color::Blue);
	choice2.setOutlineThickness(3);

	sf::RectangleShape choice3(sf::Vector2f(100.0f, 30.0f));
	choice3.setPosition(sf::Vector2f(235, 10));
	choice3.setFillColor(sf::Color::Transparent);
	choice3.setOutlineColor(sf::Color::Blue);
	choice3.setOutlineThickness(3);

	sf::RectangleShape choice4(sf::Vector2f(100.0f, 30.0f));
	choice4.setPosition(sf::Vector2f(350, 10));
	choice4.setFillColor(sf::Color::Transparent);
	choice4.setOutlineColor(sf::Color::Blue);
	choice4.setOutlineThickness(3);

	sf::RectangleShape choice5(sf::Vector2f(100.0f, 30.0f));
	choice5.setPosition(sf::Vector2f(465, 10));
	choice5.setFillColor(sf::Color::Transparent);
	choice5.setOutlineColor(sf::Color::Blue);
	choice5.setOutlineThickness(3);

	sf::RectangleShape choice6(sf::Vector2f(100.0f, 30.0f));
	choice6.setPosition(sf::Vector2f(580, 10));
	choice6.setFillColor(sf::Color::Transparent);
	choice6.setOutlineColor(sf::Color::Blue);
	choice6.setOutlineThickness(3);

	sf::RectangleShape choice7(sf::Vector2f(100.0f, 30.0f));
	choice7.setPosition(sf::Vector2f(695, 10));
	choice7.setFillColor(sf::Color::Transparent);
	choice7.setOutlineColor(sf::Color::Blue);
	choice7.setOutlineThickness(3);

	sf::RectangleShape choice8(sf::Vector2f(100.0f, 30.0f));
	choice8.setPosition(sf::Vector2f(810, 10));
	choice8.setFillColor(sf::Color::Transparent);
	choice8.setOutlineColor(sf::Color::Blue);
	choice8.setOutlineThickness(3);

	sf::RectangleShape choice20(sf::Vector2f(80.0f, 30.0f));
	choice20.setPosition(sf::Vector2f(320, 745));
	choice20.setFillColor(sf::Color::Transparent);
	choice20.setOutlineColor(sf::Color::Blue);
	choice20.setOutlineThickness(3);

	sf::RectangleShape choice30(sf::Vector2f(50.0f, 25.0f));
	choice30.setPosition(sf::Vector2f(220, 748));
	choice30.setFillColor(sf::Color::White);
	choice30.setOutlineColor(sf::Color::White);
	choice30.setOutlineThickness(3);

	sf::RectangleShape choice40(sf::Vector2f(80.0f, 30.0f));
	choice40.setPosition(sf::Vector2f(812, 748));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::Red);
	choice40.setOutlineThickness(3);


	sf::Font fontc;
	fontc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String d;
	sf::Text textc(d, fontc, 25);
	textc.setFillColor(sf::Color::Black);
	textc.setPosition(218, 743);


	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" BACK ");
	text10.setCharacterSize(20);
	text10.setFillColor(sf::Color::Red);
	text10.setPosition(820, 750);
	text10.setStyle(sf::Text::Bold);


	sf::Font font30;
	font30.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text30;
	text30.setFont(font30);
	text30.setString(" Add ");
	text30.setCharacterSize(22);
	text30.setFillColor(sf::Color::Blue);
	text30.setPosition(330, 745);
	text30.setStyle(sf::Text::Bold);

	sf::Font font40;
	font40.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text40;
	text40.setFont(font30);
	text40.setString("** Please Choose a Number **");
	text40.setCharacterSize(22);
	text40.setFillColor(sf::Color::White);
	text40.setPosition(450, 745);
	text40.setStyle(sf::Text::Bold);

	sf::Font font50;
	font50.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text50;
	text50.setFont(font50);
	text50.setString(" Product number :  ");
	text50.setCharacterSize(22);
	text50.setFillColor(sf::Color::Blue);
	text50.setPosition(15, 748);
	text50.setStyle(sf::Text::Bold);

	sf::Font font1;
	font1.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text1;
	text1.setFont(font1);
	text1.setString(" NAME ");
	text1.setCharacterSize(22);
	text1.setFillColor(sf::Color::Blue);
	text1.setPosition(14, 10);
	text1.setStyle(sf::Text::Bold);

	sf::Font font2;
	font2.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text2;
	text2.setFont(font2);
	text2.setString(" PRICE ");
	text2.setCharacterSize(22);
	text2.setFillColor(sf::Color::Blue);
	text2.setPosition(130, 10);
	text2.setStyle(sf::Text::Bold);

	sf::Font font3;
	font3.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text3;
	text3.setFont(font3);
	text3.setString(" CATEGORY  ");
	text3.setCharacterSize(18);
	text3.setFillColor(sf::Color::Blue);
	text3.setPosition(232, 14);
	text3.setStyle(sf::Text::Bold);

	sf::Font font4;
	font4.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text4;
	text4.setFont(font4);
	text4.setString("  QUANTITY ");
	text4.setCharacterSize(19);
	text4.setFillColor(sf::Color::Blue);
	text4.setPosition(340, 13);
	text4.setStyle(sf::Text::Bold);

	sf::Font font5;
	font5.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text5;
	text5.setFont(font5);
	text5.setString("  RATING ");
	text5.setCharacterSize(21);
	text5.setFillColor(sf::Color::Blue);
	text5.setPosition(461, 11);
	text5.setStyle(sf::Text::Bold);

	sf::Font font6;
	font6.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text6;
	text6.setFont(font6);
	text6.setString(" SIZE ");
	text6.setCharacterSize(22);
	text6.setFillColor(sf::Color::Blue);
	text6.setPosition(598, 10);
	text6.setStyle(sf::Text::Bold);

	sf::Font font7;
	font7.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text7;
	text7.setFont(font7);
	text7.setString(" TYPE ");
	text7.setCharacterSize(22);
	text7.setFillColor(sf::Color::Blue);
	text7.setPosition(710, 10);
	text7.setStyle(sf::Text::Bold);

	sf::Font font8;
	font8.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text8;
	text8.setFont(font8);
	text8.setString(" COLOR ");
	text8.setCharacterSize(22);
	text8.setFillColor(sf::Color::Blue);
	text8.setPosition(820, 10);
	text8.setStyle(sf::Text::Bold);
	k = 0, n = 0;
	for (int i = 0; i < maxOwners; i++) {
		for (int j = 0; j < maxProds; j++) {
			if (Owners[i].Shops.products[j].productName == s && Owners[i].Shops.products[j].Quantity != 0) {
				textname[k].setString(Owners[i].Shops.products[j].productName);
				textcate[k].setString(Owners[i].Shops.products[j].Category);
				textsize[k].setString(Owners[i].Shops.products[j].Clothes.Size);
				texttype[k].setString(Owners[i].Shops.products[j].Clothes.Type);
				textcolor[k].setString(Owners[i].Shops.products[j].Clothes.Color);
				textp[k].setString(") ");
				k++;
			}
		}
	}

	k = 0;
	for (int i = 0; i < 10; i++) {
		a[i] = i + 1;
	}

	for (int i = 0; i < 10; i++) {
		long long price1 = a[i];
		while (price1 != 0)
		{
			int m = price1 % 10;
			nump[i] += m + '0';
			price1 /= 10;
		}
		reverse(nump[i].begin(), nump[i].end());
		textnum[i].setString(nump[i]);
	}
	k = 0;
	for (int i = 0; i < maxOwners; i++) {
		for (int j = 0; j < maxProds; j++) {
			if (Owners[i].Shops.products[j].productName == s && Owners[i].Shops.products[j].Quantity != 0) {

				long long price2 = Owners[i].Shops.products[j].productPrice;
				long long price3 = Owners[i].Shops.products[j].Quantity;
				long long price4 = Owners[i].Shops.products[j].avgRating;

				while (price2 != 0) {
					int remainder = price2 % 10;
					price[n] += remainder + '0';
					price2 /= 10;
				}
				while (price3 != 0) {
					int remainder1 = price3 % 10;
					quantity[n] += remainder1 + '0';
					price3 /= 10;
				}
				while (price4 != 0)
				{
					int remainder2 = price4 % 10;
					averating[n] += remainder2 + '0';
					price4 /= 10;
				}

				reverse(price[n].begin(), price[n].end());
				textprice[k].setString(price[n]);
				reverse(quantity[n].begin(), quantity[n].end());
				textquantity[k].setString(quantity[n]);
				reverse(averating[n].begin(), averating[n].end());
				textrating[k].setString(averating[n]);
				k++;
				n++;
			}
		}
	}
	n = 0;
	int active = 0;
	bool more = false, nmore = false;
	int cc, qq;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 216 && localposition.x <= 273 && localposition.y >= 743 && localposition.y <= 774) {
					active = 1;
					cout << "nump" << endl;

				}
				else if (localposition.x >= 216 && localposition.x <= 270 && localposition.y >= 12 && localposition.y <= 741) {
					active = 2;
					cout << "quant" << endl;


				}
				else if (localposition.x >= 316 && localposition.x <= 402 && localposition.y >= 742 && localposition.y <= 776) {

					istringstream(d) >> cc;
					istringstream(q) >> qq;
					cout << "add" << endl;
					if (d.getSize() == 0 || q.getSize() == 0)
						type = true;

					else  if (d.getSize() > 0 && q.getSize() > 0) {
						if (cc <= k) {


							if (qq <= Owners[m.a[cc - 1]].Shops.products[m.b[cc - 1]].Quantity && qq != 0) {
								kk.sub[cv.index] = (qq * Owners[m.a[cc - 1]].Shops.products[m.b[cc - 1]].productPrice);
								kk.amount[cv.index] = qq;
								Owners[m.a[cc - 1]].Shops.products[m.b[cc - 1]].Quantity -= qq;
								kk.sav[cv.index].x = m.a[cc - 1];
								kk.sav[cv.index].y = m.b[cc - 1];
								cv.nump++;
								cv.index++;
								cout << qq << "  " << cc;

								for (int i = 1; i < 5; i++) {
									d.erase(d.getSize() - 1, d.getSize());
									textc.setString(d);
									if (d.getSize() == 0)
										break;
								}
								for (int i = 1; i < 5; i++) {
									q.erase(q.getSize() - 1, q.getSize());
									textq.setString(q);
									if (q.getSize() == 0)
										break;
								}
								type = false;
								more = false;
								nmore = false;
								scchoice();

							}
							else {
								type = false;
								nmore = false;
								more = true;
							}
						}
						else {
							type = false;
							nmore = true;
							more = false;
						}
					}

				}

				else if (localposition.x >= 808 && localposition.x <= 893 && localposition.y >= 747 && localposition.y <= 778) {

					return 0;
					cout << "back" << endl;

				}

				else
					active = 0;
			}

			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					d += event.text.unicode;
					textc.setString(d);
				}
				else if (active == 1 && event.text.unicode == 8 && d.getSize() > 0) {
					d.erase(d.getSize() - 1, d.getSize());
					textc.setString(d);
				}
				if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					q += event.text.unicode;
					textq.setString(q);
				}
				else if (active == 2 && event.text.unicode == 8 && q.getSize() > 0) {
					q.erase(q.getSize() - 1, q.getSize());
					textq.setString(q);
				}

			}
		}

		for (; n < k; n++) {


			textname[n].setPosition(32, hi);
			textname[n].setFont(fontname);
			textname[n].setCharacterSize(20);
			textprice[n].setPosition(165, hi);
			textprice[n].setFont(fontprice);
			textprice[n].setCharacterSize(20);
			textquantity[n].setPosition(400, hi);
			textquantity[n].setFont(fontprice);
			textquantity[n].setCharacterSize(20);
			textrating[n].setPosition(510, hi);
			textrating[n].setFont(fontprice);
			textrating[n].setCharacterSize(20);
			textcate[n].setPosition(232, ho);
			textcate[n].setFont(fontprice);
			textcate[n].setCharacterSize(15);
			textsize[n].setPosition(620, hi);
			textsize[n].setFont(fontname);
			textsize[n].setCharacterSize(20);
			texttype[n].setPosition(720, hi);
			texttype[n].setFont(fontname);
			texttype[n].setCharacterSize(20);
			textcolor[n].setPosition(840, hi);
			textcolor[n].setFont(fontname);
			textcolor[n].setCharacterSize(20);
			textnum[n].setPosition(1, hi);
			textnum[n].setFont(fontnum);
			textnum[n].setCharacterSize(20);
			textp[n].setPosition(23, hi);
			textp[n].setFont(fontp);
			textp[n].setCharacterSize(18);
			hi += 20;
			ho += 20.2;


		}

		window.draw(photo);

		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);
		window.draw(text8);
		window.draw(choice1);
		window.draw(choice2);
		window.draw(choice3);
		window.draw(choice4);
		window.draw(choice5);
		window.draw(choice6);
		window.draw(choice7);
		window.draw(choice8);
		window.draw(choice33);
		window.draw(textq);
		window.draw(text60);
		window.draw(choice20);
		window.draw(choice30);
		window.draw(choice40);
		if (type)
			window.draw(text40);
		if (more)
			window.draw(text100);
		if (nmore)
			window.draw(text200);
		window.draw(text10);

		window.draw(text30);
		window.draw(text50);

		window.draw(textc);



		for (n = 0; n < k; n++) {

			window.draw(textname[n]);
			window.draw(textprice[n]);
			window.draw(textcate[n]);
			window.draw(textquantity[n]);
			window.draw(textrating[n]);
			window.draw(textsize[n]);
			window.draw(texttype[n]);
			window.draw(textcolor[n]);
			window.draw(textnum[n]);
			window.draw(textp[n]);
		}




		window.display();
	}

}

int viewbyprice(int x, int y) {

	int number = 1, a[35];
	int z = 0;
	float hi = 50, ho = 50;
	bool next = false;

	bool type = false;
	int k = 0, n = 0;


	string nump[35];
	string price[35];
	string averating[35];
	string quantity[35];

	sf::String p;
	sf::Font fontp;
	fontp.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textp[35];

	sf::String name;
	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textname[35];


	sf::String num;
	sf::Font fontnum;
	fontnum.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textnum[35];

	sf::String cate;
	sf::Font fontcate;
	fontcate.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcate[35];

	sf::Font fontprice;
	fontprice.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textprice[35];

	sf::Font fontsize;
	fontsize.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textsize[35];

	sf::Font fontrating;
	fontrating.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textrating[35];

	sf::Font fontquantity;
	fontquantity.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textquantity[35];

	sf::Font fonttype;
	fonttype.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texttype[35];

	sf::Font fontcolor;
	fontcolor.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcolor[35];

	sf::RectangleShape choice1(sf::Vector2f(100.0f, 30.0f));
	choice1.setPosition(sf::Vector2f(5, 10));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineColor(sf::Color::Blue);
	choice1.setOutlineThickness(3);

	sf::RectangleShape choice2(sf::Vector2f(100.0f, 30.0f));
	choice2.setPosition(sf::Vector2f(120, 10));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineColor(sf::Color::Blue);
	choice2.setOutlineThickness(3);

	sf::RectangleShape choice3(sf::Vector2f(100.0f, 30.0f));
	choice3.setPosition(sf::Vector2f(235, 10));
	choice3.setFillColor(sf::Color::Transparent);
	choice3.setOutlineColor(sf::Color::Blue);
	choice3.setOutlineThickness(3);

	sf::RectangleShape choice4(sf::Vector2f(100.0f, 30.0f));
	choice4.setPosition(sf::Vector2f(350, 10));
	choice4.setFillColor(sf::Color::Transparent);
	choice4.setOutlineColor(sf::Color::Blue);
	choice4.setOutlineThickness(3);

	sf::RectangleShape choice5(sf::Vector2f(100.0f, 30.0f));
	choice5.setPosition(sf::Vector2f(465, 10));
	choice5.setFillColor(sf::Color::Transparent);
	choice5.setOutlineColor(sf::Color::Blue);
	choice5.setOutlineThickness(3);

	sf::RectangleShape choice6(sf::Vector2f(100.0f, 30.0f));
	choice6.setPosition(sf::Vector2f(580, 10));
	choice6.setFillColor(sf::Color::Transparent);
	choice6.setOutlineColor(sf::Color::Blue);
	choice6.setOutlineThickness(3);

	sf::RectangleShape choice7(sf::Vector2f(100.0f, 30.0f));
	choice7.setPosition(sf::Vector2f(695, 10));
	choice7.setFillColor(sf::Color::Transparent);
	choice7.setOutlineColor(sf::Color::Blue);
	choice7.setOutlineThickness(3);

	sf::RectangleShape choice8(sf::Vector2f(100.0f, 30.0f));
	choice8.setPosition(sf::Vector2f(810, 10));
	choice8.setFillColor(sf::Color::Transparent);
	choice8.setOutlineColor(sf::Color::Blue);
	choice8.setOutlineThickness(3);

	sf::RectangleShape choice20(sf::Vector2f(80.0f, 30.0f));
	choice20.setPosition(sf::Vector2f(320, 745));
	choice20.setFillColor(sf::Color::Transparent);
	choice20.setOutlineColor(sf::Color::Blue);
	choice20.setOutlineThickness(3);

	sf::RectangleShape choice30(sf::Vector2f(50.0f, 25.0f));
	choice30.setPosition(sf::Vector2f(220, 748));
	choice30.setFillColor(sf::Color::White);
	choice30.setOutlineColor(sf::Color::White);
	choice30.setOutlineThickness(3);

	sf::RectangleShape choice40(sf::Vector2f(80.0f, 30.0f));
	choice40.setPosition(sf::Vector2f(812, 748));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::Red);
	choice40.setOutlineThickness(3);

	sf::Font fontc;
	fontc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String c;
	sf::Text textc(c, fontc, 25);
	textc.setFillColor(sf::Color::Black);
	textc.setPosition(218, 743);

	sf::RectangleShape choice33(sf::Vector2f(50.0f, 25.0f));
	choice33.setPosition(sf::Vector2f(220, 715));
	choice33.setFillColor(sf::Color::White);
	choice33.setOutlineColor(sf::Color::White);
	choice33.setOutlineThickness(3);

	sf::Font fontq;
	fontq.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String q;
	sf::Text textq(q, fontq, 25);
	textq.setFillColor(sf::Color::Black);
	textq.setPosition(220, 715);


	sf::Font font100;
	font100.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text100;
	text100.setFont(font100);
	text100.setString(" Your Desired Quantity Is Unavalible.  ");
	text100.setCharacterSize(22);
	text100.setFillColor(sf::Color::White);
	text100.setPosition(250, 650);
	text100.setStyle(sf::Text::Bold);

	sf::Font font200;
	font200.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text200;
	text200.setFont(font200);
	text200.setString(" Invalid number.  ");
	text200.setCharacterSize(22);
	text200.setFillColor(sf::Color::White);
	text200.setPosition(340, 650);
	text200.setStyle(sf::Text::Bold);


	sf::Font font60;
	font60.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text60;
	text60.setFont(font60);
	text60.setString(" Product quantity:  ");
	text60.setCharacterSize(22);
	text60.setFillColor(sf::Color::Blue);
	text60.setPosition(15, 715);
	text60.setStyle(sf::Text::Bold);

	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" BACK ");
	text10.setCharacterSize(20);
	text10.setFillColor(sf::Color::Red);
	text10.setPosition(820, 750);
	text10.setStyle(sf::Text::Bold);

	sf::Font font30;
	font30.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text30;
	text30.setFont(font30);
	text30.setString(" Add ");
	text30.setCharacterSize(22);
	text30.setFillColor(sf::Color::Blue);
	text30.setPosition(330, 745);
	text30.setStyle(sf::Text::Bold);

	sf::Font font40;
	font40.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text40;
	text40.setFont(font30);
	text40.setString("** Please Choose a Number **");
	text40.setCharacterSize(22);
	text40.setFillColor(sf::Color::White);
	text40.setPosition(450, 745);
	text40.setStyle(sf::Text::Bold);

	sf::Font font50;
	font50.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text50;
	text50.setFont(font50);
	text50.setString(" Product number :  ");
	text50.setCharacterSize(22);
	text50.setFillColor(sf::Color::Blue);
	text50.setPosition(15, 748);
	text50.setStyle(sf::Text::Bold);

	sf::Font font1;
	font1.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text1;
	text1.setFont(font1);
	text1.setString(" NAME ");
	text1.setCharacterSize(22);
	text1.setFillColor(sf::Color::Blue);
	text1.setPosition(14, 10);
	text1.setStyle(sf::Text::Bold);

	sf::Font font2;
	font2.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text2;
	text2.setFont(font2);
	text2.setString(" PRICE ");
	text2.setCharacterSize(22);
	text2.setFillColor(sf::Color::Blue);
	text2.setPosition(130, 10);
	text2.setStyle(sf::Text::Bold);

	sf::Font font3;
	font3.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text3;
	text3.setFont(font3);
	text3.setString(" CATEGORY  ");
	text3.setCharacterSize(18);
	text3.setFillColor(sf::Color::Blue);
	text3.setPosition(232, 14);
	text3.setStyle(sf::Text::Bold);

	sf::Font font4;
	font4.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text4;
	text4.setFont(font4);
	text4.setString("  QUANTITY ");
	text4.setCharacterSize(19);
	text4.setFillColor(sf::Color::Blue);
	text4.setPosition(340, 13);
	text4.setStyle(sf::Text::Bold);

	sf::Font font5;
	font5.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text5;
	text5.setFont(font5);
	text5.setString("  RATING ");
	text5.setCharacterSize(21);
	text5.setFillColor(sf::Color::Blue);
	text5.setPosition(461, 11);
	text5.setStyle(sf::Text::Bold);

	sf::Font font6;
	font6.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text6;
	text6.setFont(font6);
	text6.setString(" SIZE ");
	text6.setCharacterSize(22);
	text6.setFillColor(sf::Color::Blue);
	text6.setPosition(598, 10);
	text6.setStyle(sf::Text::Bold);

	sf::Font font7;
	font7.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text7;
	text7.setFont(font7);
	text7.setString(" TYPE ");
	text7.setCharacterSize(22);
	text7.setFillColor(sf::Color::Blue);
	text7.setPosition(710, 10);
	text7.setStyle(sf::Text::Bold);

	sf::Font font8;
	font8.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text8;
	text8.setFont(font8);
	text8.setString(" COLOR ");
	text8.setCharacterSize(22);
	text8.setFillColor(sf::Color::Blue);
	text8.setPosition(820, 10);
	text8.setStyle(sf::Text::Bold);
	k = 0, n = 0;
	for (int i = 0; i < maxOwners; i++) {
		for (int j = 0; j < maxProds; j++) {
			if (Owners[i].Shops.products[j].productPrice > x && Owners[i].Shops.products[j].productPrice < y && Owners[i].Shops.products[j].Quantity != 0) {
				textname[k].setString(Owners[i].Shops.products[j].productName);
				textcate[k].setString(Owners[i].Shops.products[j].Category);
				textsize[k].setString(Owners[i].Shops.products[j].Clothes.Size);
				texttype[k].setString(Owners[i].Shops.products[j].Clothes.Type);
				textcolor[k].setString(Owners[i].Shops.products[j].Clothes.Color);
				textp[k].setString(") ");
				m.a[k] = i;
				m.b[k] = j;
				k++;
			}
		}
	}

	k = 0;
	for (int i = 0; i < 20; i++) {
		a[i] = i + 1;
	}

	for (int i = 0; i < 20; i++) {
		long long price1 = a[i];
		while (price1 != 0)
		{
			int m = price1 % 10;
			nump[i] += m + '0';
			price1 /= 10;
		}
		reverse(nump[i].begin(), nump[i].end());
		textnum[i].setString(nump[i]);
	}

	for (int i = 0; i < maxOwners; i++) {
		for (int j = 0; j < maxProds; j++) {
			if (Owners[i].Shops.products[j].productPrice > x && Owners[i].Shops.products[j].productPrice < y && Owners[i].Shops.products[j].Quantity != 0) {

				long long price2 = Owners[i].Shops.products[j].productPrice;
				long long price3 = Owners[i].Shops.products[j].Quantity;
				long long price4 = Owners[i].Shops.products[j].avgRating;

				while (price2 != 0) {
					int remainder = price2 % 10;
					price[k] += remainder + '0';
					price2 /= 10;
				}
				while (price3 != 0) {
					int remainder1 = price3 % 10;
					quantity[k] += remainder1 + '0';
					price3 /= 10;
				}
				while (price4 != 0)
				{
					int remainder2 = price4 % 10;
					averating[k] += remainder2 + '0';
					price4 /= 10;
				}


				reverse(price[k].begin(), price[k].end());
				textprice[k].setString(price[k]);
				reverse(quantity[k].begin(), quantity[k].end());
				textquantity[k].setString(quantity[k]);
				reverse(averating[k].begin(), averating[k].end());
				textrating[k].setString(averating[k]);
				k++;
			}
		}
	}
	int cc, qq;
	bool more = false, nmore = false;
	int active = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 216 && localposition.x <= 273 && localposition.y >= 743 && localposition.y <= 774) {
					active = 1;
					cout << "nump" << endl;

				}
				else if (localposition.x >= 316 && localposition.x <= 402 && localposition.y >= 742 && localposition.y <= 776) {
					cout << "add" << endl;
					cout << "add" << endl;

					istringstream(c) >> cc;
					istringstream(q) >> qq;

					if (c.getSize() == 0 || q.getSize() == 0)
						type = true;
					else  if (c.getSize() > 0 && q.getSize() > 0) {
						if (cc <= k) {


							if (qq <= Owners[m.a[cc - 1]].Shops.products[m.b[cc - 1]].Quantity && qq != 0) {
								kk.sub[cv.index] = (qq * Owners[m.a[cc - 1]].Shops.products[m.b[cc - 1]].productPrice);
								kk.amount[cv.index] = qq;
								Owners[m.a[cc - 1]].Shops.products[m.b[cc - 1]].Quantity -= qq;
								kk.sav[cv.index].x = m.a[cc - 1];
								kk.sav[cv.index].y = m.b[cc - 1];
								cv.nump++;
								cv.index++;
								cout << qq << "  " << cc;

								for (int i = 1; i < 5; i++) {
									c.erase(c.getSize() - 1, c.getSize());
									textc.setString(c);
									if (c.getSize() == 0)
										break;
								}
								for (int i = 1; i < 5; i++) {
									q.erase(q.getSize() - 1, q.getSize());
									textq.setString(q);
									if (q.getSize() == 0)
										break;
								}
								type = false;
								more = false;
								nmore = false;

							}
							else {
								type = false;
								nmore = false;
								more = true;
							}
						}
						else {
							type = false;
							nmore = true;
							more = false;
						}
					}

				}
				else if (localposition.x >= 216 && localposition.x <= 270 && localposition.y >= 12 && localposition.y <= 741) {

					active = 2;
					cout << "quant" << endl;


				}
				else if (localposition.x >= 808 && localposition.x <= 893 && localposition.y >= 747 && localposition.y <= 778) {
					return 0;
					cout << "back" << endl;

				}

				else
					active = 0;
			}

			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					c += event.text.unicode;
					textc.setString(c);
				}
				else if (active == 1 && event.text.unicode == 8 && c.getSize() > 0) {
					c.erase(c.getSize() - 1, c.getSize());
					textc.setString(c);
				}
				if (active == 2 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					q += event.text.unicode;
					textq.setString(q);
				}
				else if (active == 2 && event.text.unicode == 8 && q.getSize() > 0) {
					q.erase(q.getSize() - 1, q.getSize());
					textq.setString(q);
				}

			}
		}

		for (; n < k; n++) {


			textname[n].setPosition(32, hi);
			textname[n].setFont(fontname);
			textname[n].setCharacterSize(20);
			textprice[n].setPosition(165, hi);
			textprice[n].setFont(fontprice);
			textprice[n].setCharacterSize(20);
			textquantity[n].setPosition(400, hi);
			textquantity[n].setFont(fontprice);
			textquantity[n].setCharacterSize(20);
			textrating[n].setPosition(510, hi);
			textrating[n].setFont(fontprice);
			textrating[n].setCharacterSize(20);
			textcate[n].setPosition(232, ho);
			textcate[n].setFont(fontprice);
			textcate[n].setCharacterSize(15);
			textsize[n].setPosition(620, hi);
			textsize[n].setFont(fontname);
			textsize[n].setCharacterSize(20);
			texttype[n].setPosition(720, hi);
			texttype[n].setFont(fontname);
			texttype[n].setCharacterSize(20);
			textcolor[n].setPosition(840, hi);
			textcolor[n].setFont(fontname);
			textcolor[n].setCharacterSize(20);
			textnum[n].setPosition(1, hi);
			textnum[n].setFont(fontnum);
			textnum[n].setCharacterSize(20);
			textp[n].setPosition(23, hi);
			textp[n].setFont(fontp);
			textp[n].setCharacterSize(18);
			hi += 20;
			ho += 20.2;


		}

		window.draw(photo);

		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.draw(text5);
		window.draw(text6);
		window.draw(text7);
		window.draw(text8);
		window.draw(choice1);
		window.draw(choice2);
		window.draw(choice3);
		window.draw(choice4);
		window.draw(choice5);
		window.draw(choice6);
		window.draw(choice7);
		window.draw(choice8);
		window.draw(choice33);
		window.draw(textq);
		window.draw(text60);
		window.draw(choice20);
		window.draw(choice30);
		window.draw(choice40);
		if (type)
			window.draw(text40);
		if (more)
			window.draw(text100);
		if (nmore)
			window.draw(text200);
		window.draw(text10);
		window.draw(text30);
		window.draw(text50);
		window.draw(textc);

		for (n = 0; n < k; n++) {

			window.draw(textname[n]);
			window.draw(textprice[n]);
			window.draw(textcate[n]);
			window.draw(textquantity[n]);
			window.draw(textrating[n]);
			window.draw(textsize[n]);
			window.draw(texttype[n]);
			window.draw(textcolor[n]);
			window.draw(textnum[n]);
			window.draw(textp[n]);
		}

		window.display();
	}

}

int rating() {

	sf::RectangleShape choice1(sf::Vector2f(50.0f, 20.0f));
	choice1.setPosition(sf::Vector2f(560, 110));
	choice1.setFillColor(sf::Color::White);
	choice1.setOutlineColor(sf::Color::White);
	choice1.setOutlineThickness(7);


	sf::RectangleShape choice2(sf::Vector2f(80.0f, 40.0f));
	choice2.setPosition(sf::Vector2f(750, 110));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineColor(sf::Color::Red);
	choice2.setOutlineThickness(3);

	sf::RectangleShape choice3(sf::Vector2f(80.0f, 40.0f));
	choice3.setPosition(sf::Vector2f(750, 160));
	choice3.setFillColor(sf::Color::Transparent);
	choice3.setOutlineColor(sf::Color::Red);
	choice3.setOutlineThickness(3);



	sf::Font fontnum;
	fontnum.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String num;
	sf::Text textnum(num, fontnum, 25);
	textnum.setFillColor(sf::Color::Black);
	textnum.setPosition(560, 105);

	sf::Font fonta;
	fonta.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texta;
	texta.setFont(fonta);
	texta.setString(" Product's number ");
	texta.setCharacterSize(30);
	texta.setFillColor(sf::Color::White);
	texta.setPosition(280, 100);
	texta.setStyle(sf::Text::Bold);

	sf::Font fontb;
	fontb.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textb;
	textb.setFont(fontb);
	textb.setString(" Rate this product : ");
	textb.setCharacterSize(30);
	textb.setFillColor(sf::Color::White);
	textb.setPosition(40, 220);
	textb.setStyle(sf::Text::Bold);

	sf::Font fontc;
	fontc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textc;
	textc.setFont(fontc);
	textc.setString(" Rate  ");
	textc.setCharacterSize(30);
	textc.setFillColor(sf::Color::Red);
	textc.setPosition(750, 110);
	textc.setStyle(sf::Text::Bold);


	sf::Font fontd;
	fontd.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textd;
	textd.setFont(fontd);
	textd.setString(" Back ");
	textd.setCharacterSize(30);
	textd.setFillColor(sf::Color::Red);
	textd.setPosition(750, 160);
	textd.setStyle(sf::Text::Bold);


	sf::ConvexShape star(11);
	star.setOutlineColor(sf::Color::Black);
	star.setFillColor(sf::Color(225, 247, 164));
	star.setPoint(0, sf::Vector2f(100, 0));
	star.setPoint(1, sf::Vector2f(77, 68));
	star.setPoint(2, sf::Vector2f(5, 69));
	star.setPoint(3, sf::Vector2f(63, 112));
	star.setPoint(4, sf::Vector2f(42, 180));
	star.setPoint(5, sf::Vector2f(100, 139));
	star.setPoint(6, sf::Vector2f(158, 180));
	star.setPoint(7, sf::Vector2f(137, 112));
	star.setPoint(8, sf::Vector2f(194, 69));
	star.setPoint(9, sf::Vector2f(123, 68));
	star.setPoint(10, sf::Vector2f(100, 0));
	star.setPosition(320, 200);
	star.setScale(0.4, 0.4);
	star.setFillColor(sf::Color(255, 255, 255));

	sf::ConvexShape star2(11);
	star2.setOutlineColor(sf::Color::Black);
	star2.setFillColor(sf::Color(225, 247, 164));
	star2.setPoint(0, sf::Vector2f(100, 0));
	star2.setPoint(1, sf::Vector2f(77, 68));
	star2.setPoint(2, sf::Vector2f(5, 69));
	star2.setPoint(3, sf::Vector2f(63, 112));
	star2.setPoint(4, sf::Vector2f(42, 180));
	star2.setPoint(5, sf::Vector2f(100, 139));
	star2.setPoint(6, sf::Vector2f(158, 180));
	star2.setPoint(7, sf::Vector2f(137, 112));
	star2.setPoint(8, sf::Vector2f(194, 69));
	star2.setPoint(9, sf::Vector2f(123, 68));
	star2.setPoint(10, sf::Vector2f(100, 0));
	star2.setPosition(400, 200);
	star2.setScale(0.4, 0.4);
	star2.setFillColor(sf::Color(255, 255, 255));

	sf::ConvexShape star3(11);
	star3.setOutlineColor(sf::Color::Black);
	star3.setFillColor(sf::Color(225, 247, 164));
	star3.setPoint(0, sf::Vector2f(100, 0));
	star3.setPoint(1, sf::Vector2f(77, 68));
	star3.setPoint(2, sf::Vector2f(5, 69));
	star3.setPoint(3, sf::Vector2f(63, 112));
	star3.setPoint(4, sf::Vector2f(42, 180));
	star3.setPoint(5, sf::Vector2f(100, 139));
	star3.setPoint(6, sf::Vector2f(158, 180));
	star3.setPoint(7, sf::Vector2f(137, 112));
	star3.setPoint(8, sf::Vector2f(194, 69));
	star3.setPoint(9, sf::Vector2f(123, 68));
	star3.setPoint(10, sf::Vector2f(100, 0));
	star3.setPosition(480, 200);
	star3.setScale(0.4, 0.4);
	star3.setFillColor(sf::Color(255, 255, 255));

	sf::ConvexShape star4(11);
	star4.setOutlineColor(sf::Color::Black);
	star4.setFillColor(sf::Color(225, 247, 164));
	star4.setPoint(0, sf::Vector2f(100, 0));
	star4.setPoint(1, sf::Vector2f(77, 68));
	star4.setPoint(2, sf::Vector2f(5, 69));
	star4.setPoint(3, sf::Vector2f(63, 112));
	star4.setPoint(4, sf::Vector2f(42, 180));
	star4.setPoint(5, sf::Vector2f(100, 139));
	star4.setPoint(6, sf::Vector2f(158, 180));
	star4.setPoint(7, sf::Vector2f(137, 112));
	star4.setPoint(8, sf::Vector2f(194, 69));
	star4.setPoint(9, sf::Vector2f(123, 68));
	star4.setPoint(10, sf::Vector2f(100, 0));
	star4.setPosition(560, 200);
	star4.setScale(0.4, 0.4);
	star4.setFillColor(sf::Color(255, 255, 255));

	sf::ConvexShape star5(11);
	star5.setOutlineColor(sf::Color::Black);
	star5.setFillColor(sf::Color(225, 247, 164));
	star5.setPoint(0, sf::Vector2f(100, 0));
	star5.setPoint(1, sf::Vector2f(77, 68));
	star5.setPoint(2, sf::Vector2f(5, 69));
	star5.setPoint(3, sf::Vector2f(63, 112));
	star5.setPoint(4, sf::Vector2f(42, 180));
	star5.setPoint(5, sf::Vector2f(100, 139));
	star5.setPoint(6, sf::Vector2f(158, 180));
	star5.setPoint(7, sf::Vector2f(137, 112));
	star5.setPoint(8, sf::Vector2f(194, 69));
	star5.setPoint(9, sf::Vector2f(123, 68));
	star5.setPoint(10, sf::Vector2f(100, 0));
	star5.setPosition(640, 200);
	star5.setScale(0.4, 0.4);
	star5.setFillColor(sf::Color(255, 255, 255));

	bool fill = false;
	int active = 0, ratenum = 0, rating = 0;
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 552 && localposition.x <= 615 && localposition.y >= 103 && localposition.y <= 135) {
					active = 1;
					cout << "Number" << endl;

				}
				else if (localposition.x >= 747 && localposition.x <= 830 && localposition.y >= 107 && localposition.y <= 152 && num.getSize() > 0) {

					cout << "save" << endl;
					istringstream(num) >> ratenum;
					if (ratenum <= cv.nump) {
						ogRating(ratenum, rating);
						receipt(LogID);
					}
				}
				else if (localposition.x >= 747 && localposition.x <= 830 && localposition.y >= 159 && localposition.y <= 202) {

					cout << "back" << endl;
					return 0;
				}
				else if (localposition.x >= 324 && localposition.x <= 390 && localposition.y >= 201 && localposition.y <= 270) {
					active = 2;
					cout << "star 1" << endl;
					rating = 1;

				}
				else if (localposition.x >= 403 && localposition.x <= 470 && localposition.y >= 201 && localposition.y <= 270) {
					active = 3;
					cout << "star 2" << endl;
					rating = 2;
				}
				else if (localposition.x >= 499 && localposition.x <= 540 && localposition.y >= 201 && localposition.y <= 270) {
					active = 4;
					cout << "star 3" << endl;
					rating = 3;
				}
				else if (localposition.x >= 575 && localposition.x <= 625 && localposition.y >= 201 && localposition.y <= 270) {
					active = 5;
					cout << "star 4" << endl;
					rating = 4;
				}
				else if (localposition.x >= 649 && localposition.x <= 711 && localposition.y >= 201 && localposition.y <= 270) {
					active = 6;
					cout << "star 5" << endl;
					rating = 5;
				}
				else
				{
					active = 0;
				}
			}
			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					num += event.text.unicode;
					textnum.setString(num);
				}
				else if (active == 1 && event.text.unicode == 8 && num.getSize() > 0) {
					num.erase(num.getSize() - 1, num.getSize());
					textnum.setString(num);
				}
			}
			if (active == 2)
			{
				star.setFillColor(sf::Color(255, 255, 0));
				star2.setFillColor(sf::Color(255, 255, 255));
				star3.setFillColor(sf::Color(255, 255, 255));
				star4.setFillColor(sf::Color(255, 255, 255));
				star5.setFillColor(sf::Color(255, 255, 255));
			}
			else if (active == 3)
			{
				star.setFillColor(sf::Color(255, 255, 0));
				star2.setFillColor(sf::Color(255, 255, 0));
				star3.setFillColor(sf::Color(255, 255, 255));
				star4.setFillColor(sf::Color(255, 255, 255));
				star5.setFillColor(sf::Color(255, 255, 255));
			}
			else if (active == 4)
			{
				star.setFillColor(sf::Color(255, 255, 0));
				star2.setFillColor(sf::Color(255, 255, 0));
				star3.setFillColor(sf::Color(255, 255, 0));
				star4.setFillColor(sf::Color(255, 255, 255));
				star5.setFillColor(sf::Color(255, 255, 255));
			}
			else if (active == 5)
			{
				star.setFillColor(sf::Color(255, 255, 0));
				star2.setFillColor(sf::Color(255, 255, 0));
				star3.setFillColor(sf::Color(255, 255, 0));
				star4.setFillColor(sf::Color(255, 255, 0));
				star5.setFillColor(sf::Color(255, 255, 255));
			}
			else if (active == 6)
			{
				star.setFillColor(sf::Color(255, 255, 0));
				star2.setFillColor(sf::Color(255, 255, 0));
				star3.setFillColor(sf::Color(255, 255, 0));
				star4.setFillColor(sf::Color(255, 255, 0));
				star5.setFillColor(sf::Color(255, 255, 0));
			}
		}


		window.draw(photo);
		window.draw(star);
		window.draw(star2);
		window.draw(star3);
		window.draw(star4);
		window.draw(star5);
		window.draw(choice1);
		window.draw(choice2);
		window.draw(choice3);
		window.draw(textb);
		window.draw(textc);
		window.draw(textd);
		window.draw(texta);
		window.draw(textnum);
		window.display();
	}
}

int byshop() {


	int a[maxOwners];

	sf::RectangleShape choice8(sf::Vector2f(100.0f, 30.0f));
	choice8.setPosition(sf::Vector2f(800, 747));
	choice8.setFillColor(sf::Color::Transparent);
	choice8.setOutlineColor(sf::Color::Red);
	choice8.setOutlineThickness(3);

	sf::Font fontc;
	fontc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::String c;
	sf::Text textc(c, fontc, 25);
	textc.setFillColor(sf::Color::Black);
	textc.setPosition(218, 743);

	sf::String num;
	sf::Font fontnum;
	fontnum.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textnum[maxOwners];

	string nump[maxOwners];

	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" BACK ");
	text10.setCharacterSize(20);
	text10.setFillColor(sf::Color::Red);
	text10.setPosition(820, 750);
	text10.setStyle(sf::Text::Bold);

	sf::RectangleShape choice30(sf::Vector2f(50.0f, 25.0f));
	choice30.setPosition(sf::Vector2f(220, 748));
	choice30.setFillColor(sf::Color::White);
	choice30.setOutlineColor(sf::Color::White);
	choice30.setOutlineThickness(3);

	sf::RectangleShape choice20(sf::Vector2f(80.0f, 30.0f));
	choice20.setPosition(sf::Vector2f(320, 745));
	choice20.setFillColor(sf::Color::Transparent);
	choice20.setOutlineColor(sf::Color::White);
	choice20.setOutlineThickness(3);

	sf::Font font30;
	font30.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text30;
	text30.setFont(font30);
	text30.setString(" View ");
	text30.setCharacterSize(22);
	text30.setFillColor(sf::Color::White);
	text30.setPosition(325, 745);
	text30.setStyle(sf::Text::Bold);

	sf::Font font40;
	font40.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text40;
	text40.setFont(font30);
	text40.setString("** Please Choose Number **");
	text40.setCharacterSize(22);
	text40.setFillColor(sf::Color::White);
	text40.setPosition(450, 745);
	text40.setStyle(sf::Text::Bold);

	sf::String p;
	sf::Font fontp;
	fontp.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textp[75];

	sf::Font font50;
	font50.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text50;
	text50.setFont(font50);
	text50.setString("    Shop number :  ");
	text50.setCharacterSize(22);
	text50.setFillColor(sf::Color::White);
	text50.setPosition(20, 748);
	text50.setStyle(sf::Text::Bold);

	sf::Font font60;
	font60.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text60;
	text60.setFont(font60);
	text60.setString("    Shop Names .  ");
	text60.setCharacterSize(40);
	text60.setFillColor(sf::Color::White);
	text60.setPosition(20, 20);
	text60.setStyle(sf::Text::Bold);

	sf::Font fontshop;
	fontshop.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textshop[maxOwners];



	int n = 0, k = 0;
	double hi = 100;

	for (int i = 0, k = 0; i < maxOwners; i++) {
		if (Owners[i].Shops.ShopName != ("")) {
			textshop[i].setString(Owners[i].Shops.ShopName);
			textp[k].setString(") ");
			n++;
			k++;
		}

	}


	for (int i = 0; i < maxOwners; i++) {
		a[i] = i + 1;
	}
	for (int i = 0; i < maxOwners; i++) {
		long long price1 = a[i];
		while (price1 != 0)
		{
			int m = price1 % 10;
			nump[i] += m + '0';
			price1 /= 10;
		}
		reverse(nump[i].begin(), nump[i].end());
		textnum[i].setString(nump[i]);
	}


	bool type = false;
	int active = 0, nums = 1;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 216 && localposition.x <= 273 && localposition.y >= 743 && localposition.y <= 774) {
					active = 1;
					cout << "nump" << endl;

				}
				else if (localposition.x >= 316 && localposition.x <= 402 && localposition.y >= 742 && localposition.y <= 776) {
					//function l add
					cout << "add" << endl;
					int j;
					string shop;
					istringstream(c) >> j;
					for (int i = 0; i < n; i++) {
						if (i == j - 1) {
							shop = Owners[i].Shops.ShopName;
						}
					}


					if (c.getSize() == 0)
						type = true;
					else {
						for (int i = 1; i < 5; i++) {
							c.erase(c.getSize() - 1, c.getSize());
							textc.setString(c);
							if (c.getSize() == 0)
								viewbystring(shop, nums);
							break;
						}
					}

				}

				else if (localposition.x >= 797 && localposition.x <= 903 && localposition.y >= 745 && localposition.y <= 778) {
					return 0;
					cout << "back" << endl;

				}

				else
					active = 0;
			}

			if (event.type == sf::Event::TextEntered) {

				if (active == 1 && event.text.unicode >= 32 && event.text.unicode <= 126 && event.text.unicode != 8) {
					c += event.text.unicode;
					textc.setString(c);
				}
				else if (active == 1 && event.text.unicode == 8 && c.getSize() > 0) {
					c.erase(c.getSize() - 1, c.getSize());
					textc.setString(c);
				}

			}
		}


		for (; k < n; k++) {


			textshop[k].setPosition(50, hi);
			textshop[k].setFont(fontshop);
			textshop[k].setCharacterSize(20);
			textnum[k].setPosition(10, hi);
			textnum[k].setFont(fontnum);
			textnum[k].setCharacterSize(20);
			textp[k].setPosition(30, hi);
			textp[k].setFont(fontnum);
			textp[k].setCharacterSize(20);

			hi += 50;



		}


		window.draw(photo);

		window.draw(choice20);
		window.draw(choice30);
		window.draw(choice8);
		window.draw(text60);
		window.draw(text30);
		window.draw(text10);
		window.draw(text50);
		if (type) {
			window.draw(text40);
		}

		window.draw(textc);
		for (k = 0; k < n; k++) {

			window.draw(textshop[k]);
			window.draw(textnum[k]);
			window.draw(textp[k]);
		}
		window.display();
	}
}

int bycategory() {

	sf::RectangleShape choice8(sf::Vector2f(110.0f, 35.0f));
	choice8.setPosition(sf::Vector2f(750, 30));
	choice8.setFillColor(sf::Color::Transparent);
	choice8.setOutlineThickness(5);
	choice8.setOutlineColor(sf::Color::Red);

	sf::RectangleShape choice10(sf::Vector2f(330.0f, 40.0f));
	choice10.setPosition(sf::Vector2f(30, 190));
	choice10.setFillColor(sf::Color::Transparent);
	choice10.setOutlineColor(sf::Color::White);
	choice10.setOutlineThickness(3);

	sf::RectangleShape choice20(sf::Vector2f(330.0f, 40.0f));
	choice20.setPosition(sf::Vector2f(30, 260));
	choice20.setFillColor(sf::Color::Transparent);
	choice20.setOutlineColor(sf::Color::White);
	choice20.setOutlineThickness(3);

	sf::RectangleShape choice30(sf::Vector2f(330.0f, 40.0f));
	choice30.setPosition(sf::Vector2f(30, 330));
	choice30.setFillColor(sf::Color::Transparent);
	choice30.setOutlineColor(sf::Color::White);
	choice30.setOutlineThickness(3);

	sf::RectangleShape choice40(sf::Vector2f(330.0f, 40.0f));
	choice40.setPosition(sf::Vector2f(30, 400));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::White);
	choice40.setOutlineThickness(3);

	sf::RectangleShape choice50(sf::Vector2f(330.0f, 40.0f));
	choice50.setPosition(sf::Vector2f(30, 470));
	choice50.setFillColor(sf::Color::Transparent);
	choice50.setOutlineColor(sf::Color::White);
	choice50.setOutlineThickness(3);

	sf::RectangleShape choice60(sf::Vector2f(330.0f, 40.0f));
	choice60.setPosition(sf::Vector2f(30, 540));
	choice60.setFillColor(sf::Color::Transparent);
	choice60.setOutlineColor(sf::Color::White);
	choice60.setOutlineThickness(3);

	sf::RectangleShape choice70(sf::Vector2f(330.0f, 40.0f));
	choice70.setPosition(sf::Vector2f(30, 610));
	choice70.setFillColor(sf::Color::Transparent);
	choice70.setOutlineColor(sf::Color::White);
	choice70.setOutlineThickness(3);

	sf::Font font1;
	font1.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text1;
	text1.setFont(font1);
	text1.setString(" Phones & Tablets ");
	text1.setCharacterSize(30);
	text1.setFillColor(sf::Color::White);
	text1.setPosition(50, 188);
	text1.setStyle(sf::Text::Bold);

	sf::Font font2;
	font2.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text2;
	text2.setFont(font2);
	text2.setString("      Electronics ");
	text2.setCharacterSize(30);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(60, 258);
	text2.setStyle(sf::Text::Bold);

	sf::Font font3;
	font3.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text3;
	text3.setFont(font3);
	text3.setString(" Makeup & Accessories ");
	text3.setCharacterSize(30);
	text3.setFillColor(sf::Color::White);
	text3.setPosition(30, 328);
	text3.setStyle(sf::Text::Bold);

	sf::Font font4;
	font4.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text4;
	text4.setFont(font4);
	text4.setString("        Clothing ");
	text4.setCharacterSize(30);
	text4.setFillColor(sf::Color::White);
	text4.setPosition(60, 398);
	text4.setStyle(sf::Text::Bold);

	sf::Font font5;
	font5.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text5;
	text5.setFont(font5);
	text5.setString("       Shoes & Bags ");
	text5.setCharacterSize(30);
	text5.setFillColor(sf::Color::White);
	text5.setPosition(58, 468);
	text5.setStyle(sf::Text::Bold);

	sf::Font font6;
	font6.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text6;
	text6.setFont(font5);
	text6.setString("         Books ");
	text6.setCharacterSize(30);
	text6.setFillColor(sf::Color::White);
	text6.setPosition(62, 538);
	text6.setStyle(sf::Text::Bold);

	sf::Font font7;
	font7.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text7;
	text7.setFont(font5);
	text7.setString("         Gaming ");
	text7.setCharacterSize(30);
	text7.setFillColor(sf::Color::White);
	text7.setPosition(60, 608);
	text7.setStyle(sf::Text::Bold);

	sf::Font font8;
	font8.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text8;
	text8.setFont(font8);
	text8.setString("   Choose One Category ");
	text8.setCharacterSize(50);
	text8.setFillColor(sf::Color::White);
	text8.setPosition(30, 70);
	text8.setStyle(sf::Text::Bold);

	sf::Font font9;
	font9.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text9;
	text9.setFont(font9);
	text9.setString("  BACK ");
	text9.setCharacterSize(30);
	text9.setFillColor(sf::Color::Red);
	text9.setPosition(750, 30);
	text9.setStyle(sf::Text::Bold);

	string g;
	int  num = 2;
	bool fill = false;
	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 28 && localposition.x <= 362 && localposition.y >= 189 && localposition.y <= 227) {
					g = ("Phones&Tablets");
					cout << "phones&tablets" << endl;
					viewbystring(g, num);
				}
				else if (localposition.x >= 28 && localposition.x <= 362 && localposition.y >= 259 && localposition.y <= 295) {
					g = ("Electronics");
					cout << "electronics" << endl;
					viewbystring(g, num);
				}
				else if (localposition.x >= 28 && localposition.x <= 362 && localposition.y >= 327 && localposition.y <= 370) {
					g = ("Makeup&Accessories");
					cout << "makeup & accessories" << endl;
					viewbystring(g, num);
				}
				else if (localposition.x >= 28 && localposition.x <= 362 && localposition.y >= 399 && localposition.y <= 439) {
					g = ("Clothing");
					cout << "clothing" << endl;
					viewbystring(g, num);
				}
				else if (localposition.x >= 28 && localposition.x <= 362 && localposition.y >= 469 && localposition.y <= 505) {
					g = ("Shoes&Bags");
					cout << "shoes & bags" << endl;
					viewbystring(g, num);
				}
				else if (localposition.x >= 28 && localposition.x <= 362 && localposition.y >= 541 && localposition.y <= 575) {
					g = ("Books");
					cout << "books" << endl;
					viewbystring(g, num);
				}
				else if (localposition.x >= 28 && localposition.x <= 362 && localposition.y >= 607 && localposition.y <= 649) {
					g = ("Gaming");
					cout << "gaming" << endl;
					viewbystring(g, num);
				}
				else if (localposition.x >= 743 && localposition.x <= 865 && localposition.y >= 25 && localposition.y <= 68) {
					return 0;
				}
			}

			window.clear();
			window.draw(photo);
			window.draw(choice8);
			window.draw(choice10);
			window.draw(choice20);
			window.draw(choice30);
			window.draw(choice40);
			window.draw(choice40);
			window.draw(choice50);
			window.draw(choice60);
			window.draw(choice70);
			window.draw(text1);
			window.draw(text2);
			window.draw(text3);
			window.draw(text4);
			window.draw(text5);
			window.draw(text6);
			window.draw(text7);
			window.draw(text8);
			window.draw(text9);


			window.display();

		}
	}


}

int byprice() {

	sf::RectangleShape choice1(sf::Vector2f(320.0f, 80.0f));
	choice1.setPosition(sf::Vector2f(250, 100));
	choice1.setFillColor(sf::Color::Transparent);
	choice1.setOutlineThickness(5);
	choice1.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice2(sf::Vector2f(320.0f, 80.0f));
	choice2.setPosition(sf::Vector2f(250, 225));
	choice2.setFillColor(sf::Color::Transparent);
	choice2.setOutlineThickness(5);
	choice2.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice3(sf::Vector2f(320.0f, 80.0f));
	choice3.setPosition(sf::Vector2f(250, 350));
	choice3.setFillColor(sf::Color::Transparent);
	choice3.setOutlineThickness(5);
	choice3.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice4(sf::Vector2f(320.0f, 80.0f));
	choice4.setPosition(sf::Vector2f(250, 475));
	choice4.setFillColor(sf::Color::Transparent);
	choice4.setOutlineThickness(5);
	choice4.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice5(sf::Vector2f(320.0f, 80.0f));
	choice5.setPosition(sf::Vector2f(250, 600));
	choice5.setFillColor(sf::Color::Transparent);
	choice5.setOutlineThickness(5);
	choice5.setOutlineColor(sf::Color::White);

	sf::RectangleShape choice0(sf::Vector2f(110.0f, 25.0f));
	choice0.setPosition(sf::Vector2f(770, 15));
	choice0.setFillColor(sf::Color::Transparent);
	choice0.setOutlineThickness(3);
	choice0.setOutlineColor(sf::Color::White);

	sf::Font fontz;
	fontz.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textz;
	textz.setFont(fontz);
	textz.setString("    BACK   ");
	textz.setCharacterSize(20);
	textz.setFillColor(sf::Color::White);
	textz.setPosition(770, 15);
	textz.setStyle(sf::Text::Regular);

	sf::Font fonta;
	fonta.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texta;
	texta.setFont(fonta);
	texta.setString(" From 1$ - TO 50$ ");
	texta.setCharacterSize(30);
	texta.setFillColor(sf::Color::White);
	texta.setPosition(283, 118);
	texta.setStyle(sf::Text::Bold);

	sf::Font fontb;
	fontb.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textb;
	textb.setFont(fontb);
	textb.setString("From 50$ - TO 200$ ");
	textb.setCharacterSize(30);
	textb.setFillColor(sf::Color::White);
	textb.setPosition(270, 243);
	textb.setStyle(sf::Text::Bold);

	sf::Font fontc;
	fontc.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textc;
	textc.setFont(fontc);
	textc.setString(" From 200$ - TO 500$ ");
	textc.setCharacterSize(30);
	textc.setFillColor(sf::Color::White);
	textc.setPosition(250, 368);
	textc.setStyle(sf::Text::Bold);

	sf::Font fontd;
	fontd.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textd;
	textd.setFont(fontd);
	textd.setString(" From 500$ - TO 1000$");
	textd.setCharacterSize(30);
	textd.setFillColor(sf::Color::White);
	textd.setPosition(247, 494);
	textd.setStyle(sf::Text::Bold);

	sf::Font fonte;
	fonte.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texte;
	texte.setFont(fonte);
	texte.setString("From 1000$ - TO 20000 ");
	texte.setCharacterSize(28);
	texte.setFillColor(sf::Color::White);
	texte.setPosition(250, 618);
	texte.setStyle(sf::Text::Bold);

	int x, y;
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << "{" << localposition.x << "-" << localposition.y << "]" << endl;
				if (localposition.x >= 245 && localposition.x <= 570 && localposition.y >= 93 && localposition.y <= 177) {
					cout << "1-50" << endl;
					x = 1;
					y = 50;
					viewbyprice(x, y);

				}
				else if (localposition.x >= 245 && localposition.x <= 570 && localposition.y >= 221 && localposition.y <= 302) {
					cout << "50-200" << endl;
					x = 50;
					y = 200;
					viewbyprice(x, y);
				}
				else if (localposition.x >= 245 && localposition.x <= 570 && localposition.y >= 345 && localposition.y <= 428) {
					cout << "200-500" << endl;
					x = 200;
					y = 500;
					viewbyprice(x, y);

				}
				else if (localposition.x >= 767 && localposition.x <= 883 && localposition.y >= 10 && localposition.y <= 41) {
					cout << "back" << endl;
					return 0;
				}
				else if (localposition.x >= 245 && localposition.x <= 570 && localposition.y >= 470 && localposition.y <= 553) {
					cout << "500-1000" << endl;
					x = 500;
					y = 1000;
					viewbyprice(x, y);
				}
				else if (localposition.x >= 245 && localposition.x <= 570 && localposition.y >= 593 && localposition.y <= 680) {
					cout << "1000-++" << endl;
					x = 1000;
					y = 100000;
					viewbyprice(x, y);
				}


			}
			window.clear();
			window.draw(photo);
			window.draw(texta);
			window.draw(textb);
			window.draw(textc);
			window.draw(textd);
			window.draw(texte);
			window.draw(choice0);
			window.draw(textz);
			window.draw(choice1);
			window.draw(choice2);
			window.draw(choice3);
			window.draw(choice4);
			window.draw(choice5);
			window.display();
		}
	}

}

int shopperprofile(int x) {

	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textname;
	textname.setPosition(215, 40);
	textname.setFont(fontname);
	textname.setCharacterSize(30);
	textname.setString(Shoppers[x].name);


	sf::Font fontage;
	fontage.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textage;
	textage.setPosition(215, 130);
	textage.setFont(fontage);
	textage.setCharacterSize(30);
	textage.setString(Shoppers[x].name);

	sf::Font fontgender;
	fontgender.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textgender;
	textgender.setPosition(215, 230);
	textgender.setFont(fontgender);
	textgender.setCharacterSize(30);
	textgender.setString(Shoppers[x].gender);

	sf::Font fontcountry;
	fontcountry.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcountry;
	textcountry.setPosition(215, 330);
	textcountry.setFont(fontcountry);
	textcountry.setCharacterSize(30);
	textcountry.setString(Shoppers[x].Add.Country);

	sf::Font fontcity;
	fontcity.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcity;
	textcity.setPosition(215, 430);
	textcity.setFont(fontcity);
	textcity.setCharacterSize(30);
	textcity.setString(Shoppers[x].Add.City);

	sf::Font fontId;
	fontId.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textId;
	textId.setPosition(215, 520);
	textId.setFont(fontId);
	textId.setCharacterSize(30);

	sf::RectangleShape choice40(sf::Vector2f(80.0f, 30.0f));
	choice40.setPosition(sf::Vector2f(812, 748));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::Red);
	choice40.setOutlineThickness(3);

	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" BACK ");
	text10.setCharacterSize(20);
	text10.setFillColor(sf::Color::Red);
	text10.setPosition(820, 750);
	text10.setStyle(sf::Text::Bold);

	sf::Font fonta;
	fonta.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texta;
	texta.setFont(fonta);
	texta.setString("Name             : ");
	texta.setCharacterSize(30);
	texta.setFillColor(sf::Color::White);
	texta.setPosition(10, 40);
	texta.setStyle(sf::Text::Regular);

	sf::Font fontl;
	fontl.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textc;
	textc.setFont(fontl);
	textc.setString("Age                : ");
	textc.setCharacterSize(30);
	textc.setFillColor(sf::Color::White);
	textc.setPosition(10, 130);
	textc.setStyle(sf::Text::Regular);

	sf::Font fontd;
	fontd.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textd;
	textd.setFont(fontd);
	textd.setString("Gender          : ");
	textd.setCharacterSize(30);
	textd.setFillColor(sf::Color::White);
	textd.setPosition(10, 230);
	textd.setStyle(sf::Text::Regular);

	sf::Font fontf;
	fontf.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textf;
	textf.setFont(fontf);
	textf.setString("City                 :");
	textf.setCharacterSize(30);
	textf.setFillColor(sf::Color::White);
	textf.setPosition(10, 420);
	textf.setStyle(sf::Text::Regular);

	sf::Font fontg;
	fontg.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textg;
	textg.setFont(fontg);
	textg.setString("Country          :");
	textg.setCharacterSize(30);
	textg.setFillColor(sf::Color::White);
	textg.setPosition(10, 330);
	textg.setStyle(sf::Text::Regular);

	sf::Font fontid;
	fontid.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textid;
	textid.setFont(fontid);
	textid.setString("   ID                    : ");
	textid.setCharacterSize(25);
	textid.setFillColor(sf::Color::White);
	textid.setPosition(-10, 525);
	textid.setStyle(sf::Text::Bold);
	int active;
	string id, age;

	long long price2 = Shoppers[x].id + 1;
	long long price3 = Shoppers[x].age;

	while (price2 != 0) {
		int remainder = price2 % 10;
		id += remainder + '0';
		price2 /= 10;
	}

	while (price3 != 0) {
		int remainder1 = price3 % 10;
		age += remainder1 + '0';
		price3 /= 10;
	}

	reverse(id.begin(), id.end());
	textId.setString(id);
	reverse(age.begin(), age.end());
	textage.setString(age);


	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 808 && localposition.x <= 893 && localposition.y >= 747 && localposition.y <= 778) {
					return 0;
					cout << "back" << endl;

				}
			}



			window.clear();
			window.draw(photo);
			window.draw(choice40);
			window.draw(texta);
			window.draw(textname);
			window.draw(textcountry);
			window.draw(textcity);
			window.draw(textgender);
			window.draw(textId);
			window.draw(textage);
			window.draw(text10);
			window.draw(textc);
			window.draw(textd);
			window.draw(textf);
			window.draw(textg);
			window.draw(textid);
			window.display();

		}
	}

}

int ownerprofile(int x) {

	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textname;
	textname.setPosition(215, 40);
	textname.setFont(fontname);
	textname.setCharacterSize(30);
	textname.setString(Owners[x].Name);


	sf::Font fontage;
	fontage.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textage;
	textage.setPosition(215, 130);
	textage.setFont(fontage);
	textage.setCharacterSize(30);

	sf::Font fontgender;
	fontgender.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textgender;
	textgender.setPosition(215, 230);
	textgender.setFont(fontgender);
	textgender.setCharacterSize(30);
	textgender.setString(Owners[x].Gender);

	sf::Font fontcountry;
	fontcountry.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcountry;
	textcountry.setPosition(215, 330);
	textcountry.setFont(fontcountry);
	textcountry.setCharacterSize(30);
	textcountry.setString(Owners[x].Add.Country);

	sf::Font fontcity;
	fontcity.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcity;
	textcity.setPosition(215, 430);
	textcity.setFont(fontcity);
	textcity.setCharacterSize(30);
	textcity.setString(Owners[x].Add.City);

	sf::Font fontId;
	fontId.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textId;
	textId.setPosition(215, 520);
	textId.setFont(fontId);
	textId.setCharacterSize(30);

	sf::RectangleShape choice30(sf::Vector2f(80.0f, 30.0f));
	choice30.setPosition(sf::Vector2f(812, 748));
	choice30.setFillColor(sf::Color::Transparent);
	choice30.setOutlineColor(sf::Color::Red);
	choice30.setOutlineThickness(3);

	sf::RectangleShape choice40(sf::Vector2f(110.0f, 30.0f));
	choice40.setPosition(sf::Vector2f(680, 748));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::Red);
	choice40.setOutlineThickness(3);

	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" BACK ");
	text10.setCharacterSize(20);
	text10.setFillColor(sf::Color::Red);
	text10.setPosition(820, 750);
	text10.setStyle(sf::Text::Bold);

	sf::Font font20;
	font20.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text20;
	text20.setFont(font10);
	text20.setString(" SHOP DATA ");
	text20.setCharacterSize(17);
	text20.setFillColor(sf::Color::Red);
	text20.setPosition(680, 753);
	text20.setStyle(sf::Text::Bold);

	sf::Font fonta;
	fonta.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texta;
	texta.setFont(fonta);
	texta.setString("Name             : ");
	texta.setCharacterSize(30);
	texta.setFillColor(sf::Color::White);
	texta.setPosition(10, 40);
	texta.setStyle(sf::Text::Regular);

	sf::Font fontl;
	fontl.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textc;
	textc.setFont(fontl);
	textc.setString("Age                : ");
	textc.setCharacterSize(30);
	textc.setFillColor(sf::Color::White);
	textc.setPosition(10, 130);
	textc.setStyle(sf::Text::Regular);

	sf::Font fontd;
	fontd.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textd;
	textd.setFont(fontd);
	textd.setString("Gender          : ");
	textd.setCharacterSize(30);
	textd.setFillColor(sf::Color::White);
	textd.setPosition(10, 230);
	textd.setStyle(sf::Text::Regular);

	sf::Font fontf;
	fontf.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textf;
	textf.setFont(fontf);
	textf.setString("City                 :");
	textf.setCharacterSize(30);
	textf.setFillColor(sf::Color::White);
	textf.setPosition(10, 420);
	textf.setStyle(sf::Text::Regular);

	sf::Font fontg;
	fontg.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textg;
	textg.setFont(fontg);
	textg.setString("Country          :");
	textg.setCharacterSize(30);
	textg.setFillColor(sf::Color::White);
	textg.setPosition(10, 330);
	textg.setStyle(sf::Text::Regular);

	sf::Font fontid;
	fontid.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textid;
	textid.setFont(fontid);
	textid.setString("   ID                    : ");
	textid.setCharacterSize(25);
	textid.setFillColor(sf::Color::White);
	textid.setPosition(-10, 525);
	textid.setStyle(sf::Text::Bold);

	string id, age;

	long long price2 = Owners[x].ID + 1;
	long long price3 = Owners[x].Age;

	while (price2 != 0) {
		int remainder = price2 % 10;
		id += remainder + '0';
		price2 /= 10;
	}

	while (price3 != 0) {
		int remainder1 = price3 % 10;
		age += remainder1 + '0';
		price3 /= 10;
	}

	reverse(id.begin(), id.end());
	textId.setString(id);
	reverse(age.begin(), age.end());
	textage.setString(age);


	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 808 && localposition.x <= 893 && localposition.y >= 747 && localposition.y <= 778) {
					return 0;
					cout << "back" << endl;

				}
				else if (localposition.x >= 676 && localposition.x <= 791 && localposition.y >= 745 && localposition.y <= 780) {
					shopprofile(LogID);
					cout << "shop data " << endl;

				}
			}



			window.clear();
			window.draw(photo);
			window.draw(choice40);
			window.draw(choice30);
			window.draw(texta);
			window.draw(textname);
			window.draw(textcountry);
			window.draw(textcity);
			window.draw(textgender);
			window.draw(textId);
			window.draw(textage);
			window.draw(text10);
			window.draw(text20);
			window.draw(textc);
			window.draw(textd);
			window.draw(textf);
			window.draw(textg);
			window.draw(textid);
			window.display();

		}
	}

}

int shopprofile(int x) {

	sf::RectangleShape choice40(sf::Vector2f(80.0f, 30.0f));
	choice40.setPosition(sf::Vector2f(812, 748));
	choice40.setFillColor(sf::Color::Transparent);
	choice40.setOutlineColor(sf::Color::Red);
	choice40.setOutlineThickness(3);

	sf::Font fontname;
	fontname.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textname;
	textname.setPosition(215, 50);
	textname.setFont(fontname);
	textname.setCharacterSize(30);
	textname.setString(Owners[x].Shops.ShopName);

	sf::Font fontcountry;
	fontcountry.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcountry;
	textcountry.setPosition(215, 150);
	textcountry.setFont(fontcountry);
	textcountry.setCharacterSize(30);
	textcountry.setString(Owners[x].Shops.Add.Country);

	sf::Font fontcity;
	fontcity.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcity;
	textcity.setPosition(215, 250);
	textcity.setFont(fontcity);
	textcity.setCharacterSize(30);
	textcity.setString(Owners[x].Shops.Add.City);

	sf::Font fontcate;
	fontcate.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textcate;
	textcate.setPosition(215, 350);
	textcate.setFont(fontcate);
	textcate.setCharacterSize(30);
	textcate.setString(Owners[x].Shops.Category);


	sf::Font font10;
	font10.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text text10;
	text10.setFont(font10);
	text10.setString(" BACK ");
	text10.setCharacterSize(20);
	text10.setFillColor(sf::Color::Red);
	text10.setPosition(820, 750);
	text10.setStyle(sf::Text::Bold);

	sf::Font fonta;
	fonta.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text texta;
	texta.setFont(fonta);
	texta.setString("Name             : ");
	texta.setCharacterSize(30);
	texta.setFillColor(sf::Color::White);
	texta.setPosition(10, 50);
	texta.setStyle(sf::Text::Regular);

	sf::Font fontf;
	fontf.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textf;
	textf.setFont(fontf);
	textf.setString("City                 :");
	textf.setCharacterSize(30);
	textf.setFillColor(sf::Color::White);
	textf.setPosition(10, 150);
	textf.setStyle(sf::Text::Regular);

	sf::Font fontg;
	fontg.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textg;
	textg.setFont(fontg);
	textg.setString("Country          :");
	textg.setCharacterSize(30);
	textg.setFillColor(sf::Color::White);
	textg.setPosition(10, 250);
	textg.setStyle(sf::Text::Regular);

	sf::Font fontz;
	fontz.loadFromFile("Roboto-MediumItalic.ttf");
	sf::Text textz;
	textz.setFont(fontz);
	textz.setString("Category         : ");
	textz.setCharacterSize(30);
	textz.setFillColor(sf::Color::White);
	textz.setPosition(10, 350);
	textz.setStyle(sf::Text::Regular);


	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				sf::Vector2i localposition = sf::Mouse::getPosition(window);
				cout << '(' << localposition.x << ',' << localposition.y << ')' << endl;
				if (localposition.x >= 808 && localposition.x <= 893 && localposition.y >= 747 && localposition.y <= 778) {
					return 0;
					cout << "back" << endl;

				}
			}



			window.clear();
			window.draw(photo);
			window.draw(texta);
			window.draw(textname);
			window.draw(textcountry);
			window.draw(textcity);
			window.draw(text10);
			window.draw(textcate);
			window.draw(textf);
			window.draw(textz);
			window.draw(textg);
			window.draw(choice40);
			window.display();

		}
	}

}

int RegOwner(string name, string Password, int passnum, int age, string gender, string country, string city)
{


	int  j;
	for (j = 0; j < maxOwners; j++)
	{
		if (Owners[j].Age == 0)
		{
			Owners[j].Name = name;
			Owners[j].ID = j;
			Owners[j].Password = Password;
			Owners[j].PassNum = passnum;
			Owners[j].Age = age;
			Owners[j].Gender = gender;
			Owners[j].Add.Country = country;
			Owners[j].Add.City = city;
			s.countOwn++;
			break;
		}
	}
	return j;
}

void Lowner(int id, string pass, int j)
{
	int  i;
	bool flag = true;
	string LogPass = { 0 };

	LogID = id - 1;

	LogPass = pass;



	for (i = 0; i < maxOwners; i++)
	{
		flag = true;
		if (j > Owners[i].PassNum || j < Owners[i].PassNum) {
			flag = false;
		}
		else if (j == Owners[i].PassNum) {

			if (LogPass != Owners[i].Password)
			{
				flag = false;
			}
		}
		if (LogID == Owners[i].ID && (flag))
		{
			break;
		}

	}
	LogIndex = i;
	if (flag == false)
	{

		LogIndex = maxOwners;
	}

	if (flag) {
		homepageOwner();
	}
}

void Eowner(int j, bool fname, bool fgender, bool fpass, bool fage, bool fcountry, bool fcity, string name, string newpass, int passnum, string gender, int age, string city, string country) {
	if (fname) {
		Owners[j].Name = name;
	}
	if (fage) {
		Owners[j].Age = age;
	}
	if (fgender) {
		Owners[j].Gender = gender;
	}
	if (fpass) {
		Owners[j].Password = newpass;
		Owners[j].PassNum = passnum;
	}
	if (fcountry) {
		Owners[j].Add.Country = country;
	}
	if (fcity) {
		Owners[j].Add.City = city;
	}
}

void discounts(int j, string name, int discount, int month2, int day2)
{
	for (int i = 0; i < maxProds; i++)
	{
		if (Owners[j].Shops.products[i].productName == name) {
			discount = Owners[j].Shops.products[i].productPrice * discount / 100;
			Owners[j].Shops.products[i].oldPrice = Owners[j].Shops.products[i].productPrice;
			Owners[j].Shops.products[i].productPrice = Owners[j].Shops.products[i].productPrice - discount;
			Owners[j].Shops.products[i].month = month2;
			Owners[j].Shops.products[i].day = day2;
		}
	}
}

void ogRegShop(int i, string categoryChoice, string name, string country, string city)
{
	Owners[i].Shops.ShopName = name;
	Owners[i].Shops.Add.Country = country;
	Owners[i].Shops.Add.City = city;
	Owners[i].Shops.Category = categoryChoice;

}

void editprods(int j, bool flag, bool flag2, bool flag3, string Newname, int price, int quantity, string name) {

	int i;
	bool same = false;
	for (i = 0; i < maxProds; i++)
	{
		if (name == Owners[j].Shops.products[i].productName)
		{
			break;
		}
	}

	if (flag) {
		Owners[j].Shops.products[i].productName = Newname;
	}
	if (flag2) {
		Owners[j].Shops.products[i].productPrice = price;
	}
	if (flag3) {
		Owners[j].Shops.products[i].Quantity = quantity;
	}
}

void del(int j) {

	Shoppers[j].name = { 0 };
	Shoppers[j].id = 0;
	Shoppers[j].pass = { 0 };
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




}

int Regshopper(string name, string Password, int passnum, int age, string gender, string country, string city) {
	int  j;
	for (j = 0; j < maxOwners; j++)
	{
		if (Shoppers[j].age == 0)
		{
			Shoppers[j].name = name;
			Shoppers[j].id = j;
			Shoppers[j].pass = Password;
			Shoppers[j].passnum = passnum;
			Shoppers[j].age = age;
			Shoppers[j].gender = gender;
			Shoppers[j].Add.Country = country;
			Shoppers[j].Add.City = city;
			s.countShopper++;
			break;

		}
	}
	return j;


}

void removeReg(int j)
{
	Owners[j].Name = { 0 };
	Owners[j].ID = 0;
	Owners[j].Password = { 0 };
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

void Lshopper(int id, string pass, int j)
{
	int  i;
	bool flag = true;
	string LogPass = { 0 };

	LogID = id - 1;

	LogPass = pass;



	for (i = 0; i < maxShoppers; i++)
	{
		flag = true;
		if (j > Shoppers[i].passnum || j < Shoppers[i].passnum) {
			flag = false;
		}
		else if (j == Shoppers[i].passnum) {

			if (LogPass != Shoppers[i].pass)
			{
				flag = false;
			}
		}
		if (LogID == Shoppers[i].id && (flag))
		{
			break;
		}

	}
	LogIndex = i;
	if (flag == false)
	{

		LogIndex = maxShoppers;
	}

	if (flag) {
		scchoice();
	}
}

void addProds(int j, string name, int price, int quantity, string type, string size, string color)
{
	for (int i = 0; i <= maxProds; i++)
	{

		if (Owners[j].Shops.products[i].productPrice == 0)
		{
			Owners[j].Shops.products[i].productName = name;
			Owners[j].Shops.products[i].productPrice = price;

			if (Owners[j].Shops.Category == "Clothing") {
				Owners[j].Shops.products[i].Clothes.Type = type;
				Owners[j].Shops.products[i].Clothes.Color = color;
				Owners[j].Shops.products[i].Clothes.Size = size;
				Owners[j].Shops.products[i].Category = Owners[j].Shops.Category;
			}
			else {
				Owners[j].Shops.products[i].Category = Owners[j].Shops.Category;
			}

			Owners[j].Shops.products[i].Quantity = quantity;
			Owners[j].Shops.countProd++;
			break;
		}
	}
}

int removeProds(int j, string name)
{
	int i;
	bool same = false;
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
		Owners[j].Shops.products[i].sum = 0;
		Owners[j].Shops.products[i].oldPrice = 0;
		Owners[j].Shops.products[i].month = 0;
		Owners[j].Shops.products[i].day = 0;
		Owners[j].Shops.products[i].counter = 0;
		Owners[j].Shops.products[i].avgRating = 0;
		Owners[j].Shops.countProd--;
		if (Owners[j].Shops.products[i].Category == "Clothing") {
			Owners[j].Shops.products[i].Clothes.Type = { 0 };
			Owners[j].Shops.products[i].Clothes.Color = { 0 };
			Owners[j].Shops.products[i].Clothes.Size = { 0 };
			Owners[j].Shops.products[i].Category = "";
		}
		else {
			Owners[j].Shops.products[i].Category = "";
		}
		return 1;
	}
	return 0;
}

void ogRating(int ratenum, int rating)

{
	Owners[kk.sav[ratenum - 1].x].Shops.products[kk.sav[ratenum - 1].y].counter++;
	Owners[kk.sav[ratenum - 1].x].Shops.products[kk.sav[ratenum - 1].y].sum += rating;
	Owners[kk.sav[ratenum - 1].x].Shops.products[kk.sav[ratenum - 1].y].avgRating = Owners[kk.sav[ratenum - 1].x].Shops.products[kk.sav[ratenum - 1].y].sum / Owners[kk.sav[ratenum - 1].x].Shops.products[kk.sav[ratenum - 1].y].counter;
}

void seearch(string name)
{

	bool flag = false;
	int x = 1, l = 0;
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
				m.a[l] = i;
				m.b[l] = j;
				l++;
			}

		}

	}

	if (flag == false) {
		cout << "                                     Out Of Stock. \n\n\n ";
		m.a[0] = -1;
	}
}

void editShopdata(int j, bool fname, bool fcountry, bool fcity, bool fcategory, string name, string country, string city, string category)
{
	if (fname) {
		Owners[j].Shops.ShopName = name;
	}
	if (fcountry) {
		Owners[j].Shops.Add.Country = country;
	}
	if (fcity) {
		Owners[j].Shops.Add.City = city;
	}
	if (fcategory) {
		Owners[j].Shops.Category = category;
	}
}

void Eshopper(int j, bool fname, bool fgender, bool fpass, bool fage, bool fcountry, bool fcity, string name, string newpass, int passnum, string gender, int age, string city, string country) {
	if (fname) {
		Shoppers[j].name = name;
	}
	if (fpass) {
		Shoppers[j].pass = newpass;
		Shoppers[j].passnum = passnum;
	}
	if (fage) {
		Shoppers[j].age = age;
	}
	if (fgender) {
		Shoppers[j].gender = gender;
	}
	if (fcountry) {
		Shoppers[j].Add.Country = country;
	}
	if (fcity) {
		Shoppers[j].Add.City = city;
	}
}

void deletee(int deletenum) {

	Owners[kk.sav[deletenum - 1].x].Shops.products[kk.sav[deletenum - 1].y].Quantity += kk.amount[deletenum - 1];
	kk.amount[deletenum - 1] = 0;
	for (int i = 0; i < cv.nump; i++) {
		if (i > deletenum - 1) {
			kk.sav[i - 1].x = kk.sav[i].x;
			kk.sav[i - 1].y = kk.sav[i].y;
			kk.amount[i - 1] = kk.amount[i];
			kk.sub[i - 1] = kk.sub[i];
		}
	}
	cv.nump--;
	cv.index--;

}

