#pragma once

#include <array>

namespace Enum {}

#define SERIALIZABLE_ENUM(Name, Type, Serializer, ...)                                 \
        enum Name : Type { __VA_ARGS__ };                                              \
        constexpr auto serial(enum Name value) noexcept { return Serializer(value); }  \
        namespace Enum { static const std::array Name = []{                            \
            static Type __VA_ARGS__; return std::array{__VA_ARGS__}; }(); }            

#define CONSTANT_ENUM(Name, Type, ...)                                                 \
        enum Name : Type { __VA_ARGS__ };                                              \
        constexpr auto serial(enum Name value) noexcept { return value; }              \
        namespace Enum { static const std::array Name{__VA_ARGS__}; }                  
