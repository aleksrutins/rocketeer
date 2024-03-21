#include <vector>
#include <memory>
#include <raylib-cpp.hpp>
#include <Rocketeer/Util/IGameObject.hpp>
#include <Rocketeer/Objects/Player.hpp>

using namespace std;
using namespace Rocketeer;

int main() {
    int screenWidth = 800;
    int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight, "raylib-cpp - basic window");
    
    auto player = new Objects::Player;

    raylib::Vector2 playerInit = { (float)(screenWidth/2 - player->GetWidth()), (float)(screenHeight/2 - player->GetHeight()) };

    player->SetPosition(playerInit);

    vector<Util::IGameObject*> gameObjects {
        player
    };

    SetTargetFPS(120);

    while (!window.ShouldClose())
    {
        BeginDrawing();

        window.ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190 - player->GetPosition().GetX(), 200 - player->GetPosition().GetY(), 20, LIGHTGRAY);

        for(auto obj = gameObjects.begin(); obj < gameObjects.end(); obj++) {
            (*obj)->HandleInput();
        }

        for(auto obj = gameObjects.begin(); obj < gameObjects.end(); obj++) {
            (*obj)->Update();
        }

        for(auto obj = gameObjects.begin(); obj < gameObjects.end(); obj++) {
            (*obj)->Draw(player->GetPosition() - playerInit);
        }

        EndDrawing();
    }

    for(auto obj = gameObjects.begin(); obj < gameObjects.end(); obj++) {
        delete *obj;
    }

    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}