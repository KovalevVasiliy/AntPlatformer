#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TinyXML/tinyxml.h"

struct ObjectT
{

	int GetPropertyInt(std::string name);
	float GetPropertyFloat(std::string name);
	std::string GetPropertyString(std::string name);
	void hhh(int jj)
	{
		rect.top = jj;
	}
	std::string name;
	std::string type;
	sf::Rect<float> rect;
	std::map<std::string, std::string> properties;

	sf::Sprite sprite;
};

struct Layer
{
	int opacity;
	std::vector<sf::Sprite> tiles;
};

class Level
{
public:
	Level();
	bool LoadFromFile(std::string filename);
	ObjectT* GetObjectT(std::string name);
	std::vector<ObjectT*> GetObjectTs(std::string name);
	std::vector<ObjectT>* GetAllObjectTs();
	void Draw(sf::RenderWindow &window);
	sf::Vector2i GetTileSize();
	void addSprite(sf::Sprite sprite);
	void addObjectT(ObjectT object);
private:
	int width, height, tileWidth, tileHeight;
	int firstTileID;// ���� ������� �����
	sf::Rect<float> drawingBounds;//������ ����� ����� ������� ������
	sf::Texture tilesetImage;//�������� �����
	std::vector<ObjectT> objectTs;
	std::vector<Layer> layers;
	std::vector<sf::Sprite> sprites;
};




#endif
