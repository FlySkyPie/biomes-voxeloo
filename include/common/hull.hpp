#pragma once

#include <algorithm>
#include <cstdint>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <vector>

#include <VoxelooGeometry/geometry.hpp>

namespace voxeloo::hull {

std::vector<size_t> jarvis(const std::vector<Vec2d>& points);
std::vector<size_t> graham(const std::vector<Vec2d>& points);

}  // namespace voxeloo::hull
