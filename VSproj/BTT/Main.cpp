#include <iostream>
#include "Text.h"
#include "stdio.h"
#include "conio.h"
#include <iomanip>
#include <chrono>
#include "Graphics.h"

using namespace std;

int main() 
{
	Text txt;
	txt.loadText("test.txt");
	Graphics window(txt);

	while (window.loop());

	return 0;
}