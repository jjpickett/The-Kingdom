//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose, Jordan Pickett, Nora White
/// \date Nov 26, 2017
///
///
/// \brief The AssetManager handles loading the textures and fonts from 
/// a file into memory. 
///


#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

// *******************************************************************************
/// The AssetManager handles loading the textures and fonts from 
/// a file into memory. 
// *******************************************************************************

class AssetManager
{
public:

	/// Creates the AssetManager and initializes it.
	AssetManager() {}
	~AssetManager() {}

	/// loads Texture into memory from a specific file
	/// \param[in] name The name of the texture that will be loaded
	/// \param[in] fileName the name of the file for the texture
	void LoadTexture(std::string name, std::string fileName);
	sf::Texture &getTexture(std::string name);

	/// loads font into memory from a specific file
	/// \param[in] name The name of the font that will be loaded
	/// \param[in] fileName the name of the file for the font
	void LoadFont(std::string name, std::string  fileName);
	sf::Font &getFont(std::string name);

private:
	/// \brief	The textures
	std::map<std::string, sf::Texture> _textures;
	std::map<std::string, sf::Font> _fonts;

};

