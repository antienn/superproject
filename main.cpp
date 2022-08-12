#include<iostream>
#include<iomanip>
#include<fstream>
#include <string>
#include"mylib.h"
#include<Windows.h>
#include<conio.h>

using namespace std;

//oject

struct date {
	int day;
	int month;
	int year;
};

struct user {
	int id;
	string fullname;
	string pass;
	date birthday;
};
struct usernode {
	user info;
	usernode* next;
};

struct book {
	int masach;
	string tensach;
	string tacgia;
	string nxb;
	int namxb;
};

struct Booknode {

	book info;
	Booknode* next;
};


// function

void print_list_book(Booknode* filebook)
{
	Booknode* tmp = filebook;
	while (tmp != NULL) {
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "   book id: " << tmp->info.masach << endl;
		cout << "   name book: " << tmp->info.tensach << endl;
		cout << "   author: " << tmp->info.tacgia << endl;
		cout << "   publisher: " << tmp->info.nxb << endl;
		cout << "   date publish: " << tmp->info.namxb << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		tmp = tmp->next;
	}

}
void print_author(Booknode* filebook, string key)
{
	Booknode* tmp = filebook;
	while (tmp != NULL)
	{
		/*cout << tmp->info.tacgia << key << "iiiiii" << endl;*/
		if (tmp->info.tacgia == key)
		{
			cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "   book id: " << tmp->info.masach << endl;
			cout << "   name book: " << tmp->info.tensach << endl;
			cout << "   author: " << tmp->info.tacgia << endl;
			cout << "   publisher: " << tmp->info.nxb << endl;
			cout << "   date publish: " << tmp->info.namxb << endl;
		}
		tmp = tmp->next;
	}
}
void print_publisher(Booknode* filebook, string key){
	Booknode* tmp = filebook;
	while (tmp != NULL)
	{
		// neu gia tri key = vs ma sach vs ten sach 
		if (tmp->info.nxb == key)
		{
			cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "   book id: " << tmp->info.masach << endl;
			cout << "   name book: " << tmp->info.tensach << endl;
			cout << "   author: " << tmp->info.tacgia << endl;
			cout << "   publisher: " << tmp->info.nxb << endl;
			cout << "   date publish: " << tmp->info.namxb << endl;
		}
		tmp = tmp->next;
	}
}
void find_book_by_id(Booknode* filebook, int key)
{
	Booknode* tmp = filebook;
	while (tmp != NULL)
	{
		// neu gia tri key = vs ma sach vs ten sach 
		if (tmp->info.masach == key)
		{
			cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "   book id: " << tmp->info.masach << endl;
			cout << "   name book: " << tmp->info.tensach << endl;
			cout << "   author: " << tmp->info.tacgia << endl;
			cout << "   publisher: " << tmp->info.nxb<< endl;
			cout << "   date publish: " << tmp->info.namxb << endl;
			cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			return;
		}
		tmp = tmp->next;
	}
	cout << "can't find the book what you want to find!" << endl;
}

void find_book_by_name(Booknode* filebook, string key)
{
	Booknode* tmp = filebook;
	while (tmp != NULL)
	{
		// neu gia tri key = vs ma sach vs ten sach 
		if (tmp->info.tensach == key)
		{
			cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "   book id: " << tmp->info.masach << endl;
			cout << "   name book: " << tmp->info.tensach << endl;
			cout << "   author: " << tmp->info.tacgia << endl;
			cout << "   publisher: " << tmp->info.nxb << endl;
			cout << "   date publish: " << tmp->info.namxb << endl;
			cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			return;
		}
		tmp = tmp->next;
	}
	cout << "can't find the book what you want to find!" << endl;
}

book checkid(book curbook, Booknode* filebook) {
	Booknode* listbook = filebook;
	while (listbook != NULL) {
		if (listbook->info.masach == curbook.masach) {
			gotoXY(0, 19);
			cout << "This id have had in our library please change your id book !";
			gotoXY(30, 3);
			cout << "                            " << endl;
			gotoXY(30, 3);
			cin >> curbook.masach;
			return checkid(curbook, filebook);
		}
		listbook = listbook->next;
	}
	return curbook;
}

