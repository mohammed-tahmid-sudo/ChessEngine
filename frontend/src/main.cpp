#include <array>
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
    while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);
      int PosX = 0;
      int PosY = 0;
      int sizeX = width / 8;
      int SizeY = height / 8;
      bool color = true;

      int counter = 0;
      for (int i = 0; i < BoardSize; i++) {
        DrawRectangle(PosX, PosY, sizeX, SizeY, color ? WHITE : BLACK);
        DrawPiece(board[i], PosX, PosY);
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
    CloseWindow();
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
  return 0;
}
