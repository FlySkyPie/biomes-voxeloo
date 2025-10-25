#include <emscripten/bind.h>

#include "js_ext/anima.hpp"
#include "js_ext/biomes.hpp"
#include "js_ext/buffers.hpp"
#include "js_ext/common.hpp"
#include "js_ext/culling.hpp"
#include "js_ext/gaia.hpp"
#include "js_ext/galois.hpp"
#include "js_ext/mapping.hpp"
#include "js_ext/march.hpp"
#include "js_ext/shards.hpp"
#include "js_ext/tensors.hpp"
#include "js_ext/voxels.hpp"

EMSCRIPTEN_BINDINGS(voxeloo_module) {
  voxeloo::js::bind();
  voxeloo::anima::js::bind();
  voxeloo::biomes::js::bind();
  voxeloo::buffers::js::bind();
  voxeloo::culling::js::bind();
  voxeloo::gaia::js::bind();
  voxeloo::galois::js::bind();
  voxeloo::mapping::js::bind();
  voxeloo::march::js::bind();
  voxeloo::shards::js::bind();
  voxeloo::tensors::js::bind();
  voxeloo::voxels::js::bind();
}
