#include <vector>
#include <memory>
#include <raylib-cpp.hpp>
#include <Rocketeer/Util/IGameObject.hpp>
#include <Rocketeer/Util/Math.hpp>
#include <Rocketeer/Objects/Player.hpp>

using namespace std;
using namespace Rocketeer;

int main() {
    int screenWidth = 800;
    int screenHeight = 450;

    raylib::Window window(screenWidth, screenHeight, "raylib-cpp - basic window");
    
    auto player = new Objects::Player;

    raylib::Vector2 playerInit = { (float)(screenWidth/2 - player->GetWidth()), (float)(screenHeight/2 - player->GetHeight()) };

    raylib::Vector2 cameraPos = { 0, 0 };

    player->SetPosition(playerInit);

    vector<Util::IGameObject*> gameObjects {
        player
    };

    SetTargetFPS(165);

    while (!window.ShouldClose())
    {
        BeginDrawing();

        window.ClearBackground(BLACK);

        DrawText("Congrats! You created your first window!", 190 - player->GetPosition().GetX(), 200 - player->GetPosition().GetY(), 20, WHITE);
        DrawFPS(screenWidth - 100, 20);

        for(auto obj = gameObjects.begin(); obj < gameObjects.end(); obj++) {
            (*obj)->HandleInput();
        }

        for(auto obj = gameObjects.begin(); obj < gameObjects.end(); obj++) {
            (*obj)->Update();
        }

        for(auto obj = gameObjects.begin(); obj < gameObjects.end(); obj++) {
            (*obj)->Draw(cameraPos);
        }

        cameraPos = Util::Math::Lerp(cameraPos, player->GetPosition() - playerInit, 0.05);

        EndDrawing();
    }

    for(auto obj = gameObjects.begin(); obj < gameObjects.end(); obj++) {
        delete *obj;
    }

    // UnloadTexture() and CloseWindow() are called automatically.

    return 0;
}