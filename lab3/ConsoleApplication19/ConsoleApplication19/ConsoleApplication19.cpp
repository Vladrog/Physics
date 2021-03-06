#include "stdafx.h"
#include <iostream>
#include "conio.h"
#include <clocale>
#include <fstream>
using namespace std;


int main()
{
	int squaresAmount, dots = 0, k = 0, curDots = 0, sum = 0;
	setlocale(LC_ALL, "rus");
	ifstream Input;
	ofstream Output;
	Input.open("Input.txt");
	Input >> squaresAmount;
	int* squares = new int[squaresAmount];
	for (int i = 0; i < squaresAmount; i++)
	{
		Input >> squares[i];
	}
	int* squareDots = new int[squaresAmount];
	for (int i = 0; i < squaresAmount; i++)
	{
		squareDots[i] = squares[i] * 4 - 4;
		dots += squareDots[i];
	}
	double* potentials = new double[dots];
	double* answers = new double[dots];
	for (int i = 0; i < dots; i++)
	{
		Input >> potentials[i];
	}
	Input.close();
	Output.open("Output.txt");
	Output << "Лабы и курсачи по программированию и информатике : 89679687572 - whatsApp (Влад Р.)" << endl;
	while (k < squaresAmount)
	{
		Output << endl;
		Output << "Квадрат №" << k + 1 << endl;
		Output << "Точек: " << squareDots[k];
		Output << endl;
		for (int i = curDots; i < squareDots[k]+curDots-1; i++)
		{
			answers[i] = (potentials[i] - potentials[i + 1]) / 0.005;
			Output << "a" << i + 1 - curDots << " = " << answers[i] << endl;
		}
		answers[squareDots[k] +curDots-1] = (potentials[squareDots[k]+curDots-1] - potentials[curDots]) / 0.005;
		Output << "a" << squareDots[k] << " = " << answers[squareDots[k] + curDots - 1] << endl;
		curDots += squareDots[k];
		k++;
	}
	Output << endl;
	Output << "Лабы и курсачи по программированию и информатике : 89679687572 - whatsApp (Влад Р.)" << endl;
	Output.close();
    return 0;
}

