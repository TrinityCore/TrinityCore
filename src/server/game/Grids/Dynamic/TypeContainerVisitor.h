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

#ifndef TRINITY_TYPECONTAINERVISITOR_H
#define TRINITY_TYPECONTAINERVISITOR_H

/*
 * @class TypeContainerVisitor is implemented as a visitor pattern.  It is
 * a visitor to the TypeContainerList or TypeContainerMapList.  The visitor has
 * to overload its types as a visit method is called.
 */

#include "Dynamic/TypeContainer.h"

// visitor helper
template <class Visitor, template <typename> typename UnderlyingContainer, typename... Types>
inline void VisitorHelper(Visitor& /*v*/, [[maybe_unused]] TypeListContainerStorage<UnderlyingContainer, Types...>& /*c*/)
{
}

template <class Visitor, template <typename> typename UnderlyingContainer, typename First, typename... Types>
inline void VisitorHelper(Visitor& v, TypeListContainerStorage<UnderlyingContainer, First, Types...>& c)
{
    v.Visit(c.Head);
    VisitorHelper(v, c.Tail);
}

template <class Visitor, template <typename> typename UnderlyingContainer, typename... Types>
inline void VisitorHelper(Visitor& v, TypeListContainer<UnderlyingContainer, Types...>& c)
{
    VisitorHelper(v, c.Data);
}

template<class Visitor, class TypeContainer>
class TypeContainerVisitor
{
public:
    TypeContainerVisitor(Visitor& v) : i_visitor(v) { }

    void Visit(TypeContainer& c)
    {
        VisitorHelper(i_visitor, c);
    }

    void Visit(TypeContainer const& c) const
    {
        VisitorHelper(i_visitor, c);
    }

private:
    Visitor& i_visitor;
};
#endif
