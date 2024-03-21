#include "Player.hpp"

using namespace Rocketeer::Objects;

void Player::HandleInput()
{
    if(IsKeyDown(KEY_W)) {
        acceleration.y = -0.01;
    } else if(IsKeyDown(KEY_S)) {
        acceleration.y = 0.01;
    } else {
        acceleration.y = 0;
    }

    if(IsKeyDown(KEY_D)) {
        acceleration.x = 0.01;
    } else if(IsKeyDown(KEY_A)) {
        acceleration.x = -0.01;
    } else {
        acceleration.x = 0;
    }
}

void Player::Update()
{
    velocity += acceleration;
    position += velocity;
}

void Player::Draw(raylib::Vector2 cameraOffset)
{
    auto screenPos = position - cameraOffset;
    DrawCircle(screenPos.x, screenPos.y, 12, BLUE);
}

int Player::GetWidth() const
{
    return 24;
}

int Player::GetHeight() const
{
    return 24;
}