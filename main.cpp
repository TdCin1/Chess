#include "ChessWindow/Window.h"
#include "Pieces/Pieces.h"
using namespace std;

int main() {
    Window window;
    window.setupSprites();
    //window.place(window.pieceMap["BishopLight"],'e',4);
    window();
    return 0;
}
