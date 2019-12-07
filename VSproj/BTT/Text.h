#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Text
{
	public:
		Text();
		void loadText(string file_name);
		int check(char input);
		void startTimer();
		float wordsPerSecond();
		int errors;
		string getText();
		float wordsPerSecondAvg();
	private:
		string text;
		int wordcount;
		time_t start_time;
		time_t perm_time;
		float avgspeed;
};