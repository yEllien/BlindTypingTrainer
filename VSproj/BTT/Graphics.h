#pragma once
#include "Text.h"
#include <SFML/Graphics.hpp>

class Graphics
{
public:
	Graphics(Text t);
	int loop();

private:
	Text text;
	bool first;
	sf::Font f;
	sf::Text sftxt;
	sf::RenderWindow win;
	sf::Text mistake;
	sf::Text time;
};

