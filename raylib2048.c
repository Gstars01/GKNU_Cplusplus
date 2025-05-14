#include "raylib.h"
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define TILE_SIZE 100
#define TILE_PADDING 10

int board[SIZE][SIZE] = { 0 };

void AddRandomTile() {
    int empty[SIZE * SIZE][2];
    int emptyCount = 0;

    for (int y = 0; y < SIZE; y++)
        for (int x = 0; x < SIZE; x++)
            if (board[y][x] == 0) {
                empty[emptyCount][0] = y;
                empty[emptyCount][1] = x;
                emptyCount++;
            }

    if (emptyCount > 0) {
        int index = rand() % emptyCount;
        int y = empty[index][0];
        int x = empty[index][1];
        board[y][x] = (rand() % 10 == 0) ? 4 : 2;
    }
}

bool SlideAndMergeRow(int* row) {
    bool moved = false;
    int temp[SIZE] = { 0 };
    int idx = 0;

    for (int i = 0; i < SIZE; i++) {
        if (row[i] != 0) {
            if (temp[idx] == 0) {
                temp[idx] = row[i];
            }
            else if (temp[idx] == row[i]) {
                temp[idx++] *= 2;
                moved = true;
            }
            else {
                temp[++idx] = row[i];
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        if (row[i] != temp[i]) {
            moved = true;
            row[i] = temp[i];
        }
    }

    return moved;
}

bool Move(int direction) {
    bool moved = false;

    for (int i = 0; i < SIZE; i++) {
        int row[SIZE];
        for (int j = 0; j < SIZE; j++) {
            if (direction == 0) row[j] = board[i][j];          // Left
            else if (direction == 1) row[j] = board[j][i];     // Up
            else if (direction == 2) row[j] = board[i][SIZE - 1 - j]; // Right
            else row[j] = board[SIZE - 1 - j][i];              // Down
        }

        bool rowMoved = SlideAndMergeRow(row);
        moved |= rowMoved;

        for (int j = 0; j < SIZE; j++) {
            if (direction == 0) board[i][j] = row[j];
            else if (direction == 1) board[j][i] = row[j];
            else if (direction == 2) board[i][SIZE - 1 - j] = row[j];
            else board[SIZE - 1 - j][i] = row[j];
        }
    }

    return moved;
}

void DrawBoard() {
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            int value = board[y][x];
            Rectangle tile = {
                x * (TILE_SIZE + TILE_PADDING) + TILE_PADDING,
                y * (TILE_SIZE + TILE_PADDING) + TILE_PADDING,
                TILE_SIZE,
                TILE_SIZE
            };

            // 기본 색상 (빈칸)
            Color tileColor = (Color){ 202, 192, 180 ,255 };

            // 값에 따라 색상 지정
            switch (value) {
            case 2:  tileColor = (Color){ 236, 229, 219, 255 }; break; // 회색
            case 4:  tileColor = (Color){ 235, 224, 202, 255 }; break; // 살구색
            case 8:  tileColor = (Color){ 232, 180, 130, 255 }; break; // 연주황
            case 16: tileColor = (Color){ 232, 154, 108, 255 }; break;   // 주황
            case 32: tileColor = (Color){ 230, 131, 102, 255 }; break;  // 자홍색
            case 64: tileColor = (Color){ 229, 106, 072, 255 }; break;
            default: if (value) tileColor = (Color){ 234, 209, 127, 255 }; break;           // 기타 숫자
            }

            DrawRectangleRec(tile, tileColor);
            if (value<7 && value>0) {
                DrawText(TextFormat("%d", value),
                    tile.x + TILE_SIZE / 2.5,
                    tile.y + TILE_SIZE / 2.8,
                    35,
                    (Color) {
                    117, 110, 100, 255
                });
            }
            else if (value>=128) {
                DrawText(TextFormat("%d", value),
                    tile.x + TILE_SIZE / 3.8,
                    tile.y + TILE_SIZE / 2.8,
                    35,
                    RAYWHITE);
            }
            else if (value >= 1024) {
                DrawText(TextFormat("%d", value),
                    tile.x + TILE_SIZE / 6,
                    tile.y + TILE_SIZE / 2.8,
                    35,
                    RAYWHITE);
            }
            else if (value) {
                DrawText(TextFormat("%d", value),
                    tile.x + TILE_SIZE / 2.5,
                    tile.y + TILE_SIZE / 2.8,
                    35,
                    RAYWHITE);
            }
        }
    }
}

int main() {
    InitWindow(500, 500, "2048 - raylib");
    SetTargetFPS(60);
    srand(time(NULL));

    AddRandomTile();
    AddRandomTile();

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_LEFT)) {
            if (Move(0)) AddRandomTile();
        }
        if (IsKeyPressed(KEY_UP)) {
            if (Move(1)) AddRandomTile();
        }
        if (IsKeyPressed(KEY_RIGHT)) {
            if (Move(2)) AddRandomTile();
        }
        if (IsKeyPressed(KEY_DOWN)) {
            if (Move(3)) AddRandomTile();
        }

        BeginDrawing();
        ClearBackground((Color) { 182, 174, 163, 255 });
        DrawBoard();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
