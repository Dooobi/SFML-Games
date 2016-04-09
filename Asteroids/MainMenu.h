#ifndef MAINMENU_H
#define MAINMENU_H

class MainMenu {
public:
	enum MenuResult { Nothing, Exit, Play };

	struct MenuItem {
		sf::Rect<int> rect;
		MenuResult action;
	};

	MenuResult show(sf::RenderWindow& window);
private:
	MenuResult getMenuResponse(sf::RenderWindow& window);
	MenuResult handleClick(int x, int y);
	std::list<MenuItem> _menuItems;
};

#endif