book creatBook(Booknode* filebook) {
	char p;
	int tmp;
	system("cls");
	book curBook;
	SetColor(9);
	int posX = 30;
	int posY = 3;
	cout << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
	cout << " ++                        BOOK IN LIBRARY                         ++ " << endl;
	cout << " ++                                                                ++ " << endl;
	cout << " ++      1/ID:                                                     ++ " << endl;
	cout << " ++                                                                ++ " << endl;
	cout << " ++      2/Name:                                                   ++ " << endl;
	cout << " ++                                                                ++ " << endl;
	cout << " ++      3/Author:                                                 ++ " << endl;
	cout << " ++                                                                ++ " << endl;
	cout << " ++      4/Publisher:                                              ++ " << endl;
	cout << " ++                                                                ++ " << endl;
	cout << " ++      5/Date publish:                                           ++ " << endl;
	cout << " ++                                                                ++ " << endl;
	cout << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
	SetColor(6);
	while (posY <= 11) {
		gotoXY(posX, posY);
		if (posY == 3) {
			cin >> curBook.masach;
		}
		if (posY == 5) {
			cin.ignore();
			getline(cin,curBook.tensach);
		}
		if (posY == 7) {
			cin.ignore();
			getline(cin,curBook.tacgia);
		}
		if (posY == 9) {
			cin.ignore();
			getline(cin, curBook.nxb);
		}
		if (posY == 11) {
			cin >> curBook.namxb;
		}
		posY += 2;
	}
	//edit
	while (true) {
		gotoXY(0, 16);
		cout << " " << endl;
		cout << "                                                      " << endl;
		cout << " ";
		gotoXY(0, 15);
		cout << "Do you want to change your info's book press Y/N" << endl;
		cin >> p;
		if (p == 'y') {
			cout << "Give us your number what you want to change" << endl;
			cin >> tmp;
			switch (tmp) {
				case 1: {
					gotoXY(30, 3);
					cout << "                            " << endl;
					gotoXY(30, 3);
					cin >> curBook.masach;
					break;
				}
				case 2: {
					gotoXY(30, 5);
					cout << "                            " << endl;
					gotoXY(30, 5);
					cin.ignore();
					getline(cin, curBook.tensach);
					break;
				}
				case 3: {
					gotoXY(30, 7);
					cout << "                            " << endl;
					gotoXY(30, 7);
					cin.ignore();
					getline(cin, curBook.tacgia);
					break;
				}
				case 4: {
					gotoXY(30, 9);
					cout << "                            " << endl;
					gotoXY(30, 9);
					cin.ignore();
					getline(cin, curBook.nxb);
					break;
				}
				case 5: {
					gotoXY(30, 11);
					cout << "                            " << endl;
					gotoXY(30, 11);
					cin >> curBook.namxb;
					break;
				}

			}
		}
		else {
			curBook = checkid(curBook, filebook);
			system("cls");
			break;
		}

	}
	return curBook;
}
void sort(Booknode* first)
{
	Booknode* p = first;
	Booknode* q = NULL;
	int tmp;
	if (first == NULL)
		return;
	while (p != NULL)
	{
		q = p->next;
		while (q != NULL)
		{
			if (p->info.namxb < q->info.namxb)
			{
				tmp = p->info.namxb;
				p->info.namxb = q->info.namxb;
				q->info.namxb = tmp;
			}
			q = q->next;
		}
		p = p->next;
	}
}


Booknode* CreateNodeBook(book mybook)
{
	Booknode* tmpNode = new Booknode;
	tmpNode->info.masach = mybook.masach;
	tmpNode->info.namxb = mybook.namxb;
	tmpNode->info.nxb = mybook.nxb;
	tmpNode->info.tacgia = mybook.tacgia;
	tmpNode->info.tensach = mybook.tensach;
	tmpNode->next = NULL;
	return tmpNode;
}
usernode* CreateNodeUser(user curuser)
{
	usernode* tmpNode = new usernode;
	tmpNode->info.id = curuser.id;
	tmpNode->info.fullname = curuser.fullname;
	tmpNode->info.pass = curuser.pass;
	tmpNode->info.birthday.day = curuser.birthday.day;
	tmpNode->info.birthday.month = curuser.birthday.month;
	tmpNode->info.birthday.year = curuser.birthday.year;
	tmpNode->next = NULL;
	return tmpNode;
}

