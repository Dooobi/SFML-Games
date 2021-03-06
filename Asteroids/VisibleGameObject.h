#ifndef VISIBLEGAMEOBJECT_H
#define VISIBLEGAMEOBJECT_H

class VisibleGameObject {
public:
	VisibleGameObject();
	virtual ~VisibleGameObject();

	virtual void load(std::string filename);
	virtual void draw(sf::RenderWindow& window);
	virtual void update(float elapsedTime);

	virtual void setPosition(float x, float y);
	virtual void setRotation(float angle);
	virtual sf::Vector2f getPosition() const;
	virtual void setSize(int width, int height);
	virtual void setScale(float widthScale, float heightScale);
	virtual bool isLoaded() const;
	bool isDestroying() const;
	void setDestroying(bool destroying);

	sf::Sprite& getSprite();

private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	std::string _filename;
	bool _isLoaded;
	bool _destroying;
};

#endif