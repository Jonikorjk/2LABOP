#include <iostream>
#include <string>
using namespace std;

class Human
{
private:
	int age;
	int weight;
	int height;
	string name;

public:
	Human(string name, int age, int height, int weight)
	{
		this->name = name; 
		this->age = age;
		this->height = height;
		this->weight = weight;
	}
	virtual void GetInfo()
	{
		cout << "Имя: " << name << " Возраст: " << age << " Рост: " << height << " Вес: " << weight << endl;
	}
	virtual ~Human(){}
};

struct Citizen : public Human 
{
private:
	string citizenship;

public:
	Citizen(string name, int age, int height, int weight, string citizenship) : Human(name, age, height, weight)
	{
		this->citizenship = citizenship;
	}
	void GetInfo() override 
	{
		Human::GetInfo();
		cout << "Гражданство: " << citizenship << endl;
	}
	virtual ~Citizen() {}
};

class Student final : public Citizen 
{
private: 
	int scolarship;
	int course; 

public:
	Student(string name, int age, int height, int weight, string citizenship, int scolarship, int course) :
		Citizen(name, age, height, weight, citizenship)
	{
		this->scolarship = scolarship;
		this->course = course;
	}
	void GetInfo() final
	{
		Citizen::GetInfo();
		cout << "Стипендия: " << scolarship << " Курс: " << course << endl;
	}
};

class Employee final : public Citizen
{
private:
	int salary;
	string profession;

public:
	Employee(string name, int age, int height, int weight, string citizenship, int salary, string profession) : 
		Citizen(name, age, height, weight, citizenship)
	{
		this->salary = salary;
		this->profession = profession;
	}
	void GetInfo() final
	{
		Citizen::GetInfo();
		cout << "Зарплата: " << salary << " Профессия: " << profession << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "ru");
	const int N = 3;
	Human* ptr[N];
	ptr[0] = new Employee("Василий", 37, 192, 79, "украинец", 17000, "Строитель");
	ptr[1] = new Student("Александр", 17, 189, 67,"украинец", 2000, 1);
	ptr[2] = new Citizen("Себастьян", 39, 195, 94, "украинец");

	for (int i = 0; i < N; i++)
	{
		ptr[i]->GetInfo();
		cout << endl;
		cout << endl;
	}

	for (int i = 0; i < N; i++)
	{
		delete ptr[i];
	}
	
	for (int i = 0; i < N; i++)
	{
		ptr[i] = nullptr;
	}
	return 0;
}