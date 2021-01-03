#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
//node structure that can store string
struct node {
	char data; //store the char
	node *next;
	node() {
		data = '0';
		next = NULL;
	}
};

//list class, declare data members as discussed and write constructor
class list {

private:
	int len;//len use for lenght
	node *head;
public:
	list() {
		len = 0;
		head = NULL;
	}
	void display();
	int lenght();
	int search(char, int = 0);
	int count(char);
	bool replace(char, int);
	bool remove(char);
	int replace(char, char);
	int removeall(char, int = 0);
	bool insert(char, int = 0);
	bool shuffle(int, int);
};
//this function use to display the list
void list::display() {
	node *t = head;
	while (t != NULL) {

		cout << t->data << endl;;
		t = t->next;
	}

}

// function use to input tha list is add return true otherwise else
bool list::insert(char ch, int pos) {
	node *t = new node();
	if (pos > 0) {
		if (len > 0 && pos <= len) {
			t = head;
			for (int i = 0; i < pos; i++) {
				t = t->next;

			}
			t->data = ch;
			len++;
		}
	}
	else	if (pos == 0) {
	t->data = ch;
	t->next = head;
	head = t;
	len++;
}
	

	return true;


}
//function use to remove char.. if matched
bool list::remove(char ch) {
	node *t;
	t = head;
	while (t != NULL)
	{
		
		if (t->data == ch) {

			t->next = t->next->next;
			//delete t;
			len--;
		}
		t = t->next;
	}
	return true;

}
//this function use to search a char. and return the position if matched
int list::search(char ch, int s) {
	node *t = head;
	int pos = 0;// use to check the position of char
	while (t != NULL) {
		t = t->next;
		pos++;
		if (t->data == ch) {
			return pos;
		}
	}
	return -1;

} //function use to replace char -- in list  and return index
int list::replace(char ch, char b) {
	node *t = head;
	int c = 0;//c use to count number of char are replace
	while (t != NULL) {
		if (t->data == ch) {

			t->data = b;
			t = t->next;
			c++;
		}


	}
	return c;

}//function use to count (rapetation) the one char in list
int list::count(char ch) {
	node *t;
	t = head;
	int n = 0;// n use to check the position of char
	while (t->data = NULL) {


		t = t->next;
		n++;
	}
	return n;

}
//funtion use to replace the char on the spacific  index
bool list::replace(char ch, int b) {
	node *t = head;

	for (int i = 0; i<b; i++) {
		t = t->next;

	}
	t->data = ch;
	return true;

}
// function use to remove the list from the matched char and return the index
int list::removeall(char ch, int x) {
	node *t;
	t = head;
	int z = 0; //z show the positoin of  char
	while (t->data != ch) {
		t = t->next;
		z++;
	}
	t->next = t;
	return z;
}

// function use to return the lenght of list
int list::lenght() {
	return len;
}
//function use to swap the char on indexs
bool list::shuffle(int x, int y) {
	node *t, *r;
	t = head;//this point for first index
	r = head;//this point for secound index
	for (int i = 0; i < x; i++) {
		t = t->next;
	}
	for (int i = 0; i < y; i++) {
		r = r->next;
	}
	char temp;
	temp = t->data;
	t->data = r->data;
	r->data = temp;
	return true;
}

//main function
void main() {
	list l;
	l.insert('u');
	l.insert('s');
	l.insert('m');
	l.insert('q');
	l.insert('w', 2);
	l.remove('u');
	l.display();



	_getch();
}
