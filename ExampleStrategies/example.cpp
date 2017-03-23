// strategy_cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <fstream>

using namespace std;

int main()
{
	// Номер хода
	int turnNum;
	// Расположение фишек на доске(двумерный массив)
	int board[10][10];

	// Чтение входныех данных
	ifstream input("input.txt");

	// Номер хода
	input >> turnNum;

	// Состояние доски
	for (int row = 0; row < 10; row++)
		for (int column = 0; column < 10; column++)
			input >> board[row][column];

	input.close();

	// Пример простой стратегии

	// Перебираем все клетки доски
	for (int row = 0; row < 10; row++)
		for (int column = 0; column < 10; column++)
			if (board[row][column] == 1)	// Если в клетке наша фишка
				if (column + 1 < 10 & board[row][column + 1] == 0)	// Если клетка справа не выходит за пределы доски и в ней пусто
				{
					ofstream output("output.txt");	// Записываем ход в выходной файл
					output
						<< column << ' '		// Индекс столбца откуда ходим
						<< row << ' '			// Индекс строки откуда ходим
						<< column + 1 << ' '	// Индекс столбца куда ходим
						<< row;					// Индекс строки куда ходим
					output.close();
					return 0;			// Завершаем программу
				}
				else if (row + 1 < 10 && board[row + 1][column] == 0)	// Если клетка снизу не выходит за пределы доски и в ней пусто
				{
					ofstream output("output.txt");
					output
						<< column << ' '
						<< row << ' '
						<< column << ' '
						<< row + 1;
					output.close();
					return 0;
				}

				// Продолжаем перебор
}

