#include<iostream>
#include<iomanip>
#include<time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int high, const int low);
void Print(int** a, const int k, const int n);
int Calc(int** a, const int k, const int n);

int main()
{
	srand((unsigned)time(NULL));

	int high = 30;
	int low = 1;
	int S = 0;
	int k, n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;


	int** a = new  int* [k];
	for (int i = 0; i < k; i++)
	{
		a[i] = new int[n];
	}

	Create(a, k, n, high, low);
	Print(a, k, n);
	S = Calc(a, k, n);

	cout << "S = " << S << endl;


	for (int i = 0; i < k; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	return 0;
}

void Create(int** a, const int k, const int n, const int high, const int low)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = low + rand() % (high - low + 1);
		}
	}
}

void Print(int** a, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int Calc(int** a, const int k, const int n)
{
	int max;
	int S = 0;
	for (int i = 1; i < k; i += 2)
	{
		max = a[i][0];
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
			}
		}
		S += max;
	}
	return S;
}