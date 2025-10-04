#ifndef INCLUDES_HPP
#define INCLUDES_HPP

//standard includes
#include <iostream>
#include <stdint.h>
#include <string>
#include <unordered_map>
#include <array>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stack>
#include <optional>
#include <functional>
#include <chrono>
#include <list>
#include <variant>
#include <cassert>

//external includes
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <stb/stb_image.h>

#include "typedefs.hpp"
#include "utils.hpp"
#include "math.hpp"
#include "buffer.hpp"
#include "shader.hpp"
#include "light.hpp"
#include "texture.hpp"
#include "font_loader.hpp"
#include "material.hpp"
#include "window.hpp"
#include "mesh.hpp"
#include "sprite_batch.hpp"
#include "geo_batch.hpp"
#include "text_batch.hpp"
#include "save.hpp"
#include "menu.hpp"
#include "gui.hpp"
#include "animator.hpp"
#include "state_machine.hpp"
#include "shapes.hpp"
#include "particle_sys.hpp"

#endif