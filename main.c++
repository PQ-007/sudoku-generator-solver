#include <iostream>
#include <raylib.h>
#include <random>
using namespace std;

int initializeBoard(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int randm = rand() % 10;
            randm!= 0 ? board[i][j] = randm : j--; 
        }
    }
    return 0; 
}

int main() {

    const int screenWidth = 600;
    const int screenHeight = 600;
    const int cellSize = 60;
    const int offset = (screenWidth - (cellSize * 9)) / 2;
    int board[9][9]; 
    initializeBoard(board);

    InitWindow(screenWidth, screenHeight, "Sudoku Generator and Solver");
    SetTargetFPS(60);


    while (!WindowShouldClose()) {
        

        BeginDrawing();
            ClearBackground(RAYWHITE);


            for (int i = 0; i <= 9; i++) {

                float thickness = (i % 3 == 0) ? 3.0f : 1.0f;

                DrawLineEx(
                    (Vector2){ (float)offset + i * cellSize, (float)offset }, 
                    (Vector2){ (float)offset + i * cellSize, (float)offset + 9 * cellSize }, 
                    thickness, BLACK
                );

                DrawLineEx(
                    (Vector2){ (float)offset, (float)offset + i * cellSize }, 
                    (Vector2){ (float)offset + 9 * cellSize, (float)offset + i * cellSize }, 
                    thickness, BLACK
                );
            }

            DrawText("Sudoku Board", offset, 8, 20, DARKGRAY);

            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                  int offs;
                  board[i][j] == 1 ? offs = offset + 10 : offs = offset + 3;
                  DrawText(
                      TextFormat("%d", board[i][j]), 
                      offs + j * cellSize + cellSize / 4, 
                      offset-3 + i * cellSize + cellSize / 4, 
                      40, BLACK
                  );  
                }
            }


        EndDrawing();
    }

    CloseWindow();

    return 0;
}