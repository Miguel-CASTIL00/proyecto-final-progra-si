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
	//arriba izquierda
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
	//arriba medio
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
	
	//arriba derecha
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
		intentos();
		gotoxy(50, 4);
		cout << "RESPUESTA CORRECTA!" << endl;
		bol = false;
		Sleep(3000);
		antx = coordx;
		
		anty = coordy;
		posiantx = posicionx;
		posianty = posiciony;
		gotoxy(50, 4);
		cout << "                                          " << endl;
		system("cls");
		intentos();
		resetPasa();
	}
	else
	{
		intentos();
		gotoxy(50, 4);
		cout << "incorrecta !" << endl;
		intento++;
		Sleep(3000);
		coordx = antx;
		coordy = anty;
		posicionx = posiantx;
		posiciony = posianty;
		gotoxy(50, 4);
		cout << "                                          " << endl;
		system("cls");
		intentos();
		resetPasa();
		
	}
	
	return 0;
}
void instrucciones() {
	SetConsoleTextAttribute(hConsole, 3);
	cout << "PREPARATE!" << endl;
	Sleep(1250);
	cout << "Cada 2 movimientos te bloquearas" << endl;
	Sleep(1250);
	cout << "Te rodearan los numeros " << endl;
	Sleep(1250);
	cout << "Suma los de arriba y multiplicalo por el de la derecha en medio" << endl;
	Sleep(1250);
	cout << "Suma los de abajo y multiplicalo por el de la izquierda en medio " << endl;
	Sleep(1250);
	cout << "resta el resultado de arriba - el de abajo y resuelve!!!";
	Sleep(2250);
}
void juego() {
	
	generadornumeros();
	signos();
	matriz();
	intentos();
	coordx = 3; coordy = 9;
	int valor;
	posicionx = 1;
	posiciony = 5;
	int ascii = 254;
	antx = 3;
	anty = 9;
	ganar = 0;
	posiantx = 1;
	posianty = 5;
	contador = 0;
	intento = 0;
	ask = true;
	gotoxy(coordx, coordy);
	cin;
	while (intento !=8)
	{
		
		while (ask)
		{
			
			valor = _getch();
			
			if (valor == 224) {
				valor = _getch();
				switch (valor) {
				case 72: 
					if (posiciony + 1 > 2)
					{
						coordy = coordy - 2;
						
						gotoxy(coordx, coordy);
						cin;
						posiciony = posiciony - 1;
						contador++;
						if (posicionx==5&&posiciony==1)
						{
							ganar = 1;
							ask = false;
							intento = 8;
							contador = 0;
							Sleep(500);
						}
						
					}
					break;
				case 80: 
					if (posiciony - 1 < 4)
					{
						coordy = coordy + 2;
						
						gotoxy(coordx, coordy);
						cin;
						posiciony = posiciony + 1;
						contador++;
						
					}
					
					break;
				case 75: 
					if (posicionx + 1 > 2)
					{
						coordx = coordx - 5;
						
						gotoxy(coordx, coordy);
						cin;
						posicionx = posicionx - 1;
						contador++;
						
					}
					
					break;
				case 77: 
					if (posicionx - 1 < 4)
					{
						coordx = coordx + 5;
						
						gotoxy(coordx, coordy);
						cin;
						posicionx = posicionx + 1;
						contador++;
						if (posicionx == 5 && posiciony == 1)
						{
							ganar = 1;
							ask = false;
							intento = 8;
							contador = 0;
							Sleep(500);
						}
					}
					
					break;
					
				}
				if (contador == 2)
				{
					SetConsoleTextAttribute(hConsole, 4);
					cout << char(ascii);
					ask = false;
					SetConsoleTextAttribute(hConsole, 8);
					
				}
			}
			else if (valor == 27) {
				ask = false;
				contador2 = 1;
				intento = 8;
			}
			
		}
		if (contador2==0 && contador==2)
		{
			impresionnumeros(posicionx,posiciony);
		}
		
		
	}
	
	
	if (ganar==1)
	{
		system("cls");
		cout << "FELICIDADES HA GANADO!" << endl;
		system("pause");
		
	}
	else if(ganar==0&&contador2==0)
	{
		system("cls");
		cout << "HA PERDIDO :C" << endl;
		system("pause");
	}
	else
	{
		system("cls");
		cout << "salido del juego, Suerte!" << endl;
		system("pause");
		menu = false;
	}
}
int repetirmenu() {
	int op = 0;
	SetConsoleTextAttribute(hConsole, 3);
	cout << "DESEA JUGAR?" << endl << "1.Si" << endl << "2.No" << endl;
	cin >> op;
	return op;
}
int main()
{
	
	int op = 0;
	while (menu)
	{
		
		SetConsoleTextAttribute(hConsole, 3);
		system("cls");
		op = repetirmenu();
		if (op==1)
		{
			system("cls");
			instrucciones();
			system("cls");
			juego();
		}
		else if (op==2)
		{
			system("cls");
			cout << "salido del juego, Suerte!" << endl;
			system("pause");
			menu = false;
		}
		else
		{
			system("cls");
			cout << "Opcion invalida" << endl;
			system("pause");
			
		}
		
		
	}
	
}
