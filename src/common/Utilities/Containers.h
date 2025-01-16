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

#ifndef TRINITY_CONTAINERS_H
#define TRINITY_CONTAINERS_H

#include "Concepts.h"
#include "Define.h"
#include "Random.h"
#include <algorithm>
#include <iterator>
#include <span>
#include <stdexcept>
#include <type_traits>
#include <utility>
#include <vector>

namespace Trinity
{
    template <class T>
    class CheckedBufferOutputIterator
    {
        public:
            using iterator_category = std::output_iterator_tag;
            using value_type = void;
            using pointer = T*;
            using reference = T&;
            using difference_type = std::ptrdiff_t;

            CheckedBufferOutputIterator(T* buf, size_t n) : _buf(buf), _end(buf+n) {}

            T& operator*() const { check(); return *_buf; }
            CheckedBufferOutputIterator& operator++() { check(); ++_buf; return *this; }
            CheckedBufferOutputIterator operator++(int) { CheckedBufferOutputIterator v = *this; operator++(); return v; }

            size_t remaining() const { return (_end - _buf); }

        private:
            T* _buf;
            T* _end;
            void check() const
            {
                if (!(_buf < _end))
                    throw std::out_of_range("index");
            }
    };

    namespace Containers
    {
        // resizes <container> to have at most <requestedSize> elements
        // if it has more than <requestedSize> elements, the elements to keep are selected randomly
        template <std::ranges::forward_range C>
        void RandomResize(C& container, std::size_t requestedSize)
        {
            uint32 elementsToProcess = uint32(std::ranges::size(container));
            if (elementsToProcess <= requestedSize)
                return;

            auto keepIt = std::ranges::begin(container), curIt = std::ranges::begin(container);
            uint32 elementsToKeep = uint32(requestedSize);
            while (elementsToProcess)
            {
                // this element has chance (elementsToKeep / elementsToProcess) of being kept
                if (urand(1, elementsToProcess) <= elementsToKeep)
                {
                    if (keepIt != curIt)
                        *keepIt = std::move(*curIt);
                    ++keepIt;
                    --elementsToKeep;
                }
                ++curIt;
                --elementsToProcess;
            }
            container.erase(keepIt, std::ranges::end(container));
        }

        template <std::ranges::forward_range C, invocable_r<bool, std::ranges::range_reference_t<C>> Predicate>
        void RandomResize(C& container, Predicate&& predicate, std::size_t requestedSize)
        {
            //! First use predicate filter
            C containerCopy;
            std::ranges::copy_if(container, std::inserter(containerCopy, std::ranges::end(containerCopy)), std::forward<Predicate>(predicate));

            if (requestedSize)
                RandomResize(containerCopy, requestedSize);

            container = std::move(containerCopy);
        }

        /*
         * Select a random element from a container.
         *
         * Note: container cannot be empty
         */
        template <std::ranges::input_range C>
        inline auto SelectRandomContainerElement(C const& container) -> std::add_const_t<decltype(*std::ranges::begin(container))>&
        {
            auto it = std::ranges::begin(container);
            std::ranges::advance(it, urand(0, uint32(std::ranges::size(container)) - 1));
            return *it;
        }

        /*
         * Select a random element from a container where each element has a different chance to be selected.
         *
         * @param container Container to select an element from
         * @param weights Chances of each element to be selected, must be in the same order as elements in container.
         *                Caller is responsible for checking that sum of all weights is greater than 0.
         *
         * Note: container cannot be empty
         */
        template <std::ranges::input_range C>
        inline auto SelectRandomWeightedContainerElement(C const& container, std::span<double> const& weights) -> decltype(std::ranges::begin(container))
        {
            auto it = std::ranges::begin(container);
            std::ranges::advance(it, urandweighted(weights.size(), weights.data()));
            return it;
        }

        /*
         * Select a random element from a container where each element has a different chance to be selected.
         *
         * @param container Container to select an element from
         * @param weightExtractor Function retrieving chance of each element in container, expected to take an element of the container and returning a double
         *
         * Note: container cannot be empty
         */
        template <std::ranges::input_range C, invocable_r<double, std::ranges::range_reference_t<C>> Fn>
        inline auto SelectRandomWeightedContainerElement(C const& container, Fn weightExtractor) -> decltype(std::ranges::begin(container))
        {
            std::size_t size = std::ranges::size(container);
            std::size_t i = 0;
            double* weights = new double[size];
            double weightSum = 0.0;
            for (auto const& val : container)
            {
                double weight = weightExtractor(val);
                weights[i++] = weight;
                weightSum += weight;
            }

            auto it = std::ranges::begin(container);
            std::ranges::advance(it, weightSum > 0.0 ? urandweighted(size, weights) : urand(0, uint32(std::ranges::size(container)) - 1));
            delete[] weights;
            return it;
        }

        /**
         * @fn void Trinity::Containers::RandomShuffle(Iterator begin, Iterator end)
         *
         * @brief Reorder the elements of the iterator range randomly.
         *
         * @param begin Beginning of the range to reorder
         * @param end End of the range to reorder
         */
        template <std::random_access_iterator Iterator>
        inline void RandomShuffle(Iterator begin, Iterator end)
        {
            std::ranges::shuffle(begin, end, RandomEngine::Instance());
        }

