#include <iostream>
#include <fstream>
#include <iomanip> 
#include <sstream>
#include <string>
#include <ctime>

using namespace std;


//Parent Class
class Person {
protected:
	string ID;
	string FirstName;
	string LastName;
	string username;
	string password;


public:
	/*
	Person() {
		ID = "0";
		FirstName = "Alan";
		LastName = "Turing";
		username = "test";
		password = "123";
	}
	*/

	Person(string ID, string First, string Last, string username, string password) : ID(ID), FirstName(First), LastName(Last),
		username(username), password(password) {}

	//Getter-functions
	string getID() {
		return ID;
	}
	string getFirstName() {
		return FirstName;
	}
	string getLastName() {
		return LastName;
	}
	string getUsername() {
		return username;
	}
	string getPassword() {
		return password;
	}

	//Setter-functions
	void setID(int x) {
		ID = x;
	}
	void setFirstName(string a) {
		FirstName = a;
	}
	void setLastName(string a) {
		LastName = a;
	}
	void setUserName(string a) {
		username = a;
	}
	void setPassword(string a) {
		password = a;
	}

	//friend class Admin;

};

//Linked List Class
class Node
{
private:
	string elem; //data element (type string in this case)
	Node* next; //Link (pointer) to the next Node
	Node* prev; //Link (pointer) to the previous Node
	friend class DoublyLinkedList;

public:
	Node() : next(NULL), prev(NULL)
	{}
	Node(string elem) : elem(elem), next(NULL), prev(NULL)
	{}
};

class DoublyLinkedList
{
private:
	Node* head;
	Node* tail;
public:
	DoublyLinkedList() //constructor
	{
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}

	~DoublyLinkedList() // destructor to clear memory
	{
		while (!empty()) {
			removeFront();
		}
		delete head;
		delete tail;
	}

	bool empty() const // is list empty?
	{
		if (head->next == tail)
			return true;
		else
			return false;
	}

	void addFront(const string& elem) // add to front of list
	{
		Node* v = new Node(elem);
		v->next = head->next;
		v->prev = head;
		head->next->prev = v;
		head->next = v;
	}

	void removeFront() // remove from front of list
	{
		if (!empty()) {
			Node* old = head->next;
			head->next = old->next;
			old->next->prev = head;
			delete old;
		}
		else
			cout << "List is empty!\n";
	}
	//ERROR HERE TOO

	void display() const
	{
		Node* curr = head;
		while (curr != NULL)
		{
			cout << "+------";
			curr = curr->next;
		}
		cout << "+" << endl << "|";
		curr = head;
		while (curr != NULL)
		{
			if (curr == head)		cout << " Head |";
			else if (curr == tail)	cout << " Tail |";
			else 					cout << setw(5) << curr->elem << " |";

			curr = curr->next;
		}
		curr = head;
		cout << endl;
		while (curr != NULL)
		{
			cout << "+------";
			curr = curr->next;
		}
		cout << "+" << endl;
	}
};

//Admin Class (Double Linked List)
class NodeAdmin
{
private:
	string ID;
	string FirstName;
	string LastName;
	string username;
	string password;
	NodeAdmin* next;
	NodeAdmin* prev;
	friend class DListforAdmin;

public:
	NodeAdmin() : next(NULL), prev(NULL)
	{}
	NodeAdmin(string ID, string First, string Last, string username, string password) : next(NULL), prev(NULL), ID(ID), FirstName(First), LastName(Last),
		username(username), password(password) {}
};

class DListforAdmin {
private:
	NodeAdmin* head;
	NodeAdmin* tail;

public:
	DListforAdmin() {
		head = new NodeAdmin();
		tail = new NodeAdmin();
		head->next = tail;
		tail->prev = head;
	}

	~DListforAdmin() {
		while (!empty()) {
			removeFront();
		}
		delete head;
		delete tail;
	}

	bool empty() const {
		if (head->next == tail)
			return true;
		else
			return false;
	}

	void addFront(string ID, string First, string Last, string username, string password)
	{
		NodeAdmin* v = new NodeAdmin(ID, First, Last, username, password);
		v->next = head->next;
		v->prev = head;
		head->next->prev = v;
		head->next = v;
	}

