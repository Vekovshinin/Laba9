#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream f1; // Для чтения
	ofstream f2; // Для записи

	f1.open("F1.txt");
	f2.open("F2.txt");

	// Задача: Посчитать количество строк в файле и записать их в массив
	string s; // Переменная для строки
	string line[100];
	int lineCount = 0;
	while (getline(f1, s)) // пока строки в файле есть 
	{
		line[lineCount] = s;
		lineCount++; // Считаем количество строк в файле
	}
	for (int i = 0; i < lineCount; i++) {
		cout << line[i] << endl;
	}
	cout << endl;
	// Задача: Записать все слова из файла в массив
	// Задача: Проверить, есть ли в строке два одинаковых слова

	//string line[] = { "cat love my cat", "i like pasta" }; // представим, что это строки файла

	string allwords[100]; // Массив для всех слов
	int k = 0; // Счетчик для allwords
	for (int x = 0; x < lineCount; x++) // x - номер слова в строке
	{
		string words[100]; // Массив для слов каждой строки
		int count = 0; // Счетчик для массива word

		for (int i = 0; i <= line[x].length(); i++) // идем до конца строки 
		{
			if (line[x][i] == ' ' || line[x][i] == '\0')
			{
				count += 1;
				k += 1;
			}
			else
			{
				words[count] += line[x][i];
				allwords[k] += line[x][i];
			}
		}

		count += 1;
		k += 1;

		// Задача: Определить, повторяются ли элементы массива

		for (int i = 0; i < count; i++)
		{
			bool flag = false;
			for (int j = i + 1; j < count; j++)
			{
				if (words[i] == words[j]) flag = true;
			}
			if (flag == true)
			{
				f2 << line[x] << endl;
				break;
			}
		}
	}
	// Задача: Найти номер слова с наибольшим количеством цифр
	int max = 0;
	int wordIndex = 0;
	for (int i = 0; i < k; i++)
	{
		int number = 0;
		for (int j = 0; j < allwords[i].length(); j++)
		{
			if (allwords[i][j] >= '0' && allwords[i][j] <= '9')
				number += 1;
		}
		if (number > max)
		{
			max = number;
			wordIndex = i;
		}
	}
	cout << "Номер слова с наибольшим количеством цифр: " << wordIndex;
	f1.close();
	f2.close();
}
