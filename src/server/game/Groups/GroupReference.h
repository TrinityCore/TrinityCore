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

#ifndef _GROUPREFERENCE_H
#define _GROUPREFERENCE_H

#include "LinkedReference/Reference.h"

class Group;
class Player;

class TC_GAME_API GroupReference : public Reference<Group, Player>
{
    protected:
        uint8 iSubGroup;
        void targetObjectBuildLink() override;
        void targetObjectDestroyLink() override;
        void sourceObjectDestroyLink() override;
    public:
        GroupReference() : Reference<Group, Player>(), iSubGroup(0) { }
        ~GroupReference() { unlink(); }
        GroupReference* next() { return (GroupReference*)Reference<Group, Player>::next(); }
        GroupReference const* next() const { return (GroupReference const*)Reference<Group, Player>::next(); }
        uint8 getSubGroup() const { return iSubGroup; }
        void setSubGroup(uint8 pSubGroup) { iSubGroup = pSubGroup; }
};
#endif
