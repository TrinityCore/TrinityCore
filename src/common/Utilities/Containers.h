/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "Define.h"
#include "Random.h"
#include <algorithm>
#include <functional>
#include <list>
#include <vector>

namespace Trinity
{
    namespace Containers
    {
        template<class T>
        void RandomResizeList(std::list<T> &list, uint32 size)
        {
            size_t list_size = list.size();

            while (list_size > size)
            {
                typename std::list<T>::iterator itr = list.begin();
                std::advance(itr, urand(0, list_size - 1));
                list.erase(itr);
                --list_size;
            }
        }

        template<class T, class Predicate>
        void RandomResizeList(std::list<T> &list, Predicate& predicate, uint32 size)
        {
            //! First use predicate filter
            std::list<T> listCopy;
            for (typename std::list<T>::iterator itr = list.begin(); itr != list.end(); ++itr)
                if (predicate(*itr))
                    listCopy.push_back(*itr);

            if (size)
                RandomResizeList(listCopy, size);

            list = listCopy;
        }

        /*
         * Select a random element from a container.
         *
         * Note: container cannot be empty
         */
        template <class C>
        typename C::value_type const& SelectRandomContainerElement(C const& container)
        {
            typename C::const_iterator it = container.begin();
            std::advance(it, urand(0, container.size() - 1));
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
        template <class C>
        typename C::const_iterator SelectRandomWeightedContainerElement(C const& container, std::vector<double> weights)
        {
            Trinity::discrete_distribution_param<uint32> ddParam(weights.begin(), weights.end());
            std::discrete_distribution<uint32> dd(ddParam);
            typename C::const_iterator it = container.begin();
            std::advance(it, dd(SFMTEngine::Instance()));
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
        template <class C, class Fn>
        typename C::const_iterator SelectRandomWeightedContainerElement(C const& container, Fn weightExtractor)
        {
            std::vector<double> weights;
            weights.reserve(container.size());
            double weightSum = 0.0;
            for (auto itr = container.begin(); itr != container.end(); ++itr)
            {
                double weight = weightExtractor(*itr);
                weights.push_back(weight);
                weightSum += weight;
            }
            if (weightSum <= 0.0)
                weights.assign(container.size(), 1.0);

            return SelectRandomWeightedContainerElement(container, weights);
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
        template<class Iterator1, class Iterator2>
        bool Intersects(Iterator1 first1, Iterator1 last1, Iterator2 first2, Iterator2 last2)
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

        template<class K, class V, template<class, class, class...> class M, class... Rest>
        void MultimapErasePair(M<K, V, Rest...>& multimap, K const& key, V const& value)
        {
            auto range = multimap.equal_range(key);
            for (auto itr = range.first; itr != range.second; )
            {
                if (itr->second == value)
                    itr = multimap.erase(itr);
                else
                    ++itr;
            }
        }
    }
    //! namespace Containers
}
//! namespace Trinity

#endif //! #ifdef TRINITY_CONTAINERS_H
