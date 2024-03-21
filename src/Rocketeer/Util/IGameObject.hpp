#pragma once
#include <raylib-cpp.hpp>

namespace Rocketeer::Util {
    class IGameObject {
    public:
        virtual ~IGameObject() {}
        virtual void HandleInput() = 0;
        virtual void Update() = 0;
        virtual void Draw(raylib::Vector2 cameraOffset) = 0;

        virtual auto GetWidth() const -> int;
        virtual auto GetHeight() const -> int;
    };
}