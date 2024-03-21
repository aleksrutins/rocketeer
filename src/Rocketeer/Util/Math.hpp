#pragma once
#include <raylib-cpp.hpp>

namespace Rocketeer::Util::Math {
	auto Lerp(float v0, float v1, float t) -> float;
	auto Lerp(raylib::Vector2 v0, raylib::Vector2 v1, float t) -> raylib::Vector2;
}