#include "Player.hpp"

#define PLAYER_ACCEL 0.05

using namespace Rocketeer::Objects;

void Player::HandleInput()
{
    if(IsKeyDown(KEY_W)) {
        acceleration.y = -PLAYER_ACCEL;
    } else if(IsKeyDown(KEY_S)) {
        acceleration.y = PLAYER_ACCEL;
    } else {
        acceleration.y = 0;
    }

    if(IsKeyDown(KEY_D)) {
        acceleration.x = PLAYER_ACCEL;
    } else if(IsKeyDown(KEY_A)) {
        acceleration.x = -PLAYER_ACCEL;
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