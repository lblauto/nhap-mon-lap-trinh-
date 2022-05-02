#include<iostream>
#include<fstream>
#include<iomanip>
#include<queue>
#include<stack>
using namespace std;

const int MAX = 100;
#define fn "E:\\hoc ky 2\\ly thuyet do thi\\test3.txt"

int visited[MAX];
int nSoMienLienThong;
//int Free[MAX];
//int Trace[MAX];
int Queue[MAX];
int QueueCount, QueueIndex = 0;
int x, CanhLT[MAX][MAX], dem[MAX], tongcanh = 1;

struct GRAPH
{
	int sodinh;
	int a[MAX][MAX];
};

int KiemTraMaTranHopLe(GRAPH& g);
int KiemTraDoThi(GRAPH& g);
void XetLienThong(GRAPH& g);
void visit(GRAPH g, int i, int nLabel);
void InThanhPhanLienThong(GRAPH g);
void ThemCanhLienThong(GRAPH& g);

void readGraph(string file, GRAPH& g)
{
	ifstream f;
	f.open(file);
	if (f.is_open())
	{
		f >> g.sodinh;
		for (int i = 0; i < g.sodinh; i++)
			for (int j = 0; j < g.sodinh; j++)
				f >> g.a[i][j];
		f.close();
	}
	else cout << "khong mo duoc file !!";
}


void printGraph(GRAPH g)
{
	cout << "So dinh cua do thi la: " << g.sodinh << endl;
	for (int i = 0; i < g.sodinh; i++)
	{
		for (int j = 0; j < g.sodinh; j++)
			cout << setw(4) << g.a[i][j];
		cout << endl;
	}
}


int CheckMaTranKeHopLe(GRAPH& g)
{
	int i;
	for (i = 0; i < g.sodinh; i++)
		if (g.a[i][i] != 0)
			return 0;
	return 1;
}


int KiemTraDoThi(GRAPH& g)
{
	int i, j;
	for (i = 0; i < g.sodinh; i++)
		for (j = 0; j < g.sodinh; j++)
			if (g.a[i][j] != g.a[j][i])
				return 0;
	return 1;
}

void visit(GRAPH g, int i, int nLabel)
{
	visited[i] = nLabel;
	for (int j = 0; j < g.sodinh; j++)
	{
		if (visited[j] == 0 && g.a[i][j] != 0)
		{
			visit(g, j, nLabel);
		}
	}
}

void XetLienThong(GRAPH& g)
{
	for (int i = 0; i < g.sodinh; i++)
		visited[i] = 0;
	nSoMienLienThong = 0;

	for (int i = 0; i < g.sodinh; i++)
		if (visited[i] == 0) {
			nSoMienLienThong++;
			visit(g, i, nSoMienLienThong);
		}
}


void InThanhPhanLienThong(GRAPH g)
{
	cout << "So mien lien thong : " << nSoMienLienThong << endl;

	for (int i = 1; i <= nSoMienLienThong; i++)
	{
		cout << "Mien lien thong thu " << i << endl;
		for (int j = 0; j < g.sodinh; j++) 
		{
			if (visited[j] == i)
			{
				CanhLT[i - 1][dem[i - 1]] = j;
				dem[i - 1]++;
				cout << j+1 << setw(4);
			}
		}
		cout << endl;
		tongcanh *= dem[i - 1];
	}
}

void ThemCanhLienThong(GRAPH& g)
{
	cout << "So canh toi thieu: " << nSoMienLienThong - 1 << endl;
	cout << "Tong truong hop: " << tongcanh << endl;
	for (int i = 0; i < nSoMienLienThong; i++)
	{
		for (int j = 0; j < dem[i]; j++)
		{
			for (int q = 0; q < dem[i + 1]; q++)
			{
				cout << CanhLT[i][j] << CanhLT[i + 1][q] << setw(5);
			}
		}
	}
}

int main()
{
	GRAPH g;
	readGraph(fn, g);
	//printGraph(g);

	if (KiemTraDoThi(g) == 1)
	{
		XetLienThong(g);
		if (nSoMienLienThong == 1)
		{
			cout << "LIEN THONG\n";
		}
		else
			cout << "KHONG LIEN THONG\n";
	}

	XetLienThong(g);
	InThanhPhanLienThong(g);
	ThemCanhLienThong(g);
	return 0;
}

























