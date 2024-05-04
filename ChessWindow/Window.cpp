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
    rook.loadFromFile("../PNGs/Figures1.png",sf::IntRect(25, 0, 12.5, 18.5));
    sf::Texture& pawn = textureMap["pawn"];
    pawn.loadFromFile("../PNGs/Figures1.png",sf::IntRect(36, 0, 12.5, 18.5));
    sf::Texture& king = textureMap["king"];
    king.loadFromFile("../PNGs/Figures1.png",sf::IntRect(48.75, 0, 12.5, 18.5));
    sf::Texture& queen = textureMap["queen"];
    queen.loadFromFile("../PNGs/Figures1.png",sf::IntRect(63, 0, 12.5, 18.5));


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
    setupSprites();
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
            else if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(*displayWindow);
                    cout<<mousePosition.x<<" "<<mousePosition.y<<endl;

                }
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
        displayWindow->draw(*pieceMap["queen"].sprite);
        displayWindow->draw(*pieceMap["king"].sprite);
        displayWindow->draw(*pieceMap["rookLeft"].sprite);
        displayWindow->draw(*pieceMap["rookRight"].sprite);
        displayWindow->draw(*pieceMap["pawn1"].sprite);
        displayWindow->draw(*pieceMap["pawn2"].sprite);
        displayWindow->draw(*pieceMap["pawn3"].sprite);
        displayWindow->draw(*pieceMap["pawn4"].sprite);
        displayWindow->draw(*pieceMap["pawn5"].sprite);
        displayWindow->draw(*pieceMap["pawn6"].sprite);
        displayWindow->draw(*pieceMap["pawn7"].sprite);
        displayWindow->draw(*pieceMap["pawn8"].sprite);






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

    //edges about 10 pixels
    //board is 696,696 and each tile middle is 42 total is 84x84

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

    //ROOK LEFT
    piece& rookLeft = pieceMap["rookLeft"];
    rookLeft.sprite = new sf::Sprite;
    loadSprite(rookLeft, "rook",4);
    place(rookLeft,'a',1);

    //ROOK RIGHT
    piece& rookRight = pieceMap["rookRight"];
    rookRight.sprite = new sf::Sprite;
    loadSprite(rookRight, "rook",4);
    place(rookRight,'h',1);


    //QUEEN
    piece& queen = pieceMap["queen"];
    queen.sprite = new sf::Sprite;
    loadSprite(queen, "queen",4);
    place(queen,'d',1);

    //KING
    piece& king = pieceMap["king"];
    king.sprite = new sf::Sprite;
    loadSprite(king, "king",4);
    place(king,'e',1);

    //PAWN 1
    piece& pawn1 = pieceMap["pawn1"];
    pawn1.sprite = new sf::Sprite;
    loadSprite(pawn1, "pawn",4);
    place(pawn1,'a',2);

    //PAWN 2
    piece& pawn2 = pieceMap["pawn2"];
    pawn2.sprite = new sf::Sprite;
    loadSprite(pawn2, "pawn",4);
    place(pawn2,'b',2);

    //PAWN 3
    piece& pawn3 = pieceMap["pawn3"];
    pawn3.sprite = new sf::Sprite;
    loadSprite(pawn3, "pawn",4);
    place(pawn3,'c',2);

    //PAWN 4
    piece& pawn4 = pieceMap["pawn4"];
    pawn4.sprite = new sf::Sprite;
    loadSprite(pawn4, "pawn",4);
    place(pawn4,'d',2);

    //PAWN 5
    piece& pawn5 = pieceMap["pawn5"];
    pawn5.sprite = new sf::Sprite;
    loadSprite(pawn5, "pawn",4);
    place(pawn5,'e',2);

    //PAWN 6
    piece& pawn6 = pieceMap["pawn6"];
    pawn6.sprite = new sf::Sprite;
    loadSprite(pawn6, "pawn",4);
    place(pawn6,'f',2);

    //PAWN 7
    piece& pawn7 = pieceMap["pawn7"];
    pawn7.sprite = new sf::Sprite;
    loadSprite(pawn7, "pawn",4);
    place(pawn7,'g',2);

    //PAWN 8
    piece& pawn8 = pieceMap["pawn8"];
    pawn8.sprite = new sf::Sprite;
    loadSprite(pawn8, "pawn",4);
    place(pawn8,'h',2);
}