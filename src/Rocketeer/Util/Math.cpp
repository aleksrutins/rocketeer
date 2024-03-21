#include "Math.hpp"

namespace Rocketeer::Util::Math {
	float Lerp(float v0, float v1, float t)
	{
		return v0 + t * (v1 - v0);
	}
	auto Lerp(raylib::Vector2 v0, raylib::Vector2 v1, float t) -> raylib::Vector2
	{
		return { Lerp(v0.x, v1.x, t), Lerp(v0.y, v1.y, t) };
	}
}
