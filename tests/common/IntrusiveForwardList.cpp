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

#include "tc_catch2.h"

#include "IntrusiveForwardList.h"

struct ListItem;

struct ListItemLinkBase
{
    ListItem* Link = nullptr; // inheritance intrusive link
};

struct ListItem : ListItemLinkBase
{
    std::size_t Id = 0;
    std::atomic<ListItem*> AtomicLink = nullptr; // direct member intrusive link
};

static std::array<ListItem, 5> GenerateData()
{
    return {{ { .Id = 1 }, { .Id = 2 }, { .Id = 3 }, { .Id = 4 }, { .Id = 5 } }};
}

TEMPLATE_TEST_CASE_SIG("IntrusiveForwardList default constructed is empty", "[IntrusiveForwardList]", ((auto ListLink), ListLink),
    &ListItemLinkBase::Link, &ListItem::AtomicLink)
{
    STATIC_REQUIRE(std::ranges::range<Trinity::Containers::IntrusiveForwardList<ListLink>> == true);

    Trinity::Containers::IntrusiveForwardList<ListLink> list;

    REQUIRE(list.empty() == true);
}

TEMPLATE_TEST_CASE_SIG("IntrusiveForwardList links and unlinks items", "[IntrusiveForwardList]", ((auto ListLink), ListLink),
    &ListItemLinkBase::Link, &ListItem::AtomicLink)
{
    std::array<ListItem, 5> items = GenerateData();

    Trinity::Containers::IntrusiveForwardList<ListLink> list;

    for (ListItem& item : items)
        list.push_back(item);

    SECTION("Insertion succeeds")
    {
        REQUIRE(list.empty() == false);

        for (std::size_t i = 0; i < items.size() - 1; ++i)
            REQUIRE(items[i].*ListLink != nullptr);

        // last item should have no "next"
        REQUIRE(items.back().*ListLink == nullptr);
    }

    SECTION("Move transferts all items")
    {
        Trinity::Containers::IntrusiveForwardList<ListLink> list2 = std::move(list);

        REQUIRE(list.empty() == true);
        REQUIRE(list2.empty() == false);
    }

    SECTION("Items are retrieved in the same order as they were inserted")
    {
        for (std::size_t i = 0; i < items.size(); ++i)
        {
            REQUIRE(list.empty() == false);
            REQUIRE(list.front().Id == (i + 1));

            list.pop_front();

            REQUIRE(items[i].*ListLink == nullptr);
        }

        REQUIRE(list.empty() == true);
    }
}

TEMPLATE_TEST_CASE_SIG("IntrusiveForwardList allows insertion at front", "[IntrusiveForwardList]", ((auto ListLink), ListLink),
    &ListItemLinkBase::Link, &ListItem::AtomicLink)
{
    std::array<ListItem, 5> items = GenerateData();

    Trinity::Containers::IntrusiveForwardList<ListLink> list;
    for (ListItem& item : items)
        list.push_front(item);

    for (std::size_t i = items.size(); i > 0; --i)
    {
        REQUIRE(list.empty() == false);
        REQUIRE(list.front().Id == i);

        list.pop_front();

        REQUIRE(items[i - 1].*ListLink == nullptr);
    }

    REQUIRE(list.empty() == true);
}

TEMPLATE_TEST_CASE_SIG("IntrusiveForwardList destruction unlinks all items", "[IntrusiveForwardList]", ((auto ListLink), ListLink),
    &ListItemLinkBase::Link, &ListItem::AtomicLink)
{
    std::array<ListItem, 5> items = GenerateData();

    {
        Trinity::Containers::IntrusiveForwardList<ListLink> list;
        for (ListItem& item : items)
            list.push_back(item);
    }

    for (ListItem& item : items)
        REQUIRE(item.*ListLink == nullptr);
}

TEMPLATE_TEST_CASE_SIG("IntrusiveForwardList iterators empty begin == end", "[IntrusiveForwardList]", ((auto ListLink), ListLink),
    &ListItemLinkBase::Link, &ListItem::AtomicLink)
{
    Trinity::Containers::IntrusiveForwardList<ListLink> list;

    REQUIRE(list.begin() == list.end());
}

TEMPLATE_TEST_CASE_SIG("IntrusiveForwardList iterators allow looping over entire list", "[IntrusiveForwardList]", ((auto ListLink), ListLink),
    &ListItemLinkBase::Link, &ListItem::AtomicLink)
{
    std::array<ListItem, 5> items = GenerateData();

    Trinity::Containers::IntrusiveForwardList<ListLink> list;

    for (ListItem& item : items)
        list.push_back(item);

    auto itemsItr = items.begin(), itemsEnd = items.end();
    auto listItr = list.begin();
    auto listEnd = list.end();

    while (listItr != listEnd)
    {
        REQUIRE(listItr->Id == itemsItr->Id);

        ++itemsItr;
        ++listItr;
    }

    REQUIRE(itemsItr == itemsEnd);
}

TEMPLATE_TEST_CASE_SIG("IntrusiveForwardList erase links item adjacent to removed item", "[IntrusiveForwardList]", ((auto ListLink), ListLink),
    &ListItemLinkBase::Link, &ListItem::AtomicLink)
{
    std::array<ListItem, 5> items = GenerateData();

    Trinity::Containers::IntrusiveForwardList<ListLink> list;

    for (std::size_t i = 0; i < 4; ++i)
        list.push_back(items[i]);

    auto listItr = list.begin();

    // erase in the middle
    std::advance(listItr, 1);
    REQUIRE(listItr->Id == 2);
    auto newItr = list.erase(listItr);
    REQUIRE(newItr->Id == 3);
    REQUIRE(std::ranges::distance(list) == 3);

    // erase first
    listItr = list.begin();
    REQUIRE(listItr->Id == 1);
    newItr = list.erase(listItr);
    REQUIRE(newItr->Id == 3);
    REQUIRE(list.front().Id == 3);
    REQUIRE(std::ranges::distance(list) == 2);

    // erase last
    listItr = list.begin();
    std::advance(listItr, 1);
    REQUIRE(listItr->Id == 4);
    newItr = list.erase(listItr);
    REQUIRE(newItr == list.end());
    REQUIRE(std::ranges::distance(list) == 1);

    // erase only remaining element
    listItr = list.begin();
    REQUIRE(listItr->Id == 3);
    newItr = list.erase(listItr);
    REQUIRE(newItr == list.end());
    REQUIRE(list.empty());

    for (ListItem& item : items)
        REQUIRE(item.*ListLink == nullptr);
}
