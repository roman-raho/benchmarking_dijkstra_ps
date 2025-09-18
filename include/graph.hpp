#pragma once

#include <vector>
#include <cstdint>
#include <limits>
#include <utility>
#include <stdexcept>

// use 32 bit ints for node indiciess and edge weights
// distances will be in 64-bit ot avoid overflow when summing many weights
using Node = int;
using Weight = int;
