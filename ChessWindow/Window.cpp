#include "Window.h"

//CONSTRUCTOR
Window::Window() {

}

void Window::loadTextures() {
    getTexture("../PNGs/Board1.png","board");
    sf::Texture& bishop = textureMap["bishop"];
    bishop.loadFromFile("../PNGs/Figures1.png",sf::IntRect(0, 0, 12.5, 18.5));

}

void Window::setupSprites() {
    loadTextures();

    //BOARD
    piece& board = pieceMap["board"];
    board.sprite = new sf::Sprite;
    loadSprite(board, "board",4);
    board.sprite->setPosition(348,348);

    //Bishop
    piece& bishopWhite = pieceMap["bishopWhite"];
    bishopWhite.sprite = new sf::Sprite;
    loadSprite(bishopWhite, "bishop",4);
    bishopWhite.sprite->setPosition(104,104);
}

void Window::loadSprite(piece& pe, string texture, float scale) {
    pe.sprite->setTexture(textureMap[texture]);
    pe.sprite->scale(scale,scale);
    sf::FloatRect Rect = pe.sprite->getLocalBounds();
    pe.sprite->setOrigin(Rect.left + Rect.width/2.0f, Rect.top + Rect.height/2.0f);
}



sf::Texture& Window::getTexture(const string& filename, const string& key) {
    sf::Texture& texture = textureMap[key];
    if(!texture.loadFromFile(filename)) {
        cout<<"error";
        throw 505;
    }
    return texture;
}

void Window::operator()() {
    displayWindow = new sf::RenderWindow(sf::VideoMode(696,696), "Welcome Window");
    while (displayWindow->isOpen())
    {
        // check all the window event since last event
        sf::Event event;
        while (displayWindow->pollEvent(event)){
            // closes window
            if (event.type == sf::Event::Closed){
                displayWindow->close();
                return;

            }
            else if(event.key.code == sf::Keyboard::Enter){

            }
            else if(event.type == sf::Event::TextEntered){

            }
        }
        displayWindow->clear(sf::Color::White);
        displayWindow->draw(*pieceMap["board"].sprite);
        displayWindow->draw(*pieceMap["bishopWhite"].sprite);
        displayWindow->display();
    }
}


