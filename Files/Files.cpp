#include <iostream>
#include <fstream>
#include <io.h>

using namespace std;

class Person
{
	string name;
	string surname;
	int day;
	int month;
	int year;

public:
	Person() : Person("Yuriy", "Solomon", 13, 11, 1983) {}
	Person(string name, string surname, int day, int month, int year)
	{
		SetName(name);
		SetSurname(surname);
		SetDay(day);
		SetMonth(month);
		SetYear(year);
	}
	void SetName(string name)
	{
		this->name = name;
	}
	void SetSurname(string surname)
	{
		this->surname = surname;
	}
	void SetDay(int day)
	{
		this->day = day;
	}
	void SetMonth(int month)
	{
		this->month = month;
	}
	void SetYear(int year)
	{
		this->year = year;
	}
	string GetName() const
	{
		return name;
	}
	string GetSurname() const
	{
		return surname;
	}
	int GetDay() const
	{
		return day;
	}
	int GetMonth() const
	{
		return month;
	}
	int GetYear() const
	{
		return year;
	}	
	void Print()
	{
		cout << "Имя = " << GetName() << "\n";
		cout << "Имя = " << GetSurname() << "\n";
		printf("Дата Рождения = %02d:%02d:%4d \n", GetDay(), GetMonth(), GetYear());
	}
};

class Files
{
public:
	static const char* path;
	
	static void File()
	{
		int n;
		cout << "1. Write\n2. Read\n";
		cout << "Select menu item 1 or 2:";
		cin >> n;
		system("cls");
		if (n == 1)
		{
			ofstream out("student.txt", ios::binary | ios::out | ios::trunc); 
			if (!out.is_open()) 
			{
				cout << "Error to WRITE\n";
				return;
			}

			Person p;
			
			out.seekp(sizeof(Person), ios::beg); 				
			out.write((char*)&p, sizeof(p)); 
			out.close(); 
		}
		else
		{
			ifstream in("student.txt", ios::binary | ios::in); 
			if (!in.is_open()) 
			{
				cout << "Error to READ)\n";
				return;
			}

			in.seekg(sizeof(Person), ios::beg); 				
			Person p;
			in.read((char*)&p, sizeof(Person)); 
			cout << p.GetName() << endl << p.GetSurname() << endl << p.GetDay() << ":" << p.GetMonth() << ":" << p.GetYear() << endl << endl;
			in.close(); 
		}

		cout << "\nSave to File DONE!\n";
	}

};

const char* Files::path = "file.txt";

int main()
{
	Files::File();
}