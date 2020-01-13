/*
Дан текстовый файл, содержащий программу на языке С++.
Проверить эту программу на соответствие открывающих и закрывающих скобок разных типов
(), {}, [].
проверка комментариев {][}(];
*/
//{][}(]
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

int Check(string a, unsigned int b);
int findround(string a, int i);

int main()
{
	string a;//строка ввода
	cout << "Enter name of file\n";
	getline(cin, a);//ввод названия файла

	ifstream file(a);//открытие файла с названием, который ввел пользователь
	if (!file.is_open())//проверка открытости файла, вывод об ошибке и закрытие программы
	{
		cout << "Error, cannot open file";
		return 1;
	}

	string b;//буферная переменная для ввода
	a.clear();//отчистка от названия файла
	while (file.good())
	{
		getline(file, b);
		a += b + "\n";
	}
	file.close();
	cout << a << endl;
}

int Check(string a, int b)
{
	for (int i = b; i < a.length(); i++)//перебираем каждый символ
	{
		switch (a[i])
		{
		case '/'://если обнаружен комментарий
			if (!a.length() == i - 1)//если не конец файла
			{
				if (a[i + 1] == '/')//если комментарий типа "//"
				{
					i++;
					for (; i < a.length() && !(a[i] == '\n'); i++) {} //если не конец строки и символ не \n i++
				}

				if (a[i + 1] == '*' && i + 2 < a.length())//если комментарий типа "/*    */" и не конец файла
				{
					i += 2;//переход после "/*"
					for (; i + 1 < a.length() && a[i] == '*' && a[i + 1] == '/'; i++)
					{//если i+1 не конец файла и найдено сочетание "*/" i++
					}
				}
			}
			break;

		case '(':
		{
			i = findround(a, i+1);
			if (i<0)
			{
				return i;
			}
			break;
		}
		case '[':
			//i=findsquare(a, i);
			if (i < 0)
			{
				return i;
			}
			break;

		case'{':
			//i= findbraces(a, i);
			if (i < 0)
			{
				return i;
			}
			break;

		case')':
			return i;//если найдена скобка, возвращаем i+1
			break;
		case']'://
			return i;
			break;
		case'}':
			return i;
			break;
		}
	}
	return 0;
}

int findround(string a, int b)//поиск закрытых круглых скобок
{
	int i = Check(a, b);//возвращает позицию закрытой скобки
	if (i<0)
	{
		return i;
	}
	if (a[i] == ')')
	{
		return i;
	}
	if (a[i] == ']')
	{
		return 0;
	}
	if (a[i] == '}')
	{
		return 0;
	}
	return i;//не забыть убрать
}

unsigned int findsquare(string a, unsigned int b)//поиск закрытых квадратных скобок
{
	int i = b;
	return i;//не забыть убрать
}

unsigned int findbraces(string a, unsigned int b)//поиск закрытых фигурных скобок
{
	int i = b;
	return i;//не забыть убрать
}