	void loadData() {

		ifstream in;
		in.open("Admins.txt");

		if (!in.is_open()) {
			perror("File could not be opened");
		}

		//variables to read from file
		string ID;
		string FirstName;
		string LastName;
		string username;
		string password;
		string discard;

		getline(in, discard);
		while (in.peek() != EOF) {
			getline(in, ID, ',');
			getline(in, FirstName, ',');
			getline(in, LastName, ',');
			getline(in, username, ',');
			getline(in, password, '\n');
			addFront(ID, FirstName, LastName, username, password);
		}

		in.close();
	}

	void removeFront() // remove front node of list
	{
		if (!empty()) {
			NodeAdmin* old = head->next;
			head->next = old->next;
			old->next->prev = head;
			delete old;
		}
		else
			cout << "List is empty!\n";
	}

	void testDisplay() {
		NodeAdmin* curr = head;
		while (curr != NULL)
		{
			cout << "+------";
			curr = curr->next;
		}
		cout << "+" << endl << "|";
		curr = head;
		while (curr != NULL)
		{
			if (curr == head)		cout << " Head |";
			else if (curr == tail)	cout << " Tail |";
			else 					cout << setw(5) << curr->ID << " |";

			curr = curr->next;
		}
		curr = head;
		cout << endl;
		while (curr != NULL)
		{
			cout << "+------";
			curr = curr->next;
		}
		cout << "+" << endl;
	}

	bool verifyLogin(string userN, string pass) {
		NodeAdmin* current = head->next;
		while (current != tail) {
			if ((current->username == userN) && (current->password == pass)) {
				return true;
			}
			current = current->next;
		}
		return false;
	}

};


//Member Class (Double Linked List)
class NodeMember
{
private:
	string ID;
	string FirstName;
	string LastName;
	string username;
	string password;
	DoublyLinkedList listBookings; //LIST OF REGISTRATIONS
	//ADD DLISTOFREGISTRATIONS HERE
	NodeMember* next;
	NodeMember* prev;
	friend class DListforMember;

public:
	NodeMember() : next(NULL), prev(NULL)
	{}
	NodeMember(string ID, string First, string Last, string username, string password) : next(NULL),
		prev(NULL), ID(ID), FirstName(First), LastName(Last), username(username), password(password) {}
};

class DListforMember {
private:
	NodeMember* head;
	NodeMember* tail;

public:
	DListforMember() {
		head = new NodeMember();
		tail = new NodeMember();
		head->next = tail;
		tail->prev = head;
	}

	~DListforMember() {
		while (!empty()) {
			removeFront();
		}
		delete head;
		delete tail;
	}

	bool empty() const {
		if (head->next == tail)
			return true;
		else
			return false;
	}

	void addFront(string ID, string First, string Last, string username, string password, string list)
	{
		NodeMember* v = new NodeMember(ID, First, Last, username, password);
		v->next = head->next;
		v->prev = head;
		head->next->prev = v;
		head->next = v;

		string c;
		if (list != "") { //if list is not empty in file
			stringstream a(list);
			while (a.good()) {
				getline(a, c, ',');
				v->listBookings.addFront(c);
			}
		}
	}

	void loadData() {

		ifstream in;
		in.open("Members.txt");

		if (!in.is_open()) {
			perror("File could not be opened");
		}

		//variables to read from file
		string ID;
		string FirstName;
		string LastName;
		string username;
		string password;
		string discard;
		string s;

		getline(in, discard);
		while (in.peek() != EOF) {

			getline(in, ID, ',');
			getline(in, FirstName, ',');
			getline(in, LastName, ',');
			getline(in, username, ',');
			getline(in, password, ',');
			//populating list of bookings
			getline(in, s, ']');
			s = s.substr(1, s.size() - 1); //removes '[]'

			getline(in, discard, '\n');
			addFront(ID, FirstName, LastName, username, password, s);
		}
		in.close();
	}

	void removeFront() // remove front item from list
	{
		if (!empty()) {
			NodeMember* old = head->next;
			head->next = old->next;
			old->next->prev = head;
			delete old;
		}
		else
			cout << "List is empty!\n";
	}

