#include <iostream>
using namespace std;

template<class T>
class Pair
{
private:
	T fValue, sValue;

public:
	void setfValue(T a) { fValue = a; }
	void setsValue(T a) { sValue = a; }
	T getfValue() const { return fValue; }
	T getsValue() const { return sValue; }
	Pair(T fValue, T sValue)
	{
		this->fValue = fValue;
		this->sValue = sValue;
	}
	Pair() : Pair(0,0) {}
	Pair(const Pair& a)
	{
		fValue = a.fValue;
		sValue = a.sValue;
	}
	Pair operator+(const Pair<T>& a)
	{
		Pair temp;
		temp.fValue = fValue + a.fValue;
		temp.sValue = sValue + a.sValue;
		return temp;
	}
	Pair operator-(const Pair& a)
	{
		Pair temp;
		temp.fValue = fValue - a.fValue;
		temp.sValue = sValue - a.sValue;
		return temp;
	}
	Pair operator*(const Pair& a)
	{
		Pair temp;
		temp.fValue = fValue * a.fValue;
		temp.sValue = sValue * a.sValue;
		return temp;
	}
	Pair operator/(const Pair& a)
	{
		Pair temp;
		temp.fValue = fValue / a.fValue;
		temp.sValue = sValue / a.sValue;
		return temp;
	}
	Pair& operator=(const Pair& a)
	{
		fValue = a.fValue;
		sValue = a.sValue;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Pair& a)
	{
		out << "Pair: " << a.fValue << " " << a.sValue << endl;
		return out;
	}
};

template<typename T1, typename T2>
Pair<T2> operator+(const Pair<T1>& a, const Pair<T2>& b)
{
	Pair<T2> temp;
	temp.setfValue(a.getfValue() + b.getfValue());
	temp.setsValue(a.getsValue() + b.getsValue());
	return temp;
}


int main()
{
	Pair<int> pair(3, 5);
	Pair<double> somePair(12.1, 5.6);
	Pair<double> a;
	a = pair + somePair;
	cout << a;
}