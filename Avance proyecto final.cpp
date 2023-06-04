#include <iostream>
#include <Windows.h>
#include<stdlib.h>
#include<conio.h> 
#include <time.h>
#include<cstdalign>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;
char cruz = 206;
char horizontal = 205;

char vertical = 186;
char esquinasupizq = 201;  bool ask = true, menu = true;
char esquinasupd = 187;
char esquinainfizq = 200;
char esquinainfder = 188;
int posicionx = 1, posiciony = 5;
char Taprriba = 203;
char Tapbajo = 202;
int contador = 0, contador2 = 0;
int matriznumeros[5][5];
int f=5, c=5, intento=0;
int coordx = 3, coordy = 9;
int vv = 3;
int bb = 0,ganar=0;
int antx = 0, anty = 0;
int posiantx = 0, posianty = 0;
void gotoxy(int x, int y)
{
	HANDLE hcon;
	//PREPARAR IOSTREAM (Cin, Cout) para ponerle posicion
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	//Crear la cordenada
	COORD dwpos;
	dwpos.X = x;
	dwpos.Y = y;
	//asignar posicion
	SetConsoleCursorPosition(hcon, dwpos);
}
void generadornumeros() {
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			
			matriznumeros[i][j] = 1 + rand() % (11 - 1);
		}
	}
}
void matriz() {
	SetConsoleTextAttribute(hConsole, 8);
	f = 5, c = 5;
	for (int i = 0; i < f + 1; i++)
	{
		for (int j = 0; j < c * 5; j++)
		{
			gotoxy(j, i * 2);
			cout << horizontal;
		}
		cout << endl;
	}
	for (int i = 0; i < c + 1; i++)
	{
		for (int j = 0; j < (2 * f) - 1; j++)
		{
			gotoxy(i * 5, j + 1);
			cout << vertical;
		}
	}
	5 * c;
	for (int i = 0; i < 5 * c; i += 5)
	{
		if (i != 0)
		{
			gotoxy(i, 0);
			cout << Taprriba;
		}
	}
	5 * c;
	for (int i = 0; i < 5 * c; i += 5)
	{
		if (i != 0)
		{
			gotoxy(i, f * 2);
			cout << Tapbajo;
		}
	}
	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < 5 * c; j += 5)
		{
			
			if ((i != 0) && (j != 0))
			{
				gotoxy(j, i * 2);
				cout << cruz;
			}
			
		}
		
	}
	bb = 1;
	vv = 3;
	for (int i = 0; i < c; i++)
	{
		gotoxy(vv, (f * 2) + 1);
		
		vv = vv + 5;
		bb = bb + 1;
	}
	bb = 1;
	vv = 1;
	for (int i = 0; i < f; i++)
	{
		gotoxy((c * 5) + 1, vv);
		
		vv = vv + 2;
		bb = bb + 1;
	}
	gotoxy(0, 0);
	cout << esquinasupizq;
	gotoxy(5 * c, 0);
	cout << esquinasupd;
	gotoxy(0, 2 * f);
	cout << esquinainfizq;
	gotoxy(5 * c, 2 * f);
	cout << esquinainfder;
	gotoxy(26,1);
	cout << "META";
	gotoxy(0, 11);
	cout << "INICIO";
}
void signos() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 6);
	
	for (int i = 0; i < f * 2; i++)
	{
		gotoxy(0, i);
		for (int j = 0; j < c; j++)
		{
			cout << "  " << " ?" << ' ';
		}
		cout << endl;
	}
	
}
void intentos() {
	int mequedan = 8;
	mequedan = mequedan - intento;
	gotoxy(60, 0);
	cout << "TIENES: " << mequedan << " INTENTOS";
}
void resetPasa() {
	signos();
	matriz();
	contador = 0;
	ask = true;
	gotoxy(coordx, coordy);
	cin;
	
}
int impresionnumeros(int corsx , int corsy) {
	
	int resularriba = 0;
	int resulabajo = 0;
	int resp = 0;
	int total = 0;
	if (corsx>1 && corsy>1)
	{
		gotoxy(coordx-5,coordy-2);
		cout << matriznumeros[corsx-2][corsy-2];
		resularriba = resularriba + matriznumeros[corsx - 2][corsy - 2];
	}
	else
	{
		resularriba = resularriba + 0;
	}
	
	if (corsy > 1)
	{
		gotoxy(coordx, coordy - 2);
		cout << matriznumeros[corsx - 1][corsy - 2];
		resularriba = resularriba + matriznumeros[corsx-1][corsy - 2];
	}
	else
	{
		resularriba = resularriba + 0;
	}
	
	
	if (corsx <5 && corsy > 1)
	{
		gotoxy(coordx + 5, coordy - 2);
		cout << matriznumeros[corsx][corsy - 2];
		resularriba = resularriba + matriznumeros[corsx][corsy - 2];
	}
	else
	{
		resularriba = resularriba + 0;
	}
	
	//abajo izquierda
	if (corsx > 1 && corsy < 5)
	{
		gotoxy(coordx - 5, coordy + 2);
		cout << matriznumeros[corsx-2][corsy];
		resulabajo = resulabajo + matriznumeros[corsx - 2][corsy];
	}
	else
	{
		resulabajo = resulabajo + 0;
	}
	//abajo medio
	if ( corsy  < 5)
	{
		gotoxy(coordx, coordy + 2);
		cout << matriznumeros[corsx - 1][corsy];
		resulabajo = resulabajo + matriznumeros[corsx - 1][corsy];
	}
	else
	{
		resulabajo = resulabajo + 0;
	}
	//abajo derecha
	if (corsy < 5 && corsx < 5)
	{
		gotoxy(coordx + 5, coordy + 2);
		cout << matriznumeros[corsx][corsy];
		resulabajo = resulabajo + matriznumeros[corsx][corsy];
	}
	else
	{
		resulabajo = resulabajo + 0;
	}
	//medio izquierda
	if (corsx>1)
	{
		gotoxy(coordx - 5, coordy);
		cout << matriznumeros[corsx-2][corsy-1];
		resulabajo = resulabajo * matriznumeros[corsx - 2][corsy - 1];
	}
	else
	{
		resulabajo = resulabajo * 0;
	}
	//medio derecha
	if (corsx < 5)
	{
		gotoxy(coordx + 5, coordy);
		cout << matriznumeros[corsx][corsy - 1];
		resularriba = resularriba * matriznumeros[corsx][corsy - 1];
	}
	else
	{
		resularriba = resularriba * 0;
	}
	total = resularriba - resulabajo;
	bool bol = true;
	
	intentos();
	gotoxy(50, 4);
	cout << "INGRESE LA RESPUESTA"<<endl;
	gotoxy(50, 5);
	cin >> resp;
	gotoxy(50, 5);
	cout << "                                          " << endl;
	gotoxy(50, 4);
	cout << "                                          " << endl;
	if (resp==total)
	{
