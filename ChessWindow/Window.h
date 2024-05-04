#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include<map>
#include <SFML/Graphics.hpp>

using namespace std;

class Window {
public:
    struct piece {
        string name;
        sf::Sprite* sprite;

        int col;
        int row;
    };

    map<string,sf::Texture> textureMap;
    map<string,piece> pieceMap;
    sf::RenderWindow* displayWindow;

    Window();
    void operator()();

    void loadTextures();
    void setupSprites();
    void loadSprite(piece &pe, string texture, float scale);
    void place(piece& pe, char a, int y);
    sf::Texture& getTexture(const string& filename, const string& key);
};



#endif //WINDOW_H
