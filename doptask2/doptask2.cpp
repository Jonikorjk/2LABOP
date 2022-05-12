#include <iostream>
#include <string>
using namespace std;


class Gadget
{
protected:
	string Model;
	int PowerOfPhone;

public:
	Gadget(string model, int powerofphone) : Model(model), PowerOfPhone(powerofphone) {}
	virtual void Print() = 0;
	virtual ~Gadget() {}
};


class MobilePhone : public Gadget
{
public:
	MobilePhone(string model, int power) : Gadget(model, power)
	{
	}
	void Print() override 
	{
		cout << Model << endl;
		cout << PowerOfPhone << endl;
	}
};



int main()
{
	const int N = 3;
	Gadget* ptr[N];
	ptr[0] = new MobilePhone("SamsungTab1242", 1);
	ptr[1] = new MobilePhone("Iphone32R2", 5);
	ptr[2] = new MobilePhone("Xiaomi 42", 7);

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