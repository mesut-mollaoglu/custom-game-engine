#ifndef INCLUDES_H
#define INCLUDES_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdint.h>
#include <type_traits>
#include <cstring>
#include <math.h>
#include <cmath>
#include <unordered_map>
#include <array>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stack>
#include <cassert>
#include <optional>
#include <functional>
#include <chrono>
#include <string_view>
#include <list>

using steady_clock = std::chrono::steady_clock;
using time_point = std::chrono::time_point<steady_clock>;

inline constexpr int32_t materialCount = 4;
inline constexpr std::string_view shaderMaterialArrName = "MATERIAL_COUNT";

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "stb_image.h"
#include "math.h"
#include "buffer.h"
#include "shader.h"
#include "utils.h"
#include "light.h"
#include "texture.h"
#include "material.h"
#include "mesh.h"
#include "window.h"
#include "sprite_batch.h"
#include "geo_batch.h"
#include "text_batch.h"
#include "save.h"
#include "menu.h"
#include "gui.h"
#include "animator.h"
#include "state_machine.h"
#include "common.h"
#endif