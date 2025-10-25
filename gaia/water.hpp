#pragma once

#include <VoxelooGeometry/geometry.hpp>
#include "gaia/terrain.hpp"

namespace voxeloo::gaia {

WorldMap<uint8_t> update_water(const TerrainMapV2& map, Vec3i chunk_pos);

}  // namespace voxeloo::gaia