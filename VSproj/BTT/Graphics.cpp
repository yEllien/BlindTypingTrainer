#include "Graphics.h"
#include <iostream>
#include <string>
#include <iomanip>

Graphics::Graphics(Text t) : text(t) , first(false)
{
	sftxt.setString(text.getText());
	std::cout << f.loadFromFile("calibri.ttf");
	

	// mistake setup
	mistake.setFont(f);
	mistake.setPosition(0, 0);
	mistake.setFillColor(sf::Color::Red);
	mistake.setCharacterSize(14);
	
	// sftxt setup
	sftxt.setFont(f);
	sftxt.setPosition(0, 0);
	sftxt.setFillColor(sf::Color::White);
	sftxt.setCharacterSize(14);

	string str;
	getline(stringstream(text.getText()), str);

	// time setup
	time.setFont(f);
	time.setPosition(sftxt.getCharacterSize() * str.size()  / 2, 550);
	time.setFillColor(sf::Color::Green);
	time.setCharacterSize(30);

	win.create(sf::VideoMode(sftxt.getCharacterSize() * str.size(), 600), "BTT");


}

int Graphics::loop()
{
	sf::Event e;
	win.pollEvent(e);

	//Handle Events 
	if (e.type == sf::Event::Closed) { 
		win.close(); 
		return 0;
	
	}
	

	sftxt.setString(text.getText());
	win.clear();

	


	
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(3) << "current speed : " << text.wordsPerSecond() << " overall speed : " << std::fixed << std::setprecision(3)  << text.wordsPerSecondAvg();
	std::string s(ss.str());
	time.setString(ss.str());
	
	if (text.check(e.key.code))
	{
		if (!first) { text.startTimer(); first = true; }
		mistake.setString(' ');
			
	}else if (e.type == sf::Event::KeyPressed) mistake.setString(sftxt.getString()[0]);

	
	win.draw(sftxt);
	win.draw(mistake);
	win.draw(time);
	win.display();

	return 1;
}
