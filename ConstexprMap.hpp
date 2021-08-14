#pragma once

#include <array>
#include <utility>
#include <algorithm>
#include <stdexcept>

template <typename Key, typename Value, std::size_t Size>
struct ConstexprMap : std::array<std::pair<Key, Value>, Size>
{
    constexpr Value& at(const Key& key) const
    {
        const auto it = find(key);
        if (it == this->end())
            throw std::range_error("not found");
        return it->second;
    }
    constexpr auto find(const Key& key) const noexcept
    {
        return std::find_if(this->begin(), this->end(), [&](const std::pair<Key, Value>& pair)
        {
            return pair.first == key;
        });
    }
    constexpr bool contains(const Key& key) const noexcept
    {
        const auto it = find(key);
        return it != this->end();
    }
};