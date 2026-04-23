#include <array>
#include <iostream>
#include <raylib.h>
#define BoardSize 64

#define EMPTY 0

#define WHITEPAWN 1
#define BLACKPAWN -1

#define WHITEKNIGHT 2
#define BLACKKNIGHT -2

#define WHITEBISHOP 3
#define BLACKBISHOP -3

#define WHITEROOK 4
#define BLACKROOK -4

#define WHITEQUEEN 5
#define BLACKQUEEN -5

#define WHITEKING 6
#define BLACKKING -6

class Board {
public:
  int height = 0;
  int width = 0;
  std::array<int, 64> board;

  Board(int hght, int wdth, std::array<int, 64> bord)
      : height(hght), width(wdth), board(bord) {}
  std::array<Texture2D, 13> textures;

  void LoadTextures() {
    textures[WHITEPAWN + 6] =
        LoadTexture("/home/tahmid/ChessEngine/frontend/data/pawn-w.png");

    textures[BLACKPAWN + 6] =
        LoadTexture("/home/tahmid/ChessEngine/frontend/data/pawn-b.png");

    textures[WHITEKNIGHT + 6] =
        LoadTexture("/home/tahmid/ChessEngine/frontend/data/knight-w.png");
    textures[BLACKKNIGHT + 6] =
        LoadTexture("/home/tahmid/ChessEngine/frontend/data/knight-b.png");

    textures[WHITEBISHOP + 6] =
        LoadTexture("/home/tahmid/ChessEngine/frontend/data/bishop-w.png");
    textures[BLACKBISHOP + 6] =
        LoadTexture("/home/tahmid/ChessEngine/frontend/data/bishop-b.png");

    textures[WHITEROOK + 6] =
        LoadTexture("/home/tahmid/ChessEngine/frontend/data/rook-w.png");
    textures[BLACKROOK + 6] =
        LoadTexture("/home/tahmid/ChessEngine/frontend/data/rook-b.png");

    textures[WHITEQUEEN + 6] =
        LoadTexture("/home/tahmid/ChessEngine/frontend/data/queen-w.png");
    textures[BLACKQUEEN + 6] =
        LoadTexture("/home/tahmid/ChessEngine/frontend/data/queen-b.png");

    textures[WHITEKING + 6] =
        LoadTexture("/home/tahmid/ChessEngine/frontend/data/king-w.png");
    textures[BLACKKING + 6] =
        LoadTexture("/home/tahmid/ChessEngine/frontend/data/king-b.png");
  }

  void DrawPiece(int piece, int x, int y) {
    if (piece != EMPTY) {
      DrawTexture(textures[piece + 6], x, y, WHITE);
    }
  }

  void UnloadTextures() {
    for (auto &tex : textures) {
      UnloadTexture(tex);
    }
  }

  void DrawBoard() {

    bool clicked = false;
    int store = 0;
    while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);
      int PosX = 0;
      int PosY = 0;
      int sizeX = width / 8;
      int SizeY = height / 8;
      bool color = true;

      int counter = 0;

      bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
      Vector2 mousePos = GetMousePosition();

      for (int i = 0; i < BoardSize; ++i) {
        Color white = {240, 217, 181, 255};
        Color black = {181, 136, 99, 255};

        DrawRectangle(PosX, PosY, sizeX, SizeY, color ? white : black);
        DrawPiece(board[i], PosX, PosY);

        Rectangle rect = {(float)PosX, (float)PosY, (float)sizeX, (float)SizeY};

        if (CheckCollisionPointRec(mousePos, rect)) {
          if (mousePressed && clicked) {
            clicked = !clicked;
            if (board[store] < 0 && board[i] >= 0 ||
                board[store] > 0 && board[i] <= 0) {
              board[i] = board[store];

              board[store] = EMPTY;
            } else {
              std::cout << "SORRY BUT CANIBALISSSM IS NOT ALOWED IN CHESS";
            }

            // board[store] = EMPTY;
            std::cout << "clicked=" << clicked
                      << " mouse=" << IsMouseButtonPressed(MOUSE_BUTTON_LEFT)
                      << " i=" << i << '\n';
          } else if (mousePressed && !clicked) {
            clicked = !clicked;
            store = i;
            std::cout << "clicked=" << clicked
                      << " mouse=" << IsMouseButtonPressed(MOUSE_BUTTON_LEFT)
                      << " i=" << i << '\n';
          }
        }

        PosX += sizeX;
        color = !color;

        if ((i + 1) % 8 == 0) {
          PosX = 0;
          PosY += SizeY;

          color = !color;
        }
      }
      EndDrawing();
    }
  }
};

int main() {
  std::array<int, BoardSize> board = {
      BLACKROOK, BLACKKNIGHT, BLACKBISHOP, BLACKQUEEN,
      BLACKKING, BLACKBISHOP, BLACKKNIGHT, BLACKROOK,

      BLACKPAWN, BLACKPAWN,   BLACKPAWN,   BLACKPAWN,
      BLACKPAWN, BLACKPAWN,   BLACKPAWN,   BLACKPAWN,

      EMPTY,     EMPTY,       EMPTY,       EMPTY,
      EMPTY,     EMPTY,       EMPTY,       EMPTY,

      EMPTY,     EMPTY,       EMPTY,       EMPTY,
      EMPTY,     EMPTY,       EMPTY,       EMPTY,

      EMPTY,     EMPTY,       EMPTY,       EMPTY,
      EMPTY,     EMPTY,       EMPTY,       EMPTY,

      EMPTY,     EMPTY,       EMPTY,       EMPTY,
      EMPTY,     EMPTY,       EMPTY,       EMPTY,

      WHITEPAWN, WHITEPAWN,   WHITEPAWN,   WHITEPAWN,
      WHITEPAWN, WHITEPAWN,   WHITEPAWN,   WHITEPAWN,

      WHITEROOK, WHITEKNIGHT, WHITEBISHOP, WHITEQUEEN,
      WHITEKING, WHITEBISHOP, WHITEKNIGHT, WHITEROOK};
  Board b = Board(1000, 1000, board);
  InitWindow(b.height, b.width, "GigaEngine");
  b.LoadTextures();
  b.DrawBoard();
  b.UnloadTextures();
  CloseWindow();
  return 0;
}
