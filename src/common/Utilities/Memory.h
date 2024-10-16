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

#ifndef TRINITY_MEMORY_H
#define TRINITY_MEMORY_H

#include "CompilerDefs.h"
#include <concepts>
#include <memory>

#if TRINITY_COMPILER == TRINITY_COMPILER_GNU
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wignored-attributes"
#endif

namespace Trinity
{
namespace Impl
{
template<typename T, typename Del>
struct stateful_unique_ptr_deleter
{
    using pointer = T;
    explicit(false) stateful_unique_ptr_deleter(Del deleter) : _deleter(std::move(deleter)) { }
    void operator()(pointer ptr) const { (void)_deleter(ptr); }

private:
    Del _deleter;
};

template<typename T, auto Del>
struct stateless_unique_ptr_deleter
{
    using pointer = T;
    void operator()(pointer ptr) const
    {
        if constexpr (std::is_member_function_pointer_v<decltype(Del)>)
            (void)(ptr->*Del)();
        else
            (void)Del(ptr);
    }
};
}

/**
 * Convenience function to construct type aliases for std::unique_ptr stateful deleters (such as lambda with captures)
 * @tparam Ptr    Type of the pointer
 * @tparam Del    Type of object freeing function (deduced from argument)
 * @param deleter Object deleter
 *
 * Example use
 * @code
 * void FreeV1(Resource*);
 * void FreeV2(Resource*);
 *
 * using ResourceDeleter = decltype(Trinity::unique_ptr_deleter<Resource*>(&FreeV1));
 *
 * std::unique_ptr<Resource, ResourceDeleter> resource = Trinity::make_unique_ptr_with_deleter(GetResourceV1(), &FreeV1);
 * // do stuff ...
 * // ... later get new resource
 * resource = Trinity::make_unique_ptr_with_deleter(GetResourceV2(), &FreeV2);
 * @endcode
 */
template <typename Ptr, typename Del> requires std::invocable<Del, Ptr> && std::is_pointer_v<Ptr>
Impl::stateful_unique_ptr_deleter<Ptr, Del> unique_ptr_deleter(Del deleter)
{
    return Impl::stateful_unique_ptr_deleter<Ptr, Del>(std::move(deleter));
}

/**
 * Convenience function to construct type aliases for std::unique_ptr stateful deleters (such as lambda with captures)
 *
 * Main use is for forming struct/class members without the call to make_unique_ptr_with_deleter
 * @tparam Ptr    Type of the pointer
 * @tparam Del    The freeing function. This can be either a free function pointer that accepts T* as argument, pointer to a member function of T that accepts no arguments or a lambda with no captures
 *
 * Example use
 * @code
 * using FileDeleter = decltype(Trinity::unique_ptr_deleter<FILE*, &::fclose>());
 *
 * class Resource
 * {
 *     std::unique_ptr<FILE, FileDeleter> File;
 * };
 * @endcode
 */
template <typename Ptr, auto Del> requires std::invocable<decltype(Del), Ptr> && std::is_pointer_v<Ptr>
Impl::stateless_unique_ptr_deleter<Ptr, Del> unique_ptr_deleter()
{
    return Impl::stateless_unique_ptr_deleter<Ptr, Del>();
}

/**
 * Utility function to construct a std::unique_ptr object with custom stateful deleter (such as lambda with captures)
 * @tparam Ptr    Type of the pointer
 * @tparam T      Type of the pointed-to object (defaults to std::remove_pointer_t<Ptr>)
 * @tparam Del    Type of object freeing function (deduced from second argument)
 * @param ptr     Raw pointer to owned object
 * @param deleter Object deleter
 *
 * Example use
 * @code
 * class Resource
 * {
 * };
 * class ResourceService
 * {
 *     Resource* Create();
 *     void Destroy(Resource*);
 * };
 *
 * ResourceService* service = GetResourceService();
 *
 * // Lambda that captures all required variables for destruction
 * auto resource = Trinity::make_unique_ptr_with_deleter(service->Create(), [service](Resource* res){ service->Destroy(res); });
 * @endcode
 */
template<typename Ptr, typename T = std::remove_pointer_t<Ptr>, typename Del> requires std::invocable<Del, Ptr> && std::is_pointer_v<Ptr>
std::unique_ptr<T, Impl::stateful_unique_ptr_deleter<Ptr, Del>> make_unique_ptr_with_deleter(Ptr ptr, Del deleter)
{
    return std::unique_ptr<T, Impl::stateful_unique_ptr_deleter<Ptr, Del>>(ptr, std::move(deleter));
}

/**
 * Utility function to construct a std::unique_ptr object with custom stateless deleter (function pointer, captureless lambda)
 * @tparam Del    The freeing function. This can be either a free function pointer that accepts T* as argument, pointer to a member function of T that accepts no arguments or a lambda with no captures
 * @tparam Ptr    Type of the pointer
 * @tparam T      Type of the pointed-to object (defaults to std::remove_pointer_t<Ptr>)
 * @param ptr     Raw pointer to owned object
 *
 * Example uses
 * @code
 * void DestroyResource(Resource*);
 * class Resource
 * {
 *     void Destroy();
 * };
 *
 * // Free function
 * auto free = Trinity::make_unique_ptr_with_deleter<&DestroyResource>(new Resource());
 *
 * // Member function
 * auto member = Trinity::make_unique_ptr_with_deleter<&Resource::Destroy>(new Resource());
 *
 * // Lambda
 * auto lambda = Trinity::make_unique_ptr_with_deleter<[](Resource* res){ res->Destroy(); }>(new Resource());
 * @endcode
 */
template<auto Del, typename Ptr, typename T = std::remove_pointer_t<Ptr>> requires std::invocable<decltype(Del), Ptr> && std::is_pointer_v<Ptr>
std::unique_ptr<T, Impl::stateless_unique_ptr_deleter<Ptr, Del>> make_unique_ptr_with_deleter(Ptr ptr)
{
    return std::unique_ptr<T, Impl::stateless_unique_ptr_deleter<Ptr, Del>>(ptr);
}
}

#if TRINITY_COMPILER == TRINITY_COMPILER_GNU
#pragma GCC diagnostic pop
#endif

#endif // TRINITY_MEMORY_H
