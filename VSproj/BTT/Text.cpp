#include "Text.h"
#include <iostream>

Text::Text(): wordcount(0), start_time(0), errors(0) {
}

void Text::loadText(string file_name) {

	ifstream file(file_name);
	stringstream buffer;
	buffer << file.rdbuf();
	text = buffer.str();
}

/*
	0  -> No match
	1  -> Match
	-1 -> End of Text
*/
int Text::check(char ch) {

	if (ch == text[0]) {

		
		if (text[0] == ' ') wordcount++;
		text.erase(0, 1);
		if (text[0] == '\n') text.erase(0,1);
		if (text[0] == '\0') return -1;
		return 1;
	}
	else {
		errors++;
		return 0;
	}
}

void Text::startTimer()
{
	start_time = std::clock();
}

float Text::wordsPerSecond()
{
	return (float) (wordcount / (float((std::clock() - start_time)) / CLOCKS_PER_SEC))*60;
}

string Text::getText() {

	return text;
}