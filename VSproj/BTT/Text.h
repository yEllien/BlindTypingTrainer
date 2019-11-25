#pragma once

#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Text
{
	public:
		Text();
		void loadText(string file_name);
		int check(char input);
		void startTimer();
		float wordsPerSecond();
		string getText();
	private:
		string text;
		int wordcount;
		time_t time;
};