        /**
         * @fn void Trinity::Containers::RandomShuffle(C& container)
         *
         * @brief Reorder the elements of the container randomly.
         *
         * @param container Container to reorder
         */
        template <std::ranges::random_access_range C>
        inline void RandomShuffle(C& container)
        {
            RandomShuffle(std::ranges::begin(container), std::ranges::end(container));
        }

        /**
         * @fn bool Trinity::Containers::Intersects(Iterator first1, Iterator last1, Iterator first2, Iterator last2)
         *
         * @brief Checks if two SORTED containers have a common element
         *
         * @param first1 Iterator pointing to start of the first container
         * @param last1 Iterator pointing to end of the first container
         * @param first2 Iterator pointing to start of the second container
         * @param last2 Iterator pointing to end of the second container
         *
         * @return true if containers have a common element, false otherwise.
        */
        template <std::input_iterator Iterator1, std::sentinel_for<Iterator1> Sentinel1,
                  std::input_iterator Iterator2, std::sentinel_for<Iterator2> Sentinel2>
        inline constexpr bool Intersects(Iterator1 first1, Sentinel1 last1, Iterator2 first2, Sentinel2 last2)
        {
            while (first1 != last1 && first2 != last2)
            {
                if (*first1 < *first2)
                    ++first1;
                else if (*first2 < *first1)
                    ++first2;
                else
                    return true;
            }

            return false;
        }

        /**
         * @fn bool Trinity::Containers::Intersects(Iterator first1, Iterator last1, Iterator first2, Iterator last2, Predicate&& equalPred)
         *
         * @brief Checks if two SORTED containers have a common element
         *
         * @param first1 Iterator pointing to start of the first container
         * @param last1 Iterator pointing to end of the first container
         * @param first2 Iterator pointing to start of the second container
         * @param last2 Iterator pointing to end of the second container
         * @param equalPred Additional predicate to exclude elements
         *
         * @return true if containers have a common element, false otherwise.
        */
        template <std::input_iterator Iterator1, std::sentinel_for<Iterator1> Sentinel1,
                  std::input_iterator Iterator2, std::sentinel_for<Iterator2> Sentinel2,
                  invocable_r<bool, std::iter_reference_t<Iterator1>, std::iter_reference_t<Iterator2>> Predicate>
        inline constexpr bool Intersects(Iterator1 first1, Sentinel1 last1, Iterator2 first2, Sentinel2 last2, Predicate&& equalPred)
        {
            while (first1 != last1 && first2 != last2)
            {
                if (*first1 < *first2)
                    ++first1;
                else if (*first2 < *first1)
                    ++first2;
                else if (!std::invoke(std::forward<Predicate>(equalPred), *first1, *first2))
                    ++first1, ++first2;
                else
                    return true;
            }

            return false;
        }

        namespace Impl
        {
            template <typename Container, typename Predicate>
            void EraseIfMoveAssignable(Container& c, Predicate p)
            {
                auto wpos = c.begin();
                for (auto rpos = c.begin(), end = c.end(); rpos != end; ++rpos)
                {
                    if (!p(*rpos))
                    {
                        if (rpos != wpos)
                            std::swap(*rpos, *wpos);
                        ++wpos;
                    }
                }
                c.erase(wpos, c.end());
            }

            template <typename Container, typename Predicate>
            void EraseIfNotMoveAssignable(Container& c, Predicate p)
            {
                for (auto it = c.begin(); it != c.end();)
                {
                    if (p(*it))
                        it = c.erase(it);
                    else
                        ++it;
                }
            }
        }

        template <std::ranges::forward_range Container, invocable_r<bool, std::ranges::range_reference_t<Container>> Predicate>
        inline void EraseIf(Container& c, Predicate p) requires requires { c.erase(c.begin(), c.end()); }
        {
            if constexpr (std::is_move_assignable_v<decltype(*c.begin())>)
                Impl::EraseIfMoveAssignable(c, std::ref(p));
            else
                Impl::EraseIfNotMoveAssignable(c, std::ref(p));
        }

        /**
         * Returns a mutable reference to element at index i
         * Will resize vector if neccessary to ensure element at i can be safely written
         *
         * This exists as separate overload instead of one function with default argument to allow using
         * with vectors of non-default-constructible classes
         */
        template <typename T>
        inline decltype(auto) EnsureWritableVectorIndex(std::vector<T>& vec, typename std::vector<T>::size_type i)
        {
            if (i >= vec.size())
                vec.resize(i + 1);

            return vec[i];
        }

        /**
         * Returns a mutable reference to element at index i
         * Will resize vector if neccessary to ensure element at i can be safely written
         *
         * This overload allows specifying what value to pad vector with during .resize
         */
        template <typename T>
        inline decltype(auto) EnsureWritableVectorIndex(std::vector<T>& vec, typename std::vector<T>::size_type i, T const& resizeDefault)
        {
            if (i >= vec.size())
                vec.resize(i + 1, resizeDefault);

            return vec[i];
        }
    }
    //! namespace Containers
}
//! namespace Trinity

#endif //! #ifdef TRINITY_CONTAINERS_H
