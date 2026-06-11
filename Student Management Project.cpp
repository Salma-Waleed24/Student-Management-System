#include <iostream>
#include <string>
#include<limits>
using namespace std;

// linked list of students

struct Student
{
	string Name;
	int id;
	string year;
	float GPA;
	Student* next;
};

// SMS refers to Student Management System 

class SMS{

private:
	Student* Head; // The head of the list
	int get_size();
	bool Check_id(int id);
	int ReadInt();
	float ReadFloat();
public:
	SMS();
	~SMS();
	void Add_Student();
	void Delete_Student_by_ID(int id);
	void Search_Students(int id);
	void Display_Students();
};

SMS::SMS()
{
	Head = nullptr;
}

SMS::~SMS()
{
	while (Head != nullptr)
	{
		Student* temp = Head;
		Head=Head->next;
		delete temp;
	}
}
int SMS::ReadInt()
{
	int value;

	while (!(cin >> value))
	{
		cout << "Invalid input. Please enter a number: ";

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return value;
}

float SMS::ReadFloat()
{
	float value;

	while (!(cin >> value))
	{
		cout << "Invalid input. Please enter a number: ";

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return value;
}

int SMS::get_size()
{
	Student* current = Head;
	int count = 0;
	while (current != nullptr)
	{
		count++;
		current = current->next;
	}

	return count;
}

bool SMS::Check_id(int id)
{
	Student* current = Head;
	while (current != nullptr)
	{
		if ( current->id==id)
		{
				return true;
		}
		current = current->next;
	}
	return false;
}


// Take data from the user 
void SMS:: Add_Student()
{
	string Name;
	int id;
	string year;
	float GPA;
	
	cout << "Enter the student Name" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, Name);

	cout << "Enter the student id" << endl;
	id = ReadInt();

	cout << "Enter the student year" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, year);

	cout << "Enter the student GPA" << endl;
	GPA= ReadFloat();



	Student* temp = new Student;
	Student*Location;

	temp->Name = Name;
	temp->year = year;
	temp->id = id;
	temp->GPA = GPA;
	temp->next = nullptr;

	if (Head == nullptr)

		Head = temp;

	
	else if (Head != nullptr )
	{
		Location = Head;
		while(Location->next!=nullptr)
			Location = Location->next;
		Location->next = temp;
	}
	
}

void SMS::Display_Students()
{
	Student* current = Head;
	if(current == nullptr)
	{
		cout << "The list is empty, No students to show" << endl;
		return;
	}
	while (current != nullptr)
	{
		cout << "-----------------------------------------" << endl;
		cout << "Student name is : " << current->Name << endl;
		cout << "His year is : " << current->year << endl;
		cout << "His ID is : " << current->id << endl;
		cout << "His GPA is : " << current->GPA << endl;
		cout << "-----------------------------------------" << endl;
		current = current->next;
	}
}

void SMS::Search_Students(int id)
{
	Student* current = Head;
	while (current != nullptr)
	{
		if (current->id == id)
		{
			cout << "-----------------------------------------" << endl;
			cout << "Student name is : " << current->Name << endl;
			cout << "His year is : " << current->year << endl;
			cout << "His GPA is : " << current->GPA << endl;
			cout << "-----------------------------------------" << endl;
			return;
		}
		current = current->next;
	}
	cout << "ID is not found, please check it" << endl;

}


void SMS::Delete_Student_by_ID(int id)
{

	Student* temp, * Location;
	Location = Head;

	if (Head == nullptr)
	{
		cout << "The list is empty, No students to delete." << endl;
		return;
	}
	if (Head->id == id)
	{
		temp = Head;
		Head = Head->next;
		delete temp;
		return;
	}

	while (Location != nullptr && Location->next != nullptr)
	{
		if (((Location->next)->id) == id)
		{
			temp = Location->next;
			Location->next = temp->next;
			delete temp;
			return;
		}
		Location = Location->next;
	}

	cout << "This ID is not in the system, please check it." << endl;

}


int main()
{
	SMS student;
	int choice;
	do
	{
		cout << "-----------Student Management System-----------\n";
		cout << "1.Add Student" << endl;
		cout << "2.Search for a student using ID\n";
		cout << "3.Delete Student by ID\n";
		cout << "4.Display all Students\n";
		cout << "5.Exit\n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			student.Add_Student();
			break;

		case 2:
		{
			int id; 
			cout << "enter ID\n";
			cin>> id;
			student.Search_Students(id);
			break;
		}
			
		case 3:
		{
			int id;
			cout << "enter ID\n";
			cin >> id;
			student.Delete_Student_by_ID(id);
			break;
		}

		case 4:
			student.Display_Students();
			break;

		case 5:
			cout << "Good bye " << endl;
			break;

		default:
			cout << "Invalid choice " << endl;

		} 

    } while (choice != 5);

	return 0;
}