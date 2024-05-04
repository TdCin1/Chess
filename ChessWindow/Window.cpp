#include "Window.h"

//CONSTRUCTOR
Window::Window() {

}

void Window::loadTextures() {
    getTexture("../PNGs/Board1.png","board");
    sf::Texture& bishop = textureMap["bishop"];
    bishop.loadFromFile("../PNGs/Figures1.png",sf::IntRect(0, 0, 12.5, 18.5));
    sf::Texture& knight = textureMap["knight"];
    knight.loadFromFile("../PNGs/Figures1.png",sf::IntRect(12.5, 0, 12.5, 18.5));
    sf::Texture& rook = textureMap["rook"];
    //WRONG ORDER
    rook.loadFromFile("../PNGs/Figures1.png",sf::IntRect(25, 0, 12.5, 18.5));
    sf::Texture& king = textureMap["king"];
    king.loadFromFile("../PNGs/Figures1.png",sf::IntRect(37.5, 0, 12.5, 18.5));
    sf::Texture& queen = textureMap["queen"];
    queen.loadFromFile("../PNGs/Figures1.png",sf::IntRect(50, 0, 12.5, 18.5));


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

void Window::place(piece& pe, char a, int y) {
    int x = (unsigned int)a -97;
    y--;
    y = 7-y;
    int xcord = 53.5 + 85*x;
    int ycord = 53.5 + 85*y;
    pe.sprite->setPosition(xcord,ycord);
}



//MAIN LOOP
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
        displayWindow->clear(sf::Color::Blue);
        displayWindow->draw(*pieceMap["board"].sprite);
        displayWindow->draw(*pieceMap["BishopLight"].sprite);
        displayWindow->draw(*pieceMap["BishopDark"].sprite);
        displayWindow->draw(*pieceMap["knightLeft"].sprite);
        displayWindow->draw(*pieceMap["knightRight"].sprite);
        displayWindow->display();
    }
}


void Window::setupSprites() {
    loadTextures();

    //BOARD
    piece& board = pieceMap["board"];
    board.sprite = new sf::Sprite;
    loadSprite(board, "board",4);
    board.sprite->setPosition(348,348);

    //edges about 9 or 10 pixels
    //board is 696,696 and each tile middle is 43.5
    //BASE is 53.5 53.5 add 85

    //BishopLight
    piece& BishopLight = pieceMap["BishopLight"];
    BishopLight.sprite = new sf::Sprite;
    loadSprite(BishopLight, "bishop",4);
    place(BishopLight,'c',1);

    //BishopDark
    piece& BishopDark = pieceMap["BishopDark"];
    BishopDark.sprite = new sf::Sprite;
    loadSprite(BishopDark, "bishop",4);
    place(BishopDark,'f',1);

    //KNIGHT LEFT
    piece& knightLeft = pieceMap["knightLeft"];
    knightLeft.sprite = new sf::Sprite;
    loadSprite(knightLeft, "knight",4);
    place(knightLeft,'b',1);

    //KNIGHT RIGHT
    piece& knightRight = pieceMap["knightRight"];
    knightRight.sprite = new sf::Sprite;
    loadSprite(knightRight, "knight",4);
    place(knightRight,'g',1);

}