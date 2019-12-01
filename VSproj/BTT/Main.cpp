#include <iostream>
#include "Text.h"
#include "stdio.h"
#include "conio.h"
#include <iomanip>
#include <chrono>	
using namespace std;

int main() 
{
	string fn;
	char input;
	Text txt;
	int i = 0;

	cout << "hello ello" << endl;

	cin >> fn;

	txt.loadText(fn);

	cout << txt.getText();
	txt.startTimer();
	while (i != -1) {
		input = _getch();
		i = txt.check(input);
		if (i == 1) system("color 2");
		if (i == 0) system("color 4");
		system("color 7");
		system("cls");

		cout << txt.getText() << "\n " <<"Wpm :" << fixed <<setprecision(4) << txt.wordsPerSecond()<<"		Errors:"<<txt.errors;
	}


	return 0;
}