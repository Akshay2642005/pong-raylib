#include "raylib.h"
#include <iostream>

using namespace std;

Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};

int player_score = 0;
int cpu_score = 0;

// class Ball
class Ball {
public:
  float x, y;
  int speed_x, speed_y;
  int radius;

  void Draw() { DrawCircle(x, y, radius, Yellow); };

  void Update() {
    x += speed_x;
    y += speed_y;

    if (y + radius >= GetScreenHeight() || y - radius <= 0) {
      speed_y *= -1;
    }
    // Cpu wins
    if (x + radius >= GetScreenWidth()) {
      cpu_score++;
      Reset();
    }
    // player wins
    if (x - radius <= 0) {
      player_score++;
      Reset();
    }
  };

  void Reset() {
    x = GetScreenWidth() / 2.0;
    y = GetScreenHeight() / 2.0;

    int speed_directions[2] = {-1, 1};
    speed_x *= speed_directions[GetRandomValue(0, 1)];
    speed_y *= speed_directions[GetRandomValue(0, 1)];
  };
};

// class Paddle

class Paddle {
protected:
  void MoveLimits() {
    if (y <= 0) {
      y = 0;
    }
    if (y + height >= GetScreenHeight()) {
      y = GetScreenHeight() - height;
    }
  };

public:
  float x, y;
  float width, height;
  int speed;

  void Draw() {
    DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);
  };

  void Update() {
    if (IsKeyDown(KEY_UP)) {
      y = y - speed;
    }
    if (IsKeyDown(KEY_DOWN)) {
      y = y + speed;
    }

    MoveLimits();
  };
};

class CpuPaddle : public Paddle {
public:
  void Update(int ball_y) {
    if (y + height / 2 > ball_y) {
      y = y - speed;
    }
    if (y + height / 2 <= ball_y) {
      y = y + speed;
    }
    MoveLimits();
  };
};

// Game Objs
Ball ball;
Paddle player;
CpuPaddle cpu;

int main() {
  cout << "Starting Game!" << endl;

  const int windowWidth = 1280;
  const int windowHeight = 800;

  InitWindow(windowWidth, windowHeight, "My pong Game!");
  SetTargetFPS(90);

  // ball params
  ball.radius = 20;
  ball.x = windowWidth / 2.0;
  ball.y = windowHeight / 2.0;
  ball.speed_x = 7;
  ball.speed_y = 7;

  // player params

  player.width = 25;
  player.height = 120;
  player.x = windowWidth - player.width - 10;
  player.y = windowHeight / 2.0 - player.height / 2.0;
  player.speed = 6;

  // cpu params

  cpu.width = 25;
  cpu.height = 120;
  cpu.x = 10;
  cpu.y = windowHeight / 2.0 - cpu.height / 2.0;
  cpu.speed = 6;

  while (!WindowShouldClose()) {
    BeginDrawing();

    // Updating
    ball.Update();
    player.Update();
    cpu.Update(ball.y);

    // Collision Checking

    if (CheckCollisionCircleRec(
            Vector2{ball.x, ball.y}, ball.radius,
            Rectangle{player.x, player.y, player.width, player.height})) {
      ball.speed_x *= -1;
    }
    if (CheckCollisionCircleRec(
            Vector2{ball.x, ball.y}, ball.radius,
            Rectangle{cpu.x, cpu.y, cpu.width, cpu.height})) {
      ball.speed_x *= -1;
    }
    // Drawing
    ClearBackground(Dark_Green);
    DrawRectangle(windowWidth / 2, 0, windowHeight / 2, windowHeight, Green);
    DrawCircle(windowWidth / 2, windowHeight / 2, 150, Light_Green);
    DrawLine(windowWidth / 2, 0, windowWidth / 2, windowHeight, WHITE);
    ball.Draw();
    cpu.Draw();
    player.Draw();
    DrawText(TextFormat("%i", cpu_score), windowWidth / 4 - 20, 20, 80, WHITE);
    DrawText(TextFormat("%i", player_score), 3 * windowWidth / 4 - 20, 20, 80,
             WHITE);

    EndDrawing();
  }
  CloseWindow();
  return 0;
}
