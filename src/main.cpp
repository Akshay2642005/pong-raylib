#include <raylib.h>

int main() {
    InitWindow(600, 400, "My Game");
    SetExitKey(KEY_Q);

    while (!WindowShouldClose()) {
        BeginDrawing();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}