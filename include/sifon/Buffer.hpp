#pragma once 

#include <array>

namespace sifon
{

constexpr size_t DEFAULT_BUFFER_SIZE = 1024;

using Buffer = std::array<char, DEFAULT_BUFFER_SIZE>;

}