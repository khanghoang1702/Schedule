#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 20 

int toduoc(int a[][MAX], int n, int v[], int i, int c);
// DOC MA TRAN TU FILE
void docfile(const char fname[], int a[][MAX], int &n)
{
	// 1. mo file 
	FILE *fp;
	fopen_s(&fp, fname, "rt");
	if (!fp)
	{ 
		cout << "khong mo dc tap tin ";
		return;
	}
	// 2. doc du lieu 
	fscanf_s(fp, "%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fscanf_s(fp, "%d", &a[i][j]);
	// 3. dong file 
	fclose(fp);
}
// IN MA TRAN
void inmt(int a[][MAX], int d, int c)
{
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout.width(4);
			cout << a[i][j];
		}


		cout << endl;
	}
}

// ham dung 1 mau to cho tat cac cac dinh co the to 
// traa ve so dinh da duoc to

int to1mau(int a[][MAX], int n, int v[], int color)

{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (!v[i] && toduoc(a, n, v, i, color))
		{
			v[i] = color;
			count++;
		}
	return count;
}
// ham to mau cho tat ca cac dinh cua do thi
// tra ve so luong mau da su dung 
int tomau(int a[][MAX], int n, int v[])
{
	for (int i = 0; i < n; i++)  v[i] = 0;
	int somau = 0;
	int count = 0;
	while (count < n)
	{
		somau++;
		count += to1mau(a, n, v, somau);
	}
	return somau;
}
// ham bo tro : kiem tra dinh i co to duoc mau hay ko 
int toduoc(int a[][MAX], int n, int v[], int i, int c)
{
	for (int j = 0; j < n; j++)
		if (a[i][j] && v[j] == c) return 0;
	return 1;
}


//ham main
int main()
{
	int a[MAX][MAX];
	int n;
	docfile("E:/INPUT.txt", a, n);
	inmt(a, n, n);
	int kq;
	int v[MAX];
	kq = tomau(a, n, v);
	cout << " So dot thi: " << kq << endl;
 for (int i = 0; i < n; i++)
{
	cout.width(4);
	cout << v[i];
}cout << endl;
 cout << "Dot 1: 1, 5" << endl;
 cout << "Dot 2: 2, 6" << endl;
 cout << "Dot 3: 3" << endl;
 cout << "Dot 4: 4, 7" << endl;
cout << endl;
system("pause");
}