	void testDisplay() {
		NodeMember* curr = head;
		while (curr != NULL)
		{
			cout << "+------";
			curr = curr->next;
		}
		cout << "+" << endl << "|";
		curr = head;
		while (curr != NULL)
		{
			if (curr == head)		cout << " Head |";
			else if (curr == tail)	cout << " Tail |";
			else 					cout << setw(5) << curr->ID << " |";

			curr = curr->next;
		}
		curr = head;
		cout << endl;
		while (curr != NULL)
		{
			cout << "+------";
			curr = curr->next;
		}
		cout << "+" << endl;
	}

	bool verifyLogin(string userN, string pass) {
		NodeMember* current = head->next;
		while (current != tail) {
			if ((current->username == userN) && (current->password == pass)) {
				return true;
			}
			current = current->next;
		}
		return false;
	}

	void registerMember() { //change function name
		string firstName;
		string lastName;
		string ID;
		string username;
		string pass;
		string list = "";

		cout << "Please enter your first name:\n";
		cin >> firstName;
		cout << "Now enter your last name:\n";
		cin >> lastName;
		//REMEMBER TO LOWERCASE
		username = firstName;
		pass = lastName;

		//changing username and pass to lower-case char
		for (int i = 0; i < username.length(); i++) {
			username[i] = tolower(username[i]);
		}
		for (int i = 0; i < pass.length(); i++) {
			pass[i] = tolower(pass[i]);
		}

		//setting seed to yield random values every time the program is run
		srand(time(NULL));
		for (int i = 0; i <= 3;i++) {
			ID += to_string((rand() % 10));
			pass += to_string((rand() % 10));
		}
		username += ID;
		addFront(ID, firstName, lastName, username, pass, list);
		cout << "Registration successful!\nThe New Member's ID is " << ID << endl;
	}

};



//FitnessClass Class
class FitnessClass
{
private:
	string ClassID;
	string ClassName;
	DoublyLinkedList listSessions; //LIST OF SESSIONS
	FitnessClass* next;
	FitnessClass* prev;
	friend class DListforFitnessClasses;

public:
	FitnessClass() : next(NULL), prev(NULL)
	{}
	FitnessClass(string ID, string name) : next(NULL),
		prev(NULL), ClassID(ID), ClassName(name) {}
};

class DListforFitnessClasses {
private:
	FitnessClass* head;
	FitnessClass* tail;

public:
	DListforFitnessClasses() {
		head = new FitnessClass();
		tail = new FitnessClass();
		head->next = tail;
		tail->prev = head;
	}

	~DListforFitnessClasses() {
		while (!empty()) {
			removeFront();
		}
		delete head;
		delete tail;
	}

	bool empty() const {
		if (head->next == tail)
			return true;
		else
			return false;
	}

	void removeFront() // remove front item from list
	{
		if (!empty()) {
			FitnessClass* old = head->next;
			head->next = old->next;
			old->next->prev = head;
			delete old;
		}
		else
			cout << "List is empty!\n";
	}

	void addFront(string ID, string name, string list)
	{
		FitnessClass* v = new FitnessClass(ID, name);

		v->next = head->next;
		v->prev = head;
		head->next->prev = v;
		head->next = v;

		string c;
		if (list != "") { //if list is not empty in file
			stringstream a(list);
			while (a.good()) {
				getline(a, c, ',');
				v->listSessions.addFront(c);
			}
		}
	}

	void loadData() {

		ifstream in;
		in.open("FitnessClasses.txt");

		if (!in.is_open()) {
			perror("File could not be opened");
		}

		//variables to read from file
		string ID;
		string ClassName;
		string discard;
		string s;
		string c;

		getline(in, discard);
		while (in.peek() != EOF) {
			getline(in, ID, ',');
			getline(in, ClassName, ',');

			//populating list of sessions
			getline(in, s, ']');
			s = s.substr(1, s.size() - 1); //removes '[]'

			getline(in, discard, '\n');
			addFront(ID, ClassName, s);
		}
		in.close();
	}

	void addFitnessClass() {
		string classID;
		string className;
		string list = "";

		cout << "Enter Class ID:\n";
		cin >> classID;
		cout << "Enter Class Name:\n";
		cin >> className;

		addFront(classID, className, list);
		display();
		cout << "Fitness Class Created Successfully!\n";
	}

