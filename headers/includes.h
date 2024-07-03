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
#include <list>

using steady_clock = std::chrono::steady_clock;
using time_point = std::chrono::time_point<steady_clock>;

#include "stb_image.h"
#include "math.h"
#include "buffer.h"
#include "shader.h"
#include "window.h"
#include "sprite_batch.h"
#include "geo_batch.h"
#include "text_batch.h"
#include "save.h"
#include "menu.h"
#include "animator.h"
#include "state_machine.h"
#include "common.h"
#endif