Booknode* insert_last(book mybook, Booknode* first)
{
	Booknode* tmp = first;
	if (tmp == NULL) {
		return CreateNodeBook(mybook);
	}
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = CreateNodeBook(mybook);

	return first;
}
usernode* insert_last_user(user curuser, usernode* first)
{
	usernode* tmp = first;
	if (tmp == NULL) {
		return CreateNodeUser(curuser);
	}
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = CreateNodeUser(curuser);

	return first;
}

bool remove_bookid(Booknode*& first, int key)
{
	Booknode* p = first;
	Booknode* q = NULL;
	if (p->info.masach == key) {
		first = p->next;
		delete p;
		return true;
	}
	while (p != NULL && p->info.masach != key)
	{
		q = p;
		p = p->next;
	}
	if (p == NULL) {
		return false;
	}
	q->next = p->next;
	delete p;
	return true;
}
bool remove_bookauthor(Booknode*& first, string key)
{
	Booknode* p = first;
	Booknode* q = NULL;
	if (p->info.tacgia == key) {
		first = p->next;
		delete p;
		return true;
	}
	while (p != NULL && p->info.tacgia != key)
	{
		q = p;
		p = p->next;
	}
	if (p == NULL) {
		return false;
	}
	q->next = p->next;
	delete p;
	return true;
}
void remove_bookauthorall(Booknode*& first, string key)
{
	bool clear = false;
	while (true){
		if (clear) {
			return;
		}
		clear = !remove_bookauthor(first, key);
	}
}


