#include <iostream>
using namespace std;

void OutputNETELEMENTOVMASIVA();

template<class T, int size>
class Array
{
private: 
	T arr[size];

public:
	const T& GetElementOfArray(int elem) const
	{
		return arr[elem];
	}

	friend istream& operator>>(istream& in, Array<T,size>& a)
	{
		for (int i = 0; i < size ; i++)
		{
			in >> a.arr[i];
		}
		return in;
	}
};

template<class T, int size>
void FindElementInRange(T start, T end, const Array<T,size>& a)
{
	bool isExist = false; // Хотя бы один элемент найдётся в промежутке
	cout << "Елементы массива входящие в промежуток: ";
	for (int i = 0; i < size; i++)
	{
		if (a.GetElementOfArray(i) < end && a.GetElementOfArray(i) > start)
		{
			cout << a.GetElementOfArray(i) << " ";
			isExist = true;
		}
	}
	if (!isExist)
	{
		OutputNETELEMENTOVMASIVA();
	}
}

void OutputNETELEMENTOVMASIVA()
{
	cout << "Нет элементов массива входящий в этот промежуток." << endl;
}
int main()
{
	setlocale(LC_ALL, "ru");
	Array<double, 5> array;
	cin >> array;
	FindElementInRange(-10., 15., array);
}