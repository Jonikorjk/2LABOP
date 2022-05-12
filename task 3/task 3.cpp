#include <iostream>
using namespace std;


template <class T>
class Array
{
private:
	T** ptr = nullptr;
	int rows, colz;

	bool IndexOfRowsIsRight(int rows) { return (this->rows > rows && rows >= 0); }
	bool IndexOfColzIsRight(int colz) { return (this->colz > colz && colz >= 0); }

public:
	class Exception
	{
	private:
		const char* textOfError;
		int badIndex;

	public:
		Exception(const char* error, int index) : textOfError(error), badIndex(index) {}
		int getBadIndex() const { return badIndex; }
		const char* getTextOfError() const { return textOfError; }
	};

	Array(int rows, int colz) 
	{
		this->rows = rows;
		this->colz = colz;
		ptr = new T * [rows];
		for (int i = 0; i < rows; i++)
		{
			ptr[i] = new T[colz];
		}
	}
	Array() : Array(1, 1)
	{
	}
	Array(const Array& a)
	{
		rows = a.rows;
		colz = a.colz;
		ptr = new T * [rows];
		for (int i = 0; i < rows; i++)
		{
			ptr[i] = new T[colz];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < colz; j++)
			{
				ptr[i][j] = a(i,j);
			}
		}
	}
	~Array()
	{
		if (ptr != nullptr)
		{
			for (int i = 0; i < rows; i++)
			{
				delete[] ptr[i];
			}
			delete[] ptr;
		}
	}
	T& operator()(int rows, int colz);
	//{
	//	if (!IndexOfRowsIsRight(rows))
	//	{
	//		throw Exception("BadIndexOfRows", rows);
	//	}
	//	if (!IndexOfColzIsRight(colz))
	//	{
	//		throw Exception("BadIndexOfColz", colz);
	//	}
	//	return ptr[rows][colz];
	//}
	T GetMin();
	int GetRows() { return rows; }
	int GetColz() { return colz; }
	friend ostream& operator<<(ostream& out, const Array<T>& a)
	{
		for (int i = 0; i < a.rows; i++)
		{
			for (int j = 0; j < a.colz; j++)
			{
				out << a.ptr[i][j] << "\t";
			}
			out << endl;
		}
		return out;
	}
	friend istream& operator>>(istream& in, Array<T>& a)
	{
		for (int i = 0; i < a.rows; i++)
		{
			for (int j = 0; j < a.colz; j++)
			{
				in >> a(i,j);
			}
		}
		return in;
	}
};

template<class T>
T Array<T>::GetMin()
{
	T Min = 0;						// Значение которое будем выводить		
	T* minOfRow = new T[rows];		// Вспомогательный массив для записывания минимального элемента каждой строчки

	for (int i = 0; i < rows; i++)
	{
		int j = 0;						// Для того чтобы записать одно значение из строчки для сравнения с другими значениями этой строчки
		minOfRow[i] = ptr[i][j];
		for (; j < colz; j++)
		{
			if (minOfRow[i] > ptr[i][j])
			{
				minOfRow[i] = ptr[i][j];	
			}
		}
	}
	Min = minOfRow[0];
	for (int i = 0; i < rows; i++)
	{
		if (Min > minOfRow[i]) Min = minOfRow[i]; // Сравнение какое минимальное значение каждой строчки меньше
	}
	delete[] minOfRow;
	minOfRow = nullptr;
	return Min;
}

template<class T>
T& Array<T>::operator()(int rows, int colz)
{
	if (!IndexOfRowsIsRight(rows))
	{
		throw Exception("BadIndexOfRows", rows);
	}
	if (!IndexOfColzIsRight(colz))
	{
		throw Exception("BadIndexOfColz", colz);
	}
	return ptr[rows][colz];
}

template<class T>
void Change(Array<T>& a)
{
	for (int i = 0; i < a.GetRows(); i++)
	{
		for (int j = 0; j < a.GetColz(); j++)
		{
			if (a(i,j) == 0)
			{
				a(i,j) = 1;
			}
		}
	}
}

int main()
{
	/*Array<int> array(3, 3);*/
	Array<double> array(2, 2);
	cin >> array;
	cout << endl << endl;
	cout << array;
	cout << endl << endl;
	try
	{
		cout << array(1, 1);
	}
	catch (const Array<int>::Exception& exception)
	{
		cout << exception.getTextOfError() << "---" << exception.getBadIndex();
	}
	catch (const Array<double>::Exception& exception)
	{
		cout << exception.getTextOfError() << "---" << exception.getBadIndex();
	}
	catch (const Array<char>::Exception& exception)
	{
		cout << exception.getTextOfError() << "---" << exception.getBadIndex();
	}
}