void initdata(Booknode*& filebook, usernode*& listuser) {
	ifstream f;
	f.open("libraryy.txt", ios::in);
	while (!f.eof()) {
		book mybook;
		f >> mybook.masach;
		f.ignore();
		getline(f, mybook.tensach, ',');
		getline(f, mybook.tacgia, ',');
		getline(f, mybook.nxb, ',');
		f >> mybook.namxb;
		f.ignore();
		filebook = insert_last(mybook, filebook);
	}
	f.close();
	f.open("userr.txt", ios::in);
	while (!f.eof()) {
		user curuser;
		f >> curuser.id;
		f.ignore();
		getline(f, curuser.fullname, ',');
		f >> curuser.birthday.day;
		f.ignore();
		f >> curuser.birthday.month;
		f.ignore();
		f >> curuser.birthday.year;
		f.ignore();
		getline(f, curuser.pass);
		listuser = insert_last_user(curuser, listuser);
	}
	f.close();
}
usernode* form(usernode* listuser) {
	int curID;
	string curPass = "                                                  ";
	int length = 0;
	int posXinputpass = 30;
	SetColor(9);
	cout << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
	cout << " ++                        LOG IN TO LIBRARY                       ++ " << endl;
	cout << " ++                                                                ++ " << endl;
	cout << " ++                                                                ++ " << endl;
	cout << " ++      YOUR ID:                                                  ++ " << endl;
	cout << " ++                                                                ++ " << endl;
	cout << " ++                                                                ++ " << endl;
	cout << " ++      YOUR PASSWORD:                                            ++ " << endl;
	cout << " ++                                                                ++ " << endl;
	cout << " ++                                                                ++ " << endl;
	cout << " ++                                                                ++ " << endl;
	cout << " ++                                                                ++ " << endl;
	cout << " ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << endl;
	SetColor(6);
	while (true) {
		gotoXY(20, 4);
		cin >> curID;
		if (curID>=10000 && curID<=99999){
			gotoXY(25, 10);
			cout << "                            ";
			break;
		}
		else {
			gotoXY(25, 10);
			cout << "your id must have 5 numbers";
			gotoXY(20, 4);
			cout << "          ";
		}
	}
	while (true) {
		gotoXY(posXinputpass + length, 7);

		char p = 0;
		p = _getch();
		if (p == 13) {
			if (length < 1) {
				gotoXY(25, 11);
				cout << "please input your pass";
				continue;
			}
			else {
				gotoXY(25, 11);
				cout << "please wait for a moment...";
				Sleep(1000);
				break;
			}
		}
		if (p == 8) {
			gotoXY(posXinputpass + length-1, 7);
			cout << " ";
			if (length <= 0) {
				length = 1;
			}
			curPass[--length] = ' ';
		}
		else {
			gotoXY(posXinputpass + length, 7);
			cout << "*";
			curPass[length++] = p;
		}
	}
	for (int i = 0; i < curPass.length(); i++) {
		if (curPass[i] == ' ') {
			curPass = curPass.substr(0, i);
		}
	}
	usernode* ptmp = listuser;
	while (ptmp != NULL) {
		if (ptmp->info.id == curID && ptmp->info.pass == curPass) {
			
			return ptmp;
		}
		ptmp = ptmp->next;
	}
	system("cls");
	gotoXY(10, 0);
	cout << "Your pass or id is wrong,please input again..." << endl;
	Sleep(5000);
	system("cls");
	return form(listuser);
}
void menu() {
	cout << "1/find a book by name" << endl;
	cout << "2/find a book by id" << endl;
	cout << "3/print list book by author" << endl;
	cout << "4/print list book by publishing company" << endl;
	cout << "5/return the book to the library" << endl;
	cout << "6/borrow books to students" << endl;
	cout << "7/remove all author's book" << endl;
	cout << "8/sort ascending by name book" << endl;
	cout << "9/sort descending by date publish" << endl;
	cout << "10/" << endl;
	cout << "11/ log out" << endl;

}
int main() {
	bool ignore = false;
	usernode* curUser;
	Booknode* filebook = NULL;
	usernode* listuser = NULL;
	initdata(filebook, listuser);
	/*print_list_book(filebook);
	system("pause");*/
	curUser = form(listuser);
	do {
		system("cls");
		int tmp;
		string temp;
		int posX = 60;
		int posY = 1;
		char p = 0;
		cout << "hello " << curUser->info.fullname << endl;
		menu();
		while (p != 13) {
			gotoXY(posX, posY);
			cout << "-+-";
			p = _getch();
			if ((int)p == 80 && whereY() != 11) {
				gotoXY(posX, posY);
				cout << "   ";
				posY++;
			}if ((int)p == 72 && whereY() != 1) {
				gotoXY(posX, posY);
				cout << "   ";
				posY--;
			}
		}
		int pick = whereY();
		system("cls");
		switch (pick) {
			case 1: {
				cout << "please input the name what you want to find" << endl;
				if (!ignore) {
					ignore = true;
					cin.ignore();
				}
				getline(cin, temp);
				find_book_by_name(filebook, temp);
				system("pause");
				break;
			}
			case 2: {
				cout << "please input id what you want to find" << endl;
				cin >> tmp;
				find_book_by_id(filebook, tmp);
				system("pause");
				break;
			}
			case 3: {
				cout << "please input the author for us to print" << endl;
				if (!ignore) {
					ignore = true;
					cin.ignore();
				}
				getline(cin, temp);
				print_author(filebook, temp);
				system("pause");
				break;
			}
			case 4: {
				cout << "please input the publishing company for us to print" << endl;
				if (!ignore) {
					ignore = true;
					cin.ignore();
				}
				getline(cin, temp);
				print_publisher(filebook, temp);
				system("pause");
				break;
			}
			case 5: {
				filebook = insert_last(creatBook(filebook), filebook);
				system("pause");
				break;
			}
			case 6: {
				cout << "please input id which book you want to borrow" << endl;
				cin >> tmp;
				if (remove_bookid(filebook, tmp)) {
					cout << "delete successfull!" << endl;
					print_list_book(filebook);
					system("pause");
				}
				else {
					cout << "can't find the book id which you want to borrow" << endl;
					system("pause");
				}
				break;
			}
			case 7: {
				cout << "please input the author for us to delete" << endl;
				if (!ignore) {
					ignore = true;
					cin.ignore();
				}
				getline(cin, temp);
				remove_bookauthorall(filebook, temp);
				print_list_book(filebook);
				system("pause");
				break;
			}
			case 8: {
				sort(filebook);
				print_list_book(filebook);
				system("pause");
				break;
			}
		}
	} while (true);


	gotoXY(10, 99);
	cout << "thanks for using" << endl;
	return 0;
}