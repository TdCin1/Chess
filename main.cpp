#include "ChessWindow/Window.h"
#include "Pieces/Pieces.h"
using namespace std;

int main() {
    Window window;
    window.setupSprites();
    window();
    return 0;
}
