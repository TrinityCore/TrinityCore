/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TRINITYCORE_HASH_H
#define TRINITYCORE_HASH_H

#include <functional>
#include <span>
#include <utility>

namespace Trinity
{
    template <typename T>
    inline void hash_combine(std::size_t& seed, T const& val)
    {
        // Taken from boost::hash_combine

        seed = seed + 0x9E3779B9 + std::hash<T>()(val);

        if constexpr (sizeof(std::size_t) == 8)
        {
            constexpr std::size_t m = 0xE9846AF9B1A615D;

            seed ^= seed >> 32;
            seed *= m;
            seed ^= seed >> 32;
            seed *= m;
            seed ^= seed >> 28;
        }
        else
        {
            constexpr std::size_t m1 = 0x21F0AAAD;
            constexpr std::size_t m2 = 0x735A2D97;

            seed ^= seed >> 16;
            seed *= m1;
            seed ^= seed >> 15;
            seed *= m2;
            seed ^= seed >> 15;
        }
    }

    template <std::size_t>
    struct HashFnv1aConstants { };

    template <>
    struct HashFnv1aConstants<4>
    {
        static constexpr std::uint32_t Basis = 0x811C9DC5u;
        static constexpr std::uint32_t Prime = 0x01000193u;
    };

    template <>
    struct HashFnv1aConstants<8>
    {
        static constexpr std::uint64_t Basis = 0xCBF29CE484222325ull;
        static constexpr std::uint64_t Prime = 0x00000100000001B3ull;
    };

    template <typename T>
    concept HashablePrimitive = std::is_arithmetic_v<T> || std::is_enum_v<T> || std::is_pointer_v<T>;

    template <typename T = std::size_t>
    struct HashFnv1a
    {
        using Constants = HashFnv1aConstants<sizeof(T)>;

        T Value = Constants::Basis;

        template <HashablePrimitive V, std::size_t Extent>
        inline constexpr void UpdateData(std::span<V, Extent> data) noexcept
        {
            T hash = Value;

            if (std::is_constant_evaluated())
            {
                static_assert(std::is_integral_v<V> || std::is_enum_v<V>, "Only integral types can be hashed at compile time");

                for (V c : data)
                {
                    for (std::size_t i = 0; i < sizeof(V); ++i)
                    {
                        hash ^= (static_cast<T>(c) >> (i * 8)) & 0xFF;
                        hash *= Constants::Prime;
                    }
                }
            }
            else
            {
                std::byte const* c = reinterpret_cast<std::byte const*>(data.data());
                std::byte const* end = c + data.size_bytes();
                while (c != end)
                {
                    hash ^= static_cast<T>(*c);
                    hash *= Constants::Prime;
                    ++c;
                }
            }

            Value = hash;
        }

        template <HashablePrimitive V>
        inline constexpr void UpdateData(V data) noexcept
        {
            this->UpdateData(std::span<V, 1>(&data, 1));
        }

        template <typename V>
        inline constexpr void UpdateData(V const& data) noexcept requires requires { std::span(data); }
        {
            this->UpdateData(std::span(data));
        }

        template <HashablePrimitive V, std::size_t Extent>
        inline static constexpr std::size_t GetHash(std::span<V, Extent> data) noexcept
        {
            HashFnv1a hash;
            hash.UpdateData(data);
            return hash.Value;
        }

        template <HashablePrimitive V>
        inline static constexpr std::size_t GetHash(V data) noexcept
        {
            return HashFnv1a::GetHash(std::span<V, 1>(&data, 1));
        }

        template <typename V>
        inline static constexpr std::size_t GetHash(V const& data) noexcept requires requires { std::span(data); }
        {
            return HashFnv1a::GetHash(std::span(data));
        }
    };

    template <typename T, typename Hash = std::hash<T>>
    struct TransparentHash : Hash
    {
        using is_transparent = int;
    };
}

 //! Hash implementation for std::pair to allow using pairs in unordered_set or as key for unordered_map
 //! Individual types used in pair must be hashable by std::hash
template <typename K, typename V>
struct std::hash<std::pair<K, V>>
{
    std::size_t operator()(std::pair<K, V> const& p) const
    {
        std::size_t hashVal = std::hash<K>()(p.first);
        Trinity::hash_combine(hashVal, p.second);
        return hashVal;
    }
};

#endif // TRINITYCORE_HASH_H
