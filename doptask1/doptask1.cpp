#include <iostream>
#include <string>
using namespace std;


class House
{
protected:
	string Name;
	int Number;

public:
	House(string name, int number) : Name(name), Number(number) {}
	virtual void Print() = 0;
	virtual ~House() {}
};


class EducationalBuilding : public House
{
public:
	EducationalBuilding(string name, int number) : House(name, number)
	{
	}
	void Print() override
	{
		cout << Name << endl;
		cout << Number << endl;
	}
};



int main()
{
	setlocale(LC_ALL, "ukr");
	const int N = 3;
	House* ptr[N];
	ptr[0] = new EducationalBuilding("Навчальний Корпус №1", 1);
	ptr[1] = new EducationalBuilding("Навчальний Корпус №2", 5);
	ptr[2] = new EducationalBuilding("Навчальний Корпус №3", 7);

	for (int i = 0; i < N; i++)
	{
		ptr[i]->Print();
		cout << endl;
	}
	for (int i = 0; i < N; i++)
	{
		delete[] ptr[i];
	}
	return 0;
}