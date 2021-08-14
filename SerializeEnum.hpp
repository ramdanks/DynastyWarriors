#pragma once

#define SERIALIZE(Enum, Serializer) \
    constexpr auto serial(Enum value) noexcept { return Serializer(value); }

#define NOSERIALIZE(Enum) \
    constexpr auto serial(Enum value) noexcept { return value; }
