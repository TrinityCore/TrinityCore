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

#ifndef TRINITY_GAMEOBJECTAI_H
#define TRINITY_GAMEOBJECTAI_H

#include "Define.h"
#include <list>

class GameObject;
class Player;
class Quest;
class SpellInfo;
class Unit;

class TC_GAME_API GameObjectAI
{
    protected:
        GameObject* const me;
    public:
        explicit GameObjectAI(GameObject* g) : me(g) { }
        virtual ~GameObjectAI() { }

        virtual void UpdateAI(uint32 /*diff*/) { }

        virtual void InitializeAI() { Reset(); }

        virtual void Reset() { }

        // Pass parameters between AI
        virtual void DoAction(int32 /*param = 0 */) { }
        virtual void SetGUID(uint64 /*guid*/, int32 /*id = 0 */) { }
        virtual uint64 GetGUID(int32 /*id = 0 */) const { return 0; }

        static int32 Permissible(GameObject const* /*go*/);

        // Called when a player opens a gossip dialog with the gameobject.
        virtual bool GossipHello(Player* /*player*/) { return false; }

        // Called when a player selects a gossip item in the gameobject's gossip menu.
        virtual bool GossipSelect(Player* /*player*/, uint32 /*menuId*/, uint32 /*gossipListId*/) { return false; }

        // Called when a player selects a gossip with a code in the gameobject's gossip menu.
        virtual bool GossipSelectCode(Player* /*player*/, uint32 /*menuId*/, uint32 /*gossipListId*/, char const* /*code*/) { return false; }

        // Called when a player accepts a quest from the gameobject.
        virtual void QuestAccept(Player* /*player*/, Quest const* /*quest*/) { }

        // Called when a player completes a quest and is rewarded, opt is the selected item's index or 0
        virtual void QuestReward(Player* /*player*/, Quest const* /*quest*/, uint32 /*opt*/) { }

        // Called when the dialog status between a player and the gameobject is requested.
        virtual uint32 GetDialogStatus(Player* player);

        // Called when a Player clicks a GameObject, before GossipHello
        // prevents achievement tracking if returning true
        virtual bool OnReportUse(Player* /*player*/) { return false; }

        virtual void Destroyed(Player* /*player*/, uint32 /*eventId*/) { }
        virtual void Damaged(Player* /*player*/, uint32 /*eventId*/) { }

        virtual uint32 GetData(uint32 /*id*/) const { return 0; }
        virtual void SetData64(uint32 /*id*/, uint64 /*value*/) { }
        virtual uint64 GetData64(uint32 /*id*/) const { return 0; }
        virtual void SetData(uint32 /*id*/, uint32 /*value*/) { }

        virtual void OnGameEvent(bool /*start*/, uint16 /*eventId*/) { }
        virtual void OnLootStateChanged(uint32 /*state*/, Unit* /*unit*/) { }
        virtual void OnStateChanged(uint32 /*state*/) { }
        virtual void EventInform(uint32 /*eventId*/) { }
        virtual void SpellHit(Unit* /*unit*/, const SpellInfo* /*spellInfo*/) { }
};

class TC_GAME_API NullGameObjectAI : public GameObjectAI
{
    public:
        explicit NullGameObjectAI(GameObject* g);

        void UpdateAI(uint32 /*diff*/) override { }

        static int32 Permissible(GameObject const* /*go*/);
};
#endif
