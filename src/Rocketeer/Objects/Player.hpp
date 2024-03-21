#pragma once
#include <raylib-cpp.hpp>
#include <Rocketeer/Util/IGameObject.hpp>

namespace Rocketeer::Objects {
    class Player : public Rocketeer::Util::IGameObject {
        raylib::Vector2 position { 0, 0 };
        raylib::Vector2 velocity { 0, 0 };
        raylib::Vector2 acceleration { 0, 0 };

    public:

        GETTERSETTER(raylib::Vector2, Position, position);

        void HandleInput();
        void Update();
        void Draw(raylib::Vector2 cameraOffset);

        auto GetWidth() const -> int;
        auto GetHeight() const -> int;
    };
}