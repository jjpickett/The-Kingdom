#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

class AssetManager
{
public:
	AssetManager() {}
	~AssetManager() {}

	void LoadTexture(std::string name, std::string fileName);
	sf::Texture &getTexture(std::string name);

	void LoadFont(std::string name, std::string  fileName);
	sf::Font &getFont(std::string name);

private:
	/// \brief	The textures
	std::map<std::string, sf::Texture> _textures;
	std::map<std::string, sf::Font> _fonts;

};