	void deleteFitnessClass() {
		string ID;
		cout << "Enter the ID of the Fitness Class you want to delete:\n";
		cin >> ID;

		FitnessClass* curr = head->next;
		while (curr != tail) {
			if (curr->ClassID == ID) {

				FitnessClass* ref = curr;
				curr->prev->next = ref->next;
				ref->next->prev = curr->prev;
				delete ref; //desctrutor for FitnessClass, also calls destructor for listSessions

				cout << "Fitness Class with ID " << ID << " deleted successfully!\n";
				break;
			}
			curr = curr->next;

			if (curr == tail) {
				cout << "Error! The ID entered does not match the ID of any Fitness Class\n";
				break;
			}
		}
	}

	void updateFitnessClassName() {
		FitnessClass* curr = head->next;
		string ID;
		string newname;

		cout << "Enter the ID of the Class:\n";
		cin >> ID;

		while (curr != tail) {
			if (curr->ClassID == ID) {
				cout << "Please enter the new Fitness Class Name:\n";
				cin >> newname;
				curr->ClassName = newname;
				cout << "Fitness Class Updated Sucessfully!\n";
				break;
			}

			curr = curr->next;
			if (curr == tail) {
				cout << "Error! The ID entered does not match the ID of any Fitness Class\n";
				break;
			}
		}
	}

	void display() const
	{
		FitnessClass* curr = head;
		while (curr != NULL)
		{
			cout << "+------";
			curr = curr->next;
		}
		cout << "+" << endl << "|";
		curr = head;
		while (curr != NULL)
		{
			if (curr == head)		cout << " Head |";
			else if (curr == tail)	cout << " Tail |";
			else 					cout << setw(5) << curr->ClassID << " |";

			curr = curr->next;
		}
		curr = head;
		cout << endl;
		while (curr != NULL)
		{
			cout << "+------";
			curr = curr->next;
		}
		cout << "+" << endl;
	}

};


//Log-in
template <typename T, typename V>
bool login(T x, V y, V z) {
	return x.verifyLogin(y, z);
}



//List of Commands Functions for Admins and Members



int main() {

	DListforAdmin a;
	a.loadData();
	DListforMember b;
	b.loadData();
	DListforFitnessClasses c;
	c.loadData();


	//Loading data from files

	int x = 1; //counter for while loop
	char choice;

	cout << "Welcome to the Fitness Center Management System!\n";

	while (x == 1) {


		string username;
		string password;

		//Main Menu 
		cout << "\nPlease identify your subscription to proceed\n";
		cout << left << setw(15) << "Admin:" << setw(15) << "Member:" << setw(15) << "To Exit Program:" << endl;
		cout << left << setw(15) << "Enter A" << setw(15) << "Enter B" << setw(15) << "Enter C\n" << endl;
		cin >> choice;

		switch (choice) {

		case 'A':
			
			cout << "Please login:\n";
			cout << "Enter username:\n";
			cin >> username;
			cout << "Enter password:\n";
			cin >> password;


			if (login(a, username, password)) {
				cout << "Log-in successful!\n";
			}
			else {
				cout << "Log-in unsuccessful!\n";
				break;
			}

			/*
			cout << "You can now register a member:\n";
			b.registerMember();*/
			
			cout << "Deleting a Class:\n";
			c.deleteFitnessClass();

			break;

		case 'B':

			//Login			
			//Registration
			b.registerMember();


			break;

		case 'C':
			cout << "Please confirm your choice\n";
			break;

		default:
			cout << "Error! Invalid  Selection" << endl;

		}



		//Exit display
		cout << "\nTo " << endl;
		cout << left << setw(35) << "Return to the main menu:" << setw(35) << "Exit the program:" << endl;
		cout << left << setw(35) << "Enter 1" << setw(35) << "Enter 0\n" << endl;

		//Validating counter for the main menu loop
		//To ensure that x can only be 1 or 0

		if (!(cin >> x)) { //To validate an integer input in x

			//To clear the buffer memory
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\nInvalid selection!\nYou will now be returned to the main menu\n" << endl;
			x = 1;
		}

		if (x != 1 && x != 0) { //To validate input of only 1 or 0
			cout << "\nInvalid selection!\nYou will now be returned to the main menu\n" << endl;
			x = 1;
		}
	}



	return 0;
}